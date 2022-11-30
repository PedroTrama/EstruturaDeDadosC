#include <stdio.h>

void print(int v[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("](%d)\n",n);
}

int max(int v[],int n){
    int m=0;
    for(int i=1;i<n;i++){
        if(v[i]>v[m]){
            m=i;
        }
    }
    return m;
}

void selecaoRecursivo(int v[],int n){
    int m,aux;
    if(n<2){
        return;
    }
    m = max(v,n);
    aux = v[m];
    v[m] = v[n-1];
    v[n-1]=aux;
    print(v,n);
    selecaoRecursivo(v,n-1);
}

void selecaoIterativo(int v[],int n){
    int m,aux;
    while(n>1){
        m = max(v,n);
        aux = v[m];
        v[m] = v[n-1];
        v[n-1]=aux;
        print(v,n);
        n--;
    }
}

void bolhaRecursiva(int v[],int n){
    if(n<2){
        return;
    }
    int aux;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
        print(v,n);
    }
    bolhaRecursiva(v,n-1);
    
}

void bolhaIterativa(int v[],int n){
    int aux;
    while(n>2){
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
            print(v,n);
        }
        n--;
    }
    
}

void insercaoRec(int v[],int n){
    int lixo=-1;
    if(n<2){
        return ;
    }
    
    insercaoRec(v,n-1);
    
    int aux = v[n-1];
    v[n-1]=lixo;
    int i = n-2;
    print(v,n);
    while(i>=0&&v[i]>aux){
        v[i+1]=v[i];
        v[i] = lixo;
        i--;
        print(v,n);
    }
    v[i+1]=aux;
    print(v,n);
}


void insercaoIterativo(int v[],int N){
    int lixo=-1;

    int n=2;
    
    while(n<=N){
        int aux = v[n-1];
        v[n-1]=lixo;
        int i = n-2;
        print(v,n);
        while(i>=0&&v[i]>aux){
            v[i+1]=v[i];
            v[i] = lixo;
            i--;
            print(v,n);
        }
        v[i+1]=aux;
        print(v,n);
        n++;
    }
    
    
    
}

int main() {
    int n=7;
    int v[] = {9,2,4,0,1,4,3};
    //print(v,n);
    insercaoIterativo(v, n);
    //print(v,n);
}