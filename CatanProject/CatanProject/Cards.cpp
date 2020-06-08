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
	string Nazwa = "Punkt rozwoju";
	string effect = "Daje ci 1 PKT zwyciêstwa";
	string Podnazwa;
};
class Biblioteka :KartazPkt
{
	unsigned int numb = 1;
	unsigned int count = 1;
	string Podnazwa = "Biblioteka";
};
class Ratusz :KartazPkt
{
	unsigned int numb = 3;
	unsigned int count = 1;
	string Podnazwa = "Ratusz";
};
class Rynek :KartazPkt
{
	unsigned int numb = 7;
	unsigned int count = 1;
	string Podnazwa = "Rynek";
};
class Uniwersytet :KartazPkt
{
	unsigned int numb = 4;
	unsigned int count = 1;
	string Podnazwa = "Uniwersytet";
};
class Stacja :KartazPkt
{
	unsigned int numb = 9;
	unsigned int count = 1;
	string Podnazwa = "Stacja";
};
class Budowadrog :Kard
{
	unsigned int numb = 2;
	unsigned int count = 2;
	string Nazwa = "Ekspansja drogowa";
	string effect = "Pozwala na wybudowanie 2 dróg";
};
class Monopol :Kard
{
	unsigned int numb = 6;
	unsigned int count = 3;
	string Nazwa = "Przewaga handlowa";
	string effect = "Pozwala na zabranie wszystkich surowców od innych graczy";
};
class Wynalazek :Kard
{
	unsigned int numb = 8;
	unsigned int count = 4;
	string Nazwa = "Wynalazek";
	string effect = "Pozwala na dobranie 2 dowolnych zasobów";
};
class Rycerz :Kard
{
	unsigned int numb = 5;
	unsigned int count = 12;
	string Nazwa = "Rycerz";
	string effect = "Pozwala na przeniesienie z³odzieja w inne miesjce";
};