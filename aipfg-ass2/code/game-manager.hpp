#ifndef _GAME_MANAGER_HPP_
#define _GAME_MANAGER_HPP_

#include "audio-manager.hpp"
#include "openai-helper.hpp"
#include "raylib-cpp.hpp"
#include "sprite.hpp"

#include "Scene.hpp"
namespace aipfg
{

	class TextBox;
	class PC;

	class GameManager
	{
	public:
		GameManager(raylib::Window&);

		void update();
		void draw();
		void OAIImage(std::string, std::string);
		void DrawMap();
		void ChangeScene(int);
		void UnloadMap();
		void SetScenes(std::vector<aipfg::scene>);
		AudioManager am_;
		TextBox* text_box_;
		raylib::Window& window_;
		openai_helper oai_help_;
		PC* pc_; // the player character
		raylib::Texture tex;
		Sprite spr;
		int sceneIndex;
		int boo;


		std::vector<aipfg::scene> GameScenes;
	};

} // namespace aipfg

#endif // _GAME_MANAGER_HPP_
