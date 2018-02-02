#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int lena = a.length(),lenb = b.length();
    if(lena != lenb)
    {
        cout<<"unequal lengths.\n";
        return 0;
    }
    map<char,string> h;
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
    string ha = "",hb = "",fin = "",tp = "";
    for(int i=0;i<lena;i++)
    {
        ha += h[a[i]];
        hb += h[b[i]];
    }
    int t = 0;
    for(int i=0;i<lena*4;i++)
    {
        int x = ha[i]-'0';
        int y = hb[i]-'0';
        char c = (char)(x ^ y + '0');
        ++t;
        tp += c;
        if(t==4)
        {
            map<char,string>::iterator it = h.begin();
            for(;it!=h.end();it++)
            {
                if(it->second == tp)
                {
                    fin += it->first;
                    break;
                }
            }
            t = 0;
            tp = "";
        }
    }
    cout<<fin<<'\n';
    return 0;
}
