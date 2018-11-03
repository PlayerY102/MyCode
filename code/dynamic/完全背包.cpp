#include<stdio.h>
#include<algorithm>
#define max_num 207
#define max_to 30007
using namespace std;
int outp[max_to];
void zeropack(int val,int wei,int v){
    for(int i=v;i>=wei;i--){
        outp[i]=max(outp[i],outp[i-wei]+val);
    }
}
void compack(int val,int wei,int v){
    for(int i=wei;i<=v;i++){
        outp[i]=max(outp[i],outp[i-wei]+val);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int v,n;
        scanf("%d %d",&v,&n);
        for(int i=0;i<=v;i++){
            outp[i]=0;
        }
        for(int i=0;i<n;i++){
            int val,wei,tot;
            scanf("%d %d %d",&val,&wei,&tot);
            if(wei*tot>=v||tot==233){
                compack(val,wei,v);
            }
            else{
                for(int j=1;j<tot;j=j*2){
                    zeropack(val*j,wei*j,v);
                    tot-=j;
                }
                zeropack(val*tot,wei*tot,v);
            }
        }
        printf("%d",outp[v]);
    }
    return 0;
}
