//Define pin for button and led
float temperature;

void setup(){
  Serial.begin (9600);
}

void loop (){
  delay(1000);
  temperature = analogRead(A0);
  float celsius = (temperature / 1024) * 500;
  Serial.print("Temperatura: " + String(celsius));
  Serial.println("°C");
}