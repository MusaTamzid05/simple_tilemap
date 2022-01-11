#include "edge_detector.h"
#include "utils.h"

namespace Vision {
    EdgeDetector::EdgeDetector(const std::string& src_image_path) {
        src_image = cv::imread(src_image_path);

        if(src_image.empty()) {
            std::cerr << "Could load " << src_image_path << "\n";
            exit(1);
        }

    }

    EdgeDetector::~EdgeDetector() {
    }



    void EdgeDetector::run() {
        CVutils::show_image(src_image);

    }
}
