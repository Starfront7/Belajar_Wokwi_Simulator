const int r = 25;
const int g = 26;
const int b = 27;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(r, 255);
  analogWrite(g, 0);
  analogWrite(b, 0);
  delay(100);

  analogWrite(r, 0);
  analogWrite(g, 255);
  analogWrite(b, 0);
  delay(100);

  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 255);
  delay(100);

  analogWrite(r, 255);
  analogWrite(g, 0);
  analogWrite(b, 255);
  delay(100);
}

// https://wokwi.com/projects/465994717712576513
