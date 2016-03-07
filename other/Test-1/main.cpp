/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-18.36
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

void str_num_multi(string str,int num,string& res)
{
    cout<<str<<endl;
    cout<<num<<endl;
    int carry=0;
    for(int i=0; i<str.length(); ++i)
    {
        int now=num*(str[i]-'0')+carry;
        carry=now/10;
        now%=10;
        res.push_back(char(now+'0'));
    }
    if(carry)
        res.push_back(char(carry+'0'));
}

int main()
{
    string str;
    int num;
    string res;
    cin>>str>>num;
    str_num_multi(str,num,res);
    cout<<res<<endl;
    return 0;
}
/*

*/
