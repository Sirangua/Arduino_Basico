//Libraries to use Display ssd1306
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display (-1);

//Define pins
byte button_down = 2;
byte button_up = 3;
byte led = 6;
byte fan  = 5;

//Global variables
float temperature;
float signal_temperature;
float room_temperature = 30; 
bool fan_activated = false;
long last_time_down;
long time_gap_down;
long last_time_up;
long time_gap_up;
long counter1 = 0;
bool change_room_temperature = false;
byte buffer_temps [128];

//SETUP function
void setup() {
  Serial.begin (9600);
  pinMode (fan, OUTPUT);

  //Set interruption for the buttons
  pinMode (button_down, INPUT_PULLUP);
  pinMode (button_up, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(button_down), increase_limit, FALLING);
  attachInterrupt (digitalPinToInterrupt(button_up), decrease_limit, FALLING);

  //Initialize display for AxAA direction
  display.begin (SSD1306_SWITCHCAPVCC, 0x3C);
  //Clear display
  display.clearDisplay ();

  //Show the initial temperature's room
  show_room_temperature (room_temperature);

  //Filling the buffer array
  for (int i = 0; i < 128; i++){
    buffer_temps [i] = 110;
  }
}


//LOOP function
void loop() {
  
  //To wait 1 second
  if(millis() - counter1 > 1000){
    counter1 = millis ();
    signal_temperature = analogRead(A0);
    temperature = (signal_temperature / 1024) * 500;
    fan_action ();
    show_temperature(temperature);
    fill_buffer(temperature);
    draw_grid();
    graph ();
  }

  //To show changes in the room's temperature
  if (change_room_temperature){
    show_room_temperature(room_temperature);
    change_room_temperature = false;
  }
}

//Function to move the fan
void fan_action() {
  if (temperature > room_temperature){
    digitalWrite (fan, HIGH);
    fan_activated = true;
  }else{
    digitalWrite (fan, LOW);
    fan_activated  = false;
  }
}


//Function to increase room's temperature
void increase_limit (){
  time_gap_up = millis () - last_time_up;
  last_time_up = millis ();

  if (time_gap_up > 350){
    room_temperature ++;
    change_room_temperature = true;
  } 
}


//Function to decrease room's temperature
void decrease_limit (){
  time_gap_down = millis () - last_time_down;
  last_time_down = millis ();

  if (time_gap_down > 350){
    room_temperature --;
    change_room_temperature = true;
  } 
}

//Function to show the temperature on display
void show_temperature (float temp){
  display.setTextColor (WHITE,BLACK);
  display.setTextSize (1);
  display.setCursor (0,0);
  display.println ("T = " + String(temp,1));
  display.display ();
}

//Function to show the room's temperature on display
void show_room_temperature (float temp){
  display.setTextColor (WHITE,BLACK);
  display.setTextSize (1);
  display.setCursor (80,0);
  display.println ("T0 = " + String(temp,0));
  display.display ();
}


//Function to show a grid on display
void draw_grid (){
  //To erase the last results
  display.fillRect(0,16,128,50,BLACK);
  //Repeat points drawing a grid 
  for (int j = 16; j < 63; j = j + 10){
    for (int i = 0; i < 127; i = i + 10 ){
      display.drawPixel (i,j,WHITE);
    }

    //To draw a line for 0°C
    if (j == 56){
      for (int i = 0; i < 127; i++ ){
      display.drawPixel (i,j,WHITE);
      }
    }
  }
}


//Function to graphic in real time the curve of temperature
void graph (){ //FAlta pasarle el parametro
  for (int i = 0; i < 127; i++){
    if (buffer_temps [i]< 100){
      int y = map (buffer_temps [i],-7,42,64,16);
      display.drawPixel (i,y,WHITE);
    }
  }
}

//Functoion to fill the buffer
void fill_buffer (float temp){
  for (int i = 1; i < 128; i++){
    buffer_temps [i - 1] = (byte) buffer_temps[i];
  }
  buffer_temps [127] = (byte) temp;
}