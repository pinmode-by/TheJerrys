#include "Sensors.h"
#include "Motors.h"

Sensors sensors;
Motors motors;

void setup() {
	//sensors.init( 100000 );
	motors.init();
    sensors.init(50000);
  	Serial.begin( 57600 );
	while( !Serial );
	Serial.println( "Initializing" );
	motors.stop();
}

void loop() {
    static uint8_t speed = 70;
    if( Serial.available() > 0 ){
        char incomingChar = Serial.read();
        switch (incomingChar) {
            case 'a':
                motors.turnLeft();
                Serial.println( "Turning left");
                break;
            case 'd':
                motors.turnRight();
                Serial.println( "Turning right");
                break;
            case 'x':
                motors.stop();
                break;
            case 'w':
                motors.moveForward(200);
                Serial.println( "Moving forward ");
                break;
			case 'c':
				motors.tankTurnLeft( );
				Serial.println("Turning left tank style");
				break;
			case 'q':
				motors.tankTurnRight( );
				Serial.println("Turning right tank style");
				break;
            case '+':
                speed+=10;
                motors.setSpeed(speed);
                Serial.print( "Current speed is now: "); Serial.println( speed );
                break;
            case '-':
                speed-=10;
                motors.setSpeed(speed);
                Serial.print( "Current speed is now: "); Serial.println( speed );
                break;
			case 't':
				while( sensors.getLeftDistance() < 5 ) {
					motors.moveForward(100);
				} 
				motors.moveForward(175);
				motors.turnLeft();
				break;
			case 'u':
				motors.turnAround();
				Serial.println("Turning around");
				break;
        }
        motors.stop();
    }

    Serial.print( "Right Distance: " ); Serial.println( sensors.getRightDistance() );
    Serial.print( "Left Distance: " ); Serial.println( sensors.getLeftDistance() );
    Serial.print( "Middle Distance: " ); Serial.println( sensors.getMiddleDistance() );
	delay(100);	
}


