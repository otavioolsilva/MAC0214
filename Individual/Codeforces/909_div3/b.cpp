#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 5e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n; cin >> n;

  vector<ll> boxes(n+1, 0), acc(n+1, 0);
  for(int i = 1; i <= n; i++){
    cin >> boxes[i];
    acc[i] = acc[i-1] + boxes[i];
  }

  ll ans = 0;
  for(int k = 1; k <= n/2; k++){ // nem um pouco confiante de que isso passa
    if(n%k == 0){
      ll minimum = INFLL, maximum = -1;
      
      for(int i = k; i <= n; i += k){
        minimum = min(minimum, acc[i] - acc[i-k]);
        maximum = max(maximum, acc[i] - acc[i-k]);
      }

      ans = max(ans, maximum - minimum);
    }
  }

  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

