#include <vulkan/vulkan.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char*argv[])
{
    auto name = "vulkansamples_instance";
    VkApplicationInfo app_info ;
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pNext = nullptr;
    app_info.pApplicationName = name;
    app_info.applicationVersion = 1;
    app_info.pEngineName = name;
    app_info.engineVersion = 1;
    app_info.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo inst_info;
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    inst_info.pNext = nullptr;
    inst_info.flags = 0;
    inst_info.pApplicationInfo = &app_info;
    inst_info.enabledExtensionCount = 0;
    inst_info.ppEnabledExtensionNames = NULL;
    inst_info.enabledLayerCount = 0;
    inst_info.ppEnabledLayerNames = NULL;

    VkInstance inst;
    VkResult ret;

    ret = vkCreateInstance(&inst_info,NULL,&inst);
    if (ret == VK_ERROR_INCOMPATIBLE_DRIVER) {
        std::cout << "cannot find a compatible Vulkan ICD\n";
        exit(-1);
    } else if (ret) {
        std::cout << "unknown error\n";
        exit(-1);
    }

    vkDestroyInstance(inst, NULL);

    return 0;
}