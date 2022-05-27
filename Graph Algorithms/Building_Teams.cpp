#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100001] ;
int grp[100001] , n , m , x , y ;
bitset<100001>visited ;
bool possible = true ;

void dfs(int now , int pa){

    if(!possible)return ;

    visited[now] = true ;

    for(auto v : adj[now]){
        
        if(v == pa)continue ;

        if(!visited[v]){
            grp[v] = !grp[now] ;
            dfs(v , now) ;
        }
        else {
            if(grp[now] == grp[v]){
                possible = false ;
                return ;
            }
        }
    }

    return ;
}

int main(){

    ios_base::sync_with_stdio(0);

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; i ++ ){
        if(!visited[i]){
            dfs(i , - 1);
        }
    }

    if(!possible){
        cout << "IMPOSSIBLE" ;
        return 0 ;
    }

    for(int i = 1 ; i <= n ; i ++ )(grp[i]) ? cout << 2 << ' ': cout << 1 << ' ' ;

    
    return 0 ;
}