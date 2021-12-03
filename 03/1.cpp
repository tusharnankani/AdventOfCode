#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

typedef pair<ll,ll>             pll;
typedef vector<ll>              vll;
typedef vector<pll>             vpll;
typedef map<ll, ll>             mll;
typedef map<char, ll>           mcl;

#define inf                 1<<30
#define mx9                 1000000007
#define test(t)             int t; cin >> t; while(t--)
#define f(i, a, b)          for(int (i) = (a); (i) < (b); ++(i))
#define all(a)              (a).begin(), (a).end()
#define endl                "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define deb(x)              cout << #x << ": " << x << endl;
#define deb2(x,y)           cout << #x << ": " << x << " ~ " <<  #y << ": " << y << endl;
#define deba(arr)           cout << #arr << " ~ [ "; for(auto n: arr) cout << n << " "; cout << "]" << endl;
#define debap(arr)          cout << #arr << " ~ [ "; for(auto n: arr) cout << n.first << "-" << n.second << " "; cout << "]" << endl;
#define fast                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll str (string s) {
    reverse(all(s));
    ll ans = 0, t = 0;
    f(i, 0, s.length()) {
        ans += ((s[i] - '0') * pow(2, t++));
    }
    return ans;
}

void solve()
{
    string s;
    vpll a;
    while (cin >> s) {
        string curr = s;
        if(!a.size()) {
            f(i, 0, s.size()) {
                ll x = (s[i] == '0');
                ll y = (s[i] == '1');
                a.pb({x, y});
            }
        } else {
            f(i, 0, s.size()) {
                a[i].ff += (s[i] == '0');
                a[i].ss += (s[i] == '1');
            }
        }
    }
    string gamma = "", epsilon = "";
    for(auto it: a) {
        if(it.ff > it.ss) {
            gamma += "0";
            epsilon += "1";
        }
        else {
            gamma += "1";
            epsilon += "0";
        }
    }
    cout << str(gamma) * str(epsilon) << endl;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // test(t)
        solve();
    return 0;
}