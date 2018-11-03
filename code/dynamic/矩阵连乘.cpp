#include<stdio.h>
#define max_size 307
int row[max_size];
int value[max_size][max_size];
int s[max_size][max_size];
int comp(int n){
    for(int i=0;i<=n;i++){
        value[i][i]=0;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            value[i][i+len-1]=(unsigned)-1>>1;
            for(int j=i;j<i+len-1;j++){
                int temp=value[i][j]+value[j+1][i+len-1]+row[i]*row[j+1]*row[i+len];
                if(temp<=value[i][i+len-1]){
                    value[i][i+len-1]=temp;
                    s[i][i+len-1]=j;
                }
            }
        }
    }
    return value[1][n];
}
void print_chain(int l,int r){
    if(l==r){
        printf("A%d",l);
    }
    else{
        printf("(");
        print_chain(l,s[l][r]);
        print_chain(s[l][r]+1,r);
        printf(")");
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n+1;i++){
            scanf("%d",row+i);
        }
        printf("%d\n",comp(n));
        print_chain(1,n);
        printf("\n");
    }

    return 0;
}
