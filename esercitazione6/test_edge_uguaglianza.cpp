#include <iostream>
#include <cstdlib>
#include "undirected_edge.h"

int main(){
    undirected_edge<int> e1(1,2);
    undirected_edge<int> e2 (1,4);
    undirected_edge<int> e3(2,1);
    if (e1 == e3){
        return EXIT_SUCCESS;
    }
    if (!(e1 == e2)){
        return EXIT_SUCCESS;
    }
    std::cerr << "Errore nelle uguaglianze tra edge\n";
    return EXIT_FAILURE;
}
