// stl 练习-map - 2023/01/13

/*
    1. array
    2.vector
    3.map
 */


#include <iostream>
#include <string>
#include <map>

using namespace std;

 int main()
 {
    map<int, string> map1 = {
        {34, "C语言"},
        {2, "高等数学"}
    };
    map1.insert({33, "离散数学"});

    for (auto&& value : map1) {
        cout << value.first << "---" << value.second << endl;
    }
    auto it = map1.find(2);
    if (it != map1.end()) {
        cout << it->second << endl;
    } else {
        cout << "not find";
    }
    return 0;
 }