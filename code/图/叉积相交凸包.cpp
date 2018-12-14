#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
using namespace std;
struct point{
    int x;
    int y;
    int operator* (point b){
        return x*b.y-b.x*y;
    }
    point operator-(point b){
        point result;
        result.x=x-b.x;
        result.y=y-b.y;
        return result;
    }
    point operator+(point b){
        point result;
        result.x=x+b.x;
        result.y=y+b.y;
        return result;
    }
    bool operator==(point b){
        return (x==b.x&&y==b.y);
    }
    bool operator!=(point b){
        return !(x==b.x&&y==b.y);
    }
};
int direction(point pi,point pj,point pk){
    return (pk-pi)*(pj-pi);
}
bool online(point pi,point pj,point pk){
    if (pk.x>=min(pi.x,pj.x) && pk.x<=max(pi.x,pj.x) && pk.y>=min(pi.y,pj.y) && pk.y<=max(pi.y,pj.y)){
        return true;       
    }
    return false;
}
bool intersect(point p1,point p2,point p3,point p4){
    int d1=direction(p3,p4,p1);
    int d2=direction(p3,p4,p2);
    int d3=direction(p1,p2,p3);
    int d4=direction(p1,p2,p4);
    if(((d1>0 && d2<0)||(d1<0 && d2>0))&&((d3>0 && d4<0)||(d3<0 && d4>0))){
        return true;
    }
    else if(d1==0&&online(p3,p4,p1)){
        return true;
    }
    else if(d2==0&&online(p3,p4,p2)){
        return true;
    }
    else if(d3==0&&online(p1,p2,p3)){
        return true;
    }
    else if(d4==0&&online(p1,p2,p4)){
        return true;
    }
    return false;
}
double angle(point to){
    double len=sqrt(to.x*to.x+to.y*to.y);
    return (double)to.y/len;
}
bool cmp_graham(point a,point b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    else{
        return a.x<b.x;
    }
}
point origin_point;
bool cmp_angle(point a,point b){
    int temp=direction(origin_point,a,b);
    if(temp<0){
        return true;
    }
    else{
        return false;
    }
}
vector<point>Q;
vector<point>S;
void graham_scan(){
    S.clear();
    sort(Q.begin(),Q.end(),cmp_graham);
    if(Q.size()<=2){ 
        for(int i=0;i<Q.size();i++){
            S.push_back(Q[i]);
        }
        return;
    }
    origin_point=Q[0];
    S.push_back(Q[0]);
    sort(Q.begin()+1,Q.end(),cmp_angle);
    S.push_back(Q[1]);
    S.push_back(Q[2]);
    for(int i=3;i<Q.size();i++){
        while(direction(S[S.size()-2],S[S.size()-1],Q[i])>0){
            S.erase(S.end()-1);
        }
        S.push_back(Q[i]);
    }
}
struct line{
    point a;
    point b;
};
vector<line> add_line(){
    vector<line> result;
    point pre=S[0];
    for(int i=1;i<S.size();i++){
        line temp;
        temp.a=pre;
        temp.b=S[i];
        pre=S[i];
        result.push_back(temp);
    }
    line temp;
    temp.a=pre;
    temp.b=S[0];
    result.push_back(temp);
    return result;
}
bool check(vector<line>& a,vector<line>& b){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(intersect(a[i].a,a[i].b,b[j].a,b[j].b)){
                return true;
            }
        }
    }
    return false;
}
bool if_in(vector<line>&a,point b){
    int sign=direction(a[0].a,a[0].b,b);
    if(sign==0){
        return false;
    }
    else if(sign>0){
        for(int i=1;i<a.size();i++){
            point temp1=a[i].a;
            point temp2=a[i].b;
            int temp=direction(temp1,temp2,b);
            if(temp<=0){
                return false;
            }
        }
    }
    else {
        for(int i=1;i<a.size();i++){
            point temp1=a[i].a;
            point temp2=a[i].b;
            int temp=direction(temp1,temp2,b);
            if(temp>=0){
                return false;
            }
        }
    }
    return true;
}