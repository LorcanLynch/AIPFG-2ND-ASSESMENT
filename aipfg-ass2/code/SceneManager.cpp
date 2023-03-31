#include "sprite.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "game-manager.hpp"
#include "openai-helper.hpp"
#include "CurrentScene.hpp"
#include "raylib-tileson.h"
#include "raylib-cpp.hpp"
#include <string>     // std::string
#include <vector>     // std::vector
#include <numeric>    // std::iota
#include <iostream>   // std::cout
#include <future>     // std::async
#include <functional> // std::ref
#include <map>        // std::map
#include <algorithm>  // std::sort
#include <thread>
#include "SceneManager.hpp"
namespace aipfg
{

	
	scene::scene(CurrentMap m_, std::vector<Sprite*>sceneChars) :map{ m_ }, all_game_chars{ sceneChars } {
		
	}
	void scene::draw()
	{
		map.DrawMap_();
		auto comp = [](Sprite* s1, Sprite* s2) { return (*s1).posn_.y < (*s2).posn_.y; };
		std::sort(all_game_chars.begin(), all_game_chars.end(), comp);
		for (const auto& s : all_game_chars) { (*s).draw(); }
		
	}

	

}