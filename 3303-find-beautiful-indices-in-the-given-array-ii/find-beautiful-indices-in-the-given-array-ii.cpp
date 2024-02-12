class Solution {
public:
    
    vector<int> kmp(string s){
	vector<int> lps(s.size() , 0);
	
	
	for(int i = 1; i < lps.size() ;i ++){
		int prefixIndex = lps[i-1];
		
		while ( prefixIndex > 0 && s[i] != s[prefixIndex]){
			prefixIndex = lps[prefixIndex - 1] ;
		}
		
		lps[i] = prefixIndex + ( s[i] == s[prefixIndex] ? 1 : 0 ) ;
	}
	
	return lps ;
}


vector<int> beautifulIndices(string s, string a, string b, int k) {
		string firstPattern = a + "@" + s;
		string secondPattern = b + "@" + s;
		
		vector<int> arr1 = kmp(firstPattern) ;
		vector<int> arr2 = kmp(secondPattern) ;
		vector< int > valida;
		vector< int > validb;
		
		for(int i = a.size() ; i < arr1.size() ;i ++){
			int ele = arr1[i] ;
			if( ele == a.size() ){
                int index = i - ( 2 * a.size());
                if(index >= 0)
				valida.push_back(index);
			}
		}
		
		for(int i = b.size() ; i < arr2.size() ;i ++){
			int ele = arr2[i] ;
			if( ele == b.size()){
                int index = i - (2 * b.size() );
                if( index >= 0)
				validb.push_back(index);
			}
		}

        vector<int> ans;
        if( valida.size() ==0 || validb.size() == 0){
            return ans;
        }
      
        for(int i = 0;i < valida.size() ;i ++){
        	auto  curr = lower_bound( validb.begin() , validb.end() , valida[i]) - validb.begin() ;
            cout << curr << ' ' << validb.size() << endl;
            if( curr != validb.size() && abs(valida[i] - validb[curr]) <= k){
                cout << 'i';
                ans.push_back( valida[i]);
                continue;
            }
            if( curr != 0 && abs( valida[i] - validb[curr - 1] <= k)){
                ans.push_back( valida[i]);
            }
		}
		return ans;
        
    }
};