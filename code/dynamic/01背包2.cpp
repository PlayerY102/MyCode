#include <stdio.h>
#include <algorithm>
#define max_num 307
#define max_we 20007
using namespace std;
int w[max_num];
int v[max_num];
int b[max_we];
int main(){
    int T,K;
    while(scanf("%d %d",&T,&K)!=EOF){
        for(int i=0;i<K;i++){
            scanf("%d %d",v+i,w+i);
        }
        for(int i=0;i<=T;i++){
            b[i]=0;
        }
        for(int i=0;i<K;i++){
            for(int j=T;j>=w[i];j--){
                b[j]=max(b[j],b[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",b[T]);
    }

}