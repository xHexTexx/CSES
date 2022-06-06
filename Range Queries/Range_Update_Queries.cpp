#include<bits/stdc++.h>

using namespace std ;

const int N = 2e5 + 1 ;

class Segment {

    public :

        long long seg[4 * N] , lazy[4 * N] ;

        void push(int nl , int nr , int now){
            if(lazy[now]){
                seg[now] += (nr - nl + 1) * lazy[now] ;
                lazy[now * 2] += lazy[now] ;
                lazy[now * 2 + 1] += lazy[now] ;
                lazy[now] = 0 ;
            }
        }
        void update(int l , int r , int nl , int nr , long long val , int now){
            push(nl , nr , now) ;
            if(nr < l || nl > r)return ;
            if(nl >= l && nr <= r){
                lazy[now] = val ;   
                return ;
            }
            int mid = (nl + nr) >> 1 ;
            update(l , r , nl , mid , val , now * 2) ; update(l , r , mid + 1 , nr, val , now * 2 + 1); 
        }
        long long query(int nl , int nr , int idx , int now){
            push(nl , nr , now);
            if(nl > idx || nr < idx)return 0 ;
            if(nl == nr){
                return seg[now] ;
            }
            int mid = (nl + nr) >> 1 ;
            return query(nl , mid , idx , now * 2) + query(mid + 1 , nr , idx , now * 2 + 1);
        }
}Seg;

int n , q  , l , r , cmd , idx ;

long long val ;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> val ;
        Seg.update(i , i , 1 , n , val , 1);
    }

    while(q -- ){
        cin >> cmd ;
        if(cmd == 1){
            cin >> l >> r >> val ;
            Seg.update(l , r , 1 , n , val , 1);
        }
        else {
            cin >> idx ;
            cout << Seg.query(1 , n , idx , 1) << '\n';
        }
    }
    return 0 ;
}