#include <iostream>
#include <string>
#include <regex>

void test_regex_search(const std::string& input)
{
    std::regex rgx("((1[0-2])|(0?[1-9])):([0-5][0-9])((am)|(pm))");
    std::smatch match;

    std::regex rgx2("/v1/pic-face-detect/[1-9]");
#if 0
    if (std::regex_search(input.begin(), input.end(), match, rgx))
    {
        std::cout << "Match\n";

        //for (auto m : match)
        //  std::cout << "  submatch " << m << '\n';
        std::cout << "match[0] = " << match[0] << '\n';
        std::cout << "match[1] = " << match[1] << '\n';
	std::cout << "match[2] = " << match[2] << '\n';
	std::cout << "match[3] = " << match[3] << '\n';
        std::cout << "match[4] = " << match[4] << '\n';
        std::cout << "match[5] = " << match[5] << '\n';
    }
    else
        std::cout << "No match\n";
#endif

    if (std::regex_search(input.begin(), input.end(), match, rgx2))
    {
	std::cout << "match[0] = " << match[0] << '\n';
	std::cout << "match[1] = " << match[1] << '\n';
	std::cout << "match[2] = " << match[2] << '\n';
	std::cout << "match[3] = " << match[3] << '\n';
	std::cout << "match[4] = " << match[4] << '\n';
    }
}

int main()
{
    const std::string time1 = "9:45pm";
    const std::string time2 = "11:53am";
    const std::string time3 = "/v1/pic-face-detect/1";	

    test_regex_search(time1);
    test_regex_search(time2);
    test_regex_search(time3);
}
