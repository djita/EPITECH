#include <iostream>
#include <string>
#include "droid.hh"
#include "droidmemory.hh"

// int main()
// {
//   Droid d;
//   Droid d1("Avenger");
//   size_t Durasel = 200;

//   std::cout << d << std::endl;
//   std::cout << d1 << std::endl;
//   d = d1;
//   d.setStatus(new std::string("Kill Kill Kill!"));
//   d << Durasel;
//   std::cout << d << "--" << Durasel << std::endl;
//   Droid d2 = d;
//   d.setId("Rex");
//   std::cout << (d2 != d) << std::endl;
//   return (0);
// }

int main()
{
  DroidMemory dm;
  DroidMemory dn;
  DroidMemory dg;
  dm += 42;
  DroidMemory dn1 = dm;
  std::cout << dm << std::endl;
  dn << dm;
  dn >> dm;
  dn << dm;
  std::cout << dn << std::endl;
  std::cout << dm << std::endl;
  dg = dm + dn1;

  Droid d("rudolf");
  Droid d2("gaston");
  size_t DuraSell = 40;
  d << DuraSell;
  d.setStatus(new std::string("having some reset"));
  d2.setStatus(new std::string("having some reset"));
  if (d2 != d && !(d == d2))
    std::cout << "a droid is a droid, all its matter is what it’s doing" << std::endl;
  d(new std::string("take a coffee"), 20);
  std::cout << d << std::endl;
  while (d(new std::string("Patrol around"), 20))
    {
      if (!d(new std::string("Shoot some ennemies"), 50))
	d(new std::string("Run Away"), 20);
      std::cout << d << std::endl;
    }
  std::cout << d << std::endl;
  return (0);
}
