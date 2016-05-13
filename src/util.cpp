#include "util.hpp"

enum sources { EEPROM };

const int source = EEPROM;

/**
 * Carga la configuración general.
 * @return configuración cargada
 */
Config LoadConfig() {
  struct Config config;

  switch (source) {
  case EEPROM:
    config = LoadEEPROMConfig();
    break;
  }

  return config;
}

/**
 * Carga la configuración general de la EEPROM
 * @return configuración cargada.
 */
Config LoadEEPROMConfig() {
  struct Config config;

  // TODO

  return config;
}
