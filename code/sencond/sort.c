#include<stdio.h>
#include<stdlib.h>
#define max_size 1000007
int comp(const void* a,const void* b){
    return *(int *)a-*(int*)b;
}
int inp[max_size];
int L,R;
long long ans;
void find(int n){
    int fi=1,se=1;
    for(int i=1;i<=n;i++){
        while(inp[fi]-inp[i-1]<L&&fi<=n){
            fi++;
        }
        while(inp[se]-inp[i-1]<=R&&se<=n){
            se++;
        }
        ans+=se-fi;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        int n;
        scanf("%d %d %d",&n,&L,&R);
        for(int i=1;i<=n;i++){
            scanf("%d",inp+i);
            inp[i]=inp[i]+inp[i-1];
        }
        qsort(inp+1,n,sizeof(int),comp);
        find(n);
        printf("%lld\n",ans);
    }
    return 0;
}
