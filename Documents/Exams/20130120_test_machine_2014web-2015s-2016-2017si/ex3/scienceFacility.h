#ifndef SCIENCEFACILITY_H_
#define SCIENCEFACILITY_H_

#include <string>

enum e_search
  {
    EMP_BLAST = 1,
    IRRADIATE = 2,
    TITAN_REACTOR = 3
  };

enum e_addon
  {
    COVERT_OPS = 1,
    PHYSICS_LAB = 2
  };

class scienceFacility : virtual public building
{
 public:
  scienceFacility(std::string name = "", std::string type = "scienceFacilityAdvanced",
		  int posX = 0, int posY = 0, int cHP = 1500, int mHP = 1500, bool isFlying = false);
  scienceFacility(int posX = 0, int posY = 0);
  ~scienceFacility();

  void doResearch(int);
};

#endif
