#include "Macierz.hh"


Macierz::Macierz(){
    for (int i=0; i<ROZMIAR; i++){
        tab[i]=Wektor();
    }
}

Wektor Macierz::operator*(Wektor We){
    Wektor wynik;
    for(int i=0; i<ROZMIAR; i++){
        for(int j=0; j<ROZMIAR; j++){
            wynik[i]=tab[j][i]*We[j]+wynik[i];
        }
    }
    return wynik;
}
std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{   Strm.clear();
    for(int i=0;i<ROZMIAR;i++){
        if(!(Strm >> Mac[i])) Strm.setstate(std::ios::failbit);
    }
    return Strm;
}
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for (int i=0;i<ROZMIAR;i++){
        std::cout << Mac[i] << std::endl;
    }
    return Strm;
}

double Macierz::wyznacznik(){
     double det;
     Macierz Ma;
     for(int i=0; i<ROZMIAR; i++){
         for(int j=0; j<ROZMIAR; j++){
             Ma[i][j]=tab[i][j];
         }
     }
  for(int i=0;i<ROZMIAR-1;i++)

    for(int j=i+1;j<ROZMIAR;j++)

      for(int k=i+1;k<ROZMIAR;k++)

        Ma[j][k]-= Ma[j][i] / Ma[i][i] * Ma[i][k];



  det=1;

    for(int i=0;i<ROZMIAR;i++) det *= Ma[i][i];

    return det;
}
Macierz Macierz::podstawKolumne(Wektor We, int numerKolumny){
    for (int i=0; i<ROZMIAR; i++){
        tab[numerKolumny][i]=We[i];
    }
    return *this;
}
Macierz Macierz::transpozycja(){
    TYP temp;
    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<i;j++){
            temp=tab[i][j];
            tab[i][j]=tab[j][i];
            tab[j][i]=temp;
        }
    }
    return *this;
}
