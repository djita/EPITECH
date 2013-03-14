/*
** Object.h for Object in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan 19 11:36:54 2013 lyoma guillou
** Last update Sat Jan 19 14:04:40 2013 lyoma guillou
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include <string>

class Object
{
 protected:
  bool Taken;
  std::string Title;

 public:
  Object(std::string const &title = "");
  virtual ~Object(void);
  
  std::string const & getTitle(void) const;
};

#endif
