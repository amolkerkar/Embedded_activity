/**
* @file act3.c
 * @author Amol Kerkar
 * @brief Activity-3 of Seat heater
 * @version 0.1
 * @date 2021-04-28
* @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>
int temperature=0;
void finalact();
/** \brief Generating PWM pulse for controlling the temperature using Heater.Recieving input from ADC register and using Output Compare Match register
 *
 * \param void
 * \return int
 *
 */
int thirdact(void)
{
TCCR1A=(1<<COM1A1)|(1<<WGM11)|(WGM10);          // Timer/Counter 1 Control Register A // Compare output mode for channel A
TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);          // Waveform Generation Mode bits      // Clock Select Bits
DDRB|=(1<<PB1);

PORTB |= (1<<PB1);

    {
        if(ADC <=200)
        {
         temperature = 20;
        finalact(); //calling activity 4
         OCR1A=102;                             // Output Compare Register A stores TOP value
         _delay_ms(200);
        }
        else if(ADC <= 500)
        {
         temperature = 25;
         finalact(); //calling activity 4
         OCR1A=204;
         _delay_ms(200);
        }
        else if(ADC <= 700)
        {
         temperature = 29;
        finalact(); //calling activity 4
         OCR1A=358;
         _delay_ms(200);
        }
        else if(ADC <= 1024)
        {
         temperature = 33;
         finalact(); //calling activity 4
         OCR1A=484;
         _delay_ms(200);
        }
    }
    return temperature;
}
