#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

int depth , x , y , n , s , MAX = 0;
vector<int>adj[N] ;

void dfs(int now , int pa , int level){

    if(level > MAX){
        MAX = level ;
        s = now ;
    }
    for(auto i : adj[now]){
        if(i == pa)continue ;
        dfs(i , now , level + 1) ;
    }

}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i =  0 ; i < n - 1 ;  i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    dfs(1 , -1 , 1) ;
    dfs(s , -1 , 1) ;

    cout << MAX - 1 ;

    return 0 ; 
}