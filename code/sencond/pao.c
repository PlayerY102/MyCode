#include <stdio.h>
#include <stdlib.h>
int comp(const void* a,const void *b){
    return *(int*)b-*(int*)a;
}
#define max_size 1000007
int inp[max_size];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        int i=n-1;
        long long outp=0;
        while(i>0){
            qsort(inp,i+1,sizeof(int),comp);
            inp[i-1]=inp[i]+inp[i-1];
            outp+=inp[i-1];
            i=i-1;
        }
        printf("%lld\n",outp);
    }
    return 0;
}
