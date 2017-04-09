#include <iostream>
#include <string>
 
using namespace std;
pair<int, int> heap[1000010];
int size;
 
void shiftUp(int i) {
    while (i > 1 && heap[i / 2].first > heap[i].first) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}
 
void shiftDown(int i) {
    while (i <= (size)) {
        int m;
        heap[i].first > heap[i * 2].first && i * 2 <= size ? m = i * 2 : m = i;
        heap[m].first > heap[2 * i + 1].first && i * 2 + 1 <= size ? m = 2 * i + 1 : m = m;
        if (m == i) {
            break;
        }
        swap(heap[m], heap[i]);
        i = m;
    }
}
 
void add(int x, int index) {
    heap[size + 1].first = x;
    heap[size + 1].second = index;
    shiftUp(size + 1);
    size++;
}
 
int extractMin() {
    int result = heap[1].first;
    swap(heap[1], heap[size]);
    size--;
    shiftDown(1);
    return result;
}
 
void decrease(int key, int val) {
    for (int i = 1; i <= size; i++) {
        if (heap[i].second == key) {
            heap[i].first = val;
            shiftUp(i);
            break;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string a;
    size = 0;
    int index = 1;
    while (cin >> a) {
        int k;
        if (a == "push") {
            cin >> k;
            add(k, index);
 
        }
        if (a == "extract-min") {
            if (size == 0) {
                cout << "*" << endl;
            } else {
                cout << extractMin() << endl;
            }
        }
        if (a == "decrease-key") {
            int val, key;
            cin >> key >> val;
            decrease(key, val);
        }
        index++;
    }
 
}
