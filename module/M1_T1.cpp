int pirState = 2;
int ledPin = 13;

void setup()
{
  pinMode(pirState, INPUT);   // Set PIR pin as input
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  Serial.begin(9600);
}

void loop()
{
  int motionState = digitalRead(pirState);  // Read PIR sensor state

  if (motionState == HIGH) {
    // Motion detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
    delay(1000); // Add a delay to avoid rapid LED toggling due to continuous motion
  } else {
    // No motion, turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("No motion");
  }
}
