struct Node{
    Node *links[26];
    bool flag = false;
    Node(){
        for(int i = 0;i < 26;i ++){
            links[i] = NULL;
        }
    }
    bool containsKey(char ch){
        return links[ch - 'a'] == NULL;
    }
    void putKey(char ch,Node* node){
        links[ch - 'a'] = node;
        return;
    }
    Node *getNext(char ch){
        return links[ch - 'a'];
    }
    void setFlag(){
        flag = true;
    }
    bool endFlag(){
        return flag;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(auto it:word){
            if(node->containsKey(it)){
                node->putKey(it , new Node());
            }
            node = node->getNext(it);
        }
        node->setFlag();
    }
    bool search(string word) {
       Node *node = root;
       for(auto it:word){
            if(node->containsKey(it)) return false;
            node = node->getNext(it);
       } 
       return node->endFlag();
    }
    bool startsWith(string prefix) {
        Node *node = root;
        for(auto it:prefix){
            if(node->containsKey(it)) return false;
            node = node->getNext(it);
        }       
        return true;
    }
};
