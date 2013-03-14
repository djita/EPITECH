//
// Federation.hh for federation in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 09:20:41 2013 lyoma guillou
// Last update Tue Jan 15 15:27:14 2013 lyoma guillou
//

#ifndef FEDERATION_H_
# define FEDERATION_H_

# include <string>

# include "Warpsystem.hh"

namespace		Federation
{
  namespace			Starfleet
  {
    class			Ensign
    {
      std::string		_name;

    public:
      explicit Ensign(std::string);
      ~Ensign();
    };

    class			Captain
    {
      std::string		_name;
      int			_age;

    public:
      Captain(std::string);
      ~Captain();

      std::string		getName();
      int			getAge();
      void			setAge(int);
    };

    class			Ship
    {
      int			_length;
      int			_width;
      std::string		_name;
      short			_maxWarp;

      WarpSystem::Core		*core;

      class Captain		*captain;
      
    public:
      Ship(int, int, std::string, short);
      ~Ship();

      void			setupCore(WarpSystem::Core *);
      void			checkCore(void);
      void			promote(Captain *);
    };
  }

  class			Ship
  {
    int			_length;
    int			_width;
    std::string		_name;
    short		_maxWarp;
    
    WarpSystem::Core	*core;
    
  public:
    Ship(int, int, std::string);
    ~Ship();

    void		setupCore(WarpSystem::Core *);
    void		checkCore(void);
  };
}

#endif
