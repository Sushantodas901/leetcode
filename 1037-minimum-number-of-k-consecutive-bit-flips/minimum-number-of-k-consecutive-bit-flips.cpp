class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flag = 0;
        int cnt = 0;
        int n = nums.size();
        vector<int> diff(n+1,0);
        for(int i = 0 ;i <= n - k; i ++){
            flag += diff[i];
            if(nums[i] == 0){
                if(flag % 2 == 0){
                    flag ++;
                    cnt ++;
                    diff[i + k] = -1;
                }
            }
            else{
                if(flag % 2 != 0){
                    flag ++;
                    cnt ++;
                    diff[i + k] = -1;
                }
            }
        }
        for(int i = n-k + 1;i < n ;i ++){
            flag += diff[i];
            if(flag % 2 == 0 && nums[i] == 0){
                return -1;
            }
            else if(flag % 2 != 0 && nums[i] == 1){
                return -1;
            }
        }
        return cnt;
    }
};