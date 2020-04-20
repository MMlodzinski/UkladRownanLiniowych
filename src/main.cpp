#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;  
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
  

 


}
 

  

  

return 0;
}
