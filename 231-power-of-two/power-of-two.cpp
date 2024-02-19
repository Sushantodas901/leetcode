class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n < 0) return false;
        if(n == 0) return false;
        int temp = log2(n);
        if(pow(2,temp) == n){
            return true;
        }
        return false;
    }
};