#include "Arduino.h"

/**
 * Objeto que controla el Sol en función del tiempo.
 */
class KairosSun {
  uint8_t relay;
  uint8_t hour;
  uint8_t minute;
  uint8_t interval;

public:
  KairosSun(const uint8_t relay);
  uint8_t SetStartTime(uint8_t hour, uint8_t minute);
  uint8_t SetInterval(uint8_t interval);
  uint8_t Start();
  uint8_t Reload();
};
