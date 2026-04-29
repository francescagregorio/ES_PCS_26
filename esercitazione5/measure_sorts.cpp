#include <iostream>
#include <vector>
#include <algorithm>
#include "sorts.h"
#include "randfiller.h"
#include "timecounter.h"
#include <fstream>

int main(){
    //creo il vettore delle dimensioni
    int n = 150; //numero delle dimensioni
    /* anche se il testo dell'esercitazione dice di usare vettori di dimensione <100,
    il mio calcolatore non riesce a trovare la soglia in modalità Release*/
    std::vector<int> dim(n);
    for (int i = 0; i < n; i ++){
        dim[i] = (i+1)*2;
    }
    //creo il vettore delle dimensioni
    randfiller rf(42); //creo randfiller e fisso il seed
    timecounter tc;
    /* per realizzare i grafici in Matlab, avrò bisogno di 
    un vettore per ciascun metodo e contenente tutti i tempi*/
    std::vector<double> y_bubble(n);
    std::vector<double> y_inser(n);
    std::vector<double> y_select(n);
    std::vector<double> y_sort(n);
    std::vector<double> y_merge(n);
    std::vector<double> y_quick(n);
    std::vector<double> y_quick_hybrid(n); //aggiunto dopo aver implementato il quick_sort_hybrid
    const int m = 1000; //numero di vettori per dimensione
    std::ofstream file("tempi.csv");
    if (!file.is_open()){
        std::cerr << "ERRORE nell'apertura del file\n";
    }
    file <<"n, bubble, insertion, selection, std::sort, quick, merge, quick hybrid\n";
    for (int i = 0; i <n; i ++){
        std::vector <std::vector<int>> vecs(m, std::vector<int>(dim[i])); //creo il vettore dei vettori
        for (int r=0; r <m; r++){
            rf.fill(vecs[r], -10000, 10000); //riempimento
        }
        //ora procedo
        //Bubble sort
        std::vector<std::vector<int>> copie1 = vecs;
        std::vector<std::vector<int>> copie2 = vecs;
        std::vector<std::vector<int>> copie3 = vecs;
        std::vector<std::vector<int>> copie4 = vecs;
        std::vector<std::vector<int>> copie5 = vecs;
        std::vector<std::vector<int>> copie6 = vecs;
        std::vector<std::vector<int>> copie7 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            bubble_sort(copie1[r]);
        }
        y_bubble[i] = tc.toc()/m;
        //Insertion sort
        //std::vector<std::vector<double>> copie2 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            insertion_sort(copie2[r], 0, dim[i]-1);
        }
        y_inser[i] = tc.toc()/m;
        //Selection sort
        //std::vector<std::vector<double>> copie3 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            selection_sort(copie3[r]);
        }
        y_select[i] = tc.toc()/m;
        //std::sort
        //std::vector<std::vector<double>> copie4 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            std::sort(copie4[r].begin(), copie4[r].end());
        }
        y_sort[i] = tc.toc()/m;
        //merge sort
        //std::vector<std::vector<double>> copie5 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            merge_sort(copie5[r], 0, dim[i]-1);
        }
        y_merge[i] = tc.toc()/m;
        //Quick sort
        //std::vector<std::vector<double>> copie6 = vecs;
        tc.tic();
        for (int r = 0; r<m; r++){
            quick_sort(copie6[r], 0, dim[i]-1);
        }
        y_quick[i] = tc.toc()/m;
        //quick sort hybrid (aggiunto in un secondo momento)
        //std::vector<std::vector<double>> copie7 = vecs;
        tc.tic();
        for (int r=0; r<m; r++){
            quick_sort_hybrid(copie7[r], 0, dim[i]-1);
        }
        y_quick_hybrid[i] = tc.toc()/m;
        //stampo i risultati così ottenuti
        std::cout << "Dimensione --> " << dim[i] <<"\n";
        std::cout << "Tempo bubble sort --> " << y_bubble[i] << " secondi\n";
        std::cout << "Tempo insertion sort --> " << y_inser[i] << " secondi\n";
        std::cout << "Tempo selection sort --> " << y_select[i] <<" secondi\n";
        std::cout << "Tempo std::sort --> " << y_sort[i]<< " secondi\n"; 
        std::cout << "Tempo merge sort --> " << y_merge[i] << " secondi\n";
        std::cout <<"Tempo quick sort --> " <<y_quick[i] << " secondi\n";
        std::cout <<"Tempo quick sort hybrid --> "<< y_quick_hybrid[i] << " secondi\n"; //aggiunto in un secondo momento
        /*dal momento che il migliore algoritmo di complessità quadratica è l'insertion sort
        e che il migliore di complessità logaritmica è il quick sort, stampo quando il quick sort è 
        più veloce dell'insertion sort; ciò, insieme al grafico Matlab, mi aiuterà a trovare
        la dimensione di soglia n0
        */
        if (y_inser[i] > y_quick[i]){
	        std::cout <<"\nPer n = "<< dim[i]<< " il quick sort è più veloce dell' insertion sort\n"; 
	     }
        std::cout <<"\n";
        file << dim[i] << "," << y_bubble[i] << "," << y_inser[i] <<"," << y_select[i] << "," << y_sort[i] << "," << y_merge[i] << "," << y_quick[i] <<"," << y_quick_hybrid[i]<<"\n";
    }
    file.close();
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
    //quick sort hybrid, aggiunto in un secondo momento
    std::cout <<"y_quick_hybrid = [";
    for (int j = 0; j < n-1; j++){
        std::cout << y_quick_hybrid[j] << "; ";
    }
    std::cout << y_quick_hybrid[n-1] << "];\n";
    /*Cerco la soglia al di sotto della quale gli algoritmi quadratici
    battono quelli logaritmici*/
    //devono essere battuti per almeno 2 dimensioni
    /*std::cout << "\nRicerca della soglia n0 al di sotto della quale gli algoritmi quadratici sono più veloci dei logaritmici\n";
    bool found = false;
    for (int i = 0; i <n; i++){
        double best_quad = std::min({y_bubble[i], y_inser[i], y_select[i]});
        double best_log = std::min({y_merge[i], y_quick[i]});
        if (best_log < best_quad){
            std::cout << "n0 = " <<dim[i]<<"\n";
            found = true;
            break;
        }
    }
    if (! found){
        std::cout <<"n0 non trovato nel range testato\n";
    }*/
    /*A causa del rumore, n0 varia ogni volta che lancio il programma;
    un grafico realizzato con Matlab può facilitare la comprensione*/
    /*Dopo aver modificato quick sort e averne testato la versione "ibrida",
    provo a prenderne i tempi, inserendo il quick_sort_hybrid nel ciclo for che 
    si apre alla linea di codice 35*/
    

    return 0;
    
}