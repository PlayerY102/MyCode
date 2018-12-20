#include <algorithm>
#include<stdio.h>
#include<string.h>
#include<complex>
#define max_l 410010
using namespace std;
const int maxl=2094153;
const double PI=acos(-1);
complex<double> a[maxl],b[maxl];
int rev[maxl];
void get_rev(int bit){
    for(int i=0;i<(1<<bit);i++){
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    }
}
void fft(complex<double> *a,int n,int dft){
    for(int i=0;i<n;i++){
        if(i<rev[i]){
            swap(a[i],a[rev[i]]);
        }
    }
    for(int step=1;step<n;step<<=1){
        complex<double> wn=exp(complex<double>(0,dft*PI/step));
        for(int j=0;j<n;j+=step<<1){
            complex<double> wnk(1,0);
            for(int k=j;k<j+step;k++){
                complex<double> x=a[k];
                complex<double> y=wnk*a[k+step];
                a[k]=x+y;
                a[k+step]=x-y;
                wnk*=wn;
            }
        }
    }
    if(dft==-1){
        for(int i=0;i<n;i++){
            a[i]/=n;
        }
    }
}
char s1[max_l];
char s2[max_l];
int result1[max_l];
int result2[max_l];
int result3[max_l];
void conv(int total,int *result){
    fft(a,total,1);
    fft(b,total,1);
    for(int i=0;i<total;i++){
        a[i]=a[i]*b[i];
    }
    fft(a,total,-1);
    for(int i=0;i<total;i++){
        result[i]=a[i].real()+0.5;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s%s",s1,s2);
    int bit=1;
    int total=2;
    int lenmax=n+m;
    while((1<<bit)<lenmax){
        bit+=1;
        total*=2;
    }
    get_rev(bit);
    for(int i=0,j=m-1;i<j;i++,j--){
        swap(s2[i],s2[j]);
    }
    for(int i=0;i<total;i++){
        a[i]=s1[i]=='R';
    }
    for(int i=0;i<total;i++){
        b[i]=s2[i]=='P';
    }
    conv(total,result1);
    for(int i=0;i<total;i++){
        a[i]=s1[i]=='P';
    }
    for(int i=0;i<total;i++){
        b[i]=s2[i]=='S';
    }
    conv(total,result2);
    for(int i=0;i<total;i++){
        a[i]=s1[i]=='S';
    }
    for(int i=0;i<total;i++){
        b[i]=s2[i]=='R';
    }
    conv(total,result3);
    int outp=0;
    for(int i=m-1;i<=n+m-2;i++){
        outp=max(outp,result1[i]+result2[i]+result3[i]);
    }
    printf("%d\n",outp);
    system("pause");
    return 0;
}
