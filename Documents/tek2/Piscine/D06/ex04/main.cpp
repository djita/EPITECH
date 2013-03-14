#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"
#include <string>

int	main()
{
  KoalaDoctor	doctor("Kreog");
  KoalaNurse	nurse(42);
  SickKoala	patient("Toto");
  std::string	ext = ".report";
  std::string	file = patient.getName() + ext;
  std::string	drug = "Viagra";

  while (true)
    {
      doctor.diagnose(&patient);
      drug = nurse.readReport(file);
      nurse.giveDrug(drug, &patient);
    }
}
