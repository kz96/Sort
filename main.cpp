#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

void merge(int* A, int low, int high, int mid) {

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

void mergeSort (int* A, int low, int high) {

    if (low < high){
        int mid;
        mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, low, high, mid);
    }
}

int partition (int* A, int low, int high) {
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

void quickSort (int* A, int low, int high) {
    int border;
    if (low < high) {
        border = partition(A,low,high);
            quickSort(A, low, border);
            quickSort(A, border+1, high);
    }
}

void maxHeapify (int* A, int heapSize, int i){
    int low = (i+1) * 2 - 1;
    int high = (i+1) * 2;
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

void heapSort (int* A, int arraySize) {
    int heapSize = arraySize;

    for(int j = (heapSize - 1) / 2; j >= 0; j--) {
        maxHeapify(A, heapSize, j);
    }

    for (int i = arraySize -1; i > 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        --heapSize;
        maxHeapify(A, heapSize, 0);
    }
}

void insertionSort (int* A, int low, int high) {
    int temp;
    int i,j;

    for (i = low; i < high; i++) {
        temp = A[i];
        for (j = i; j > 0 && A[j-1] > temp; j--){
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

void introSort (int* A, int arraySize) {
    //int arraySize = high + 1;
    int partitionSize = partition(A, 0, arraySize-1);

    if (partitionSize < 16) {
        insertionSort(A, 0, arraySize-1);
    }
    else if (partitionSize > (2*log(arraySize))) {
        heapSort(A, arraySize);
    }
    else {
        quickSort(A, 0, arraySize-1);
    }
}

int main() {
    srand(time(NULL));

    int arraySize;
    cout << "Podaj dlugosc tablicy" << endl;
    cin >> arraySize;

    int *A, *A1, *A2;
    A = new int [arraySize];
    int low = 0;
    int high = arraySize - 1;


    ofstream myfile;

   for (int j=1; j < 101; j++) {

        for (int i = 0; i < arraySize; i++) {
            A[i] = rand() % 9999 + 1;

        }

        //cout << "\nINTRO SORT" << endl;

        clock_t start = clock();
        quickSort(A, low, high);
        clock_t stop = clock();

        double czas = (double) (stop - start) / CLOCKS_PER_SEC;
        //cout << "CZAS " << czas << endl;


        myfile.open("rand[1000000].txt", ios::app);
        myfile << j << ". " << czas << endl;
        myfile.close();
    }


    delete A;
}