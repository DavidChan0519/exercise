#include <iostream>
#include <map>

int main()
{
    std::multimap<int, char> a = {{1,'a'},{2,'b'},{3,'c'},{1,'d'}};
    std::cout << "===================1st================="<<std::endl;
    auto itera = a.find(1);
    std::cout << "key: " << itera->first << " val:" << itera->second << std::endl;

    auto itera2 = ++itera;
    std::cout << "key: " << itera2->first << " val:" << itera2->second << std::endl;

    std::cout << "===================2nd================="<<std::endl;
    auto range = a.equal_range(1);
    for (auto i= range.first; i!= range.second; i++) {
        std::cout << "key: " << i->first << " val:" << i->second << std::endl;
    }
    return 0;
}
