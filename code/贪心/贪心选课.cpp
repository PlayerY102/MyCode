#include<stdio.h>
#include<queue>
#include<algorithm>
#define max_size 100007
using namespace std;
struct course{
    int d;
    int e;
    bool operator<(const struct course &b)const{
        return this->e<b.e;
    }
};
struct course courses[max_size];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %d",&courses[i].d,&courses[i].e);
        }
        sort(courses,courses+n);
        int current=0;
        priority_queue<int> Q;
        for(int i=0;i<n;i++){
            Q.push(courses[i].d);
            current+=courses[i].d;
            if(current>courses[i].e){
                current-=Q.top();
                Q.pop();
            }
        }
        printf("%d\n",Q.size());
    }
    return 0;
}
