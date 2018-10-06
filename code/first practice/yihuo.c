#include <stdio.h>
int inp;
int x[1000007];
int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&inp);
            x[i]=x[i-1]^inp;
        }
        scanf("%d",&k);
        int i,j;
        while(k--){
            scanf("%d %d",&i,&j);
            if(i>j){
                int temp=i;
                i=j;
                j=temp;
            }
            printf("%d\n",x[j]^x[i-1]);
        }
    }
    return 0;
}
