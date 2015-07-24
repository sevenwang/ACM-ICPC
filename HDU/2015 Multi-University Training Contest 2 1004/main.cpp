/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-24-11.03
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

LL L,N,K;
multiset<pair<int,int> > apple;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int cas;
      cin>>cas;
      while(cas--)
      {
            cin>>L>>N>>K;
            int x,m;
            int cnt=1;
            for(int i=0;i<N;++i)
            {
                  cin>>x>>m;
                  while(m--)
                  {
                        apple.insert(make_pair(x,cnt++));
                  }
            }
            LL ans=0;
            LL mid=L/2;
            multiset<pair<int,int> >::iterator ibe=apple.begin(),it,tmp;
            multiset<pair<int,int> >::iterator ien=apple.end();
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

            for(it=apple.begin();it!=apple.end();++it)
            {
                  cout<<(*it).first<< " "<<(*it).second<<endl;
            }
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

            int container;
            for(;ibe!=apple.end() && (*ibe).first<mid;)
            {
                  container=0;
                  while(container!=K && (*ibe).first<mid)
                  {
                        ibe++;
                        container++;
                  }
                  if(container==K)
                  {
                        it=ibe;
                        ans+=(*it).first*2;
                        for(int i=0;i<K;++i)
                        {
                              it=apple.begin();
                              apple.erase(*it);
                        }
                  }
                  else break;
            }
            cout<<ans<<endl;
            for(;ien!=apple.begin() && (*ien).first>=mid;)
            {
                  container=0;
                  while(container!=K && (*ien).first>=mid)
                  {
                        ien--;
                        container++;
                  }
                  if(container==K)
                  {
                        it=ien;
                        ans+=(L-(*it).first)*2;
                        for(int i=0;i<K;++i)
                        {
                              it=apple.end();
                              apple.erase(*it);
                        }
                  }
                  else break;
            }
            int si=apple.size();
            if(si<K)
            {
                  ans+=L; // run a cycle
            }
            else  // 3 case
            {
                  int r=-1-0x7fffffff,l=0x7fffffff;
                  multiset<pair<int,int> > :: iterator it;
                  for(it=apple.begin();it!=apple.end();++it)
                  {
                        if((*it).first<mid) r=max(r,(*it).first);
                        else l=min(l,(*it).first);
                  }
                  LL dis1=0,dis2=0,dis3=0;
                  if(r!=-1-0x7fffffff)
                  {
                        dis1+=r;
                  }
                  if(l!=0x7fffffff)
                  {
                        dis1+=L-l;
                  }
                  for(container=0,it=apple.begin();it!=apple.end()&&container !=K;++it,++container){}
                  dis2+=L+(L-(*it).first)*2;

                  for(container=0,it=apple.end();it!=apple.begin()&&container!=K;--it,container++){}
                  dis3+=L+(*it).first*2;
                  LL dis=min(dis1,min(dis2,dis3));
                  ans+=dis;
            }
            cout<<ans<<endl;


      }
      return 0;
}
/*

*/
