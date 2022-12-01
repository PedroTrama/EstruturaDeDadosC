//Buscar valores no vetor 

void embaralha(int *v, int n){
    int aux,pos;
    for(int i=0;i<n;i++){
        pos = rand()%n;
        aux = v[pos];
        v[pos] = v[i];
        v[i]  = aux;
    }
}
/**
 *int v[] - vetor de inteiros
 *int n - número de elementos do vetor
 *int k - chave de busca
 *Se a chave k ocorrer dentro do vetor v, devolve
 *a posição pos tal que v[pos]==k (primeira ocorrencia).
 *Devolve -1 se k não pertence a v.
 */
int buscaSequencial(int v[], int n, int k){
    for(int i=0;i<n;i++){
        if(v[i]==k){
            return i;
        }
    }
    return -1;
}


/**
 Complexidade Pior Caso Theta(log n)
 Melhor Caso O(1)
 Caso médio: Theta(log n)
 */
int buscaBinariaRecursiva(int v[],int ini, int fim,int key){
    if(fim<ini){
        //não encontrei
        return -1;
    }
    int meio = (ini+fim)/2;
    if(v[meio]==key){
        return meio;
    }
    if(key<v[meio]){
        return buscaBinariaRecursiva(v,ini,meio-1,key);
    }else{
        return buscaBinariaRecursiva(v,meio+1,fim,key);
    }
}

int buscaBinaria(int v[],int n,int key){
    int ini,fim,meio;
    ini = 0;
    fim = n;
    while(ini<=fim){
        //printf("[%d,%d] size=%d\n",ini,fim,fim-ini);
        meio = (ini+fim)/2;
        if(v[meio]==key){
            return meio;
        }
        if(key<v[meio]){
            fim = meio-1;
        }else{
            ini = meio+1;
        }
        
    }
    return -1;
}
