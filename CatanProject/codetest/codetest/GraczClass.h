#pragma once
#include <iostream>
using namespace std;

class Gracz {
	//stan pocz¹tkowy surowców
	unsigned int zboze{0};
	unsigned int zelazo{0};
	unsigned int drewno{0};
	unsigned int cegla{0};
	unsigned int owca{0};
	//posiada port
	bool port = false;
	//stan pocz¹tkowy dróg, osad oraz miast
	unsigned int droga{ 15 };
	unsigned int miasta{ 4 };
	unsigned int osada{ 5 };
	//stan pocz¹tkowy kart rozwoju
	unsigned int karty{ 0 };
	//iloœæ punktów zwyciêstwa
	unsigned int pkt{ 0 };
public:
	//ustawianie surowców
	void setzboze(unsigned int Z);
	void setzelazo(unsigned int Ze);
	void setdrewno(unsigned int D);
	void setcegla(unsigned int C);
	void setowca(unsigned int O);
	//wyœwietlanie surowców
	unsigned int getzboze();
	unsigned int getzelazo();
	unsigned int getdrewno();
	unsigned int getcegla();
	unsigned int getowce();
	//wymiana surowców
	void Trade(unsigned int x, unsigned int y);
	void BetterTrade(unsigned int x, unsigned int y);
	//posiadanie portu
	void portchange();
	//wyœwietlenie stanu portu
	bool portshow();
	//Rozwój
	void BudowaDrogi(unsigned int x);
	void BudowaOsady();
	void BudowaMiasta();
	void DoburKarty();
};