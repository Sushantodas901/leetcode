class Solution {
public:
    bool prime[10000000];
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    map<int,int>mp;
    void sieve() {
        int n=1000000;    
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p < n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i < n; i += p)
                    prime[i] = false;
            }
        }
    }
    void solve(int i,int j,int &move,int no,vector<vector<int>>&a){
        if(i < 0 || j < 0 || i == a.size() || j == a[0].size() ) return ;
        int curr = no*10 + a[i][j];
        if(curr > 10 && prime[curr]){
            mp[curr] ++;
        }
        solve(i + dx[move],j + dy[move], move, curr , a);
        return;
    }
    int mostFrequentPrime(vector<vector<int>>& a) {
        sieve();
        for(int i = 0;i < a.size() ;i ++){
            for(int j =0 ;j < a[0].size();j ++){
                for(int k = 0;k < 8;k ++){
                    solve(i,j,k,0,a);
                }
            }
        }
        int maxi = 0;
        int ans = 0;
        for(auto it:mp){
            if(maxi <= it.second){
                ans = it.first;
                maxi = it.second;
            }
        }
        if(maxi == 0) return -1;
        return ans;
    }
};