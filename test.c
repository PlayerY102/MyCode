#include<stdio.h>
void show(unsigned char* start,int len){
    int i;
    for(i=len-1;i>=0;i--){
        printf("%.2x",start[i]);
    }
    printf("\n");
}
int main()
{
    short sx=0xFFFF;
    unsigned real=sx;
    int A_temp=sx;
    unsigned A_out=A_temp;
    unsigned short B_temp=sx;
    unsigned int B_out=B_temp;
    printf("sx is ");
    show((unsigned char*)&sx,sizeof(sx));
    printf("A's ans is ");
    show((unsigned char*)&A_out,sizeof(A_out));
    printf("B's ans is ");
    show((unsigned char*)&B_out,sizeof(B_out));
    printf("The real ans is ");
    show((unsigned char*)&real,sizeof(real));
    getchar();
    return 0;
}
