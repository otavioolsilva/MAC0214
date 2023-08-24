#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin >> n;

  vector<int> a, b(n);
  for(int& i : b)
    cin >> i;

  a.push_back(b[0]);
  for(int i = 1; i < n; i++){
    if(b[i] < a.back()){
      a.push_back(b[i]);
    }

    a.push_back(b[i]);
  }

  cout << a.size() << "\n";
  for(int& i : a)
    cout << i << " ";
  cout << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}
