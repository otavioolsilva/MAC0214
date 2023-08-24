#include <bits/stdc++.h>
using namespace std;

char grid[22][22];

void solve(){
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> grid[i][j];

  if(m < 4){ cout << "NO\n"; return; }

  char targets[4] = {'v', 'i', 'k', 'a'};
 
  int k = 0, j = 0;
  while(k < 4 && j < m){
    for(int i = 0; i < n; i++){
      if(grid[i][j] == targets[k]){ 
        k++;
        break;
      }
    }
    j++;
  }

  if(k == 4) cout << "YES\n";
  else cout << "NO\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}
