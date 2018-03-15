#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

int arr[]={0,1,2,3,4,5,6,7,8,9};
//hard-coded, doesn't depend on ASCII, UTF etc
int threshold_final =10;
void sumString(const std::string& input)
{
    int threshold_local;
    int sum{};
    bool match = false;
    for (const auto& elem : input)
    {
        if(isdigit(elem))
        {
            int temp = arr[elem - '0'];
            sum += temp;
            match = true;
            if(sum<=threshold){
             continue;
            }
            else{
             threshold=sum;

            }
        }
    }
    if(match == false)
    {
        std::cout << "No digits in the string \n";
    }
    else
    {
        std::cout << sum << '\n';
    }
}
int main()
{
    std::cout << "Enter input \n";
    std::string input{};
    getline(std::cin, input);
    sumString(input);
}
