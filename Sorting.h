#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>

#ifndef SORTING_H
#define SORTING_H

template <class T>
class Sorting {

public:
    /*
     * Funkcja scalania dwoch rownych podtablic
     */
    void merge(T* A, int low, int high, int mid);

    /*
     * Rekurencyjny wariant algorytmu sortowania przez scalanie, tworzy dwie rowne podtablice, o liczbie elementow wiekszej
     * niz 1, nastepnie wywoluje dla nich samego siebie, na koniec dokonuje scalenia
     */
    void mergeSort(T *A, int low, int high);

    /*
     * Funkcja partycjonowania tablicy wzgledem elementu nazywanego piwotem, mniejsze od niego trafiaja na lewo, wieksze
     * na prawo
     */

    int partition(T *A, int low, int high);

    /*
     * Rekurencyjny wariant algorytmu sortowania szybkiego, po dokonaniu partycjnowania tablicy wzgledem piwota
     * wywoluje samego siebie dla dwoch podtablic
     */
    void quickSort(T *A, int low, int high);

    /*
     * Funkcja budujaca kopiec z elementow nieposortowanej tablicy, nowo dodane elementy sa porownywane i umieszczane w
     * odpowiednich miejscach, majac na uwadze ich rozmiar,
     */
    void maxHeapify(T *A, int heapSize, int i);

    /*
     * Algorytm sortowania przez kopcowanie, elementy na jego dole tworza czesc posortowana, druga czesc zostaje naprawiona
     * procedura jest powtarzana az do posortowania calosci
     */
    void heapSort(T *A, int arraySize);

    /*
     * Porownuje pierwszy element tablicy, znajdujacy sie w "czesci posortowanej", z dalszymi elemnetami i dokonuje
     * ewentualnego "swapu"
     */
    void insertionSort(T *A, int arraySize);

    /*
     * Jeden z wariantow hybrydowego sortowania introspektywnego, w zaleznosci od stalej okreslajacej maksymalna
     * dozwolona globokosc rekurencyjnych wywolan zostaje wywolany odpowiedni algorytm sortujacy
     */
    void introSort(T *A, int arraySize);

    /*
     * Funkcja sprawdzajaca poprawnosc sortowania i funkcja wyswietlajaca odpowiedni komunikat
     */
    bool check(T *A, int arraySize);
    void ifCorrect(T *A, int arraySize);


    /*
     * Pomocnicza funkcja odwracajaca tablice "do gory nogami"
     */
    void reverse(T *A, int arraySize);

    /*
     * Pomocniczna funckja sluzaca do wyswietlania elementow tablicy
     */
    void print(T *A, int arraySize);

    /*
     * Pomocnicza funkcja sluzaca do wyboru odpowiedniego sortowania w menu
     */
    void sorting(T *A, int arraySize);
};



#endif //SORTING_H
