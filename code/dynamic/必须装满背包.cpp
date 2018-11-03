#include<stdio.h>
#include<memory.h>
#define max_num 307
#define max_wei 20007
int val[max_num];
int wei[max_num];
int outp[max_wei];
int main()
{
    int P,N;
    while(scanf("%d %d",&P,&N)!=EOF){
        for(int i=0;i<N;i++){
            scanf("%d %d",val+i,wei+i);
        }
        memset(outp,-1,sizeof(outp));
        outp[0]=0;
        for(int i=0;i<N;i++){
            for(int j=P;j>=wei[i];j--){
                if(outp[j-wei[i]]!=-1 && outp[j-wei[i]]+val[i]>outp[j]){
                    outp[j]=outp[j-wei[i]]+val[i];
                }
            }
        }
        if(outp[P]==-1){
            printf("jpx\n");
        }
        else{
            printf("%d\n",outp[P]);
        }
    }
    return 0;
}
