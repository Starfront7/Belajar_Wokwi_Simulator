const int pinTrig = 22;
const int pinEcho = 21;

const int pinMerah  = 25;
const int pinKuning = 26;
const int pinHijau  = 27;
const int pinBiru   = 14;

void setup() {

  Serial.begin(115200);
  
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  pinMode(pinMerah, OUTPUT);
  pinMode(pinKuning, OUTPUT);
  pinMode(pinHijau, OUTPUT);
  pinMode(pinBiru, OUTPUT);
}

void loop() {

  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  

  long durasi = pulseIn(pinEcho, HIGH);
  

  int jarak = durasi * 0.034 / 2;
  

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  
  digitalWrite(pinMerah, LOW);
  digitalWrite(pinKuning, LOW);
  digitalWrite(pinHijau, LOW);
  digitalWrite(pinBiru, LOW);

  
  if (jarak == 1) {
    digitalWrite(pinMerah, HIGH);
  } 
  else if (jarak == 2) {
    digitalWrite(pinKuning, HIGH);
  } 
  else if (jarak == 3) {
    digitalWrite(pinHijau, HIGH);
  } 
  else if (jarak >= 4 && jarak <= 5) {
    digitalWrite(pinBiru, HIGH);
  }

  delay(200); 
}

// https://wokwi.com/projects/466059416511971329
