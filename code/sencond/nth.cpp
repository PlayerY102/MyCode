#include <stdio.h>
#include <algorithm>
#define max_size 3000007
long long a[max_size];
int main(){
    int A,B,C,k;
    while(scanf("%d %d %d %lld %d",&A,&B,&C,a+1,&k)!=EOF){
        for(int i=2;i<=3000000;i++){
            a[i] = ((1LL * a[i - 1] * A ^ B) + C) % 1000000007;
        }
        std::nth_element(a+1,a+k,a+3000000);
        printf("%d\n",a[k]);
    }
}