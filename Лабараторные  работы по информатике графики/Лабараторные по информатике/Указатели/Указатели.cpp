#include <iostream>
using namespace std;

void swap_(int* a, int* b){
    int* c = new int;
    *c = *a;
    *a = *b;
    *b = *c;
    delete c;
}
int main(){
    int b = 47;
    int* a = new int; //выделить память
    int* c;
    c = &b;

    *a = 5;
    int m = 5;
    cout << *a << endl;
    cout << m << endl;

    int x = 1;
    int* y = &x;
    (*y)++;
    cout << x << endl;

    int* e = (int*)malloc (1 * sizeof(int)); // выделить память и вернуть войд
    int* n = (int*)calloc (10, sizeof(int)); // выделить память и вернуть войд
    n[5] = 100;

    int* l = new int[10]; // почти тоже что и int a[10];

    for(int i = 0; i < 10 ; i++){
        l[i] = 2 * i;
    }

    delete[] l;

    int p = 1, f = 2;
    swap_(&p, &f);
    cout << p << f;
    return 0;
}
