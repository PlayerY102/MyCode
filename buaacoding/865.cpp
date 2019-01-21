#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct frog{
    int pos;
    int dis;
    bool operator<(const frog &b) const{
        if(pos==b.pos){
            return dis<b.dis;
        }
        return pos>b.pos;
    }
};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        priority_queue<frog> Q;
        for(int i=0;i<n;i++){
            frog temp;
            scanf("%d%d",&temp.pos,&temp.dis);
            Q.push(temp);
        }
        int fail=0;
        int sum=0;
        frog nowf;
        while(!Q.empty()){
            nowf=Q.top();
            Q.pop();
            if(fail){
                fail=0;
                while(!Q.empty()&&Q.top().pos==nowf.pos){
                    Q.pop();
                }
            }
            else{
                fail=1;
                int temp=0;
                int addnum=1;
                while(!Q.empty()&&Q.top().pos==nowf.pos){
                    frog nexf=Q.top();
                    Q.pop();
                    if(nexf.dis!=nowf.dis){
                        temp++;
                    }
                    else{
                        addnum++;
                    }
                }
                if(temp>0){
                    fail=0;
                    sum+=temp;
                }
                nowf.pos+=nowf.dis;
                for(int i=0;i<addnum;i++){
                    Q.push(nowf);
                }
            }
        }
        printf("%d %d\n",nowf.pos,sum);
    }
    return 0;
}
