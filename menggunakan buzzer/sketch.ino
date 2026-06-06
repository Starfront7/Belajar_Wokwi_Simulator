int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int durasi = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(25, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 8; i++ ){
    tone(25, melody[i], durasi);
    delay(durasi);
    noTone(25);
    delay(1000);
  }
}

// https://wokwi.com/projects/466058081030695937