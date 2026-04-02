#include <iostream>
#include <vector>
#include <algorithm>
#include "sorts.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main(){
    //creo il vettore delle dimensioni
    std::vector<int> dim;
    randfiller rf(42); //creo randfiller e fisso il seed
    for (int i = 4; i <= 8192; i *= 2){
        dim.push_back(i);
    }
    /* per realizzare i grafici in Matlab, avrò bisogno di 
    un vettore per ciascun metodo e contenente tutti i tempi*/
    std::vector<double> y_bubble;
    std::vector<double> y_inser;
    std::vector<double> y_select;
    std::vector<double> y_sort;

    int n = dim.size();
    std::vector <int> vec; //creo il vettore che volta per volta utilizzerò
    for (int i=0; i < n; i++){
        //creo il vettore di lunghezza dim[i] sul quale verificherò le lunghezze
        vec.resize(dim[i]);
        rf.fill(vec, -10000, 10000);
        timecounter tc;
        //bubble sort
        std::vector<int> v1 = vec; //creo una copia di vec da riordinare
        tc.tic();
        bubble_sort(v1);
        double t_bubble = tc.toc();
        y_bubble.push_back(t_bubble);
        //insertion sort
        std::vector<int> v2 = vec;
        tc.tic();
        insertion_sort(v2);
        double t_inser = tc.toc();
        y_inser.push_back(t_inser);
        //selection sort
        std::vector<int> v3 = vec;
        tc.tic();
        selection_sort(v3);
        double t_select = tc.toc();
        y_select.push_back(t_select);
        //std::sort
        std::vector<int> v4 = vec;
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double t_sort = tc.toc();
        y_sort.push_back(t_sort);
        //stampo i risultati così ottenuti
        std::cout << "Dimensione --> " << dim[i] <<"\n";
        std::cout << "Tempo bubble sort --> " << t_bubble << " secondi\n";
        std::cout << "Tempo insertion sort --> " << t_inser << " secondi\n";
        std::cout << "Tempo selection sort --> " << t_select <<" secondi\n";
        std::cout << "Tempo std::sort --> " << t_sort << " secondi\n"; 
        std::cout <<"\n";
    }
    /*stampo il vettore delle dimensioni per poi copiare e incollare
    l'output su MatLab*/
    std::cout << "Per MatLab: \n";
    std::cout <<"d = [";
    for (int j = 0; j<n-1; j++){
        std::cout << dim[j] << "; ";
    }
    std::cout << dim[n-1] <<"];\n";

    /*stampo i tempi ottenuti per ciascun metodo per poi copiare
    e incollare l'output su MatLab*/
    //bubble sort
    std::cout <<"y_bubble = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_bubble[j] << "; ";
    }
    std::cout << y_bubble[n-1] << "];\n";
    //insertion sort
    std::cout <<"y_inser = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_inser[j] << "; ";
    }
    std::cout << y_inser[n-1] << "];\n";
    //selection sort
    std::cout <<"y_select = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_select[j] << "; ";
    }
    std::cout << y_select[n-1] << "];\n";
    //std::sort
    std::cout <<"y_sort = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_sort[j] << "; ";
    }
    std::cout << y_sort[n-1] << "];\n";

    return 0;
    
}