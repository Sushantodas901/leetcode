class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        int curr = 0;
        int j = 0;
        multiset<int> st;
        for(int i = 0;i < nums.size() ;i++){
            st.insert(nums[i]);
            while(j < i ){
                int first = *st.begin() , last = *(prev(st.end()));
                if(last - first <= limit) break;
                st.erase(st.find(nums[j]));
                j ++;
            }
            res = max(res ,(int ) st.size());
        }
        return res;
    }
};