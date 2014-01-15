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

class GalaxyTrip {
    public:
    vector<string> dependencies; 
    int parent[31];

    int findparent(int u) {
        if (parent[u] != u) {
            parent[u] = findparent(parent[u]);
        }
        return parent[u];
    }
    void connect(int i, int j) {
        int u = findparent(i);
        int v = findparent(j);
        if (u == v)
            return;

        if (u < v) {
            parent[v] = u;
        } else {
            parent[u] = v;
        }
    }
    vector<int> possibleValues(vector<string> dependencies) {

        this->dependencies = dependencies; 
        FORN(i, sz(dependencies)) parent[i] = i;

        FORN(i, sz(dependencies)) {
            string t = dependencies[i];
            if (t == "")
                continue;
            stringstream s; s<<t;
            while (!s.eof()) {
                int temp;
                s >> temp;
                connect(i, temp);
            }
        }

        int freq[31];
        memset(freq, 0, sizeof freq);
        FORN(i, sz(dependencies)) {
            freq[findparent(i)] ++;
        }

        std::vector<int> components;
        FORN(i, sz(dependencies)) {
            if (freq[i] != 0) {
                components.pb(freq[i]);
            }
        }
    
        std::vector<bool> prev(40, false);
        std::vector<bool> current(40);

        prev[0] = true;

        FORN(i, sz(components)) {

            FORN(j, sz(prev)) {
                if (prev[j]) {
                    current[j] = true;
                    current[j + components[i]] = true;
                }
            }
            prev = current;
        }

        
        std::vector<int> res;
        FOR(i, 1, sz(prev) - 1) {
            if (prev[i])
                res.pb(i);
        }
        return res;
    }
};

// CUT begin
ifstream data("GalaxyTrip.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> dependencies, vector<int> __expected) {
    time_t startClock = clock();
    GalaxyTrip *instance = new GalaxyTrip();
    vector<int> __result = instance->possibleValues(dependencies);
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
        vector<string> dependencies;
        from_stream(dependencies);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(dependencies, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387966100;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "GalaxyTrip (1000 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
