#include <iostream>
#include <fstream>
#include <string>
#include "Picture.h"

Picture::Picture() : data("")
{

}

Picture::Picture(const std::string &file)
{
  std::ifstream fstr;
  std::string buffer;

  fstr.open(file.c_str(), std::ifstream::in);
  if (fstr.is_open())
    {
      while (getline(fstr, buffer))
	this->data += buffer += "\n";
      fstr.close();
    }
}

bool Picture::getPictureFromFile(const std::string &file)
{
  std::ifstream fstr;
  std::string buffer;
  std::string picture;

  fstr.open(file.c_str(), std::ifstream::in);
  if (fstr.is_open())
    {
      this->data = "";
      while (getline(fstr, buffer))
	picture += buffer += "\n";
      fstr.close();
      return true;
    }
  return false;
}
