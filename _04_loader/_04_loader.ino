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

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

#define ARRAY_SIZE(x)  (sizeof(x)/sizeof(x[0]))

// Global data
typedef struct
{
  textEffect_t  effect;   // text effect to display
  char *        psz;      // text string nul terminated
  uint16_t      speed;    // speed multiplier of library default
  uint16_t      pause;    // pause multiplier for library default
} sCatalog;

sCatalog  catalog[] =
{
  { PA_SCROLL_DOWN, "man", 3, 2 },
  { PA_SCROLL_DOWN, "design", 3, 2 },
  { PA_SCROLL_DOWN, "branding", 3, 2 },
  { PA_SCROLL_DOWN, "advertising", 3, 2 },
  { PA_SCROLL_DOWN, "typography", 3, 2 },
  { PA_SCROLL_DOWN, "photography", 3, 2 },
  { PA_SCROLL_DOWN, "illustration", 3, 2 },
  { PA_SCROLL_DOWN, "editorial", 3, 2 },
  { PA_SCROLL_DOWN, "video", 3, 2 },
  { PA_SCROLL_DOWN, "print", 3, 2 },
  { PA_SCROLL_DOWN, "web", 3, 2 },
};


void setup(void)
{
  P.begin();
  P.setInvert(false);

  for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++)
  {
    catalog[i].speed *= P.getSpeed();
    catalog[i].pause *= 500;
  }
}

void loop(void) {

  textPosition_t just;
  just = PA_LEFT;

  for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++) {
    P.displayText(catalog[i].psz, just, catalog[i].speed, catalog[i].pause, catalog[i].effect, catalog[i].effect);

    while (!P.displayAnimate())
      ; // animates and returns true when an animation is completed

    delay(catalog[i].pause);
  }
}
