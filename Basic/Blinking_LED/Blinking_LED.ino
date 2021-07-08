void setup() {
  // put your setup code here, to run once:
  pinMode (13,OUTPUT);
  pinMode (3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (13,HIGH);
  digitalWrite (3,HIGH);
  Serial.println ("---> Los leds están encendidos");
  delay (1000);
  digitalWrite (13,LOW);
  digitalWrite (3,LOW);
  Serial.println ("---> Los leds están apagados");
  delay (1000);
}
