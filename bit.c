#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max_len 1000000
int count_dif(short* a, short *b,int len){
    int temp=0;
    int i;
    for(i=0;i<len;i++){
        temp+=a[i]^b[i];
    }
    return temp;
}
int count_1(short* a,int len){
    int temp=0;
    int i;
    for(i=0;i<len;i++){
        temp+=a[i];
    }
    return temp;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    short* a;
    short* b;
    short* c;
    a=(short *)malloc(sizeof(short)*max_len);
    b=(short *)malloc(sizeof(short)*max_len);
    c=(short *)malloc(sizeof(short)*max_len);
    int len;
    char temp;
    int result;
    while(n--){
        len=0;
        while(scanf("%c",&temp)!=EOF){
            if(temp=='\n'){
                break;
            }
            else if(temp=='1'||temp=='0'){
                b[len++]=temp-'0';
            }
        }
        len=0;
        while(scanf("%c",&temp)!=EOF){
            if(temp=='\n'){
                break;
            }
            else if(temp=='1'||temp=='0'){
                a[len++]=temp-'0';
            }
        }
        int count_d=count_dif(a,b,len);
        int count_a1=count_1(a,len);
        int count_b1=count_1(b,len);
        if(count_b1==0||count_b1==len){
            result=-1;
        }
        else{
            //printf("count_d=%d count_a1=%d count_b1=%d\n",count_d,count_a1,count_b1);
            result=(count_d+abs(count_a1-count_b1))/2;
        }
        printf("%d\n",result);
    }
    return 0;
}
