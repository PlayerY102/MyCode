#include<stdio.h>
#define max_size 100007
int count[100007];
int main()
{
    int n,t;
    while(scanf("%d %d",&n,&t)!=EOF){
        for(int i=0;i<max_size;i++){
            count[i]=0;
        }
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            count[num]++;
        }
        while(t--){
            int ask;
            scanf("%d",&ask);
            printf("%d ",count[ask]);
        }
        printf("\n");
    }
    return 0;
}
