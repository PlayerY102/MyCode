#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char inp[57];
long long dp[57];
int search(int st){
    if(st>=strlen(inp)){
        return -1;
    }
    while(inp[st]!='#'&&inp[st]!='\0'){
        st++;
    }
    return st;
}
int judge1(int from){
    if(inp[from]=='0'){
        return 0;
    }
    return 1;
}
int judge2(int from){
    if(inp[from]=='0'){
        return 0;
    }
    if((inp[from]-'0')*10+inp[from+1]-'0'<=26){
        return 1;
    }
    return 0;
}
long long find_dp(int from,int to){
    if(inp[from]=='#'){
        return 0;
    }
    dp[to]=judge1(to);
    dp[to-1]=0;
    if(judge1(to-1)){
        dp[to-1]+=dp[to];
    }
    if(judge2(to-1)){
        dp[to-1]+=1;
    }
    for(int i=to-2;i>=0;i--){
        dp[i]=0;
        if(judge1(i)){
            dp[i]+=dp[i+1];
        }
        if(judge2(i)){
            dp[i]+=dp[i+2];
        }
    }
    return dp[from];
}
int main()
{
    while(scanf("%s",inp)!=EOF){
        if(strlen(inp)==1&&inp[0]=='0'){
            break;
        }
        long long result=1;
        int from=0;
        int to=0;
        while((to=search(to+1))!=-1){
            result=result*find_dp(from,to-1);
            from=to+1;
        }
        printf("%lld\n",result);
    }
    return 0;
}