#include <Sensor.hh>

/*
 * Reads one double from the PH Sensor
 */
double readPh()
{
  double voltage;

  voltage = analogRead(PH_READ);

  return 5 * VOLT_MULTIPLIER_PH * voltage / 1024 + CAL_OFFSET_PH;
}

double readSoil()
{
  return analogRead(SOIL_READ);
}

double readRaindrop()
{
  if(digitalRead(RAINDROP_D))
  {
    return(analogRead(RAINDROP_READ));
  }
  return -1;
}