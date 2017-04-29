#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int hash_value = 703;
int size = 0;

struct element {
public:
    string key, value;
    element *prev, *next;
public:
    element(string k, string v) {
        key = k;
        value = v;
        prev = next = NULL;
    }

    element() {
        prev = next = NULL;
    }
};

element *prevElement = NULL;
vector<vector<element *> > linkedMap(3000000, vector<element *>());

int hashing(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += 31 * ans + s[i];
        ans %= hash_value;
    }
    return ans;
}

int get(string key) {
    int hash = hashing(key);
    if (linkedMap[hash].size() != 0) {
        for (int i = 0; i < linkedMap[hash].size(); i++) {
            if (linkedMap[hash][i]->key == key) {
                return i;
            }
        }
    }
    return -1;
}

void insert(string key, string value) {
    int i = get(key);
    int hash = hashing(key);
    if (i != -1) {
        linkedMap[hash][i]->value = value;
    } else {
        element *temp = new element(key, value);
        temp->prev = prevElement;
        if (prevElement != NULL) {
            temp->prev->next = temp;
        }
        prevElement = temp;
        linkedMap[hash].push_back(temp);
    }
    return;
}

void del(string key) {
    int hash = hashing(key);
    int i = get(key);
    if (i != -1) {
        //cout << i << endl;
        if (linkedMap[hash][i]->prev == NULL && linkedMap[hash][i]->next == NULL) {
            prevElement = NULL;
        } else {
            if (linkedMap[hash][i]->prev == NULL) {
                linkedMap[hash][i]->next->prev = NULL;
            } else {
                if (linkedMap[hash][i]->next == NULL) {
                    linkedMap[hash][i]->prev->next = NULL;
                    prevElement = linkedMap[hash][i]->prev;
                } else {
                    linkedMap[hash][i]->prev->next = linkedMap[hash][i]->next;
                    linkedMap[hash][i]->next->prev = linkedMap[hash][i]->prev;
                }
            }
        }
        element *temp = new element;
        linkedMap[hash].push_back(temp);
        for (int j = i; j < linkedMap[hash].size() - 1; j++) {
            linkedMap[hash][j] = linkedMap[hash][j + 1];
        }
        linkedMap[hash].pop_back();
        linkedMap[hash].pop_back();
        delete temp;
    }
}


int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    string in;
    while (cin >> in) {
        string key;
        if (in == "put") {
            string value;
            cin >> key >> value;
            insert(key, value);
            //cout << "kek" << endl;

        }
        if (in == "get") {
            cin >> key;
            int i = get(key);
            if (i != -1) {
                int hash = hashing(key);
                cout << linkedMap[hash][i]->value << endl;
            } else {
                cout << "none" << endl;
            }

        }
        if (in == "delete") {
            cin >> key;
            //cout << "kek1" << endl;
            del(key);
        }
        if (in == "prev") {
            cin >> key;
            int i = get(key);
            if (i != -1) {
                int hash = hashing(key);
                if (linkedMap[hash][i]->prev != NULL) {
                    cout << linkedMap[hash][i]->prev->value << endl;
                } else {
                    cout << "none" << endl;
                }
            } else {
                cout << "none" << endl;
            }
        }
        if (in == "next") {
            cin >> key;
            int i = get(key);
            if (i != -1) {
                int hash = hashing(key);
                if (linkedMap[hash][i]->next != NULL) {
                    cout << linkedMap[hash][i]->next->value << endl;
                } else {
                    cout << "none" << endl;
                }
            } else {
                cout << "none" << endl;
            }
        }
    }


}

