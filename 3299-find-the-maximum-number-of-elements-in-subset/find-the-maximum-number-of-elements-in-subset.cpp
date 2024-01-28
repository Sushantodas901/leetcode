class Solution {
public:
    int maximumLength(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(auto it:nums){
        mp[it]++;
    }
    int res = 0;
    for(int i=2;i<sqrt(1e9);i++){
        long long x = i;
        int count = 0;
        bool flag = false;
        while(x <= 1e9 && mp.find(x)!=mp.end() ){
            if(mp[x] >= 2){
                count += 2;
                x *= x;
            }
            else {
                flag = true;
                count++;
                break;
            }
        }
        if(!flag) count--;
        res = max(res,count);
    }
    if(mp.find(1)!=mp.end()){
        res = max(res , (mp[1]%2?mp[1]:mp[1]-1));
    }   
    return res;
}
};