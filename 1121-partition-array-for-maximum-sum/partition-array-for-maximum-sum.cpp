class Solution {
public:
    int solve(vector<int>&arr,int k,int index,vector<vector<int>>& dp){
        if(index == arr.size()){
            return 0;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int ans = 0;
        int prev = -1;
        for(int j = index,l=1;j<arr.size() && j < index+k;j++,l++){
            prev = max(prev , arr[j]);
            int temp = solve(arr,k,j+1,dp) + prev*l;
            ans  = max(ans, temp);
        }
        return dp[index][k] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        return solve(arr,k,0,dp);
    }
};