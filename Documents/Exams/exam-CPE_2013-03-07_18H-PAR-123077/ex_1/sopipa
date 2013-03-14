#!/bin/sh

if test -f $1 ; then 
    < $1; $2 | $3 > $4;
else
    touch $1;
    < $1; $2 | $3 > $4;
fi