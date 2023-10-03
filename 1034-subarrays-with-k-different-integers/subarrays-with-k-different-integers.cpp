class Solution {
public:
    int solve(vector<int>&nums,int k){
        unordered_map<int,int>window;
        int i=0;
        int j=0;
        int ans = 0;
        int n = nums.size();
        while(i<n){
            window[nums[i++]]++;
            while(j<i and window.size() > k){
                window[nums[j]]--;
                if(window[nums[j]]==0){
                    window.erase(nums[j]);
                }
                j++;
            }
            ans += i-j;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};