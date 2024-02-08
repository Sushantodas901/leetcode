class Solution {
public:
    int solve(vector<int>&dp,int x,vector<int>&choices){
        if(x==0){
            return 0;
        }
        if(x<0){
            return INT_MAX;        
        }
        if(choices[x]!=-1){
            return choices[x];
        }
        int ans = INT_MAX;
        for(int i=0;i<dp.size();i++){
            if(dp[i] <= x){
                int temp = solve(dp,x - dp[i],choices);
                if(temp!=INT_MAX){
                    ans = min(temp+1,ans);
                }
            }
        }
        return choices[x] = ans;
    }
    int numSquares(int n) {
        vector<int>choices;
        vector<int>dp(n+1,-1);
        int size = sqrt(n);
        for(int i=1;i<=size;i++){
            choices.push_back(i*i);
        }
        return solve(choices,n,dp);
    }
};