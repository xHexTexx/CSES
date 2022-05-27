#include<bits/stdc++.h>

using namespace std;

int n , m , x , y ;
int pa[100001] ;
 
bitset<100001>visited ;
vector<int>adj[100001] ;
bool found = false ;
int str ;

void dfs(int now , int par){

    if(found){
        return ;
    }
    visited[now] = true ;
    for(auto i : adj[now]){
        if(i == par)continue ;
        if(found)return ;

        if(!visited[i]){
            pa[i] = now ;
            dfs(i , now) ;
        }
        else {
            found = true ;
            pa[i] = now ;
            str = i ;
            return ;
        }
    }
}

void fp(int x){
    if(x == str){
        cout << x << ' ' ;
        return ;
    }
    fp(pa[x]);
    cout << x << ' ' ;
    
}

int cnt(int x){
    if(x == str){
        return 1 ;
    }
    return 1 + cnt(pa[x]) ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n ; i++ ){
        if(!visited[i])
            dfs(i , -1) ;
    }

    if(!found){
        cout << "IMPOSSIBLE" ;
        return 0;
    }
    cout << cnt(pa[str]) + 1 << '\n' ;
    fp(pa[str]) ;
    cout << str << ' ';
    return 0 ;
}