#include<stdio.h>
#include<stdlib.h>
long long outp[300]={0};
long long seek(int n){
    if(n<=0){
        return 0;
    }
    if(outp[n]){
        return outp[n];
    }
    else{
        outp[n]=seek(n-1)+seek(n-2)-seek(n-12);
        return outp[n];
    }
}
int main(){
    int t,n;
    outp[1]=2;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",seek(n)-seek(n-20));
    }
}