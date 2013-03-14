#include "ATarget.h"
#include "ASpell.h"
#include "Warlock.h"
#include <iostream>

// int main()
// {
//   const Warlock richard("Richard", "Mistress of Magma");
//   richard.introduce();
//   std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
//   Warlock* jack = new Warlock("Jack", "the Long");
//   jack->introduce();
//   jack->setTitle("the Not-So-Long-After-All");
//   jack->introduce();
//   delete jack;
//   return (0);
// }

// int main()
// {
//   Warlock richard("Richard");
//   richard.addTitle("Chief Warlock of the Brothers of Darkness");
//   richard.addTitle("Lord of the Thirteen Hells");
//   richard.addTitle("Emperor of the Black");
//   richard.addTitle("Lord of the Undead");
//   richard.addTitle("Mistress of Magma");
//   richard.introduce();
//   richard.removeTitle("Mistress of Magma");
//   richard.introduce();
//   richard.addQuote("You’ve just been Dick-rolled !");
//   richard.addQuote("This day is fantastic ...");
//   richard.addQuote("That orphanage attacked ME. It was self-defense !");
//   richard.addQuote("You like what I do ?");
//   richard.talk();
//   richard.talk();
// }

int main()
{
  Warlock richard("Richard");
  richard.addTitle("Chief Warlock of the Brothers of Darkness");
  richard.addTitle("Lord of the Thirteen Hells");
  richard.addTitle("Emperor of the Black");
  richard.addTitle("Lord of the Undead");
  richard.addTitle("Mistress of Magma");
  richard.addQuote("You’ve just been Dick-rolled !");
  richard.addQuote("This day is fantastic ...");
  richard.addQuote("That orphanage attacked ME. It was self-defense !");
  richard.addQuote("You like what I do ?");
  LittleKid bob;
  Fwoosh* fwoosh = new Fwoosh();
  richard.learnSpell(fwoosh);
  richard.introduce();
  richard.launchSpell("Fwoosh", bob);
  richard.talk();
  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
