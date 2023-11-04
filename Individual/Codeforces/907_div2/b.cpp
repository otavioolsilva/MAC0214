#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 8010;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n, q;
  cin >> n >> q;

  vector<ll> arr(n);
  for(ll &a : arr) cin >> a;

  vector<int> queries(1);
  cin >> queries[0];
  for(int i = 1; i < q; i++){
    int x; cin >> x;
    if(x < queries.back()) queries.push_back(x);
  }

  for(int x : queries){
    for(ll & a : arr){
      int pot = 0, aux = a;
      while(aux % 2 == 0){
        aux /= 2;
        pot++;
      }

      if(pot >= x)
        a += (1 << (x-1));
    }
  }

  for(ll &a : arr) cout << a << " ";
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

