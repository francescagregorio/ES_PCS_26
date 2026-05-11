#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <algorithm>
#include <cstdlib>
int main(){
    undirected_graph<int> g;
    g.add_edge (1,2);
    g.add_edge (2,3);
    auto nodi = g.all_nodes();
    auto c1 = std::find(nodi.begin(), nodi.end(), 1);
    auto c2 = std::find(nodi.begin(), nodi.end(),2);
    auto c3 = std::find(nodi.begin(), nodi.end(),3);
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
    //cappi
    g.add_edge(4,4);
    if (g.all_edges().size()!=3){
        std::cerr <<"Errore nella gestione dei cappi\n";
        return EXIT_FAILURE;
    }
    //faccio un check anche su neighbours
    auto vic_2_opt = g.neighbours(2);
    if (!vic_2_opt.has_value()){
        std::cerr <<"Errore: neighbours(2) ha restituito nullopt\n";
        return EXIT_FAILURE;
    }
    const auto& vic_2 = *vic_2_opt;
    if (vic_2.size()!= 2 || vic_2[0] != 1 || vic_2[1] != 3){
        std::cerr <<"Errore: i vicini di 2 non sono corretti o sono ordinati male\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}