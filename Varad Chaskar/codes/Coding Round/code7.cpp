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

void ins(int d , struct N * rt){

    if(rt == NULL){
        return;
    }

    struct N * t = rt;

    while(t != NULL){
        if(d < t -> d){
            if(t -> l == NULL){
                t -> l = new N(d);
                return;
            }else{
                t = t -> l;
            }
        }else{
            if(t -> r == NULL){
                t -> r = new N(d);
                return;
            }else{
                t = t -> r;
            }
        }
    }

    return;
}

void main(){

    N * rt = NULL;
    ins(5 , rt);
}
