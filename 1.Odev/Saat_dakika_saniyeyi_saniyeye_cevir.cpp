#include <iostream>

using namespace std;

int main()
{
	struct Zaman
	{
		int saat;
		int dakika;
		int saniye;
		long toplam_saniye;
	};
	char ikinokta;
	Zaman Sure;
	cout << "Saat:Dakika:Saniye seklinde zamani giriniz: ";
	cin >> Sure.saat >> ikinokta >> Sure.dakika >> ikinokta >> Sure.saniye;
	//Sure.saatin dogru aralik icinde olup olmadıgını kontrol ediyoruz
	if (Sure.saat > 24 || Sure.saat < 0)
		cout << "Girilen saat degeri " << Sure.saat << " yanlis girilmistir" << endl;
	//Sure.dakikanin dogru aralik icinde olup olmadıgını kontrol ediyoruz
	if (Sure.dakika > 60 || Sure.dakika < 0)
		cout << "Girilen dakika degeri " << Sure.dakika << " yanlis girilmistir" << endl;
	//Sure.saniyenin dogru aralik icinde olup olmadıgını kontrol ediyoruz
	if (Sure.saniye > 60 || Sure.saniye < 0)
		cout << "Girilen saniye degeri " << Sure.saniye << " yanlis girilmistir" << endl;
	//toplam_saniye hesaplanip yazdirilmasi için gereken kosullari kontrol ediyoruz
	if (Sure.saat < 24 && Sure.dakika < 60 && Sure.saniye < 60 && Sure.saat >= 0 && Sure.dakika >= 0 && Sure.saniye >= 0)
	{
		Sure.toplam_saniye = Sure.saat * 3600 + Sure.dakika * 60 + Sure.saniye;
		cout << "Saniye olarak hesaplanan deger: " << Sure.toplam_saniye << endl;
	}
	return 0;
}
