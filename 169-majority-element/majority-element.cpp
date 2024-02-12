class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int me = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)me = nums[i];
            if(me==nums[i])count++;
            else count-=1;
        }
        return me;
    }
};