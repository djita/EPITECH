//
// sickkoala.cpp for sickkoala in /home/guillo_e//Documents/working/tek2/piscine/D06/ex02
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Mon Jan 14 15:07:22 2013 lyoma guillou
// Last update Mon Jan 14 19:34:54 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name;
  std::cout << ": Kreooogg !! Je suis gueriii !" << std::endl;
}

void		SickKoala::poke()
{
  std::cout << "Mr." << this->name;
  std::cout << ": Gooeeeeerrk !! :’(" << std::endl;
}

bool		SickKoala::takeDrug(std::string drug)
{
  std::locale	loc;

  if (drug == "Buronzand")
    {
      std::cout << "Mr." << this->name;
      std::cout << ": Et la fatigue a fait son temps!" << std::endl;
      return true;
    }
  for (size_t i = 0; i < drug.length(); ++i)
    drug[i] = std::tolower(drug[i], loc);
  if (drug == "mars")
    {
      std::cout << "Mr." << this->name;
      std::cout << ": Mars, et ca Kreog !" << std::endl;
      return true;
    }
  std::cout << "Mr." << this->name;
  std::cout << ": Goerk !" << std::endl;
  return false;
}

void		SickKoala::overDrive(std::string msg)
{
  std::string	kreog = "Kreog !";
  std::string	leet = "1337 !";
  size_t	start_pos = 0;

  while ((start_pos = msg.find(kreog, start_pos)) != std::string::npos)
    {
      msg.replace(start_pos, kreog.length(), leet);
      start_pos += leet.length();
    }
  std::cout << "Mr." << this->name;
  std::cout << ": " << msg << std::endl;
}

std::string	SickKoala::getName()
{
  return this->name;
}
