#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>

int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,6);
    undirected_edge<int> e0(1,2);
    undirected_edge<int> e1(4,3);
    undirected_edge<int> e2(5,6);
    undirected_edge<int> e3(8,9);
    //archi presenti
    auto pos0 = g.edge_number(e0);
    if (!pos0.has_value() || *pos0 != 0) {
        std::cerr << "Errore: indice di " << e0 << " non è corretto o arco non trovato\n";
        return EXIT_FAILURE;
    }
    auto pos1 = g.edge_number(e1);
    if (!pos1.has_value() || *pos1 != 1) {
        std::cerr << "Errore: indice di " << e1 << " non è corretto\n";
        return EXIT_FAILURE;
    }
    //arco assente
    std::cout << "Tentativo di accesso all'arco " << e3 << " non presente\n";
    auto pos3 = g.edge_number(e3);
    if (pos3.has_value()){
        std::cerr << "Errore: l'arco " << e3 << " non dovrebbe essere presente, ma ha indice " << *pos3 << "\n";
        return EXIT_FAILURE;
    } 
    else {
        std::cout << "Successo: l'arco " << e3 << " correttamente non trovato (nullopt)\n";
    }
    return EXIT_SUCCESS;
}