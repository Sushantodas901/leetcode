class Solution {
public:
    bool check(vector<int>& hand,int curr, int size){
        int ind = hand[curr] + 1;
        int cnt = 1;
        hand[curr] = -1;
        curr++;
        while(curr < hand.size() && cnt < size){
            if(hand[curr] == ind){
                ind = hand[curr] + 1;
                hand[curr] = -1;
                cnt ++;
            }
            curr ++;
        }
        return cnt == size;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        for(int i  = 0;i < hand.size() ;i ++){
            if(hand[i] >= 0){
                if(!check(hand,i,groupSize)){
                    return false;
                }
            }
        }
        return true;
    }
};