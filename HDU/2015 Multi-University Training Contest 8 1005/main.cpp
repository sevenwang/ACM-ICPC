/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-13-20.20
* Time: 0MAXNS
* MAXNemory: 137KB
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

const int MAXN = 50+(int)1e5;
class node
{
public:
      bool flag;
      int cnt;
      node *fail, *next[26];
      node()
      {
            cnt=0;
            flag = false;
            fail = NULL;
            memset(next, NULL, sizeof next);
      }
};
node *root;
queue<node*> q;
char s[MAXN], str[MAXN];
char art[MAXN][10010];

void Insert(char *str)   // build Trie-Tree
{
      node *p = root;
      int i = 0, index;
      while(str[i])
      {
            index = str[i] - 'a';
            if(p->next[index] == NULL)
                  p->next[index] = new node();
            p = p->next[index];
            ++i;
      }
      p->flag = true;
      p->cnt++;
}

void build_ac_automation(node *root)   // build fail ptr
{
      root->fail = NULL;
      while(!q.empty()) q.pop();
      q.push(root);
      while(!q.empty())
      {
            node *temp = q.front(); q.pop();
            node *p = NULL;
            for(int i = 0; i < 26; ++i)
            {
                  if(temp->next[i] != NULL)
                  {
                        if(temp == root) temp->next[i]->fail = root;
                        else
                        {
                              p = temp->fail;
                              while(p != NULL)
                              {
                                    if(p->next[i] != NULL)
                                    {
                                          temp->next[i]->fail = p->next[i];
                                          break;
                                    }
                                    p = p->fail;
                              }
                              if(p == NULL) temp->next[i]->fail = root;
                        }
                        q.push(temp->next[i]);
                  }
            }
      }
}


int query(node *root ,int idx)   // mathing and counting
{
      node *p = root;
      int i = 0, ans = 0, index;
      while(art[idx][i])
      {
            index = art[idx][i] - 'a';
            while(p->next[index] == NULL && p != root)
                  p = p->fail;
            p = p->next[index];
            if(p == NULL)
                  p = root;
            node *temp = p;
            while(temp != root)
            {
                  if(temp->cnt>0) ans+=temp->cnt;
//                  temp->flag = false;
                  temp = temp->fail;
            }
            i++;
      }
      return ans;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int Cas;
      scanf("%d", &Cas);
      while(Cas--)
      {
            root = new node();
            int n,m;
            scanf("%d %d", &n ,&m);
            for(int i=0; i<n; ++i)
            {
                  scanf("%s", art[i]);
            }
            while(m--)
            {
                  scanf("%s", s);
                  Insert(s);
            }
            build_ac_automation(root);
            for(int i=0; i<n; ++i)
            {
                  printf("%d\n",query(root,i));
            }
      }
      return 0;
}
/*

*/
