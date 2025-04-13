#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#include <curl/curl.h>

#include <string>

static void write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *output = (std::string *)userdata;

    output->reserve(output->size() + nmemb);

    for (size_t i = 0; i < nmemb; i++)
    {
        output->push_back(ptr[i]);
    }
}

std::string download(const std::string &url)
{
    curl_global_init(CURL_GLOBAL_DEFAULT);

    CURL *curl = curl_easy_init();

    std::string output;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_NONE);
    curl_easy_setopt(curl, CURLOPT_HTTP09_ALLOWED, 1L);

    CURLcode code = curl_easy_perform(curl);
    printf("Code: %s\n", curl_easy_strerror(code));

    curl_easy_cleanup(curl);

    curl_global_cleanup();

    return output;
}