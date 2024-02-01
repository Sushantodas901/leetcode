class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i+=3){
            vector<int>temp;
            if(nums[i+2] - nums[i] > k){
                return {};
            }
            temp.push_back(nums[i]);
            temp.push_back(nums[i+1]);
            temp.push_back(nums[i+2]);
            ans.push_back(temp);
        }
        return ans;
    }
};