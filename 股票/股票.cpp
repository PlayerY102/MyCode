#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
class Solution1 {//一次
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int curmin=prices[0];
        int result=0;
        for(int i=1;i<prices.size();i++){
            result=max(result,prices[i]-curmin);
            curmin=min(curmin,prices[i]);
        }
        return result;
    }
};
class Solution2 {//无数次
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0){
                result+=prices[i]-prices[i-1];
            }
        }
        return result;
    }
};
class Solution3 {//两次
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        int* dp1=new int[n];
        int* dp2=new int[n];
        int curmin=prices[0];
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,prices[i]-curmin);
            curmin=min(curmin,prices[i]);
            dp1[i]=result;
        }
        int curmax=prices[n-1];
        result=0;
        for(int i=n-1;i>=0;i--){
            result=max(result,curmax-prices[i]);
            curmax=max(curmax,prices[i]);
            dp2[i]=result;
        }
        result=0;
        for(int i=0;i<n;i++){
            result=max(result,dp1[i]+dp2[i]);
        }
        return result;
    }
};
class Solution4 {//cooldown
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        int buyi_1=max(-1*prices[0],-1*prices[1]);
        int selli_2=0;
        int selli_1=max(0,prices[1]-prices[0]);
        for(int i=2;i<n;i++){
            int buyi=max(selli_2-prices[i],buyi_1);
            int selli=max(buyi_1+prices[i],selli_1);
            buyi_1=buyi;
            selli_2=selli_1;
            selli_1=selli;
        }
        return selli_1;
    }
};
class Solution5 {//k次
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        if(k>n){
            k=n;
        }
        int* local = new int[k+1];
        int* global = new int[k+1];
        for(int i=0;i<=k;i++){
            local[i]=global[i]=0;
        }
        for(int i=1;i<n;i++){
            int temp=prices[i]-prices[i-1];
            int global_j_1=global[0];
            for(int j=1;j<=k;j++){
                int localnow=max(global_j_1,local[j]+temp);
                int globalnow=max(localnow,global[j]);
                global_j_1=global[j];
                global[j]=globalnow;
                local[j]=localnow;
            }
        }
        return global[k];
    }
};
class Solution6 {//有手续费
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int none=0;
        int have=-prices[0];
        for(int i=0;i<n;i++){
            int now_none=max(none,have+prices[i]-fee);
            int now_have=max(have,none-prices[i]);
            have=now_have;
            none=now_none;
        }
        return none;
    }
};