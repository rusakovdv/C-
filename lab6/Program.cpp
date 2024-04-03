#include <iostream>
#include "StringM.h"

using namespace std;

int main() {
    StringM s1("qwert"), s3, s4(s1), s5;
    s3.input();
    s3 = "asdfg";
    s3.output();
    s5 = (s1 + s3 + s4);
    cout << "длина s5 = " << s5.length() << endl;
    s5.output();
    if (s1 == s5)
        cout << "s1 = s5" << endl;
    else if (s1 == s4)
        cout << "s1 = s4" << endl;

    return 0;
}