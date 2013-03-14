#include <p18cxxx.h>
#include "jobs.h"

void high_isr(void);

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
  _asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr(void)
{
  //job();
}
