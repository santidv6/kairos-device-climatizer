
/*
Título: RTC_Arduino, Interrupciones por tiempo y uso de relé para encendido de bombillas.
Descripción: Uso básico del reloj RTC DS1307 (RTCLIB.h), uso de interrupciones (TimerOne.h) y de relé.
Autor: frankamente
Fecha: 11/05/2016
URL: https://github.com/frankamente
email: fran29400@gmail.com
Referencia: http://www.tuelectronica.es/tutoriales/arduino/reloj-rtc-i2c-con-arduino.html  http://www.prometec.net/timers/
*/

#include <Wire.h> 
#include "RTClib.h"
#include <TimerOne.h>

#define rele 12  // Pin asociado a la entrada 2 del Relé

int estadoLuz = LOW;    // La luz empieza apagada

int contador=0; //Variables usadas en la interrupción
int contadorAnterior=0;

int hora_on =8; //Hora a la que se enciende
int minutos_on =0; //Minuto al que queremos que se encienda
int h_to_min_on= hora_on * 60 + minutos_on;

int hora_off =22;//Horas que queremos que esté encendida
int minutos_off = 0; //Minutos que queremos que esté encendida
int h_to_min_off= hora_off * 60 + minutos_off;

const long convertirAuSegundos = 1000000;
int segundos = 2; // Dispara cada 2 segundos la interrupción
RTC_DS1307 RTC;

void setup () {
   pinMode(rele, OUTPUT); //Declaramos el pin asociado al rele como salida
   
   Timer1.initialize(segundos*convertirAuSegundos); //Inicializamos un timer.
   Timer1.attachInterrupt(interrupcion); // Activa la interrupcion y la asocia a ISR_Blink
   
   Wire.begin(); // Inicia el puerto I2C
   RTC.begin(); // Inicia la comunicación con el RTC
   //RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
   
   Serial.begin(9600); // Establece la velocidad de datos del puerto serie
   
   if(estadoLuz==LOW)
     digitalWrite(rele,HIGH);
   else
     digitalWrite(rele,LOW);
}

void interrupcion()
   {
       contador^=1;    ;     // Toggle del valor de contador (0/1)
   }

void loop(){

  //if (blinkCount%2 == 0){ //Cada 2 Segundos
    if (contador!=contadorAnterior){
      contadorAnterior=contador;
    DateTime now; //Declaramos una variable tipo DateTime llamada now
    now = RTC.now(); //  Leemos la hora del reloj 
//         Serial.print(now.unixtime()); //seconds from 1/1/1970
//         Serial.print("\t");
//         Serial.print(now.day(), DEC); // Dia
//         Serial.print(' ');
//         Serial.print(now.hour(), DEC); // Horas
//         Serial.print(':');
//         Serial.print(now.minute(), DEC); // Minutos
//         Serial.print(':');
//         Serial.print(now.second(), DEC); // Segundos
//         Serial.println(); 
       
     if (now.hour()*60 + now.minute() >= h_to_min_on && now.hour()*60 + now.minute()<h_to_min_off && estadoLuz == LOW){
       
       estadoLuz=HIGH;
       Serial.println("Encendida");
       digitalWrite(rele,LOW);
       
     }
    if ((now.hour()*60 + now.minute() >= h_to_min_off && now.hour()*60 + now.minute()<1440 || now.hour()*60 + now.minute() > 0 && now.hour()*60 + now.minute()<h_to_min_on) && estadoLuz == HIGH){
      
      estadoLuz=LOW;
      Serial.println("Apagada");
      digitalWrite(rele,HIGH);
      
    }
  }

}

