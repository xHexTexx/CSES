#include<bits/stdc++.h>

using namespace std;

struct coor {
    long long v , w , potion ;
    bool operator < (const coor & rhs)const { return rhs.w < w ; } 
};

struct path {
    long long v , w ;
};

const int N = 1e5 + 1 ;

long long dis[N][2];

priority_queue<coor>pq ;

vector<path>adj[N] ;

long long n , m , x , y , w ;

int main(){

    ios_base::sync_with_stdio(false);

    memset(dis , 0x3f3f3f3f , sizeof(dis)) ;

    cin >> n >> m ;
    
    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y >> w ;
        adj[x].push_back({y , w}) ;
    }

    pq.push({1 , 0 , 0});

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;
        
        if(temp.w > dis[temp.v][temp.potion])continue ;
        if(temp.v == n){
            cout << temp.w ;
            return 0 ;
        }
        for(auto i : adj[temp.v]){
            if(temp.w + i.w < dis[i.v][temp.potion]){
                dis[i.v][temp.potion] = temp.w + i.w ;
                pq.push({i.v , temp.w + i.w , temp.potion});
            }
            if(temp.potion == 0){
                if(temp.w + i.w / 2 < dis[i.v][1]){
                    dis[i.v][1] = temp.w + i.w / 2 ;
                    pq.push({i.v , temp.w + i.w / 2 , 1});
                }
            }
        }

    }

    return 0 ;
}