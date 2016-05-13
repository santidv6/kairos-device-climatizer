#include "util.hpp"
#include <kairos-sun.hpp>

// Variables globales
const uint8_t RELAY = 12;
const uint8_t DEFAULT_HOUR = 0;
const uint8_t DEFAULT_MINUTE = 0;
const uint8_t DEFAULT_INTERVAL = 0;

// Inicialización de librerías
KairosSun Sun(RELAY);

void setup() {
  // Carga la configuración
  Config config = LoadConfig();

  // Activa el Sol
  Sun.SetStartTime(config.hour, config.minute);
  Sun.SetInterval(config.interval);
  Sun.Start();
}

void loop() {}
