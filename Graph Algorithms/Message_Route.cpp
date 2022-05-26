#include<bits/stdc++.h>

using namespace std;

struct coor {
    int v , t ;
};

int pa[100001] ;

void fp(int x){
    
    if(pa[x] == -1){
        cout << 1 << ' ';
        return ;
    }
    fp(pa[x]) ;
    cout << x << ' ';
}

vector<int>adj[100001] ;

bitset<100001>visited ;

int n , m , x , y ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    cin >> n >> m ; 

    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    queue<coor>q ;
    
    q.push({1 , 1});
    visited[1] = true ;
    pa[1] = -1;

    while(!q.empty()){

        auto temp = q.front() ;
        q.pop() ;

        if(temp.v == n){
            cout << temp.t << '\n' ;
            fp(n) ;
            return 0 ;
        }
        for(auto i : adj[temp.v]){
            if(visited[i])continue ;
            visited[i] = true ;
            pa[i] = temp.v ;
            q.push({i , temp.t + 1}) ;
        }

    }

    cout <<  "IMPOSSIBLE" ;

    return 0 ;
}