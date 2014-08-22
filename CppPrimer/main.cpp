#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v{1,2,3,4,5,6,7};

    for (auto &i : v)
    {
        i *= i;
    }

    for (auto i: v)
    {
        cout << i << " ";
    }

    return 0;
}
