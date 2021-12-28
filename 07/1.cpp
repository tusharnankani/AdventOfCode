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

void solve()
{
    string s;
    cin >> s;
    vll order;
    ll curr = 0;
    f(i, 0, s.length()) {
        if(s[i] == ',') {
            order.pb(curr);
            curr = 0;
        } else {
            curr = curr * 10 + (s[i] - '0');
        }
    }
    order.pb(curr);
    // deba(order)
    
    map<ll, ll> mp;
    set<ll> st;
    for(auto it: order) {
        mp[it] += 1;
        st.insert(it);
    }
    // deba(st)
    // debap(mp)

    ll ans = LONG_MAX;
    for(auto it: st) {
        ll curr = 0;
        for(auto x: mp) {
            curr += (x.ss * abs(x.ff - it));
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        solve();
    return 0;
}