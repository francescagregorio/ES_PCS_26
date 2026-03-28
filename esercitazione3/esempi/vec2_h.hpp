#pragma once
template<typename T> 
class vec2{
    T x_;
    T y_;
    public:
    /*Costruttoredidefault*/
    vec2() 
    :x_(T{0.0}), y_(T{0.0})
    {} 
    /*Costruttoreuser-defined */
    vec2(const T& px,const T& py) 
    :x_(px),y_(py)
    {} 
    /*Restituisconoivaloridixey*/
    T x() const{ return x_; }
    T y() const{ return y_; }
    /*Implementazionecanonica dell'incremento*/
    vec2& operator +=(const vec2& other){ 
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    } 
    /*Implementazionecanonica dellasomma*/
    vec2 operator+(const vec2& other)const{ 
        vec2 ret=*this;
        ret += other;
        return ret;
    } 
    /*Implementazionecanonica di*=conunoscalare*/
    vec2& operator*=(const T& s){
         x_ *=s;
         y_ *=s; 
         return *this;
    }   
    /*Implementazionecanonica delprodottovettoreperscalare*/ 
    vec2 operator*(const T& s) const{
        vec2 ret= *this;
        ret *= s;
        return ret;
    } 
};
template<typename T> 
std::ostream& 
operator<<(std::ostream& os, const vec2<T>& v) 
{ 
    os << "(" << v.x() << "," << v.y() << ")"; 
    return os; 
}