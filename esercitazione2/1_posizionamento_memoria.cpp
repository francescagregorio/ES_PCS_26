#include <iostream>

int main() 
{ 
    double ad[4] = {0.0, 1.1, 2.2, 3.3}; 
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; 
    int ai[3] = {0, 1, 2}; 
    //due variabili scalari
    int x = 1; 
    float y = 1.1; 
    //tratto y come array
    (&y)[1] = 0;

     std::cout << x << "\n"; 

     //stampo le dimensioni dei tipi utilizzati
     std::cout <<"Size of double: " << sizeof(double) << " bytes \n";
     std::cout << "Size of int: " << sizeof(int) << " bytes \n";
     std::cout << "Size of float: " << sizeof(float) << " bytes \n";

     //provo a vedere cosa è successo a y
     std::cout << y << "\n";
     //y sembra sempre essere uno scalare

     //provo a stampare alcuni indirizzi degli elementi degli array
     std::cout << &ad[0] << "\n";
     std::cout <<&af[0] << "\n";
     std::cout << &ai[0] <<"\n";
     //stampo l'indirizzo di x in memoria
     std::cout << &x << "\n";
     //stampo l'indirizzo di y in memoria 
     std::cout << &y << "\n";
 
     return 0; 
}