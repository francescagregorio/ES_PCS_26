#pragma once
#include "undirected_edge.h"
#include "undirected_graph.h"
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <climits>
/*l'algoritmo Dijkstra si basa sulle code con priorità.
In C++ std::priority_queue estrae sempre il valore massimo. 
Qui sono interessata ad estrarre sempre il nodo con distanza minore;
devo, in qualche modo, invertire l'ordine*/
//definisco una struttura NodeDist che mi permetta di fare ciò
template <typename T>
struct NodeDist{

    double dist; //distanza per raggiungere questo nodo dalla sorgente
    T node; //valore del nodo    
    bool operator> (const NodeDist& other) const{
        return dist> other.dist; //perchè voglio poi estrarre sempre il nodo con distanza MINORE dalla priority_queue
    }
};
template <typename T>
undirected_graph<T> dijkstra(const undirected_graph<T>& g, const T& s){
    undirected_graph<T> tree;
    //creo la mappa delle distanze
    std::map<T, double> dist;
    //creo una mappa che memorizza i padri
    std::map<T,T> pred; //non lo inizializzo con valori sentinella in quanto il grafo ammette tutti i tipi di nodi, quindi aggiungo (ed eventualmente aggiorno) i predecessori man mano che li trovo
    //inizializzo le distanze a infinito per ogni nodo 
    for (const auto& n: g.all_nodes()){
        dist[n] = std::numeric_limits<double>::infinity();
    }
    //la sorgente v esiste?
    if (dist.find(s) == dist.end()){
        return tree;
    }
    dist[s] = 0.0; //inizializzo a 0 la distanza dalla sorgente
    //min priority_queue delle distanze
    /*Elementi contenuti nella pq -- memorizzazione interna -- priorità nell'ordinamento*/
    std::priority_queue<NodeDist<T>, std::vector<NodeDist<T>>, std::greater<NodeDist<T>>> pq; //minore distanza --> maggiore priorità
    pq.push({dist[s],s});
    while (!pq.empty()){
        T u = pq.top().node;
        double d = pq.top().dist;
        pq.pop();
        if (d>dist[u]){
            continue;
        }
        auto vicini_opt = g.neighbours(u);
        if (vicini_opt){
            for (const auto& v : *vicini_opt){
                /*Il grafo, per come è implementato in undirected_graph non ha archi pesati;
                uso, di default, w = 1.0*/
                double w = 1.0;
                //riesco a trovare un cammino più breve?

                if (dist[v]>dist[u]+w ){
                    /* Dijkstra e grafo non pesato --> se uso > trovato un cammino di uguale lunghezza non aggiorno il predecessore:
                    il primo cammino minimo trovato viene mantenuto.
                    Usando >=, invece, mantengo l'ultimo cammino trovato come in BFS */
                    dist[v] = dist[u] + w;
                    pred[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    //aggiungo gli archi al cammino
    for (const auto& [figlio, padre] : pred){
        tree.add_edge(padre, figlio);
    }
    return tree;
}   