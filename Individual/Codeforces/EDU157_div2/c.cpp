#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4+10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f;

vector<string> ticket;

ll odd_all[6][50], odd_3pref1[50], odd_5pref1[50], odd_5pref2[50],
                   odd_3suf1[50], odd_5suf1[50], odd_5suf2[50];
ll even_all[6][50], even_4pref1[50], even_4suf1[50];

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  
  ll ans = 0;
  ticket.resize(n);

  // computando só com tickets do mesmo tamanho
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    ticket[i] = s;

    int sum = 0, len = (int)s.size();
    for(char c : s) sum += (int) c-'0';

    if(len&1){ // odd
      ans += 2*odd_all[len][sum];

      if(len == 1){
        odd_all[1][sum]++;
      } else if(len == 3){
        odd_all[3][sum]++;
        odd_3pref1[sum - 2*(((int)s[0]-'0'))]++;
        odd_3suf1[sum - 2*((int)s[2]-'0')]++;
      } else {
        odd_all[5][sum]++;
        odd_5pref2[sum - 2*(((int)s[0] - '0') + ((int)s[1] - '0'))]++;
        odd_5pref1[sum - 2*(((int)s[0] - '0'))]++;
        odd_5suf2[sum - 2*(((int)s[3] - '0') + ((int)s[4] - '0'))]++;
        odd_5suf1[sum - 2*(((int)s[4] - '0'))]++;
      }
    } else { // even
      ans += 2*even_all[len][sum];

      if(len == 2){
        even_all[2][sum]++;
      } else {
        even_all[4][sum]++;
        even_4pref1[sum - 2*(((int)s[0] - '0'))]++;
        even_4suf1[sum - 2*(((int)s[3] - '0'))]++;
      }
    }
  }

  // computando juntar com tickets de outros tamanhos;
  for(int i = 0; i < n; i++){
    int sum = 0, len = (int)ticket[i].size();
    for(char c : ticket[i]) sum += (int) c-'0';

    if(len&1){ // odd
      if(len == 1){
        ans += odd_3pref1[sum];
        ans += odd_3suf1[sum];
        ans += odd_5pref2[sum];
        ans += odd_5suf2[sum];
      } else if(len == 3){
        ans += odd_5pref1[sum];
        ans += odd_5suf1[sum];
      }
    } else { // even
      if(len == 2){
        ans += even_4pref1[sum];
        ans += even_4suf1[sum];
      }
    }
  }

  cout << ans+n << "\n";

  return 0;
}

