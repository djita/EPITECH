//
// Warpsystem.hh for warpsystem in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 09:40:00 2013 lyoma guillou
// Last update Tue Jan 15 14:11:56 2013 lyoma guillou
//

#ifndef WARPSYSTEM_H_
# define WARPSYSTEM_H_

namespace			WarpSystem
{
  class				QuantumReactor
  {
    bool			_stability;

  public:
    QuantumReactor(void);
    ~QuantumReactor(void);

    bool			isStable();
    void			setStability(bool);
    
  };

  class				Core
  {
    class QuantumReactor	*_coreReactor;

  public:
    Core(QuantumReactor *);
    ~Core();

    QuantumReactor		*checkReactor();
  };
};

#endif
