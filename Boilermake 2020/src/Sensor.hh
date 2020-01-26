#include <Arduino.h>

#define SOIL_READ 36
#define RAINDROP_READ 39
#define PH_READ 34
#define RAINDROP_D 23

#define CAL_OFFSET_PH 0

#define VOLT_MULTIPLIER_PH 3.5

double readPh();
double readSoil();
double readRaindrop();


