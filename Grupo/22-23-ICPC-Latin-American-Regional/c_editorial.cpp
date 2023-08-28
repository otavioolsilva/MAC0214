// Solução seguindo o editorial, https://codeforces.com/blog/entry/114211

#include <bits/stdc++.h>
using namespace std;
 
void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl
 
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 63;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<ll> p2(MAXN);
void get_power(){
  p2[0] = 1;
  for(int i = 1; i < MAXN; i++)
    p2[i] = 2*p2[i-1];
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  get_power();

  ll n, p, h; cin >> n >> p >> h;

  vector<bool> fold(n, 0);
  for(int i = n-1; i >= 0; i--)
    if(h > p2[i]) h = (2*p2[i]) - h + 1, fold[i] = true;

  string ans = "";
  for(int i = 0; i < n; i++){
    if(fold[i]){
      if(p <= p2[n-i-1]) {
        ans += 'L';
        p = p2[n-i-1] - p + 1;
      } else {
        ans += 'R';
        p = p2[n-i] - p + 1;
      }
    } else {
      if(p <= p2[n-i-1])
        ans += 'R';
      else {
        ans += 'L';
        p -= p2[n-i-1];
      }
    }
  }

  cout << ans << "\n";

  return 0;
}

