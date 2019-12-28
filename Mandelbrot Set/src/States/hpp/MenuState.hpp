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

		inline double mandelbrot(std::complex<long double> c, int zoom);
		//inline std::complex<long double> indexToComplex(int x, int y, int zoom, sf::Vector2i mousePos);
		inline std::complex<long double> indexToComplex(int x, int y);
		inline sf::Color toRGB(int hue, int sat, int val);
		inline void zoom(int scale, sf::Vector2i mousePos);
		inline void XD(int zoom, sf::Vector2i mousePos);

		static const int MAX_ITER = 50;
		long double divZoom = 200;
		int zoomVal = 1, totalZoom = 0;
		sf::Vector2i mousePos, lastMousePos;
	private:
		GameDataRef _data;

		sf::Vertex grid[800][800];
		std::complex<long double> complexGrid[800][800];
	};
}