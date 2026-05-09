#include <iostream>
#include <cstdlib>
#include "undirected_edge.h"

int main(){
    undirected_edge<int> e1(1,2);
    undirected_edge<int> e2(1,3);
    undirected_edge<int> e3(2,1);
    undirected_edge<int> e4(2,3);
    if (e2<e1|| e2<e3 || e3< e1 || e1 < e3 ||e4 < e1 || e4<e3 || e4 < e2){
        std::cerr << "ERRORE: arco "<< e1 << "< arco " << e2<< "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;  
}
