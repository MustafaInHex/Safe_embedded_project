#ifndef BUZZER_H_
#define BUZZER_H_

void BUZZER_initialize(unsigned char port, unsigned char pin);
void BUZZER_on(unsigned char port, unsigned char pin);
void BUZZER_off(unsigned char port, unsigned char pin);
void BUZZER_toggle(unsigned char port, unsigned char pin);
unsigned char BUZZER_status(unsigned char port, unsigned char pin);



#endif /* BUZZER_H_ */