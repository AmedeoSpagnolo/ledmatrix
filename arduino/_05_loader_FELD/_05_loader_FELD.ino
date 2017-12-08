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

#define DEBUG true

int _SPEED;

MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
MD_MAX72XX mx = MD_MAX72XX(DATA_PIN, MAX_DEVICES);

#define ARRAY_SIZE(x)  (sizeof(x)/sizeof(x[0]))

// Global data
typedef struct
{
  textEffect_t  effect;   // text effect to display
  char *        psz;      // text string nul terminated
  uint16_t      speed;    // speed multiplier of library default
  uint16_t      pause;    // pause multiplier for library default
} sCatalog;

char* catalog[] = {
  "man",
  "design",
  "branding",
  "advertising",
  "typography",
  "photography",
  "illustration",
  "editorial",
  "video",
  "print",
  "web",
};

int catalog_length(char* item)
{ 
    uint8_t  charWidth;
    int l = strlen(item);
    int temp = 0;
    for (uint8_t i=0; i<l; i++) {
      char this_char = item[i];
      int this_char_length = 5; // to fix
      int this_char_spacing = 1; // to fix
       temp += this_char_length + this_char_spacing;
    }
    return temp;
}

void setup(void)
{
  P.begin(2);
  P.setInvert(false);
  P.setZone(ZONE_LEFT,0,0);
  P.setZone(ZONE_RIGHT,1,3);

  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  Serial.println("START");
  P.displayZoneText(ZONE_RIGHT, "Feld", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop(void) {

  while (!P.getZoneStatus(ZONE_RIGHT))
    P.displayAnimate();

 for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++) {
   Serial.print(catalog[i]);
   Serial.print(" ");
   Serial.print(catalog_length(catalog[i]));
   Serial.println();
   P.displayZoneText(ZONE_LEFT, catalog[i], PA_LEFT, SPEED_TIME, PAUSE_TIME, PA_SCROLL_DOWN, PA_SCROLL_DOWN);
   while (!P.getZoneStatus(ZONE_LEFT))
      P.displayAnimate(); // animates and returns true when an animation is completed
   delay(300);
 }

}
