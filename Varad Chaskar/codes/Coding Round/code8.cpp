#include<stdlib.h>
#include <iostream>

using namespace std;

struct N
{
    int d;
    struct N * l;
    struct N * r;

    N(int d){
        this -> d = d;
        this -> l = NULL;
        this -> r = NULL;
    }
};

int sz(N * rt){

    if(rt == NULL){
        return 0;
    }

    int ls = sz(rt -> l);
    int rs = sz(rt -> r);

    return ls + rs + 1;
}


int main(){
    N * rt = NULL;
    // initialize a bst here and send root

    int r = sz(rt);

    cout<<r<<endl;
}
