#include "Cards.h"
void Kard::kardget() {
	count--;
}
unsigned int Kard::kardcountget() {
	return count;
}
void Kard::karduse() {
	count++;
}
class KartazPkt :Kard
{
	string Kard::Nazwa = "Punkt rozwoju";
	string Kard::effect = "Daje ci 1 PKT zwyciêstwa";
	string Podnazwa;
};
class Biblioteka :KartazPkt
{
	unsigned int Kard::numb = 1;
	unsigned int Kard::count = 1;
	string KartazPkt::Podnazwa = "Biblioteka";
};
class Ratusz :KartazPkt
{
	unsigned int Kard::numb = 3;
	unsigned int Kard::count = 1;
	string KartazPkt::Podnazwa = "Ratusz";
};
class Rynek :KartazPkt
{
	unsigned int Kard::numb = 7;
	unsigned int Kard::count = 1;
	string KartazPkt::Podnazwa = "Rynek";
};
class Uniwersytet :KartazPkt
{
	unsigned int Kard::numb = 4;
	unsigned int Kard::count = 1;
	string KartazPkt::Podnazwa = "Uniwersytet";
};
class Stacja :KartazPkt
{
	unsigned int Kard::numb = 9;
	unsigned int Kard::count = 1;
	string KartazPkt::Podnazwa = "Stacja";
};
class Budowadrog :Kard
{
	unsigned int Kard::numb = 2;
	unsigned int Kard::count = 2;
	string Kard::Nazwa = "Ekspansja drogowa";
	string Kard::effect = "Pozwala na wybudowanie 2 dróg";
};
class Monopol :Kard
{
	unsigned int Kard::numb = 6;
	unsigned int Kard::count = 3;
	string Kard::Nazwa = "Przewaga handlowa";
	string Kard::effect = "Pozwala na zabranie wszystkich surowców od innych graczy";
}; 
class Wynalazek :Kard
{
	unsigned int Kard::numb = 8;
	unsigned int Kard::count = 4;
	string Kard::Nazwa = "Wynalazek";
	string Kard::effect = "Pozwala na dobranie 2 dowolnych zasobów";
};
class Rycerz :Kard
{
	unsigned int Kard::numb = 5;
	unsigned int Kard::count = 12;
	string Kard::Nazwa = "Rycerz";
	string Kard::effect = "Pozwala na przeniesienie z³odzieja w inne miesjce";
};