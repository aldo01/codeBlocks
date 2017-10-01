#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include<stdio.h>


int main()
{
   std::regex url("/.*(href=')(.*)(>)/");
  std::string url_test = "11_custom_io.ppt";
    std::ifstream file("in.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file!\n";
        return -1;
    }


    const std::string needle = "11_custom_io.ppt";

    std::string haystack;
    while (std::getline(file, haystack))

    {
        if (haystack.find(needle) != std::string::npos)
        {
          if(regex_match(url_test, url)){
           std::cout << url_test << "\n";
}

        }
    }
}
