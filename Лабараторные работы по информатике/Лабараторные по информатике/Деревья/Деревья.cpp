#include <iostream>
using namespace std;

struct Vertice{
    int value;
    Vertice* right;
    Vertice* left;
};

int main(){
    Vertice* r = new Vertice;
    r->value = 0;
    r->right = r->left = NULL;

    Vertice* l = new Vertice;
    l->value = 47;
    l->right = l->left = NULL;
    r->left = l;

    Vertice* r1 = new Vertice;
    r1->value = 2;
    r1->right = r1->left = NULL;
    r->right = r1;

    cout << r->right->value;
    return 0;
}
