#include<stdio.h>
#include<algorithm>
#define mod 100007
long long inv(long long a, long long m) {
    if (a == 1)return 1;
    return inv(m % a, m) * (m - m / a) % m;
}
int main()
{
    int t;
    scanf("%d\n",&t);
    long long inv24=inv(24,mod);
    while(t--){
        long long x;
        scanf("%lld",&x);
        x=x%mod;
        long long ans=(x+mod-6)%mod;
        ans=((x*ans)%mod+23)%mod;
        ans=((x*ans)%mod+mod-18)%mod;
        ans=((x*ans)%mod+24)%mod;
        ans=(ans*inv24)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
