#include<bits/stdc++.h>

using namespace std;

struct edge {
    int u , v ; long long w ;
};

long long dis[2501] ;

int n , m , x , y  ;
long long w , MAX = INT_MIN ;

vector<edge>edges ;


int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        edges.push_back({x , y , -w}) ;
    } 
    
    for(int i = 1 ; i <= n ; i ++ )dis[i] = 1e9 ;
    dis[1] = 0 ;

    for(int i = 0 ; i < n - 1 ; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            
            x = edges[j].u , y = edges[j].v , w = edges[j].w ;
            if(dis[y] > dis[x] + w ){
                dis[y] = dis[x] + w ; 
            }

        }
    }

    for(int j = 0 ; j < m ; j ++ ){
            
        x = edges[j].u , y = edges[j].v , w = edges[j].w ;
        if(dis[y] > dis[x] + w ){
            cout << -1 ;
            return 0 ;
        }

    }

    cout << - dis[n] ;

    

    return 0 ;
}