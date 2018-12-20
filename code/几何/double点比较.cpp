#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
using namespace std;
int cmp(double x) {
	if (fabs(x) < 1e-9)return 0;
	if (x > 0)return 1;
	else return -1;
}
struct point{
    double x;
    double y;
    point operator-(point &b){
        point result;
        result.x=x-b.x;
        result.y=y-b.y;
        return result;
    }
    bool operator==(point &b){
        double tempx=x-b.x;
        double tempy=y-b.y;
        if(cmp(tempx)==0){
            if(cmp(tempy)==0){
                return true;
            }
        }
        return false;
    }
};
struct line{
    point a;
    point b;
};
double det(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
}
bool parallel(line &a,line &b){
    double temp=det(a.b-a.a,b.b-b.a);
    return !cmp(temp);
}
bool online(line &a,point &p){
    if(p.x>=min(a.a.x,a.b.x)&&p.x<=max(a.a.x,a.b.x)){
        if(p.y>=min(a.a.y,a.b.y)&&p.y<=max(a.a.y,a.b.y)){
            return true;
        }
    }
    return false;
}
bool inter(line &a,line &b,point &p){
    if (parallel(a, b)){
        return false;
    }
    double s1 = det(a.a - b.a, b.b - b.a);
	double s2 = det(a.b - b.a, b.b - b.a);
	p.x = (s1*a.b.x - s2 * a.a.x) / (s1 - s2);
	p.y = (s1*a.b.y - s2 * a.a.y) / (s1 - s2);
    if(online(a,p)&&online(b,p)){
        return true;
    }
    return false;
}
line lines[507];
bool cmp_x(point &a,point &b){
    return a.x<b.x;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        vector <point>points;
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&lines[i].a.x,&lines[i].a.y,&lines[i].b.x,&lines[i].b.y);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                point p;
                if(inter(lines[i],lines[j],p)){
                    points.push_back(p);
                }
            }
        }
        sort(points.begin(),points.end(),cmp_x);
        if(points.empty()){
            printf("0\n");
            continue;
        }
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(!(points[i]==points[i-1])){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
