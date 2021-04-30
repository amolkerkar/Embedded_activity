
/**
 * @file act4.c
 * @author Amol Kerkar
 * @brief

 * @version 0.1
 * @date 2021-04-29
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>
int temperature;

/** \brief In USARTInit function the initialization of UART registers are done
 *
 * \param ubrr_value uint16_t
 * \return void
 *
 */
void USARTInit(uint16_t ubrr_value)
{
    //set baud-rate

    UBRR0L = ubrr_value;                                  // USART Baud Rate Register Low
    UBRR0H = (ubrr_value>>8)&0x00ff;                      // USART Baud Rate Register High only 4 LSB bits
    UCSR0C =(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);         // USART Control and Status Register in C // USART Mode Select(00 for Async) // Character Size

    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0); // Receiver Enable // Transmitter Enable // RX and TX Complete Interrupt Enable
}

/** \brief This USARTWriteChar function writes char data in serial monitor for transmitting
 *
 * \param data char
 * \return char
 *
 */
char USARTWriteChar(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))           // USART Data Register Empty and ready to receive
    {
        //DO NOTHING
    }
    UDR0 = data;                            // USART I/O Data Register (16 bits)
    return 0;
}

/** \brief In main function of act4 configuration of output port and writing the temp Serial monitor is being done
 *
 * \return void
 *
 */
void finalact()
{
DDRB|=(1<<PB1);
USARTInit(103);
    {
        USARTWriteChar(temperature);
        _delay_ms(100);
    }
}
