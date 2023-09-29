class Solution {
public:
    bool isPossible(vector<int>&piles,int h,int target){
        int count = 0;
        // cout<<"target"<<target<<endl;
        for(auto i:piles){
            if(i > target){
                count += i/target;
                if(i%target)count++;
                // cout<<"nums[i]"<<i<<" inside"<<endl;
            }
            else{
                count++;
                // cout<<"nums[i]"<<i<<"outside"<<endl;
            }
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left < right){
            int middle = (left+right)/2;
            if(isPossible(piles,h,middle)){
                right = middle;
            }
            else{
                left = middle+1;
            }
        }
        return left;
    }
};