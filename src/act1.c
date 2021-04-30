/**
 * @file act1.c
 * @author Amol Kerkar
 * @brief

 * @version 0.1
 * @date 2021-04-27
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>

/** \brief main function of act1 is sensing the occupance of the seat and the manual heater and turning the dummy heater i.e. Led ON or OFF
 *
 * \return void
 *
 */
void firstact()
{
DDRB |= (1<<PB0); // set PortB0=1; set bit for Led output      // PortB Data Direction Register

DDRD &=~(1<<PD2); // set PortD2=0; clear bit for input         // PortD Data Direction Register
PORTD |= (1<<PD2);

DDRD &=~(1<<PD3); // set PortD3=0; clear bit for input
PORTD |= (1<<PD3);

    {
        if(!(PIND&(1<<PD2))&&!(PIND&(1<<PD3)))                // PortD Input Pin Address
        {
        PORTB |=(1<<PB0);                                     // PortB Data Register
        }
        else
        {
        PORTB &=~(1<<PB0);                                    // PortB Data Register
        }
    }
}
