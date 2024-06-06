#define ll long long 
class Solution {
public:
ll maxi = -1e9+8;
ll mini = 1e9+8;
ll sum = 0;
    ll solve(ll size, int &cost1,int &cost2, ll maxii){
        ll maxdiff = maxii - mini;
        ll total = maxii*size - sum;
        if(cost1 * 2LL <= cost2){
            return (ll)total * cost1;
        }
        ll last = total - maxdiff;
        if(total/2 < maxdiff){
            return (ll)(maxdiff - last) * cost1 + last * cost2;
        } 

        if(total % 2LL == 0LL){
            return (ll)(total/2LL)* cost2;
        }
        else{
            return (ll)(total/2LL) * cost2 + cost1;
        }
    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        for(auto it:nums){
            maxi = max(maxi , 1LL*it);
            mini = min(mini , 1LL*it);
            sum = sum + it*1LL;
        }
        ll ans = 1e18;
        for(ll i = maxi; i <= 4LL * maxi; i++){
            ll curr = solve((ll)nums.size(), cost1, cost2, i);
            ans = min(ans, curr);
        }
        int mod = 1e9+7;
        return ans%(mod);
    }
};
