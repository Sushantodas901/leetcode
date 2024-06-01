class FenwickTree{
	int n;
	vector<int> bit;
	
	public:
	
	FenwickTree(int n){
		this->n = n;
		bit = vector<int>(n);
	}
	void update(int ind,int val){
		while(ind <= n){
			bit[ind] = max(bit[ind] , val);
			ind += (ind & (-ind));
		}
		return;
	}
	int add(int ind){
		int ans = 0;
		while(ind > 0){
			ans = max(ans , bit[ind]);
			ind -= (ind & (-ind));
		}
		return ans;
	}
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
    	set<int> obs;
    	int n = 50001;
    	FenwickTree ft(n);
    	obs.insert(0);
    	obs.insert(n+1);
    	
    	//inserting all the type 1 query in obstacles
    	for(auto it:queries){
    		if(it[0] == 1){
    			obs.insert(it[1]);
    		}
    	}
    	for(auto it = obs.begin(); it != obs.end(); it ++){
            if(it == obs.begin()) continue;

            auto earlier = prev(it);
            int block = *it - *earlier;
            ft.update(*it, block);
        }
    	
        vector<bool> ans;
        for(int i = queries.size()-1;i >= 0 ;i --){
            if(queries[i][0] == 1){
                int ind = queries[i][1];
                auto currObs = obs.find(ind);
                auto prevObs = prev(currObs);
                auto nextObs = next(currObs);
                ft.update(*nextObs, *nextObs - *prevObs);
                obs.erase(currObs);
            }
            else{
                int pos = queries[i][1];
                int block = queries[i][2];
                auto curr = obs.upper_bound(pos);
                auto prevObs = prev(curr);
                int currMax = ft.add(*prevObs);
                currMax = max(currMax , pos - *prevObs);
                if(currMax >= block){
                    ans.push_back(true);
                }
                else ans.push_back(false);
            }

        }
    	reverse(ans.begin(),ans.end());
        return ans;
    }
};