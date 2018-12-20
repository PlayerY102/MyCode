#include<algorithm>
#include<stdio.h>
#include<math.h>
#define max_size 100007
using namespace std;
struct point{
    long long x;
    long long y;
    int q;
    char name[100];
    long long operator* (point b){
        return (long long)x*b.y-(long long)b.x*y;
    }
};
point points[max_size];
long long dist(point a){
    return (long long)a.x*a.x+(long long)a.y*a.y;
}
int quad(point a){
    if(a.x==0&&a.y==0){
        return 0;
    }
    else if(a.x>0&&a.y>=0){
        return 1;
    }
    else if(a.x<=0&&a.y>0){
        return 2;
    }
    else if(a.x<0&&a.y<=0){
        return 3;
    }
    else{
        return 4;
    }
}
bool cmp_angle(point a,point b){
    if(a.q!=b.q){
        return a.q<b.q;
    }
    long long temp=a*b;
    if(temp==0){
        return dist(a)<dist(b);
    }
    return temp>0;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s %lld %lld",points[i].name,&points[i].x,&points[i].y);
            points[i].q=quad(points[i]);
        }
        sort(points,points+n,cmp_angle);
        for(int i=0;i<n;i++){
            printf("%s\n",points[i].name);
        }
        printf("\n");
    }
    return 0;
}
