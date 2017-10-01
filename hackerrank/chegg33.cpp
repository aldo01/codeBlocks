#include <iostream>
#include <regex>
#include <string>

int main()
{
  std::regex url(".*\\..*");
  std::string url_test = "example.com";

  if(regex_match(url_test, url)) {
    std::cout << "It's a url!" << std::endl;
  } else {
    std::cout << "Oh snap! It's not a url!" << std::endl;
  }
}
