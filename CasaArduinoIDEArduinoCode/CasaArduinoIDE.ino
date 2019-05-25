#include <Servo.h>

const byte dormitorio = 2;
const byte sanitario= 3;
const byte comedor= 4;
const byte sala = 5;
Servo plumilla;
Servo puerta;
char letra;
String accion;

void setup() {
  pinMode(dormitorio, OUTPUT);
  pinMode(sanitario, OUTPUT);
  pinMode(comedor, OUTPUT);
  pinMode(sala, OUTPUT);
  plumilla.attach(9);
  plumilla.write(0);
  puerta.attach(10);
  puerta.write(180);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0)
  {
    letra= Serial.read();
    accion.concat(letra);
    delay(10);
  }
//Dormitorio
  if(accion.equals("encendido1")==true)
  {
    digitalWrite(dormitorio, HIGH);//Encendemos la luz del dormitorio
  }

   if(accion.equals("apagado1")==true)
  {
    digitalWrite(dormitorio, LOW);//Apagamos la luz del dormitorio
  }
//Sanitario
  if(accion.equals("encendido2")==true)
  {
    digitalWrite(sanitario, HIGH);//Encendemos la luz del dormitorio
  }

   if(accion.equals("apagado2")==true)
  {
    digitalWrite(sanitario, LOW);//Apagamos la luz del dormitorio
  }

 //Comedor
   if(accion.equals("encendido3")==true)
  {
    digitalWrite(comedor, HIGH);//Encendemos la luz del dormitorio
  }

   if(accion.equals("apagado3")==true)
  {
    digitalWrite(comedor, LOW);//Apagamos la luz del dormitorio
  }

  //Sala
   if(accion.equals("encendido4")==true)
  {
    digitalWrite(sala, HIGH);//Encendemos la luz del dormitorio
  }

   if(accion.equals("apagado4")==true)
  {
    digitalWrite(sala, LOW);//Apagamos la luz del dormitorio
  }

  //Plumilla
  if(accion.equals("arriba"))
  {
    plumilla.write(90); //Levantamos la plumilla 
  }
  if(accion.equals("abajo"))
  {
    plumilla.write(0); //Bajamos la plumilla 
  }

  //Puerta
  if(accion.equals("abierto"))
  {
    puerta.write(90); //abrimos la puerta
  }
  if(accion.equals("cerrado"))
  {
    puerta.write(180); //cerramos la puerta
  }
  accion="";

}
