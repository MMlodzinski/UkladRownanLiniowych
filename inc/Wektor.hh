#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Wektor - tablica ROZMIAR-elementowa.
 */
class Wektor {
    /*
    * tablica typu TYP o rozmiarze ROZMIAR
    */
    TYP tab[ROZMIAR];

  public:
    /*
    * inicjalizacja wektora
    */
    Wektor();
    TYP operator [] (int Ind) const {return tab[Ind];}
    TYP& operator [] (int Ind) {return tab[Ind];}
    /*
    * funkcja zwracajaca dlugosc wektora
    */
    double dlugosc();
    /*
    * Przeciazenie operatora dodawania dla wektorow.
    */
    Wektor operator + (Wektor We);

    /*
    * Przeciazenie operatora odejmowania dla wektorow. 
    */
    Wektor operator - (Wektor We);
    /*
     * Przeciazenie operatora mnozenia dla wektorow ( iloczyn skalarny).
     */
    Wektor operator * (Wektor We);
    /*
    * Przeciazenie operatora mnozenia dla iloczynu wektor * liczba.
     */
    Wektor operator * (TYP liczba);
    /*
     * Przeciazenie operatora dzielenia dla ilorazu wektor/liczba.
    */
    Wektor operator / (TYP liczba);

};


/*
 * To przeciazenie sluzy do pobierania wektorow ze strumienia wejsciowego.
 * Bedzie akceptowalo dane typu TYP, inaczej bedzie ustalalo stan
 * Strm -> failbit. 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie sluzy do wysylania wektora na strumien wyjsciowy.
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);





#endif
