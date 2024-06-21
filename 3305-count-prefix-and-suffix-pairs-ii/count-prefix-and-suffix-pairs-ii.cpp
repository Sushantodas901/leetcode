struct Node{
    unordered_map<string,Node*>links;
    int flag;
    Node(){
        flag = 0;
        // for(int i = 0;i < 26;i ++) links[i] = 0;
    }
};
class Solution {
    Node *root;
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
      root = new Node();
      long long cnt = 0;
      for(auto it:words){
        Node *node = root;
        for(int i = 0, j = it.size()-1;i < it.size(); i ++ ,j --){
            string temp ="";
            temp += it[i] ;
            temp += it[j];
            if(node->links[temp] == NULL){
                node->links[temp] = new Node();
            }
            
            node = node->links[temp];
            cnt += node->flag;
        }
        node->flag ++;
      }
      return cnt;
    }
};