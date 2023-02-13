#ifndef ASCII_MEDIA_PLAYER_SCREEN_H
#define ASCII_MEDIA_PLAYER_SCREEN_H

#include <opencv2/opencv.hpp>
#include <ncurses.h>

struct Screen {
    Screen(cv::VideoCapture video) : video(video) {
        initscr();
        noecho();
        curs_set(0);
        start_color();

        for (short i = 32; i <= 32 + 1000; ++i) init_color(i, short(i - 32), short(i - 32), short(i - 32));
        for (short i = 0; i <= 1000; ++i) init_pair(i, short(i + 32), COLOR_BLACK);
    }

    void Show() {
        while (true) {
            video >> image;
            if (image.empty()) break;
            cv::imshow("movie", image);
            cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
            cv::resize(image, image, cv::Size(80, 24));
            clear();
            for (int y = 0; y < image.size().height; ++y) {
                for (int x = 0; x < image.size().width; ++x) {
                    auto color = short(float(image.at<uchar>(y, x)) * (1000.0f / 255.0f));
                    move(y, x);
                    attron(COLOR_PAIR(color));
                    addch('@');
                    attroff(COLOR_PAIR(color));
                }
            }
            refresh();

            if (cv::waitKey(1) == 'q') break;
        }
    }

    ~Screen() {
        curs_set(1);
        endwin();
    }

private:
    cv::VideoCapture video;
    cv::Mat image;
};

#endif //ASCII_MEDIA_PLAYER_SCREEN_H
