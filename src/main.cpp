#include <iostream>

#include "VulkanApplication.hpp"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

int main() {
    VulkanApplication app(WIDTH, HEIGHT);

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
