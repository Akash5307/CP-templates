struct monotone_deque {
        deque<pair<int, int>> dq;  // pair of (value, index)
        void insert(int x, int idx) {
            while (!dq.empty() && dq.back().first < x) {
                dq.pop_back();
            }
            dq.push_back({x, idx});
        }
        void remove(int idx) {
            if (!dq.empty() && dq.front().second == idx) {
                dq.pop_front();
            }
        }
        int getMax() {
            if (!dq.empty()) {
                return dq.front().first;
            }
            return 0;
        }
    };
