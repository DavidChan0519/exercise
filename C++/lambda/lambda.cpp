#include<functional>
#include<vector>
#include<iostream>
double eval(std::function<double(double)> f, double x = 2.0){return f(x);}
int main()
{
     std::function<double(double)> f0    = [](double x){return 1;};
     auto                          f1    = [](double x){return x;};
     decltype(f0)                  fa[3] = {f0,f1,[](double x){return x*x;}};
     std::vector<decltype(f0)>     fv    = {f0,f1};
     fv.push_back                  ([](double x){return x*x;});
     for(int i=0;i<fv.size();i++)  std::cout << fv[i](2.0) << "\n";
     for(int i=0;i<3;i++)          std::cout << fa[i](2.0) << "\n";
     for(auto &f : fv)             std::cout << f(2.0) << "\n";
     for(auto &f : fa)             std::cout << f(2.0) << "\n";
     std::cout << eval(f0) << "\n";
     std::cout << eval(f1) << "\n";
     return 0;
}
