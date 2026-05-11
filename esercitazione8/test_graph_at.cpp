#include <iostream>
#include <cstdlib>
#include "undirected_edge.h"
#include "undirected_graph.h"

int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,6);
    //all_edges restituisce vettore ordinato
    undirected_edge<int> e0(1,2);
    undirected_edge<int> e1(3,4);
    undirected_edge<int> e2(5,6);
    undirected_edge<int> es(-1,-1);
    //edge_at
    //indici validi
    auto res0 = g.edge_at(0);
    auto res1 = g.edge_at(1);
    auto res2 = g.edge_at(2);
    //gli optional vanno referenziati *
    if (!res0 || *res0 != e0){
        std::cerr<<"Errore in edge_at per la posizione 0\n";
        return EXIT_FAILURE;
    }
    if (!res1 || *res1 != e1){
        std::cerr <<"Errore in edge_at per la posizione 1\n";
        return EXIT_FAILURE;
    }
    if (!res2 || *res2 != e2){
        std::cerr <<"Errore in edge_at per la posizione 2\n";
        return EXIT_FAILURE;
    }
    //test out_of_range
    //non lancio eccezioni, ma verifico che sia vuoto
    auto res_out = g.edge_at(19);
    if (res_out.has_value()){
        std::cerr<< "Errore: g.edge_at(19) ha un valore, ma avrebbe dovuto restituire nullopt\n";
        return EXIT_FAILURE;
    }
    else{
        std::cout<<"Successo: indice out_of_range gestito correttamente come nullopt\n";
    }
    return EXIT_SUCCESS;
}