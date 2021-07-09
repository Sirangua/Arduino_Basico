//Define name's pin
const int red_led = 2;
const int blue_led = 3;
const int green_led = 4;
const int pause = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(red_led,OUTPUT);
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  left ();
  right ();
  left ();
  right ();

  off ();
  delay (500);

  left (); 
  left ();
  left ();
  right ();
  right ();
  right ();

  off ();
  delay (500);

  right ();
  right ();
  right ();
  right ();
  right ();
  right ();
  left (); 
  left ();
  left ();
  left (); 
  left ();
  left ();

  off ();
  delay (100);

}

void right () {
  digitalWrite (green_led,HIGH);
  digitalWrite (blue_led,LOW);
  digitalWrite (red_led,LOW);
  Serial.println("--> LED verde encendido");
  delay (pause);
  digitalWrite (blue_led,HIGH);
  digitalWrite (green_led,LOW);
  digitalWrite (red_led,LOW);
  Serial.println("--> LED azul encendido");
  delay (pause);
  digitalWrite (red_led,HIGH);
  digitalWrite (green_led,LOW);
  digitalWrite (blue_led,LOW);
  Serial.println("--> LED rojo encendido");
  delay (pause);
}

void left () {
  digitalWrite (red_led,HIGH);
  digitalWrite (green_led,LOW);
  digitalWrite (blue_led,LOW);
  Serial.println("--> LED rojo encendido");
  delay (pause);
  digitalWrite (blue_led,HIGH);
  digitalWrite (green_led,LOW);
  digitalWrite (red_led,LOW);
  Serial.println("--> LED azul encendido");
  delay (pause);
  digitalWrite (green_led,HIGH);
  digitalWrite (blue_led,LOW);
  digitalWrite (red_led,LOW);
  Serial.println("--> LED verde encendido");
  delay (pause);
}

void off (){
  digitalWrite (red_led,LOW);
  digitalWrite (green_led,LOW);
  digitalWrite (blue_led,LOW);
}

