#include<stdio.h>
#include<functional>
#include<algorithm>
#define max_size 100007
using namespace std;
int dp[max_size];
int dp2[max_size];
int main()
{
    int temp;
    int index=1;
    int index2=1;
    scanf("%d",&temp);
    dp[1]=temp;
    dp2[1]=-temp;
    while(scanf("%d",&temp)!=EOF){
        if(temp>=dp[index]){
            dp[++index]=temp;
        }
        else{
            *lower_bound(dp+1,dp+index+1,temp)=temp;
        }
        temp=-temp;
        if(temp>=dp2[index2]){
            dp2[++index2]=temp;
        }
        else{
            *lower_bound(dp2+1,dp2+index2+1,temp)=temp;
        }
    }
    printf("%d\n",index2);
    printf("%d\n",index);
    system("pause");
    return 0;
}
