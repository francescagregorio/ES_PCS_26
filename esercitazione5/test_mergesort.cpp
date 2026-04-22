#include <iostream>
#include <vector>
#include <string>
#include "sorts.h"
#include "randfiller.h"
#include <cstdlib>

int main(){
    //Riempimento di vettori con numeri casuali
    randfiller rf(42); //fisso un seme
    std::vector<double> vec;
    std::vector<int> dim; //credo vettore delle dimensioni con randfiller
    dim.resize(100);
    rf.fill(dim, 0, 5000); //riempio il vettore delle dimensioni casuali
    for (int t = 0; t <100; t++){
        vec.resize(dim[t]);
        rf.fill(vec, -10000.0, 10000.0);
        merge_sort(vec, 0, dim[t]-1);
        if (! is_sorted(vec)){
            std::cerr << "ERRORE: vettore di dimensione "<< dim[t] << " non è ordinato\n";
            return EXIT_FAILURE;
        }
    }
    /*faccio dei test con delle stringhe, ma non generate con randfiller.h
    in quanto esso lavora sugli integrals*/
    std::vector<std::string> mesi= {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
    merge_sort(mesi, 0, (int)mesi.size()-1);
    if(!is_sorted(mesi)){
        std::cerr <<"ERRORE nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector<std::string> stagioni {"primavera", "estate", "autunno", "inverno"};
    merge_sort(stagioni, 0, (int)stagioni.size()-1);
    if (!is_sorted(stagioni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector<std::string> giorni {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"};
    merge_sort(giorni, 0,  (int)giorni.size()-1);
    if (!is_sorted(giorni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout <<"Test superati con SUCCESSO";
    return EXIT_SUCCESS;

}