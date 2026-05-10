
#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>
#include <stdexcept>
int main(){
    undirected_graph<int> g;
    g.add_edge (1,2);
    g.add_edge (2,3);
    auto nodi = g.all_nodes();
    auto c1 = nodi.find(1);
    auto c2 = nodi.find(2);
    auto c3 = nodi.find(3);
    if (nodi.size() != 3 || c1 == nodi.end() || c2 ==nodi.end() || c3 == nodi.end()){
	    std::cerr << "Errore nell'add_edge\n";
        return EXIT_FAILURE;
    }
    //ignoro gli archi duplicati
    g.add_edge(2,1);
    if (g.all_edges().size() !=2){
	    std::cerr << "Errore nell'add_edge: ignora archi duplicati\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}