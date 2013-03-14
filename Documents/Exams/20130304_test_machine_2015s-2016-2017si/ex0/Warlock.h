#ifndef WARLOCK_H_
#define WARLOCK_H_

#include <string>

class Warlock
{
  std::string name;
  std::string title;

  Warlock(Warlock const &);
  Warlock const & operator=(Warlock const &);
 public:
  Warlock(std::string _name, std::string _title);
  ~Warlock();

  std::string getName() const;
  std::string getTitle() const;

  void setTitle(std::string title);
  void introduce() const;
};

#endif
