//Define pin's name 
const int led = 5;
const int button  = 3;

void setup() {
  Serial.begin (9600);
  pinMode (button,INPUT_PULLUP);
  pinMode (led,OUTPUT);
}

void loop() {
  bool button_state = digitalRead (button);

  if (button_state == false){
    if (digitalRead(led) == LOW){
      digitalWrite (led,HIGH);
    } else {
      digitalWrite (led, LOW);
    }
  }

delay (400); 
}
