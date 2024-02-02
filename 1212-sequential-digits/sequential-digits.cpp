class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            int curr = i;
            int digit = curr + 1;
            while( curr<=high and digit <= 9){
                curr = curr*10 + digit;
                if( curr >= low and curr<=high){
                    ans.push_back(curr);
                }
                digit++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};