//
// main.cpp for tempConversion in /home/guillo_e//Documents/working/tek2/piscine/D06/ex01
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Mon Jan 14 14:27:33 2013 lyoma guillou
// Last update Mon Jan 14 15:05:17 2013 lyoma guillou
//

#include <iostream>
#include <iomanip>

int		main()
{
  std::string	str;
  float		t;


  std::cin >> t >> str;
  if (str == "Celsius")
    {
      str = "Fahrenheit";
      t = (t * 9 / 5) + 32;
    }
  else if (str == "Fahrenheit")
    {
      str = "Celsius";
      t = (t - 32) * 5.0 / 9.0;
    }
  std::cout << std::fixed;
  std::cout << std::setw(16) << std::setprecision(3) << t;
  std::cout << std::setw(16) << str << std::endl;
}
