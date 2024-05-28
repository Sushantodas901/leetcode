class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = t.size();
        int diff[n];
        for(int i = 0;i < n;i ++){
            diff[i] = abs(t[i] - s[i]);
        }
        int j = 0;
        int window = 0;
        int ans = 0;
        for(int i = 0;i < n;i ++){
            window += diff[i];
            while(j <= i && window > maxCost){
                window -= diff[j];
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        // ans = max(ans,)
        return ans;
    }
};