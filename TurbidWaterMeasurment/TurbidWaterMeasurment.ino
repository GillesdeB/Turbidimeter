// From Turbid Water to Clear Water using ESP8266 
// Blink the internal blue LED on the ESP-01 - GPIO1
// Read the photoresistor to find the turpidity level
// Display red when turpidity high, and grenn when ok to drink

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);     // LED_BUILTIN
  pinMode(D1, OUTPUT);              // Green LED
  pinMode(D2, OUTPUT);              // Red LED
}

// the loop function runs over and over again forever
void loop() {
  blinkLed();
  float voltage = readVoltage();
  displayStatus(voltage);
}

void displayStatus(float level) {
  if (level > 4)
  {
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
  }
  else
  {
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
  }  
}

float readVoltage() {
  int sensorValue = 0;
  for (int i = 0; i<5; i++) {
    sensorValue += analogRead(A0); // read the input on analog pin 0
    delay(50);  
  }
  float voltage = (sensorValue / 5)* (5.0 / 1023.0);
  Serial.println(voltage);  
  // Convert analog read (0-1023) to voltage (0-5V)
  return  voltage ; 
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (active low on ESP-01)
  delay(30);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off (voltage HIGH)
  delay(220);  
}
