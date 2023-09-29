class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int target){
        int sum  =0 ;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > target){
                return false;
            }
            sum+=nums[i];
            if(sum > target){
                sum = nums[i];
                count++;
            }
        }
        if(count<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        while(left < right){
            int middle = (left+right)/2;
            if(isPossible(nums,k,middle)){
                right = middle;
            }
            else{
                left = middle+1;
            }
        }
        return left;
    }
};