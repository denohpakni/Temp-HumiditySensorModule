#include <Arduino.h>
#include <dht_nonblocking.h>

#define my_DHT_SENSOR_TYPE DHT_TYPE_11  //define the sensor type from the library

static const int DHT_SENSOR_PIN = 2;  // where the input pin is connected to.

DHT_nonblocking the_thing_dht_sensor( DHT_SENSOR_PIN, my_DHT_SENSOR_TYPE );

void setup( )
{
  Serial.begin(9600);
}
void loop( )
{
  float temperature;
  float humidity;

  if(the_thing_dht_sensor.measure(&temperature, &humidity)){
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}

