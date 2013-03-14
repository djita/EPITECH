#include <string>
#include <iostream>

scienceFacility::scienceFacility(std::string name, std::string type, int posX, int posY, int cHP, int mH, bool isFlying) : building(name, type, posX, posY, cHP, mHP, isFlying)
{

}

scienceFacility::scienceFacility(int posX, int posY) : building("", "scienceFacility", posX, posY, 1500, 1500, false)
{

}

scienceFacility::~scienceFacility()
{

}

void	scienceFacility::doResearch(int type)
{
  static int tab[3] = {0, 0, 0}
  if (type >= 1 && type <= 3)
    {
      tab[type - 1] = 1;
      std::cout << ((type == 1 && !tab[type - 1]) ? "EMP Blast research finished, sir !" 
		    : ((type == 2 && !tab[type - 1]) ? "Irradiate research finished, sir !" 
		       : ((type == 3 && !tab[type - 1]) ? "Titan reactor research finished, sir !"
			  : "This research was already done, sir !")));
      std::cout << std::endl;
    }
}
