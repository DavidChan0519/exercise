#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <string>

int main()
{
    using namespace std;
    ifstream mat("mat.txt");
    if (!mat.is_open())
    {
        cerr << "Can't open mat.dat.\n";
        exit(1);
    }
    ifstream pat("pat.txt");
    if (!pat.is_open())
    {
        cerr << "Can't open pat.dat.\n";
        exit(1);
    }
 
    ofstream matnpat("matnpat.txt");
    if (!matnpat.is_open())
    {
        cerr << "Can't open pat.dat.\n";
        exit(1);
    }
   
    string temp;

    set<string> mats;
    while (getline(mat,temp))
        mats.insert(temp);
    ostream_iterator<string,char> out (cout, "\n");
    cout << "Mat's guest list:\n";
    copy(mats.begin(), mats.end(), out);

    set<string> pats;
    while (getline(pat,temp))
        pats.insert(temp);
    cout << "\nPat's guest list:\n";
    copy(pats.begin(), pats.end(), out);

    ostream_iterator<string,char> fout (matnpat, "\n");
    set<string> both;
    set_union(mats.begin(), mats.end(), pats.begin(), pats.end(),
        insert_iterator<set<string> >(both, both.begin()));
    cout << "\nMerged guest list:\n";
    copy(both.begin(), both.end(), out);
    copy(both.begin(), both.end(), fout);

    return 0;
}
   