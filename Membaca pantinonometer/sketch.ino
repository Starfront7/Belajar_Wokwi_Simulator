int pot1 = 34; 
int value1 = 0; 

int pot2 = 35; 
int value2 = 0; 

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
}

void loop() {
  value1 = analogRead(pot1);
  Serial.print("Potentiometer 1: ");
  Serial.println(value1);

  value2 = analogRead(pot2);
  Serial.print("Potentiometer 2: ");
  Serial.println(value2);
  
  Serial.println(""); 
  delay(500);
}

// https://wokwi.com/projects/466075506225241089