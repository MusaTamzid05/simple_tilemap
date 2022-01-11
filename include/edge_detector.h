#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <string>
#include <opencv2/opencv.hpp>


namespace Vision {
    struct EdgeDetector {
        EdgeDetector(const std::string& image_path);
        virtual ~EdgeDetector();

        void show(const cv::Mat& image) const;
        void run();

        cv::Mat src_image;
    };
}

#endif
