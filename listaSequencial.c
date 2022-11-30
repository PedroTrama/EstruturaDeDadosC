#include <stdio.h>
#include <stdlib.h>


typedef struct ListaSeq{
    int *v;
    int MAX;
    int top;
}ListaSeq;

ListaSeq * newListaSeq(int max){
    ListaSeq * f = (ListaSeq*)malloc(sizeof(ListaSeq));
    f->top = 0;
    f->MAX = max;
    f->v = (int *)malloc(sizeof(int)*max);
    for(int i=0;i<max;i++){
        f->v[i]=-1;
    }
    return f;
}



void printSeq(ListaSeq *li){
    printf("[");
    for(int i = 0;i<li->top;i++){
        printf("%d",li->v[i]);
        if(i<li->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

int main(){
    ListaSeq * aux = newListaSeq(100);
    aux->v[aux->top++] = 10;
    aux->v[aux->top++] = 20;
    printSeq(aux);

}
