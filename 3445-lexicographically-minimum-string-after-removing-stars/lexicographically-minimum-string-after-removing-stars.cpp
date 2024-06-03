class Solution {
public:
    string clearStars(string s) {
        set<int> pos;
        priority_queue<pair<char,int>, vector<pair<char,int>> ,greater<pair<char,int>>> pq;
        // priority_queue<pair<char,int>> pq;
        for(int i = 0;i < s.size() ;i ++){
            if(s[i] == '*'){
                auto top = pq.top();
                // cout << top.second << endl;
                pos.insert(abs(top.second));
                pos.insert(i);
                pq.pop();
            }
            else{
                pq.push({s[i],-i});
            }
        }
        string ans = "";
        for(int i = 0;i < s.size() ;i ++){
            if(pos.find(i) != pos.end()) continue;
            ans += s[i];
        }
        return ans;
    }
};