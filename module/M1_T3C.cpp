int ledpin = 3;
int pirpin = 2;
int temppin = A0;
bool ledstate = false;

void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(pirpin, INPUT);
  pinMode(temppin, INPUT);

  attachInterrupt(digitalPinToInterrupt(pirpin), motionDetectedInterrupt, RISING);
  Serial.begin(9600);
}

void loop()
{
  checkMotion();    // Check for motion
  checkTemperature();  // Check temperature

  if (ledstate) {
    Serial.println("LED is ON");
  } else {
    Serial.println("LED is OFF");
  }

  delay(1000);
}

void motionDetectedInterrupt()
{
  ledstate = !ledstate;
  digitalWrite(ledpin, ledstate ? HIGH : LOW);
  Serial.println(ledstate ? "Motion Detected - LED ON" : "No Motion - LED OFF");
}

void checkMotion()
{
  if (digitalRead(pirpin) == HIGH)
  {
    ledstate = !ledstate;
    digitalWrite(ledpin, ledstate ? HIGH : LOW);
    Serial.println(ledstate ? "Motion Detected - LED ON" : "No Motion - LED OFF");
  }
}

void checkTemperature()
{
  float temperature = analogRead(temppin) * 0.48828125; // Convert analog reading to temperature in Celsius

  const float highTempThreshold = 25.0;

  if (temperature > highTempThreshold)
  {
    ledstate = true;
  }
  else
  {
    ledstate = false;
  }

  digitalWrite(ledpin, ledstate ? HIGH : LOW);
  Serial.println(ledstate ? "High Temperature - LED ON" : "Normal Temperature - LED OFF");
}
