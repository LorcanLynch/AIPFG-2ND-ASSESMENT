#include "game-manager.hpp"
#include "audio-manager.hpp"
#include "openai-helper.hpp"
#include "text-box.hpp"
#include "raylib-cpp.hpp"
#include "sprite.hpp"
#include <thread>
namespace aipfg
{
    
GameManager::GameManager(raylib::Window& window)
    : am_{}, text_box_{}, window_{ window }, oai_help_{}, pc_{}, tex{ "../build/currentimage.png" }, spr{ tex }, gmMap_{ LoadTiled("../resources/ashlands.json") } {}


void GameManager::update()
{
  am_.update();
  if (text_box_)
  {
    if (false == (*text_box_).update()) // make text_box_ a member of GameManager
    {
      text_box_ = nullptr;
      am_.dehush();
    }
  }
}
void GameManager::OAIImage(std::string prompt)
{
    std::future<void> fh{};
  fh=  std::async(std::launch::async, &openai_helper::CreateImage, &oai_help_, prompt);
    /*if(fh.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
        tex = { "../build/currentimage.png" };
        }*/
    

}

void GameManager::draw()
{
   
  if (text_box_)
  {
    (*text_box_).draw();
    DrawTexture(tex, 750,0, WHITE);
  }

}

void GameManager::ChangeMap(const char* newMap)
{
    gmMap_.ChangeMap(newMap);
}

void GameManager::DrawMap()
{
    gmMap_.DrawMap_();
}

void GameManager::UnloadMap()
{
    gmMap_.unloadMap();
}
} // namespace aipfg
