#include<stdio.h>
long long inp[2000000];
long long temp[2000000];
long long count,l_num,r_num;
void merge(int l,int r){
    int mid=(l+r)/2;
    int fir,sen;
    fir=l;
    sen=l;
    for(int i=mid+1;i<=r;i++){
        while(inp[i]-inp[fir]>=l_num && fir<=mid){
            fir++;
        }
        while(inp[i]-inp[sen]>r_num && sen<=mid){
            sen++;
        }
        count+=fir-sen;
    }
    int a=l;
    int b=mid+1;
    int current=l;
    while(a<=mid&&b<=r){
        if(inp[a]<=inp[b]){
            temp[current++]=inp[a++];
        }
        else{
            temp[current++]=inp[b++];
        }
    }
    while(a<=mid){
        temp[current++]=inp[a++];
    }
    if(b<=r){
        r=b-1;
    }
    for(current=l;current<=r;current++){
        inp[current]=temp[current];
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
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        count=0;
        scanf("%d %lld %lld",&n,&l_num,&r_num);
        for(int i=0;i<n;i++){
            scanf("%lld",inp+i);
        }
        msort(0,n-1);
        printf("%lld\n",count);
    }
    return 0;
}
