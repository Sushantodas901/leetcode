class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> s;
        for(auto it : arr1){
            while ( it ){
                s.insert(it);
                it /= 10;
            }
        }
        int ans = 0;
        for(auto it: arr2){
            int curr = 0;
            while ( it > 0){
                if(s.find(it)!= s.end()){
                    break;
                }
                it /= 10;
            }
            if(it == 0)continue;
            string temp = to_string(it);
            curr = temp.size();
            ans = max(curr , ans);
        }
        return ans;
    }
};