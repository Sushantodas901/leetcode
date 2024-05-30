class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        map<int,int> mp;
        for(auto it:nums2){
            mp[it*k] ++;
        }
        for(auto it:nums1){
            for(int i = 1;i <= sqrt(it); i++){
                if(it % i != 0)continue;
                if(it/i == i){
                    ans += mp[i];
                    continue;
                }
                ans += mp[i];
                ans += mp[it/i];
            }
        }
        return ans;
    }
};