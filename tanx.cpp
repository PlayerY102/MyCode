#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[1000007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        int index=0;
        long long total=0;
        while(index<n-1){
            if(inp[index]<inp[index+1]){
                total+=inp[index+1]-inp[index];
            }
            index++;
        }
        printf("%lld\n",total);
    }
    return 0;
}
