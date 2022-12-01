//O(n²)
//divide o vetor em vetores menores e vai trocando de lugar os maiores e menores


void insercaoRec(int v[],int n){
    int lixo = -1;
    if(n<2){
        return ;
    }
    insercaoRec(v,n-1);
    //valor minimo pra entrar aqui é 3
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