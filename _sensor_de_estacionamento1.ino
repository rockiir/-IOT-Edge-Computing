// C++ code
//
int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(10, 11);
  if (distancia < 50) {
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(5, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
  }
}