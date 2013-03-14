//
// koaladoctor.cpp for koaladoctor in /home/guillo_e//Documents/working/tek2/piscine/D06/ex04
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Mon Jan 14 17:43:48 2013 lyoma guillou
// Last update Mon Jan 14 20:15:24 2013 lyoma guillou
//

#include <cstdlib>

#include <string>
#include <fstream>
#include <iostream>

#include "sickkoala.h"
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string str)
{
  this->name = str;
  std::cout << "Dr." << this->name << ": Je suis le Dr." << this->name;
  std::cout << " ! Comment Kreoggez-vous?" << std::endl;
  this->status = 1;
}

KoalaDoctor::~KoalaDoctor()
{
  (void) this;
}

void		KoalaDoctor::diagnose(SickKoala *patient)
{
  std::ofstream	drug;
  std::string	ext = ".report";
  std::string	file;

  if (!this->status)
    this->timeCheck();
  std::cout << "Dr." << this->name;
  std::cout << " Alors, qu'est-ce qui vous goerk, Mr." << patient->getName() << std::endl;
  patient->poke();
  file = patient->getName();
  file += ext;
  drug.open(file.c_str());
  if (drug.is_open())
    {
      switch (rand() % 5) //FIXME
	{
	case 0:
	  drug.write("mars", 4);
	  break;
	case 1:
	  drug.write("Buronzand", 9);
	  break;
	case 2:
	  drug.write("Viagra", 6);
	  break;
	case 3:
	  drug.write("Extasy", 6);
	  break;
	case 4:
	  drug.write("Feuille d'eucalyptus", 20);
	  break;
	}
      drug.close();
    }
}

void		KoalaDoctor::timeCheck(void)
{
  if (!this->status)
    {
      std::cout << "Dr." << this->name;
      std::cout << ": Je commence le travail !" << std::endl;
      this->status = 1;
    }
  else
    {
      std::cout << "Dr." << this->name;
      std::cout << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
      this->status = 0;
    }
}
