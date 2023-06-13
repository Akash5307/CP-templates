vector<int> d;
void f(int x) {
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(x / i != i) {
                d.push_back(i);
                d.push_back(x / i);
            }
            else d.push_back(i);
        }
    }
}