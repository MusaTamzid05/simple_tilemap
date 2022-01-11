#include "edge_detector.h"

namespace Vision {
    EdgeDetector::EdgeDetector(const std::string& src_image_path) {
        src_image = cv::imread(src_image_path);

        if(src_image.empty()) {
            std::cerr << "Could load " << src_image_path << "\n";
            exit(1);
        }

    }

    EdgeDetector::~EdgeDetector() {
        cv::destroyAllWindows();
        std::cout << "Destroyting all the window.\n";
    }


    void EdgeDetector::show(const cv::Mat& src_image) const {
        std::string window_name = "Vision Window";
        cv::namedWindow(window_name, cv::WINDOW_NORMAL);
        cv::imshow(window_name, src_image);

        cv::waitKey(0);
    }

    void EdgeDetector::run() {
        show(src_image);
    }
}
