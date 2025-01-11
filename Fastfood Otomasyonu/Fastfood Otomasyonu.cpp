#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

//Eylül Gizem Elidar-Fastfood Ootomasyonu

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
            cout << "Menü dolu, ürün eklenemdi." << endl;
            cout << endl; 
            return;
        }
        
        urunler[mevcutElemanSayisi].urunNo=siradakiNo++;
        urunler[mevcutElemanSayisi].urunAdi=urunAdi;
        urunler[mevcutElemanSayisi].fiyat=fiyat;
        mevcutElemanSayisi++;
        cout << "Ürün eklendi: [" << urunler[mevcutElemanSayisi-1].urunNo << "] " << urunler[mevcutElemanSayisi-1].urunAdi << " => " << urunler[mevcutElemanSayisi-1].fiyat << "TL" << endl;
        cout << endl; 
    }
 
    void urunSil(int urunNo) 
	{
        int index=noyaGoreUrunBul(urunNo);
        if(index!=-1) 
		{
            cout << "Ürün silindi: [" << urunler[index].urunNo << "] " << urunler[index].urunAdi << "\n";
            cout << endl; 
            for(int i=index; i<mevcutElemanSayisi-1; ++i) 
			{
                urunler[i]=urunler[i+1];
            }
            mevcutElemanSayisi--;
        }
		
		else 
		{
            cout << urunNo << " ürün numarasý ile eþleþen ürün bulunamadý." << endl;
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
            cout << "Ürün güncellendi: [" << urunler[index].urunNo << "] " << urunler[index].urunAdi << " (" << urunler[index].fiyat << " TL)\n";
            cout << endl; 
        } 
		
		else 
		{
            cout << "\"" << urunNo << "\" ürün numarasý ile eþleþen ürün bulunamadý." << endl;
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
                cout << "Bulunan ürün: [" << urunler[i].urunNo << "] " << urunler[i].urunAdi << " (" << urunler[i].fiyat << " TL)\n";
                cout << endl; 
                bulundu=true;
            }
        }
        
        if(!bulundu) 
		{
            cout << "\"" << urunAdi << "\" adýna sahip bir ürün bulunamadý." << endl;
            cout << endl; 
        }
    }

    void menuGoster() const 
	{
        if(mevcutElemanSayisi==0) 
		{
            cout << "Menüde ürün yok." << endl;
            cout << endl; 
            return;
        }

        cout << "\nMevcut Menü:" << endl;
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
        cout << "1- Ürün Ekle" << endl;
        cout << "2- Ürün Sil" << endl;
        cout << "3- Ürün Güncelle" << endl;
        cout << "4- Ürün Ara" << endl;
        cout << "5- Menüyü Göster" << endl;
        cout << "6- Çýkýþ Yap" << endl;
        cout << endl; 
        cout << "Ýþlem seçimi yapýnýz: " << endl;
        cin >> secim;

        switch(secim) 
		{
            case 1: 
			{
                string urunAdi;
                double fiyat;
                cout << "Ürün adýný girin: " << endl;
                cin.ignore();
                getline(cin, urunAdi);
                cout << "Ürün fiyatýný girin: " << endl;
                cin >> fiyat;
                fastFood.urunEkle(urunAdi, fiyat);
                break;
            }
            case 2: 
			{
                int urunNo;
                cout << "Silinecek ürünün numarasýný girin: " << endl;
                cin >> urunNo;
                fastFood.urunSil(urunNo);
                break;
            }
            case 3: 
			{
                int urunNo;
                string urunAdi;
                double fiyat;
                cout << "Güncellenecek ürünün numarasýný girin: " << endl;
                cin >> urunNo;
                cout << "Yeni ürün adýný girin: " << endl;
                cin.ignore();
                getline(cin, urunAdi);
                cout << "Yeni ürün fiyatýný girin: " << endl;
                cin >> fiyat;
                fastFood.urunGuncelle(urunNo, urunAdi, fiyat);
                break;
            }
            case 4: 
			{
                string urunAdi;
                cout << "Aranacak ürün adýný girin: " << endl;
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
				cout << "Çýkýþ yapýlýyor..." << endl;
                break;
            }
			default:
                cout << "Geçersiz seçim. Lütfen tekrar deneyin." << endl;
        }
    }while (secim!=6);

	system("pause");
    return 0;
}
