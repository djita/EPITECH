//
// Borg.hh for Borg in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex01
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 14:46:25 2013 lyoma guillou
// Last update Tue Jan 15 15:19:07 2013 lyoma guillou
//

#ifndef BORG_H_
# define BORG_H_

# include <string>

# include "Warpsystem.hh"

namespace		Borg
{
  class			Ship
  {
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*core;

  public:
    Ship(void);
    ~Ship();

    void		setupCore(WarpSystem::Core *);
    void		checkCore(void);
  };
};

#endif
