#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>
#include <stdexcept>
int main(){
    undirected_graph<int> g;
    g.add_edge(1,1);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,3);
    try{
        auto nb1 = g.neighbours(1);
        if (nb1.size()!=3 || nb1.find(1) == nb1.end()|| nb1.find(3) == nb1.end() || nb1.find(4) == nb1.end()|| nb1.find(2) != nb1.end()){
            std::cerr<< "Errore nei vicini del nodo 1\n";
            return EXIT_FAILURE;
        }
        auto nb3 = g.neighbours(3);
        if (nb3.size() != 2 || nb3.find(1) == nb3.end() || nb3.find(2) == nb3.end() || nb3.find(3) != nb3.end() || nb3.find(4) != nb3.end()){
            std::cerr <<"Errore nei vicini del nodo 3\n";
            return EXIT_FAILURE;
        }
    } catch (const std::out_of_range &e){
        std::cerr <<"Errore non previsto: nodo esistente non trovato" << e.what() <<"\n";
        return EXIT_FAILURE;
    }
    //test nodi inesistenti
    try{
        auto b5 = g.neighbours(5);
        //se arrivo qui, non è stata lanciata l'eccezione
        std::cerr <<"Errore: neighbours(5) avrebbe dovuto lanciare un'eccezione out_of_range\n";
        return EXIT_FAILURE;
    } catch(const std::out_of_range& e){
        std::cout <<"Eccezione "<< e.what()<< " catturata con successo\n";
    } catch (const std::exception& e){
        //eccezione generica e imprevista
        std::cerr <<"Errore: lanciata un'eccezione "<< e.what() << " non prevista\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}