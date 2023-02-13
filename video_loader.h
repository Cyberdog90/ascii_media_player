#ifndef ASCII_MEDIA_PLAYER_VIDEO_LOADER_H
#define ASCII_MEDIA_PLAYER_VIDEO_LOADER_H

#include <opencv2/opencv.hpp>

struct Video {
    Video(std::string filepath) : filepath(std::move(filepath)) {
        this->load_video();
        this->fps = video.get(cv::CAP_PROP_FPS);
    }

    cv::VideoCapture get_video() {
        return this->video;
    }

    double get_fps() const {
        return this->fps;
    }

private:
    std::string filepath;
    cv::VideoCapture video;
    double fps;

    void load_video();

};

#endif //ASCII_MEDIA_PLAYER_VIDEO_LOADER_H
