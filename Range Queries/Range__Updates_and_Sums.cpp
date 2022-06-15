#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1 ;
int n , q , cmd , l , r ;

class Segment {

    public :

        int seg[4 * N] , sum_lazy[4 * N] , init_lazy[4 * N] ;

        void push_sum_lazy(int l , int r , int now){
            if(sum_lazy[now]){
                seg[now] += (r - l + 1) * sum_lazy[now] ;
                sum_lazy[now * 2] += sum_lazy[now] ;
                sum_lazy[now * 2 + 1] += sum_lazy[now] ;
                sum_lazy[now] = 0 ;
            }
        }

        void push_init_lazy(int l , int r , int now){
            if(init_lazy[now]){
                seg[now] = (r - l + 1) * init_lazy[now] ;
                init_lazy[now * 2] = init_lazy[now] ;
                init_lazy[now * 2 + 1] = init_lazy[now] ;
                init_lazy[now] = 0 ;
            }
        }

        void update_sum(int l , int r , int nl , int nr , int val , int now){
            
            push_init_lazy(l , r , now);
            push_sum_lazy(l , r , now);

            if(nl > r || nr < l) return ;
            if(nl >= l && nr <= r){
                sum_lazy[now] = val ;
                return ;
            }
            
        }

};

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    return 0 ;
}