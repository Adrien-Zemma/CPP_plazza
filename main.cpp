#include <iostream>
#include <string>
#include <regex>
 
int main()
{
    // Simple regular expression matching
    std::string fnames[] = {"0647005996", "bar.txt", "baz.dat", "zoidberg"};
   
    // Extraction of a sub-match
    std::regex pieces_regex("0[0-9]( ?[0-9]{2}){4}");
    std::smatch pieces_match;
 
    for (const auto &fname : fnames)
    {
        if (std::regex_match(fname, pieces_match, pieces_regex))
	{
            std::cout << fname << '\n';
            for (size_t i = 0; i < pieces_match.size(); ++i)
	    {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "  submatch " << i << ": " << piece << '\n';
            }   
        }   
    }   
 
}