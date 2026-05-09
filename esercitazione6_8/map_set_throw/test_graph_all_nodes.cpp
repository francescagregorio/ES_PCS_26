#include <iostream>
#include "undirected_edge.h"
#include <cstdlib>
#include <stdexcept>
#include "undirected_graph.h"
int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    if (g.all_nodes().size() != 4){
	    std::cerr << "Errore in all_nodes: attesi 4 nodi, ma ne ho trovati solo: "<< g.all_nodes().size()<<"\n";
        return EXIT_FAILURE;
    }
    g.add_edge(1,4);
    if (g.all_nodes().size() != 4){
	    std::cerr << "Errore in all_nodes quando si inserisce un arco collegato a nodi già esistenti\n";
        return EXIT_FAILURE;
    }
    g.add_edge(1,5);
    if (g.all_nodes().size() != 5){
	     std::cerr << "Errore in all_nodes quando si inserisce un arco collegato a un nodo già esistente\n";        
	     return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}