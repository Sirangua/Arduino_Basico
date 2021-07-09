//Define pin for led
int blue_led = 3;
int green_led = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode (13,OUTPUT);
  pinMode (3,OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (green_led,HIGH);
  digitalWrite (blue_led,HIGH);
  Serial.println ("---> Los leds están encendidos");
  delay (1000);
  digitalWrite (green_led,LOW);
  digitalWrite (blue_led,LOW);
  Serial.println ("---> Los leds están apagados");
  delay (1000);
}
