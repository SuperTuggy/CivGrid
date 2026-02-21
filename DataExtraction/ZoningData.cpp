#include <curl/curl.h>
#include <iostream>
#include <string>

// This function is called by libcurl when data arrives
size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::string* response = static_cast<std::string*>(userdata);
    response->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to init curl\n";
        return 1;
    }

    std::string response;

    // 1️⃣ Where are we sending the request?
    curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/get");

    // 2️⃣ How should libcurl give us the response?
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // 3️⃣ Send the request (THIS IS THE MOMENT IT HAPPENS)
    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        std::cerr << "Request failed: "
                  << curl_easy_strerror(result) << "\n";
    } else {
        // 4️⃣ Print what the server sent back
        std::cout << "Server response:\n";
        std::cout << response << "\n";
    }

    curl_easy_cleanup(curl);
    return 0;
}
