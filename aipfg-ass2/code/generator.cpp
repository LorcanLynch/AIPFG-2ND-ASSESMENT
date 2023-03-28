#include "include/liboai.h"

// HTTP_PROXY  146.191.228.21:9090
// HTTPS_PROXY 146.191.228.21:9090
using namespace liboai;
int generate()
{
    
  
    OpenAI oai;

    if (oai.auth.SetKeyFile("../.env"))
    {
        try {
            Response response = oai.Image->create(
                "a siamese cat!"
            );
            Network::Download(
                "", // add a string holding a png filename here
                response["data"][0]["url"].get<std::string>()
            );
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
