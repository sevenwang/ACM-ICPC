/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-22-17.35
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=1010;
int mat[MAXN*MAXN],ans[MAXN][MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      while(cin>>n)
      {
            for(int i=1;i<=n*n;++i)
                  cin>>mat[i];
            int cnt=1;
            for(int i=n;i>=1;--i) // lie
            {
                  for(int j=1;j<=n;++j) // hang
                  {
                        ans[j][i]=mat[cnt++];
                  }
            }
            for(int i=1;i<=n;++i)
            {
                  for(int j=1;j<=n;++j)
                  {
                        cout<<ans[i][j]<<" ";
                  }
                  cout<<endl;
            }
      }
      return 0;
}
/*

*/
