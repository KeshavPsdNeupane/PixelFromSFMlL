#pragma once
#include<memory>
#include<vector>
#include<SFML/Graphics.hpp>
#include<iostream>

struct PixelsData {
	std::shared_ptr<sf::RectangleShape>pixel;
	sf::Vector2i position;
	bool alreadyVisited;  /// only needed for flood fill
	bool alreadyPushed;

	PixelsData(std::shared_ptr<sf::RectangleShape>pixel, sf::Vector2i position) :
		pixel(pixel), position(position) {
		this->alreadyVisited = this->alreadyPushed = false;
	}
};



class PixelDraw {
	std::vector<std::shared_ptr<PixelsData>> pixels;
	bool isCalcDone;
public:
	PixelDraw();
	~PixelDraw();
public:
	void Load();
	void Draw(std::shared_ptr<sf::RenderWindow>window);
	void PutPixel(int x, int y, sf::Color color);
	void ReInitAllPixels();
	int GetPixelIndex(const int x, const int y);
	std::shared_ptr<PixelsData> GetPixel(int index);
};

extern PixelDraw pixels;
