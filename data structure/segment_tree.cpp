#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ina{
    int a,b;
};
typedef struct vector v;
typedef struct ina k;
struct vector{
    k* arr;
    int size;
    int cap;
};
void vector_create(v* vect,int s){
    vect->arr=malloc(sizeof(k)*s);
    vect->size=s;
    vect->cap=s;
}
void vector_copy(v* a,v* b){
    a->arr=b->arr;
    a->size=b->size;
    a->cap=b->cap;
}
void push_back(v* vect,k data){
    if(vect->size==vect->cap){
        v tmp;
        int siz=vect->size;
        vector_create(&tmp,2*vect->size);
        for(int i=0;i<vect->size;i++){
            tmp.arr[i]=vect->arr[i];
        }
        vect->arr=tmp.arr;
        vect->size=tmp.size;
        vect->cap=tmp.cap;
        vect->size=siz+1;
        vect->arr[siz]=data;
    }
    else{
        vect->arr[vect->size]=data;
        vect->size++;
    }
}
bool empty(v a){
    return a.size==0;
}
void pop_back(v* a){
    if(!empty(*a)){
        a->size--;
    }
}
void print(v a){
    for(int i=0;i<a.size;i++){
        printf("%d ",a.arr[i]);
    }
    printf("\n");
}
int main()
{
    v a;
    vector_create(&a,10);
    for(int i=0;i<a.size;i++){
        a.arr[i]=i;
    }
    print(a);
    for(int i=0;i<100;i++)
        push_back(&a,i);
    pop_back(&a);
    push_back(&a,111);
    print(a);
}