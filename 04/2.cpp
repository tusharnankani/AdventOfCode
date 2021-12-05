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

vector<vector<vector<int>>> v;

void remove(ll n) {
    // deb(n)
    for(auto &dd: v) {
        for(auto &d: dd) {
            for(auto &it: d) {
                if(it == n) {
                    it = -1;
                }
            }
            // deba(d)
        }
    }
}

ll check () {
    ll cnt = -1;
    for(auto &dd: v) {
        cnt += 1;

        for(auto &d: dd) {
            bool ok = 0;
            // deba(d)

            for(auto &it: d) {
                if(it != -1) {
                    ok = 1;
                    break;
                }
            }

            // deb2(ok, cnt)
            if(!ok) {
                return cnt;
            }
        }
    }

    cnt = -1;
    for(auto &dd :v) {
        cnt += 1;

        f(j, 0, 5) {
            bool ok = 0;

            f(i, 0, 5) {
                if(dd[i][j] != -1) {
                    ok = 1;
                    break;
                }
            }

            if(!ok) {
                return cnt;
            }
        }
    }

    return -1;
}

void solve()
{
    string s;
    cin >> s;

    vll order;
    ll curr = 0, t = 1;
    f(i, 0, s.length()) {
        if(s[i] == ',') {
            order.pb(curr);
            curr = 0;
            t = 1;
        } else {
            curr = curr * t + (s[i] - '0');
            t *= 10;
        }
    }

    order.pb(curr);
    deba(order)
    deb(order.size())
    // deb(s);

    ll d;
    while(cin >> d) {

        vector<vector<int>> a;
        f(i, 0, 5)
        {
            vector<int> b(5);

            if(i == 0) {
                b[0] = d;
                f(j, 1, 5) {
                    cin >> b[j];
                }
            }

            else {
                f(j, 0, 5) {
                    cin >> b[j];
                }
            }
            a.pb(b);
        }
        v.pb(a);
    }

    // deb(v.size());

    for(auto it: order) {
        remove(it);
        ll cr = check();
        // deb(v.size())

        while(1) {

            if(cr != -1 && v.size() > 1) {
                v.erase(v.begin() + cr);
            } else {
                break;
            }

            cr = check();
            // deb(cr)
            
        }
        if(v.size() == 1 && cr != -1) {
            // deb2(cr, it)
            ll sum = 0;

            for(auto tt: v[0]) {
                // deba(tt)

                for(auto j: tt) {
                    
                    if(j != -1) {
                        sum += j;
                    }
                }
                // cout << endl;
            }
            // deb2(sum, it)
            cout << sum * it << endl;
            return;
        }
    }
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