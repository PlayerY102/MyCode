#include<stdio.h>
#include<stdlib.h>
int main()
{
    const  int mod=1000000007;
    int n;
    long long total;
    char temp;
    scanf("%d\n",&n);
    while(n--){
        total=0;
        while(scanf("%c",&temp)!=EOF){
            if(temp=='\n'){
                break;
            }
            else if(temp>='0'&&temp<='7'){
                total=((total*8)%mod+temp-'0')%mod;
            }
        }
        printf("%lld\n",total);
    }
    return 0;
}