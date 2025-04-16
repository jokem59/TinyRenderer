#include <cmath>
#include "tgaimage.h"

constexpr TGAColor white   = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green   = {  0, 255,   0, 255};
constexpr TGAColor red     = {  0,   0, 255, 255};
constexpr TGAColor blue    = {255, 128,  64, 255};
constexpr TGAColor yellow  = {  0, 200, 255, 255};

struct Point {
		int x = 0;
		int y = 0;
		Point(int x, int y) : x{x}, y{y} {}
};

void linearInterpolation_v3(TGAImage& framebuffer, const TGAColor& color, const Point& a, const Point& b) {
    bool steep = abs(a.x - b.x) < abs(a.y - b.y);
    if (steep) {
        int start_y = std::min(a.y, b.y);
        int end_y = std::max(a.y, b.y);
        for (int y = start_y; y <= end_y; y++) {
	        float t = (y - a.y) / static_cast<float>(b.y - a.y);
		    int x = a.x + t * (b.x - a.x);
  	        framebuffer.set(x, y, color);
        }
    } else {
        int start_x = std::min(a.x, b.x);
        int end_x = std::max(a.x, b.x);
        for (int x = start_x; x <= end_x; x++) {
	        float t = (x - a.x) / static_cast<float>(b.x - a.x);
		    int y = a.y + t * (b.y - a.y);
  	        framebuffer.set(x, y, color);
        }
    }
    return;
}

int main(int argc, char** argv) {
    constexpr int width  = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    Point a = Point(7, 3);
    Point b = Point(12, 37);
    Point c = Point(62, 53);

    framebuffer.set(a.x, a.y, white);
    framebuffer.set(b.x, b.y, white);
    framebuffer.set(c.x, c.y, white);

		linearInterpolation_v3(framebuffer, red, a, b);
		linearInterpolation_v3(framebuffer, blue, b, c);
		linearInterpolation_v3(framebuffer, yellow, c, a);

    framebuffer.write_tga_file("framebuffer.tga");
    return 0;
}

