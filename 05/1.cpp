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

pll getIn(string s) {
    ll n = s.length();
    ll x, y;
    x = y = 0;
    ll t = 0;
    bool ok = 0;
    f(i, 0, n) {
        if(s[i] == ',') {
            ok = 1;
            t = 0;
            continue;
        }

        if(!ok) {
            x *= 10;
            x += (s[i] - '0');
        } else {
            y *= 10;
            y += (s[i] - '0');
        }
    }
    return {x, y};
}

void solve()
{
    string s, notRequired;
    map<pll, ll> mp;
    while(cin >> s) { 
        pll left = getIn(s);
        cin >> notRequired; // the arrow;
        cin >> s;           // the right side coordinates;
        pll right = getIn(s);
        
        ll x1 = left.ff;
        ll y1 = left.ss;
        ll x2 = right.ff;
        ll y2 = right.ss;

        if(x1 == x2) {
            if(y1 > y2) 
                swap(y1, y2);
            f(i, y1, y2 + 1) {
                mp[{x1, i}] += 1;
            }
        }
        else if (y1 == y2) {
            if(x1 > x2) 
                swap(x1, x2);
            f(i, x1, x2 + 1) {
                mp[{i, y1}] += 1;
            }
        }

    }
    
    // for(auto it: mp) {
    //     deb2(it.ff.ff, it.ff.ss)
    //     deb(it.ss)
    //     cout << endl;
    // }

    ll cnt = 0;
    for(auto it: mp) {
        if(it.ss >= 2) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
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