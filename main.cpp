#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // Maintain disjoint closed intervals [l, r], no overlaps allowed.
    // On operation A l r: remove all intervals that intersect [l, r], output count, then insert [l, r].
    // On operation B: output current number of intervals.
    map<int, int> intervals; // key: left, value: right

    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);

            int removed = 0;

            auto it = intervals.lower_bound(l);
            if (it != intervals.begin()) {
                auto pit = prev(it);
                if (pit->second >= l) {
                    it = pit; // candidate that might overlap
                }
            }

            // Remove all intervals that overlap [l, r]
            while (it != intervals.end() && it->first <= r) {
                if (it->second < l) {
                    ++it; // this one is strictly before [l, r]
                    continue;
                }
                ++removed;
                it = intervals.erase(it);
            }

            intervals.emplace(l, r);
            cout << removed << '\n';
        } else if (op == 'B') {
            cout << intervals.size() << '\n';
        } else {
            // Unknown op: consume rest of line safely
            string skip;
            getline(cin, skip);
            cout << 0 << '\n';
        }
    }

    return 0;
}

