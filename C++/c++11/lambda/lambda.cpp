#include <iostream>

using namespace std;

int main()
{
    auto f = []() {cout << "hello world!" << endl; };
    f();  //hello world!

    int a = 123;
    auto f1 = [a] { cout << a << endl; };
    f1();  //123

    auto f2 = [&a] {cout << a << endl; };
    a = 789;
    f2();  //789

    //隐式捕获:让编译器根据函数体中的代码来推断需要捕获哪些变量
    auto f3 = [=] {cout << a << endl; };
    f3();  //789

    auto f4 = [&] {cout << a << endl; };
    a = 990;
    f4();  //990

    auto f5 = [](int a, int b)->int {return a + b; };
    printf("%d\n", f5(1, 2));  //3

    return 0;
}
