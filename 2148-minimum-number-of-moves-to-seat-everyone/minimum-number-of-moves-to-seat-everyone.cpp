class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& s) {
        sort(begin(seats), end(seats));
        sort(begin(s), end(s));
        int moves = 0;

        for(int i = 0; i < seats.size(); ++i) {
            moves += abs(seats[i] - s[i]);
        }
        
        return moves;
    }
};