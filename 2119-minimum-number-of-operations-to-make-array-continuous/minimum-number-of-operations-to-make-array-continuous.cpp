class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(begin(nums),end(nums)),end(nums));
        
        int n = nums.size();
        int ans = size;
        int j=0;
        for(int i=0;i<n;i++){
            while( j < n and nums[j] < nums[i] + size){
                j++;
            }
            ans = min(ans, size - j+i);
        }
        return ans;
    }
};