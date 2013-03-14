#ifndef SCV_H_
#define SCV_H_

#include <string>
#include "IScv.h"
#include "unit.h"

enum e_1build
  {
    COMMAND_CENTER = 1,
    BARRACK = 2,
    SUPPLY_DEPOT = 3,
    BUNKER = 4
  };

class scv : virtual public unit, public IScv
{
  int _gold;
  int _gas;

  void (IScv::*build[])(void);

 protected:
  virtual void buildCommandCenter();
  virtual void buildBarrack();
  virtual void buildSupplyDepot();
  virtual void buildBunker();

 public:
  scv(std::string name = "", int posX = 0, int posY = 0);
  scv(scv const &);
  ~scv();

  void gather(int x, int y, int type);
  void repair(int x, int y, std::string const &target);

  virtual void createBuilding(int);
};

#endif
