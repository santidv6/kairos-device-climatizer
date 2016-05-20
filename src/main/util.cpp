#include "util.hpp"

enum sources { EEPROM, DEFAULt };

const int source = DEFAULt;

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
	case DEFAULt:
	config = LoadDEFAULtConfig();
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

/**
 * Carga la configuración general por defecto
 * @return configuración cargada.
 */
Config LoadDEFAULtConfig() {
  struct Config config;

  config.hour = 12;
  config.minute = 0;
  config.interval = 8*60;

  return config;
}
