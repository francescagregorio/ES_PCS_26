#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

//vec.size() --> auto, ma, su consiglio del docente uso int, l'importante è che sia non negativo -->  unsigned
template <typename T> 
bool is_sorted(const std::vector<T>& vec){
    int N = vec.size();
    if (N <= 0){
        return true;
    }
    for (int i = 1; i < N; i++){
        if (vec[i] < vec[i-1]){
            return false;
        }
    }
    return true;
}

//bubble sort
template <typename T> 
void bubble_sort(std::vector<T>& vec){
    int N = vec.size();
    if (N==0){
        return;
    }
    for (int i = 0; i < N-1; i ++){
        for (int j = N-1; j> i ; j--){
            if (vec[j] < vec[j-1]){
                std::swap(vec[j],vec[j-1]);
            }
        }
    }
}
//insertion sort
template <typename T>
void insertion_sort(std::vector<T>& vec){
    int  N = vec.size();
    if (N==0){
        return;
    }
    for (int j = 1; j < N; j ++){
        T key = vec[j];
        int i = j-1;
        while (i>=0 && vec[i]>key){
            vec[i+1] = vec[i];
            i = i-1;
        }
        vec[i+1] = key;
    }
}
//selection sort
template <typename T>
void selection_sort(std::vector<T>& vec){
    int N = vec.size();
    if (N==0){
        return;
    }
    for (int i = 0; i < N-1; i++){
        int min_index = i;
        for (int j = i+1; j < N; j++){
            if (vec[j] < vec[min_index]){
                min_index = j;
            }
        }
        std::swap(vec[i], vec[min_index]);
    }
}

//merge sort
//merge
template <typename T>
void merge(std::vector<T>& A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    //creo vettore 
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    for (int i=0; i < n1; i++){
        L[i] = A[p+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = A[q + j +1];
    }
    /*non esiste per le stringhe un concetto di infinito...dovrei creare una stringa di grandi dimensioni
    ma grande quanto? 
    Mi servo di un'implementazione alternativa del merge che permette di trattare indistintamente vettori
    di elementi numerici e non*/
    int i = 0;
    int j = 0;
    int k = p;
    //i due vettori hanno ancora elementi
    while (i <n1 && j<n2){
        if (L[i]<=R[j]){
            A[k] = L[i]; 
            i++;
        }
        else{
            A[k++] = R[j++];
            j++;
        }
        k ++;
    }
    //elementi rimasti
    while (i<n1){
        A[k++] = L[i++]; //prima eseguo l'operazione di assegnazione e poi di incremento (post-incremento)
    }
    while (j<n2){
        A[k++] = R[j++];
    }
}
//mergesort parte ricorsiva
template <typename T>
void merge_sort(std::vector<T>& A, int p, int r){
    int N = A.size();
    if (N == 0){
        return;
    }
    if (p>=0 && r>=0){
        if (p<r){
            int q = (p+r)/2;
            merge_sort(A, p, q);
            merge_sort(A, q+1, r);
            merge(A, p, q, r);
        }
    }
}

//quick sort
//partition
template <typename T>
int partition(std::vector<T> &A, int p, int r){
    T x = A[r]; //seleziono l'ultimo elemento come pivot
    int i = p -1;
    for (int j = p; j < r; j ++ ){
        if (A[j] <= x){
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i+1;

}
//quick sort ricorsivo
template <typename T>
void quick_sort(std::vector<T>& A, int p, int r){
    int N = A.size();
    if (N==0){
        return;
    }
    if (p<r){
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}



