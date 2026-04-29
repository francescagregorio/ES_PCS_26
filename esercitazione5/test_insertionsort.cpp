#include <string>
#include "sorts.h"
#include "randfiller.h"
#include <cstdlib>

int main(){
    //Riempimento di vettori con numeri casuali
    randfiller rf(42); //fisso un seme
    for (int t=0; t<100; t++){
        //creo centro vettori di prova
        int dim = std::rand() %5000+1;
        std::vector<double> v(dim);
        //esempio usato per debuggare durante la progettazione
       //std::vector<double> v(3);
        //v = {10, 9, 8};
        rf.fill(v, -10000.0, 10000.0);
        insertion_sort(v, 0, (int)v.size()-1);
        if (!is_sorted(v)){
            std::cerr <<"ERRORE: Test fallito per il vettore " << t+1 <<" di dimensione " << v.size() <<"\n";
            return EXIT_FAILURE;
        }
    }

    /*faccio dei test con delle stringhe, ma non generate con randfiller.h
    in quanto esso lavora sugli integrals*/
    std::vector <std::string> mesi= {"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
    insertion_sort(mesi, 0, (int)mesi.size()-1);
    if(!is_sorted(mesi)){
        std::cerr <<"ERRORE nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector <std::string> stagioni {"primavera", "estate", "autunno", "inverno"};
    insertion_sort(stagioni, 0, (int)stagioni.size()-1);
    if (!is_sorted(stagioni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::vector <std::string> giorni {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"};
    insertion_sort(giorni, 0, (int)giorni.size()-1);
    if (!is_sorted(giorni)){
        std::cerr<<"Errore nell'ordinamento di un vettore di stringhe\n";
        return EXIT_FAILURE;
    }
    std::cout <<"Test superati con SUCCESSO";
    return EXIT_SUCCESS;

}