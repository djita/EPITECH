/*
** serial.h for robot_tp in /home/falck_m/Work/robot_tp
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Thu Mar 01 14:42:03 2012 mickael falck
** Last update Mon Mar 05 16:09:54 2012 mickael falck
*/

#ifndef SERIAL_H_
#  define SERIAL_H_

unsigned char putchar(unsigned char data);
unsigned char getchar(unsigned char *data);
void    serial_write(void);
void    serial_read(void);

#endif /* !SERIAL_H_ */
