#include<bits/stdc++.h>

using namespace std;

int n , m , x , y , dp[100001];   

vector<int>graph[100001] ;
bitset<100001>visited ;

void dfs1(int now){

    visited[now] = true ;
    
    if(now == n){
        dp[now] = 1 ;
        return ;
    }

    for(auto i : graph[now]){
        if(!visited[i])dfs1(i) ;
        if(dp[i])dp[now] = max(dp[now] , dp[i] + 1) ;
    }

}

void dfs2(int now){

    cout << now << ' ' ;

    int next = 0 ;
    int MAX = 0 ;

    for(auto i : graph[now]){
        if(dp[i] > MAX){
            next = i ;
            MAX = dp[i] ;
        }
    }

    if(next != 0)dfs2(next) ;

}   

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ; 

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        graph[x].push_back(y) ;
    }

    dfs1(1) ;

    if(!visited[n]){
        cout << "IMPOSSIBLE" ;
    }
    else {
        cout << dp[1] << '\n';
        dfs2(1) ;
    }

    return 0 ;
}