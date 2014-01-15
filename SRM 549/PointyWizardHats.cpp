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

class PointyWizardHats {
    public:

    bool canPlace(int hT, int rT, int hB, int rB){  return (rB>rT) && ( (hT*rB) > (hB*rT) );}

    bool graph[51][51];
    bool seenL[51];
    bool seenR[51];
    int leftOf[51];

    int N, M;

    bool bpm(int u) {

        if(seenL[u])
            return false;

        seenL[u] = true;
        FORN(i, M) {
            if (graph[u][i] && !seenR[i]) {
                seenR[i] = true;
                if (leftOf[i] == -1 || bpm(leftOf[i]))
                {
                    leftOf[i] = u;
                    return true;
                }
            }

        }

        return false;
    }

    int solve() {

        int res = 0;
        memset(leftOf, -1, sizeof leftOf);
        FORN(i, N) {
            memset(seenL, 0, sizeof seenL);
            memset(seenR, 0, sizeof seenR);
            if(bpm(i))
                res ++;
        }
        return res;

    }

    int getNumHats(vector<int> topHeight, vector<int> topRadius, vector<int> bottomHeight, vector<int> bottomRadius) {

        N = sz(topHeight);
        M = sz(bottomHeight);
        memset(graph, 0, sizeof graph);
        FORN(i, sz(topHeight))
            FORN(j, sz(bottomHeight))
                graph[i][j] = canPlace(topHeight[i], topRadius[i], bottomHeight[j], bottomRadius[j]);


        return solve();
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> topHeight, vector<int> topRadius, vector<int> bottomHeight, vector<int> bottomRadius, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    PointyWizardHats *instance = new PointyWizardHats();
    int __result = instance->getNumHats(topHeight, topRadius, bottomHeight, bottomRadius);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int topHeight[] = {
                30
            };
            int topRadius[] = {
                3
            };
            int bottomHeight[] = {
                3
            };
            int bottomRadius[] = {
                30
            };
            int __expected = 1;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 1: {
            int topHeight[] = {
                4, 4
            };
            int topRadius[] = {
                4, 3
            };
            int bottomHeight[] = {
                5, 12
            };
            int bottomRadius[] = {
                5, 4
            };
            int __expected = 1;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 2: {
            int topHeight[] = {
                3
            };
            int topRadius[] = {
                3
            };
            int bottomHeight[] = {
                1, 1
            };
            int bottomRadius[] = {
                2, 4
            };
            int __expected = 1;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 3: {
            int topHeight[] = {
                10, 10
            };
            int topRadius[] = {
                2, 5
            };
            int bottomHeight[] = {
                2, 9
            };
            int bottomRadius[] = {
                3, 6
            };
            int __expected = 2;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 4: {
            int topHeight[] = {
                3, 4, 5
            };
            int topRadius[] = {
                5, 4, 3
            };
            int bottomHeight[] = {
                3, 4, 5
            };
            int bottomRadius[] = {
                3, 8, 5
            };
            int __expected = 2;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 5: {
            int topHeight[] = {
                1, 2, 3, 4, 5
            };
            int topRadius[] = {
                2, 3, 4, 5, 6
            };
            int bottomHeight[] = {
                2, 3, 4, 5, 6
            };
            int bottomRadius[] = {
                1, 2, 3, 4, 5
            };
            int __expected = 0;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 6: {
            int topHeight[] = {
                123, 214, 232, 323, 342, 343
            };
            int topRadius[] = {
                123, 123, 232, 123, 323, 434
            };
            int bottomHeight[] = {
                545, 322, 123, 545, 777, 999
            };
            int bottomRadius[] = {
                323, 443, 123, 656, 767, 888
            };
            int __expected = 5;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }
        case 7: {
            int topHeight[] = {
                999, 999, 999, 10000, 10000, 10000
            };
            int topRadius[] = {
                10000, 10000, 10000, 1, 2, 3
            };
            int bottomHeight[] = {
                2324, 2323, 234, 5454, 323, 232
            };
            int bottomRadius[] = {
                1, 2, 3222, 434, 5454, 23
            };
            int __expected = 3;
            return do_test(to_vector(topHeight), to_vector(topRadius), to_vector(bottomHeight), to_vector(bottomRadius), __expected, __no);
        }

        // Your custom testcase goes here
        case 8:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "PointyWizardHats (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379562364;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
