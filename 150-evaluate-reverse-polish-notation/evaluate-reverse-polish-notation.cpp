class Solution {
public:
bool isOperator(string ch){
    if(ch=="+"){
            return true;
        }
        else if(ch=="-"){
            return true;
        }
        else if(ch=="/"){
            return true;
        }
        else if(ch=="*"){
            return true;
        }
        return false;
}
    int solve(int first,int second,string ch){
        if(ch=="+"){
            return second + first;
        }
        else if(ch=="-"){
            return second - first;
        }
        else if(ch=="/"){
            return second / first;
        }
        else if(ch=="*"){
            return second * first;
        }
        return 0;
    } 
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int val = solve(first,second,tokens[i]);
                st.push(val);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};