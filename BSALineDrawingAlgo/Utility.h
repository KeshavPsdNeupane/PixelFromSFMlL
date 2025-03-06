#pragma once
#include<SFML/Graphics.hpp>

namespace Utility {
	const sf::Vector2f WINDOWSIZE(800.0f, 600.0f);
	const float PIXEL_SIZE = 5.0f;
	const sf::Vector2i PIXEL_COUNT(static_cast<int>(WINDOWSIZE.x / PIXEL_SIZE), static_cast<int>(WINDOWSIZE.y / PIXEL_SIZE));
	const bool IS_PADDING = false;


	const bool BSA_LINE_DRAW = false;
	const bool CircleDraw = false;
	const bool FloodFill = true;
}