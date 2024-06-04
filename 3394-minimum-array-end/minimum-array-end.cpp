class Solution {
public:
    long long minEnd(int n1, int x1) {
        vector<long long> arr;
        n1 --;
        long long n = n1;
        long long x = x1;
        for(int i = 0;i < 64;i ++){
            if(((n >> i) & 1) == 1){
                arr.push_back(1);
            }
            else arr.push_back(0);
        }
        long long ans = 0;
        int ind = 0;
        for(int i = 0 ;i < 64;i ++){
            if(((x >> i) & 1LL) == 1){
                ans += (1LL << i);
            }
            else{
                long long temp = arr[ind ++];
                if(temp)
                ans += (1LL << i);
            }
        }
        return ans;
    }
};