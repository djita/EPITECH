#include "Humanoid.h"
#include "Changeling.h"
#include "Ferengi.h"

int main()
{
  Ferengi *vilain = new Ferengi("Vilain");
  Changeling *Odo = new Changeling("Odo");
  Humanoid *Bob = new Humanoid("Bob");

  vilain->rip(vilain);
  vilain->rip(Odo);
  vilain->rip(Bob);
}
