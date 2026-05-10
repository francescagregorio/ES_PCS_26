#include <iostream>
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <cstdlib>
int main(){
    undirected_graph<int> g;
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,6);
    undirected_graph<int> diff = g-g;
    if (!diff.all_edges().empty() || !diff.all_nodes().empty()){
	    std::cerr <<"Errore nella differenza G - G\n";
        return EXIT_FAILURE;
    }
    //g e g1 disgiunti
    undirected_graph<int> g1;
    g1.add_edge(7,8);
    g1.add_edge(9,10);
    undirected_graph<int> diff1 = g - g1;
    if (!(diff1.all_edges()== g.all_edges())){
	    std::cerr <<"Errore nella differenza di grafi disgiunti\n";
        return EXIT_FAILURE;
    }
    undirected_graph<int> g2;
    undirected_graph<int> g3;
    g2.add_edge(1,2);
    g2.add_edge(2,3);
    g3.add_edge(3,2);
    undirected_graph<int> diff2 = g2 - g3;
    auto nodi_r = diff2.all_nodes();
    auto f_1 = std::find(nodi_r.begin(), nodi_r.end(),1);
    bool has1 = f_1 != nodi_r.end();
    auto f2 = std::find(nodi_r.begin(), nodi_r.end(), 2);
    bool has2 = f2 != nodi_r.end();
    auto f3 = std::find(nodi_r.begin(), nodi_r.end(),3);
    auto has3 = f3 != nodi_r.end();
    if (!has1 || !has2 || has3){
        std::cerr <<"Errore nella differenza di grafi non disgiunti (nodi)\n";
        return EXIT_FAILURE;
    }
    if (diff2.all_edges().size()!=1){
        std::cerr <<"Errore nella differenza di grafi non disgiunti (archi)\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}