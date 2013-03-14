/*
** main.c for my_cat in /home/guillo_e//Documents/working/tek2/piscine/D06/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan 14 13:47:46 2013 lyoma guillou
// Last update Mon Jan 14 17:26:23 2013 lyoma guillou
*/

#include <fstream>
#include <iostream>

int		main(int ac, char **av)
{
  std::fstream	filestr;
  std::string	str;

  if (ac != 1)
    {
      for (int i = 0; i < ac - 1; ++i)
	{
	  filestr.open(av[i + 1], std::fstream::in | std::fstream::out);
	  if (filestr.is_open())
	    {
	      while (getline(filestr, str))
		std::cout << str << std::endl;
	      filestr.close();
	    }
	  else
	    {
	      std::cerr << "my_cat: ";
	      std::cerr << av[i + 1];
	      std::cerr << ": No such file or directory" << std::endl;	      
	    }
	}
    }
  else
    std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
}
