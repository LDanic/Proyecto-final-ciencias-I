//
// Created by vadan on 26/11/2023.
//

#ifndef PROYECTO_FINAL_CIENCIAS_I_MERGESORT_H
#define PROYECTO_FINAL_CIENCIAS_I_MERGESORT_H


#include <algorithm>

template<class T, class C> struct Pos{
    T info;
    C clave;
};

template<class T, class C> class MergeSort{

    Pos<T, C> *aux;
public:
    MergeSort(){
    }

    void merge(Pos<T, C> *a, int lo, int mid, int hi);
    void sort(Pos<T, C>  *a, int N);
};

template<class T, class C>void MergeSort<T, C>::sort(Pos<T, C> *a, int N) {
    int sz, lo;
    aux = new Pos<T, C>[N];

    for(sz=1; sz<N; sz=sz+sz){
        for(lo=0; lo<N-sz; lo+=sz+sz){
            merge(a, lo, lo+sz-1, std::min(lo+sz+sz-1, N-1));
        }
    }
}

template<class T, class C> void MergeSort<T, C>::merge(Pos<T, C> *a, int lo, int mid, int hi) {
    int k, i = lo, j=mid+1;

    for(k=lo; k<=hi; k++){
        aux[k] = a[k];
    }

    for(k=lo; k<=hi; k++){
        if(i>mid)                               a[k] = aux[j++];
        else if(j>hi)                           a[k]=aux[i++];
        else if(aux[j].clave<=aux[i].clave)     a[k]=aux[j++];
        else                                    a[k]=aux[i++];
    }
}

#endif //PROYECTO_FINAL_CIENCIAS_I_MERGESORT_H
