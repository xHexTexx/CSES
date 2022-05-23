#include<bits/stdc++.h>

using namespace std;

struct coor {
    short x , y , t ;
    string path ;
};

queue<coor>q ;

string graph[1001] ;

short m , n , cnt = 0;

bool is_valid(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= n)return false ;
    return true ;
}

bool visited[1001][1001] ;

short dir[] = {0 , 0 , -1 , 1};
char dirc[] = {'R' , 'L' , 'U' , 'D'};

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n ;

    for(int i = 0 ; i < m ; i ++ )cin >> graph[i] ;

    for(short i = 0 ; i < m ; i ++ ){
        for(short j = 0 ; j < n ; j ++ ){
            if(visited[i][j] || graph[i][j] != 'A')continue ;
            visited[i][j] = true ;
            q.push({i , j , 0 , ""});
            while(!q.empty()){

                auto temp = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i ++ ){
                    short nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i] , nowt = temp.t + 1;
                    if(!is_valid(nowx , nowy))continue ;
                    if(graph[nowx][nowy] == '#')continue ;

                    if(graph[nowx][nowy] == 'B'){
                        cout << "YES\n" << nowt << '\n' << temp.path + dirc[i];
                        return 0 ; 
                    }

                    if(!visited[nowx][nowy]){
                        visited[nowx][nowy] = true ;
                        q.push({nowx , nowy , nowt , temp.path + dirc[i]});
                    }
                }
            }

        }
    }

    cout << "NO" ;

    return 0 ;
}