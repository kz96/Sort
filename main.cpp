#include <iostream>
#include <ctime>

using namespace std;

void merge(int A[], int low, int high, int mid) {

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

void mergeSort (int A[], int low, int high) {

    if (low < high){
        int mid;
        mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, low, high, mid);
    }
}

void quickSort (int A[], int low, int high) {
    int mid = A[(low + high) / 2];
    int i,j,k;

    i=low;
    j=high;

    do {
        while (A[i] < mid) {
            i++;
        }

        while (A[j] > mid) {
            j--;
        }

        if (i <= j) {
            k = A[i];
            A[i] = A[j];
            A[j] = k;
            i++;
            j--;
        }
    }
    while (i <= j);

    if (j > low) {
        quickSort(A, low, j);
    }
    if (i < high) {
        quickSort(A, i, high);
    }
}

int main() {
    srand(time(NULL));

    int arraySize;
    cout << "Podaj dlugosc kolejki" << endl;
    cin >> arraySize;

    int *A, *A1;
    A = new int [arraySize];
    A1 = new int [arraySize];
    int low = 0;
    int high = arraySize - 1;

    for (int i = 0; i < arraySize; i++) {
        A[i] = rand() % 2000 + 1000;
        A1[i] = A[i];
        //cout << A[i] << endl;
    }

    cout << "-------- MERGE SORT -----------" << endl;

    clock_t start = clock();
    mergeSort(A,low,high);
    clock_t stop = clock();

    double czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << "CZAS " << czas << endl;


    cout << "-------- QUICK SORT -----------" << endl;

    start = clock();
    quickSort(A,low,high);
    stop = clock();

    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << "CZAS " << czas << endl;

    /*for (int i = 0; i < arraySize; i++) {
        cout << A[i] << endl;
    }*/

    delete A;
}