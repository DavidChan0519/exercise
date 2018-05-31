#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

static cv::Mat mtcnn_pre(const cv::Mat &image) {
      int target_w = 1920, target_h = 1080;
        float ratio = 1.0 * image.rows / image.cols;
          float ratio_standard = 1.0 * target_h / target_w;
            int pad_rows, pad_cols;
              int pad_bottom, pad_top, pad_right, pad_left;

              if (ratio > ratio_standard) {
                      pad_rows = image.rows;
                          pad_cols = pad_rows / ratio_standard;
                              pad_bottom = 0;
                                  pad_right = pad_cols - image.cols;

              } else {
                      pad_cols = image.cols;
                          pad_rows = pad_cols * ratio_standard;
                              pad_bottom = pad_rows - image.rows;
                                  pad_right = 0;

              }
                pad_top = 0;
                  pad_left = 0;
                    cv::Mat frame, resized;
                      cv::copyMakeBorder(image, resized,
                                                   pad_top, pad_bottom, pad_left, pad_right,
                                                                        cv::BORDER_CONSTANT, cv::Scalar(0));
                        cv::resize(resized, resized, cv::Size(target_w, target_h),
                                             0, 0, cv::INTER_AREA);

                          resized.convertTo(frame, CV_32FC3);
                            cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
                              frame = frame.t();
                                return frame;

}

cv::Mat resize_image(cv::Mat &image) {
      cv::Mat resized;
        cv::resize(image, resized, cv::Size(640, 480),
                             0, 0, cv::INTER_AREA);
          return resized;

}

cv::Mat crop_image(cv::Mat &image) {
      cv::Mat result = image(cv::Range(0, 1080), cv::Range(0, 1920));
        return result;

}

#define ALIGN2(x) ((x + 0x1) & (~0x1))
cv::Mat concat_image(vector<cv::Mat *> &src, int cols, int rows) {
      int size = src.size();
        int img_per_row = ALIGN2(size) / 2;
          int img_per_col = 2;
            int height = rows * img_per_row;
              int width = cols * img_per_col;
                cout << "size: " << height << " " << width << endl;
                  cv::Mat image(height, width, CV_8UC3, cv::Scalar(255, 255, 255));
                  for(int i = 0; i < size; i++) {
                          cv::Mat img = image(cv::Rect((i % 2) * cols, (i / 2) * rows, cols, rows));
                              src[i]->copyTo(img);

                  }
                    return image;

}

int main(int argc, char **argv)
{
    if (argc < 2) {
            cout << "Usage: " << argv[0] << " pic_file" << endl;
                return -1;

    }
      cv::Mat image = cv::imread(argv[1]);
        cv::Mat result = resize_image(image);
          cv::imwrite("640.jpg", result);
            //result = crop_image(image);
            // cv::imwrite("crop.jpg", result);
                result = mtcnn_pre(image);
                  cv::imwrite("out.jpg", result);
                    vector<cv::Mat *> src;
                      src.push_back(&image);
                        src.push_back(&image);
                          src.push_back(&image);
                            src.push_back(&image);
                              src.push_back(&image);
                                src.push_back(&image);
                                  result = concat_image(src, image.cols, image.rows);
                                    cv::imwrite("concat.jpg", result);
                                      return 0;

}

