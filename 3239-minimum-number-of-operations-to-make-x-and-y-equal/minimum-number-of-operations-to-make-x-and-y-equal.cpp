class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
	if(x == y){
		return 0;
	}        
	vector<int>dist(1e5,INT_MAX);
	
	priority_queue<pair<int,int>, vector<pair<int,int>>,
					greater<pair<int,int>>>q;
	q.push({0,x});
	while(!q.empty()){
		int n = q.top().second;
		int cost = q.top().first;
		q.pop();
		if(n == y){
			return cost;
		}
		if(n%11 == 0 && dist[n/11] > cost + 1){
			dist[n/11] = cost + 1;
			q.push({cost+1,n/11});
		}
		if(n%5 == 0 && dist[n/5] > cost + 1){
			dist[n/5] = cost + 1;
			q.push({cost+1,n/5});
		}
		if(n > 0 && dist[n-1] > cost + 1){
			dist[n-1] = cost + 1;
			q.push({cost+1,n-1});
		}
		if(dist[n+1] > cost + 1){
			dist[n+1] = cost + 1;
			q.push({cost+1,n+1});
		}
	}
	return -1;
}
};