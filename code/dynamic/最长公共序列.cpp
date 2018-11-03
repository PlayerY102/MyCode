#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max_size 10007
using namespace std;
char x[max_size],y[max_size];
int value[max_size][max_size];
int main(){
    while(scanf("%s",x)!=EOF){
        scanf("%s",y);
        int x_size=strlen(x);
        int y_size=strlen(y);
        for(int i=0;i<x_size;i++){
            value[i][0]=0;
        }
        for(int j=0;j<y_size;j++){
            value[0][j]=0;
        }
        for(int i=1;i<=x_size;i++){
            for(int j=1;j<=y_size;j++){
                if(x[i-1]==y[j-1]){
                    value[i][j]=value[i-1][j-1]+1;
                }
                else{
                    value[i][j]=max(value[i-1][j],value[i][j-1]);
                }
            }
        }
        for(int i=0;i<=x_size;i++){
            for(int j=0;j<=y_size;j++){
                printf("%d ",value[i][j]);
            }
            printf("\n");
        }
        printf("%d\n",value[x_size][y_size]);
    }
}
