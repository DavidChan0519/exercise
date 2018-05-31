#include <opencv2/core/core.hpp>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cv::Mat M(3,2,CV_8SC3);
	cout<<"M="<<M<<endl;
	return 0;
}
