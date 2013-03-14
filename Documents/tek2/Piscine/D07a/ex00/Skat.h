/*
** Skat.h for skat in /home/guillo_e//Documents/working/tek2/piscine/D07a/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan 15 17:19:40 2013 lyoma guillou
** Last update Tue Jan 15 18:09:28 2013 lyoma guillou
*/

#ifndef SKAT_H_
# define SKAT_H_

# include <string>

class			Skat
{
  std::string		_name;
  int			_nbStimPaks;

 public:
  Skat(void);
  Skat(std::string const& name, int stimPaks);
  ~Skat();

  int			stimPaks();
  const std::string&	name();
  
  void			shareStimPaks(int number, int *stock);
  void			addStimPaks(unsigned int number);
  void			useStimPaks();

  void			status();
};

#endif
