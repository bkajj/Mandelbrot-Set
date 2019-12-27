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

		inline double mandelbrot(std::complex<long double> c);
		inline std::complex<long double> indexToComplex(long double x, long double y, long double div, long double X, long double Y);
		inline sf::Color toRGB(int hue, int sat, int val);

		static const int MAX_ITER = 500;
		long double divZoom = 200;
	private:
		GameDataRef _data;

		sf::Vertex grid[800][800];
	};
}