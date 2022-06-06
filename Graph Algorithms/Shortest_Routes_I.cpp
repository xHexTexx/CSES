#include<bits/stdc++.h>

using namespace std;

struct path {
    int v , w ;
};

struct coor {
    int v ; long long w ;
    bool operator < (const coor & rhs)const { return rhs.w < w ;}
};

vector<path>adj[100001] ;

long long dis[100001] , w ; 
int n , m , x , y ;

priority_queue<coor>pq ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        adj[x].push_back({y , w});
    }

    for(int i = 1 ; i <= n ; i ++ ){
        dis[i] = LLONG_MAX ;
    }
    
    dis[1] = 0 ;
    pq.push({1 , 0});

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        for(auto i : adj[temp.v]){
            int nowv = i.v ; long long noww = temp.w + i.w ; 
            if(dis[nowv] > noww){
                dis[nowv] = noww ;
                pq.push({nowv , noww});
            }
        }
    } 

    for(int i = 1 ; i <= n ; i ++ ){
        cout << dis[i] << ' ' ;
    }
    return 0 ;
}