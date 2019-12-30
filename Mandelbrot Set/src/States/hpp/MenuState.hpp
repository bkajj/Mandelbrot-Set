#pragma once
#include "src/GameEngine/hpp/State.hpp"
#include "src/GameEngine/hpp/Game.hpp"
#include <complex>

namespace hgw
{
	class MenuState : public State
	{
	public:
		MenuState(GameDataRef _data);
		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		int mandelbrot(std::complex<long double> c, double zoom);
		std::complex<long double> indexToComplex(int x, int y);
		sf::Color toRGB(int hue, int sat, int val);
		void zoom (double scale, sf::Vector2i mousePos);
		void CalculateMandelbrot(double scale, sf::Vector2i mousePos);

		const int MAX_ITER = 30;
		const double ZOOM_VALUE = 5;
	private:
		GameDataRef _data;

		sf::Vertex grid[800][800];
		std::complex<long double> complexGrid[800][800];
	};
}