#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
      return false;
  }
  return true;
}

bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < int >> & dp) {

  //Base Conditions
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0)
    return isAllStars(S1, i);
    //cout<<i<<" "<<j<<endl;
  if (dp[i][j] != -1) return dp[i][j];

  if (S1[i] == S2[j] || S1[i] == '?')
    return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

  else {
    //cout<<"Hey\n";
    if (S1[i] == '*')
      return dp[i][j]=wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
  }
  return false;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < int >> dp(n, vector < int > (m, -1));
  return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);

}
// tabulation
// bool wildcardMatching(string & S1, string & S2) {

//   int n = S1.size();
//   int m = S2.size();

//   vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

//   dp[0][0] = true;

//   for (int j = 1; j <= m; j++) {
//     dp[0][j] = false;
//   }
//   for (int i = 1; i <= n; i++) {
//     dp[i][0] = isAllStars(S1, i);
//   }

//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {

//       if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
//         dp[i][j] = dp[i - 1][j - 1];

//       else {
//         if (S1[i - 1] == '*')
//           dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

//         else dp[i][j] = false;
//       }
//     }
//   }

//   return dp[n][m];

// }
int main() {


    int t;
    cin>>t;
    while(t--){
        string S1 ;
        string S2 ;
        cin>>S1>>S2;
        if (wildcardMatching(S1, S2))
            cout << "True\n";
        else cout << "False\n";
    }

}