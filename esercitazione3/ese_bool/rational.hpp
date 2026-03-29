#pragma once
#include <concepts>
#include <numeric>
#include <ostream>

template<typename I> requires std::integral<I>
class rational{
    I num_;
    I den_;
    void reduce(){
        /* voglio il segno al numeratore */
        if (den_ < I{0}){
            num_ = -I{1}*num_ ;
            den_ = -I{1} * den_;
        }
        if (den_ == I{0}) {//non normalizzo
            return;
        }
        if (num_ == I{0}){
            den_ = 1;
            return;
        }
        /* passo alla semplificazione vera e propria, sfruttando il il GDC (ita: MCD)*/
        I g = std::gcd(num_, den_); //funzione trovata su C++reference
        num_ = num_ / g;
        den_ = den_ /g;
    }
    bool is_nan() const { //il const dopo le parentesi indica che il metodo non modifica l'oggetto su cui è chiamato
        if (num_ == I{0} && den_== I{0}){
            return true;
            }
        return false;
    }
    bool is_pinf() const{
        if(num_>I{0} && den_ == I{0}){
            return true;
        }
        return false;
    }
    bool is_minf() const{
        if (num_<I{0} && den_ == I{0}){
            return true;
        }
        return false;
    }
    bool is_fin() const{
        if( den_ != I{0}){
            return true;
        }
        return false;
    }
    public:
        /* Costruttore di default che rappresenta 0/1 */
        rational()
            : num_(I{0}), den_(I{1})
        {}
    /* Costruttore user-defined*/
    /*n/0 = + inf, -n/0 = -inf se n >0 e 0/0 = NaN */
        rational(const I& n, const I& d)
            : num_(n), den_(d)
        {/*devo semplificare e gestire il caso den_ !=  0, per il caso den_ = 0 farò degli if e modificherò in stampa; avrei anche potuto gestire gli if con dei bool*/
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
        /*in alternativa, avrei potuto costruire delle variabili booleane del tipo
        bool isnan*/
        if (is_nan() || other.is_nan()){
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* Inf + (- Inf) = NaN; Inf + Inf = Inf*/
        if ((is_pinf() || is_minf()) && (other.is_pinf() || other.is_minf())){
            /*Inf + (-Inf)*/
            if ((is_pinf()&& other.is_minf()) || (is_minf() && other.is_pinf())){
                num_ = I{0};  
                return *this;  
            }
            /*se Inf + Inf o (-Inf) + (-Inf) ottengo lo stesso oggetto*/
            return *this;
        }
        /*finito & infinito = infinito, ma devo distinguere se l'inf riguarda other*/
        if (is_pinf() || is_minf()){
            return *this; //già incluso
        }
        //ho esaurito i casi in cui den_ == I{0}, d'ora in poi sarà sempre !=
        if (other.is_pinf() || other.is_minf()){
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
        if (is_nan() || other.is_nan()){
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* 0* Inf = NaN + ho esaurito i casi in cui uno dei due fattori è NaN*/
        if ((num_ == I{0} && (other.is_pinf() || other.is_minf())) || ((is_pinf()|| is_minf())&& other.num_ == I{0})) {
            num_ = I{0};
            den_ = I{0};
            return *this;
        }
        /* Inf * qualsiasi cosa non nulla e non NaN(incluso Inf) = Inf, ma occorre fare attenzione al segno*/
        if ((is_pinf()||is_minf())|| (other.is_pinf()||other.is_minf())) {
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
operator<<(std::ostream &os, const rational<I>& r){
    bool nan (r.num() == I{0} && r.den()== I{0});
    bool pinf (r.num()>I{0} && r.den() == I{0});
    bool minf (r.num()<I{0} && r.den()==I{0});
    bool nint (r.den()==I{1});
    if (nan){
        os <<"NaN";
    }
    else if (pinf){
        os << "+Inf";
    }
    else if (minf){
        os << "-Inf";
    }
    else if (nint){
        os << r.num();
    }
    else{
        os << r.num()<<"/"<<r.den();
    }
    return os;
}