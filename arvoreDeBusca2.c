#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No * esq;
    struct No * dir;
}No;

typedef struct Tree {
    No * raiz;
}Tree;

typedef struct Lista{
    int *v;
    int top,max;
}Lista;

Lista * newLista(int max){
    Lista * aux = (Lista *)malloc(sizeof(Lista));
    aux->top = 0;
    aux->max = max;
    aux->v = (int *)malloc(sizeof(int)*max);
    return aux;
}

void printL(Lista *l){
    printf("[");
    for(int i=0;i<l->top;i++){
        printf("%d",l->v[i]);
        if(i<l->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

void addL(Lista *l, int valor){
    if(l->top==l->max){
        printf("Lista cheia\n");
        exit(0);
    }
    l->v[l->top++]=valor;
}


No * newNo(int valor){
    No * aux = (No *)malloc(sizeof(No));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}
Tree * newTree(){
    Tree * aux  = (Tree *)malloc(sizeof(Tree));
    aux->raiz = NULL;
    return aux;
}
/** adiciona um elemento na árvore.
 * Assumo que t não é null.
 */ 
void addNo(No * t,int valor){
    if(valor<t->valor){
        //inserir esquerdo
        if(t->esq==NULL){
            t->esq = newNo(valor);
        }else{
            addNo(t->esq,valor);
        }
    }else{
        //inserir direito
        if(t->dir==NULL){
            t->dir = newNo(valor);
        }else{
            addNo(t->dir,valor);
        }
    }
    
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

void printXml(No * no, FILE * fp){
    fprintf(fp,"%d\n",no->valor);
    if(no->esq!=NULL){
        fprintf(fp,"<esq>\n");
        printXml(no->esq,fp);
        fprintf(fp,"</esq>\n");
    }
    if(no->dir!=NULL){
        fprintf(fp,"<dir>\n");
        printXml(no->dir,fp);
        fprintf(fp,"</dir>\n");
    }
}


void printXmlT(Tree *t){
    FILE * fp;
    fp = fopen("Tree.xml","w+");
    fprintf(fp,"<Tree>\n");
    if(t->raiz!=NULL){
        printXml(t->raiz,fp);
    }
    fprintf(fp,"</Tree>\n");
    fclose(fp);
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