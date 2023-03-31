#include "sprite.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "game-manager.hpp"
#include "openai-helper.hpp"
#include "CurrentScene.hpp"
#include "raylib-tileson.h"
#include "raylib-cpp.hpp"
#include "SceneManager.hpp"
#include <string>     // std::string
#include <vector>     // std::vector
#include <numeric>    // std::iota
#include <iostream>   // std::cout
#include <future>     // std::async
#include <functional> // std::ref
#include <map>        // std::map
#include <algorithm>  // std::sort
#include <thread>
// This version makes the call to OpenAI asynchronous; and add a resizable
// window. Also, Sprite class now removes set_* member functions, and a new NPC
// and PC class is added. Also added exception handler to OpenAI code.
// Sprite now has an update member function: more logical to update the
// animation here

aipfg::NPC make_reaper(aipfg::GameManager&, raylib::Texture&);
aipfg::NPC make_green_knight(aipfg::GameManager&, raylib::Texture&);
aipfg::scene makeScene(aipfg::CurrentMap,std::vector<sprite*>)


int main(int argc, char *argv[])
{
  using namespace aipfg;

  raylib::Window window(1024, 576, "Raylib OpenAI NPCs Extended");
  window.SetState(FLAG_WINDOW_RESIZABLE);

  raylib::RenderTexture rt{ GetScreenWidth(), GetScreenHeight() };

  SetTargetFPS(60);            // Set our game to run at 60 frames-per-second
  
  GameManager gm{ window };
  
  
  gm.ChangeMap("../resources/ashlands.json");
 
  raylib::Texture tex1{ "../resources/time_fantasy/knights_3x.png" };
  raylib::Texture tex2{ "../resources/time_fantasy/reaper_blade_3.png" };
  
 
  int ncols = 12, nrows = 8;
  std::map<std::string, std::vector<int>> all_frame_ids;
  all_frame_ids["down"]  = {  3,  4,  5,  3 };
  all_frame_ids["left"]  = { 15, 16, 17, 16 };
  all_frame_ids["right"] = { 27, 28, 29, 28 };
  all_frame_ids["up"]    = { 39, 40, 41, 40 };
  Sprite sprt { tex1, ncols, nrows, { 40, 200 }, all_frame_ids, 6 };
  PC pc{ gm, sprt, "Human" };
 

  NPC knight = make_green_knight(gm, tex1);
  NPC reaper = make_reaper(gm, tex2);
  
  std::vector<Sprite*> all_game_chars{ &pc, &knight, &reaper };

  while (!window.ShouldClose()) // Detect window close button or ESC key
  {
    gm.update();

    pc.update();
    reaper.update();
    knight.update();
    
    BeginTextureMode(rt);

    ClearBackground(RAYWHITE);

    gm.DrawMap();

    // Drawn from back (-ve y coord) to front (+ve y coord)
    auto comp = [](Sprite* s1, Sprite* s2) { return (*s1).posn_.y < (*s2).posn_.y; };
    std::sort(all_game_chars.begin(), all_game_chars.end(), comp);
    for (const auto& s : all_game_chars) { (*s).draw(); }
    gm.draw(); // possibly draw the text box
    
    EndTextureMode();

    BeginDrawing();
    DrawTexturePro(
      rt.texture,
      Rectangle{ 0, 0, static_cast<float>(rt.texture.width), static_cast<float>(-rt.texture.height) },
      Rectangle{ 0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) },
      Vector2{ 0, 0 },
      0,
      WHITE);
    EndDrawing();
  }
  
  gm.UnloadMap();

  std::cout << "Waiting for the future's result to become available...\n";
  knight.text_box_wait();
  reaper.text_box_wait();

  return 0;
}

aipfg::NPC make_reaper(aipfg::GameManager& gm, raylib::Texture& tex)
{
  using namespace aipfg;

  aipfg::Sprite s{ tex, 3, 4, { 886, 134 } };
  const std::string nature =
   "The following is a conversation with the grim reaper. The grim reaper is a "
   "personified force. In some mythologies, the grim reaper causes the "
   "victim's death by coming to collect that person's soul.\n\n";
  const std::string gambit = "Why are you here?";
  const std::string name   = "Reaper";

  return { gm, s, name, { nature, gambit } };
}

aipfg::NPC make_green_knight(aipfg::GameManager& gm, raylib::Texture& tex)
{
  using namespace aipfg;

  aipfg::Sprite s{ tex, 12, 8, { 422, 340 }, {{ "", { 10 } }} };
  std::string nature =
    "The following is a conversation with the Green Knight. The Green Knight "
    "is a character from a classic 14th-century chivalric romance written in "
    "Middle English. The Green Knight represents a unity of two concepts, "
    "nature, and chivalry. First, the connection with nature is clear from his "
    "clothes, armour, green skin, and horse. Second, going further, we can "
    "observe he represents the spirit of vegetation.\n\n";
  const std::string name   = "Green Knight";
  const std::string gambit =
    "And who, is governor of this gaggle?";
    // "I'll be glad to know. It's with him and no one else I'll hold a pact.";

  return { gm, s, name, { nature, gambit } };
}


