#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100001] ;
vector<int>bridges ;
bitset<100001>visited ;

void dfs(int now){

    visited[now] = true ;

    for(auto i : adj[now]){
        if(visited[i])continue ;
        dfs(i) ;
    }

}

int n , m , x , y ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; i ++ ){
        if(visited[i])continue ;
        bridges.push_back(i) ;
        dfs(i);
    }

    cout << bridges.size() - 1 << '\n' ;

    for(int i = 0 ; i < bridges.size() - 1  ; i ++ ){
        cout << bridges[i] << ' ' << bridges[i + 1] << '\n';
    }

    return 0 ;
}