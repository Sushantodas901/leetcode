class Solution {
public:
    bool check(unordered_map<char,int>&temp,unordered_map<char,int>&mp){
        for(auto it:temp){
            if(it.second > mp[it.first]){
                return false;
            }
        }
        return true;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        int n = words.size();
        unordered_map<char,int> mp;
        for(auto it:letters){
            mp[it]++;
        }
        int ans = 0;
        for(int i = 0; i < (1<<n); i++){
            vector<string> temp;
            for(int j = 0;j < n; j++){
                if ((i & (1 << j)) != 0) {
                    temp.push_back( words[j] );
                }
            }
            unordered_map<char,int> xtemp;
            for(auto it:temp){
                for(auto ch:it){
                    xtemp[ch]++;
                }
            }
            if(check(xtemp,mp)){
                int curr_score = 0;
                for(auto it:xtemp){
                    curr_score += it.second * score[it.first - 'a'];
                }
                ans = max(ans,curr_score);
            }
        }
        return ans;
    }
};