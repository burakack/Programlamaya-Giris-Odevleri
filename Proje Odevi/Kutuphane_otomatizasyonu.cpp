#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
using namespace std;
void kulgirissistemi();
void okuyucukayit();
void okuyucuguncelleme();
void okuyucusilme();
void ustundekikitaplist();
void kitapoduncalma();
void kitapgeridondurme();
void kitapgeridondurmeoto(string silinentc);
void kitapekle();
void kitapsil();
void kitapduzenle();
string Zaman();

int main()
{
	kulgirissistemi();
	int Secim;
	//Tum islemlerin defalarca yapilabilmesi icin dongu
	do {
		//ekrani temizliyoruz
		cout << "1 - Okuyucu kaydi" << endl;
		cout << "2 - Okuyucu kaydi guncelleme" << endl;
		cout << "3 - Okuyucu silme" << endl;
		cout << "4 - Okuyucu uzerindeki kitaplar listesi" << endl;
		cout << "5 - Okuyucu kitap odunc alma" << endl;
		cout << "6 - Okuyucu kitap geri dondurme" << endl;
		cout << "7 - Kitap ekleme" << endl;
		cout << "8 - Kitap silme" << endl;
		cout << "9 - Kitap duzeltme" << endl;
		cout << "10 - Cikis yapmak icin" << endl << endl;
		cout << "Secim yapiniz: "; cin >> Secim;
		if (Secim == 1)
			okuyucukayit();
		if (Secim == 2)
			okuyucuguncelleme();
		if (Secim == 3)
			okuyucusilme();
		if (Secim == 4)
			ustundekikitaplist();
		if (Secim == 5)
			kitapoduncalma();
		if (Secim == 6)
			kitapgeridondurme();
		if (Secim == 7)
			kitapekle();
		if (Secim == 8)
			kitapsil();
		if (Secim == 9)
			kitapduzenle();
		if (Secim == 10)
		{
			ofstream kullaniciyaz("Kullanicilar.txt", ios::app);
			kullaniciyaz << "\t Cikis zamani :" << Zaman() << endl;
			kullaniciyaz.close();
			cout << "Cikis Zamani: " << Zaman() << endl;
			break;
		}
	} while (true);
	return 0;
}
void kulgirissistemi()
{
	int Secim1;
	string Kuladi;
	string Sifre;
	//kayit yaptıktan sonra giris yapabilmek icin dongu
	do
	{
		char secimk = 'e';
		cout << "1)Kullanici kayit etmek" << endl << "2)Giris yapmak" << endl;
		cout << "Secim yapiniz: "; cin >> Secim1;
		if (Secim1 == 1)
		{
			ofstream Kayityaz("Kullanicilar.txt", ios::app);
			do {
				cout << "Kullanici adi belirleyin:"; cin >> Kuladi;
				cout << "Sifre belirleyin:"; cin >> Sifre;
				Kayityaz << setw(20) << Kuladi << setw(20) << Sifre << endl;
				//ekrani temizliyoruz
				system("cls");
				cout << "Kayit basarili!\n";
				cout << "Baska kayit yapmak ister misiniz?(e/h): "; cin >> secimk;
			} while (secimk == 'e' || secimk == 'E');
			//ekrani temizliyoruz
			system("cls");
			Kayityaz.close();
		}
		if (Secim1 == 2)
		{
			string kayitkuladi;
			string kayitsifre;
			/*Dosyadaki bilgi ile yazilan bilgi eslesmezse tekrar Kuladi Sifre istemesi icin dongu*/
			do
			{
				ofstream Kayityaz("Kullanicilar.txt", ios::app);
				ifstream Kayital("Kullanicilar.txt");
				cout << "Kullanici adinizi girin: "; cin >> Kuladi;
				cout << "Sifrenizi girin: "; cin >> Sifre;
				//Dosya icindeki kelimeleri tek tek kontrol etmesi icin dongu
				do
				{
					Kayital >> kayitkuladi >> kayitsifre;
					if (kayitkuladi == Kuladi && kayitsifre == Sifre)
						break;
				} while (!Kayital.eof());
				if (Kuladi == kayitkuladi && Sifre == kayitsifre)
				{
					//ekrani temizliyoruz
					system("cls");
					cout << "Hosgeldin " << Kuladi << "!\n";
					cout << "Giris saatiniz:" << Zaman() << endl;
					Kayityaz << "\n \t" << Kuladi << "  Giris zamani: \t" << setw(20) << Zaman();
				}
				else
				{
					//ekrani temizliyoruz
					system("cls");
					cout << "Giris bilgileriniz uyusmuyor! " << endl;
				}
				Kayityaz.close();
				Kayital.close();
			} while (!(Kuladi == kayitkuladi && Sifre == kayitsifre));
		}
	} while (Secim1 != 2);
}
void okuyucukayit()
{
	//Okuyucu.txt dosyasında yer alacak alanlar
	char Tc[80];
	string Okuyucuad;
	string Okuyucusoyad;
	string Uyeno;
	string Telefon;
	string Dogumtar;
	string Gorevi;
	string Kitap_limit;
	char secim;
	//Arka arkaya okuyucu kaydedebilmek icin dongu
	do
	{
		bool kontrol11hane;
		//tc alma ve kontrol
		do
		{
			kontrol11hane = true;
			cout << "Tc : ";
			cin >> Tc;
			if (strlen(Tc) != 11)
			{
				cout << "Tc kimlik numarasi 11 haneden olusmalidir ve sadece rakam icermelidir!" << endl;
				kontrol11hane = false;
			}
		} while (kontrol11hane == false);
		cout << "Ad: "; cin >> Okuyucuad;
		cout << "Soyad: "; cin >> Okuyucusoyad;
		cout << "Uye numarasi: "; cin >> Uyeno;
		cout << "Telefon: "; cin >> Telefon;
		cout << "Dogum tarihi: "; cin >> Dogumtar;
		cout << "Gorevi: "; cin >> Gorevi;
		cout << "Kitap limiti: "; cin >> Kitap_limit;
		ofstream okuyucugir("Okuyucu.txt", ios::app);
		okuyucugir << setw(20) << Uyeno << setw(20) << Tc << setw(20) << Okuyucuad << setw(20) << Okuyucusoyad
			<< setw(20) << Telefon << setw(20) << Dogumtar << setw(20) << Gorevi << setw(20) << Kitap_limit << endl;
		okuyucugir.close();
		cout << "Kayit tamamlandi" << endl;
		cout << "Baska okuyucu kaydedecek misiniz?(e/h)"; cin >> secim;
	} while (secim == 'e');

}
void okuyucuguncelleme()
{
	//okuyucu.txt ve gecici.txt icin degiskenler
	char Tc[80];
	string Okuyucuad;
	string Okuyucusoyad;
	string Uyeno;
	string Telefon;
	string Dogumtar;
	string Gorevi;
	string Kitap_limit;
	string uyeno; //kullanıcı girdisini dosya icinde aramak icin
	cout << "Guncellemek istediginiz okuyucunun uyenosunu giriniz: "; cin >> uyeno;
	int verisayisi = 0;//kac tane okuyucu verisi oldugunu anlamamızı saglayacak
	ofstream Dosyayaz("gecici.txt", ios::app);
	ifstream Dosyaal("Okuyucu.txt", ios::in);
	while (!Dosyaal.eof())
	{
		Dosyaal >> Uyeno >> Tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		verisayisi += 1;
	}
	verisayisi -= 1;//for döngüsü her zaman kaç sıra  verimiz varsa +1 kadar hesaplıyor bu nedenle -1 çıkartıyoruz
	Dosyaal.close();
	bool kontrol11hane;
	//tc alma ve kontrol
	do
	{
		kontrol11hane = true;
		cout << "yen  tc : ";
		cin >> Tc;
		if (strlen(Tc) != 11)
		{
			cout << "Tc kimlik numarasi 11 haneden olusmalidir ve sadece rakam icermelidir!" << endl;
			kontrol11hane = false;
		}
	} while (kontrol11hane == false);
	cout << "yeni ad: "; cin >> Okuyucuad;
	cout << "yeni soyad: "; cin >> Okuyucusoyad;
	cout << "yeni telefon: "; cin >> Telefon;
	cout << "yeni dogum tarihi: "; cin >> Dogumtar;
	cout << "yeni gorevi: "; cin >> Gorevi;
	cout << "yeni kitap limiti: "; cin >> Kitap_limit;
	Dosyaal.open("Okuyucu.txt", ios::in);
	//girilen degerleri dogrudan gecici.txt dosyamıza yazıyoruz
	Dosyayaz << setw(20) << uyeno << setw(20) << Tc << setw(20) << Okuyucuad << setw(20) << Okuyucusoyad
		<< setw(20) << Telefon << setw(20) << Dogumtar << setw(20) << Gorevi << setw(20) << Kitap_limit << endl;
	//guncellenmek istenen deger disinda her seyi gecici.txt ye yazmak icin dongu
	for (int i = 0; i < verisayisi; i++)
	{
		Dosyaal >> Uyeno >> Tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		if (Uyeno == uyeno)
		{
			cout << "---Guncellenen eski okuyucu bilgileri----" << endl;
			cout << "Uyeno:" << Uyeno << endl;
			cout << "Tc: " << Tc << endl;
			cout << "Ad: " << Okuyucuad << endl;
			cout << "Soyad: " << Okuyucusoyad << endl;
			cout << "Uye numarasi: " << Uyeno << endl;
			cout << "Telefon: " << Telefon << endl;
			cout << "Dogum tarihi: " << Dogumtar << endl;
			cout << "Gorevi: " << Gorevi << endl;
			cout << "Kitap limiti: " << Kitap_limit << endl;
		}
		else
			Dosyayaz << setw(20) << Uyeno << setw(20) << Tc << setw(20) << Okuyucuad << setw(20) << Okuyucusoyad
			<< setw(20) << Telefon << setw(20) << Dogumtar << setw(20) << Gorevi << setw(20) << Kitap_limit << endl;
	}
	Dosyaal.close();
	Dosyayaz.close();
	remove("Okuyucu.txt");
	rename("gecici.txt", "Okuyucu.txt");

}
void okuyucusilme()
{
	//kitapları dondurmek icin silinentcyi saklıyoruz
	string silinentc;
	//Okuyucu.txt icin degiskenler
	string Tc;
	string Okuyucuad;
	string Okuyucusoyad;
	string Uyeno;
	string Telefon;
	string Dogumtar;
	string Gorevi;
	string Kitap_limit;
	string uyeno; //kullanıcı girdisini dosya icinde aramak icin
	int verisayisi = 0;//kac tane okuyucu verisi oldugunu anlamamızı saglayacak
	cout << "Silmek istediginiz okuyucunun uyenosunu giriniz: "; cin >> uyeno;
	ofstream Dosyayaz("gecici.txt", ios::app);
	ifstream Dosyaal("Okuyucu.txt", ios::in);
	while (!Dosyaal.eof())
	{
		Dosyaal >> Uyeno >> Tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		verisayisi += 1;
	}
	verisayisi -= 1;//for döngüsü her zaman kaç sıra  verimiz varsa +1 kadar hesaplıyor bu nedenle -1 çıkartıyoruz
	Dosyaal.close();
	Dosyaal.open("Okuyucu.txt", ios::in);
	for (int i = 0; i < verisayisi; i++)
	{
		Dosyaal >> Uyeno >> Tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		if (Uyeno == uyeno)
		{
			silinentc = Tc;
			cout << "----Silinen okuyucu bilgileri----" << endl;
			cout << "Uyeno:" << Uyeno << endl;
			cout << "Tc: " << Tc << endl;
			cout << "Ad: " << Okuyucuad << endl;
			cout << "Soyad: " << Okuyucusoyad << endl;
			cout << "Uye numarasi: " << Uyeno << endl;
			cout << "Telefon: " << Telefon << endl;
			cout << "Dogum tarihi: " << Dogumtar << endl;
			cout << "Gorevi: " << Gorevi << endl;
			cout << "Kitap limiti: " << Kitap_limit << endl;
		}
		else
		{
			Dosyayaz << setw(20) << Uyeno << setw(20) << Tc << setw(20) << Okuyucuad << setw(20) << Okuyucusoyad
				<< setw(20) << Telefon << setw(20) << Dogumtar << setw(20) << Gorevi << setw(20) << Kitap_limit << endl;
		}
	}
	Dosyaal.close();
	Dosyayaz.close();
	remove("Okuyucu.txt");
	rename("gecici.txt", "Okuyucu.txt");
	kitapgeridondurmeoto(silinentc);
}
void ustundekikitaplist()
{
	/*Bu fonksiyon kitap bilgileri için  Kitaplar.txt
	 Odunc bilgileri için Odunc.txt dosyasına bagli olmalidir.*/
	 //Odunc dosyası degiskenleri
	string TC;
	string Odunctarihi;
	string Donustarihi;
	//Okuyucular dosyasinda aramak icin
	string tc;
	//Kitaplar dosyası degiskenleri
	string Isbn;
	string Kitapismi;
	string Yazaradi;
	string Yazarsoyadi;
	string Konu;
	string Tur;
	string Sayfasayisi;
	//Kitaplar dosyasinda aramak icin
	string isbn;
	/*kitap ve odunc dosyalarinin veri sayilarini bulmamiz gerekiyor
	cünkü .eof() metodu ile dongu kurdugumuzda dongu fazladan bir kez daha calisiyor hatalar olusuyor*/
	int verisayisikitap = 0;
	int verisayisiodunc = 0;
	ifstream Oduncbilgial("Odunc.txt", ios::in);
	while (!Oduncbilgial.eof())
	{
		Oduncbilgial >> isbn >> TC >> Odunctarihi >> Donustarihi;
		verisayisiodunc += 1;
	}
	Oduncbilgial.close();
	verisayisiodunc -= 1;
	ifstream Kitapalbilgi("Kitaplar.txt", ios::in);
	while (!Kitapalbilgi.eof())
	{
		Kitapalbilgi >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		verisayisikitap += 1;
	}
	Kitapalbilgi.close();
	verisayisikitap -= 1;

	ifstream Oduncverial("Odunc.txt", ios::in);
	ifstream Kitapverial("Kitaplar.txt", ios::in);

	cout << "Sorgulamak istediginiz TC numarasini giriniz: "; cin >> tc;
	cout << "Okuyucunun donmemis kitaplari" << endl;
	cout << "----------------------------------" << endl;
	//odunc dosyasinda isbnyi ve tcyi ariyoruz
	for (int i = 0; i < verisayisiodunc; i++)
	{
		Oduncverial >> isbn >> TC >> Odunctarihi >> Donustarihi;
		if (tc == TC)
		{
			//tcler aynıysa kitaplar dosyasında isbnyi aratıyorum
			for (int j = 0; j < verisayisikitap; j++)
			{
				Kitapverial >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
				if (Isbn == isbn && Donustarihi == "Donmedi!")
				{
					cout << "Isbn:" << Isbn << endl;
					cout << "Kitap ismi: " << Kitapismi << endl;
					cout << "Yazar adi: " << Yazaradi << endl;
					cout << "Yazar soyadi: " << Yazarsoyadi << endl;
					cout << "Konu: " << Konu << endl;
					cout << "Tur: " << Tur << endl;
					cout << "Sayfa sayisi: " << Sayfasayisi << endl;
					cout << "Odunc tarihi: " << Odunctarihi << endl;
					cout << "Donustarihi: " << Donustarihi << endl;
					cout << "----------------------------------" << endl;
				}
			}

		}
	}
	Oduncverial.close();
	Kitapverial.close();
}
void kitapoduncalma()
{
	string isbn; // kitabı aratabilmek icin kullanicidan aliyoruz
	string Isbn;
	string uyeno; // okuyucuyu aratabilmek icin kullanicidan aliyoruz
	string Uyeno;
	string Tc;
	string tc; //uye no ya ait tcyi ararken kullaniyoruz.
	//okuyucu dosyasi degiskenleri
	string Okuyucuad;
	string Okuyucusoyad;
	string Telefon;
	string Dogumtar;
	string Gorevi;
	string Kitap_limit;
	//kitap dosyasi degiskenleri
	string Kitapismi;
	string Yazaradi;
	string Yazarsoyadi;
	string Konu;
	string Tur;
	string Sayfasayisi;
	string Donustarihi = "Donmedi!";
	bool kontrol = false;
	//kullanicidan direkt okuyucunun tc kimlik numarasini alabilirdik ama sık bir hareket olmazdi. uye no aliyoruz.
	cout << "Odunc almak isteyen okuyucunun uye no giriniz: "; cin >> uyeno;
	cout << "Odunc almak istediginiz kitabin Isbn giriniz: "; cin >> isbn;
	ifstream Okuyucual("Okuyucu.txt", ios::in);
	ifstream Dosyaal("Kitaplar.txt", ios::in);
	ofstream Dosyayaz("Odunc.txt", ios::app);
	//bu uye no ya sahip tc kimlik numarasini buluyorum
	while (!Okuyucual.eof())
	{
		//boyle bir okuyucu var mi kontrol ediyoruz
		Okuyucual >> Uyeno >> tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		if (uyeno == Uyeno)
		{
			Tc = tc;
			kontrol = true;
			break;
		}
	}
	if (!kontrol)
		cout << "Boyle bir kullanici bulunamadi!!" << endl;
	//Boyle bir okuyucu var ise Kitaplar dosyasında isbnyi kontrol ediyorum
	do
	{
		Dosyaal >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		if (Isbn == isbn)
		{
			string Odunctarihi = Zaman();
			Dosyayaz << setw(20) << isbn << setw(20) << Tc << setw(30) << Odunctarihi << setw(30) << Donustarihi << endl;
			cout << "Odunc alma islemi gerceklesitirildi!" << endl;
			break;
		}
		else
			cout << "Böyle bir kitap bulunamadi!" << endl;
	} while (!Dosyaal.eof() && kontrol);
	Okuyucual.close();
	Dosyaal.close();
	Dosyayaz.close();
}
void kitapgeridondurme()
{
	//odunc dosyası degiskenleri
	string Isbn;//kitaplar dosyasinda kitabi tespit  edebilmek icin
	string isbn;
	string Tc;
	string Odunctarihi;
	string Donustarihi = "Donmedi!";
	//kitap dosyası degiskenleri
	string iisbn;
	string Kitapismi;
	string Yazaradi;
	string Yazarsoyadi;
	string Konu;
	string Tur;
	string Sayfasayisi;
	//okuyucu dosyasi degiskenleri
	string tc;
	string Okuyucuad;
	string Okuyucusoyad;
	string Uyeno; // okuyucu dosyasinda okuyucuyu tespit edebilmek icin
	string uyeno;
	string Telefon;
	string Dogumtar;
	string Gorevi;
	string Kitap_limit;
	bool kontrol = false;
	cout << "Geri dondurmek isteyen okuyucunun uye nosunu giriniz: "; cin >> Uyeno;
	cout << "Geri dondurmek istediginiz kitabın ISBN giriniz: "; cin >> Isbn;
	/*kitap ve odunc dosyalarinin veri sayilarini bulmamiz gerekiyor
	cünkü .eof() metodu ile dongu kurdugumuzda dongu fazladan bir kez daha calisiyor hatalar olusuyor*/
	int verisayisikitap = 0;
	int verisayisiodunc = 0;
	ifstream Oduncbilgial("Odunc.txt", ios::in);
	while (!Oduncbilgial.eof())
	{
		Oduncbilgial >> isbn >> Tc >> Odunctarihi >> Donustarihi;
		verisayisiodunc += 1;
	}
	verisayisiodunc -= 1;
	Oduncbilgial.close();
	ifstream Kitapalbilgi("Kitaplar.txt", ios::in);
	while (!Kitapalbilgi.eof())
	{
		Kitapalbilgi >> isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		verisayisikitap += 1;
	}
	verisayisikitap -= 1;
	Kitapalbilgi.close();
	ifstream Okuyucudosyaal("Okuyucu.txt", ios::in);
	ifstream Oduncdosyaal("Odunc.txt", ios::in);
	ofstream Geciciodunc("gecici.txt", ios::app);
	while (!Okuyucudosyaal.eof())
	{
		Okuyucudosyaal >> uyeno >> tc >> Okuyucuad >> Okuyucusoyad >> Telefon >> Dogumtar >> Gorevi >> Kitap_limit;
		if (Uyeno == uyeno)
		{
			Tc = tc;
			kontrol = true;
			Okuyucudosyaal.close();
		}
	}
	if (kontrol == false)
		cout << "Boyle bir okuyucu yoktur!!" << endl;
	for (int i = 0; i < verisayisiodunc; i++)
	{
		Oduncdosyaal >> isbn >> tc >> Odunctarihi >> Donustarihi;
		if (Tc == tc && isbn == Isbn)
		{
			Donustarihi = Zaman();
			Geciciodunc << setw(30) << isbn << setw(30) << tc << setw(30) << Odunctarihi << setw(30) << Donustarihi << endl;
			cout << "Kitabiniz basariyla geri donduruldu! " << endl;
			cout << "-----Geri dondurulen kitap bilgileri------" << endl;
			//Geri dondurulen kitabin bilgilerini yazdiriyoruz
			ifstream Kitapdosyaal("Kitaplar.txt", ios::in);
			for (int i = 0; i < verisayisikitap; i++)
			{
				Kitapdosyaal >> iisbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
				if (Isbn == iisbn)
				{
					cout << "Isbn:" << iisbn << endl;
					cout << "Kitap ismi: " << Kitapismi << endl;
					cout << "Yazar adi: " << Yazaradi << endl;
					cout << "Yazar soyadi: " << Yazarsoyadi << endl;
					cout << "Konu: " << Konu << endl;
					cout << "Tur: " << Tur << endl;
					cout << "Sayfa sayisi: " << Sayfasayisi << endl;
					cout << "Odunc tarihi: " << Odunctarihi << endl;
					cout << "Donustarihi: " << Donustarihi << endl;
					cout << "----------------------------------" << endl;
					break;
				}
			}
			Donustarihi = "Donmedi!";
			Kitapdosyaal.close();
		}
		else
			Geciciodunc << setw(30) << isbn << setw(30) << tc << setw(30) << Odunctarihi << setw(30) << Donustarihi << endl;
	}

	Oduncdosyaal.close();
	Geciciodunc.close();
	remove("Odunc.txt");
	rename("gecici.txt", "Odunc.txt");
}
void kitapgeridondurmeoto(string silinentc)
{
	//odunc dosyası degiskenleri
	string Isbn;//kitaplar dosyasinda kitabi tespit  edebilmek icin
	string isbn;
	string Tc;
	string Odunctarihi;
	string Donustarihi = "Donmedi!";
	/* odunc dosyasinin veri sayilarini bulmamiz gerekiyor
	cünkü .eof() metodu ile dongu kurdugumuzda dongu fazladan bir kez daha calisiyor hatalar olusuyor*/
	int verisayisiodunc = 0;
	ifstream Oduncbilgial("Odunc.txt", ios::in);
	//Veri sayisini ogreniyoruz
	while (!Oduncbilgial.eof())
	{
		Oduncbilgial >> isbn >> Tc >> Odunctarihi >> Donustarihi;
		verisayisiodunc += 1;
	}
	verisayisiodunc -= 1;
	Oduncbilgial.close();
	ifstream Oduncdosyaal("Odunc.txt", ios::in);
	ofstream Geciciodunc("gecici.txt", ios::app);
	for (int i = 0; i < verisayisiodunc; i++)
	{
		Oduncdosyaal >> isbn >> Tc >> Odunctarihi >> Donustarihi;
		if (Tc == silinentc && Donustarihi == "Donmedi!")
		{
			Donustarihi = Zaman();
			Geciciodunc << setw(30) << isbn << setw(30) << Tc << setw(30) << Odunctarihi << setw(30) << Donustarihi << endl;
			cout << "Okuyucunun kitabi basariyla geri donduruldu! " << endl;
		}
		else
			Geciciodunc << setw(30) << isbn << setw(30) << Tc << setw(30) << Odunctarihi << setw(30) << Donustarihi << endl;
	}

	Oduncdosyaal.close();
	Geciciodunc.close();
	remove("Odunc.txt");
	rename("gecici.txt", "Odunc.txt");
}
void kitapekle()
{
	char secim;
	do {
		//Kitaplar.txt degiskenleri
		string Isbn;
		string Kitapismi;
		string Yazaradi;
		string Yazarsoyadi;
		string Konu;
		string Tur;
		string Sayfasayisi;
		ofstream Dosyayaz("Kitaplar.txt", ios::app);
		cout << "ISBN giriniz: "; cin >> Isbn;
		cout << "Kitap ismi giriniz: "; cin >> Kitapismi;
		cout << "Yazar adi giriniz: "; cin >> Yazaradi;
		cout << "Yazar soyadi giriniz: "; cin >> Yazarsoyadi;
		cout << "Konu giriniz: "; cin >> Konu;
		cout << "Tur giriniz: "; cin >> Tur;
		cout << "Sayfa sayisi giriniz: "; cin >> Sayfasayisi;
		Dosyayaz << setw(20) << Isbn << setw(20) << Kitapismi << setw(20) << Yazaradi << setw(20) << Yazarsoyadi
			<< setw(20) << Konu << setw(20) << Tur << setw(20) << Sayfasayisi << endl;
		Dosyayaz.close();
		cout << "Baska kitap eklemek ister misiniz(e/h)? "; cin >> secim;
	} while (secim == 'e');

}
void kitapsil()
{
	//Kitaplar.txt degiskenleri
	string Isbn;
	string Kitapismi;
	string Yazaradi;
	string Yazarsoyadi;
	string Konu;
	string Tur;
	string Sayfasayisi;
	string isbn; //kullanıcı girdisini dosya icinde aramak icin
	cout << "Silmek istediginiz kitabin Isbn  giriniz: "; cin >> isbn;
	ofstream Dosyayaz("gecici.txt", ios::app);
	ifstream Kitapbilgial("Kitaplar.txt", ios::in);
	int verisayisikitap = 0;
	while (!Kitapbilgial.eof())
	{
		Kitapbilgial >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		verisayisikitap += 1;
	}
	verisayisikitap -= 1;
	Kitapbilgial.close();
	ifstream Dosyaal("Kitaplar.txt", ios::in);
	for (int i = 0; i < verisayisikitap; i++)
	{
		Dosyaal >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		if (Isbn == isbn)
		{
			cout << "----Silinen kitap bilgileri----" << endl;
			cout << "Isbn:" << Isbn << endl;
			cout << "Kitap ismi: " << Kitapismi << endl;
			cout << "Yazaradi: " << Yazaradi << endl;
			cout << "Yazarsoyadi: " << Yazarsoyadi << endl;
			cout << "Konu: " << Konu << endl;
			cout << "Tur: " << Tur << endl;
			cout << "Sayfa sayisi: " << Sayfasayisi << endl;
		}
		else
			Dosyayaz << setw(20) << Isbn << setw(20) << Kitapismi << setw(20) << Yazaradi << setw(20) << Yazarsoyadi
			<< setw(20) << Konu << setw(20) << Tur << setw(20) << Sayfasayisi << endl;
	}
	Dosyaal.close();
	Dosyayaz.close();
	remove("Kitaplar.txt");
	rename("gecici.txt", "Kitaplar.txt");

}
void kitapduzenle()
{
	string Isbn;
	string Kitapismi;
	string Yazaradi;
	string Yazarsoyadi;
	string Konu;
	string Tur;
	string Sayfasayisi;
	string isbn; //kullanıcı girdisini dosya icinde aramak icin
	ifstream Kitapbilgial("Kitaplar.txt", ios::in);
	int verisayisikitap = 0;
	while (!Kitapbilgial.eof())
	{
		Kitapbilgial >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		verisayisikitap += 1;
	}
	verisayisikitap -= 1;
	Kitapbilgial.close();
	cout << "Guncellemek istediginiz kitabin Isbn giriniz: "; cin >> isbn;
	cout << "yeni Kitap ismi: "; cin >> Kitapismi;
	cout << "yeni Yazar adi: "; cin >> Yazaradi;
	cout << "yeni Yazar soyadi: "; cin >> Yazarsoyadi;
	cout << "yeni Konu: "; cin >> Konu;
	cout << "yeni Tur: "; cin >> Tur;
	cout << "yeni Sayfasayisi: "; cin >> Sayfasayisi;
	ofstream Dosyayaz("gecici.txt", ios::app);
	ifstream Dosyaal("Kitaplar.txt", ios::in);
	Dosyayaz << setw(20) << isbn << setw(20) << Kitapismi << setw(20) << Yazaradi << setw(20) << Yazarsoyadi << setw(20)
		<< Tur << setw(20) << Konu << setw(20) << Sayfasayisi << endl;
	for (int i = 0; i < verisayisikitap; i++)
	{
		Dosyaal >> Isbn >> Kitapismi >> Yazaradi >> Yazarsoyadi >> Konu >> Tur >> Sayfasayisi;
		if (Isbn == isbn)
		{
			cout << "----Guncellenen kitabin bilgileri----" << endl;
			cout << "Isbn:" << Isbn << endl;
			cout << "Kitap ismi: " << Kitapismi << endl;
			cout << "Yazar adi: " << Yazaradi << endl;
			cout << "Yazar soyadi: " << Yazarsoyadi << endl;
			cout << "Konu: " << Konu << endl;
			cout << "Tur: " << Tur << endl;
			cout << "Sayfa sayisi: " << Sayfasayisi << endl;

		}
		else
			Dosyayaz << setw(20) << Isbn << setw(20) << Kitapismi << setw(20) << Yazaradi << setw(20) << Yazarsoyadi
			<< setw(20) << Konu << setw(20) << Tur << setw(20) << Sayfasayisi << endl;
	}
	Dosyaal.close();
	Dosyayaz.close();
	remove("Kitaplar.txt");
	rename("gecici.txt", "Kitaplar.txt");

}
string Zaman()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       Zaman[80];
#pragma warning(disable: 4996)
	tstruct = *localtime(&now);
#pragma warning(default: 4996)
	strftime(Zaman, sizeof(Zaman), "%H:%M:%S___%d-%m-%Y", &tstruct);

	return Zaman;
}
