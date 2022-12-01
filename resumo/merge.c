//O(n log n)
//Separa o vetor em dois vetores menores, ordena eles e depois junta eles
//https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Merge_sort_algorithm_diagram.svg/1024px-Merge_sort_algorithm_diagram.svg.png

void merge(int *v1,int n1,int *v2,int n2,int *v){
    int top1=0,top2=0,top=0;
    while(top1<n1 && top2<n2){
        if(v1[top1]<v2[top2]){
            v[top++]=v1[top1++];
        }else{
            v[top++]=v2[top2++];
        }
    }
    while(top1<n1){
        v[top++]=v1[top1++];
    }
    while(top2<n2){
        v[top++]=v2[top2++];
    }
}

void mergeSort(int v[],int n){
    if(n>1){
        int n1,n2;
        n1 = n/2;
        n2 = n-n1;
        int *v1,*v2;
        v1 = (int *)malloc(sizeof(int)*n1);
        v2 = (int *)malloc(sizeof(int)*n2);

        for(int i=0;i<n1;i++){
            v1[i]=v[i];
        }
        for(int i=0;i<n2;i++){
            v2[i]=v[n1+i];
        }

        mergeSort(v1,n1);
        mergeSort(v2,n2);
        merge(v1,n1,v2,n2,v);
        free(v1);
        free(v2);
    }
}