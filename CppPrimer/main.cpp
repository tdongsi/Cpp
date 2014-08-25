#include <iostream>
#include "Sales_data.h"

using std::cout;
using std::endl;

int main()
{
//    vector<int> v{1,2,3,4,5,6,7};
//
//    for (auto &i : v)
//    {
//        i *= i;
//    }
//
//    for (auto i: v)
//    {
//        cout << i << " ";
//    }

    cpp_primer::chapter7::SaleData data;
    cout << "\nCheck: " << data.avg_price() << endl;

    return 0;
}
