#include<stdio.h>
long long per[30];
long long sta[30];
double out[30];
long long find_sta(int n){
    if(n<=1){
        return 0;
    }
    if(sta[n]){
        return sta[n];
    }
    else{
        sta[n]=(n-1)*(find_sta(n-2)+find_sta(n-1));
        return sta[n];
    }
}
long long find_per(int n){
    if(n<=0){
        return 0;
    }
    if(per[n]){
        return per[n];
    }
    else{
        per[n]=n*find_per(n-1);
        return per[n];
    }
}
double pro(int n){
    double temp=0;
    if(n<=1){
        return 0.0;
    }
    if(out[n]){
        return out[n];
    }
    else{
        if(n%2==0){
            out[n]= out[n-1]+1.0/(double)find_per(n);
        }
        else{
            out[n]=out[n-1]-1.0/(double)find_per(n);
        }
        
    }
}
int main()
{   per[1]=1;
    per[2]=2;
    sta[1]=0;
    sta[2]=1;
    int n;
    long long ele,deo;
    while(scanf("%d",&n)!=EOF){
        if(n>=10){
            printf("%.2lf\n",36.79);
            continue;
        }
        ele=find_sta(n);
        deo=find_per(n);
        printf("%lf%%\n",((double)ele)/((double)deo)*100);
        // printf("%lf%%\n",pro(n));
    }
    return 0;
}
