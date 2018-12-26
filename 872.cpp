#include<stdio.h>
#include<algorithm>
#include<map>
#define max_size 1007
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        map<int,int> li;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                int temp;
                scanf("%d",&temp);
                if(j==m-1){
                    continue;
                }
                sum+=temp;
                li[sum]++;
            }
        }
        int result=0;
        for(map<int,int>::iterator it=li.begin();it!=li.end();it++){
            result=max(result,it->second);
        }
        printf("%d\n",n-result);
    }
}
