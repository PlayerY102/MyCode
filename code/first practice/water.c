#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI acos(-1)
struct wood{
    int h;
    int x;
};
struct wood l[200],r[200];
int main()
{
    int n,x,h;
    int max;
    while(scanf("%d",&n)!=EOF){
        int i=0,j=0;
        while(n--){
            scanf("%d %d",&x,&h);
            if(x<0){
                l[i].x =x;
                l[i].h=h;
                i++;
            }
            else if(x>0){
                r[j].x=x;
                r[j].h=h;
                j++;
            }
            else{
                l[i].x =x;
                l[i].h=h;
                i++;
                r[j].x=x;
                r[j].h=h;
                j++;
            }
        }
        max=0;
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                int h_min=(l[a].h<r[b].h?l[a].h:r[b].h);
                int temp=(r[b].x-l[a].x)*(r[b].x-l[a].x)*h_min;  
                max=max>temp?max:temp;
            }
        }
        printf("%.3lf\n",max*PI*0.25);
    }
    return 0;
}
