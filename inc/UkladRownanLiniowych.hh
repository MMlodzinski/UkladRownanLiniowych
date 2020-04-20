#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "rozmiar.h"
#include "Macierz.hh"


/*
 *  Klasa Uklad Rownan Liniowych:
 *  zawiera tabele 4x3 zawierajaca macierz rownania i wektor wyrazow wolnych, 
 *  osobno Macierz Rownania, Wektor Wyrazow Wolnych, Wektor Rownania - zawierajacy rozwiazania, 
 *  Wektor Blad - zawierajacy blad rozwiazania; 
 *  
 */
class UkladRownanLiniowych 
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Macierz MacierzRownania;
  Wektor WektorWyrazowWolnych;


  public:

/*
* funkcja przypisuje wartosci z tabeli do macierzy rownania i wektora wyrazow wolnych 
*/

/*
* metoda uzyskująca Macierz Rownania
*/
    Macierz &DajMacierzRownania();
    Macierz WezMacierzRownania()const;


/*
*   Wektor Wyrazow Wolnych
*/
    Wektor &DajWektorWyrazowWolnych();
    Wektor WezWektorWyrazowWolnych()const;

/*
 *  funkcja inicjalizuje uklad rownan 
 */
    UkladRownanLiniowych();

/*
* funkcja rozwiazuje uklad rownan metoda Cramera, zwraca wektor z rozwiazaniem
*/
    Wektor rozwiazUklad();
/*
* funkcja obliczajaca wektor bledu rozwiazania
*/
    Wektor bladRozwiazania(UkladRownanLiniowych UklRown);
 
};


/*
* przeciazenie operatora wejscia dla ukladu rownan - dane przyjmowane sa do tabeli 4x3 zawierajaca macierz i wektor wyrazow wolnych
*/
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
* przeciazenie operatora wyjscia dla ukladu rownan, oddaje on na strumien wyjsciowy tabele 4x3, macierz oraz wektor wyrazow wolnych
*/
std::ostream& operator << ( std::ostream &Strm,const UkladRownanLiniowych &UklRow);


#endif
