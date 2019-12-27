#pragma once

#include <SFML/Graphics.hpp>

namespace hgw
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteHeld(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsSpriteHeld(sf::IntRect intRect, sf::Mouse::Button button, sf::RenderWindow &window);

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::Event::EventType eventType, sf::RenderWindow &window);
		bool IsSpriteClicked(sf::IntRect intRect, sf::Mouse::Button button, sf::Event::EventType eventType, sf::RenderWindow &window);

		bool IsSpriteReleased(sf::Sprite object, sf::Mouse::Button button, sf::Event::EventType eventType, sf::RenderWindow &window);

		bool IsTextClicked(sf::Text text, sf::Mouse::Button button, sf::Event::EventType eventType, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}