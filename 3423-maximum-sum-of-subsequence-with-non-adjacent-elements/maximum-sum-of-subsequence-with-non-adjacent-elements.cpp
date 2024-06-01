#define ll long long 
const int mod = 1e9+7;
struct Node{
    ll val[2][2];
    Node(){
        for(int i = 0 ;i < 2;i ++){
            for(int j = 0;j < 2;j ++){
                val[i][j] = 0;
            }
        }
    }
    ll answer(){
        ll ans = 0;
        for(int i = 0 ;i < 2;i ++){
            for(int j = 0;j < 2;j ++){
                ans = max(val[i][j] , ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    Node tree[500005];

void build(vector<int>& a ,int index,int start,int end){
	if(start == end){
		tree[index].val[1][1] = a[start];
		return;
	}
	else{
		int mid = (start + end) >> 1;
		build(a,2*index+1,start,mid);
		build(a,2*index+2,mid+1,end);
		for(int i = 0 ;i < 2;i ++){
            for(int j = 0;j < 2;j ++){
                tree[index].val[i][j] = max({tree[2*index+1].val[i][0] + tree[2*index+2].val[0][j] , 
                                             tree[2*index+1].val[i][1] + tree[2*index+2].val[0][j] ,
                                             tree[2*index+1].val[i][0] + tree[2*index+2].val[1][j] ,
                                            });
            }
        }

	}
}

ll query(int index,int start,int end,int l ,int r){
	if(start > r || end < l){
		return 0;
	}
	else if(start >= l && end <= r){
		return tree[index].answer();
	}
	else{
		int mid = (start + end) >> 1;
		return max(query(2*index+1, start, mid , l , r)%mod,query(2*index+2,mid+1,end,l,r)%mod);
	}
    
}

void update(vector<int>& a,int index,int start,int end,int val,int req){
    if(start==end){
        a[start] = val;
        tree[index].val[1][1] = val;
        return;
    }
    int mid = (start+end)/2;
    if(req<=mid){
        update(a,2*index+1,start,mid,val,req);
    }
    else update(a,2*index+2,mid+1,end,val,req);
    for(int i = 0 ;i < 2;i ++){
            for(int j = 0;j < 2;j ++){
                tree[index].val[i][j] = max({tree[2*index+1].val[i][0] + tree[2*index+2].val[0][j] , 
                                             tree[2*index+1].val[i][1] + tree[2*index+2].val[0][j] ,
                                             tree[2*index+1].val[i][0] + tree[2*index+2].val[1][j] ,
                                             });
            }
    }
    return;
}
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        build(nums , 0 , 0 , nums.size() - 1);
        ll ans = 0;
        for(auto it:queries){
            update(nums,0,0,nums.size()-1,it[1] , it[0]);
            ll curr = query(0,0,nums.size() - 1, 0 , nums.size()-1);
            ans = (ans + curr)% mod;
        }
        return (int)ans;
    }
};