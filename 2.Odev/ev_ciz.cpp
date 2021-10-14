#include <iostream>
#include <windows.h>
using namespace std;
class Cati
{
private:
	char karaktercati = '*';
	int Catiyukseklik;
	int Catigenislik;
	int x;
	int y;
public:
	void caticiz();
	void getcatidegerleri(int Catiyukseklik, int Genislik, int x, int y);
};
class Kat
{
private:
	char Katkarakter = (char)219;
	int Katyukseklik;
	int Katgenislik;
	int x;
	int y;
public:
	void katciz();
	void getkatdegerleri(int Catiyukseklik, int Yukseklik, int Genislik, int x, int y);
};
class Kapi
{
private:
	char Kapikarakter = '#';
	int Kapiyukseklik;
	int Kapigenislik;
	int x;
	int y;
public:
	void kapiciz();
	void getkapidegerleri(int Yukseklik, int Catiyukseklik, int x, int y, int Genislik);
};
class Ev : public Cati, public Kat, public Kapi
{
private:
	int x;
	int y;
public:
	void evciz(Ev cati, Ev kat, Ev kapi);
	void getevdegerleri(int x, int y);
};
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
	int x;
	int y;
	int Yukseklik;
	int Catiyukseklik;
	int Genislik;
	cout << "Genislik: "; cin >> Genislik;
	cout << "Yukseklik: "; cin >> Yukseklik;
	cout << "Catiyukseklik: "; cin >> Catiyukseklik;
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	Ev ev;
	Ev Cati;
	Ev Kat;
	Ev Kapi;
	Cati.getcatidegerleri(Catiyukseklik, Genislik, x, y);
	Kat.getkatdegerleri(Catiyukseklik, Yukseklik, Genislik, x, y);
	Kapi.getkapidegerleri(Yukseklik, Catiyukseklik, x, y, Genislik);
	ev.getevdegerleri(x, y);
	ev.evciz(Cati, Kat, Kapi);
	return 0;
}
void Cati::getcatidegerleri(int Catiyukseklik, int Genislik, int x, int y)
{
	this->Catiyukseklik = Catiyukseklik;
	Catigenislik = Genislik;
	this->x = x;
	this->y = y;
}
void Kat::getkatdegerleri(int Catiyukseklik, int Yukseklik, int Genislik, int x, int y)
{
	Katyukseklik = Yukseklik;
	Katgenislik = Genislik;
	this->x = x;
	this->y = y + Catiyukseklik;
}
void Kapi::getkapidegerleri(int Yukseklik, int Catiyukseklik, int x, int y, int Genislik)
{
	Kapiyukseklik = (Yukseklik / 3); //Tam sayiya yuvarlanıyor
	Kapigenislik = (Genislik / 5);	//Tam sayiya yuvarlanıyor
	this->x = x + Genislik - Kapigenislik - 5; //kapimiz evin sag duvarindan 5 birim solda olsun
	this->y = y + Yukseklik + Catiyukseklik - Kapiyukseklik;
}
void Ev::getevdegerleri(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Cati::caticiz()
{	//	Catinin soldaki karakter ucgenini cizdiriyoruz
	for (int i = 0; i < Catiyukseklik; i++)
	{
		gotoxy(x - 1, y + i);
		for (int j = 0; j < Catiyukseklik - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << karaktercati;
		}
	}
	//Catinin 2 ucgen arasinndaki alani karakterle dolduruyor
	for (int i = 0; i < Catiyukseklik; i++)
		for (int j = 0; j < (Catigenislik - 2 * Catiyukseklik + 1); j++)
		{
			gotoxy(x + Catiyukseklik + j, y + i);
			cout << karaktercati;
		}
	//	Catinin sagdaki karakter ucgenini cizdiriyoruz
	for (int i = 0; i < Catiyukseklik; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			gotoxy(x + Catigenislik - Catiyukseklik + j + 1, y + i);
			cout << karaktercati;
		}
	}

}
void Kat::katciz()
{
	//evin tavanini ciziyor
	for (int i = 0; i < Katgenislik; i++)
	{
		gotoxy(x + i, y);
		cout << Katkarakter;
	}
	//evin sag duvarini ciziyor
	for (int i = 0; i < Katyukseklik; i++)
	{
		gotoxy(x + Katgenislik, y + i);
		cout << Katkarakter;
	}
	//evin sol duvarini ciziyor
	for (int i = 0; i < Katyukseklik; i++)
	{
		gotoxy(x, y + i);
		cout << Katkarakter;
	}
	//evin zeminini ciziyor	 
	for (int i = 0; i <= Katgenislik; i++)
	{
		gotoxy(x + i, y + Katyukseklik);
		cout << Katkarakter;
	}

}
void Kapi::kapiciz()
{
	//Kat cizildikten sonra katin icine zeminin ustune gelecek sekilde olculeri belli olan dikdortgeni cizdiriyoruz
	for (int i = 0; i < Kapigenislik; i++)
	{
		for (int j = 0; j < Kapiyukseklik; j++)
		{
			gotoxy(x + i, y + j + 1);
			cout << Kapikarakter;
		}
	}
}
void Ev::evciz(Ev cati, Ev kat, Ev kapi)
{
	cati.caticiz();
	kat.katciz();
	kapi.kapiciz();
	cout << endl; //kapi cizdikten sonra kat karakterlerinden birisini bozmamasi icin bunu yapiyorum
}
