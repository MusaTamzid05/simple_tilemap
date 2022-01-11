#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace cv {
    class Mat;
};

namespace CVutils {
    void show_image(cv::Mat& image);
    void show_image(const std::string& image_path);
}

#endif
