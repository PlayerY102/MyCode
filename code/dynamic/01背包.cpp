#include<stdio.h>
#include<algorithm>
#define max_size 307
#define max_time 20000
using namespace std;
int value[max_size];
int tim[max_size];
int outp[max_time];
int main(){
    int T,K;
    while(scanf("%d %d",&T,&K)!=EOF){
        for(int i=0;i<K;i++){
            scanf("%d %d",value+i,tim+i);
        }
        for(int i=0;i<K;i++){
            for(int j=T;j>=tim[i];j--){
                outp[j]=max(outp[j-tim[i]]+value[i],outp[j]);
            }
        }
        printf("%d\n",outp[T]);
    }
}