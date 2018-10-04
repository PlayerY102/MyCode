#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct wood{
    int x;
    int h;
};
struct wood list[200];
double PI;
int comp(const void* a,const void* b){
    return ((struct wood*)a)->x-((struct wood*)b)->x;
}
double count(struct wood n1,struct wood n2){
    double r=((double)abs(n1.x-n2.x))/2;
    double h=(double)(n1.h<n2.h?n1.h:n2.h);
    return PI*r*r*h;
}
double max(int n){
    qsort(list,n,sizeof(struct wood),comp);
    double temp=0;
    int zero=0;
    while(list[zero].x<0){
        zero++;
    }
    for(int i=0;i<zero;i++){
        for(int j=n-1;j>=zero;j--){
            if(count(list[i],list[j])>temp){
                temp=count(list[i],list[j]);
            }
        }
    }
    if (list[zero].x==0){
        for(int i=n-1;i>zero;i--){
            if(count(list[zero],list[i])>temp){
                temp=count(list[zero],list[i]);
            }
        }
    }
    return temp;
}
int main()
{
    int n;
    PI=acos(-1);
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %d",&list[i].x,&list[i].h);
        }
        printf("%.3lf\n",max(n));
    }
    return 0;
}
