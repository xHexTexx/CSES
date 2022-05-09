#include<bits/stdc++.h>

using namespace std;

int n ;

int dp[200001] ;

vector<int>graph[200001] ;

void dfs(int now){

    for(auto i : graph[now]){
        dfs(i) ;
        dp[now] += dp[i] + 1 ;
    }

}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ; 

    cin >> n ;
    int x ;
    for(int i = 2 ; i <= n  ; i ++ ){
        cin >> x ;
        graph[x].push_back(i) ;
    }

    dfs(1) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cout << dp[i] << ' ';
    }
    return 0 ;
}