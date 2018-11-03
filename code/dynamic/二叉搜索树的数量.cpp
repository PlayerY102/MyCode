#include<stdio.h>
int numTrees(int n) {
        if(n==0){
            return 0;
        }
        int* outp=new int[n+7];
        outp[0]=1;
        outp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                outp[i]+=outp[j]*outp[i-j-1];
            }
        }
        return outp[n];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=0){
        printf("%d\n",numTrees(n));
    }
    return 0;
}
