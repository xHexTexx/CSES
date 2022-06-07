#include <bits/stdc++.h>

using namespace std;

int qs[1001][1001] ;
char forest[1001][1001] ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    int n , q  ;
    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> forest[i][j] ;
            if(forest[i][j] == '*'){
                qs[i][j] ++ ;
            }
            qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1] ;
        }
    }

    while(q -- ){
        int y1 , x1 , y2 , x2 ;
        cin >> y1 >> x1 >> y2 >> x2 ;
        cout << qs[y2][x2] - qs[y2][x1 - 1] + qs[y1 - 1][x1 - 1] - qs[y1 - 1][x2] << '\n' ; 
    }
    return 0 ;
}
