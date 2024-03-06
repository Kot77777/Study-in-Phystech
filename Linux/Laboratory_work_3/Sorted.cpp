#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
const long long int MAX_SIZE = 128640; //518400
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
        if (count % 1000 == 0) {
            print_arr(array, n);
        }
        heapify(array, i, 0);
    }
}
void SpeedBubble_sort(long long int* arr, long long int n) {

     long long int count = 0;
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
                count++;
                cout << count << endl;
                if (count % 8096 == 0) {
                    print_arr(arr, n);
                }
               }
          }
          if (step == 1){
            n = k + 1;
          }
     }
}
void shellSort(long long int* arr, long long int n) {
long long int count = 0;
 for (int gap = n / 2; gap > 0; gap /= 2) {
     for (int i = gap; i < n; i++) {
         int temp = arr[i];
         int j;
         for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
            arr[j] = arr[j - gap];
            count++;
            cout << count << endl;
            if (count % 41156 == 0) {
                print_arr(arr, n);
            }
         }
        arr[j] = temp;
        count++;
        cout << count << endl;
        if (count % 41156 == 0) {
            print_arr(arr, n);
        }
     }
 }
}

long long int findMax(long long int* arr, long long int n)
{
    long long int i,max=arr[0],cnt=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    while(max>0)
    {
        cnt++;
        max=max/10;
    }

    return cnt;
}

void bucketSort(long long int* arr, int *bucket[], long long int n)
{
    long long int count = 0;
    static long long int i,j[10],k,l,d=1;
    long long int c;
    c=findMax(arr,n);

    for(int m=0;m<c;m++)
    {
        for(i=0;i<10;i++)
            j[i]=0;
        for(i=0;i<n;i++)
        {
            k=(arr[i]/d)%10;
            bucket[k][j[k]]=arr[i];
            j[k]++;
        }

        l=0;
        for(i=0;i<10;i++)
        {
            for(k=0;k<j[i];k++)
            {
                arr[l]=bucket[i][k];
                count++;
                cout << count << endl;
                if (count % 6030 == 0) {
                    print_arr(arr, n);
                }
                l++;
            }
        }
        d*=10;
    }
}


long long int count_4quick = 0;
void swap_X(long long int* arr , long long int pos1, long long int pos2){
	long long int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(long long int* arr, long long int low, long long int high, long long int pivot){
	long long int i = low;
	long long int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap_X(arr,i,j);
			i++;
			j++;
			count_4quick++;
			cout << count_4quick << endl;
			if (count_4quick % 10551 == 0) {
                print_arr(arr, MAX_SIZE);
			}
		}
	}
	return j-1;
}

void quickSort(long long int* arr, long long int low, long long int high){
	if(low < high){
	long long int pivot = arr[high];
	long long int pos = partition(arr, low, high, pivot);

	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

int main() {
    int *bucket[10];
    for(int i=0;i<10;i++){
        bucket[i]=new int[MAX_SIZE];
    }
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


    // Сортировка Шелла
    //shellSort(a1, MAX_SIZE);

    //СОртировка расчёской
    //SpeedBubble_sort(a1, MAX_SIZE);

    //Сортировка Heap(Кучей)
    //heapSort(a1, MAX_SIZE);

    // Сортировка ведром
    //bucketSort(a1,bucket,MAX_SIZE);
    
    //Сортировка Хоара
    //quickSort(a1, 0, MAX_SIZE - 1);
}
