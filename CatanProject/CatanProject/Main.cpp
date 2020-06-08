#include "GraczClass.h"
#include <SFML/Graphics.hpp>
using namespace sf;

RenderWindow W;

Event e;
int kostka() {
	srand(time(NULL));
	int k1, k2;
	k1 = rand() % 6 + 1;
	k2 = rand() % 6 + 1;
	return k1 + k2;
}
int main() {
	W.create(VideoMode(1200, 720), "Catan");	//tworzenie okna
	W.setActive(true);							//wyœwietla okno na wierzchu
	W.setFramerateLimit(30);					//limit fpsów do 30

	Font arial;	//£adowanie czcionki Arial
	if (!arial.loadFromFile("../../Fonts/Arial.ttf")) {
		std::cout << "Font load failed" << std::endl;
	}

	//Tworzenie mapy (wspó³rzêdne sprayów)
	Field f[19];
	Text t[19];
	Vector2f xCity[54];
	int a = 0;
	unsigned int tab[11] = {300,360,420,480,540,600,660,720,780,840,900};
	for (int x = 0; x < 54; x++) {
		if (x < 3) {
			xCity[x].x=tab[3+a];
			xCity[x].y = 80;
			a = a + 2;
		}
		else if (x < 7){
			if (x == 3)a = 0;
			xCity[x].x = tab[2 + a];
			xCity[x].y = 115;
			xCity[x + 4].x = tab[2 + a];
			xCity[x + 4].y = 185;
			a = a + 2;
		}
		else if(x<11){
			if (x == 7)a = 0;
		}
		else if (x < 16) {
			xCity[x].x = tab[1 + a];
			xCity[x].y = 220;
			xCity[x + 5].x = tab[1 + a];;
			xCity[x + 5].y = 290;
			a = a + 2;
		}
		else if (x < 21) {
			if (x == 16)a = 0;
		}
		else if (x < 27) {
			xCity[x].x = tab[0 + a];
			xCity[x].y = 325;
			xCity[x + 6].x = tab[0 + a];
			xCity[x + 6].y = 395;
			a = a + 2;
		}
		else if (x < 33) {
			if (x == 27)a = 0;
		}
		else if (x < 38) {
			xCity[x].x = tab[1 + a];
			xCity[x].y = 430;
			xCity[x + 5].x = tab[1 + a];
			xCity[x + 5].y = 500;
			a = a + 2;
		}
		else if (x < 43){
			if (x == 38)a = 0;
		}
		else if (x < 47) {
			xCity[x].x = tab[2 + a];
			xCity[x].y = 535;
			xCity[x + 4].x = tab[2 + a];
			xCity[x + 4].y = 605;
			a = a + 2;
		}
		else if (x < 51){
			if (x == 47)a = 0;
		}
		else {
			xCity[x].x = tab[3 + a];
			xCity[x].y = 640;
			a = a + 2;
		}
	}
		//background
		Texture background;
		if (!background.loadFromFile("../../Catan Graphics/map.png")) {
			std::cout << "Background load failed" << std::endl;
			system("pause");
		}
		Sprite bg;
		bg.setTexture(background);

		bg.scale(0.625, 0.667);
	
		//clay
		Texture clay;
		if (!clay.loadFromFile("../../Catan Graphics/Clay.png")) {
			std::cout << "Clay load failed" << std::endl;
			system("pause");
		}
		Sprite cla1;
		cla1.setTexture(clay);
		cla1.setOrigin(70, 60);
		cla1.rotate(90);
		cla1.setPosition(540, 255);

		f[4].setzasob(1);
		f[4].setnumb(6);

		t[4].setFont(arial);
		t[4].setString("6");
		t[4].setFillColor(Color::Red);
		t[4].setOrigin(10, 15);
		t[4].setPosition(540, 255);

		Sprite cla2;
		cla2.setTexture(clay);
		cla2.setOrigin(70, 60);
		cla2.rotate(90);
		cla2.setPosition(780, 255);

		f[6].setzasob(1);
		f[6].setnumb(10);

		t[6].setFont(arial);
		t[6].setString("10");
		t[6].setFillColor(Color::Black);
		t[6].setOrigin(15, 15);
		t[6].setPosition(780, 255);

		Sprite cla3;
		cla3.setTexture(clay);
		cla3.setOrigin(70, 60);
		cla3.rotate(90);
		cla3.setPosition(480, 570);

		f[16].setzasob(1);
		f[16].setnumb(5);

		t[16].setFont(arial);
		t[16].setString("5");
		t[16].setFillColor(Color::Black);
		t[16].setOrigin(10, 15);
		t[16].setPosition(480, 570);

		//desert
		Texture desert;
		if (!desert.loadFromFile("../../Catan Graphics/Desert.png")) {
			std::cout << "Desert load failed" << std::endl;
			system("pause");
		}
		Sprite des;
		des.setTexture(desert);
		des.setOrigin(70, 60);
		des.rotate(90);
		des.setPosition(600, 360);

		f[9].setzasob(2);
		f[9].setnumb(7);

		t[9].setFont(arial);
		t[9].setString("7");
		t[9].setFillColor(Color::Red);
		t[9].setOrigin(10, 15);
		t[9].setPosition(600, 360);

		//farm
		Texture farm;
		if (!farm.loadFromFile("../../Catan Graphics/Farm.png")) {
			std::cout << "Farm load failed" << std::endl;
			system("pause");
		}
		Sprite far1;
		far1.setTexture(farm);
		far1.setOrigin(70, 60);
		far1.rotate(90);
		far1.setPosition(660, 465);

		f[14].setzasob(3);
		f[14].setnumb(4);

		t[14].setFont(arial);
		t[14].setString("4");
		t[14].setFillColor(Color::Black);
		t[14].setOrigin(10, 15);
		t[14].setPosition(660, 465);

		Sprite far2;
		far2.setTexture(farm);
		far2.setOrigin(70, 60);
		far2.rotate(90);
		far2.setPosition(360, 360);

		f[7].setzasob(3);
		f[7].setnumb(9);

		t[7].setFont(arial);
		t[7].setString("9");
		t[7].setFillColor(Color::Black);
		t[7].setOrigin(10, 15);
		t[7].setPosition(360, 360);

		Sprite far3;
		far3.setTexture(farm);
		far3.setOrigin(70, 60);
		far3.rotate(90);
		far3.setPosition(420, 255);

		f[3].setzasob(3);
		f[3].setnumb(12);

		t[3].setFont(arial);
		t[3].setString("12");
		t[3].setFillColor(Color::Black);
		t[3].setOrigin(15, 15);
		t[3].setPosition(420, 255);

		Sprite far4;
		far4.setTexture(farm);
		far4.setOrigin(70, 60);
		far4.rotate(90);
		far4.setPosition(600, 570);

		f[17].setzasob(3);
		f[17].setnumb(6);

		t[17].setFont(arial);
		t[17].setString("6");
		t[17].setFillColor(Color::Red);
		t[17].setOrigin(10, 15);
		t[17].setPosition(600, 570);

		//field
		Texture field;
		if (!field.loadFromFile("../../Catan Graphics/Field.png")) {
			std::cout << "Field load failed" << std::endl;
			system("pause");
		}
		Sprite fie1;
		fie1.setTexture(field);
		fie1.setOrigin(70, 60);
		fie1.rotate(90);
		fie1.setPosition(660, 255);

		f[5].setzasob(4);
		f[5].setnumb(4);

		t[5].setFont(arial);
		t[5].setString("4");
		t[5].setFillColor(Color::Black);
		t[5].setOrigin(10, 15);
		t[5].setPosition(660, 255);

		Sprite fie2;
		fie2.setTexture(field);
		fie2.setOrigin(70, 60);
		fie2.rotate(90);
		fie2.setPosition(720, 570);

		f[18].setzasob(4);
		f[18].setnumb(11);

		t[18].setFont(arial);
		t[18].setString("11");
		t[18].setFillColor(Color::Black);
		t[18].setOrigin(15, 15);
		t[18].setPosition(720, 570);

		Sprite fie3;
		fie3.setTexture(field);
		fie3.setOrigin(70, 60);
		fie3.rotate(90);
		fie3.setPosition(780, 465);

		f[15].setzasob(4);
		f[15].setnumb(5);

		t[15].setFont(arial);
		t[15].setString("5");
		t[15].setFillColor(Color::Black);
		t[15].setOrigin(10, 15);
		t[15].setPosition(780, 465);

		Sprite fie4;
		fie4.setTexture(field);
		fie4.setOrigin(70, 60);
		fie4.rotate(90);
		fie4.setPosition(600, 150);

		f[1].setzasob(4);
		f[1].setnumb(2);

		t[1].setFont(arial);
		t[1].setString("2");
		t[1].setFillColor(Color::Black);
		t[1].setOrigin(10, 15);
		t[1].setPosition(600, 150);

		//forest
		Texture forest;
		if (!forest.loadFromFile("../../Catan Graphics/Forest.png")) {
			std::cout << "Forest load failed" << std::endl;
			system("pause");
		}
		Sprite fore1;
		fore1.setTexture(forest);
		fore1.setOrigin(70, 60);
		fore1.rotate(90);
		fore1.setPosition(480, 360);

		f[8].setzasob(5);
		f[8].setnumb(11);

		t[8].setFont(arial);
		t[8].setString("11");
		t[8].setFillColor(Color::Black);
		t[8].setOrigin(15, 15);
		t[8].setPosition(480, 360);

		Sprite fore2;
		fore2.setTexture(forest);
		fore2.setOrigin(70, 60);
		fore2.rotate(90);
		fore2.setPosition(720, 360);

		f[10].setzasob(5);
		f[10].setnumb(3);

		t[10].setFont(arial);
		t[10].setString("3");
		t[10].setFillColor(Color::Black);
		t[10].setOrigin(10, 15);
		t[10].setPosition(720, 360);

		Sprite fore3;
		fore3.setTexture(forest);
		fore3.setOrigin(70, 60);
		fore3.rotate(90);
		fore3.setPosition(420, 465);

		f[12].setzasob(5);
		f[12].setnumb(8);

		t[12].setFont(arial);
		t[12].setString("8");
		t[12].setFillColor(Color::Red);
		t[12].setOrigin(10, 15);
		t[12].setPosition(420, 465);

		Sprite fore4;
		fore4.setTexture(forest);
		fore4.setOrigin(70, 60);
		fore4.rotate(90);
		fore4.setPosition(720, 150);

		f[2].setzasob(5);
		f[2].setnumb(9);

		t[2].setFont(arial);
		t[2].setString("9");
		t[2].setFillColor(Color::Black);
		t[2].setOrigin(10, 15);
		t[2].setPosition(720, 150);

		//mountain
		Texture mountain;
		if (!mountain.loadFromFile("../../Catan Graphics/Mountain.png")) {
			std::cout << "Mountain load failed" << std::endl;
			system("pause");
		}
		Sprite mou1;
		mou1.setTexture(mountain);
		mou1.setOrigin(70, 60);
		mou1.rotate(90);
		mou1.setPosition(540, 465);

		f[13].setzasob(6);
		f[13].setnumb(3);

		t[13].setFont(arial);
		t[13].setString("3");
		t[13].setFillColor(Color::Black);
		t[13].setOrigin(10, 15);
		t[13].setPosition(540, 465);

		Sprite mou2;
		mou2.setTexture(mountain);
		mou2.setOrigin(70, 60);
		mou2.rotate(90);
		mou2.setPosition(840, 360);

		f[11].setzasob(6);
		f[11].setnumb(8);
		
		t[11].setFont(arial);
		t[11].setString("8");
		t[11].setFillColor(Color::Red);
		t[11].setOrigin(10, 15);
		t[11].setPosition(840, 360);

		Sprite mou3;
		mou3.setTexture(mountain);
		mou3.setOrigin(70, 60);
		mou3.rotate(90);
		mou3.setPosition(480, 150);

		f[0].setzasob(6);
		f[0].setnumb(10);

		t[0].setFont(arial);
		t[0].setString("10");
		t[0].setFillColor(Color::Black);
		t[0].setOrigin(15, 15);
		t[0].setPosition(480, 150);

		//Spray bandytów
		Texture bandits;
		if (!bandits.loadFromFile("../../Catan Graphics/Bandits.png")) {
			std::cout << "Bandits load failed" << std::endl;
			system("pause");
		}
		Sprite band;
		band.setTexture(bandits);
		band.setOrigin(30, 35);
		band.setPosition(600, 360);

	//Tworzenie graczy
	Gracz player1, player2, player3, player4;
	
	//Sprite'y(Miasta,Osady,drogi)
	//Red player1
	Texture cityRed;
	if (!cityRed.loadFromFile("../../Catan Graphics/City_Red.png")) {
		std::cout << "Red City load failed" << std::endl;
		system("pause");
	}

	Sprite cRed;
	cRed.setTexture(cityRed);
	

	Texture villageRed;
	if (!villageRed.loadFromFile("../../Catan Graphics/Village_Red.png")) {
		std::cout << "Red Village load failed" << std::endl;
		system("pause");
	}
	Sprite vRed;
	vRed.setTexture(villageRed);

	Texture roadRed;
	if (!roadRed.loadFromFile("../../Catan Graphics/Road_Red.png")) {
		std::cout << "Red Road load failed" << std::endl;
		system("pause");
	}
	Sprite rRed;
	rRed.setTexture(roadRed);

	//Blue player2
	Texture cityBlue;
	if (!cityBlue.loadFromFile("../../Catan Graphics/City_Blue.png")) {
		std::cout << "Blue City load failed" << std::endl;
		system("pause");
	}

	Sprite cBlue;
	cBlue.setTexture(cityBlue);


	Texture villageBlue;
	if (!villageBlue.loadFromFile("../../Catan Graphics/Village_Blue.png")) {
		std::cout << "Blue Village load failed" << std::endl;
		system("pause");
	}
	Sprite vBlue;
	vBlue.setTexture(villageBlue);

	Texture roadBlue;
	if (!roadBlue.loadFromFile("../../Catan Graphics/Road_Blue.png")) {
		std::cout << "Blue Road load failed" << std::endl;
		system("pause");
	}
	Sprite rBlue;
	rBlue.setTexture(roadBlue);

	//Orange player3
	Texture cityOrange;
	if (!cityOrange.loadFromFile("../../Catan Graphics/City_Orange.png")) {
		std::cout << "Orange City load failed" << std::endl;
		system("pause");
	}

	Sprite cOrange;
	cOrange.setTexture(cityOrange);


	Texture villageOrange;
	if (!villageOrange.loadFromFile("../../Catan Graphics/Village_Orange.png")) {
		std::cout << "Orange Village load failed" << std::endl;
		system("pause");
	}
	Sprite vOrange;
	vOrange.setTexture(villageOrange);

	Texture roadOrange;
	if (!roadOrange.loadFromFile("../../Catan Graphics/Road_Orange.png")) {
		std::cout << "Orange Road load failed" << std::endl;
		system("pause");
	}
	Sprite rOrange;
	rOrange.setTexture(roadOrange);

	//White player4
	Texture cityWhite;
	if (!cityWhite.loadFromFile("../../Catan Graphics/City_White.png")) {
		std::cout << "White City load failed" << std::endl;
		system("pause");
	}

	Sprite cWhite;
	cWhite.setTexture(cityWhite);


	Texture villageWhite;
	if (!villageWhite.loadFromFile("../../Catan Graphics/Village_White.png")) {
		std::cout << "WhiteVillage load failed" << std::endl;
		system("pause");
	}
	Sprite vWhite;
	vWhite.setTexture(villageWhite);

	Texture roadWhite;
	if (!roadWhite.loadFromFile("../../Catan Graphics/Road_White.png")) {
		std::cout << "White Road load failed" << std::endl;
		system("pause");
	}
	Sprite rWhite;
	rWhite.setTexture(roadWhite);

	RectangleShape linia1(Vector2f(30, 10));
	linia1.setFillColor(Color::Black);
	linia1.setOrigin(15, 5);
	linia1.setPosition(900, 395);

	Text surowce;
	surowce.setFont(arial);
	surowce.setScale(0.5, 0.5);
	surowce.setFillColor(Color::White);
	surowce.setPosition(880, 550);
	bool bSurowce = false;

	Text aPlayer;
	aPlayer.setFont(arial);
	aPlayer.setFillColor(Color::White);
	aPlayer.setPosition(30, 30);

	Text info;
	info.setFont(arial);
	info.setString("Display Materials:\"S\"\n Trade Materials:\"W\"\n  Buy road:\"Z\"\n\   Buy village:\"X\"\n    Buy city:\"C\"\n      Prices:\"A\"\n       Next player:\"N\"");
	info.setFillColor(Color::White);
	info.setPosition(900, 30);

	
	RectangleShape tradeBG(Vector2f(200, 520));
	tradeBG.setFillColor(Color::Black);
	tradeBG.setPosition(99, 99);

	RectangleShape errBG(Vector2f(450, 100));	//Wyrzucanie b³êdów
	errBG.setFillColor(Color::Black);
	errBG.setPosition(30, 30);

	bool erro = false;

	Text err;
	err.setFont(arial);
	err.setFillColor(Color::White);
	err.setPosition(31, 31);

	RectangleShape shopBG(Vector2f(350, 150));	//Cennik 
	shopBG.setFillColor(Color::Black);
	shopBG.setPosition(800, 30);

	bool bShop = false;

	Text shop;
	shop.setFont(arial);
	shop.setString("Prices:\nRoad:  Clay, Wood\nVillage: Clay, Wool, Wheat, Wood\nCity: 2xWheat");
	shop.setFillColor(Color::White);
	shop.setScale(0.7, 0.7);
	shop.setPosition(800, 31);

	Text trade;
	trade.setFont(arial);
	trade.setFillColor(Color::White);
	trade.setScale(0.5, 0.5);
	trade.setPosition(100, 100);


	RectangleShape banBG(Vector2f(400, 190));	//Bandyci 
	banBG.setFillColor(Color::Red);
	banBG.setPosition(30, 30);

	Text ban;
	ban.setFont(arial);
	ban.setString("Bandits are moving!\n Choose where to move\nthem and block Field income.\n Use up and Down arrow\n\t");
	ban.setFillColor(Color::White);
	ban.setPosition(31, 31);

	CircleShape circl(20);
	circl.setFillColor(Color::Red);
	circl.setOrigin(Vector2f(20, 20));
	circl.setPosition(600, 360);

	Obiekty linia;

	int angle = 30;
	Vector2f sides[6] = { {30,-52.5}, {60,0},{30,52.5},{-30,52.5},{-60,0},{-30,-52.5} };
	int fieldVar[19] = {10,2,9,12,6,4,10,9,11,7,3,8,8,3,4,5,5,6,11};
	int zlodz = 9;
	int activePlayer = 1;
	int resultKostka = 0;
	bool poczatek = true;
	bool wymiana = false;
	int licznik = 1;
	int licznik2 = 1;
	bool bandyci = false;
	bool cShop = false;
	bool vShop = false;
	bool rShop = false;
	bool rShop2 = false;
	bool kosc = false;
	RectangleShape rSh(Vector2f(370, 100));
	rSh.setFillColor(Color::Black);
	Text rS;
	rS.setFont(arial);
	rS.setString("Press up and down arrow\nEnter to submit.");
	//pêtla dzia³aj¹ca kiedy okno jest otwarte
	while (W.isOpen()) {
		W.clear();			//czyœci obraz
		aPlayer.setString("Active player:\t"+to_string(activePlayer)+"\nResult of Dice:\t"+to_string(resultKostka));

		if (resultKostka == 7) {
			bandyci = true;
		}
		while (W.pollEvent(e)) {	//pêtla która wy³apuje wszelakie "Eventy" i przekazuje do zmiennej e
			if (e.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape))) W.close();	//zamykanie okna
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::S)) {	//Wyœwietlanie surowców
				bSurowce = !bSurowce;
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::W)) {	//Wymiana surowców
				wymiana = !wymiana;
				licznik = 1;
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::M)) {	//Wymuszenie bandytów
				bandyci = true;
			}
			if (bandyci == true) {
				ban.setString("Bandits are moving!\n Choose where to move\n them and block Field income.\n Use up and Down arrow\n\tand Enter to confirm");
				wymiana = false;
				bShop = false;
				bSurowce = false;
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
					licznik--;
					if (licznik < 1)
						licznik = 19;
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
					licznik++;
					if (licznik > 19)
						licznik = 1;
				}
				band.setPosition(t[licznik - 1].getPosition());
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Enter)) {
					f[zlodz].zlodzusu();
					zlodz = licznik - 1;
					f[zlodz].zlodzust();
					resultKostka = 0;
					band.setPosition(t[zlodz].getPosition());
					bandyci = false;
				}

			}
			if (wymiana == true) {
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
					licznik--;
					if (licznik < 1)
						licznik = 25;
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
					licznik++;
					if (licznik > 25)
						licznik = 1;
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Enter)) {
					if (activePlayer == 1) {
						if (licznik < 6) {
							if(player1.getzboze()<4){
								erro = true;
								err.setString("Not enough Wheat. \"E\" to close");
								break;
							}
							player1.Trade(1, licznik);
						}
						else if (licznik < 11) {
							if (player1.getzelazo() < 4) {
								erro = true;
								err.setString("Not enough Iron. \"E\" to close.");
								break;
							}
							licznik = licznik - 5;
							player1.Trade(2, licznik);
						}
						else if (licznik < 16) {
							if (player1.getdrewno() < 4) {
								erro = true;
								err.setString("Not enough Wood. \"E\" to close.");
								break;
							}
							licznik = licznik - 10;
							player1.Trade(3, licznik);
						}
						else if (licznik < 21) {
							if (player1.getcegla() < 4) {
								erro = true;
								err.setString("Not enough Clay. \"E\" to close.");
								break;
							}
							licznik = licznik - 15;
							player1.Trade(4, licznik);
						}
						else {
							if (player1.getowce() < 4) {
								erro = true;
								err.setString("Not enough Wool. \"E\" to close.");
								break;
							}
							licznik = licznik - 20;
							player1.Trade(5, licznik);
						}
						wymiana = false;
					}
					else if (activePlayer == 2) {
						if (licznik < 6) {
							if (player2.getzboze() < 4) {
								erro = true;
								err.setString("Not enough Wheat. \"E\" to close");
								break;
							}
							player2.Trade(1, licznik);
						}
						else if (licznik < 11) {
							licznik = licznik - 5;
							if (player2.getzelazo() < 4) {
								erro = true;
								err.setString("Not enough Iron. \"E\" to close");
								break;
							}
							player2.Trade(2, licznik);
						}
						else if (licznik < 16) {
							licznik = licznik - 10;
							if (player2.getdrewno() < 4) {
								erro = true;
								err.setString("Not enough Wood. \"E\" to close");
								break;
							}
							player2.Trade(3, licznik);
						}
						else if (licznik < 21) {
							licznik = licznik - 15;
							if (player2.getcegla() < 4) {
								erro = true;
								err.setString("Not enough Clay. \"E\" to close");
								break;
							}
							player2.Trade(4, licznik);
						}
						else {
							licznik = licznik - 20;
							if (player2.getzboze() < 4) {
								erro = true;
								err.setString("Not enough Wool. \"E\" to close");
								break;
							}
							player2.Trade(5, licznik);
						}
						wymiana = false;
					}
					else if (activePlayer == 3) {
						if (licznik < 6) {
							player3.Trade(licznik, 1);
							if (player3.getzboze() < 4) {
								erro = true;
								err.setString("Not enough Wheat. \"E\" to close");
								break;
							}
							player3.Trade(1, licznik);
						}
						else if (licznik < 11) {
							licznik = licznik - 5;
							if (player3.getzelazo() < 4) {
								erro = true;
								err.setString("Not enough Iron. \"E\" to close");
								break;
							}
							player3.Trade(2, licznik);
						}
						else if (licznik < 16) {
							licznik = licznik - 10;
							if (player3.getdrewno() < 4) {
								erro = true;
								err.setString("Not enough Wood. \"E\" to close");
								break;
							}
							player3.Trade(3, licznik);
						}
						else if (licznik < 21) {
							licznik = licznik - 15;
							if (player3.getcegla() < 4) {
								erro = true;
								err.setString("Not enough Clay. \"E\" to close");
								break;
							}
							player3.Trade(4, licznik);
						}
						else {
							licznik = licznik - 20;
							if (player3.getowce() < 4) {
								erro = true;
								err.setString("Not enough Wool. \"E\" to close");
								break;
							}
							player3.Trade(5, licznik);
						}
						wymiana = false;
					}
					else {
						if (licznik < 6) {
							if (player4.getzboze() < 4) {
								erro = true;
								err.setString("Not enough Wheat. \"E\" to close");
								break;
							}
							player4.Trade(1, licznik);
						}
						else if (licznik < 11) {
							licznik = licznik - 5;
							if (player4.getzelazo() < 4) {
								erro = true;
								err.setString("Not enough Iron. \"E\" to close");
								break;
							}
							player4.Trade(2, licznik);
						}
						else if (licznik < 16) {
							licznik = licznik - 10;
							if (player4.getdrewno() < 4) {
								erro = true;
								err.setString("Not enough Wood. \"E\" to close");
								break;
							}
							player4.Trade(3, licznik);
						}
						else if (licznik < 21) {
							licznik = licznik - 15;
							if (player4.getcegla() < 4) {
								erro = true;
								err.setString("Not enough Clay. \"E\" to close");
								break;
							}
							player4.Trade(4, licznik);
						}
						else {
							licznik = licznik - 20;
							if (player4.getowce() < 4) {
								erro = true;
								err.setString("Not enough Wool. \"E\" to close");
								break;
							}
							player4.Trade(5, licznik);
						}
						wymiana = false;
					}
				}
				trade.setString("Press up arrow to increase\nand down arrow  to decrease\nYour choice:\t" + to_string(licznik) + "\nTrade 1:4\n1. Wheat:Wheat\n2. Iron:Wheat\n2. Wood:Wheat\n4. Clay:Wheat\n5. Wool:Wheat\n6. Wheat:Iron\n7. Iron:Iron\n8. Wood:Iron\n9. Clay:Iron\n10. Wool:Iron\n11. Wheat:Wood\n12. Iron:Wood\n13. Wood:Wood\n14. Clay:Wood\n15. Wool:Wood\n16. Wheat:Clay\n17. Iron:Clay\n18. Wood:Clay\n19. Clay:Clay\n20. Wool:Clay\n21. Wheat:Wool\n22. Iron:Wool\n23. Wood:Wool\n24. Clay:Wool\n25. Wool:Wool");
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::N)) {	//Nastêpny gracz
				activePlayer++;
				if (activePlayer>4)
				{
					activePlayer = 1;
				}
				resultKostka = kostka();
				kosc = true;
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::A)) {	//ceny
				bShop = !bShop;
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Z)) {	//kupno drogi
				if (activePlayer == 1) {
					if (player1.getcegla() < 1 || player1.getdrewno() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player1.BudowaDrogi();
					rShop = true;
					licznik = 1;
				}
				else if (activePlayer == 2) {
					if (player2.getcegla() < 1 || player2.getdrewno() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player2.BudowaDrogi();
					rShop = true;
					licznik = 1;
				}
				else if (activePlayer == 3) {
					if (player3.getcegla() < 1 || player3.getdrewno() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player3.BudowaDrogi();
					rShop = true;
					licznik = 1;
				}
				else {
					if (player4.getcegla() < 1 || player4.getdrewno() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player4.BudowaDrogi();
					rShop = true;
					licznik = 1;
				}
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::X)) {	//kupno osady
				if (activePlayer == 1) {
					if (player1.getcegla() < 1 || player1.getdrewno() < 1|| player1.getowce()<1||player1.getzboze()<1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					vShop = true;
					licznik = 1;
				}
				else if (activePlayer == 2) {
					if (player2.getcegla() < 1 || player2.getdrewno() < 1 || player2.getowce() < 1 || player2.getzboze() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					vShop = true;
					licznik = 1;
				}
				else if (activePlayer == 3) {
					if (player3.getcegla() < 1 || player3.getdrewno() < 1 || player3.getowce() < 1 || player3.getzboze() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					vShop = true;
					licznik = 1;
				}
				else{
					if (player4.getcegla() < 1 || player4.getdrewno() < 1 || player4.getowce() < 1 || player4.getzboze() < 1) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					vShop = true;
					licznik = 1;
				}
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::C)) {	//kupno miasta
				if (activePlayer == 1) {
					if (player1.getzelazo() < 3 || player1.getzboze() < 2 ) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player1.BudowaMiasta();
					cShop = true;
					licznik = 1;
				}
				else if (activePlayer == 2) {
					if (player2.getzelazo() < 3 || player2.getzboze() < 2) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player2.BudowaMiasta();
					cShop = true;
					licznik = 1;
				}
				else if (activePlayer == 3) {
					if (player3.getzelazo() < 3 || player3.getzboze() < 2) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player3.BudowaMiasta();
					cShop = true;
					licznik = 1;
				}
				else {
					if (player4.getzelazo() < 3 || player4.getzboze() < 2) {
						erro == true;
						err.setString("Not enough materials.\nPress \"E\" To close Error");
						break;
					}
					player4.BudowaMiasta();
					cShop = true;
					licznik = 1;
				}
			}
			if (erro == true) {
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::E)) {	//Wyœwietlanie surowców
					erro = false;
				}
			}
			if (rShop == true) {
				rS.setString("Press up and down arrow\nEnter to submit.");
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
					licznik--;
					if (licznik < 1)
						licznik = 19;
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
					licznik++;
					if (licznik > 19)
						licznik = 1;
				}
				circl.setPosition(t[licznik - 1].getPosition());
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Enter)) {
					rShop = false;
					rShop2 = true;
					linia1.setPosition(t[licznik - 1].getPosition()+Vector2f(30,-52.5));
					linia1.setRotation(angle);
				}
			}
			if (rShop2 == true) {
				rS.setString("Press up and down arrow\nShift to submit.");
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
					licznik2--;
					if (licznik2 < 1) {
						licznik2 = 6;
					}
					angle = angle - 60;
					if (angle < 0) {
						angle = 330;
					}
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
					licznik2++;
					if (licznik2 > 6) {
						licznik2 = 1;
					}
					angle = angle + 60;
					if (angle > 360) {
						angle = 30;
					}
				}
				linia1.setPosition(t[licznik - 1].getPosition()+sides[licznik2-1]);
				linia1.setRotation(angle);
				if (e.type == Event::KeyReleased && ((e.key.code == Keyboard::RShift)|| (e.key.code == Keyboard::LShift))) {
					for (int i = 0; i < 16 - player1.getDroga(); i++)
					{
						if (player1.getDrogi(i).getPosition() == linia1.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							rShop = true;
							rShop2 = false;
							break;
						}
					}
					for (int i = 0; i < 16 - player2.getDroga(); i++)
					{
						if (player2.getDrogi(i).getPosition() == linia1.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							rShop = true;
							rShop2 = false;
							break;
						}
					}
					for (int i = 0; i < 16 - player3.getDroga(); i++)
					{
						if (player3.getDrogi(i).getPosition() == linia1.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							rShop = true;
							rShop2 = false;
							break;
						}
					}
					for (int i = 0; i < 16 - player4.getDroga(); i++)
					{
						if (player4.getDrogi(i).getPosition() == linia1.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							rShop = true;
							rShop2 = false;
							break;
						}
					}
					linia.setOrigin({ 35,8 });
					linia.setScale({0.6,0.6});
					linia.setPosition(linia1.getPosition());
					linia.setRotation(linia1.getRotation());
					if (activePlayer == 1) {
						player1.setDrogi(15 - player1.getDroga(), linia);
					}
					else if (activePlayer == 2) {
						player2.setDrogi(15 - player2.getDroga(), linia);
					}
					else if(activePlayer ==3) {
						player3.setDrogi(15 - player3.getDroga(), linia);
					}
					else {
						player4.setDrogi(15 - player4.getDroga(), linia);
					}
					rShop2 = false;
				}
			}
			if (vShop == true){
				rS.setString("Press up and down arrow\nEnter to submit.");
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
				licznik--;
				if (licznik < 1)
					licznik = 54;
			}
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
				licznik++;
				if (licznik > 54)
					licznik = 1;
			}
			circl.setPosition(xCity[licznik - 1]);
			if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Enter)) {
				for (int i = 0; i < 5 - player1.getOsada(); i++) {
					if (player1.getOsady(i).getPosition() == circl.getPosition()) {
						erro = true;
						err.setString("Place is claimed. Chooce other one.");
						break;
					}
				}
				for (int i = 0; i < 5 - player2.getOsada(); i++) {
					if (player2.getOsady(i).getPosition() == circl.getPosition()) {
						erro = true;
						err.setString("Place is claimed. Chooce other one.");
						break;
					}
				}
				for (int i = 0; i < 5 - player3.getOsada(); i++) {
					if (player3.getOsady(i).getPosition() == circl.getPosition()) {
						erro = true;
						err.setString("Place is claimed. Chooce other one.");
						break;
					}
				}
				for (int i = 0; i < 5 - player4.getOsada(); i++) {
					if (player4.getOsady(i).getPosition() == circl.getPosition()) {
						erro = true;
						err.setString("Place is claimed. Chooce other one.");
						break;
					}
				}
				linia.setOrigin({43, 36});
				linia.setScale({0.8,0.8});
				linia.setPosition(circl.getPosition());
				linia.setRotation(0);
				if(activePlayer == 1) {
					player1.BudowaOsady();
					player1.setOsady((5-player1.getOsada()),linia);
				}
				else if (activePlayer == 2) {
					player2.BudowaOsady();
					player2.setOsady((5 - player2.getOsada()), linia);
				}
				else if (activePlayer == 3) {
					player3.BudowaOsady();
					player3.setOsady((5 - player3.getOsada()), linia);
				}
				else {
					player4.BudowaOsady();
					player4.setOsady((5 - player4.getOsada()), linia);
				}
				vShop = false;
			}
			}
			if (cShop == true) {
				rS.setString("Press up and down arrow\nEnter to submit.");
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Down)) {
					licznik--;
					if (licznik < 1)
						licznik = 5;
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Up)) {
					licznik++;
					if (licznik > 5)
						licznik = 1;
				}
				if (activePlayer == 1) {
					circl.setPosition(player1.getOsady(licznik - 1).getPosition());
				}
				else if (activePlayer == 2) {
					circl.setPosition(player2.getOsady(licznik - 1).getPosition());
				}
				else if (activePlayer == 3) {
					circl.setPosition(player3.getOsady(licznik - 1).getPosition());
				}
				else {
					circl.setPosition(player4.getOsady(licznik - 1).getPosition());
				}
				if (e.type == Event::KeyReleased && (e.key.code == Keyboard::Enter)) {
					for (int i = 0; i < 3 - player1.getMiasto(); i++) {
						if (player1.getMiasta(i).getPosition() == circl.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							break;
						}
					}
					for (int i = 0; i < 4 - player2.getMiasto(); i++) {
						if (player2.getMiasta(i).getPosition() == circl.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							break;
						}
					}
					for (int i = 0; i < 4 - player3.getMiasto(); i++) {
						if (player3.getMiasta(i).getPosition() == circl.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							break;
						}
					}
					for (int i = 0; i < 4 - player4.getMiasto(); i++) {
						if (player4.getMiasta(i).getPosition() == circl.getPosition()) {
							erro = true;
							err.setString("Place is claimed. Chooce other one.");
							break;
						}
					}
					linia.setOrigin({ 36, 36 });
					linia.setScale({ 0.8,0.8 });
					linia.setPosition(circl.getPosition());
					linia.setRotation(0);
					if (activePlayer == 1) {
						player1.BudowaMiasta();
						player1.setMiasta((4 - player1.getMiasto()), linia);
					}
					else if (activePlayer == 2) {
						player2.BudowaMiasta();
						player2.setMiasta((4 - player2.getMiasto()), linia);
					}
					else if (activePlayer == 3) {
						player3.BudowaMiasta();
						player3.setMiasta((4 - player3.getMiasto()), linia);
					}
					else {
						player4.BudowaMiasta();
						player4.setMiasta((4 - player4.getMiasto()), linia);
					}
					cShop = false;
				}
			}
		}

		{W.draw(bg);			//rysuje mapê...
		W.draw(cla1);
		W.draw(cla2);
		W.draw(cla3);
		W.draw(des);
		W.draw(far1);
		W.draw(far2);
		W.draw(far3);
		W.draw(far4);
		W.draw(fie1);
		W.draw(fie2);
		W.draw(fie3);
		W.draw(fie4);
		W.draw(fore1);
		W.draw(fore2);
		W.draw(fore3);
		W.draw(fore4);
		W.draw(mou1);
		W.draw(mou2);
		W.draw(mou3);
		for (int i = 0; i < 19; i++) {
			W.draw(t[i]);
		}
		W.draw(band);
		//obiekty player1 Red
		for (int i = 0; i < 4; i++) {
			if (player1.getMiasto() < 5 - i) {
				cRed.setOrigin(player1.getMiasta(i).getOrigin());
				cRed.rotate(player1.getMiasta(i).getRotation());
				cRed.setScale(player1.getMiasta(i).getScale());
				cRed.setPosition(player1.getMiasta(i).getPosition());
				W.draw(cRed);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (player1.getOsada() < 6 - i) {
				vRed.setOrigin(player1.getOsady(i).getOrigin());
				vRed.rotate(player1.getOsady(i).getRotation());
				vRed.setScale(player1.getOsady(i).getScale());
				vRed.setPosition(player1.getOsady(i).getPosition());
				W.draw(vRed);
			}
		}
		for (int i = 0; i < 15; i++) {
			if (player1.getDroga() < 16 - i) {
				rRed.setOrigin(player1.getDrogi(i).getOrigin());
				rRed.setRotation(player1.getDrogi(i).getRotation());
				rRed.setScale(player1.getDrogi(i).getScale());
				rRed.setPosition(player1.getDrogi(i).getPosition());
				W.draw(rRed);
			}
		}
		//obiekty player2 Blue
		for (int i = 0; i < 4; i++) {
			if (player2.getMiasto() < 5 - i) {
				cBlue.setOrigin(player2.getMiasta(i).getOrigin());
				cBlue.rotate(player2.getMiasta(i).getRotation());
				cBlue.setScale(player2.getMiasta(i).getScale());
				cBlue.setPosition(player2.getMiasta(i).getPosition());
				W.draw(cBlue);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (player2.getOsada() < 6 - i) {
				vBlue.setOrigin(player2.getOsady(i).getOrigin());
				vBlue.rotate(player2.getOsady(i).getRotation());
				vBlue.setScale(player2.getOsady(i).getScale());
				vBlue.setPosition(player2.getOsady(i).getPosition());
				W.draw(vBlue);
			}
		}
		for (int i = 0; i < 15; i++) {
			if (player2.getDroga() < 16 - i) {
				rBlue.setOrigin(player2.getDrogi(i).getOrigin());
				rBlue.setRotation(player2.getDrogi(i).getRotation());
				rBlue.setScale(player2.getDrogi(i).getScale());
				rBlue.setPosition(player2.getDrogi(i).getPosition());
				W.draw(rBlue);
			}
		}
		//obiekty player3 Orange
		for (int i = 0; i < 4; i++) {
			if (player3.getMiasto() < 5 - i) {
				cOrange.setOrigin(player3.getMiasta(i).getOrigin());
				cOrange.rotate(player3.getMiasta(i).getRotation());
				cOrange.setScale(player3.getMiasta(i).getScale());
				cOrange.setPosition(player3.getMiasta(i).getPosition());
				W.draw(cOrange);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (player3.getOsada() < 6 - i) {
				vOrange.setOrigin(player3.getOsady(i).getOrigin());
				vOrange.rotate(player3.getOsady(i).getRotation());
				vOrange.setScale(player3.getOsady(i).getScale());
				vOrange.setPosition(player3.getOsady(i).getPosition());
				W.draw(vOrange);
			}
		}
		for (int i = 0; i < 15; i++) {
			if (player3.getDroga() < 16 - i) {
				rOrange.setOrigin(player3.getDrogi(i).getOrigin());
				rOrange.setRotation(player3.getDrogi(i).getRotation());
				rOrange.setScale(player3.getDrogi(i).getScale());
				rOrange.setPosition(player3.getDrogi(i).getPosition());
				W.draw(rOrange);
			}
		}
		//obiekty player4 White
		for (int i = 0; i < 4; i++) {
			if (player4.getMiasto() < 5 - i) {
				cWhite.setOrigin(player4.getMiasta(i).getOrigin());
				cWhite.rotate(player4.getMiasta(i).getRotation());
				cWhite.setScale(player4.getMiasta(i).getScale());
				cWhite.setPosition(player4.getMiasta(i).getPosition());
				W.draw(cWhite);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (player4.getOsada() < 6 - i) {
				vWhite.setOrigin(player4.getOsady(i).getOrigin());
				vWhite.rotate(player4.getOsady(i).getRotation());
				vWhite.setScale(player4.getOsady(i).getScale());
				vWhite.setPosition(player4.getOsady(i).getPosition());
				W.draw(vWhite);
			}
		}
		for (int i = 0; i < 15; i++) {
			if (player4.getDroga() < 16 - i) {
				rWhite.setOrigin(player4.getDrogi(i).getOrigin());
				rWhite.setRotation(player4.getDrogi(i).getRotation());
				rWhite.setScale(player4.getDrogi(i).getScale());
				rWhite.setPosition(player4.getDrogi(i).getPosition());
				W.draw(rWhite);
			}
		}

		}					//...a¿ tutaj.
		if (bSurowce==true) {
			surowce.setString("\t\t\t Clay\t Wool\t Wheat \t Wood\t Iron\nRed(1)\t\t" + to_string(player1.getcegla()) + "\t\t\t" + to_string(player1.getowce()) + "\t\t\t" + to_string(player1.getzboze()) + "\t\t\t" + to_string(player1.getdrewno()) + "\t\t" + to_string(player1.getzelazo()) + "\nBlue(2)\t\t" + to_string(player2.getcegla()) + "\t\t\t" + to_string(player2.getowce()) + "\t\t\t" + to_string(player2.getzboze()) + "\t\t\t" + to_string(player2.getdrewno()) + "\t\t" + to_string(player2.getzelazo()) + "\nOrange(3)\t" + to_string(player3.getcegla()) + "\t\t\t" + to_string(player3.getowce()) + "\t\t\t" + to_string(player3.getzboze()) + "\t\t\t" + to_string(player3.getdrewno()) + "\t\t" + to_string(player3.getzelazo()) + "\nWhite(4)\t\t" + to_string(player4.getcegla()) + "\t\t\t" + to_string(player4.getowce()) + "\t\t\t" + to_string(player4.getzboze()) + "\t\t\t" + to_string(player4.getdrewno()) + "\t\t" + to_string(player4.getzelazo()));
			W.draw(surowce);
		}
		W.draw(aPlayer);
		W.draw(info);
		if (wymiana == true) {
			W.draw(tradeBG);
			W.draw(trade);
		}
		if (rShop == true) {
			W.draw(rSh);
			W.draw(rS);
			W.draw(circl);
		}
		if (rShop2 == true) {
			W.draw(rSh);
			W.draw(rS);
			W.draw(linia1);
		}
		if (vShop == true) {
			W.draw(rSh);
			W.draw(rS);
			W.draw(circl);
		}
		if (erro == true) {
			W.draw(errBG);
			W.draw(err);
		}
		if (bShop == true) {
			W.draw(shopBG);
			W.draw(shop);
		}
		if (bandyci == true) {
			W.draw(banBG);
			W.draw(ban);
		}
		W.display();		 //wyœwietla obraz
	}
};