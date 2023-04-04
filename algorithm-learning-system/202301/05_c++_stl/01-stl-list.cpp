// c++ 程序格式 - 2023/01/11

/*#include <iostream>

using namespace std;

int main()
{
    int a = -123456;
    int b;
    cin >>b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}*/

// we should study use stl,because it is important to write algorithm.
/*
第一天：vector的学习：
（1）认识vector：变长数组，可以根据实际动态调整数组大小
（2）常用函数：
    1.begin(); 用于获取首元素地址，如vector<int>::iterator it = arr.begin(); 这里it是迭代器，或者说是一种元素指针
    2.end(); 末元素地址获取
    3.push_back(); 尾插元素
    4.size(); 数组长度获取
    5.clear(); 清除vector的所有元素，且元素长度变为0
    6.insert(it, x); 在迭代器it的指示位置，插入一个元素
    7.erase(); // erase(it) 删除迭代器为it指向的元素 erase(first, last) 删除[firsr, last]区间的元素
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr; // 定义a,数组，此时数组长度是0，和普通数组不同的是，此时a可以根据存储数据的数量自动变长
    int i;
    for (i = 0; i < 100; i++) {
        arr.push_back(i * 2);
    }
    arr.push_back(52);
    arr.push_back(-99);
    /*cout << "a.size = " << arr.size() << "\n\n";
    for (i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\t";
        if ((i + 1) % 5 == 0) {
            cout << "\n";
        }
    }*/
    int index = 0;
    vector<int>().swap(arr);
    // iterator vector
    vector<int>::iterator it = arr.begin();
    while(it != arr.end()) {
        cout << "-" << *it << "-\t";
        index++;
        it++;
        if (index % 6 == 0) {
            cout << "\n";
        }
    }

    return 0;
}