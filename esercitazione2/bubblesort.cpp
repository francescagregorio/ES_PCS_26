#include <iostream>
int main(){
    static const int N = 10;
    double ad[N] = {121.0, 1.1, 2.2, 3.3, 4.4, 121.0, 6.6, 7.7, 8.8, 9.9};
    //stampa array iniziale
    std::cout <<"ad: ";
    for (int r = 0; r < N; r++){
        std::cout << ad[r] << " ";
    }
    std::cout << "\n";
    bool changes = true; //inizializzo una variabile booleana che assume valore true se sono stati effettuati scambi al passo precedente 
    while (changes){
        changes = false;
        for (int i = 0; i<N-1; i++){ //scorro lungo il vettore
            if (ad[i] > ad[i+1]){
                double a = ad[i];
                ad[i] = ad[i+1];
                ad[i+1] = a;
                changes = true;
            }

        }
    }
    std::cout << "Sorted ad: ";
    for (int c = 0; c < N; c++){
        std::cout << ad[c] << " ";
    }
    std::cout << "\n";



    return 0;}
    