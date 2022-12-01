//O(n²)
//https://lh5.googleusercontent.com/_oLwPF5ZvaZZ4pGD-HvSUSw6nTwwHjUwcLpNigUvb24-PKNwjMUwXcWYWf2wp4HopzHkh9JVmZd_AFYP4HjSYelidbw4FRo1fHrWV3KxbFM13xlRLALb-y-EbLhEmln11lhwEZPV
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

