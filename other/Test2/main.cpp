#include<cstdio>
#include<map>
using namespace std;
map<int, int> mr, mc;
map<int, map<int, int> > mp;
int main() {
      int T, n, m, k, cas = 0;
      scanf("%d",&T);
      while(T--) {
            mr.clear();
            mc.clear();
            mp.clear();
            scanf("%d %d %d",&n,&m,&k);
            int a, b, c;
            int p = 0, q = 0;
            for(int i = 0; i < k; i++) {
                  scanf("%d %d %d",&a, &b, &c);
                  if(!mr[a])
                        mr[a] = ++p;
                  if(!mc[b])
                        mc[b] = ++q;
                  mp[mr[a]][mc[b]] = c;
            }
            map<int,map<int,int> >::iterator mpit=mp.begin();
            map<int,int> it;
            for(;mpit!=mp.end();++mpit)
            {
                  it=(*mpit).begin();
                  for(;it!=(*mpit).end();++it)
                  {
                        printf("%d ",*it);
                  }
                  puts("");
            }

            int Q, type;
            scanf("%d",&Q);
            printf("Case #%d:\n", ++cas);
            while(Q--) {
                  scanf("%d %d %d",&type, &a, &b);
                  if(type == 1) {
                        int tmp = mr[a];
                        mr[a] = mr[b];
                        mr[b] = tmp;
                  } else if(type == 2) {
                        int tmp = mc[a];
                        mc[a] = mc[b];
                        mc[b] = tmp;
                  } else {
                        printf("%d\n", mp[mr[a]][mc[b]]);
                  }
            }
      }
      return 0;
}
