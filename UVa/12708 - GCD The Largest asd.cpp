#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    register unsigned int n;
    unsigned long ago;
    std::cin >> n;
    while(n--){
        std::cin >> ago;
        std::cout << (ago>>1) << "\n";
    }
    return 0;
}
