// stl 缁冧範-array - 2023/01/13

/*
    1. array
    2.vector
    3.map
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

int main ()
{
    cout << "0. sort \n";
    int a[] = {5, 8 , 63, 56, -9, -552};
    sort(a, a + sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }

    cout << "\n\n2. array\n";
    array<double, 10> dval1;
    for (int i = 0; i < dval1.size(); i++) {
        dval1.at(i) = i * 5;
    }
    if (!dval1.empty()) {
        for(auto val = dval1.begin(); val < dval1.end(); val++) {
            cout << *val << " ";
        }
    }
    putchar('\n');

    auto first = dval1.begin();
    auto last = dval1.end();
    int i = 5;
    while(first != last) {
        *first = (double)i;
        printf("-%.0f ", *first);
        first++;
        i++;
    }
    putchar('\n');
    auto rFirst = dval1.rbegin();
    auto rEnd = dval1.rend();
    while(rFirst != rEnd) {
        cout << "*" << *rFirst << "*";
        rFirst++;
    }
    putchar('\n');
    for(auto&& values:dval1){
        cout << "@" << values << "@";
    }
    putchar('\n');
    array<string, 3>s = {"234r", "456546", "666"};
    for (auto&& v : s) {
        cout << v << "-";
    }

    return 0;
}