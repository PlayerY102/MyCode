#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max_size 1000007
using namespace std;
void kmp_pre(char x[],int m,int next[]){
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j&&x[i]!=x[j]){
            j=next[j];
        }
        next[++i]=++j;
    }
}
int my_next[max_size];
int kmp_count(char x[],int m,char y[],int n){
    int i,j;
    int ans=0;
    kmp_pre(x,m,my_next);
    i=j=0;
    while(i<n){
        while(-1!=j && y[i]!=x[j]){
            j=my_next[j];
        }
        i++;
        j++;
        if(j>=m){
            ans++;
            printf("%d\n",i-m+1);
            j=my_next[j];
        }
    }
    return ans;
}
char s1[max_size];
char s2[max_size];
int main()
{
    while(scanf("%s",s1)!=EOF){
        scanf("%s",s2);
        kmp_pre(s2,strlen(s2),my_next);
        kmp_count(s2,strlen(s2),s1,strlen(s1));
        int m=strlen(s2);
        for(int i=1;i<=m;i++){
            printf("%d ",my_next[i]);
        }
    }
    return 0;
}
