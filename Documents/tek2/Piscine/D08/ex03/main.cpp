#include <iostream>
#include <string>
#include "droid.hh"
#include "droidmemory.hh"
#include "carrier.hh"

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

// int main()
// {
//   DroidMemory dm;
//   DroidMemory dn;
//   DroidMemory dg;
//   dm += 42;
//   DroidMemory dn1 = dm;
//   std::cout << dm << std::endl;
//   dn << dm;
//   dn >> dm;
//   dn << dm;
//   std::cout << dn << std::endl;
//   std::cout << dm << std::endl;
//   dg = dm + dn1;

//   Droid d("rudolf");
//   Droid d2("gaston");
//   size_t DuraSell = 40;
//   d << DuraSell;
//   d.setStatus(new std::string("having some reset"));
//   d2.setStatus(new std::string("having some reset"));
//   if (d2 != d && !(d == d2))
//     std::cout << "a droid is a droid, all its matter is what it’s doing" << std::endl;
//   d(new std::string("take a coffee"), 20);
//   std::cout << d << std::endl;
//   while (d(new std::string("Patrol around"), 20))
//     {
//       if (!d(new std::string("Shoot some ennemies"), 50))
// 	d(new std::string("Run Away"), 20);
//       std::cout << d << std::endl;
//     }
//   std::cout << d << std::endl;
//   return (0);
// }

int main()
{
  Carrier c("HellExpress");
  Droid *d1 = new Droid("Commander");
  Droid *d2 = new Droid("Sergent");
  Droid *d3 = new Droid("Troufiont");
  Droid *d4 = new Droid("Groupie");
  Droid *d5 = new Droid("BeerHolder");

  c << d1 << d2 << d3 << d4 << d5;
  std::cout << c.getSpeed() << d1 << std::endl;
  c >> d1 >> d2 >> d3;
  std::cout << c.getSpeed() << std::endl;
  c[0] = d1;
  std::cout << (~c).getSpeed() << std::endl;
  c(4, 2);
  std::cout << c << std::endl;
  c(-15, 4);
  std::cout << c << std::endl;
  c[3] = 0;
  c[4] = 0;
  (~c)(-15, 4);
  std::cout << c << std::endl;
  return 0;
}
