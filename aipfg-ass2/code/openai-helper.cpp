#include "openai-helper.hpp"
#include "include/liboai.h"
#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <exception>
#include <filesystem> // std::filesystem::path

// Basically, we need the OpenAI code in a separate translation unit than Raylib
// https://github.com/raysan5/raylib/issues/1217

namespace aipfg
{

openai_helper::openai_helper()
{
  oai_ = new liboai::OpenAI{};
  if (!(*oai_).auth.SetKeyFile("../.env"))
  {
    throw std::runtime_error{ "ERROR!: .env file not found." };
  }
}

void openai_helper::submit(const std::string& prompt, std::string& response_str,
                           const std::optional<std::vector<std::string>>& stop)
{
  const std::string model_id  = "text-davinci-003";
  // const std::optional<std::string> prompt = std::nullopt;
  const std::optional<std::string> suffix = std::nullopt;
  const std::optional<uint16_t> max_tokens = 150;
  const std::optional<float> temperature = 0.9f;
  const std::optional<float> top_p = std::nullopt;
  const std::optional<uint16_t> n = std::nullopt;
  const std::optional<std::function<bool(std::string, intptr_t)>> stream = std::nullopt;
  const std::optional<uint8_t> logprobs = std::nullopt;
  const std::optional<bool> echo = std::nullopt;
  //  const std::optional<std::vector<std::string>> stop = std::nullopt;
  const std::optional<float> presence_penalty = std::nullopt;
  const std::optional<float> frequency_penalty = std::nullopt;
  const std::optional<uint16_t> best_of = std::nullopt;
  const std::optional<std::unordered_map<std::string, int8_t>> logit_bias = std::nullopt;
  const std::optional<std::string> user = std::nullopt;

  try {

    liboai::Response response =
      (*oai_).Completion->create(
        model_id, prompt, suffix, max_tokens, temperature, top_p, n, stream,
        logprobs, echo, stop, presence_penalty, frequency_penalty, best_of,
        logit_bias, user
      );

    response_str = response["choices"][0]["text"].get<std::string>();

  } catch (std::exception& e) {

    const auto this_file = std::filesystem::path{__FILE__}.filename();
    std::cerr << "Exception caught at line " << __LINE__;
    std::cerr << " in " << this_file << std::endl;
    std::cerr << e.what() << std::endl;

  }
}

void openai_helper::CreateImage(std::string Prompt)
{
    
        using namespace liboai;
        OpenAI oai;
        std::string size = "256x256";
        UINT8 n = 1;
        if (oai.auth.SetKeyFile("../.env"))
        {
            try {
                
                Response response = oai.Image->create(
                   Prompt,n,size
                );
                Network::Download(
                    "CurrentImage.png", // add a string holding a png filename here
                    response["data"][0]["url"].get<std::string>()
                );
            }
            catch (std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

      
    
}

openai_helper::~openai_helper()
{
  delete oai_;
  
}

} // namespace aipfg
