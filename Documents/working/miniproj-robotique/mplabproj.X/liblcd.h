/*
** liblcd.h for mplabproj.X in /home/falck_m/Work/miniproj-robotique/mplabproj.X
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Apr 04 15:11:15 2012 mickael falck
** Last update Thu Apr 12 16:27:02 2012 mickael falck
*/

#ifndef LIBLCD_H_
#  define LIBLCD_H_

void    delay(int ms);
void DelayPORXLCD(void);
void DelayFor18TCY(void);
void DelayXLCD(void);
int lcd_putram(char *buffer, int line, int col);
int lcd_putrom(const rom char *buffer, int line, int col, int len);

#endif /* !LIBLCD_H_ */
