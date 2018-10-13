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
    unsigned int A=4294967295;
    int B=-1;
    printf("A is ");
    show((unsigned char*)&A,sizeof(A));
    printf("B is ");
    show((unsigned char*)&B,sizeof(B));
    getchar();
    return 0;
}
