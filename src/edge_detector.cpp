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


    std::vector<std::vector<cv::Point>> EdgeDetector::get_contours(const cv::Mat& image, std::vector<cv::Vec4i>& hierarchy) const  {
        std::vector<std::vector<cv::Point>> contours;

        cv::Mat gray_image;
        cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
        CVutils::show_image(gray_image);


        cv::findContours(gray_image, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );


        return contours;

        
    }


    void EdgeDetector::draw_contours(
            const std::vector<std::vector<cv::Point>>& contours,
            const cv::Size& image_size,
            const  std::vector<cv::Vec4i>& hierarchy) const {

        cv::Mat black_image = cv::Mat::zeros(image_size, CV_8UC1);

        cv::Scalar color = cv::Scalar(255, 0, 0);
        cv::drawContours(black_image, contours, -1,  color, cv::FILLED, 8, hierarchy);

        CVutils::show_image(black_image);

    }

    void EdgeDetector::run(bool draw) {
        std::vector<cv::Vec4i> hierarchy;
        std::vector<std::vector<cv::Point>>  contours = get_contours(src_image, hierarchy);
        std::cout << "Contour size " << contours.size() << "\n";

        if(draw) {
            draw_contours(contours, src_image.size(), hierarchy);
            draw_points(contours);

        }





    }

    void EdgeDetector::draw_points(const std::vector<std::vector<cv::Point>>& contours) const {
        int radius = 5;
        int thikness = 1;

        for(std::vector<cv::Point> contour : contours) {
            cv::Mat test_image = src_image.clone();

            std::cout << "=========================\n";
            std::cout << contour.size() << "\n";
            for(cv::Point point : contour) {
                std::cout << point << "\n";
                cv::circle(test_image, point, radius, cv::Scalar(0, 100, 0), cv::FILLED);


            }

            CVutils::show_image(test_image);

            std::cout << "=========================\n";
        }
    }
}
