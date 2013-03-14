#ifndef ISCV_H_
#define ISCV_H_

class IScv
{
 protected:
  virtual void buildCommandCenter() = 0;
  virtual void buildBarrack() = 0;
  virtual void buildSupplyDepot() = 0;
  virtual void buildBunker() = 0;

 public:
  virtual ~IScv(void) {}

  virtual void createBuilding(int) = 0;
};

#endif
