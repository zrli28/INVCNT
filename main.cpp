#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
typedef long long ll;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define f first
#define s second
const int INF = 1000000005;
//const ll INF = 10000000000000005;
const ll MOD = 3359232;
const ll MAX_N = 200005;
const ll SQRT_M = 40000;

using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, 
rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll fenwick[MAX_N], vals[MAX_N];

void update(int p, ll delta) {
    for(int i = p; i <= n; i += i&-i) {
        fenwick[i] += delta;
    }
}

ll query(int h) {
    ll sum = 0;
    for(int i = h; i > 0; i -= i&-i) {
        sum += fenwick[i];
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            fenwick[i] = 0;
            vals[i] = 0;
        }
        vector<ll> temp(n+1);
        for(int i = 1; i <= n; ++i) {
            cin >> vals[i];
            temp[i] = vals[i];
        }
        sort(temp.begin()+1, temp.end());
        temp[0] = -1;
        for(int i = 1; i <= n; ++i) {
            vals[i] = lower_bound(temp.begin(), temp.end(), vals[i])-temp.begin();
        }
        ll ans = 0;
        for(int i = n; i > 0; --i) {
            update(vals[i], 1);
            ans += query(vals[i]-1);
        }
        cout << ans << "\n";
    }
    
    return 0;
}

/*
list of data structures:
vectors
arrays
adjacency list
adjacency matrix
edge list
maps
unordered maps
sets((mono) -> insert, erase)
multisets
ordered sets(() -> insert, erase, find_by_order)
unordered sets
queues
deques
priority queues
stacks(mono)
heaps(min, max)
disjoint set union
binary search trees
spanning trees(min, max)
fenwick trees(sum, diff)
segment trees(sum, diff, min, max, xor)
tries
linked lists

list of algorithms:
prefix/suffix sums
binary search
two pointers
sliding window
recursion
dfs(floodfill)
bfs
*/