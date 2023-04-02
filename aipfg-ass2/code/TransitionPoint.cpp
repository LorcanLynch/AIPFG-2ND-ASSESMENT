#include "npc.hpp"
#include "pc.hpp"
#include "sprite.hpp"
#include "game-manager.hpp"
#include "text-box.hpp"
#include "raylib-cpp.hpp"
#include <future>     // std::async
#include <functional> // std::ref
#include <iostream>

#include "transitionPoint.hpp"
namespace aipfg
{
    transition::transition(Vector2 pos, int index, int aIndex, GameManager& gm) : posn_{ pos }, sIndex{ index }, activeIndex{ aIndex }, gm_{ gm } {}


    void transition::Update()
    {
        if (Vector2Distance(posn_,gm_.pc_->posn_) < 30.0f&&gm_.sceneIndex == activeIndex)
        {
            if (gm_.sceneIndex = 1)
            {
                gm_.sceneIndex = sIndex;
            }
            else
            {
                gm_.sceneIndex = 1;
            }
            

            
        }
      
       
    }
}