struct Node{
    Node *links[26];
    bool flag;
    Node(){
        for(int i = 0;i < 26;i ++) links[i] = NULL;
        flag = false;
    }
};
class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(auto it:word){
            if(node->links[it - 'a'] == NULL){
                node->links[it - 'a'] = new Node();
            }
            node = node->links[it - 'a'];
        }
        node->flag = true;
    }
    bool helper(int ind,string &word,Node *node){
        if(node == NULL) return false;
        if(ind == word.size()) return node->flag;
        if(word[ind] == '.'){
            bool temp = false;
            for(int i = 0;i < 26;i ++){
                temp = (temp | helper(ind + 1,word,node->links[i]));
            }
            return temp;
        }
        else if(node->links[word[ind] - 'a'] == NULL) return false;
        return helper(ind+1,word,node->links[word[ind] - 'a']);
    }
    bool search(string word) {
        bool ans = helper(0,word,root);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */