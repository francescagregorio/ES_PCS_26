#include <iostream>
#include "vec2_h.hpp"
int main(void)
{
    vec2<double> a(1.0,2.0);
    vec2<double> b(2.0,3.0); 
    vec2<double> c=a+b; 
    std::cout << c << "\n";
    return 0;
}