#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//vec.size() --> auto, ma, su consiglio del docente uso int, l'importante è che sia non negativo -->  unsigned
template <typename T> 
bool is_sorted(const std::vector<T>& vec){
    int N = vec.size();
    if (N == 0){
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
