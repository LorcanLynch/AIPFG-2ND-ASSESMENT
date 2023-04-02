
#ifndef _SCENE_HPP_
#define _SCENE_HPP_


#include "sprite.hpp"
#include "CurrentScene.hpp"
#include <string>     // std::string
#include <vector>     // std::vector
#include <numeric>    // std::iota
#include <iostream>   // std::cout
#include <future>     // std::async
#include <functional> // std::ref
#include <map>        // std::map
#include <algorithm>  // std::sort
#include <thread>
namespace aipfg
{
	class scene
	{
	public:

		scene(CurrentMap, std::vector<Sprite*>);
		std::vector<Sprite*> all_game_chars{};
		CurrentMap map;

		void draw();




	};
}
#endif //_SCENE_HPP_
