#include "src/States/hpp/MenuState.hpp"
#include "src/GameEngine/hpp/Game.hpp"
#include <iostream>
#include <complex>

namespace hgw
{
	MenuState::MenuState(GameDataRef _data)
	{
		this->_data = _data;
	}

	void MenuState::Init()
	{
		for (int i = 0; i < 800; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				grid[i][j].position = sf::Vector2f(float(i), float(j));
				complexGrid[i][j] = indexToComplex(i, j);		
			}
		}
		double noZoom = 1;
		CalculateMandelbrot(noZoom, sf::Vector2i(400, 400));
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(_data->window);
				if (mousePos.x > 0 && mousePos.x < 800 && mousePos.y > 0 && mousePos.y < 800)
				{
					CalculateMandelbrot(ZOOM_VALUE, mousePos);
				}
			}
		}
	}

	void MenuState::CalculateMandelbrot(double scale, sf::Vector2i mousePos)
	{
		zoom(scale, mousePos);

		for (int i = 0; i < 800; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				int escapeVal = mandelbrot(complexGrid[i][j], scale);

				if (escapeVal == MAX_ITER)
				{
					grid[i][j].color = sf::Color::Black;
				}
				else
				{
					int hue = 360 * escapeVal / MAX_ITER;
					int saturation = 1;
					int value;
					if (escapeVal < MAX_ITER)
					{
						value = 1;
					}
					else
					{
						value = 0;
					}

					grid[i][j].color = toRGB(hue, saturation, value);
				}
			}
		}
	}

	void MenuState::Update(float dt)
	{
		int X = sf::Mouse::getPosition(_data->window).x;
		int Y = sf::Mouse::getPosition(_data->window).y;

		std::cout << "X: " << X << "   Y: " << Y << std::endl;
	}

	void MenuState::Draw(float dt)
	{
		_data->window.clear(sf::Color::White);

		for (int i = 0; i < 800; i++)
		{
			_data->window.draw(grid[i], 800, sf::Points);
		}

		_data->window.display();
	}

	int MenuState::mandelbrot(std::complex<long double> c, double zoom)
	{
		int n = 0;
		std::complex<long double> z = 0;

		while (std::abs(z) <= 2 && n < MAX_ITER)
		{
			z = z * z + c;
			n++;
		}
		
		if (n == MAX_ITER)
		{
			return MAX_ITER;
		}
		return n + 1 - log(log2(abs(z)));
	}

	std::complex<long double> MenuState::indexToComplex(int index_x, int index_y)
	{
		long double x = (grid[index_x][index_y].position.x - 400) / 200;
		long double y = (grid[index_x][index_y].position.y - 400) / -200;

		return std::complex<long double>{x, y};
	}

	void MenuState::zoom( double scale, sf::Vector2i mousePos)
	{
		for (int i = 0; i < 800; i++)
		{
			for (int j = 0; j < 800; j++)
			{
				std::complex<long double> relativePos = complexGrid[i][j] - complexGrid[mousePos.x][mousePos.y];
				relativePos /= std::complex<long double>(scale, 0);
				std::complex<long double> posPrim = relativePos + complexGrid[mousePos.x][mousePos.y];

				complexGrid[i][j] = posPrim;
			}
		}
	}

	sf::Color MenuState::toRGB(int h, int s, int v)
	{
		double C = v * s;
		double X = C * (1 - abs((h / 60) % 2 - 1));
		double m = v - C;
		double Rp, Gp, Bp;
		if (h >= 300)
		{
			Rp = C;
			Gp = 0;
			Bp = X;
		}
		else if (h >= 240)
		{
			Rp = X;
			Gp = 0;
			Bp = C;
		}
		else if (h >= 180)
		{
			Rp = 0;
			Gp = X;
			Bp = C;
		}
		else if (h >= 120)
		{
			Rp = 0;
			Gp = C;
			Bp = X;
		}
		else if (h >= 60)
		{
			Rp = X;
			Gp = C;
			Bp = 0;
		}
		else if (h >= 0)
		{
			Rp = C;
			Gp = X;
			Bp = 0;
		}
		else
		{
			std::cout << "wtf" << std::endl;
		}

		sf::Color rgb = sf::Color((Rp + m) * 255, (Gp + m) * 255, (Bp + m) * 255);
		return rgb;
	}
}