#include <iostream>
using namespace std;

int main(){
    unsigned int u, u2;
    cin >> u >> u2;

    unsigned int *p = &u, *p2 = &u2;
    cout << *p + *p2;
    return 0;
}
