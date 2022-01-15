#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace cv {
    class Mat;
};

namespace CVutils {
    void show_image(cv::Mat& image);
    void show_image(const std::string& image_path);


}

namespace Utils {
    struct FileHandler {
        FileHandler(const std::string& path);
        virtual ~FileHandler() {}

        void write(const std::vector<std::string>& lines) const;

        std::string path;
    };
}

#endif
