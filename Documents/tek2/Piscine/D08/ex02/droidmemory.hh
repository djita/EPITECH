//
// droidmemory.hh for droidmemory in /home/guillo_e//Documents/working/tek2/piscine/D08/ex01
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 13:53:18 2013 lyoma guillou
// Last update Wed Jan 16 15:44:12 2013 lyoma guillou
//

#ifndef DROIDMEMORY_H_
# define DROIDMEMORY_H_

# include <iostream>

class			DroidMemory
{
  size_t		FingerPrint;
  size_t		Exp;

public:
  DroidMemory();
  DroidMemory(DroidMemory const &);
  ~DroidMemory();

  size_t		getFingerPrint(void);
  size_t		getExp(void);
  void			setFingerPrint(size_t);
  void			setExp(size_t);

  void			operator<<(DroidMemory const &);
  void			operator>>(DroidMemory &);
  DroidMemory&		operator+=(DroidMemory const &);
  DroidMemory&		operator+=(size_t);
  DroidMemory&		operator+(DroidMemory const &);

  bool			operator==(DroidMemory const &);
  bool			operator!=(DroidMemory const &);

  bool			operator<=(DroidMemory const &);
  bool			operator<=(size_t);

  bool			operator>=(DroidMemory const &);
  bool			operator>=(size_t);

  bool			operator<(DroidMemory const &);
  bool			operator<(size_t);

  bool			operator>(DroidMemory const &);
  bool			operator>(size_t);
};

std::ostream&		operator<<(std::ostream&, DroidMemory &);

#endif
