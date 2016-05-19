#include "Arduino.h"

/**
 * Objeto que controla el Sol en función del tiempo.
 */
class KairosSun {
  uint8_t relay;
  uint8_t hour_on;
  uint8_t minute_on;
  uint8_t hour_off;
  uint8_t minute_off;
  uint8_t time_in_min_on;
  uint8_t time_in_min_off;
  uint8_t SunState;
  uint8_t counter = 0;
  uint8_t previous_counter = 0;
  uint8_t interrupt_period;

public:
  KairosSun(const uint8_t relay);
  uint8_t SetSunrise(uint8_t hour_on, uint8_t minute_on);
  uint8_t SetSunset(uint8_t hour_off, uint8_t minute_off);
  uint8_t Start();
  uint8_t Reload();
  uint8_t Interrupt();
};
