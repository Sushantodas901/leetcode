class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s;
        for(auto it:dictionary){
            s.insert(it);
        }
        string ans = "";
        string temp = "";
        for(int i = 0;i < sentence.size() ;i ++){
            if(sentence[i] == ' '){
                // cout << temp << endl;
                string curr = "";
                bool flag = true;
                for(int j = 0;j < temp.size() ;j ++){
                    curr += temp[j];
                    // cout << curr << endl;
                    if(s.find(curr) != s.end()){
                        ans += curr + ' ';
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans += temp + ' ';
                }
                temp = "";
            }
            else temp += sentence[i];
            if(i == sentence.size() - 1){
                // cout << temp << endl;
                string curr = "";
                bool flag = true;
                for(int j = 0;j < temp.size() ;j ++){
                    curr += temp[j];
                    // cout << curr << endl;
                    if(s.find(curr) != s.end()){
                        ans += curr;
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans += temp ;
                }
                temp = "";
            }
        }
        return ans;
    }
};