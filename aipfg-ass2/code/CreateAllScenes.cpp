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

aipfg::NPC make_reaper(aipfg::GameManager& gm, raylib::Texture& tex)
{
	using namespace aipfg;

	aipfg::Sprite s{ tex, 3, 4, { 886, 134 } };
	const std::string nature =
		"The following is a conversation with the grim reaper. The grim reaper is a "
		"personified force. In some mythologies, the grim reaper causes the "
		"victim's death by coming to collect that person's soul.\n\n";
	const std::string gambit = "Why are you here?";
	const std::string name = "Reaper";

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
	const std::string name = "Green Knight";
	const std::string gambit =
		"And who, is governor of this gaggle?";
	// "I'll be glad to know. It's with him and no one else I'll hold a pact.";

	return { gm, s, name, { nature, gambit } };
}
namespace aipfg
{
	std::vector<scene> scenes_;
	NPC green = make_green_knight();
	void Start()
	{

		CurrentMap m = MakeMap(LoadTiled("../resources/ashlands.json"));
		scenes_.push_back(MakeScene(m,))
		

	}

	
	CurrentMap MakeMap(Map m_)
	{
		return{ m_ };
	}
	scene MakeScene(CurrentMap m,std::vector<Sprite*> chars)
	{

		return{ m,chars };
	}

	
} 