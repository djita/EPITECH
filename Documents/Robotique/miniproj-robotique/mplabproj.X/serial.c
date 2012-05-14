#include <p18cxxx.h>
#include "serial.h"
#include "type.h"

void putchar(unsigned char data)
{
	if (PIR1bits.TXIF)
		TXREG = data;
	while (PIR1bits.TXIF);
}