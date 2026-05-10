#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>

int main(){
    undirected_graph<int> g;
    g.add_edge(1,1);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,3);
    //vicini 1
    auto opt_nb1 = g.neighbours(1);
    if (!opt_nb1.has_value()){
        std::cerr <<"Errore: g.neighbours(1) ha restituito nullopt, ma ci sono dei nodi esistenti\n";
        return EXIT_FAILURE;
    }
    auto& nb1 = *opt_nb1;
    bool has_1 = std::find(nb1.begin(), nb1.end(), 1) != nb1.end();
    bool has_3 = std::find(nb1.begin(), nb1.end(), 3) != nb1.end();
    bool has_4 = std::find(nb1.begin(), nb1.end(), 4) != nb1.end();
    bool has_2 = std::find(nb1.begin(), nb1.end(), 2) != nb1.end();
    if (nb1.size() != 3 || !has_1 || !has_3 || !has_4 || has_2) {
        std::cerr << "Errore nei vicini del nodo 1\n";
        return EXIT_FAILURE;
    }
    //vicini 3
    auto opt_nb3 = g.neighbours(3);
    if (!opt_nb3.has_value()) {
        std::cerr << "Errore: neighbours(3) ha restituito nullopt\n";
        return EXIT_FAILURE;
    }

    auto& nb3 = *opt_nb3;
    bool nb3_has_1 = std::find(nb3.begin(), nb3.end(), 1) != nb3.end();
    bool nb3_has_2 = std::find(nb3.begin(), nb3.end(), 2) != nb3.end();
    bool nb3_has_3 = std::find(nb3.begin(), nb3.end(), 3) != nb3.end();
    bool nb3_has_4 = std::find(nb3.begin(), nb3.end(), 4) != nb3.end();

    if (nb3.size() != 2 || !nb3_has_1 || !nb3_has_2 || nb3_has_3 || nb3_has_4) {
        std::cerr << "Errore nei vicini del nodo 3\n";
        return EXIT_FAILURE;
    }
    //vicini nodo inesistente
    auto opt_b5 = g.neighbours(5);
    if (opt_b5.has_value()) {
        std::cerr << "Errore: neighbours(5) avrebbe dovuto restituire nullopt\n";
        return EXIT_FAILURE;
    } else {
        std::cout << "Successo: neighbours(5) correttamente gestito come nullopt\n";
    }
    return EXIT_SUCCESS;
}