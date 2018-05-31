#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> q;
    cout << "1# nullptr: " << q.get() <<endl;

    shared_ptr<int> p(nullptr);
    cout << "2# nullptr: " << p.get() <<endl;

    shared_ptr<int> t = shared_ptr<int>() ;
    cout << "3# nullptr: " << t.get() <<endl;

    if ((q.get() == nullptr) && (p.get() == nullptr) && (t.get() == nullptr)) {
        cout << "all are nullptr"<<endl;
    }

    shared_ptr<int> m(new int(11));
    cout << "value:" << *m << endl;

    shared_ptr<int> n(new int[5], std::default_delete<int[]>());
    for (int i=0; i<5; i++) {
        cout << "original value:"<<n.get()[i]<<endl;
    }

    for (int i=0; i<5; i++) {
        n.get()[i] = i;
    }

    for (int i=0; i<5; i++) {
        cout << "modified value:"<<n.get()[i]<<endl;
    }
    return 0;
}
