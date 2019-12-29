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

		inline double mandelbrot(std::complex<long double> &c, const double &zoom);
		inline std::complex<long double> indexToComplex(int &x, int &y);
		inline sf::Color toRGB(int &hue, int& sat, int &val);
		inline void zoom(const double &scale, sf::Vector2i &mousePos);
		inline void CalculateMandelbrot(const double &scale);

		const int MAX_ITER = 500;
		const double ZOOM_VALUE = 5;
	private:
		GameDataRef _data;

		sf::Vertex grid[800][800];
		std::complex<long double> complexGrid[800][800];
	};
}