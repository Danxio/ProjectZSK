#include "GraczClass.h"
//ustawianie liczbowo zasobów
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
void Gracz::setowca(unsigned int O) {
	owca = O;
}
void Gracz::portchange()
{
	port = true;
}
//sprawdzenie stanu zasobów
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
//dodawanie pojedyñczo
void Gracz::addzboze()
{
	zboze++;
}
void Gracz::addzelazo()
{
	zelazo++;
}
void Gracz::adddrewno()
{
	drewno++;
}
void Gracz::addcegla()
{
	cegla++;
}
void Gracz::addowca()
{
	owca++;
}
//wymiany zasobów
void Gracz::Trade(unsigned int x, unsigned int y) {
	switch (x)
	{
	case 1:zboze -= 4; break;
	case 2:zelazo -= 4;	break;
	case 3:drewno -= 4;	break;
	case 4:cegla -= 4; break;
	case 5:owca -= 4;  break;
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
//czynnoœci gracza
void Gracz::BudowaDrogi() {
	drewno --;
	cegla --;
	droga --;
}
void Gracz::BudowaOsady() {
	drewno--;
	owca--;
	cegla--;
	zboze--;
	osada--;
	Dodajpkt();
}
void Gracz::BudowaMiasta() {
	zboze -= 2;
	zelazo -= 3;
	osada += 1;
	miasto -= 1;
	Dodajpkt();
}
void Gracz::DoburKarty() {
	zboze--;
	zelazo--;
	owca--;
	karty++;
}

//droga do wygranej punkty
unsigned int Gracz::Ilepkt()
{
	return pkt;
}
void Gracz::Dodajpkt()
{
	pkt++;
}
void Gracz::Najdlreog()
{
	najdldroga = true;
	pkt += 2;
}
void Gracz::Najwryce()
{
	najwrycerz = true;
	pkt += 2;
}
void Gracz::Stratadrog()
{
	najdldroga = false;
	pkt -= 2;
}
void Gracz::StrataRyc()
{
	najwrycerz = false;
	pkt -= 2;
}
unsigned int Gracz::getDroga() {
	return droga;
}
unsigned int Gracz::getOsada() {
	return osada;
}
unsigned int Gracz::getMiasto() {
	return miasto;
}
//wspó³rzêdne obiektów
void Gracz::setDrogi(int index, Obiekty road) {
	drogi[index] = road;
}
void Gracz::setMiasta(int index, Obiekty city) {
	miasta[index] = city;
}
void Gracz::setOsady(int index, Obiekty village) {
	osady[index] = village;
}
Obiekty Gracz::getDrogi(int index) {
	return drogi[index];
}
Obiekty Gracz::getMiasta(int index) {
	return miasta[index];
}
Obiekty Gracz::getOsady(int index) {
	return osady[index];
}