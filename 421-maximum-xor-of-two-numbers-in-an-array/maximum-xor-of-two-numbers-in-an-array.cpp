struct Node{
    Node *links[2];
    Node(){
        links[0] = links[1] = NULL;
    }
};
class Solution {
    Node *root ;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int ans = 0;
        for(auto it:nums){
            // int it = nums[i];
            Node *node = root;
            for(int i = 31;i >= 0;i --){
                int x = (1 & (it >> i)) == 1;
                if(node->links[x] == NULL) node->links[x] = new Node();
                node = node->links[x];
            }
        }
        for(auto it:nums){
            Node *node = root;
            int curr = 0;
            for(int i = 31;i >= 0;i --){
                int x = (1 & (it >> i)) == 1;
                if(node->links[(x == 1)?0:1] != NULL){
                    curr += (1 << i);
                    node = node->links[(x == 1)?0:1];
                }
                else{
                    node = node->links[x];
                }
            }
            ans = max(ans , curr);
        }
        return ans;
    }
};