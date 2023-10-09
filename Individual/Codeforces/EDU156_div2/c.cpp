#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

ll f(ll x){ return (x*(x+1))/2; }

void solve(){
  string s; cin >> s;

  set<pair<int, char>> ss;
  for(int i = 1; i <= (int)s.size(); i++)
    ss.emplace(i, s[i-1]);

  ll pos; cin >> pos;

  ll n = s.size();
  ll total = f(n);
  ll pos_rev = total - pos + 1;

  ll l = 1, r = n, step = -1;
  while(l <= r){
    ll m = (l+r)/2;

    if(f(m) >= pos_rev){
      step = m;
      r = m-1;
    } else
      l = m+1;
  }

  ll pos_final = pos_rev - f(step-1);

  step = n - step + 1; // qual string que estamos olhando (em qual passo estamos)
  auto it = ss.begin();
  it++;

  while(step > 1){
    auto aux = it;

    if(it == ss.end()){
      aux--;
      ss.erase(aux);
    } else {
      aux--;

      while(it != ss.end() && it->second >= aux->second){
        aux = it;
        it++;
      }

      ss.erase(aux);
    }

    step--;
  }

  vector<char> sf(ss.size());
  int k = 0;
  for(auto [i, c] : ss) sf[k++] = c;

  cout << sf[sf.size() - pos_final];
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  cout << "\n";

  return 0;
}

