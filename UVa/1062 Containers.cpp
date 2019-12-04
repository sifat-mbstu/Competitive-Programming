#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <cstdint>
#include <bitset>

using namespace std;

array<char, 1001>  stks;
int main(void)
{
    string s;
    s.reserve(1024);
    int tc = 1;
    while(cin >> s && s[0] != 'e'){
        fill(begin(stks), end(stks), 'Z' + 1);

        auto idx = begin(stks);
        for(auto c: s){
            auto pos = lower_bound(begin(stks), idx +1, c);
            *pos = c;
            idx = max(idx, pos);
        }
        ostringstream oss;
        oss << "Case " << tc++ << ": " << idx - begin(stks) + 1 << "\n";

        cout << oss.str();

    }
    return 0;
}
