class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int j=0;
        int n = nums.size();
        long long int curr_window = 0;
        for(int i=0;i<n;i++){
            curr_window += nums[i];
            while( (long long int)(i-j+1)*nums[i] - curr_window > k){
                curr_window -= nums[j];
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};