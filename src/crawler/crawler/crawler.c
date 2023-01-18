#include <stdlib.h>
#include <curl/curl.h>
#include <stdio.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}


int main(int argc, char *argv[])
{
    CURL *curl_handle;
    static const char *pagefilename = "page.out";
    FILE *pagefile;

    if(argc < 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_ALL);

    // Init the curl session
    curl_handle = curl_easy_init();

    // Set URL to get here
    curl_easy_setopt(curl_handle, CURLOPT_URL, argv[1]);

    // Switch on full protocol/debug output while testing
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    // Disable progress meter, set to 0L to enable it
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

    // send all data to this function
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    // Open the file
    pagefile = fopen(pagefilename, "wb");
    if(pagefile)
    {
        // Write the page body to this file handle
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);

        // Get it
        curl_easy_perform(curl_handle);

        // close the header file
        fclose(pagefile);
    }

    // Cleanup curl stuff
    curl_easy_cleanup(curl_handle);

    curl_global_cleanup();

    return 0;
}
