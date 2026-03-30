#include <iostream>
#include "rational.hpp"
int main(){
    /*costruzione e semplificazione*/
    std::cout <<"Costruzione e semplificazione: \n";
    rational<int> r1(3,6);
    rational<int> r2(34, 4);
    rational<int> r3(256, -64);
    rational<int> r4(0,0);
    rational<int> r5(6, 0);
    rational<int> r6(-6,0);
    rational<int> r7;
    std::cout << "3/6 = "<< r1 << "\n";
    std::cout << "34/4 = " << r2 << "\n";
    std::cout << "256/-64 = " << r3 << "\n";
    std::cout << "0/0 = " << r4 << "\n";
    std::cout <<"6/0 = " << r5 << "\n";
    std::cout << "-6/0 = " << r6 << "\n";
    std::cout <<"default = "<< r7 << "\n";
    /*addizione*/
    std::cout << "Addizione\n";
    rational<int> a(3,9);
    rational<int> b(1,2);
    std::cout << "3/9 + 1/2 = " << (a + b) << "\n";
    std::cout << "1/2 + NaN = " << (b + r4) << "\n";
    std::cout << "1/2 + Inf = " << (b + r5) <<"\n";
    std::cout << "1/2 + (-Inf) = " << (b + r6) <<"\n";
    std::cout << "Inf + (-Inf) = " << (r5 + r6) <<"\n";
    std::cout << "Inf + NaN = " << (r5 + r4) <<"\n"; 
    /*sottrazione*/
    std::cout << "Sottrazione \n";
    std::cout << "3/9 - 1/2 = " << (a - b) << "\n";
    std::cout << "1/2 - NaN = " << (b - r4) << "\n";
    std::cout << "1/2 - Inf = " << (b - r5) <<"\n";
    std::cout << "1/2 - (-Inf) = " << (b - r6) <<"\n";
    std::cout << "Inf - (-Inf) = " << (r5 - r6) <<"\n";
    std::cout << "Inf - NaN = " << (r5 - r4) <<"\n"; 
    /*moltiplicazione*/
    rational<int> c(-3, 9);
    rational<int> d(1, -2);
    std::cout <<"Moltiplicazione \n";
    std::cout << "3/9 * 1/2 = " << (a * b) << "\n";
    std::cout << "(-3/9) * 1/2 = " << (c * b) << "\n";
    std::cout << "(-3/9) * (-1/2) = " << (c * d) << "\n";
    std::cout << "Inf * (-3/9) = " << (c * r5) <<"\n";
    std::cout << "1/2 * NaN = " << (b * r4) << "\n";
    std::cout << "1/2 * Inf = " << (b * r5) <<"\n";
    std::cout << "1/2 * (-Inf) = " << (b * r6) <<"\n";
    std::cout << "Inf * (-Inf) = " << (r5 * r6) <<"\n";
    std::cout << "Inf * NaN = " << (r5 * r4) <<"\n"; 
    /*divisione*/
    std::cout <<"Divisione \n";
    std::cout << "3/9 / 1/2 = " << (a / b) << "\n";
    std::cout << "(-3/9) / 1/2 = " << (c / b) << "\n";
    std::cout << "(-3/9) / (-1/2) = " << (c / d) << "\n";
    std::cout << "Inf / (-3/9) = " << (c / r5) <<"\n";
    std::cout << "1/2 / NaN = " << (b / r4) << "\n";
    std::cout << "1/2 / Inf = " << (b / r5) <<"\n";
    std::cout << "1/2 / (-Inf) = " << (b / r6) <<"\n";
    std::cout << "Inf / (-Inf) = " << (r5 / r6) <<"\n";
    std::cout << "Inf / NaN = " << (r5 / r4) <<"\n"; 


    return 0;
}