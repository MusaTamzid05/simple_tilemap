#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <string>
#include <opencv4/opencv2/opencv.hpp>


namespace Vision {
    struct EdgeDetector {
        EdgeDetector(const std::string& image_path);
        virtual ~EdgeDetector();

        void run();

        cv::Mat src_image;
    };
}

#endif
