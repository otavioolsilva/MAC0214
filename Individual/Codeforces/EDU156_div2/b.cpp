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

ll dist2(pair<ll, ll> a, pair<ll ,ll> b){
  return (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
}

void solve(){
  pair<ll, ll> o, p, a, b;
  o = make_pair(0, 0);
  cin >> p.first >> p.second;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;

  if(p.first == 0 && p.second == 0){
    cout << "0\n";
    return;
  }

  double ans = 0;
  ll dist_oa = dist2(o, a), dist_ob = dist2(o, b);

  if(dist_oa == dist_ob){
    if(dist2(p, a) > dist2(p, b)){ // garante P mais próximo (ou igual) de A
      swap(a, b);
      swap(dist_oa, dist_ob);
    }

    if(dist2(p, a) <= dist_oa) ans = (double)dist_oa; // P dentro de A
    else ans = dist2(p, a); // P fora de A
  } else {
    if(dist_oa > dist_ob){ // garante O dentro de A
      swap(a, b);
      swap(dist_oa, dist_ob);
    }

    if(dist2(p, a) <= dist_oa) ans = (double)dist_oa; // P dentro de A
    else {
      if(dist2(p, b) <= dist_oa) ans = max((double)dist_oa, (double)dist2(a, b)/4.0); // P dentro de B
      else { // P fora de B
        ans = (double)dist2(p, a);

        if(dist2(p, b) > max((double)dist_oa, (double)dist2(a, b)/4.0)) // intersecção não alcança P
          ans = min(ans, (double)dist2(p, b));
        else                                                            // intersecção alcança P
          ans = min(ans, max((double)dist_oa, (double)dist2(a, b)/4.0)); 
      }
    }
  } 

  cout << fixed << setprecision(10) << sqrt(ans) << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

