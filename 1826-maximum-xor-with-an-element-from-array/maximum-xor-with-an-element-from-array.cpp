struct Node{
    Node *links[2];
    Node(){
        links[0] = links[1] = NULL;
    }
};
class Solution {
    Node *root = new Node();
public:
    void insert(int x){
        Node *node = root;
        for(int i = 31;i >= 0;i --){
            int bit = (1 & (x >> i));
            if(node->links[bit] == NULL) node->links[bit] = new Node();
            node = node->links[bit];
        }
        return;
    }
    int maximumElement(int x){
        int curr = 0;
        Node *node = root;
        for(int i = 31;i >= 0;i --){
            int bit = (1 & (x >> i));
            if(node->links[bit==1 ? 0 : 1] != NULL){
                curr += (1 << i);
                node = node->links[bit == 1 ? 0 : 1];
            }
            else node = node->links[bit];
        }
        return curr;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0;i < queries.size() ;i ++){
            temp.push_back({queries[i][1],{i,queries[i][0]}});
        }
        sort(temp.begin(),temp.end());
        vector<int> res(queries.size(),0);
        int ind = 0;
        for(auto it : temp){
            while(ind < nums.size() && nums[ind] <= it.first){
                insert(nums[ind++]);
            }
            if(ind == 0){
                res[it.second.first] = -1;
            }
            else{
                int curr = maximumElement(it.second.second);
                res[it.second.first] = curr;
            }
        } 
        return res;
    }
};