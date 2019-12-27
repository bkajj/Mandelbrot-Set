#include "src/States/hpp/MenuState.hpp"
#include "src/GameEngine/hpp/Game.hpp"

namespace hgw
{
	MenuState::MenuState(GameDataRef _data)
	{
		this->_data = _data;
	}

	void MenuState::Init()
	{

	}

	void MenuState::HandleInput()
	{
		sf::Event event;
		
		while (_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_data->window.close();
			}
		}
	}

	void MenuState::Update(float dt)
	{

	}

	void MenuState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.display();
	}
}