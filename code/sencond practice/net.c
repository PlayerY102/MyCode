#include <stdio.h>
#include <stdlib.h>
#define max_size 10007
int father[max_size];
int find_fa(int n){
    if(father[n]==-1){
        return n;
    }
    else{
        father[n]=find_fa(father[n]);
        return father[n];
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        father[i]=-1;
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
    int count=0;
    for(int i=1;i<=n;i++){
        if(father[i]==-1){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
