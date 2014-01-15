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
#include <cfloat>
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
#define sqr(a) ( (a) * (a) )
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

class UnitsMoving {
    public:

    double graph[51][51];
    vector< pair<int, ii > > start;
    vector< ii > finish;
    double maximum_time;

    int leftOf[51];
    bool seenL[51];
    bool seenR[51];
    int N;

    bool bpm (int u, double t) {

        if(seenL[u]) return false;

        seenL[u] = true;
        FORN(v, N) 
            if(!seenR[v] && graph[u][v] <= t) {
                seenR[v] = true;
                if(leftOf[v] == -1 || bpm(leftOf[v], t)) {
                    leftOf[v] = u;
                    return true;
                }
            }

        return false;
    }
    int calc(double t) {

        memset(leftOf, -1, sizeof leftOf);
        int res = 0;
        FORN(i, N) {

            memset(seenL, 0, sizeof seenL);
            memset(seenR, 0, sizeof seenR);
            if(bpm(i, t))
                res ++;

        }
        return res;
    }
    double solve()
    {

        double low = 0.0;
        double high = maximum_time + 10 ;
        double res = DBL_MAX;

        FORN(i, 50) {

            double mid = low + (high - low) / 2.0;
            int ret = calc(mid);
            // db(mid);
            // db(ret);
            if (ret == N) {
                high = mid;
                res = min(mid, res);
            }
            else {
                low = mid;
            }

        }
        return res;
    }

    double bestTime(vector<string> _start, vector<string> _finish) {

        N = sz(_start);
        FORN(i,N) {

            {
                stringstream s; int a, b, c;
                s<<_start[i];

                s>>a;
                s>>b;
                s>>c;

                start.pb(mp(c, mp(a, b)));
            }
            {
                stringstream s; int a, b;
                s<<_finish[i];

                s>>a;
                s>>b;

                finish.pb(mp(a,b));
            }

        }



        maximum_time = 0.0;
        FORN(i, N) 
            FORN(j, N) {

                double dist = sqrt(sqr(start[i].second.first - finish[j].first) + sqr(start[i].second.second - finish[j].second));
                double t = dist / (double) start[i].first;
                graph[i][j] = t;
                maximum_time = max(maximum_time, t);

            }

        return solve();
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<string> start, vector<string> finish, double __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    UnitsMoving *instance = new UnitsMoving();
    double __result = instance->bestTime(start, finish);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
            string start[] = {
                "0 0 1",
                "0 1 1"
            };
            string finish[] = {
                "1 1",
                "1 0"
            };
            double __expected = 1.0;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }
        case 1: {
            string start[] = {
                "0 0 1",
                "0 1 1"
            };
            string finish[] = {
                "1 1",
                "2 1"
            };
            double __expected = 2.0;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }
        case 2: {
            string start[] = {
                "0 0 1",
                "5 0 1"
            };
            string finish[] = {
                "5 12",
                "10 12"
            };
            double __expected = 13.0;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }
        case 3: {
            string start[] = {
                "0 0 2",
                "5 0 1"
            };
            string finish[] = {
                "5 12",
                "10 12"
            };
            double __expected = 12.0;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }
        case 4: {
            string start[] = {
                "308 994 10",
                "157 22 9",
                "282 975 5",
                "993 17 8",
                "925 771 2",
                "843 110 6",
                "860 629 8",
                "947 143 6",
                "921 348 7",
                "520 607 6",
                "735 306 3",
                "253 861 7",
                "562 56 9",
                "243 168 2",
                "521 971 1",
                "745 537 7"
            };
            string finish[] = {
                "431 911",
                "109 951",
                "177 721",
                "295 831",
                "937 256",
                "608 180",
                "863 994",
                "148 406",
                "275 531",
                "635 297",
                "681 404",
                "909 151",
                "569 730",
                "332 391",
                "94 97",
                "376 142"
            };
            double __expected = 115.72920979597156;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }

        // Your custom testcase goes here
        case 5: {   
            string start[] = {
                "13 26 10"
            };
            string finish[] = {
                "100 21"
            };
            double __expected = 13.0;
            return do_test(to_vector(start), to_vector(finish), __expected, __no);
        }
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "UnitsMoving (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379565980;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
