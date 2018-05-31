#include <iostream>
#include <utility>
#include <vector>
#include <string>

bool func_test(std::string &rtn)
{
    std::string val = "move test";

    rtn = std::move(val);
}


int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n"; //After move, str is "Hello"
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";   //After move, str is ""
    std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";   //The contents of the vector are "Hello", "Hello"

    std::string value;
    func_test(value);
    std::cout << "move func test:" << value << std::endl;
}
