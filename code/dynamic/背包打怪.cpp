#include<stdio.h>
#include<algorithm>
using namespace std;
long long pack[1007];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            pack[i]=-1;
        }
        for(int i=1;i<=n;i++){
            int monster;
            scanf("%d",&monster);
            for(int j=i;j<=n;j++){
                if(pack[j-i]==-1){
                    continue;
                }
                if(pack[j]==-1){
                    pack[j]=pack[j-i]+monster;
                }
                else{
                    pack[j]=min(pack[j],pack[j-i]+monster);
                }
            }
        }
        printf("%d\n",pack[n]);
    }
}