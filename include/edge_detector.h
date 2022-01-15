#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <string>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>


namespace Vision {
    struct EdgeDetector {
        EdgeDetector(const std::string& image_path);
        virtual ~EdgeDetector();

        void run(bool draw = true);
        void save(const std::vector<std::vector<cv::Point>>& contours) const;

        std::vector<std::vector<cv::Point>> get_contours(
                const cv::Mat& image, 
                 std::vector<cv::Vec4i>& hierarchy) const;

        void draw_contours(
                const std::vector<std::vector<cv::Point>>& contours,
                const cv::Size& image_size,
                const std::vector<cv::Vec4i>& hierarchy) const;

        void draw_points(const std::vector<std::vector<cv::Point>>& points) const;

        std::string point_to_str(const std::vector<cv::Point>& points) const ;

        cv::Mat src_image;
    };
}

#endif
