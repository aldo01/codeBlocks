#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <regex>

std::string file_to_string( std::string file_name )
{
    std::ifstream file(file_name) ;
    return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{} } ;
}

std::set<std::string> extract_hyperlinks( std::string html_file_name )
{
    static const std::regex hl_regex( "<a href=\"(.*?)\">", std::regex_constants::icase  ) ;

    const std::string text = file_to_string(html_file_name) ;

    return { std::sregex_token_iterator( text.begin(), text.end(), hl_regex, 1 ),
             std::sregex_token_iterator{} } ;
}

void create_a_test_file( std::string path ) ;

int main()
{
    create_a_test_file( "test.html" ) ;
    for( auto str : extract_hyperlinks( "test.html" ) ) std::cout << str << '\n' ;
}

void create_a_test_file( std::string path )
{
    std::ofstream(path) << R"(
<!DOCTYPE html>
    <html>
        <body>
            <h2>heading</h2>
            <p>
                blah blah
                <a href="http://www.cplusplus.com/forum/general/182654/">Get All Hyperlinks</a>
                more blah blah
                <a href="http://en.cppreference.com/w/cpp/regex">Regular expressions library</a>
                blah
                <a href="https://isocpp.org/std">Standardization</a>

                blah blah
            </p>

            <p>
                <h3>user profiles</h3>
                <a href="http://www.cplusplus.com/user/Calvin_19/">User profile: Calvin 19</a>
            </p>
        </body>
    </html>
)" ;
}

