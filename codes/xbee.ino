#include <avr/io.h>
#include <avr/interrupt.h>
void usart_init(void);
void usart_tx(unsigned char msg);


int main(void)
{usart_init();
while(1){
 
usart_tx('6');             //increment count after transmission of first character
}}
void usart_init()
{
 SREG|=0x80;
 UCSR0A=0X00;                      //set global interrupt enable bit
 UCSR0B=0X00; 
 UBRR0H=0x00;
 UBRR0L=0X5F;                      //baud rate 4800, % error 0.2 %
 UCSR0B|=(1<<TXEN0)|(1<<RXEN0);   //enable transmitter, receiver, enable transmit complete interrupt
 UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);         //8-bit data, 1 stop bit, parity disabled, asynchronous operation
}
void usart_tx(unsigned char msg)
{
 while(!(UCSR0A & (UCSR0A|=1<<UDRE0)))               //wait until transmit buffer becomes empty 
{UDR0=msg;
 
 }//transmit first character by polling 
}

 
 
