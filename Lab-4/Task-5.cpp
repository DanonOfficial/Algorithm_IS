#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
double eps = 1e-9;
 
 
int main() {
    freopen("garland.in","r",stdin);
    freopen("garland.out","w",stdout);
    int n;
    cin >> n;
    vector<double> p;
    p.resize(n);
    cin >> p[0];
    double res = 1e9;
    double l = 0, r = p[0];
    while ((l < r) && !(fabs(l - r) <= eps)) {
        p[1] = (l + r) / 2;
        p.back() = 0;
        bool isUp = false;
        for (int i = 2; i < n; i++) {
            p[i] = 2 * p[i - 1] - p[i - 2] + 2;
            if ((p[i] < 0 || (fabs(p[i] - 0) <= eps))) {
                isUp = true;
                break;
            }
        }
        if ((p.back() > 0 && !fabs(p.back() - 0) < eps))
            res = min(res, p.back());
        if (isUp)
            l = p[1];
        else
            r = p[1];
    }
    printf("%0.2f", res);
    return 0;
}
