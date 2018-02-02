#include <bits/stdc++.h>
using namespace std;

int main()
{
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
    string s;
    cin>>s;
    int n = s.length();
    string asc = "";
    for(int i=0;i<n;i+=2)
    {
        int k = 0;
        string l = h[s[i]] + h[s[i+1]];
        int p = 1;
        for(int j=7;j>=0;j--)
        {
            k += p*(l[j]-'0');
            p = p*2;
        }
        asc += (char)k;
    }
    vector<string> v;
    for(int i = 0;i<26;i++)
    {
        string st = "";
        for(int j = 0;j<asc.length();j++)
        {
            st+=(char)(asc[j]^(i+'a'));
        }
        //cout<<((char)(i + 'a'))<<": "<<st<<'\n';
        v.push_back(st);
    }
    int x = asc.length();
    double freq[] = {11.7,4.4,5.2,3.1,2.8,4,1.6,4.2,7.3,0.5,0.4,2.4,3.8,2.3,7.6,4.3,0.2,2.8,6.7,15.9,1.2,0.8,5.5,0.0,0.7,0.0};
    double best = 1000;
    int idx = -1;
    for(int i=0;i<26;i++)
    {
        vector<double> f(26,0);
        double cost = 0;
        string g = v[i];
        for(int j=0;j<x;j++)
        {
            if(g[j] >= 97 && g[j]<=122) ++f[g[j]-'a'];
            else if(g[j] >= 65 && g[j]<=90) ++f[g[j]-'A'];
        }
        for(int j=0;j<26;j++)
        {
            f[j] = f[j]/x;
            cost += (f[j] - freq[j])*(f[j] - freq[j]);
        }
        if(cost < best)
        {
            best = cost;
            idx = i;
        }
    }
    cout<<"best: "<<(char)(idx+'a')<<' '<<v[idx]<<'\n';
    return 0;
}
