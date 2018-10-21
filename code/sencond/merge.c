#include<stdio.h>
#define max_size 1000007
long long inp[max_size];
long long temp[max_size];
int L,R;
long long ans;
void merge(int l,int r){

    int mid=(l+r)/2;
    int i=l,j=mid+1;
    int st=j,fi=j;
    for(i=l;i<=mid;i++){
        while(inp[st]-inp[i]<L&&st<=r){
            st++;
        }
        while(inp[fi]-inp[i]<=R&&fi<=r){
            fi++;
        }
        ans+=fi-st;
    }
    i=l;j=mid+1;
    int index=l;
    while(i<=mid&&j<=r){
        if(inp[i]<inp[j]){
            temp[index++]=inp[i++];
        }
        else{
            temp[index++]=inp[j++];
        }
    }
    while(i<=mid){
        temp[index++]=inp[i++];
    }
    while(j<=r){
        r=j-1;
    }
    for(int i=l;i<=r;i++){
        inp[i]=temp[i];
    }
}
void msort(int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    msort(l,mid);
    msort(mid+1,r);
    merge(l,r);
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
            scanf("%lld",inp+i);
            if(i>0){
                inp[i]=inp[i]+inp[i-1];
            }
        }
        msort(0,n);
        printf("%lld\n",ans);
    }
    return 0;
}
