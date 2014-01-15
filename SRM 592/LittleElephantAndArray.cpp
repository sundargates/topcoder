#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

#include <sstream>
#include <typeinfo>
#include <fstream>
using namespace std;

#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define FORN(i,n) FOR(i,0,(n-1))
#define FORE(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define db(x) cout << (#x) << " = " << x << endl;
#define CLR(x) memset(x,0,sizeof(x));
#define sz(x) ((int)x.size())
#define mp make_pair
#define pb push_back
#define re return
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define LIMIT 1000000007

class LittleElephantAndArray {
    public:
    long long A; 
    int N; 
    set<ll> indices;

    string itoa(ll A) {
        stringstream s;
        s<<A;
        return s.str();
    }
    int logbase(int n) {
        int res = 0;
        while (n) {
            n >>= 1;
            res ++;
        }
        return res;
    }
    int getNumber(long long A, int N) {

        this->A = A; 
        this->N = N;

        for (ll i = A; i<= (A + N);  i++) {
            string s = itoa(i);
            FOR(k, 1, ((1<<(s.length())) - 1)) {
                ll t = k;
                int curr = 0;
                string c = "";
                while (t) {
                    if (t & 1) {
                        c += s[curr];
                    }

                    curr ++;
                    t >>= 1;
                }
                ll j = atol(c.c_str());
                indices.insert(j);
            }
        }
        // db(index);
        int req = logbase(sz(indices));
        // db(req);
        std::vector<ll> last_dp(1<<req, 0);
        std::vector<ll> current_dp(1<<req);

        {
            string s = itoa(A);
            FOR(k, 1, ((1<<(s.length())) - 1)) {
                ll t = k;
                int curr = 0;
                string c = "";
                while (t) {
                    if (t & 1) {
                        c += s[curr];
                    }

                    curr ++;
                    t >>= 1;
                }
                ll j = atol(c.c_str());
                // db(j);
                ll t_index = indices.find(j) - indices.begin();
                last_dp[t_index] += 1;
                // db(indices[j]);
            }
        }
        // db ("here");
        for (ll i = A + 1; i <= (A + N); i++) {
            db (i);
            string s = itoa(i);
            FORN(p, sz(indices)) {
                current_dp[p] = 0;
            }

            FOR(k, 1, ((1<<(s.length())) - 1)) {
                ll t = k;
                int curr = 0;
                string c = "";
                while (t) {
                    if (t & 1) {
                        c += s[curr];
                    }

                    curr ++;
                    t >>= 1;
                }
                ll j = atol(c.c_str());
                // db(j);
                // db(index);
                ll res = 0;
                ll t_index = indices.find(j) - indices.begin();
                ll current_index = 0;
                FORE(iter, indices) {
                    if (current_index > t_index)
                        break;
                    current_index++;
                    res += last_dp[(*iter)];
                }
                // FORN(p, index) {
                //     if (rev_indices[p] <= j) {
                //         // db(p);
                //         // db(rev_indices[p]);
                //         res += last_dp[p];
                //         res %= LIMIT;
                //     }
                // }
                // db(res);
                // db(indices[j]);
                current_dp[t_index] += res;
            }
            swap(last_dp, current_dp);
        }

        ll res = 0;
        FORN(i, index) {
            res += last_dp[i];
            res %= LIMIT;
        }

        return res;
    }
};

// CUT begin
ifstream data("LittleElephantAndArray.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(long long A, int N, int __expected) {
    time_t startClock = clock();
    LittleElephantAndArray *instance = new LittleElephantAndArray();
    int __result = instance->getNumber(A, N);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

void run_test(const set<int> &case_set) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        long long A;
        from_stream(A);
        int N;
        from_stream(N);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(A, N, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387946690;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "LittleElephantAndArray (1000 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
