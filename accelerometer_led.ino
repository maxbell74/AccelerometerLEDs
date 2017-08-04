/** 
 *  This little sketch is the first example of using The Tactigon Board
 *  It will change leds color based on orientation
 *  More informations, and video, available at: 
 *  https://thetactigon.com/steps-towards-gesture-controller-part-i
 */

#include <tactigon_led.h>
#include <tactigon_IMU.h>
#include <IMU_main.h>

T_Led rLed, bLed, gLed;
T_ACC accMeter;
T_AccData accData;

void setup() {
  /* LEDs initialization */
  rLed.init(T_Led::RED);
  gLed.init(T_Led::GREEN);
  bLed.init(T_Led::BLUE);
  
  /* Turn off LEDs */
  rLed.off();
  gLed.off();
  bLed.off();
}

void loop() {
  /* Refresh IMU data */
  IMU_loop();

  /* Get Current Accelerometer Data */
  accData = accMeter.getAxis();

  /* Turn the led on if acceleration on the axis is > 500 milli g */
  if (abs(accData.x) > 500)
    rLed.on();
  else
    rLed.off();
    
  if (abs(accData.y) > 500)
    gLed.on();
  else
    gLed.off();
    
  if (abs(accData.z) > 500)
    bLed.on();
  else
    bLed.off();
}

