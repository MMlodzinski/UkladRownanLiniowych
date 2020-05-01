#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"

template <typename STyp, typename STyp2, int SWymiar>
class SUkladRownanLiniowych 
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  STyp MacierzRownania;
  STyp2 WektorWyrazowWolnych;


  public:

/*
* funkcja przypisuje wartosci z tabeli do macierzy rownania i wektora wyrazow wolnych 
*/

/*
* metoda uzyskująca Macierz Rownania
*/
    STyp &DajMacierzRownania(){return MacierzRownania;}
    STyp WezMacierzRownania()const{return MacierzRownania;}


/*
*   Wektor Wyrazow Wolnych
*/
    STyp2 &DajWektorWyrazowWolnych(){return WektorWyrazowWolnych;}
    STyp2 WezWektorWyrazowWolnych()const{return WektorWyrazowWolnych;}

/*
 *  funkcja inicjalizuje uklad rownan 
 */
    SUkladRownanLiniowych();

/*
* funkcja rozwiazuje uklad rownan metoda Cramera, zwraca wektor z rozwiazaniem
*/
    STyp2 rozwiazUklad();
/*
* funkcja obliczajaca wektor bledu rozwiazania
*/
    STyp2 bladRozwiazania(SUkladRownanLiniowych UklRown);
 std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STyp, STyp2, SWymiar> &UklRown);
};

template <typename STyp, typename STyp2, int SWymiar>
SUkladRownanLiniowych<STyp, STyp2, SWymiar>::SUkladRownanLiniowych(){

    for(int i=0;i<SWymiar;i++){
        for(int j=0; j<SWymiar; j++){
            MacierzRownania[i][j]=0;
        }
        WektorWyrazowWolnych[i]=0;
    }
}

template <typename STyp, typename STyp2, int SWymiar>
STyp2 SUkladRownanLiniowych<STyp, STyp2, SWymiar>::rozwiazUklad(){
   
   STyp2 WektorRownania;
   STyp A,B;
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

template <typename STyp, typename STyp2, int SWymiar>
STyp2 SUkladRownanLiniowych<STyp, STyp2, SWymiar>::bladRozwiazania(SUkladRownanLiniowych<STyp, STyp2, SWymiar> UklRown){
        STyp2 Blad = MacierzRownania*UklRown.rozwiazUklad()-WektorWyrazowWolnych;
        return Blad;

}

/*
* przeciazenie operatora wejscia dla ukladu rownan - dane przyjmowane sa do tabeli 4x3 zawierajaca macierz i wektor wyrazow wolnych
*/
template <typename STyp, typename STyp2, int SWymiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STyp, STyp2, SWymiar> &UklRown){
        for (int i=0; i<SWymiar+1; i++){
            if(!(Strm >> UklRown.DajMacierzRownania() >> UklRown.DajWektorWyrazowWolnych())) Strm.setstate(std::ios::failbit);
        }
        

    return Strm;
}

/*
* przeciazenie operatora wyjscia dla ukladu rownan, oddaje on na strumien wyjsciowy tabele 4x3, macierz oraz wektor wyrazow wolnych
*/
template <typename STyp, typename STyp2, int SWymiar>
std::ostream& operator << ( std::ostream &Strm,const SUkladRownanLiniowych<STyp, STyp2, SWymiar> &UklRow){
    for (int i=0; i<SWymiar+1; i++){
        Strm << UklRow.WezMacierzRownania() << UklRow.WezWektorWyrazowWolnych();
    }
    return Strm;
}

#endif