#include <iostream>
#include <vector>
#include "sorts.h"
#include "randfiller.h"
#include <string>

int main(){
	randfiller rf(42);
	std::vector<double> v(1873);
    rf.fill(v, -10000.0, 10000.0);

    merge_sort(v, 0, (int)v.size()-1);

    if (!is_sorted(v)){
        std::cerr << "Vettore di dimensione fissa: ERRORE\n";
        return 1;
    }
    std::cout << "Vettore di dimensione fissa: OK\n";
    //vettore di dimensione casuale
    std::vector<double> vec;
    std::vector<int> dim(100);
    rf.fill(dim, 0, 5000);
    for (int t = 0; t < 100; t++){
        std::cerr << "t=" << t << " dim=" << dim[t] << "\n";
        vec.resize(dim[t]);
        rf.fill(vec, -10000.0, 10000.0);
        if (!vec.empty())
            merge_sort(vec, 0, (int)vec.size()-1);
        if (!is_sorted(vec)){
            std::cerr << "Randifiller: ERRORE a t=" << t << " dim=" << dim[t] << "\n";
            return 1;
        }
    }
    std::cout << "Randfiller: OK\n";
    //vettore di stringhe
    std::vector<std::string> pianeti = {"mercurio", "venere", "terra", "marte", "giove", "saturno", "urano", "netturno"};
    merge_sort(pianeti, 0, (int)pianeti.size()-1);
    if (!is_sorted(pianeti)){
        std::cerr <<"Stringhe: ERRORE\n";
        return 1;
    }
    std::cout<< "Stringhe: OK\n";
    return 0;
}