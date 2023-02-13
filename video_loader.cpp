#include "video_loader.h"


void Video::load_video() {
    this->video.open(this->filepath);
    if (!video.isOpened()) {
        std::cerr << "ビデオのロードに失敗しました" << std::endl;
        std::cerr << "ファイル名: " << this->filepath << std::endl;
        exit(-1);
    }
}
