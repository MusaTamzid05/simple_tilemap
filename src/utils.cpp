#include "utils.h"
#include <opencv4/opencv2/opencv.hpp>
#include <fstream>

namespace CVutils {

    void show_image(cv::Mat& image) {

        std::string window_name = "Vision Window";
        cv::namedWindow(window_name, cv::WINDOW_NORMAL);
        cv::imshow(window_name, image);

        cv::waitKey(0);
        cv::destroyWindow(window_name);
    }


    void show_image(const std::string& image_path) {
        cv::Mat image = cv::imread(image_path);

        if(image.empty()) {
            std::cerr << "Could not load " << image_path << "\n";
            return;
        }

        show_image(image);
    }


}

namespace Utils {

    FileHandler::FileHandler(const std::string& path):path(path) {

    }


    void FileHandler::write(const std::vector<std::string>& lines) const {
        std::ofstream outfile(path);

        if(!outfile.is_open()) {
            std::cerr << "Could not open " << path << "\n";
            return;
        }

        for(std::string line : lines)
            outfile << line << "\n";

        outfile.close();
    }
}


