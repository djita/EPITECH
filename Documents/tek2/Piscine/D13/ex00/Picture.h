#ifndef PICTURE_H_
#define PICTURE_H_

#include <string>

class Picture
{
 public:
  std::string data;
  Picture();
  Picture(const std::string &file="");

  bool getPictureFromFile(const std::string &file);
};

#endif
