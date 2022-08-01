#include<bits/stdc++.h>

using namespace std ;

//dp[price][level] -> possible ways

struct path {
    long long v , w ;
};

const int N = 1e5 + 1 ;
vector<path>adj[N] ;
long long n , m , x , y , w , ans_dis = INT_MAX , possible = 0 , MIN = INT_MAX , MAX = INT_MIN ; 

void dfs(int now){
    
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ; 

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        adj[x].push_back({y , w});
    }

    dfs();

    return 0 ;
}