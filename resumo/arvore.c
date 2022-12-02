#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct No {
    int valor;
    struct No *esq, *dir;
}No;

No * newNo(int valor){
    No * no = (No *)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

typedef struct Tree {
    No * raiz;
}Tree;

Tree * newTree(){
    Tree * t = (Tree *)malloc(sizeof(Tree));
    t->raiz = NULL;
    return t;
}
/**
 Insere o valor ná árvore.
 no não pode ser NULL (por definição).
 */
void addNo(No* no, int valor){
    if(valor<=no->valor){
        //insere na sub-árvore à esquerda
        if(no->esq!=NULL){
            addNo(no->esq,valor);
        }else{
            no->esq = newNo(valor);
        }
    }else{
        //insere na sub-árvore à direita
        if(no->dir!=NULL){
            addNo(no->dir,valor);
        }else{
            no->dir = newNo(valor);
        }
    }
}

void addTree(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

void addTreeIt(Tree *t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
        return;
    }
    No * aux = t->raiz;
    int inseriu = FALSE;
    while(!inseriu){
        if(valor<aux->valor){
            if(aux->esq!=NULL){
                //descer para o ramo esquerdo
                aux=aux->esq;
            }else{
                aux->esq = newNo(valor);
                inseriu=TRUE;
            }
        }else{
            if(aux->dir!=NULL){
                //descer para o ramo direito
                aux=aux->dir;
            }else{
                aux->dir = newNo(valor);
                inseriu=TRUE;
            }
        }
    }
}

void printNo(No * no){
    if(no==NULL){
        return;
    }
    printNo(no->esq);
    printf("%d,",no->valor);
    printNo(no->dir);
}

void printTree(Tree *t){
    printf("[");
    printNo(t->raiz);
    printf("]\n");
}

typedef struct Lista{
    int *v;
    int top,max;
}Lista;

Lista * newLista(int max){
    Lista * l = (Lista *)malloc(sizeof(Lista));
    l->top = 0;
    l->max = max;
    l->v = (int *)malloc(sizeof(int)*max);
    return l;
}

void addLista(Lista *l,int valor){
    if(l->top==l->max){
        printf("Cheio\n");
    }
    l->v[l->top++]=valor;
}

void TreeToVector(No * no, Lista *l){
    if(no==NULL){
        return;
    }
    TreeToVector(no->esq,l);
    addLista(l,no->valor);
    TreeToVector(no->dir,l);
}

void freeLista(Lista *l){
    free(l->v);
    free(l);
}

void TreeSort(Lista *l){
    if(l->top<=1){
        return ;
    }
    Tree *t  = newTree();
    for(int i=0;i<l->top;i++){
        addTree(t,l->v[i]);
    }
    //deixar o vetor vazio.
    l->top=0;
    TreeToVector(t->raiz,l);
	// faltou dar free em t.
    
}

void printLista(Lista *l){
    printf("[");
    for(int i=0;i<l->top;i++){
        printf("%d",l->v[i]);
        if(i<l->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

int maximoRecursivo(No * no){
    return 0;
}

int maximoIt(No * no){
    if(no==NULL){
        printf("ERRO 396\n");
        exit(0);
    }
    No * aux = no;
    while(aux->dir!=NULL){
        aux = aux->dir;
    }
    return aux->valor;
}

int main(int argc, const char * argv[]) {
    
    Tree * t = newTree();
    
    addTreeIt(t, 6);
    addTreeIt(t, 8);
    addTreeIt(t, 2);
    addTreeIt(t, 10);
    addTreeIt(t, 7);
    addTreeIt(t, 1);
    addTreeIt(t, 3);
    
    
    
    printTree(t);
    
    printTreeXML(t);
    
    printf("Maximo %d\n",maximoIt(t->raiz));
     
     /*
    
    Lista *l = newLista(100);
    addLista(l, 3);
    addLista(l, 2);
    addLista(l, 1);
    addLista(l, 4);
    addLista(l, 5);
    addLista(l, 10);
    addLista(l, 0);
    
    TreeSort(l);
    printLista(l);
    
    
    */
    
    return 0;
}


void addNoT(Tree * t, int valor){
    if(t->raiz==NULL){
        t->raiz = newNo(valor);
    }else{
        addNo(t->raiz,valor);
    }
}

No * buscaRec(No *no,int valor){
    if(no==NULL){
        return NULL;
    }else{
        if(no->valor==valor){
            return no;
        }else{
            if(valor<no->valor){
                return buscaRec(no->esq,valor);
            }else{
                return buscaRec(no->dir,valor);
            }
        }
    }
}

No * buscaIterativa(No *no,int valor){
    No * aux = no;
    while(aux!=NULL){
        if(aux->valor==valor){
            return aux;
        }
        if(valor<aux->valor){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }
    return NULL;
}


void print(No *no){
    if(no!=NULL){
        print(no->esq);
        printf(" %d",no->valor);
        print(no->dir);
    }
}

void printT(Tree *t){
    if(t->raiz==NULL){
        printf("()");
    }else{
        print(t->raiz);
    }
    printf("\n");
}

void percurso(No * no,Lista *l){
    if(no!=NULL){
        percurso(no->esq,l);
        addL(l,no->valor);
        percurso(no->dir,l);
    }
}

void embaralha(Lista *l){
    for(int i=0;i<l->top;i++){
        int ran = rand()%l->top;
        int aux = l->v[i];
        l->v[i] = l->v[ran];
        l->v[ran]=aux;
    }
}

int size(No *t){
    if(t==NULL){
        return 0;
    }else{
        int sizeEsq = size(t->esq);
        int sizeDir = size(t->dir);
        return 1+sizeEsq+sizeDir;
    }
}

int altura(No *t){
    if(t==NULL){
        return -1;
    }else{
        int he = altura(t->esq);
        int hd = altura(t->dir);
        if(he>hd){
            return he+1;
        }else{
            return hd+1;
        }
    }
}


void ordenaL(Lista *l){
    if(l->top==0){
        return;
    }
    Tree * t = newTree();
    embaralha(l);
    for(int i=0;i<l->top;i++){
        addNoT(t,l->v[i]);
    }
    
    printf("ALTURA TREE: %d\n",altura(t->raiz));
    printf("SIZE TREE: %d\n",size(t->raiz));
    
    
    l->top = 0;
    percurso(t->raiz,l);
}


int minT(Tree * t){
    if(t->raiz==NULL){
        printf("Arvore Vazia\n");
        exit(0);
    }
    No * min = t->raiz;
    while(min->esq!=NULL){
        min=min->esq;
    }
    return min->valor;
}

int maxT(Tree * t){
    if(t->raiz==NULL){
        printf("Arvore Vazia\n");
        exit(0);
    }
    No * max = t->raiz;
    while(max->dir!=NULL){
        max=max->dir;
    }
    return max->valor;
}


int inter(Lista* l1, Lista *l2){
    
    Tree * t = newTree();
    embaralha(l2);
    for(int i=0;i<l2->top;i++){
        addNoT(t,l2->v[i]);
    }
    printf("ALTURA %d\n",altura(t->raiz));
    printXmlT(t);
    int intersec =0;
    for(int i=0;i<l1->top;i++){
        if(buscaIterativa(t->raiz,l1->v[i])!=NULL){
          intersec++;  
        }
    }
    
    return intersec;
}

void interseccaoX(){
    int n1 = 100;
    int n2 = 200;
    Lista *l1 = newLista(n1);
    Lista *l2 = newLista(n2);
    for(int i=0;i<n1;i++){
        addL(l1,i*5);
    }
    for(int i=0;i<n2;i++){
        addL(l2,i*5);
    }
    printf("Inter:%d\n",inter(l1,l2));
    exit(0);
    
}



int main()
{
    Tree * t = newTree();
    
    interseccaoX();
    
    //printT(t);
    
    //printf("hellow\n");
    
    int n = 100*1000;
    
    Lista * l = newLista(n);
    for(int i=0;i<n;i++){
        addL(l,i+1);
    } 
    
   
   clock_t start, end;
     double cpu_time_used;
     
     start = clock();
   
    
    //printL(l);
    
    
    ordenaL(l);
    
    
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("[%.3lfs]\n",cpu_time_used);
    
    
    
    l->top = 20;
    printL(l);
    
    /*
    
    addNoT(t,7);
    addNoT(t,6);
    addNoT(t,5);
    addNoT(t,3);
    addNoT(t,9);
    addNoT(t,10);
    addNoT(t,11);
    
    //printf("MIN %d\n",minT(t));
    //printf("MAX %d\n",maxT(t));
    
    //printXmlT(t);
    printT(t);
    */
    
    
}