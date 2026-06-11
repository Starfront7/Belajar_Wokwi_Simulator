#include <IRremote.h>
#include <LedControl.h>


const int PIN_DIN = 12;
const int PIN_CS  = 11;
const int PIN_CLK = 10;


LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, 3);


const int PIN_IR = 2;        
const int pinSpeaker = 17;

bool modeDisko = false;
unsigned long waktuSebelumnya = 0;
int langkahDisko = 0;

void setup() {
  IrReceiver.begin(PIN_IR, ENABLE_LED_FEEDBACK);
  
  
  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);       
    lc.setIntensity(i, 8);       
    lc.clearDisplay(i);          
  }
  
  pinMode(pinSpeaker, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long tombol = IrReceiver.decodedIRData.command;

    switch (tombol) {
      case 48:
        modeDisko = false;
        tampilkanPanah();
        tone(pinSpeaker, 1500, 150);
        break;
        
      case 24:
        modeDisko = false;
        tampilkanSmile();
        tone(pinSpeaker, 1000, 150);
        break;
        
      case 162:
        modeDisko = !modeDisko;
        if (!modeDisko) {
          for (int i = 0; i < 3; i++) lc.clearDisplay(i);
          noTone(pinSpeaker);
        }
        break;
    }
    IrReceiver.resume();
  }

  if (modeDisko) {
    jalankanDiskoMatrix3Layar();
  }
}

void jalankanDiskoMatrix3Layar() {
  unsigned long waktuSekarang = millis();
  
  if (waktuSekarang - waktuSebelumnya >= 120) { 
    waktuSebelumnya = waktuSekarang;
    langkahDisko++;
    
    for (int layar = 0; layar < 3; layar++) {
      for (int kolom = 0; kolom < 8; kolom++) {
        int tinggiGrafik = random(1, 9); 
        byte dataKolom = 0;
        
        for (int i = 0; i < tinggiGrafik; i++) {
          dataKolom |= (1 << i);
        }
        lc.setColumn(layar, kolom, dataKolom);
      }
    }

    switch (langkahDisko % 6) {
      case 0: tone(pinSpeaker, 523); break; // Bass Drop
      case 1: tone(pinSpeaker, 659); break; 
      case 2: tone(pinSpeaker, 587); break; 
      case 3: tone(pinSpeaker, 784); break; 
      case 4: tone(pinSpeaker, 880); break; // Klimaks
      case 5: noTone(pinSpeaker);    break; // Jeda Beat
    }
  }
}

void tampilkanPanah() {
  for (int i = 0; i < 3; i++) lc.clearDisplay(i);
  byte panah[8] = {B00011000, B00111100, B01111110, B11111111, B00011000, B00011000, B00011000, B00011000};
  for (int i = 0; i < 8; i++) lc.setRow(1, i, panah[i]); // Muncul di Layar ke-2
}

void tampilkanSmile() {
  for (int i = 0; i < 3; i++) lc.clearDisplay(i);
  byte smile[8] = {B00000000, B01100110, B01100110, B00000000, B10000001, B01000010, B00111100, B00000000};
  for (int i = 0; i < 8; i++) lc.setRow(1, i, smile[i]); // Muncul di Layar ke-2
}
