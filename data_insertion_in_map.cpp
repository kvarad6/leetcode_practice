#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s = "abc";
    string s1 = "efg";
    string s3 = "pqr";

    // declaring a map
    map<string, string> mpp;

    // inserting pair of string in map
    mpp.insert(pair<string, string>(s, s1));
    mpp.insert(pair<string, string>(s3, s));

    // printing map entries
    for (auto itr = mpp.begin(); itr != mpp.end(); ++itr)
    {
        cout << "output" << itr->second;
    }
}
