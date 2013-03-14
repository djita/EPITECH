#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

int main ()
{
  time_t rawtime;
  std::string _time;
  int i = 0;

  time(&rawtime);
  _time = ctime(&rawtime);
  std::istringstream iss(_time);

  while (iss)
    {
      std::string sub;
      iss >> sub;
      if (3 == i)
	std::cout << sub << std::endl;
      ++i;
    }
  std::cout << "seconds : " << rawtime << std::endl;
  std::cout << "miliseconds : " << rawtime * 100 << std::endl;
  return 0;
}
