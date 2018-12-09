#include<bits/stdc++.h>
struct int128
{
    long long hig;
    long long low;
};//定义int128
long long p=1e18;//作mod用
int128 max(int128 a,int128 b)
{
    if(a.hig>b.hig) return a;
    if(a.hig<b.hig) return b;//高位比较
    if(a.low>b.low) return a;
    if(a.low<b.low) return b;//低位比较
    return a;//相等时还要返回一个值
}
int128 operator + (int128 a,int128 b)//重载运算符
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low+b.low;
    k.hig=k.low/p+a.hig+b.hig;//防止溢出
    k.low%=p;
    return k;
}
int128 operator * (int128 a,int b)
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low*b;
    k.hig+=k.low/p+b*a.hig;//与上同理
    k.low%=p;
    return k;
}
void int128_print(int128 a){
    if(a.hig==0){
        printf("%lld\n",a.low);
    }
    else{
        printf("%lld%018lld\n",a.hig,a.low);
    }
}
