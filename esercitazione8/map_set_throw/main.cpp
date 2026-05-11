#include "undirected_edge.h"
#include <iostream>
#include "undirected_graph.h"
int main(){
    //faccio test stampa edge
    undirected_edge<std::string> e("a","b");
    undirected_edge<int> a(1,2);
    std::string oss;
    std::cout << oss << e << std::endl << "\n";
    std::string es;
    std::cout << es << a <<std::endl << "\n";
    //provo ad aggiungere un nodo con indice negativo
    undirected_graph<int> g;
    undirected_edge ee(-1,2);
    std::cout << "Provo ad aggiungere a un grafo l'arco " << ee <<"\n";
    g.add_edge(-1,2);
    return 0;
}