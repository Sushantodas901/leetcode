class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int size = temp.size();
        stack<pair<int,int>>st;

        vector<int> ans (size,0);
        st.push({temp[size - 1],size-1});

        for(int j=size - 2;j>=0 ; j--){
            auto it = st.top();
            if( temp[j] < it.first){
                ans[j] = it.second - j;
            }
            else{
                while (!st.empty() && st.top().first <= temp[j]){
                    st.pop();
                }
                if(st.empty()){
                    ans[j] = 0;
                }
                else{
                    ans[j] = st.top().second - j;
                }   
            }
            st.push({temp[j],j});
        }
        return ans;
    }
};