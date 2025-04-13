#include "downloader.hpp"

#include <format>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

std::string download(const std::string &url)
{
#ifdef _WIN32
    std::string curl_cmd = "curl.exe";
#else
    std::string curl_cmd = "curl";
#endif

    std::string cmd = std::format("{} -L \"{}\" -o downloaded_file", curl_cmd, url);
    int status = system(cmd.c_str());
    if (status != 0)
    {
        std::cerr << "Failed to download!" << std::endl;
        return {};
    }

    std::stringstream ss;
    std::ifstream file("downloaded_file");
    ss << file.rdbuf();
    return ss.str();
}