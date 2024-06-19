class Solution {
public:
    long long solve(int i,vector<int>&a,map<int,int>& mp,vector<long long>&dp){
        if(i == a.size()) return 0LL;
        if(dp[i] != -1) return dp[i];
        long long ch1 = 0;
        long long ch2 = 0;
        int ind = i + 1;
        for(;ind < a.size() && a[ind] <= a[i] + 2; ind ++){}
        ch1 = 1LL* mp[a[i]] * a[i] + solve(ind , a , mp, dp);
        ch2 = solve(i + 1,a,mp , dp);
        return dp[i]  = max(ch1,ch2);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int> mp;
        for(auto it:power){
            mp[it] ++;
        }
        vector<int> a;
        for(auto it:mp){
            a.push_back(it.first);
        }
        vector<long long > dp(a.size()+1, -1);
        long long ans = solve(0,a,mp,dp);
        return ans;
    }
};