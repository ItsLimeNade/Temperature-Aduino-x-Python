/* YOU WILL HAVE TO DOWNLOAD THAT FOR YOUR ARDUINO TO WORK
You can find them in packages folder in the project!

#include <LiquidCrystal.h>
#include <dht_nonblocking.h>


#define DHT_SENSOR_TYPE DHT_TYPE_11
LiquidCrystal lcd(12,11,5,4,3,2);

static const int DHT_SENSOR_PIN = 6;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup() {
    Serial.begin( 9600);
    lcd.begin(16,2);
    lcd.print("T:");
    lcd.setCursor(0,1);
    lcd.print("H:");
}

static bool measure_environment( float *temperature, float *humidity )
{
    static unsigned long measurement_timestamp = millis( );


    if( millis( ) - measurement_timestamp > 3000ul )
{
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
        measurement_timestamp = millis( );
        return( true );
    }
    }

    return( false );
}


void loop() {
    float temperature;
    float humidity;
        if( measure_environment( &temperature, &humidity ) == true )
    {
    lcd.clear();
    lcd.print( "T = " );
    lcd.print( temperature, 1 );
    lcd.print( " deg. C" );
    lcd.setCursor(0,1);
    lcd.print("H = ");
    lcd.print( humidity, 1);
    lcd.print("%");
    Serial.print(temperature,1);
    Serial.print(",");
    Serial.print(humidity,1);
    Serial.println("");
    }
}
*/
