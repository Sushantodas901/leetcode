class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>nums){
        ans.push_back(temp);
        if(temp.size()==nums.size()){
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==11){
                continue;
            }
            temp.push_back(nums[i]);
            nums[i] = 11;
            solve(ans,temp,nums);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,nums);
        return ans;
    }
};