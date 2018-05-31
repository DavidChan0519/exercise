#include <iostream>  
#include <opencv2/highgui/highgui.hpp>  
  
using namespace std;  
using namespace cv;  

int main(int argc, char *argv[])  
{    
    Mat matImage = imread(argv[1],-1);  
      
    if(matImage.data==0)  
    {  
        cout<<"load pic failed"<<endl;  
        return -1;  
    }     
      
    cv::rectangle(matImage,cvPoint(20,200),cvPoint(200,300),Scalar(255,0,0),1,1,0);  
    //Rect(int a,int b,int c,int d)a,b为矩形的左上角坐标,c,d为矩形的长和宽  
    cv::rectangle(matImage,Rect(100,300,20,200),Scalar(0,0,255),1,1,0);  
      
    imshow("1st hello world",matImage);  
    waitKey();  
    return 0;  
}  
