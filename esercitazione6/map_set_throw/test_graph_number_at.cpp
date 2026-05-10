#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>
#include <stdexcept>
int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,6);
    undirected_edge<int> e0(1,2);
    undirected_edge<int> e1(4,3);
    undirected_edge<int> e2(5,6);
    undirected_edge<int> e3(8,9);
    try{
        //test sugli archi presenti
        if(g.edge_number(e0)!=0){
            std::cerr<<"Errore:indice di " <<e0 << " non è corretto\n";
            return EXIT_FAILURE;
        }
        std::cout<<"Arco "<< e0 << " trovato in posizione 0\n";
        //Tentativo di accesso a un arco inesistente --> std::out_of_range
        std::cout<< "Tentativo di accesso all'arco "<< e3<< " non presente\n";
        int pos = g.edge_number(e3);
        //se non lancio l'eccezione eseguo questa riga
        std::cout<<"Attenzione: l'eccezione non è stata lanciata. Indice: "<< pos <<"\n";
        return EXIT_FAILURE;
    }
    catch (const std::out_of_range& e){
        std::cerr <<"L'eccezione prevista è stata correttamente catturata: "<< e.what() << std::endl;
    }
    //potrei avere avuto eccezioni impreviste
    catch (const std::exception& e){
        std::cerr << "Eccezione non prevista: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}