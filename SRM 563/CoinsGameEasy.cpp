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

int dirX[] = {-1, 0, 0, 1};
int dirY[] = {0, 1, -1, 0};

class CoinsGameEasy {
    public:
    vector<string> board; 

    bool outside(ii t) {
        if (t.first < 0 || t.first >= sz(board))
            return true;

        if (t.second < 0 || t.second >= board[0].length())
            return true;

        return false;
    }
    bool obstacle(ii t) {
        if (outside(t))
            return false;

        if (board[t.first][t.second] != '#')
            return false;

        return true;
    }
    int minimalSteps(vector<string> board) {

        this->board = board; 
        ii pos[2];
        int current = 0;
        FORN(i, sz(board)) {
            FORN(j, board[0].length()) {
                if (board[i][j] == 'o') {
                    pos[current++] = mp(i, j);
                }
            }
        }

        priority_queue< pair<int, pair<ii, ii> > > pq;
        pq.push(mp(0, mp(pos[0], pos[1])));

        bool visited[21][21][21][21];
        CLR(visited);

        while (!pq.empty()) {

            pair<int, pair<ii, ii> > p = pq.top();
            pq.pop();
            pos[0] = p.second.first;
            pos[1] = p.second.second;
            if (p.first < -10) {
                return -1;
            }

            if (pos[0] == pos[1])
                continue;

            if (outside(pos[0]) && outside(pos[1]))
                continue;

            if (outside(pos[0]))
                return -p.first;
            

            if (outside(pos[1]))
                return -p.first;

            if (visited[pos[0].first][pos[0].second][pos[1].first][pos[1].second])
                continue;

            visited[pos[0].first][pos[0].second][pos[1].first][pos[1].second] = true;

            FORN(i, 4) {
                ii t0, t1;
                t0 = mp(pos[0].first + dirX[i], pos[0].second + dirY[i]);
                if (obstacle(t0))
                    t0 = pos[0];

                t1 = mp(pos[1].first + dirX[i], pos[1].second + dirY[i]);
                if (obstacle(t1))
                    t1 = pos[1];

                pq.push(mp(p.first - 1, mp(t0, t1)));
            }
        }
    
        return -1;
    }
};

// CUT begin
ifstream data("CoinsGameEasy.sample");

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

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    CoinsGameEasy *instance = new CoinsGameEasy();
    int __result = instance->minimalSteps(board);
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
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(board, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1388633818;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "CoinsGameEasy (550 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
