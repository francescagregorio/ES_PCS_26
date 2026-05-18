#include "undirected_graph.h"
#include "undirected_edge.h"
#include "dijkstra.hpp"
#include "lifo.hpp"
#include "fifo.hpp"
#include "graph_visit.hpp"
#include <iostream>
#include <string>
int main() {
    /* Contenitore con politica FIFO */ 
    fifo<int> f; 
    f.put(10);
    if ( f.empty() ) { 
        std::cout << "ERRORE: il contenitore fifo risulta vuoto\n";
    } 
    else{
        std::cout <<"Il contenitore fifo risulta non vuoto (correttamente)\n";
    }
    // inserisce un elemento in fondo alla coda 
    auto x_opt = f.get(); 
    if (x_opt){
    std::cout <<"Risultato atteso: 10\nRisultato ottenuto: "<< *x_opt << "\n";  
    // estrae l'elemento in testa alla coda 
    }
    else{
	    std::cout <<"Errore: mi aspetto il valore 10!";
	 }    
	 if ( f.empty() ) { 
        std::cout << "Il contenitore fifo risulta vuoto (correttamente)\n";
    } 
    else{
        std::cout <<"ERRORE: il contenitore fifo risulta non vuoto\n";
    }
    /* Contenitore con politica LIFO */ 
    lifo<int> l; 
    l.put(10); 
    if ( l.empty() ) { 
        std::cout << "ERRORE: il contenitore lifo risulta vuoto\n";
    }
    else{
        std::cout <<"Il contenitore fifo risulta non vuoto (correttamente)\n";
    }
    // inserisce un elemento in cima allo stack 
    auto y_opt = l.get();
    if(y_opt){ 
    std::cout <<"Risultato atteso: 10\nRisultato ottenuto: "<< *y_opt<< "\n";
    // estrae l'elemento sulla cima dello stack 
    }
    else{
	    std::cout <<"Errore: mi aspetto il valore 10!";
	 }
    if ( l.empty() ) { 
        std::cout << "Il contenitore lifo risulta vuoto (correttamente)\n";
    }
    else{
        std::cout <<"ERRORE: il contenitore fifo risulta non vuoto\n";
    } 
    undirected_graph<int> G;
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(1, 4);
    G.add_edge(1, 6);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
    G.add_edge(2, 7);
    G.add_edge(3, 6);
    G.add_edge(4, 6);
    G.add_edge(4,7);
    G.add_edge(5, 7);
    G.add_edge(6,7);
    G.add_edge(6,8);
    G.add_edge(7,9);
    G.add_edge(8,9);
    write_dot("original_graph.dot", G, "Grafo_Originale");
    lifo<int> s; 
    fifo<int> q;
    /*Effettua una visita in profondità di G, restituendo il risultato in dfsG*/
    auto dfsG = graph_visit(G, 1, s); 
    write_dot("dfs_result.dot", dfsG, "Visita_DFS");
    /* Effettua una visita in ampiezza di G, restituendo il risultato in bfsG */ 
    auto bfsG = graph_visit(G, 1, q);
    write_dot("bfs_result.dot", bfsG, "Visita_BFS");
    /*Effettua DFS ricorsiva dal nodo 1*/
    auto rdfsG = recursive_dfs(G, 1);
    write_dot("recursive_dfs_result.dot", rdfsG, "Visita_DFS_ricorsiva");
    /*Dijstra*/
    auto dijG = dijkstra(G,1);
    write_dot("dijkstra_result.dot", dijG, "Albero_cammini_minimi_Dijkstra");
    undirected_graph<std::string> G1;
    G1.add_edge("Monday", "Tuesday");
    G1.add_edge("Monday", "Thursday");
    G1.add_edge("Tuesday", "Thursday");
    G1.add_edge("Friday", "Thursday");
    G1.add_edge("Tuesday", "Wednesday");
    G1.add_edge("Wednesday", "Friday");
    G1.add_edge("Friday", "Tuesday");
    G1.add_edge("Friday", "Sunday");
    write_dot("original_graph1.dot", G1, "Grafo_Originale");
    lifo<std::string> s_str; 
    fifo<std::string> q_str;
    /*Effettua una visita in profondità di G1, restituendo il risultato in dfsG1*/
    auto dfsG1 = graph_visit(G1, std::string("Friday"), s_str); 
    write_dot("dfs_result1.dot", dfsG1, "Visita_DFS");
    /* Effettua una visita in ampiezza di G1, restituendo il risultato in bfsG1 */ 
    auto bfsG1 = graph_visit(G1,std::string("Friday"), q_str);
    write_dot("bfs_result1.dot", bfsG1, "Visita_BFS");
    /*Effettua DFS ricorsiva dal nodo "Friday"*/
    auto rdfsG1 = recursive_dfs(G1, std::string("Friday"));
    write_dot("recursive_dfs_result1.dot", rdfsG1, "Visita_DFS_ricorsiva");
    /*Dijstra*/
    auto dijG1 = dijkstra(G1,std::string("Friday"));
    write_dot("dijkstra_result1.dot", dijG1, "Albero_cammini_minimi_Dijkstra");
    undirected_graph<double> G2;
    G2.add_edge(1.1, 2.2);
    G2.add_edge(2.2, 3.3);
    G2.add_edge(3.3, 4.4);
    G2.add_edge(1.1, 5.5);
    G2.add_edge(3.3, 5.5);
    write_dot("original_graph2.dot", G2, "Grafo_Originale");
    lifo<double> s_double;
    fifo<double> q_double;
    /*Effettua una visita in profondità di G2, restituendo il risultato in dfsG2*/
    auto dfsG2 = graph_visit(G2, 2.2, s_double); 
    write_dot("dfs_result2.dot", dfsG2, "Visita_DFS");
    /* Effettua una visita in ampiezza di G2, restituendo il risultato in bfsG2 */ 
    auto bfsG2 = graph_visit(G2,2.2, q_double);
    write_dot("bfs_result2.dot", bfsG2, "Visita_BFS");
    /*Effettua DFS ricorsiva dal nodo 2.2*/
    auto rdfsG2 = recursive_dfs(G2, 2.2);
    write_dot("recursive_dfs_result2.dot", rdfsG2, "Visita_DFS_ricorsiva");
    /*Dijstra*/
    auto dijG2 = dijkstra(G2,2.2);
    write_dot("dijkstra_result2.dot", dijG2, "Albero_cammini_minimi_Dijkstra");
    return 0;
}