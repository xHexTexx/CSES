#include<bits/stdc++.h>

using namespace std;

int n , x , y , MAX = 0 , m1 , m2 , dp[200001];

vector<int>adj[200001];

void dfs(int now , int pa){

    for(auto i : adj[now]){
        
    }
    MAX = max(MAX , m1 + m2) ;
    return ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n ; 

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    dfs(1 , -1);

    cout << MAX ;

    return 0 ; 
}