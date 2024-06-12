class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0,count2 = 0,count1 = 0;
        for(auto it:nums)
        {
            if(it==0)count0++;
            else if(it==1)count1++;
            else count2++;

        }
        int i=0;
        while(count0--){
            nums[i] = 0;
            i++;
        }
        while(count1--)
        {
            nums[i] = 1;
            i++;
        }
        while(count2--)
        {
            nums[i] = 2;
            i++;
        }
        return ;
    }
};