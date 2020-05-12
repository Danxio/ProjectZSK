#include "GraczClass.h"

void Gracz::setzboze(unsigned int Z) {
	zboze = Z;
}
void Gracz::setzelazo(unsigned int Ze) {
	zelazo = Ze;
}
void Gracz::setdrewno(unsigned int D) {
	drewno = D;
}
void Gracz::setcegla(unsigned int C) {
	cegla = C;
}
void Gracz::setzboze(unsigned int O) {
	owca = O;
}
void Gracz::portchange()
{
	port = true;
}
unsigned int Gracz::getzboze()
{
	return zboze;
}
unsigned int Gracz::getzelazo()
{
	return zelazo;
}
unsigned int Gracz::getdrewno()
{
	return drewno;
}
unsigned int Gracz::getcegla()
{
	return cegla;
}
unsigned int Gracz::getowce()
{
	return owca;
}
bool Gracz::portshow()
{
	return port;
}
void Gracz::Trade(unsigned int x, unsigned int y) {
	switch (x)
	{
		case 1:zboze-=4; break;
		case 2:zelazo -= 4; break;
		case 3:drewno -= 4; break;
		case 4:cegla -= 4; break;
		case 5:owca -= 4; break;
	}
	switch (y)
	{
	case 1:zboze += 1; break;
	case 2:zelazo += 1; break;
	case 3:drewno += 1; break;
	case 4:cegla += 1; break;
	case 5:owca += 1; break;
	}
}
void Gracz::BetterTrade(unsigned int x, unsigned int y) {
	switch (x)
	{
	case 1:zboze -= 3; break;
	case 2:zelazo -= 3; break;
	case 3:drewno -= 3; break;
	case 4:cegla -= 3; break;
	case 5:owca -= 3; break;
	}
	switch (y)
	{
	case 1:zboze += 1; break;
	case 2:zelazo += 1; break;
	case 3:drewno += 1; break;
	case 4:cegla += 1; break;
	case 5:owca += 1; break;
	}
}
void Gracz::BudowaDrogi(unsigned int x) {
	drewno -= x;
	cegla -= x;
	droga -= x;
}
void Gracz::BudowaOsady() {
	drewno--;
	owca--;
	cegla--;
	zboze--;
	osada--;
}
void Gracz::BudowaMiasta() {
	zboze -= 2;
	zelazo -= 3;
	osada += 1;
	miasta -= 1;
}
void Gracz::DoburKarty() {
	zboze--;
	zelazo--;
	owca--;
	karty++;
}