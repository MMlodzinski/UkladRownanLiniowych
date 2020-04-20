#include "Wektor.hh"
#include <cmath>



std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    Strm.clear();
    for(int i=0;i<ROZMIAR;i++){
        if(!(Strm >> Wek[i])) Strm.setstate(std::ios::failbit);
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    for(int i=0;i<ROZMIAR;i++){
        std::cout << Wek[i] << " ";
    }
    std::cout<<std::endl;
    return Strm;
}

Wektor::Wektor( )
{
for (int Ind = 0; Ind < ROZMIAR; ++Ind) tab[Ind] = 0;
}

Wektor Wektor::operator + (Wektor We1){
    
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=We1[i]+tab[i];
    }
    return *this;
}
Wektor Wektor::operator - (Wektor We1){
    
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=tab[i]-We1[i];
    }
    return *this;
}
Wektor Wektor::operator * (Wektor We1){
    
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=We1[i]*tab[i];
    }
    return *this;
}
Wektor Wektor::operator * (TYP liczba){
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=tab[i]*liczba;
    }   
    return *this;
}
Wektor Wektor::operator / (TYP liczba){
    for(int i=0;i<ROZMIAR;i++){
        tab[i]=tab[i]/liczba;
    }
    return *this;
}
double Wektor::dlugosc(){
    double dlugosc=0;
    for(int i=0;i<ROZMIAR;i++){
        dlugosc += pow(tab[i], 2);
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}
