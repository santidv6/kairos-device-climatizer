#include "KairosSun.hpp"
#include <Wire.h>
#include <RTClib.h>
#include <TimerOne.h>
RTC_DS1307 RTC;

KairosSun::KairosSun(const uint8_t relay) { this->relay = relay; }

/**
 * Ajusta la hora y el minuto del día en el que se actiará el relé.
 * @param  hour   Hora del día en el que se activa el relé
 * @param  minute Minuto dentro de la hora en el que se activará el relé
 * @return Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetStartTime(uint8_t hour_on, uint8_t minute_on) {
	// TODO

	return 0;
}

/**
 * Ajusta la duración del estado ON del relé.
 * @param  interval Tiempo que está el relé en estado ON
 * @return Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetInterval(uint8_t interval) {
	// TODO

	return 0;
}

/**
 * Comieza a contar el tiempo con las configuración actual
 * @return Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::Start() {
  // TODO
	this->time_in_min_on= this->hour_on * 60 + this->minute_on;
	this->time_in_min_off= this->time_in_min_on + this->interval;
	this->SunState = LOW;
	this->counter = 0;
	this->previous_counter = 0;
	this->interrupt_period = 2;
	pinMode(this->relay,OUTPUT);
	
	Timer1.initialize(this->interrupt_period*1000000);
	Timer1.attachinterrupt(KairosSun::interrupt);
	
	Wire.begin();
	RTC.begin();
	//RTC.adjust(DateTime(F(__DATE__),F(__TIME__)));
	
	Serial.begin(9600);
	
	if(!this->SunState)
		digitalWrite(this->relay,HIGH);
	else
		digitalWrite(this->relay,LOW);
	
	return 0;
}

/**
 * Para el conteo del tiempo actual y vuelve a activarlo usando una nueva
 * configuración.
 * @return Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::Reload() {
  // TODO

  return 0;
}

void KairosSun::interrupt(){
	  DateTime now; //Declaramos una variable tipo DateTime llamada now
    now = RTC.now(); //  Leemos la hora del reloj 
    //Serial.print(now.unixtime()); //seconds from 1/1/1970
    //Serial.print("\t");
    //Serial.print(now.day(), DEC); // Dia
    //Serial.print(' ');
    //Serial.print(now.hour(), DEC); // Horas
    //Serial.print(':');
    //Serial.print(now.minute(), DEC); // Minutos
    //Serial.print(':');
    //Serial.print(now.second(), DEC); // Segundos
    //Serial.println();
    
    if (now.hour()*60 + now.minute() >= this->time_in_min_on && now.hour()*60 + now.minute()<this->time_in_min_off && this->SunState == LOW){
       
       this->SunState = HIGH;
       Serial.println("Encendida");
       digitalWrite(this->relay,LOW);
       
    }
    if ((now.hour()*60 + now.minute() >= this->time_in_min_off && now.hour()*60 + now.minute()<1440 || now.hour()*60 + now.minute() > 0 && now.hour()*60 + now.minute()< this->time_in_min_on) && this->SunState == HIGH){
      
      this->SunState = LOW;
      Serial.println("Apagada");
      digitalWrite(this->relay,HIGH);
      
    }
}
