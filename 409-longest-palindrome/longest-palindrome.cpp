class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(auto it:s){
            mp[it] ++;
        }
        int ans = 0;
        int maxi = 0;
        vector<int> temp;
        for(auto it:mp){ 
            if(it.second%2 == 0){
                ans += it.second;
            }
            else{
                temp.push_back(it.second);
            }
        }
        if(!temp.size()) return ans;
        sort(temp.begin(),temp.end());
        for(int i = 0;i < temp.size() - 1 ;i ++){
            ans += temp[i] - 1;
        }
        if(temp.size() > 0);
        ans += temp[temp.size()-1];
        return ans + maxi;
    }
};