//Libraries to use Display ssd1306
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define pin reset
Adafruit_SSD1306 display (-1);

//Setup funcition 
void setup (){
  Serial.begin (9600);

  //Initialize display for AxAA direction
  display.begin (SSD1306_SWITCHCAPVCC, 0x3C);


  //Clear display
  display.clearDisplay ();
  
  display.fillRoundRect (0,0,127,15,6,WHITE);
  display.fillRoundRect (10,16,117,43,20,WHITE);
  display.fillRect (20,21,87,28,BLACK);
  display.drawRect (30,26,57,13,WHITE);
  display.drawRoundRect (40,31,27,5,3,WHITE);
  display.drawRect (50,36,7,3,WHITE);
  display.fillTriangle (63,16,33,63,93,63,WHITE);
  display.fillTriangle (63,20,38,59,89,59,BLACK);

  display.setTextSize (1);
  display.setTextColor (BLACK);
  display.setCursor (30,5);
  display.println ("HELLO WORLD");
  display.display ();

}

//Loop function 
void loop () {

  
}


//Functions dictionary for Display SSD1306

/*
Adafruit_SSD1306 display (-1); --> Definir el pin de reset, se usa -1 si no tiene

display.clearDisplay (); --> Limpiar pantalla

display.display (); --> Enviar la información a la pantalla

display.drawPixel (63, 31, WHITE); --> Dibujar un pixel en una direción dada

display.drawRect (10,10,80,30,WHITE); --> Dibujat un rectangualo (X,Y,Ancho,Largo,Color)

display.fillRect (10,16,117,43,BLACK); --> Rellena un rectangualo  (X,Y,Ancho,Largo,Color)

display.drawRoundRect (10,10,80,30,WHITE); --> Dibujat un rectangualo (X,Y,Ancho,Largo,radio,Color)

display.fillRoundRect (10,16,117,43,BLACK); --> Rellena un rectangualo  (X,Y,Ancho,Largo,radio,Color)

display.drawTriangle (63,16,33,63,93,63,WHITE); --> Dibuja un triangulo (coordenadas de vertices y color)

display.fillTriangle (63,16,33,63,93,63,WHITE); --> Dibuja un triangulo (coordenadas de vertices y color)

display.setTextSize (1); --> Define el tamaño de la fuente

display.setTextColor (BLACK); --> Define el el color de relleno del texto

display.setTextColor (BLACK,WHITE); --> Texto negro fondo blanco

display.setCursor (0,0); --> Define la posición del texto

display.println ("Hello world"); --> Texto a escribir con salto de linea


*/