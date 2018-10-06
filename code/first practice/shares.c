#include<stdio.h>
long long inp[1000000];
long long b[1000000];
long long outp;
void merge(int l,int r){
    int mid=(l+r)/2;
    if((inp[r]-inp[l])>outp){
        outp=inp[r]-inp[l];
    }
    int i=l;
    int j=mid+1;
    int index=l;
    while(i<=mid&&j<=r){
        if(inp[i]<=inp[j]){
            b[index++]=inp[i++];
        }
        else{
            b[index++]=inp[j++];
        }
    }
    while(i<=mid){
        b[index++]=inp[i++];
    }
    for(i=l;i<index;i++){
        inp[i]=b[i];
    }
}
void msort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        msort(l,mid);
        msort(mid+1,r);
        merge(l,r);
    }
    
}
int main()
{
    int n;
    long long earn;
    while(scanf("%d",&n)!=EOF){
        outp=0;
        for(int i=0;i<n;i++){
            scanf("%lld",inp+i);
        }
        msort(0,n-1);
        if(!outp){
            printf("No solution\n");
        }
        else{
            printf("%d\n",outp);
        }
    }
    return 0;
}
