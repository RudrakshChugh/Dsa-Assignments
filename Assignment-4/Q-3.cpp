#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;
    while (cin >> x) q.push(x);
    n = q.size();
    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    queue<int> result;
    while (!firstHalf.empty()) {
        result.push(firstHalf.front());
        firstHalf.pop();
        result.push(q.front());
        q.pop();
    }
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
}
