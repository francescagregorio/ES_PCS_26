#include <iostream>
#include "undirected_edge.h"
#include <cstdlib>
#include "undirected_graph.h"

int main(){
    undirected_graph<int> g;
    if (g.all_edges().size() != 0){
        return EXIT_FAILURE;
    }
    g.add_edge(1,2);
    g.add_edge(5,6);
    g.add_edge(4,3);
    if (g.all_edges().size() != 3){
        return EXIT_FAILURE;
    }
    //arco duplicato
    g.add_edge(6,5);
    if (g.all_edges().size()!= 3){
        return EXIT_FAILURE;
    }
    auto edges = g.all_edges();
    auto c1 = std::find(edges.begin(), edges.end(), undirected_edge<int>(1,2));
    auto c2 = std::find(edges.begin(), edges.end(), undirected_edge<int>(6,5));
    auto c3 = std::find(edges.begin(), edges.end(), undirected_edge<int>(10,8));
    if (c1 == edges.end() || c2 == edges.end()|| c3 != edges.end()){
	    std::cerr << "Errore nell' all_edges\n";
        return EXIT_FAILURE;
    }
    //controllo che all_edges ordini per < 
    auto it = edges.begin(); //iteratore
    if (*it != undirected_edge<int>(1,2)){
	    std::cerr << "Errore: all_edges non ordina per < \n";
        return EXIT_FAILURE;
    }
    ++ it;
    if (*it != undirected_edge<int>(3,4)){
	    std::cerr << "Errore: all_edges non ordina per < \n";
	    return EXIT_FAILURE;
    }
    ++ it;
    if (*it != undirected_edge<int>(6,5)){
	    std::cerr << "Errore: all_edges non ordina per < \n";        
	    return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}