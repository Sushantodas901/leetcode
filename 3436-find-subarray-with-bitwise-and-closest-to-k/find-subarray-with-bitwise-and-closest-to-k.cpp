class Solution {
public:
    
long long int tree[10000000];
void build(vector<int>&a,int index,int start,int end){
    if(start == end){
        tree[index] = a[start];
        return; 
    }
    int mid = (start+end)/2;
    build(a,2*index+1,start,mid);
    build(a,2*index+2,mid+1,end);
    tree[index] = (tree[2*index+1] & tree[2*index+2]);
    return;
}
long long int query(int index,int start,int end,int l,int r){
    if(r<start or end<l){
        return INT_MAX;
    }
    else if(start>=l and end<=r){
        return tree[index];
    }
    int mid=(start+end)/2;
    long long int left = query(2*index+1,start,mid,l,r);
    long long int right = query(2*index+2,mid+1,end,l,r);
    return (left & right);
}
int minimumDifference(vector<int>& nums, int k) {
    int ans = INT_MAX;
    int n = nums.size();
    build(nums,0,0,nums.size()-1);
    for(int l = 0;l < nums.size() ; l++){
        int low = l;
        int high = n-1;
        int mid;
        int curr = n;
        while(low <= high){
            mid = (low + high) >> 1;
            int bit = query(0 , 0 , n-1 , l, mid);
            if(bit <= k){
                curr = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(curr > l ) ans = min(ans , (int)abs(k - query(0 , 0 , n-1 , l, curr-1)));
        if(curr < n ) ans = min(ans , abs(k - (int)query(0 , 0 , n-1 , l, curr)));
        
    }
    return ans;
}
};