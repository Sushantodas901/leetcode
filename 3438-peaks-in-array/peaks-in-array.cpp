class Solution {
public:
    int tree[10000000];
    void build(vector<int>&a,int index,int start,int end){
    if(start == end){
        if(start == 0 || start == a.size()-1) {
            tree[index] = 0;
        }
        else{
            if(a[start - 1] < a[start] && a[start] > a[start+1]){
                tree[index] = 1;
            }
            else tree[index] = 0;
        }
        return; 
    }
    int mid = (start+end)/2;
    build(a,2*index+1,start,mid);
    build(a,2*index+2,mid+1,end);
    tree[index] = tree[2*index+1]+tree[2*index+2];
    return;
}
long long int query(int index,int start,int end,int l,int r){
    if(r<start or end<l){
        return 0;
    }
    else if(start>=l and end<=r){
        return tree[index];
    }
    int mid=(start+end)/2;
    long long int left = query(2*index+1,start,mid,l,r);
    long long int right = query(2*index+2,mid+1,end,l,r);
    return left+right;
}
void update(vector<int>&a,int index,int start,int end,int val,int req){
    if(start==end){
        if(start == 0 || start == a.size()-1) {
            tree[index] = 0;
        }
        else{
            if(a[start - 1] < a[start] && a[start] > a[start+1]){
                tree[index] = 1;
            }
            else tree[index] = 0;
        }
        return;
    }
    int mid = (start+end)/2;
 
    if(req<=mid){
        update(a,2*index+1,start,mid,val,req);
    }
    else update(a,2*index+2,mid+1,end,val,req);
    tree[index] = tree[index*2+1] + tree[index*2+2];
}
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        build(nums,0,0,nums.size()-1);
        vector<int> ans;
        for(auto it:queries){
            if(it[0] == 1){
                int curr = query(0,0,nums.size()-1,it[1]+1,it[2]-1);
                ans.push_back(curr);
            }
            else{
                nums[it[1]] = it[2];
                if(it[1] != 0)
                update(nums,0,0,nums.size()-1,it[2],it[1]-1);
                if(it[1] != nums.size()-1)
                update(nums,0,0,nums.size()-1,it[2],it[1] + 1);
                update(nums,0,0,nums.size()-1,it[2],it[1]);
            }
        }
        return ans;
    }
};