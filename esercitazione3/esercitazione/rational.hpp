#pragma once
#include <concepts>
#include <ostream>
#include <numeric>
template<typename I> requires std::integral<I> 
class rational 
{ 
    I num_; 
    I den_; 
    /* Creo una funzione per la semplificazione e per trattare den_ = 0*/
    void reduce()
    {
        /* voglio il segno al numeratore */
        if (den_ < I{0}){
            num_ = -num_ ;
            den_ = -den_;
        }
        if (den_ == I{0}) {//non normalizzo
            return;
        }
        if (num_ == I{0}){
            den_ = 1;
            return;
        }
        /* passo alla semplificazione vera e propria, sfruttando il il GDC (ita: MCD)*/
        I g = std::gcd(num_, den_);
        num_ = num_ / g;
        den_ = den_ /g;
    }
/* Costruisco dei */
public:
    /* Costruttore di default che rappresenta 0/1 */
    rational()
        : num_(I{0}), den_(I{1})
    {}
    /* Costruttore user-defined*/
    /*n/0 = + inf, -n/0 = -inf se n >0 e 0/0 = NaN */
    rational(const I& n, const I& d)
        : num_(n), den_(d)
    {/*devo semplificare e gestire il caso den_ !=  0, per il caso den_ = 0 farò degli if e modificherò in stampa*/
        if (d != I{0}) {
            reduce();
        }      
    }
    I num() const {return num_;}
    I den() const {return den_; }

    /* Implementazone incremento =+ */
    rational& operator+=(const rational& other) {
        /* Devo trattare tutti i casi possibili*/
        /*NaN + qualsiasi cosa = NaN*/
        if ((num_ == I{0} && den_ == I{0}) || (other.num_ == I{0} && other.den_ == I{0})){
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* Inf + (- Inf) = NaN; Inf + Inf = Inf*/
        if ((num_ != I{0} && den_ == I{0}) && (other.num_ != I{0} && other.den_ == I{0})){
            /*Inf + (-Inf)*/
            if ((num_ > I{0} && other.num_ < I{0}) || (num_ < I{0} && other.num_ > I{0})){
                num_ = I{0};  
                return *this;  
            }
            /*se Inf + Inf o (-Inf) + (-Inf) ottengo lo stesso oggetto*/
            return *this;
        }
        /*finito & infinito = infinito, ma devo distinguere se l'inf riguarda other*/
        if (num_ != I{0} && den_ == I{0}){
            return *this; //già incluso
        }
        //ho esaurito i casi in cui den_ == I{0}, d'ora in poi sarà sempre !=
        if (other.num_ != I{0} && other.den_ == I{0}){
            num_ = other.num_;
            den_ = I{0};
            return *this;
        }
        /* caso normale
        formula: a/b + c/d = (ad + cb)/(bd)*/
        num_ = num_*other.den_ + other.num_*den_;
        den_ = den_ * other.den_;
        reduce();
        return *this;
    }
    /*implementazione della somma*/
    rational operator+(const rational& other) const{
        rational ret = *this;
        ret += other;
        return ret;
    }
    rational& operator-=(const rational& other) {
        /* sottrarre equivale a sommare -other*/
        rational minus_other(-other.num_, other.den_);
        *this += minus_other;
        return *this;
    }
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }
    rational& operator*=(const rational& other) {
        /*NaN * qualsiasi cosa = NaN*/
        if ((num_ == I{0} && den_ == I{0}) || (other.num_ == I{0} && other.den_ == I{0})){
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* 0* Inf = NaN + ho esaurito i casi in cui uno dei due fattori è NaN*/
        if ((num_ == I{0} && other.den_ == I{0}) || (den_ == I{0} && other.num_ == I{0})) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* Inf * qualsiasi cosa non nulla e non NaN(incluso Inf) = Inf, ma occorre fare attenzione al segno*/
        if (den_ == I{0} || other.den_ == I{0}) {
            //studio del segno
            bool positivo = (num_*other.num_ > I{0});
            if (positivo) {
                num_ = I{1};
                den_ = I{0}; 
                return *this;
            }
            else{
                num_ = I{-1};
                den_ = I{0};
                return *this;
            }
        }
        /* caso normale
        formula: a/b * c/d = (a*c)/(b*d)*/
        num_ = num_*other.num_;
        den_ = den_*other.den_;
        reduce();
        return *this;
    }
    /* Implementazione del prodotto */
    rational operator*(const rational& other) const{
        rational ret = *this;
        ret = ret *= other;
        return ret;
    }
    /* Implementazione della divisione /=  */
    rational& operator/=(const rational& other) {
        /* la divisione equivale alla moltiplicazione per il reciproco*/
        rational reciproco(other.den_, other.num_);
        *this *= reciproco;
        return *this;
    }
    /* Implementazione della divisione / */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret = ret /= other;
        return ret;
    }
};

/* overload di << + tratto den = 0 */
template <typename I> requires std::integral<I>
std::ostream& 
operator<<(std::ostream &os, const rational<I>& r)
{
    if (r.den() == I{0}){
        if (r.num() == I{0}){
            os << "NaN";   
        }
        if (r.num() > I{0}){
            os << "+ Inf";
        }
        if(r.num()< I{0}) {
            os << "- Inf";
        }
    }
    else if (r.den() == I{1}) {
            os << r.num(); //gestione degli interi
    }
    else if (r.num() == I{0}) {
        os << 0; //gestione dello zero
    }
    else{
        os << r.num() << "/" << r.den();
    }
    
    return os;
}