// stl vector - 2023/01/13

/*
    1. array
    2.vector
    3.map
 */


#include <vector>
#include <iostream>
#include <string>


using namespace std;

void print_str(vector <string> str)
{
    int i = 0;
    for(auto&& s : str) {
        if (s != "") {
            cout  << i << "=" << s << endl;
        }

        i++;
    }
}

int main ()
{

    cout << "1.鍒╃敤vector瀛樺偍瀛楃涓�" << endl;
    vector <string> str = {"4354", "hello", "999", "hhaha"};
    print_str(str);
    putchar('\n');
    str.push_back("hello world!!");
    str.push_back("hello how are you");
    print_str(str);
    vector<string> str2(str);
    str2.push_back("helu");
    print_str(str);
    putchar('\n');
    print_str(str2);
    cout << " str:"<< str.size() << "\t"<< "str2:" << str2.size()<<endl;
    //cout <"2--" << str[2]<<endl;
    printf("\n\n%ld", sizeof(long *));
    return 0;
}
