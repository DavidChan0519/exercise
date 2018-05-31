#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i=0;

    vector<string> vec{"123","456","789"};
    for (auto &v: vec) {
        cout << "index:" << i++ <<" "<< vec.at(i) << " " << vec[i] << " " << v << endl;
    }
    return 0;
}
