#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, Pdough, Cdough, Ptopping;
    std::cin >> n >> Pdough >> Ptopping >> Cdough;

    std::vector <int> Ctopping(n);
    for (int i = 0; i < n; i++) std::cin >> Ctopping[i];

    std::sort(Ctopping.rbegin(), Ctopping.rend());

    int result, temp, totalC, totalP;
    totalC = Cdough, totalP = Pdough, result = totalC / totalP;
    for (int i = 0; i < n; i++) {
        totalC += Ctopping[i];
        totalP += Ptopping;
        temp = totalC / totalP;

        result = result > temp ? result : temp;
    }
    
    std::cout << result;
    return 0;
}