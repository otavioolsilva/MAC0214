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

void solve(){
  int n, m; cin >> n >> m;
  string s; cin >> s;

  vector<pair<int, int>> count(n); // {próximo 1 à minha direita, próximo 0 à minha esquerda}
  for(int i = 0; i < n; i++){
    if(s[i] == '0') count[i].second = i;
    else count[i].second = (i == 0 ? -1 : count[i-1].second);
  }
  for(int i = n-1; i >= 0; i--){
    if(s[i] == '1') count[i].first = i;
    else count[i].first = (i == n-1 ? n : count[i+1].first);
  }

  set<pair<int, int>> ans;
  bool flag = false;
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    
    l = count[l-1].first; r = count[r-1].second;

    if(l < r) ans.emplace(l, r);
    else if(!flag) ans.emplace(-1, -1), flag = true;
  }

  cout << ans.size() << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

