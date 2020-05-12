#pragma once
#include <iostream>
using namespace std;

class Gracz {
	//stan pocz�tkowy surowc�w
	unsigned int zboze{0};
	unsigned int zelazo{0};
	unsigned int drewno{0};
	unsigned int cegla{0};
	unsigned int owca{0};
	//posiada port
	bool port = false;
	//stan pocz�tkowy dr�g, osad oraz miast
	unsigned int droga{ 15 };
	unsigned int miasta{ 4 };
	unsigned int osada{ 5 };
	//stan pocz�tkowy kart rozwoju
	unsigned int karty{ 0 };
	//ilo�� punkt�w zwyci�stwa
	unsigned int pkt{ 0 };
public:
	//ustawianie surowc�w
	void setzboze(unsigned int Z);
	void setzelazo(unsigned int Ze);
	void setdrewno(unsigned int D);
	void setcegla(unsigned int C);
	void setowca(unsigned int O);
	//wy�wietlanie surowc�w
	unsigned int getzboze();
	unsigned int getzelazo();
	unsigned int getdrewno();
	unsigned int getcegla();
	unsigned int getowce();
	//wymiana surowc�w
	void Trade(unsigned int x, unsigned int y);
	void BetterTrade(unsigned int x, unsigned int y);
	//posiadanie portu
	void portchange();
	//wy�wietlenie stanu portu
	bool portshow();
	//Rozw�j
	void BudowaDrogi(unsigned int x);
	void BudowaOsady();
	void BudowaMiasta();
	void DoburKarty();
};