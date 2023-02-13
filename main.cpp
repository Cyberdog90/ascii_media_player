#include "video_loader.h"
#include "screen.h"

int main(int argc, char *argv[]) {
    Screen(Video(argv[1]).get_video()).Show();
}
