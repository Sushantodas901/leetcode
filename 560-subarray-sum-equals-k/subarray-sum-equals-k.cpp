//BRUTE FORCE APPROACH
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int sum = nums[i];
//             if(sum==k){
//                 count++;
//             }
//             for(int j=i+1;j<n;j++){
//                 sum+=nums[j];
//                 if(sum == k){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
//OPTIMIZED APPRAOCH
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        map<int,int>m;
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(prefix[i]==k){
                count++;
            }
            if(m.find((prefix[i]-k))!=m.end()){
                count +=m[prefix[i] - k];
            }
            m[prefix[i]]++;
        }
        return count;
    }
};