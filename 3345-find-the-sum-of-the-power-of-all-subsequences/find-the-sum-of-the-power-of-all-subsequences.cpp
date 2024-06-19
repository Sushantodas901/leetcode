class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int x){
        long long ans = 1;
        while(x --){
            ans = (ans * 2) % mod ;
        }
        return (int)ans;
    }
    int solve(int i,int sum,int cnt,vector<int>&a,int &k,vector<vector<vector<int>>>&dp){
        if(sum == k){
            return helper(a.size() - cnt);
        }
        if(i == a.size() || sum > k){
            return 0;
        }
        if(dp[i][cnt][sum] != -1)return dp[i][cnt][sum];
        return  dp[i][cnt][sum] = (solve(i+1,sum + a[i],cnt+1,a,k,dp) + solve(i+1,sum,cnt,a,k,dp))%mod;
    }
    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(101,-1)));
        long long curr =  solve(0,0,0,nums,k,dp);
        return curr;
        
    }
};