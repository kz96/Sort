#include "Sorting.h"

using namespace std;

template <class T>
void Sorting<T>::merge(T *A, int low, int high, int mid) {

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
        } else {
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

template <class T>
void Sorting<T>::mergeSort(T *A, int low, int high) {

    if (low < high) {
        int mid;
        mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, high, mid);
    }
}

template<class T>
int Sorting<T>::partition(T *A, int low, int high) {
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
        } else {
            return j;
        }
    }
}

template<class T>
void Sorting<T>::quickSort(T *A, int low, int high) {
    int x;
    if (low < high) {
        x = partition(A, low, high);
        quickSort(A, low, x);
        quickSort(A, x + 1, high);
    }
}

template<class T>
void Sorting<T>::maxHeapify(T *A, int heapSize, int i) {
    int low = (i + 1) * 2 - 1;
    int high = (i + 1) * 2;
    int largest = 0;

    if (low < heapSize && A[low] > A[i]) {
        largest = low;
    } else {
        largest = i;
    }

    if (high < heapSize && A[high] > A[largest]) {
        largest = high;
    }

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        maxHeapify(A, heapSize, largest);
    }
}

template<class T>
void Sorting<T>::heapSort(T *A, int arraySize) {
    int heapSize = arraySize;

    for (int j = (heapSize - 1) / 2; j >= 0; j--) {
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

template <class T>
void Sorting<T>::insertionSort(T *A, int arraySize) {
    int i, j, x;
    for (i = 1; i < arraySize; i++) {
        x = A[i];
        for (j = i; j > 0 && A[j - 1] > x; j--) {
            A[j] = A[j - 1];
            A[j - 1] = x;
        }
    }
}

template<class T>
void Sorting<T>::introSort(T *A, int arraySize) {
    int partitionSize = partition(A, 0, arraySize - 1);

    if (partitionSize < 16) {
        insertionSort(A, arraySize);
    } else if (partitionSize > (2 * log(arraySize))) {
        heapSort(A, arraySize);
    } else {
        quickSort(A, 0, arraySize - 1);
    }
}

template<class T>
bool Sorting<T>::check(T *A, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
        return true;
    }
}

template<class T>
void Sorting<T>::ifCorrect(T *A, int arraySize) {
    if (check(A, arraySize) == true) {
        cout << "Sortowanie wykonane poprawnie !" << endl;
    } else {
        cout << "Blad sortowania !" << endl;
    }
}

template<class T>
void Sorting<T>::reverse(T *A, int arraySize) {
    for (int i = 0; i < (arraySize / 2); i++) {
        T temp = A[i];
        A[i] = A[arraySize - 1 - i];
        A[arraySize - 1 - i] = temp;
    }
}

template <class T>
void Sorting<T>::print(T *A, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << A[i] << endl;
    }
}

template <class T>
void Sorting<T>::sorting(T *A, int arraySize) {
    cout << "Wybierz sposob sortowania\n1. QUICK SORT\n2. MERGE SORT\n3. INTRO SORT" << endl;
    char wybor;
    cin >> wybor;
    switch (wybor) {
        case '1': {
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            clock_t start = clock();
            quickSort(A, 0, arraySize - 1);
            clock_t stop = clock();
            double czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "\nPo sortowaniu" << endl;
            print(A, arraySize);
            cout << "Czas sortowania: " << setprecision(6) << fixed << czas << "[s]" << endl;
            break;
        }
        case '2': {
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            clock_t start = clock();
            mergeSort(A, 0, arraySize - 1);
            clock_t stop = clock();
            double czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "\nPo sortowaniu" << endl;
            print(A, arraySize);
            cout << "Czas sortowania: " << setprecision(6) << fixed << czas << "[s]" << endl;
            break;
        }
        case '3': {
            cout << "Przed sortowaniem" << endl;
            print(A, arraySize);
            clock_t start = clock();
            introSort(A, arraySize);
            clock_t stop = clock();
            double czas = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "\nPo sortowaniu" << endl;
            print(A, arraySize);
            cout << "Czas sortowania: " << setprecision(6) << fixed << czas << "[s]" << endl;
            break;
        }
        default:
            cout << "Zła dana" << endl;

    }
}

template class Sorting <int>;