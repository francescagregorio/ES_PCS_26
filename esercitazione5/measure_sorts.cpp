#include <iostream>
#include <vector>
#include <algorithm>
#include "sorts.h"
#include "randfiller.h"
#include "timecounter.h"

int main(){
    //creo il vettore delle dimensioni
    std::vector<int> dim;
    int n = 50;
    dim.resize(n);
    for (int i = 0; i < n; i ++){
        dim[i] = (i+1)*2;
    }
    //creo il vettore delle dimensioni
    randfiller rf(42); //creo randfiller e fisso il seed
    /* per realizzare i grafici in Matlab, avrò bisogno di 
    un vettore per ciascun metodo e contenente tutti i tempi*/
    std::vector<double> y_bubble;
    y_bubble.resize(n);
    std::vector<double> y_inser;
    y_inser.resize(n);
    std::vector<double> y_select;
    y_select.resize(n);
    std::vector<double> y_sort;
    y_sort.resize(n);
    std::vector<double> y_merge;
    y_merge.resize(n);
    std::vector<double> y_quick;
    y_quick.resize(n);
    int m = 100;
    for (int i = 0; i <n; i ++){
        std::vector <std::vector<double>> vecs(m, std::vector<double>(dim[i])); //creo il vettore dei vettori
        for (int r=0; r <m; r++){
            rf.fill(vecs[r], -10000.0, 10000.0); //riempimento
        }
        timecounter tc;
        //ora procedo
        //Bubble sort
        std::vector<std::vector<double>> copie1 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            bubble_sort(copie1[r]);
        }
        y_bubble[i] = tc.toc()/m;
        //Insertion sort
        std::vector<std::vector<double>> copie2 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            insertion_sort(copie2[r]);
        }
        y_inser[i] = tc.toc()/m;
        //Selection sort
        std::vector<std::vector<double>> copie3 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            selection_sort(copie3[r]);
        }
        y_select[i] = tc.toc()/m;
        //std::sort
        std::vector<std::vector<double>> copie4 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            std::sort(copie4[r].begin(), copie4[r].end());
        }
        y_sort[i] = tc.toc()/m;
        //merge sort
        std::vector<std::vector<double>> copie5 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            merge_sort(copie5[r], 0, dim[i]-1);
        }
        y_merge[i] = tc.toc()/m;
        //Quick sort
        std::vector<std::vector<double>> copie6 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            quick_sort(copie6[r], 0, dim[i]-1);
        }
        y_quick[i] = tc.toc()/m;
        //stampo i risultati così ottenuti
        std::cout << "Dimensione --> " << dim[i] <<"\n";
        std::cout << "Tempo bubble sort --> " << y_bubble[i] << " secondi\n";
        std::cout << "Tempo insertion sort --> " << y_inser[i] << " secondi\n";
        std::cout << "Tempo selection sort --> " << y_select[i] <<" secondi\n";
        std::cout << "Tempo std::sort --> " << y_sort[i]<< " secondi\n"; 
        std::cout << "Tempo merge sort --> " << y_merge[i] << " secondi\n";
        std::cout <<"Tempo quick sort --> " <<y_quick[i] << " secondi\n";
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
    //merge_sort
    std::cout <<"y_merge = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_merge[j] << "; ";
    }
    std::cout << y_merge[n-1] << "];\n";
    //quick sort
    std::cout <<"y_quick = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_quick[j] << "; ";
    }
    std::cout << y_quick[n-1] << "];\n";
    /*Cerco la soglia al di sotto della quale gli algoritmi quadratici
    battono quelli logaritmici*/
    //codice
    return 0;
    
}