#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define max_size 307
using namespace std;
struct match_point{
    int pos;
    int value;
};
bool cmp(struct match_point a,struct match_point b){
    return a.pos<b.pos;
}
char inp[max_size];
vector<match_point>lists;
char* my_find[5]={"AlvinZH","ModricWang","Bamboo","ConnorZhong","BCPC"};
char* ans[5]={"hg, shg, awsl!","1080Ti!, wyr, silver!!!","this is 51's father","I am so weak","I want to join in!"};
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",inp);
    for(int i=0;i<5;i++){
        int temp=0;
        char* pos=strstr(inp+temp,my_find[i]);
        while(pos!=NULL){
            temp=pos-inp+1;
            struct match_point a;
            a.pos=temp;
            a.value=i;
            lists.push_back(a);
            pos=strstr(inp+temp,my_find[i]);
        }
    }
    sort(lists.begin(),lists.end(),cmp);
    for(int i=0;i<lists.size();i++){
        int dest=lists[i].value;
        printf("%s\n",ans[dest]);
    }
    return 0;
}
