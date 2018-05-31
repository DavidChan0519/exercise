#include <future>
#include <iostream>
//#include <stout/stringify.hpp>

bool is_prime(int x)
{
  return true;
}

int main()
{
  std::future<bool> fut = std::async(is_prime, 1007);
  std::cout << "please wait";
  std::chrono::milliseconds span(100);
  while (fut.wait_for(span) != std::future_status::ready)
    std::cout << ".";
  std::cout << std::endl;

  bool ret = fut.get();
  //std::cout << "final result: " << stringify(ret) << std::endl;
  std::cout << "final result: " << ret << std::endl;
  return 0;
}
