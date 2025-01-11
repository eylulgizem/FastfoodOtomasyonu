#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

//Eyl�l Gizem Elidar-Fastfood Ootomasyonu

class Urun 
{
    public:
    int urunNo;
    string urunAdi;
    double fiyat;

    Urun(): urunNo(0), urunAdi(""), fiyat(0.0) {}
};

class FastfoodOtomasyon 
{
    private:
    Urun urunler[100]; 
    int mevcutElemanSayisi=0;
    int siradakiNo=1;

    int noyaGoreUrunBul(int urunNo) 
	{
        for(int i=0; i<mevcutElemanSayisi; ++i) 
		{
            if(urunler[i].urunNo==urunNo) 
			{
                return i;
            }
        }
        return -1;
    }

    public:

    void urunEkle(const std::string& urunAdi, double fiyat)
	{
        if(mevcutElemanSayisi>=100) 
		{
            cout << "Men� dolu, �r�n eklenemdi." << endl;
            cout << endl; 
            return;
        }
        
        urunler[mevcutElemanSayisi].urunNo=siradakiNo++;
        urunler[mevcutElemanSayisi].urunAdi=urunAdi;
        urunler[mevcutElemanSayisi].fiyat=fiyat;
        mevcutElemanSayisi++;
        cout << "�r�n eklendi: [" << urunler[mevcutElemanSayisi-1].urunNo << "] " << urunler[mevcutElemanSayisi-1].urunAdi << " => " << urunler[mevcutElemanSayisi-1].fiyat << "TL" << endl;
        cout << endl; 
    }
 
    void urunSil(int urunNo) 
	{
        int index=noyaGoreUrunBul(urunNo);
        if(index!=-1) 
		{
            cout << "�r�n silindi: [" << urunler[index].urunNo << "] " << urunler[index].urunAdi << "\n";
            cout << endl; 
            for(int i=index; i<mevcutElemanSayisi-1; ++i) 
			{
                urunler[i]=urunler[i+1];
            }
            mevcutElemanSayisi--;
        }
		
		else 
		{
            cout << urunNo << " �r�n numaras� ile e�le�en �r�n bulunamad�." << endl;
            cout << endl; 
        }
    }

    void urunGuncelle(int urunNo, const std::string& yeniAdi, double yeniFiyat) 
	{
        int index=noyaGoreUrunBul(urunNo);
        if(index!=-1) 
		{
            urunler[index].urunAdi=yeniAdi;
            urunler[index].fiyat=yeniFiyat;
            cout << "�r�n g�ncellendi: [" << urunler[index].urunNo << "] " << urunler[index].urunAdi << " (" << urunler[index].fiyat << " TL)\n";
            cout << endl; 
        } 
		
		else 
		{
            cout << "\"" << urunNo << "\" �r�n numaras� ile e�le�en �r�n bulunamad�." << endl;
            cout << endl; 
        }
    }

    void urunAra(const std::string& urunAdi) 
	{
        bool bulundu=false;
        for(int i=0; i<mevcutElemanSayisi; ++i) 
		{
            if(urunler[i].urunAdi.find(urunAdi)!=string::npos) 
			{
                cout << "Bulunan �r�n: [" << urunler[i].urunNo << "] " << urunler[i].urunAdi << " (" << urunler[i].fiyat << " TL)\n";
                cout << endl; 
                bulundu=true;
            }
        }
        
        if(!bulundu) 
		{
            cout << "\"" << urunAdi << "\" ad�na sahip bir �r�n bulunamad�." << endl;
            cout << endl; 
        }
    }

    void menuGoster() const 
	{
        if(mevcutElemanSayisi==0) 
		{
            cout << "Men�de �r�n yok." << endl;
            cout << endl; 
            return;
        }

        cout << "\nMevcut Men�:" << endl;
        cout << endl; 
        for(int i=0; i<mevcutElemanSayisi; ++i) 
		{
            cout << "[" << urunler[i].urunNo << "] " << urunler[i].urunAdi << " - " << urunler[i].fiyat << " TL\n";
        }
    }
};

int main() 
{
	setlocale(LC_ALL, "Turkish");
	
    FastfoodOtomasyon fastFood;
    int secim;

    do 
	{
        cout << "Fastfood Otomasyon Sistemi:" << endl;
        cout << "1- �r�n Ekle" << endl;
        cout << "2- �r�n Sil" << endl;
        cout << "3- �r�n G�ncelle" << endl;
        cout << "4- �r�n Ara" << endl;
        cout << "5- Men�y� G�ster" << endl;
        cout << "6- ��k�� Yap" << endl;
        cout << endl; 
        cout << "��lem se�imi yap�n�z: " << endl;
        cin >> secim;

        switch(secim) 
		{
            case 1: 
			{
                string urunAdi;
                double fiyat;
                cout << "�r�n ad�n� girin: " << endl;
                cin.ignore();
                getline(cin, urunAdi);
                cout << "�r�n fiyat�n� girin: " << endl;
                cin >> fiyat;
                fastFood.urunEkle(urunAdi, fiyat);
                break;
            }
            case 2: 
			{
                int urunNo;
                cout << "Silinecek �r�n�n numaras�n� girin: " << endl;
                cin >> urunNo;
                fastFood.urunSil(urunNo);
                break;
            }
            case 3: 
			{
                int urunNo;
                string urunAdi;
                double fiyat;
                cout << "G�ncellenecek �r�n�n numaras�n� girin: " << endl;
                cin >> urunNo;
                cout << "Yeni �r�n ad�n� girin: " << endl;
                cin.ignore();
                getline(cin, urunAdi);
                cout << "Yeni �r�n fiyat�n� girin: " << endl;
                cin >> fiyat;
                fastFood.urunGuncelle(urunNo, urunAdi, fiyat);
                break;
            }
            case 4: 
			{
                string urunAdi;
                cout << "Aranacak �r�n ad�n� girin: " << endl;
                cin.ignore();
                getline(cin, urunAdi);
                fastFood.urunAra(urunAdi);
                break;
            }
            case 5: 
			{
                fastFood.menuGoster();
                cout << endl; 
                break;
            }
            case 6:
            {
				cout << "��k�� yap�l�yor..." << endl;
                break;
            }
			default:
                cout << "Ge�ersiz se�im. L�tfen tekrar deneyin." << endl;
        }
    }while (secim!=6);

	system("pause");
    return 0;
}
