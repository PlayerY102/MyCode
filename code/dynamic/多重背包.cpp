#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define max_ca 30007
#define max_num 207
using namespace std;
int outp[max_ca];
void compack(int val,int wei,int v){
    for(int i=wei;i<=v;i++){
        outp[i]=max(outp[i],outp[i-wei]+val);
    }
}
void zeropack(int val,int wei,int v){
    for(int i=v;i>=wei;i--){
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
        memset(outp,0,sizeof(outp));
        for(int i=0;i<n;i++){
            int val,wei,tot;
            scanf("%d %d %d",&val,&wei,&tot);
            if(wei*tot>=v){
                compack(val,wei,v);
            }
            else{
                for(int j=1;j<tot;j=j*2){
                    zeropack(j*val,j*wei,v);
                    tot-=j;
                }
                zeropack(tot*val,tot*wei,v);
            }
        }
        printf("%d\n",outp[v]);
    }
    return 0;
}
