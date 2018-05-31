#include <iostream>
#include <string>


int main() 
{
	std::cout << "stoi: " <<std::stoi(std::string("123"), nullptr, 0) << std::endl;

    	std::cout <<  std::hex << std::showbase << "hex indication: size " << 23 << ", addr " << 32 << std::endl;
        std::cout <<  std::hex << std::noshowbase << "deci size " << 23 << ", addr " << 32 << std::endl;
	return 0;

}
