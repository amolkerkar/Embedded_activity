/**
 * @file act2.c
 * @author Amol Kerkar
 * @brief Activity-2 of Seat heater
 * @version 0.1
 * @date 2021-04-28
* @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>

/** \brief InitADC function does the initialization of the ADC
 *
 *
 * \return void
 *
 */
void InitADC()
{
    ADMUX = (1<<REFS0);                 // ADC Multiplexer Selection Register // Reference Selection Bit 0
    ADCSRA = (1<<ADEN)|(7<<ADPS0);      // ADC Control And Status Register A  // ADC Enable // ADC Prescaler Bit 0
}

/** \brief ReadADC function reads the analog voltage at the pin PC0 and converts and stores binary bits in the Register ADCL and  Register ADCH
 *
 * \param ch uint8_t
 * \return uint16_t
 *
 */
uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);                  // ADC Start Conversion
    while(!(ADCSRA & (1<<ADIF)));       // ADC Interrupt Flag
    ADCSRA|=(1<<ADIF);
    return(ADC);                        // ADCH and ADCL register
}

/** \brief main function of act-2 is reading the analog temperature sensor values and converting it into digital using the internal ADC
 *
 * \return void
 *
 */
void secondact()
{
    InitADC();
    {
        ReadADC(0);
    }
}
