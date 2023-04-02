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
        : am_{}, text_box_{}, window_{ window }, oai_help_{}, pc_{}, tex{ "../build/currentimage.png" }, spr{ tex }, sceneIndex{ 0 } {}


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
    void GameManager::OAIImage(std::string prompt, std::string name)
    {
        //std::future<void> fh{};
        oai_help_.CreateImage(prompt, name);
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
            DrawTexture(tex, 750, 0, WHITE);
        }

    }

    void GameManager::ChangeScene(int newIndex)
    {
        sceneIndex = newIndex;

    }

    void GameManager::SetScenes(std::vector<scene> scenes)
    {
        GameScenes = scenes;
    }

    void GameManager::DrawMap()
    {
        GameScenes[sceneIndex].draw();
    }

    void GameManager::UnloadMap()
    {
        GameScenes[sceneIndex].unload();
    }
} // namespace aipfg

