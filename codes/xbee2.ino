#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void uart0_init(void)
{
 UCSR0B = 0x00; //disable while setting baud rate
 UCSR0A = 0x00;
 UCSR0C = 0x06;
 UBRR0L = 0x5F; //set baud rate lo
 UBRR0H = 0x00; //set baud rate hi
 UCSR0B = 0xE8;
}
void init_devices()
{
cli(); //Clears the global interrupts

uart0_init(); //Initialize UART1 for serial communication
sei(); //Enables the global interrupts
}
int flag=0;
SIGNAL (SIG_UART0_DATA)
{flag=1;
UDR0 = 'A';}
SIGNAL (SIG_UART0_TRANS)
{
  flag=2;
}

int main()
{

  init_devices();
  while(1);
}


