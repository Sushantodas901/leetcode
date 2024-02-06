class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>,vector<string>> mp;
        for(int i = 0;i < strs.size() ;i++ ){
            int size = strs[i].size();
            multiset<char> temp;
            for(int j = 0; j < size; j++){
                temp.insert(strs[i][j]);
            }
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>>s;
        for( auto it: mp){
            s.push_back(it.second);
        }
        return s;
    }
};