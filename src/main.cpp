#include "app.h"
#include "edge_detector.h"
#include "utils.h"
#include <opencv4/opencv2/opencv.hpp>

int main(int argc, char** argv) {
    TileMap::App* app = new TileMap::App();
    app->run();

    Vision::EdgeDetector detector(app->screenshot_path);
    detector.run();




    return 0;
}
