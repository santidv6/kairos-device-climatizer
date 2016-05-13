#include "kairos-sun.hpp"

KairosSun::KairosSun(const uint8_t relay) { this->relay = relay; }

/**
 * Ajusta la hora y el minuto del día en el que se actiará el relé.
 * @param  hour   Hora del día en el que se activa el relé
 * @param  minute Minuto dentro de la hora en el que se activará el relé
 * @return        Cero si no hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetStartTime(uint8_t hour, uint8_t minute) {
  // TODO

  return 0;
}

/**
 * Ajusta la duración del estado ON del relé.
 * @param  interval Tiempo que está el relé en estado ON
 * @return          Cero si hay error, diferente de cero en caso contrario
 */
uint8_t KairosSun::SetInterval(uint8_t interval) {
  // TODO

  return 0;
}

/**
 * Comieza a contar el tiempo con las configuración actual
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
