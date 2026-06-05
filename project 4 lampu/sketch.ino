
const int ledm = 12
const int ledk = 14
const int ledh = 27
const int ledb = 26

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(ledm, OUTPUT);
  pinMode(ledk, OUTPUT);
  pinMode(ledh, OUTPUT);
  pinMode(ledb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // this speeds up the simulation

  digitalWrite(ledm, HIGH);
  digitalWrite(ledk, LOW);
  digitalWrite(ledh, LOW);
  digitalWrite(ledb, LOW);
  Serial.print("Merah nyala");
  delay(1000);

  digitalWrite(ledm, LOW);
  digitalWrite(ledk, HIGH);
  digitalWrite(ledh, LOW);
  digitalWrite(ledb, LOW);
  Serial.print("Kuning nyala");
  delay(1000);

  digitalWrite(ledm, LOW);
  digitalWrite(ledk, LOW);
  digitalWrite(ledh, HIGH);
  digitalWrite(ledb, LOW);
  Serial.print("Hijau nyala");
  delay(1000);

  digitalWrite(ledm, LOW);
  digitalWrite(ledk, LOW);
  digitalWrite(ledh, LOW);
  digitalWrite(ledb, HIGH);
  Serial.print("Biru nyala");
  delay(1000);
}

// https://wokwi.com/projects/465988682376809473
