#include <iostream>
#include <algorithm>
#include <cmath>
int main()
{
    static const int N = 10;
    double ad[N] = {121.0, 1.1, 2.2, 3.3, 4.4, 121.0, 6.6, 7.7, 8.8, 9.9};
    
    //calcolo massimo e minimo
    double max_val = ad[0];
    double min_val = ad[0];
    for (int c=1; c < N; c++){
        max_val = std::max(max_val, ad[c]);
        min_val = std::min(min_val, ad[c]);
    }
    std:: cout <<"The minimum value is " << min_val << "\n";
    std:: cout <<"The maximum value is " << max_val << "\n";

    //calcolo della media
    double sum = 0.0;
    for (int i = 0; i < N; i++){
        sum = sum + ad[i];
    }
    double avr = sum/N;
    std::cout << "The average is " << avr << "\n";

    //calcolo deviazione standard
    double ssum = 0.0;
    for (int r = 0; r < N; r++) {
        ssum = ssum + (ad[r] - avr)*(ad[r]-avr);
    }
    double sigma_2= ssum/N;
    double sigma = std::sqrt(sigma_2);
    std::cout << "The standard deviation is " << sigma << "\n";
    return 0;
}