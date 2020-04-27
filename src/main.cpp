#include <iostream>
#include "rozmiar.h"
#include "SWektor.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
/*  UkladRownanLiniowych   UklRown;  
  Wektor nowy;
  Macierz nowa;
  


    
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
  */

 cout << endl
       << " --------- Test klasy Wektor ----------" << endl
       << endl;
  
  SWektor<double,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;
 


}
 

  

  



