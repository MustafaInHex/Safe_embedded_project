#ifndef LED_H_
#define LED_H_

void LED_initialize(unsigned char port, unsigned char pin);
void LED_on(unsigned char port, unsigned char pin);
void LED_off(unsigned char port, unsigned char pin);
void LED_toggle(unsigned char port, unsigned char pin);
unsigned char LED_status(unsigned char port, unsigned char pin);
void LED_writefour(unsigned char port , unsigned char val , unsigned char nibble);

#endif /* LED_H_ */

