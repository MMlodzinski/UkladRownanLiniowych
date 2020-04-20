#include "UkladRownanLiniowych.hh"

Wektor &UkladRownanLiniowych::DajWektorWyrazowWolnych(){
    return WektorWyrazowWolnych;
}
Macierz &UkladRownanLiniowych::DajMacierzRownania(){
    return MacierzRownania;
}
Macierz UkladRownanLiniowych::WezMacierzRownania() const {
    return MacierzRownania;
}
Wektor UkladRownanLiniowych::WezWektorWyrazowWolnych() const {
    return WektorWyrazowWolnych;
}
UkladRownanLiniowych::UkladRownanLiniowych(){

    for(int i=0;i<ROZMIAR;i++){
        for(int j=0; j<ROZMIAR; j++){
            MacierzRownania[i][j]=0;
        }
        WektorWyrazowWolnych[i]=0;
    }
}



Wektor UkladRownanLiniowych::rozwiazUklad(){
   
   Wektor WektorRownania;
   Macierz A,B;
   for(int i=0;i<ROZMIAR; i++){
       A[i]=MacierzRownania[i];
   }
   for (int i=0; i<ROZMIAR; i++){
       B=A;
       B.podstawKolumne(WektorWyrazowWolnych, i);
       WektorRownania[i]=B.wyznacznik()/A.wyznacznik();
   }
    return WektorRownania;

}

Wektor UkladRownanLiniowych::bladRozwiazania(UkladRownanLiniowych UklRown){
        Wektor Blad = MacierzRownania*UklRown.rozwiazUklad()-WektorWyrazowWolnych;
        return Blad;

}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
        for (int i=0; i<ROZMIAR+1; i++){
            if(!(Strm >> UklRown.DajMacierzRownania() >> UklRown.DajWektorWyrazowWolnych())) Strm.setstate(std::ios::failbit);
        }
        

    return Strm;
}

std::ostream& operator << ( std::ostream &Strm,const UkladRownanLiniowych &UklRow){
    for (int i=0; i<ROZMIAR+1; i++){
        Strm << UklRow.WezMacierzRownania() << UklRow.WezWektorWyrazowWolnych();
    }
    return Strm;
}