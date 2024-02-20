class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        int m = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum +=nums[i];
           
        }
        return m*(m+1)/2 - sum;
    }
};