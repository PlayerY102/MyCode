#include<stdio.h>
#include<string.h>
int main()
{
    long long inp;
    scanf("%lld",&inp);
    printf("%lld",((inp+1)>>1)+1);
    return 0;
}
