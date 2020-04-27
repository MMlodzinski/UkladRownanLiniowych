#include "SWektor.hh"
#include "rozmiar.h"
#include <cmath>


template <typename STyp, int SWymiar>
 SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &we)
{
    SWektor<STyp,SWymiar> Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + we[Ind];
  return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &we)
{
    SWektor<STyp,SWymiar> Wynik;

    for(unsigned int Ind = 0;Ind<ROZMIAR;Ind++){
        Wynik[Ind]=we[Ind]*Wynik[Ind];
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator / (STyp liczba)
{
    SWektor<STyp,SWymiar> Wynik;

    for(int Ind=0;Ind<ROZMIAR;Ind++){
        Wynik[Ind]=Wynik[Ind]/liczba;
    }
    return Wynik;
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

template class SWektor<double,ROZMIAR>;
