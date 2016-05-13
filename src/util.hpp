#include "Arduino.h"

// Config almacena la configuración general
struct Config {
  uint8_t hour;   // Hora a la cual debe encenderse el Sol
  uint8_t minute; // Minuto dentro de la hora en la cual debe encenderse el Sol
  uint8_t interval; // Tiempo que debe estar encendido el Sol
};

Config LoadConfig();
Config LoadEEPROMConfig();
