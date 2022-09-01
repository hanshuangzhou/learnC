#include <iostream>
using namespace std;

int main() {
    int j = 12;
    auto by_value_lambda = [=]{ return j + 1;};
    auto by_ref_lambda = [&]{ return j + 1;};

    cout << "by_value_lambda: " << by_value_lambda() << endl;
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;

    j++;
    cout << "now j = " << j << endl;
    cout << "by_value_lambda: " << by_value_lambda() << endl;
    cout << "by_ref_lambda: " << by_ref_lambda() << endl;

    return 0;
}