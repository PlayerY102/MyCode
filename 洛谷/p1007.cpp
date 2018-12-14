#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define max_size 5007
using namespace std;
int main()
{
    int l,n;
    scanf("%d%d",&l,&n);
    int ansmin=0;
    int ansmax=0;
    for(int i=0;i<n;i++){
        int temp1;
        scanf("%d",&temp1);
        int temp2=l+1-temp1;
        ansmin=max(min(temp1,temp2),ansmin);
        ansmax=max(max(temp1,temp2),ansmax);
    }
    printf("%d %d\n",ansmin,ansmax);
    // system("pause");
    return 0;
}
