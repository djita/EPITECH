//
// koalanurse.cpp for koalanurse in /home/guillo_e//Documents/working/tek2/piscine/D06/ex03
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Mon Jan 14 16:47:06 2013 lyoma guillou
// Last update Mon Jan 14 20:30:50 2013 lyoma guillou
//

#include <iostream>
#include <fstream>
#include <string>

#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
  this->status = 0;
}

KoalaNurse::~KoalaNurse()
{
  if (this->status)
    {
      std::cout << "Nurse " << this->id;
      std::cout << ": Enfin un peu de repos !" << std::endl;
      this->status = 0;
    }
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
  if (!this->status)
    this->timeCheck();
  patient->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string file)
{
  std::fstream	filedrug;
  std::string	drug;
  std::string	patient;
  std::string	ext = ".report";

  if (!this->status)
    this->timeCheck();
  filedrug.open(file.c_str(), std::fstream::in | std::fstream::out);
  if (filedrug.is_open())
    {
      patient = file.substr(0, file.length() - ext.length());
      getline(filedrug, drug);
      std::cout << "Nurse " << this->id;
      std::cout << ": Kreog ! Il faut donner un ";
      std::cout << drug << " a Mr." << patient << " !" << std::endl;
      return drug;
    }
  return NULL;
}

void		KoalaNurse::timeCheck(void)
{
  if (!this->status)
    {
      std::cout << "Nurse " << this->id;
      std::cout << ": Je commence le travail !" << std::endl;
      this->status = 1;
    }
  else
    {
      std::cout << "Nurse " << this->id;
      std::cout << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
      this->status = 0;
    }
}

int		KoalaNurse::getID(void)
{
  return this->id;
}
