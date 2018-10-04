#include<stdio.h>
long long outp[100];
long long find(int n){
    if(n<0){
        return 0;
    }
    if(outp[n]){
        return outp[n];
    }
    else{
        // outp[n]=find(n-1)+find(n-2)+find(n-3)-find(n-6);
        outp[n]=find(n-1)+find(n-2)+find(n-4)+find(n-5);
        return outp[n];
    }
}
int main()
{
    int n;
    outp[0]=1;
    outp[1]=1;
    outp[2]=2;
    outp[3]=4;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",find(n));
    }
    return 0;
}
