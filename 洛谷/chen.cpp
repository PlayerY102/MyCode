#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char inp[107];
struct BigNum {
    int len;
    int num[100];
    BigNum(){
        len=0;
        memset(num,0,sizeof(num));
    }
    // BigNum operator * (BigNum &b){
    //     BigNum temp;
    //     for(int i=0;i<len;i++){
    //         for(int j=0;j<b.len;j++){
    //             temp.num[i+j]+=num[i]*b.num[j];
    //         }
    //     }
    //     temp.len=len+b.len-1;
    //     for(int i=0;i<temp.len;i++){
    //         num[i+1]+=num[i]/10;
    //         num[i]=num[i]%10;
    //     }
    //     if(num[temp.len]>0){
    //         temp.len++;
    //     }
    //     return temp;
    // }
    void operator=(int x){
        len=1;
        num[0]=x;
    }
};
BigNum operator * (BigNum &a,BigNum &b){
    BigNum temp;
    for(int i=0;i<a.len;i++){
        for(int j=0;j<b.len;j++){
            temp.num[i+j]+=a.num[i]*b.num[j];
        }
    }
    temp.len=a.len+b.len-1;
    for(int i=0;i<temp.len;i++){
        temp.num[i+1]+=temp.num[i]/10;
        temp.num[i]=temp.num[i]%10;
    }
    if(temp.num[temp.len]>0){
        temp.len++;
    }
    return temp;
}
BigNum dp[17][107];
BigNum trans(int from,int to){
    BigNum temp;
    temp.len=to-from+1;
    for(int i=temp.len-1;i>=0;i--){
        temp.num[i]=inp[to-i];
    }
    return temp;
}
BigNum MyMax(BigNum a,BigNum b){
    if(a.len!=b.len){
        return a.len>b.len?a:b;
    }
    else{
        for(int i=a.len-1;i>=0;i++){
            if(a.num[i]>b.num[i]){
                return a;
            }
            else if(a.num[i]<b.num[i]){
                return b;
            }
        }
    }
    return a;
}
void show(BigNum &a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.num[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",inp);
        int lenmax=strlen(inp)-1;
        for(int i=0;i<=lenmax;i++){
            dp[0][i]=trans(0,i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=lenmax;j++){
                dp[i][j]=0;
                for(int k=i-1;k<j;k++){
                    BigNum temp=trans(k+1,j);
                    dp[i][j]=MyMax(dp[i][j],dp[i-1][k]*temp);
                }
            }
        }
        show(dp[n][lenmax-1]);
    }
    return 0;
}
