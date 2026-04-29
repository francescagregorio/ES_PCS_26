#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

//vec.size() --> auto, ma, su consiglio del docente uso int, l'importante è che sia non negativo
template <typename T> 
bool is_sorted(const std::vector<T>& vec){
    int N = vec.size();
    if (N==0){
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
void insertion_sort(std::vector<T>& vec, int l, int n){
    for (int i = 1+l; i < n+1; i ++){
        T key = vec[i];
        int j = i-1;
        while (j>=l && vec[j]>key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
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
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + j+1];

    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // copiare gli evenutali elementi rimasti
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// merge sort ricorsivo
template <typename T>
void merge_sort(std::vector<T>& A, int p, int r){
    
    if (p >= r)
        return;

    int q =(p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
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
    return (i+1);

}
//quick sort ricorsivo
template <typename T>
void quick_sort(std::vector<T>& A, int p, int r){
    if (p<r){
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}


//quick sort modificato
template <typename T>
void quick_sort_hybrid(std::vector<T>& A, int l, int h){
    int SOGLIA = 190; //fisso una soglia
    while (l<h){
        if (h-l +1 < SOGLIA){
	        /*se la dimensione del vettore è più piccolo della soglia
	        applico l'insertion sort*/
            insertion_sort(A,l,h);
            break;
        }
        else{
	        /*quicksort hybrid lavora per prima cosa sui vettori più piccoli*/
            int pivot = partition(A, l,h);
            /*se la parte a sx del pivot è più piccola della dx --> sorting sulla parte sx
            e poi mi sposto a dx*/
            if (pivot - l < h-pivot){
                quick_sort_hybrid(A, l, pivot-1);
                l = pivot +1;
            }
            else{
	            /*se la parte dx del pivot è più piccola della sx --> sorting sulla parte dx
	            e poi mi sposto a sx*/
                quick_sort_hybrid(A, pivot+1, h);
                h = pivot-1;
            }
        }
    }
}



