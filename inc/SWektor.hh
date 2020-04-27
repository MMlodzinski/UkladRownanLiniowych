#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor();
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &we);
    SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &we);
    SWektor<STyp,SWymiar> operator / (STyp liczba);
};




template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W);

#endif
