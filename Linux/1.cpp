#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
const unsigned long long int MAX_SIZE = 130000; //518400
ofstream f("RES.txt", ios::out);
void print_arr(long long int *arr,  long long int l)
{
    for (long long int i = 0; i < l; i++)
    {
        if (i != l - 1) {
            f <<  arr[i] << " " ;
        }
        else {
            f << arr[i] << endl;
            cout << "WORKED..." << endl;
        }

    }
}

void heapify(long long int* array, long long int n, long long int i)
{
    long long int largest = i;
    long long int l = 2*i + 1;
    long long int r = 2*i + 2;

    if ((l < n) && (array[l] > array[largest])){
        largest = l;
    }
    if ((r < n) && (array[r] > array[largest])){
        largest = r;
    }
    if (largest != i)
    {
        swap(array[i], array[largest]);
        //print_arr(array, n);
        heapify(array, n, largest);
    }
}

void heapSort(long long int* array, long long int n)
{
    long long int count = 0;
    for (long long int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for (long long int i=n-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        count++;
        cout << count << endl;
        if (count % 10000 == 0) {
            print_arr(array, n);
        }
        heapify(array, i, 0);
    }
}

int main() {
    long long int a[MAX_SIZE];
    long long int a1[MAX_SIZE];
    for(long long int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = i;
    }
    vector<long long int> v(a, a+MAX_SIZE);
    random_shuffle(v.begin(), v.end());
    for(long long int i = 0; i < MAX_SIZE; i++)
    {
        a1[i] = v.at(i);
    }
    long long int index = 0;

/*
  //Сортировка гномиком
    while (index < MAX_SIZE) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
        print_arr(arr, MAX_SIZE);
    }
*/
/*
 //Сортировка пузырьком
    for (int i = 0; i < MAX_SIZE; i++){
        for (int j=0; j<MAX_SIZE-1; j++){
            if (arr[j]>arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                print_arr(arr, MAX_SIZE);
            }
        }
    }
*/
/*
 //СОртировка расчёской
     int n = MAX_SIZE;
     int tmp, k;
     int step = n - 1;
     while(n > 1) {
          step /= 1.247;
          if (step < 1){
            step = 1;
          }
          k = 0;
          for (int i = 0; i + step < n; i++) {
               if(arr[i] > arr[i + step]) {
                tmp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = tmp;
                k = i;
                print_arr(arr, MAX_SIZE);
               }
          }
          if (step == 1){
            n = k + 1;
          }
     }

*/

/*
 //Сортировка вставкой
    int i, key, j;
    int n = MAX_SIZE;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            print_arr(arr, MAX_SIZE);
        }
        arr[j + 1] = key;
    }
*/


 //Сортировка Heap(Кучей)
    heapSort(a1, MAX_SIZE);
}
