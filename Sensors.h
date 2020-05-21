#include <Ultrasonic.h>

#define PORTA_TRIGGER 2
#define PORTA_ECHO 4

/* 
*  https://circuits4you.com
*  ESP32 Internal Temperature Sensor Example
*/
#ifdef __cplusplus
  extern "C" {
#endif

uint8_t temprature_sens_read();

#ifdef __cplusplus
}
#endif
 
uint8_t temprature_sens_read();
/* 
*/

Ultrasonic ultrasonic(PORTA_TRIGGER, PORTA_ECHO);
