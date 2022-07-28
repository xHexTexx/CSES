#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;

int depth[N] , dp[N], m1 , m2 , ans = 0 , x , y , n ;
vector<int>adj[N] ;

void dfs(int now , int pa , int level){

    depth[now] = level ;
    dp[now] = level ;
    
    m1 = level , m2 = level ;
    
    for(auto i : adj[now]){
        if(i == pa)continue ;
        
        dfs(i , now , level + 1) ;
        
        dp[now] = max(dp[now] , dp[i]) ;
        if(dp[i] > m1){
            m2 = m1 ;
            m1 = dp[i] ;
        }
        else if(dp[i] > m2){
            m2 = dp[i] ;
        }
        
    }
    
    ans = max(ans , m1 - depth[now] + m2 - depth[now]) ;
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

    cout << ans ; 

    return 0 ; 
}