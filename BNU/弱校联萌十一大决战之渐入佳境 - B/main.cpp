/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-14.45
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
const int MAXN=1e6+10;

struct node
{
      int len,id,fa;
      node() {}
      node(int l,int i,int f):len(l),id(i),fa(f) {}
      bool operator<(const node& a)const
      {
            return len<a.len || (len==a.len && id>a.id);
      }
};


int cnt=-1;
int l[MAXN];
vector<LL> sum;
multiset<node> ms;
vector<int> gr[MAXN];
vector<pair<int,int> > res; // (fa,len)

void bfs(int x)
{
      while(ms.size()>0)
      {
            node now=*ms.begin();
            ms.erase(ms.begin());
            res.push_back(make_pair(now.fa,now.len));
            for(int i=0; i<gr[now.id].size(); ++i)
            {
                  int v=gr[now.id][i];
                  ms.insert(node(l[v],v,res.size()-1));
            }
      }
}
vector<int> ve;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      scanf("%d",&n);
      int len,f;
      for(int i=0; i<n; ++i)
      {
            scanf("%d %d",&len,&f);
            l[i]=len;
            if(f!=-1)
                  gr[f].push_back(i);
            else ve.push_back(i);
      }
      if(ve.size()==0)
      {
            printf("0");
            return 0;
      }
      long long sol=0;
      for(int i=0;i<ve.size();++i)
      {
            ms.clear();
            sum.clear();
            ms.insert(node(l[ve[i]],ve[i],-1));
            bfs(ve[i]);
            LL ans=0;

            sum.push_back(res[0].second);
            for(int i=1; i<res.size(); ++i)
            {
                  sum.push_back(sum[i-1]+res[i].second);
            }
            for(int i=1; i<res.size(); ++i)
            {
                  ans+=(sum[i-1]-sum[res[i].first]);
            }
            sol+=ans;
      }
      printf("%lld\n",sol);
      return 0;
}
/*

*/
