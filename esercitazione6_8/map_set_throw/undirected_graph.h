#pragma once
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include "undirected_edge.h"
#include <iterator>
#include <algorithm>
#include <stdexcept> //su consiglio del docente e ispirandomi a Python, introduco delle eccezioni al posto delle sentinelle
template <typename T>
class undirected_graph{
    //grafo come lista (in realtà mappa) di adiacenza: nodo --> vicini
    std::map<T, std::set<T>> m_adj;
    /*uso una mappa e non unordered_map perchè gli edges sono dei set (ordinati)*/
    public:
        //costruttore di default
        undirected_graph(){}
        //costruttore di copia
        undirected_graph(const undirected_graph<T>& other) //costruisco una copia che non esiste ancora
            :m_adj(other.m_adj)
        {}
        //operatore di assegnazione per copia
        undirected_graph& operator= (const undirected_graph<T>& g){ //vado a sovrascrivere un oggetto già esistente per creare una copia
            if (this != &g){
                m_adj = g.m_adj;  
            }
            return *this; //vado a restituire l'oggetto stesso
        }
        //all_edges()
        std::set<undirected_edge<T>> all_edges() const {
            std::set<undirected_edge<T>> edges;
            for (const auto& [nodo, vic]: m_adj){
                for (const T& nb: vic){
                    undirected_edge<T> e(nodo, nb);
                    edges.insert(e); //in automatico il set è ordinato
                    //VEDI SE SISTEMARLO
                }
            }
            return edges;
        }
        //all_nodes
        std::set<T> all_nodes() const {
            std::set<T> nodi;
            for (const auto& [nodo, vic] : m_adj){
                nodi.insert(nodo);
            }
            return nodi;
        }
        //add_edge()
        void add_edge(const T a, const T b){
            //controllo l'esistenza
            auto it = m_adj.find(a); //iteratore
            if (it != m_adj.end()){
                //a esiste...b è tra i suoi vicini?
                if (it->second.find(b) != it->second.end()){
                    return; //l'arco esiste già
                }
            }
            //altrimenti inserisco nella lista di adiacenza
            m_adj[a].insert(b);
            //gestisce in automatico i cappi in quanto all_edges restituisce un set
            m_adj[b].insert(a);
            /*nel caso in cui il nodo non appartenga alla lista di adiacenza,
            viene aggiunto in automatico*/
            return;
        }
        //edge_number()
        int edge_number(const undirected_edge<T>& e) const {
            int idx = 0;
            for (const auto& edge : all_edges()){
                if (edge == e){
                    return idx;
                }
                ++idx; //incremento
            }
            /*se non lo trovo --> lancio un'eccezione*/
            throw std::out_of_range("edge_number: arco non trovato\n");
        }
        //edge_at()
        undirected_edge<T> edge_at(int pos) const{
            
            auto edges = all_edges();
            //al massimo il numero d'arco può essere pari a edges.size()-1
            //il numero di arco non può essere negativo
            if (pos >= (int)edges.size()|| pos< 0){
                //lancio un'eccezione
                throw std::out_of_range("edge_at: indice fuori dal range\n");
            }
            //altrimenti devo accedere all'arco in quella posizione
            auto it = edges.begin(); //creo iteratore all'inizio
            std::advance(it, pos); //avanzo fino a quando arrivo a n
            return *it;
        }
        //neighbours
        std::set<T> neighbours(T n) const{
            auto search = m_adj.find(n);
            if (search == m_adj.end()){
                //non trovato
                //sollevo un'eccezione
                throw std::out_of_range ("neighbours: nodo non trovato\n");
            }
            return search->second;
        }

        //operator-
        undirected_graph<T> operator- (const undirected_graph<T>& other) const{
            undirected_graph<T> risultato;
            //devo cancellare gli archi presenti sia in G sia in G' (other)
            auto other_e = other.all_edges();
            for (const auto& e : all_edges()){
                if (other_e.count(e)==0){
                    risultato.add_edge(e.from(), e.to());
                }
            }
            return risultato;
        }
};
