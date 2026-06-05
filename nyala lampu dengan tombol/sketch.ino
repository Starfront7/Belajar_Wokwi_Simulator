const int ledb = 25;

const int btn = 26;
int btnstate = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(ledb, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnstate = digitalRead(btn);

  if (btnstate == HIGH){
    digitalWrite(ledb, HIGH);
  } else {
    digitalWrite(ledb, LOW);
  }
}

// https://wokwi.com/projects/465993403094851585