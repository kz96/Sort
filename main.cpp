#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 * Funkcja scalania dwoch rownych podtablic
 */

template <class T>
void merge(T* A, int low, int high, int mid) {

        int i, j, k;
        i = low;
        j = mid + 1;
        k = low;
        int c[1000000];

        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                c[k] = A[i];
                k++;
                i++;
            }
            else {
                c[k] = A[j];
                k++;
                j++;
            }
        }

        while (i <= mid) {
            c[k] = A[i];
            k++;
            i++;
        }

        while (j <= high) {
            c[k] = A[j];
            k++;
            j++;
        }

        for (i = low; i < k; i++) {
            A[i] = c[i];
        }



}

/*
 * Rekurencyjny wariant algorytmu sortowania przez scalanie, tworzy dwie rowne podtablice, o liczbie elementow wiekszej
 * niz 1, nastepnie wywoluje dla nich samego siebie, na koniec dokonuje scalenia
 */
template <class T>
void mergeSort (T* A, int low, int high) {

    if (low < high){
        int mid;
        mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, low, high, mid);
    }
}

/*
 * Funkcja partycjonowania tablicy wzgledem elementu nazywanego piwotem, mniejsze od niego trafiaja na lewo, wieksze
 * na prawo
 */

template <class T>
int partition (T* A, int low, int high) {
    int x = A[low];
    int i = low, j = high, temp;

    while (true) {
        while (A[j] > x) {
            j--;
        }
        while (A[i] < x) {
            i++;
        }

        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        else {
            return j;
        }
    }
}

/*
 * Rekurencyjny wariant algorytmu sortowania szybkiego, po dokonaniu partycjnowania tablicy wzgledem piwota
 * wywoluje samego siebie dla dwoch podtablic
 */
template <class T>
void quickSort (T* A, int low, int high) {
    int x;
    if (low < high) {
        x = partition(A,low,high);
            quickSort(A, low, x);
            quickSort(A, x+1, high);
    }
}

/*
 * Funkcja budujaca kopiec z elementow nieposortowanej tablicy, nowo dodane elementy sa porownywane i umieszczane w
 * odpowiednich miejscach, majac na uwadze ich rozmiar,
 */
template <class T>
void maxHeapify (T* A, int heapSize, int i){
    int low = (i + 1) * 2 - 1;
    int high = (i + 1) * 2;
    int largest = 0;

    if (low < heapSize && A[low] > A[i]) {
        largest = low;
    }
    else {
        largest = i;
    }

    if (high < heapSize && A[high] > A[largest]){
        largest = high;
    }

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        maxHeapify(A, heapSize, largest);
    }
}

/*
 * Algorytm sortowania przez kopcowanie, elementy na jego dole tworza czesc posortowana, druga czesc zostaje naprawiona
 * procedura jest powtarzana az do posortowania calosci
 */
template <class T>
void heapSort (T* A, int arraySize) {
    int heapSize = arraySize;

    for(int j = (heapSize - 1) / 2; j >= 0; j--) {
        maxHeapify(A, heapSize, j);
    }

    for (int i = arraySize - 1; i > 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        --heapSize;
        maxHeapify(A, heapSize, 0);
    }
}

/*
 * Porownuje pierwszy element tablicy, znajdujacy sie w "czesci posortowanej", z dalszymi elemnetami i dokonuje
 * ewentualnego "swapu"
 */
template <class T>
void insertionSort (T* A, int arraySize) {
    int i,j,x;
    for (i = 1; i < arraySize; i++) {
        x = A[i];
        for (j = i; j > 0 && A[j-1] > x; j--) {
            A[j] = A[j-1];
            A[j-1] = x;
        }
    }
}

/*
 * Jeden z wariantow hybrydowego sortowania introspektywnego, w zaleznosci od stalej okreslajacej maksymalna
 * dozwolona globokosc rekurencyjnych wywolan zostaje wywolany odpowiedni algorytm sortujacy
 */
template <class T>
void introSort (T* A, int arraySize) {
    int partitionSize = partition(A, 0, arraySize-1);

    if (partitionSize < 16) {
        insertionSort(A, arraySize);
    }
    else if (partitionSize > (2*log(arraySize))) {
        heapSort(A, arraySize);
    }
    else {
        quickSort(A, 0, arraySize-1);
    }
}

/*
 * Pomocnicza funkcja odwracajaca tablice "do gory nogami"
 */
template <class T>
void reverse (T* A, int arraySize) {
    for (int i = 0; i < (arraySize/2); i++) {
        T temp = A[i];
        A[i] = A[arraySize-1-i];
        A[arraySize-1-i] = temp;
    }
}

/*
 * Pomocniczna funckja sluzaca do wyswietlania elementow tablicy
 */
template <class T>
void print(T* A, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << A[i] << endl;
    }
}

/*
 * Pomocnicza funkcja sluzaca do wyboru odpowiedniego sortowania w menu
 */
template <class T>
void sorting(T* A, int arraySize) {
    cout << "Wybierz sposob sortowania\n1. QUICK SORT\n2. MERGE SORT\n3. INTRO SORT" << endl;
    char wybor;
    cin >> wybor;
    switch (wybor) {
        case '1':
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            //clock_t start = clock();
            quickSort(A, 0, arraySize - 1);
            //clock_t stop = clock();
            //double czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "Po sortowaniu" << endl;
            print(A, arraySize);
            break;
        case '2':
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            //start = clock();
            mergeSort(A, 0, arraySize - 1);
            //stop = clock();
            //czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "Po sortowaniu" << endl;
            print(A, arraySize);
            //cout << "CZAS" << czas << endl;
            break;
        case '3':
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            //start = clock();
            introSort(A, arraySize);
            //stop = clock();
            //czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "Po sortowaniu" << endl;
            print(A, arraySize);
            //cout << "CZAS" << czas << endl;
            break;
        default:
            cout << "Zła dana" << endl;

    }
}

void menu() {
    cout << "\n\nMENU" << endl;
    cout << "1. SORTING" << endl;
    cout << "2. REVERSE" << endl;
    cout << "3. CLEAR" << endl;
    cout << "4. END" << endl;
}

int main() {
    srand(time(NULL));

    char c;

    while(c != '4') {
        menu();
        cin >> c;

        switch (c) {
            case '1':
                int arraySize;
                cout << "Podaj dlugosc tablicy" << endl;
                cin >> arraySize;
                int *A;
                A = new int[arraySize];

                for (int i = 0; i < arraySize; i++) {
                    A[i] = rand() % 9999 + 1;
                }
                sorting(A,arraySize);
                break;
            case '2':
                reverse(A,arraySize);
                print(A,arraySize);
                break;
            case '3':
                delete A;
                cout << "Tablica usunieta !" << endl;
                break;
            default:
                cout << "ZLA DANA" << endl;
                break;

        }
    }

}