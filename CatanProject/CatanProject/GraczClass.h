#pragma once
#include "Cards.h"
#include "FieldClass.h"
#include "Obiekty.h"
using namespace std;

class Gracz {
	//stan pocz�tkowy surowc�w
	unsigned int zboze{ 2 };
	unsigned int zelazo{ 0 };
	unsigned int drewno{ 4 };
	unsigned int cegla{ 4 };
	unsigned int owca{ 2 };
	//posiada port
	bool port = false;
	//stan pocz�tkowy dr�g, osad oraz miast
	unsigned int droga{ 15 };
	unsigned int miasto{ 4 };
	unsigned int osada{ 5 };
	//tablice z posiadanymi drogami, osadami, miastami
	Obiekty drogi[15];
	Obiekty miasta[4];
	Obiekty osady[5];
	

	//stan pocz�tkowy kart rozwoju
	unsigned int karty{ 0 };
	//Jakie karty
	Kard karta;
	//ilo�� punkt�w zwyci�stwa
	unsigned int pkt{ 0 };
	bool najdldroga = false;
	bool najwrycerz = false;
public:
	//ustawianie surowc�w
	void setzboze(unsigned int Z);
	void setzelazo(unsigned int Ze);
	void setdrewno(unsigned int D);
	void setcegla(unsigned int C);
	void setowca(unsigned int O);
	//Dodawanie surwc�w
	void addzboze();
	void addzelazo();
	void adddrewno();
	void addcegla();
	void addowca();
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
	void BudowaDrogi();
	void BudowaOsady();
	void BudowaMiasta();
	void DoburKarty();
	//wsp�rz�dne obiekt�w
	void setDrogi(int index,Obiekty road);
	void setMiasta(int index, Obiekty city);
	void setOsady(int index, Obiekty village);
	Obiekty getDrogi(int index);
	Obiekty getMiasta(int index);
	Obiekty getOsady(int index);
	//Ustawianie punkt�w zwyci�stwa
	void Dodajpkt();
	void Najdlreog();
	void Najwryce();
	void Stratadrog();
	void StrataRyc();
	//Sprawdzanie pkt zwyci�stwa
	unsigned int Ilepkt();
	//Sprawdzenie ilo�ci dr�g, osad, miast
	unsigned int getDroga();
	unsigned int getMiasto();
	unsigned int getOsada();
};
