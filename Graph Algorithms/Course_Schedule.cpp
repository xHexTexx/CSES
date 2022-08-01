#include<bits/stdc++.h>

using namespace std;

int n , m ;
const int N = 1e5 + 1 ;
int visited[N] , x , y ;
bool possible = true , visited2[N] ;

vector<int>adj[N] ;

void cycle(int now){

    if(!possible)return ;

    visited[now] = 1 ;

    for(auto i : adj[now]){
        
        if(visited[i] == 0)cycle(i) ;
        if(visited[i] == 1){
            if(!possible)return ;
            cout << "IMPOSSIBLE" ;
            possible = false ;
            return ;
        }
    }

    visited[now] = 2 ;
}

void dfs(int now){

    for(auto i : adj[now]){
        if(visited2[i])continue ;
        visited2[i] = true ;
        dfs(i) ;
    }
    cout << now << ' ' ;

}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        adj[y].push_back(x) ;
    }

    for(int i = 1 ; i <= n ; i++ ){
        if(!possible){
            return 0 ;
        }
        if(!visited[i])cycle(i) ;
    }

    for(int i = 1 ; i <= n ; i ++){
        if(!visited2[i]){
            visited2[i] = true ;
            dfs(i) ;
        }
    }

    return 0 ;
}