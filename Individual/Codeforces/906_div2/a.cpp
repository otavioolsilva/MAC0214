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
  int n; cin >> n;

  multiset<int> cont;
  vector<int> num;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    
    if(cont.find(a) == cont.end())
      num.push_back(a);

    cont.insert(a);
  }

  if(num.size() > 2 ||
      (num.size() == 2 && abs((int)cont.count(num[0]) - (int)cont.count(num[1])) > 1))
    cout << "No\n";
  else cout << "Yes\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  for(int i = 1; i <= t; i++)
    solve();

  return 0;
}

