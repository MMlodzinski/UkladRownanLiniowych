#include <iostream>
#include <string.h>
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


int main(int argc, char *argv[])
{
  if(strcmp(argv[1],"r")){
    SUkladRownanLiniowych<double, ROZMIAR>   UklRown;  
    SWektor<double, ROZMIAR> nowy;
    SMacierz<double, ROZMIAR> nowa;
    if(!cin.ios::eof()){
      cin >> UklRown;
      cout << endl << " Start programu " << endl << endl;
      cout << " Macierz A^T :" << endl;
      cout << UklRown.WezMacierzRownania() << endl;
      cout << " Wektor wyrazow wolnych b :" << endl;
      cout << UklRown.WezWektorWyrazowWolnych() << endl;
      cout << " Rozwiazanie x = (x1, x2, x3, x4, x5) :" << endl;
      cout << UklRown.rozwiazUklad() << endl;
  
      cout << "\t Wektor bledu Ax-b = " <<   UklRown.bladRozwiazania(UklRown);
      cout << " Dlugosc wektora bledu |Ax-b| = " << UklRown.bladRozwiazania(UklRown).dlugosc() << endl;
    }
  }
  else if(strcmp(argv[1],"z")){
    SUkladRownanLiniowych<double, ROZMIAR>   UklRown;  
    SWektor<double, ROZMIAR> nowy;
    SMacierz<double, ROZMIAR> nowa;
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
  }
  else{return 0;}

 
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
 

  

  



