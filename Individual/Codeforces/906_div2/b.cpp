#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 8010;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;

  int mod[2] = {0, 0};
  for(int i = 0; i < n-1; i++)
    if(s[i] == s[i+1])
      mod[s[i]-'0']++;

  if(mod[0] == 0 && mod[1] == 0){ // string s já é boa
    cout << "Yes\n";
    return;
  }

  for(int i = 0; i < m-1; i++){ // string t é ruim, não tem como ajeitar s
    if(t[i] == t[i+1] || (m&1) == 0){
      cout << "No\n";
      return;
    }
  }

  if((t[0] == '0' && mod[0] == 0) || (t[0] == '1' && mod[1] == 0))
    cout << "Yes\n";
  else
    cout << "No\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  for(int i = 1; i <= t; i++)
    solve();

  return 0;
}

