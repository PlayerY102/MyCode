#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define max_size 100007
using namespace std;
int n;
struct point{
    int x;
    int y;
};
struct point points[max_size];
bool cmp_x(struct point a,struct point b){
    return a.x<b.x;
}
bool cmp_y(int a,int b){
    return points[a].y<points[b].y;
}
double dist(struct point a,struct point b){
    long long temp_x1=a.x;
    long long temp_y1=a.y;
    long long temp_x2=b.x;
    long long temp_y2=b.y;
    return sqrt((temp_x1-temp_x2)*(temp_x1-temp_x2)+(temp_y1-temp_y2)*(temp_y1-temp_y2));
}
double find_cloest(int l,int r){
    if(l+1==r){
        return dist(points[l],points[r]);
    }
    if(l+2==r){
        return min(dist(points[l],points[l+1]),min(dist(points[l],points[r]),dist(points[l+1],points[r])));
    }
    int mid=(l+r)/2;
    double ans=min(find_cloest(l,mid),find_cloest(mid+1,r));
    vector<int> temp;
    for(int i=l;i<=r;i++){
        if(points[i].x>=points[mid].x-ans && points[i].x<=points[mid].x+ans){
            temp.push_back(i);
        }
    }
    sort(temp.begin(),temp.end(),cmp_y);
    for(int i=0,size=temp.size();i<size;i++){
        for(int j=i+1;j<size && j<=i+6;j++){
            int y_dist=(points[temp[j]].y-points[temp[i]].y);
            if(y_dist>ans){
                break;
            }
            ans=min(ans,dist(points[temp[i]],points[temp[j]]));
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %d",&points[i].x,&points[i].y);
        }
        sort(points,points+n,cmp_x);
        double ans=find_cloest(0,n-1);
        printf("%.2lf\n",ans);
    }
    return 0;
}
