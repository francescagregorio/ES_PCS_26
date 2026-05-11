#include <iostream>
#include <cstdlib>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <stdexcept>
int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,6);
    //all_edges restituisce insieme ordinato
    undirected_edge<int> e0(1,2);
    undirected_edge<int> e1(3,4);
    undirected_edge<int> e2(5,6);
    undirected_edge<int> es(-1,-1);
    //edge_at
    try{
        if (g.edge_at(0) != e0){
            std::cerr << "Errore in edge_at per la posizione 0\n";
            return EXIT_FAILURE;
        }
        if (g.edge_at(1) != e1){
            std::cerr <<"Errore in edge_at per la posizione 1\n";
            return EXIT_FAILURE;
        }
        if (g.edge_at(2) != e2){
            std::cerr <<"Errore in edge_at per la posizione 2\n";
            return EXIT_FAILURE;
        }
    } catch (const std::out_of_range& e){
        std::cerr <<"Errore inatteso: indice valido segnalato come fuori dal range "<< e.what() <<"\n";
        return EXIT_FAILURE;
    }
    //test su indici out of range
    try{
        g.edge_at(19);
        //se non lancia eccezione --> mex di errore
        std::cerr << "Errore: g.edge_at(19) avrebbe dovuto lanciare un'eccezione, ma non l'ha fatto\n";
        return EXIT_FAILURE;
    } catch (const std::out_of_range& e){
        std::cout << "Catturata con successo l'eccezione per l'indice 19: "<< e.what() <<"\n";
    }
    try{
        g.edge_at(-1);
        //se non lancia eccezione --> mex di errore
        std::cerr << "Errore: g.edge_at(-1) avrebbe dovuto lanciare un'eccezione, ma non l'ha fatto\n";
        return EXIT_FAILURE;
    } catch (const std::out_of_range& e){
        std::cout << "Catturata con successo l'eccezione per l'indice -1: "<< e.what() <<"\n";
    }
    return EXIT_SUCCESS;
}