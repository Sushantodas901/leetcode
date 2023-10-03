class Solution {
public:
    int solve(vector<int>&nums,int k){
        int window = 0;
        int i=0;
        int j=0;
        int ans=0;
        while(i<nums.size()){
            if(nums[i++]%2){
                window++;
            }
            while(j<i and window > k){
                if(nums[j]%2){
                    window--;
                }
                j++;
            }
            ans+=i-j;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};