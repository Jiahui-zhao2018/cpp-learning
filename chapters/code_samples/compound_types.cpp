#include <iostream>
int main()
{
    int val = 1;
    int &refVal = val;
    int new_val = 2;
    refVal = new_val; 
    std::cout << val << std::endl;
    return 0;
}