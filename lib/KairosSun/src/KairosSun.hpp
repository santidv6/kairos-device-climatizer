#include <Arduino.h>

/**
 * Objeto que controla el Sol en función del tiempo.
 */
class KairosSun {
public:
  KairosSun(const uint8_t relay);
  uint8_t SetStartTime(uint8_t hour, uint8_t minute);
  uint8_t SetInterval(uint8_t interval);
  uint8_t Start();
  uint8_t Reload();
  void interrupt();
  
  uint8_t relay;
  uint8_t hour_on;
  uint8_t minute_on;
  uint8_t interval;
  uint8_t hour_off;
  uint8_t minute_off;
  uint8_t time_in_min_on;
  uint8_t time_in_min_off;
  uint8_t counter;
  uint8_t previous_counter;
  uint8_t interrupt_period;
  uint8_t SunState;


};
