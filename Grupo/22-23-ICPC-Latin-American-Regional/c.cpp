#include <bits/stdc++.h>
using namespace std;
 
void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl
 
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

ll two_power[63];
void calculate_power(){
  ll pot = 1;
  for(ll i = 0; i < 63; i++){
    two_power[i] = pot;
    pot *= 2;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, p, h;
  cin >> n >> p >> h;

  auto bsearch = [&](ll x){
    ll l = 1, r = (1LL << n), mid;
    string ret = "";

    while(l < r){
      mid = (l+r)/2;

      if(x <= mid){
        r = mid;
        ret += 'R';
      } else {
        l = mid+1;
        ret += 'L';
      }
    }

    return ret;
  };

  string aux = bsearch(p);
  assert(aux.size() == n);

  calculate_power();

  ll x = 1, y = h; // {x, y} = posição atual do bloco {1, h} voltando a sequência de aux

  for(ll i = n-1; i >= 0; i--){
    ll Hx = two_power[n - i - 1];
    ll Hy = two_power[i];

    if(y <= Hy){
      // se já abaixo do corte, altura (y) não muda
      // e x muda se o movimento foi L

      if(aux[i] == 'L')
        x += Hx;
    }
    else{
      // se tá acima do corte, altura cai proporcionalmente
      // e x tbm, só tomar cuidado com o lado (dobrado se for R)

      y = (2*Hy) - y + 1;

      if(aux[i] == 'L'){
        x = Hx - x + 1;
      } else {
        x = (2*Hx) - x + 1;
      }
    }
  }

  aux = bsearch(x);

  cout << aux << "\n";

  return 0;
}


