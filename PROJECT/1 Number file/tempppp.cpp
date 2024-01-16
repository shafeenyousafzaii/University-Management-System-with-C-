#include <iostream>
using namespace std;

int main() {
    cout << "\033[1m" << "Hello, World!" << "\033[0m" << endl;
    cout << "\033[2m" << "This is smaller" << "\033[0m" << endl;
    cout << "\033[3m" << "This is even smaller" << "\033[0m" << endl;
    cout << "\033[4m" << "This is normal" << "\033[0m" << endl;
    cout << "\033[5m" << "This is bigger" << "\033[0m" << endl;
    cout << "\033[6m" << "This is even bigger" << "\033[0m" << endl;
    cout << "\033[7m" << "This is the biggest" << "\033[0m" << endl;

    return 0;
}