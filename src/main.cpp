#include <iostream>
#include "rozmiar.h"
#include "SWektor.hh"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  SUkladRownanLiniowych<SMacierz<SWektor<double, ROZMIAR>, ROZMIAR>, SWektor<double, ROZMIAR>, ROZMIAR>   UklRown;  
  SWektor<double, ROZMIAR> nowy;
  SMacierz<SWektor<double, ROZMIAR>, ROZMIAR> nowa;
  


    
if(!cin.ios::eof()){
  cin >> UklRown;
  cout << endl << " Start programu " << endl << endl;
  cout << " Macierz A^T :" << endl;
  cout << UklRown.WezMacierzRownania() << endl;
  cout << " Wektor wyrazow wolnych b :" << endl;
  cout << UklRown.WezWektorWyrazowWolnych() << endl;
  cout << " Rozwiazanie x = (x1, x2, x3) :" << endl;
  cout << UklRown.rozwiazUklad() << endl;
  
  cout << "\t Wektor bledu Ax-b = " <<   UklRown.bladRozwiazania(UklRown);
  cout << " Dlugosc wektora bledu |Ax-b| = " << UklRown.bladRozwiazania(UklRown).dlugosc() << endl;
}
/*
 cout << endl
       << " --------- Test klasy Wektor ----------" << endl
       << endl;
  
  SWektor<double,3>    W, W_wynik;
  SMacierz<SWektor<double,3>,3> M;
  
  

    for (unsigned int Ind = 0; Ind < 3; ++Ind) {
    for (unsigned int Ind = 0; Ind < 3; ++Ind) {
    W[Ind] = Ind;
  }
    M[Ind] = W;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << M << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
 */


}
 

  

  



