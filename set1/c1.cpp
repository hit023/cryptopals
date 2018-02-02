#include <bits/stdc++.h>
using namespace std;
vector<char> t(64);
map<char,string> h;
int main()
{
    for(int i=0;i<26;i++)
    {
        t[i] = (char)('A' + i);
    }
    for(int i=26;i<52;i++)
    {
        t[i] = (char)('a' + i - 26);
    }
    for(int i=52;i<62;i++)
    {
        t[i] = (char)('0' + i - 52);
    }
    t[62] = '+';
    t[63] = '/';
    for(int i = 0;i<=9;i++)
    {
        string s = "0000";
        int t = 3,j = i;
        while(t >= 0)
        {
            s[t] = (char)(j%2==1) + '0';
            j = j/2;
            --t;
        }
        //cout<<"k: "<<k<<'\n';
        h[(char)i + '0'] = s;
    }
    h['a'] = "1010";
    h['b'] = "1011";
    h['c'] = "1100";
    h['d'] = "1101";
    h['e'] = "1110";
    h['f'] = "1111";
    string s;
    string bin = "",ans = "";
    cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        bin += h[s[i]];
    }
    int idx = 0;
    int len = bin.length(),f=0;
    while(len%6!=0)
    {
        bin += '0';
        ++len;
    }
    cout<<"bin: "<<bin<<'\n';
    while(idx<len)
    {
        int tp = 5, k =0, p =1;
        while(idx +tp < len && tp >= 0)
        {
            k += p*(bin[idx + tp]-'0');
            --tp;
            p = 1<<(5-tp);
        }
        //cout<<"k: "<<k<<'\n';
        /*if(tp>=0)
        {
            int j = len - idx;
            while(6-j>0)
            {
                bin += '0';
                ++j;
            }
            f=1;
        }*/
        ans += t[k];
        if(idx + 6 < len)
        {
            idx += 6;
        }
        else break;
    }
    cout<<ans<<'\n';
    return 0;
}
