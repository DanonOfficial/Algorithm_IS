#include <iostream>
#include <string>
 
using namespace std;
 
struct node {
    int data;
    node *l, *r;
};
 
int search(node *x, int k) {
    if (x == NULL) {
        return -1;
    }
    if (x->data == k) {
        return 1;
    }
    if (k < x->data) {
        return search(x->l, k);
    } else {
        return search(x->r, k);
    }
}
 
node *next(node *&root, int x) {
    node *current = root;
    node *successor = NULL;
    while (current != NULL) {
        if (current->data > x) {
            successor = current;
            current = current->l;
        } else {
            current = current->r;
        }
    }
    return successor;
}
 
node *prev(node *&root, int x) {
    node *current = root;
    node *successor = NULL;
    while (current != NULL) {
        if (current->data < x) {
            successor = current;
            current = current->r;
        } else {
            current = current->l;
        }
    }
    return successor;
}
 
node *minimum(node *&x) {
    if (x->l == NULL) {
        return x;
    }
    return minimum(x->l);
}
 
void insert(node *&x, int a) {
    if (!x) {
        x = new node;
        x->data = a;
        x->l = x->r = NULL;
        return;
    } else {
        if (x->data > a) {
            insert(x->l, a);
        } else {
            if (x->data < a) {
                insert(x->r, a);
            }
        }
    }
    return;
}
 
node *del(node *&root, int a) {
    if (root == NULL) {
        return root;
    }
    if (a < root->data) {
        root->l = del(root->l, a);
    } else if (a > root->data) {
        root->r = del(root->r, a);
    } else if (root->l != NULL && root->r != NULL) {
        root->data = minimum(root->r)->data;
        root->r = del(root->r, root->data);
    } else {
        if (root->l != NULL) {
            root = root->l;
        } else {
            root = root->r;
        }
    }
    return root;
}
 
int main() {
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    node *tree = NULL;
    string in;
    while (cin >> in) {
        int key;
        cin >> key;
        if (in == "insert") {
            insert(tree, key);
        }
        if (in == "exists") {
            search(tree, key) == -1 ? cout << "false" << endl : cout << "true" << endl;
        }
        if (in == "next") {
            node *temp = next(tree, key);
            (temp == NULL) ? cout << "none" << endl : cout << temp->data << endl;
        }
        if (in == "prev") {
            node *temp = prev(tree, key);
            (temp == NULL) ? cout << "none" << endl : cout << temp->data << endl;
        }
        if (in == "delete") {
            del(tree, key);
        }
    }
}
