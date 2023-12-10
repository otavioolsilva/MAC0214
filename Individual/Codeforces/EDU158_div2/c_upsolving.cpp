#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;

void solve(){
  int n; cin >> n;

  int lower = INF, bigger = -1;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    lower = min(a, lower);
    bigger = max(a, bigger);
  }

  int ans = 0;
  vector<int> ans_arr;

  while(lower != bigger){
    if(lower&1) ans_arr.push_back(1);
    else ans_arr.push_back(0);

    bigger = (bigger + (lower&1))/2;
    lower = (lower + (lower&1))/2;
  
    ans++;
  }

  cout << ans << "\n";
  if(ans <= n && ans > 0){
    for(int a : ans_arr)
      cout << a << " ";
    cout << "\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

