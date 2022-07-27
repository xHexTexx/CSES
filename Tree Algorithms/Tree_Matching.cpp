#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;
vector<int>adj[N] ;
int dp[N][2] , n ,x , y ;

void dfs(int now , int pa){

    for(auto i : adj[now]){
        if(i == pa)continue ;
        dfs(i , now) ;
        dp[now][0] += dp[i][1] ;
    }
    for(auto i : adj[now]){
        if(i == pa)continue ;
        dp[now][1] = max(dp[now][1] , dp[now][0] + dp[i][0] + 1 - dp[i][1] );
    }

}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ;  i < n - 1 ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    dfs(1 , -1) ;

    cout << max(dp[1][0] , dp[1][1]); 
    
    return 0 ;
}