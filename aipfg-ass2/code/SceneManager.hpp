#ifndef _SCENE_MANAGER_HPP_
#define _SCENE_MANAGER_HPP_

#include "audio-manager.hpp"
#include "openai-helper.hpp"
#include "raylib-cpp.hpp"
#include "sprite.hpp"
#include "CurrentScene.hpp"
namespace aipfg
{
	class scene
	{
	public:

		scene(CurrentMap, std::vector<Sprite*>);
		std::vector<Sprite*> all_game_chars{};
		CurrentMap map;

		void draw();
		void update();



	};
}
#endif


