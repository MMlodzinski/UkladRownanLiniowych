#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"

template <typename STyp, int SWymiar>
class SUkladRownanLiniowych 
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  SMacierz<STyp,SWymiar> MacierzRownania;
  SWektor<STyp,SWymiar> WektorWyrazowWolnych;


  public:

/*
* funkcja przypisuje wartosci z tabeli do macierzy rownania i wektora wyrazow wolnych 
*/

/*
* metoda uzyskująca Macierz Rownania
*/
    SMacierz<STyp,SWymiar> &DajMacierzRownania(){return MacierzRownania;}
    SMacierz<STyp,SWymiar> WezMacierzRownania()const{return MacierzRownania;}


/*
*   Wektor Wyrazow Wolnych
*/
    SWektor<STyp,SWymiar> &DajWektorWyrazowWolnych(){return WektorWyrazowWolnych;}
    SWektor<STyp,SWymiar> WezWektorWyrazowWolnych()const{return WektorWyrazowWolnych;}

/*
 *  funkcja inicjalizuje uklad rownan 
 */
    SUkladRownanLiniowych();

/*
* funkcja rozwiazuje uklad rownan metoda Cramera, zwraca wektor z rozwiazaniem
*/
    SWektor<STyp,SWymiar> rozwiazUklad();
/*
* funkcja obliczajaca wektor bledu rozwiazania
*/
    SWektor<STyp,SWymiar> bladRozwiazania(SUkladRownanLiniowych UklRown);
};

template <typename STyp, int SWymiar>
SUkladRownanLiniowych<STyp, SWymiar>::SUkladRownanLiniowych(){

    for(int i=0;i<SWymiar;i++){
        for(int j=0; j<SWymiar; j++){
            MacierzRownania[i][j]=0;
        }
        WektorWyrazowWolnych[i]=0;
    }
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::rozwiazUklad(){
   
   SWektor<STyp,SWymiar> WektorRownania;
   SMacierz<STyp,SWymiar> A,B;
   for(int i=0;i<SWymiar; i++){
       A[i]=MacierzRownania[i];
   }
   for (int i=0; i<SWymiar; i++){
       B=A;
       B.podstawKolumne(WektorWyrazowWolnych, i);
       WektorRownania[i]=B.wyznacznik()/A.wyznacznik();
   }
    return WektorRownania;

}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::bladRozwiazania(SUkladRownanLiniowych<STyp, SWymiar> UklRown){
        SWektor<STyp,SWymiar> Blad = MacierzRownania*UklRown.rozwiazUklad()-WektorWyrazowWolnych;
        return Blad;

}

/*
* przeciazenie operatora wejscia dla ukladu rownan - dane przyjmowane sa do tabeli 4x3 zawierajaca macierz i wektor wyrazow wolnych
*/
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STyp, SWymiar> &UklRown){
        for (int i=0; i<SWymiar+1; i++){
            if(!(Strm >> UklRown.DajMacierzRownania() >> UklRown.DajWektorWyrazowWolnych())) Strm.setstate(std::ios::failbit);
        }
        

    return Strm;
}

/*
* przeciazenie operatora wyjscia dla ukladu rownan, oddaje on na strumien wyjsciowy tabele 4x3, macierz oraz wektor wyrazow wolnych
*/
template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &Strm,const SUkladRownanLiniowych<STyp, SWymiar> &UklRow){
    for (int i=0; i<SWymiar+1; i++){
        Strm << UklRow.WezMacierzRownania() << UklRow.WezWektorWyrazowWolnych();
    }
    return Strm;
}

#endif