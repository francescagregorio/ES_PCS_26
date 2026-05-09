#include <iostream>
#include "undirected_edge.h"
#include <cstdlib>
int main(){
    undirected_edge<int> e1(1,2);
    if (e1.from() != 1 || e1.to() !=2){
	    std::cerr << "Errore nel from_to dell'arco " << e1 <<"\n";
        return EXIT_FAILURE;
    }
    undirected_edge<int> e3(2,1);
    if (e3.from() != 1 || e3.to() !=2){
	    std::cerr <<"Errore nel from_to dall'arco " << e3 << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;  
}
