#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;

using namespace std;

int main()
{
    vector<string> v = {"one", "two", "three"};
    for(auto it = begin(v); it!=end(v); it++)
    {
        cout << *it << "\n";
    }

    for(vector<string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << "\n";
    }
    
    for(vector<string>::const_iterator it = v.cbegin(); it != v.cend(); it++)
    {
        cout << *it << "\n";
    }
    
    for(auto & x : v)
    {
        cout << x << "\n";
    }
    
    
    return 0;
}