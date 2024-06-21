class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int window = 0;
        int i = 0;
        for(i = 0;i < minutes;i ++){
            window += customers[i];
        }
        int j = 0;
        int ans = 0;
        for(int ind = i;ind < customers.size();ind ++) {
            if(grumpy[ind] == 0) ans += customers[ind];
        }
        int res = ans + window;
        while(i < customers.size()){
            if(grumpy[j] == 0){
                ans += customers[j];
            }
            if(grumpy[i] == 0)
            ans -= customers[i];
            window -= customers[j];
            window += customers[i];
            res = max(res , ans + window);
            i ++;
            j ++;
        }
        return res;
    }
};