//ORDENA PILHA COM BUBBLE
int ordenaPilha(int * vetor[], int n, Pilha *p){
    for(int i=0; i<n; i++){
        vetor[i] = pop(p);
    }
    bolhaIterativa(vetor, n);
} 
