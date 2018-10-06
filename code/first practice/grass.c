#include<stdio.h>
int main()
{
    long long n,ans;
    while(scanf("%lld",&n)!=EOF){
        ans=0;
        while(n){
            n=n/2;
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
