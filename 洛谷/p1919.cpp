#include <algorithm>
#include<stdio.h>
#include<string.h>
#include<complex>
#define max_l 2*60007
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
int outp[max_l];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",s1,s2);
    int l1=strlen(s1);
    int l2=strlen(s2);
    
    int bit=1;
    int total=2;
    while((1<<bit)<2*n-1){
        bit+=1;
        total*=2;
    }
    get_rev(bit);
    for(int i=0;i<l1;i++){
        a[l1-i-1].real(s1[i]-'0');
    }
    for(int i=0;i<l2;i++){
        b[l2-i-1].real(s2[i]-'0');
    }
    fft(a,total,1);
    fft(b,total,1);
    for(int i=0;i<total;i++){
        a[i]=a[i]*b[i];
    }
    fft(a,total,-1);
    for(int i=0;i<2*n;i++){
        outp[i]+=(int)(a[i].real()+0.5);
        outp[i+1]+=outp[i]/10;
        outp[i]=outp[i]%10; 
    }
    int pos;
    for(pos=2*n;pos>0;pos--){
        if(outp[pos]!=0){
            break;
        }
    }
    for(int i=pos;i>=0;i--){
        printf("%d",outp[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
