#include <iostream>
#include "undirected_graph.h"
#include "undirected_edge.h"
int main(){
    //edge stringa
    undirected_edge<std::string> nome("Gregorio", "Francesca");
    std::cout <<nome <<"\n";
    undirected_graph<int> g1;
    g1.add_edge(10,20);
    g1.add_edge(20,30);
    g1.add_edge(30,10); //ciclo
    undirected_graph<int> g2;
    g2.add_edge(20,30);
    g2.add_edge(40,50);
    //cosa c'è in g1?
    std::cout <<"Archi in g1: \n";
    for (const auto& e:g1.all_edges()){
        std::cout << "- Edge: "<< e <<"\n";
    }
    std::cout <<"Nodi in g1: \n";
    for (const auto& n: g1.all_nodes()){
        std::cout <<"- Nodo: " << n << "\n";
    }
    //sottrazione
    undirected_graph <int> ris = g1-g2;
    std::cout <<"Archi in g1 - g2: ";
    for (const auto&e : ris.all_edges()){
        std::cout << "- Edge: " << e <<"\n";
    }
    //vicini di un nodo
    std::cout <<"Vicini del nodo 10 in G1: \n";
    auto vic_opt = g1.neighbours(10);
    if (vic_opt){
        for (int v: *vic_opt){
            std::cout<< "- Vicino "<<v<<"\n";
        }
    }
    g1.add_edge(30,40);
    std::cout << "Aggiungo a g1 "<< undirected_edge<int>(30,40) <<"\n";
    std::cout <<"Archi in g1: \n";
    for (const auto& e:g1.all_edges()){
        std::cout << "- Edge: "<< e <<"\n";
    }
    std::cout <<"Nodi in g1: \n";
    for (const auto& n: g1.all_nodes()){
        std::cout <<"- Nodo: " << n << "\n";
    }
    undirected_edge<int> f(30,10);
    auto idx_opt = g1.edge_number(f);
    if (idx_opt){
        std::size_t idx = *idx_opt;
        std::cout <<"L'arco "<< f<< " si trova all'indice " <<idx <<"\n";
        //faccio verifica inversa
        auto f_inv = g1.edge_at(idx);
        if (f_inv){
            std::cout << "All'indice "<<idx << " è presente l'arco: " << *f_inv <<"\n";
        } 
    }
    return 1;
}