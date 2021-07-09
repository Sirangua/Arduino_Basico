//Define pin's name
const int led = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_value = analogRead (A0);
  int adapted_value = map (analog_value,0,1023,0,255);

  analogWrite (led,adapted_value);

  Serial.println ("El valor leido es (" + String(analog_value) + ") y en PWM " + String (adapted_value));
}
