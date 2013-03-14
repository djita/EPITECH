#ifndef AUNIT_H_
#define AUNIT_H_

class AUnit
{
protected:
  int _x;
  int _y;
  int _damages;
public:
  AUnit();
  AUnit(AUnit const &);
  virtual ~AUnit();

  virtual void attack(int x, int y) = 0;
  virtual void move(int x, int y) = 0;

  int getX(void) const;
  int getY(void) const;
  int getDam(void) const;

  void setX(int x);
  void setY(int y);
  void setDam(int damages);

  void pos(void) const;

  AUnit const & operator=(AUnit const &);
};

#endif
