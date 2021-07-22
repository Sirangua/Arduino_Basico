//Libraries to use Display ssd1306
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define display with pin reset
Adafruit_SSD1306 display (-1);

//Define pins
byte potentiometer = A0;
byte buzzer = 2;
byte button = 3;

//Global variables
byte cursor_size = 30;
byte cursor_value;
byte ball_x = 63;
byte ball_y = 0;
byte prev_ball_x;
byte prev_ball_y;
byte score = 0;
byte hearts = 3;
byte level = 1;
byte score_count = 0;
bool play = false;

//Setup function
void setup() {

  //Initialize display for AxAA direction
  display.begin (SSD1306_SWITCHCAPVCC, 0x3C);
  display.display ();
  display.clearDisplay ();
  display.display ();

  //The button to start game
  pinMode (button, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(button), button_presed, FALLING);

}

//Loop function
void loop() {

  if (play == false){
    delay (1000);
    display.clearDisplay ();
    display.setCursor (0,28);
    display.println ("P R E S S   S T A R T");
    display.display();

    while (play == false){
      delay (100);
    }

    display.clearDisplay ();
    score_marker ();
    draw_level ();
    draw_hearts ();
  }


  randomSeed (analogRead(A2));
  int analog_value = analogRead (A0);
  analog_value = map (analog_value, 4, 1020, 0, 127 - cursor_size);
  cursor_value = byte (analog_value);
  draw_cursor (cursor_value);
  move_ball (cursor_value);
}


//Function to draw the cursor
void draw_cursor (byte pos){
  display.drawLine (0,63,127,63,BLACK);
  display.drawLine (pos ,63 ,pos + cursor_size ,63 ,WHITE );
  display.display ();
}


//Function to move the ball
void move_ball (byte pos){
  ball_x = ball_x + random (-5,5);
  
  //Keep the ball on the screen
  if (ball_x > 127){
    ball_x = 127;
  }

  //Move in the Y axis
  ball_y = ball_y + 3;

  //Ball catched
  if (ball_y == 63 && ball_x > cursor_value && ball_x < cursor_value + cursor_size){ 
    score++;
    score_count ++;

    //To increase level
    if (score_count == 3){
      level ++;
      score_count = 0;
      tone (buzzer, 6000, 150);
      delay (50);
      tone (buzzer, 10000, 150);
      delay (50);
      tone (buzzer, 12000, 100);
      delay (50);
      tone (buzzer, 15000, 150);
    }

    cursor_size--;
    ball_y = 0;
    ball_x = 63;

    score_marker ();
  } 

  // Ball missed
  if (ball_y > 64){
    hearts--;
    ball_y = 0;
    ball_x = 63;
    draw_hearts ();
  }
  
  //Draw the pixel
  display.drawPixel (prev_ball_x ,prev_ball_y, BLACK);
  display.drawPixel (ball_x ,ball_y, WHITE);
  display.display ();
  prev_ball_x = ball_x;
  prev_ball_y = ball_y;
}

//Functions to show score marker
void score_marker (){
  display.setCursor (0,0);
  display.setTextColor (WHITE, BLACK);
  display.println("Score:" + String (score) );
  display.display ();
  tone (buzzer, 5000, 150);
  draw_level ();
}

//Functions to show level up
void draw_level (){
  display.setCursor (60,0);
  display.setTextColor (WHITE, BLACK);
  display.println("Lvl:" + String (level) );
  display.display ();
}

//Functions to show hearts
void draw_hearts (){
  display.setCursor (100,0);
  display.setTextColor (WHITE, BLACK);
  display.println("<3:" + String (hearts) );
  display.display ();
  tone (buzzer, 1000, 100);
  delay (50);
  tone (buzzer, 800, 100);
  delay (50);
  tone (buzzer, 500, 100);
  delay (50);
  tone (buzzer, 250, 200);

  //To show the Game Over screen
  if (hearts == 0 ){
    hearts = 3;
    level = 1;
    score = 0;
    cursor_size = 30;
    display.clearDisplay ();
    display.setCursor (0,28);
    display.println ("  G A M E   O V E R ");
    display.display();
    tone (buzzer, 255, 1000);
    delay (3000);
    display.clearDisplay ();
    display.display();
    play = false;
  }
}


//Function to press start
void button_presed (){
  play = true;
}