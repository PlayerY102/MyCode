#include<stdio.h>
#include<algorithm>
#include<queue>
#define max_size 100007
using namespace std;
struct course{
    int s;
    int f;
    bool operator <(const course &b){
        return f<b.f;
    }
};
course courses[max_size];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d %d",&courses[i].s,&courses[i].f);
        }
        sort(courses,courses+n);
        int current=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(courses[i].s>=current){
                current=courses[i].f;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
