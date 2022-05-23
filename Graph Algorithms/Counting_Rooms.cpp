#include<bits/stdc++.h>

using namespace std;

struct coor {
    int x , y ;
};

queue<coor>q ;

string graph[1001] ;

int m , n , cnt = 0;

bool is_valid(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= n)return false ;
    return true ;
}

bitset<1001>visited[1001] ;

int dir[] = {0 , 0 , -1 , 1};

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n ;

    for(int i = 0 ; i < m ; i ++ )cin >> graph[i] ;

    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            if(visited[i][j] || graph[i][j] == '#')continue ;
            visited[i][j] = true ;
            cnt ++ ;
            q.push({i , j});
            while(!q.empty()){

                auto temp = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i ++ ){
                    int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i] ;
                    if(!is_valid(nowx , nowy))continue ;
                    if(graph[nowx][nowy] != '.')continue ;

                    if(!visited[nowx][nowy]){
                        visited[nowx][nowy] = true ;
                        q.push({nowx , nowy});
                    }
                }
            }

        }
    }

    cout << cnt ;

    return 0 ;
}