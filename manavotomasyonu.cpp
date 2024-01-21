//nisa_savaþkan_2212721015 
//manav otomasyonu 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Urun {
public:
    string ad;
    double fiyat;
    int miktar;

    Urun(const string& ad, double fiyat, int miktar) : ad(ad), fiyat(fiyat), miktar(miktar) {}
};

class ManavOtomasyonu {
private:
    vector<Urun> urunler;

public:
    void menu() {
        int secim;
        do {
            cout << "1. Urun Ekle\n"
                 << "2. Urun Ara\n"
                 << "3. Urun Duzelt/Guncelle\n"
                 << "4. Urun Sil\n"
                 << "5. Urunleri Listele\n"
                 << "6. Cikis\n"
                 << "Seciminizi yapiniz: ";
            cin >> secim;

            switch (secim) {
                case 1:
                    urunEkle();
                    break;
                case 2:
                    urunAra();
                    break;
                case 3:
                    urunDuzelt();
                    break;
                case 4:
                    urunSil();
                    break;
                case 5:
                    urunleriListele();
                    break;
                case 6:
                    cout << "Cikis yapiliyor.\n";
                    break;
                default:
                    cout << "Gecersiz secim. Tekrar deneyin.\n";
            }
        } while (secim != 6);
    }

    void urunEkle() {
        string ad;
        double fiyat;
        int miktar;

        cout << "Urun Adi: ";
        cin >> ad;
        cout << "Urun Fiyati: ";
        cin >> fiyat;
        cout << "Urun Miktar: ";
        cin >> miktar;

        urunler.push_back(Urun(ad, fiyat, miktar));

        cout << "Urun basariyla eklendi.\n";
    }

    void urunAra() {
        string arananAd;
        cout << "Aranacak Urun Adi: ";
        cin >> arananAd;

        bool bulundu = false;
        for (size_t i = 0; i < urunler.size(); ++i) {
            if (urunler[i].ad == arananAd) {
                cout << "Urun bulundu:\n";
                cout << "Ad: " << urunler[i].ad << "\n";
                cout << "Fiyat: " << urunler[i].fiyat << "\n";
                cout << "Miktar: " << urunler[i].miktar << "\n";
                bulundu = true;
                break;
            }
        }

        if (!bulundu) {
            cout << "Urun bulunamadi.\n";
        }
    }

    void urunDuzelt() {
        string duzeltilecekAd;
        cout << "Duzeltilecek Urun Adi: ";
        cin >> duzeltilecekAd;

        for (size_t i = 0; i < urunler.size(); ++i) {
            if (urunler[i].ad == duzeltilecekAd) {
                cout << "Yeni Fiyat: ";
                cin >> urunler[i].fiyat;
                cout << "Yeni Miktar: ";
                cin >> urunler[i].miktar;
                cout << "Urun basariyla duzeltildi.\n";
                return;
            }
        }

        cout << "Urun bulunamadi.\n";
    }

    void urunSil() {
        string silinecekAd;
        cout << "Silinecek Urun Adi: ";
        cin >> silinecekAd;

        for (size_t i = 0; i < urunler.size(); ++i) {
            if (urunler[i].ad == silinecekAd) {
                urunler.erase(urunler.begin() + i);
                cout << "Urun basariyla silindi.\n";
                return;
            }
        }

        cout << "Urun bulunamadi.\n";
    }

    void urunleriListele() {
        if (urunler.empty()) {
            cout << "Urun bulunmamaktadir.\n";
            return;
        }

        cout << "Urun Listesi:\n";
        for (size_t i = 0; i < urunler.size(); ++i) {
            cout << "Ad: " << urunler[i].ad << "\n";
            cout << "Fiyat: " << urunler[i].fiyat << "\n";
            cout << "Miktar: " << urunler[i].miktar << "\n";
            cout << "-----------------\n";
        }
    }
};

int main() {
    ManavOtomasyonu manav;
    manav.menu();

    return 0;
}

