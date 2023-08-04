#ifndef VULKAN_APP_H
#define VULKAN_APP_H

#include <vector>
#include <optional>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

class VulkanApplication {
public:
    VulkanApplication(uint32_t WIDTH, uint32_t HEIGHT);

    void run();

private:
    const std::vector <const char *> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    uint32_t WIDTH;
    uint32_t HEIGHT;

    GLFWwindow* window;
    VkInstance instance;
    
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    VkDebugUtilsMessengerEXT debugMessenger;

    void initWindow();
    void initVulkan();

    void mainLoop();
    void cleanup();

    int rateDeviceSuitability(VkPhysicalDevice);

    void pickPhysicalDevice();

    void setupDebugMessenger();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT&);

    void createInstance();

    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice);
};

#endif