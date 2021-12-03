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

string struggle(map<string, ll> mp, bool ok) {
    string rating = "";
    map<string, ll> mp1 = mp;

    ll idx = 0;
    while(1) {
        
        if(mp1.size() == 1) {
            auto fin = *mp1.begin();
            rating = fin.ff;
            break;
        }
        
        ll cnt0 = 0, cnt1 = 0;
        for(auto it: mp1) {
            cnt0 += (it.ff[idx] == '0');
            cnt1 += (it.ff[idx] == '1');
        }

        if(!ok) {
            if(cnt0 > cnt1) {
                rating += "0";
            }
            else {
                rating += "1";
            }
        } else {
            if(cnt0 > cnt1) {
                rating += "1";
            }
            else {
                rating += "0";
            }
        }

        ll rtl = rating.length();
        map<string, ll> mp2 = mp1;

        for(auto it: mp1) {
            string curr = it.ff;

            if(curr.substr(0, rtl) != rating) {
                mp2.erase(curr);
            }

            if(mp2.size() == 1) {
                auto fin = *mp2.begin();
                rating = fin.ff;
                break;
            }
        }
        mp1 = mp2;
        idx += 1;
    }
    return rating;
}

void solve()
{
    string s;
    vpll a;
    map<string, ll> mp;
    while (cin >> s) {
        string curr = s;
        mp[s] += 1;
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
    map<string, ll> mp1 = mp;
    string ox = struggle(mp1, 0);
    string co = struggle(mp1, 1);
    // deb(ox)
    // deb(co)

    cout << str(ox) * str(co) << endl;
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