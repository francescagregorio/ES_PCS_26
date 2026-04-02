#include <string>
#include "sorts.hpp"
#include "randfiller.h"
#include <cstdlib>

int main(){
    //Riempimento di vettori con numeri casuali --> uso interi (+, -)
    randfiller rf(42); //fisso un seme
    std::vector<int> vec;
    std::vector<int> dim; //credo vettore delle dimensioni con randfiller
    dim.resize(100);
    rf.fill(dim, 0, 5000); //riempio il vettore delle dimensioni casuali
    for (int t = 0; t <100; t++){
        vec.resize(dim[t]);
        rf.fill(vec, -10000, 10000);
        insertion_sort(vec);
        if (! is_sorted(vec)){
            std::cerr << "ERRORE: vettore di dimensione "<< dim[t] << " non è ordinato\n";
            return EXIT_FAILURE;
        }
    }
    /*faccio dei test con delle stringhe, ma non generate con randfiller.h
    in quanto esso lavora sugli integrals*/
    std::vector <std::string> mesi= {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
    insertion_sort(mesi);
    if(!is_sorted(mesi)){
        std::cerr <<"ERRORE nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector <std::string> stagioni {"primavera", "estate", "autunno", "inverno"};
    insertion_sort(stagioni);
    if (!is_sorted(stagioni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector <std::string> giorni {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"};
    insertion_sort(giorni);
    if (!is_sorted(giorni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout <<"Test superati con SUCCESSO";
    return EXIT_SUCCESS;

}