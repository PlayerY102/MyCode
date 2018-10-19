#include<stdio.h>
#define max_size 100007
int father[max_size];
int count[max_size];
int find_fa(int n){
    if(father[n]!=n){
        father[n]=find_fa(father[n]);
    }
    return father[n];
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        int fx=find_fa(x);
        int fy=find_fa(y);
        if(fx!=fy){
            father[fy]=fx;
        }
    }
    for(int i=0;i<n;i++){
        int fa=find_fa(i);
        count[fa]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(count[i]>ans){
            ans=count[i];
        }
    }
    printf("%d",ans);
    return 0;
}
