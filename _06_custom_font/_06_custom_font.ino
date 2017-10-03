// Program to show full catalog of the MD_Parola animations
//
// NOTE: MD_MAX72xx library must be installed and configured for the LED
// matrix type being used. Refer documentation included in the MD_MAX72xx
// library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

#define MAX_ZONES 2
#define ZONE_RIGHT 1
#define ZONE_LEFT 0

#define SPEED_TIME  25
#define PAUSE_TIME  1000

uint8_t degC[] = { 2, 171, 84}; // Deg C

MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin(2);
  P.setInvert(false);

  P.setZone(ZONE_LEFT,0,1);
  P.setZone(ZONE_RIGHT,2,3);

  #ifdef DEBUG
    Serial.begin(9600);
  #endif

  P.displayZoneText(ZONE_RIGHT, "c", PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
  P.addChar('c', degC);
  P.displayZoneText(ZONE_LEFT, "c", PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop(void) {

  while (!P.getZoneStatus(ZONE_RIGHT))
    P.displayAnimate();

}
