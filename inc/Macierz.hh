#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"

#include <iostream>


/*
 *  Klasa Macierz zawiera tablicę wektorow
 * oraz metody odpowiednie dla macierzy
 */
class Macierz 
{
  /*
  * tablica wektorow o rozmiarze ROZMIAR
  */
  Wektor tab[ROZMIAR];

  public:
    /*
    * inicjalizacja macierzy
    */
    Macierz();
    Wektor operator [] (int Ind) const {return tab[Ind];}
    Wektor& operator [] (int Ind) {return tab[Ind];}
    /*
    *  przeciazenie operatora mnozenia dla operacji macierz*wektor, zwracajaca wektor 
    */
    Wektor operator * (Wektor We);
    /*
    * funkcja zwracajaca wyznacznik macierzy 
    */
    double wyznacznik();
    /*
    * metoda zamieniajaca wybrana z kolumn macierzy na wpodany wektor
    */
    Macierz podstawKolumne(Wektor We, int numerKolumny);
    /*
    * metoda - transpozycja macierzy
    */
    Macierz transpozycja();
};


/*
 * Przeciazenie operatora >> by na strumien wejsciowy przekazywac strukture Macierz
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * Przeciazanie operatora, by na strumien wyjsiowy przekazywac 
 * strukture Macierz
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
