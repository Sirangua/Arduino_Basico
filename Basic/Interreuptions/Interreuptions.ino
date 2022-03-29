//Define pin's name 
const int led = 5;
const int button  = 3;
bool button_state;
//Variables used in millis
long last_time;
long time_gap;

void setup() {
  Serial.begin (9600);
  pinMode (button,INPUT_PULLUP);
  pinMode (led,OUTPUT);
  //Difining an interrruption
  attachInterrupt (digitalPinToInterrupt(button),consult_state,FALLING); //Best form to define a pin as a interruption 
}

void loop() {
}

void consult_state (){

    time_gap = millis () - last_time;
    last_time = millis ();
    Serial.println (time_gap);

    if (time_gap > 400){
     if (digitalRead(led) == LOW){
       digitalWrite (led,HIGH);
      } else {
        digitalWrite (led, LOW);
      }
     delay (400); 
    } 
}