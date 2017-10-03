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

#define DEBUG 1

MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void){

  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("start");
  #endif

  P.begin(2);
  P.setInvert(false);

  P.setZone(ZONE_LEFT,0,1);
  P.setZone(ZONE_RIGHT,2,3);

  P.displayZoneText(ZONE_RIGHT, "R", PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
  P.displayZoneText(ZONE_LEFT, "L", PA_LEFT, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop(void){
  Serial.println("loop");
  // P.displayAnimate();
  delay(300);
}
