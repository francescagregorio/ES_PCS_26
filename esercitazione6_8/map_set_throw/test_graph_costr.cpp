#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>
#include <stdexcept>
int main(){
    //costruttore di default
    undirected_graph<int> g;
    if (!g.all_nodes().empty()){
	    std::cerr <<"Errore con il costruttore di default\n";
        return EXIT_FAILURE;
    }
    g.add_edge(3,4);
    if (g.all_nodes().size() !=2){
	    std::cerr <<"Errore: conteggio nodi errato\n";
        return EXIT_FAILURE;
    }
    //costruttore di copia, stessi archi
    undirected_graph<int> g1;
    g1.add_edge(1,2);
    g1.add_edge(3,4);
    undirected_graph<int> g2(g1);
    if (g2.all_edges() != g1.all_edges()){
	    std::cerr <<"Errore nel costruttore di copia - archi\n";
        return EXIT_FAILURE;
    }
    //stessi nodi
    if(g2.all_nodes() != g1.all_nodes()){
	    std::cerr <<"Errore nel costruttore di copia - nodi\n";
        return EXIT_FAILURE;
    }
    //modificare la copia non altera l'originale
    g2.add_edge(5,6);
    auto archi_g1 = g1.all_edges();
    auto it_intruso = archi_g1.find(undirected_edge<int>(5,6));
    if (it_intruso != archi_g1.end()){
        std::cerr <<"Errore: modificare la copia altera l'originale\n";
        return EXIT_FAILURE;
    }
    //modificare l'originale non altera la copia
    g1.add_edge(8,7);
    auto archi_g2 = g2.all_edges();
    auto it_i2 = archi_g2.find(undirected_edge<int> (8,7));
    if (it_i2 != archi_g2.end()){
        std::cerr<<"Errore: modificare l'ordinale altera la copia\n";
        return EXIT_FAILURE;
    }
    
    //copiare grafo vuoto
    undirected_graph<int> g3;
    undirected_graph<int> g4(g3);
    if (!g4.all_edges().empty()){
	    std::cerr<<"Errore nella copia del grafo vuoto\n";
        return EXIT_FAILURE;
    }
    //assegnazioni (=)
    undirected_graph<int> g5;
    g5.add_edge(1,2);
    undirected_graph<int> g6;
    g6 = g5;
    g5.add_edge(3,4);
    if (g5.all_edges().size() != 2 || g6.all_edges().size() !=1){
	    std::cerr<<"Errore nelle assegnazioni\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}