#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 3e5;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n; cin >> n;

  vector<int> elves(n);
  for(int &i : elves)
    cin >> i;

  sort(elves.begin(), elves.end());

  double ans;
  if(n == 5){
    ans = max((double)(elves[4] + elves[3])/2.0 - (double)(elves[2] + elves[0])/2.0,
              (double)(elves[4] + elves[2])/2.0 - (double)(elves[1] + elves[0])/2.0);
  } else {
    ans = (double)(elves[n-1] + elves[n-2])/2.0 - (double)(elves[1] + elves[0])/2.0;
  }

  cout << fixed << setprecision(8) << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

