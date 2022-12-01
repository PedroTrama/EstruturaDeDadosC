//O(n²)
//Pega o maior valor e taca no final

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