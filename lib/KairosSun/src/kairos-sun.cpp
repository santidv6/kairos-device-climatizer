#include "kairos-sun.hpp"
#include "Wire.h"
#include "RTClib.h"
#include "TimerOne.h"

KairosSun::KairosSun(const uint8_t relay) { this->relay = relay; }

/**
 * Ajusta la hora y el minuto del día en el que se actiará el relé.
 * @param  hour_on   Hora del día en el que se activa el relé
 * @param  minute_on Minuto dentro de la hora en el que se activará el relé
 * @return        Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetSunrise(uint8_t hour_on, uint8_t minute_on) {
  // TODO
	time_in_min_on = hour_on * 60 + minute_on;
  return 0;
}

/**
 * Ajusta la hora y el minuto del día en el que se desactivará el relé.
 * @param  hour_off   Hora del día en el que se desactiva el relé
 * @param  minute_off Minuto dentro de la hora en el que se desactivará el relé
 * @return        Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetSunset(uint8_t hour_off, uint8_t minute_off) {
  // TODO
	time_in_min_off = hour_off * 60 + minute_off;
  return 0;
}

/**
 * Comieza a contar el tiempo con la configuración actual
 * @return Cero si hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::Start() {
  // TODO
	
	
	
  return 0;
}

/**
 * Para el conteo del tiempo actual y vuelve a activarlo usando una nueva
 * configuración.
 * @return Cero si hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::Reload() {
  // TODO

  return 0;
}

void KairosSun::Interrupt() {
	counter^=1;
}