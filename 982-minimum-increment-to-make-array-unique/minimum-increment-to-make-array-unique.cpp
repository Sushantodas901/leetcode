class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        set<int> st;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            if(st.find(it) != st.end()){
                auto temp = st.end();
                --temp;
                ans += (*temp - it) + 1;
                
                st.insert((*temp ) + 1);
            }
            else{
                st.insert(it);
            }
        }
        return ans;
    }
};