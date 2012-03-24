/* 
 * File:   main.c
 * Author: falck_m
 *
 * Created on 22 March 2012, 14:35
 */

#include	<p18cxxx.h>
#include	"picdem2.h"
#include        "jobs.h"
#include        "init.h"

void    delay(void)
{
    int i;

    i = 0;
    while (i < 0x4000)
        ++i;
}

void main(void) {
    init_all();
    PORTB = 0b00001111;
    while (1)
    {
        job();
        delay();
    }
}

