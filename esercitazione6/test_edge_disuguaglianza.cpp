#include <iostream>
#include "undirected_edge.h"
#include <cstdlib>
int main(){
    undirected_edge<int> e1(1,2);
    undirected_edge<int> e2 (1,4);
    undirected_edge<int> e3(2,1);
    if (e1 != e3){
	    std::cerr <<"Errore nelle disuguaglianze tra archi "<< e1 <<", " << e3 <<"\n";
        return EXIT_FAILURE;
    }
    if (!(e1 != e2)){
	    std::cerr <<"Errore nelle disuguaglianze tra archi "<< e1 <<", " << e2 <<"\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}