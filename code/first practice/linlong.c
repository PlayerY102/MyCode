#include<stdio.h>
long long ans;
long long inp[20000];
long long b[20000];
long long temp[20000];
void merge(int l,int r){
    int mid=(l+r)/2;
    for(int i=l,j=mid+1;i<=mid;i++){
        while(inp[i]>2*inp[j]&&j<=r){
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
            scanf("%lld",temp+i);
        }
        scanf("%d",&t);
        int p,q;
        for(int i=0;i<n;i++){
            inp[i]=temp[i];
        }
        while(t--){
            ans=0;
            scanf("%d %d",&p,&q);
            if(p<q){
                msort(p,q);
                for(int i=p;i<=q;i++){
                    inp[i]=temp[i];
                }
            }
            else{
                msort(q,p);
                for(int i=q;i<=p;i++){
                    inp[i]=temp[i];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
