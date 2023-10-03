class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        int j=0;
        int i=0;
        long long window = 0;
        while(i<n){
            window += nums[i++];
            while(j<i and (window*(i-j)>=k)){
                window -= nums[j++];
            }
            ans += i-j;
        }
        return ans;
    }
};