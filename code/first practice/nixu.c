#include<stdio.h>
int inp[20000];
int temp[20000];
int b[20000];
long long ans;
void merge(int l,int r){
    int mid=(l+r)/2;
    for(int i=l,j=mid+1;i<=mid;i++){
        while(inp[i]>inp[j]&&j<=r){
            j++;
        }
        ans+=j-mid-1;
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
    int n,t;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        scanf("%d",&t);
        int x,y;
        for(int i=0;i<n;i++){
            temp[i]=inp[i];
        }
        while(t--){
            ans=0;
            scanf("%d %d",&x,&y);
            msort(x,y);
            printf("%lld\n",ans);
            for(int i=x;i<=y;i++){
                inp[i]=temp[i];
            }
        }
    }
    return 0;
}
