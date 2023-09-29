class Solution {
public:
    bool canShift(vector<int>&weights,int days,int mid){
    long long int sum=0;
    int count=1;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
        if(sum>mid){
        sum=weights[i];
        count++;}

    }
    if(count<=days)
    return true;
    return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left < right){
            int middle = ( right + left)/2;
            if(canShift(weights,days,middle)){
                right = middle;
            }
            else{
                left = middle+1;
            }
        }
        return left;
    }
};