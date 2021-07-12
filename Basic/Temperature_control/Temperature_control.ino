//Define pins
const int button_down = 2;
const int button_up = 3;
const int led = 6;
const int fan  = 5;

//Global variables
float temperature;
float signal_temperature;
float room_temperature = 23; 
bool fan_activated = false;
long last_time_down;
long time_gap_down;
long last_time_up;
long time_gap_up;

//SETUP function
void setup() {
  Serial.begin (9600);
  pinMode (fan, OUTPUT);
  pinMode (button_down, INPUT_PULLUP);
  pinMode (button_up, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(button_down), increase_limit, FALLING);
  attachInterrupt (digitalPinToInterrupt(button_up), decrease_limit, FALLING);

}


//LOOP function
void loop() {
  delay(500);
  signal_temperature = analogRead(A0);
  temperature = (signal_temperature / 1024) * 500;
  fan_action ();
  }

//Function to move the fan
void fan_action() {
  if (temperature > room_temperature){
    digitalWrite (fan, HIGH);
    fan_activated = true;
    Serial.println ("Ventilador activado --> Temperatura: " + String(temperature) + "°C");
  }else{
    digitalWrite (fan, LOW);
    fan_activated  = false;
    Serial.println ("Ventilador desactivado --> Temperatura: " + String(temperature) + "°C");
  }
}


//Function to increase room's temperature
void increase_limit (){
  time_gap_up = millis () - last_time_up;
  last_time_up = millis ();

  if (time_gap_up > 350){
    room_temperature ++;
    Serial.println ("La temperatura ambiente ha subido a: " + String(room_temperature));
  } 
}


//Function to decrease room's temperature
void decrease_limit (){
  time_gap_down = millis () - last_time_down;
  last_time_down = millis ();

  if (time_gap_down > 350){
    room_temperature --;
    Serial.println ("La temperatura ambiente ha bajado a: " + String(room_temperature));
  } 
}