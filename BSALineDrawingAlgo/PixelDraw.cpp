#include "PixelDraw.h"
#include"Utility.h"

PixelDraw pixels;


PixelDraw::PixelDraw():isCalcDone(false){
	this->pixels.reserve(Utility::PIXEL_COUNT.x * Utility::PIXEL_COUNT.y);
	for (int y = 0; y < Utility::PIXEL_COUNT.y; ++y) {
		for (int x = 0; x < Utility::PIXEL_COUNT.x; ++x) {
			sf::RectangleShape s;
			s.setPosition(sf::Vector2f(Utility::PIXEL_SIZE * x, Utility::PIXEL_SIZE * y));
			s.setFillColor(sf::Color::Black);
			s.setSize(sf::Vector2f(Utility::PIXEL_SIZE, Utility::PIXEL_SIZE));
			if (Utility::IS_PADDING) {
				s.setOutlineThickness(0.5f);
				s.setOutlineColor(sf::Color::White);
			}
			this->pixels.push_back(std::make_shared<PixelsData>(
				std::make_shared<sf::RectangleShape>(s), sf::Vector2i(x, y)));;
		}
	}
}

PixelDraw::~PixelDraw(){}

void PixelDraw::Load(){}



void PixelDraw::Draw(std::shared_ptr<sf::RenderWindow> window){
	for (std::shared_ptr<PixelsData> pixeldata: this->pixels) {
		window->draw(*pixeldata->pixel);
	}
}







void PixelDraw::PutPixel(int x, int y, sf::Color color){
	if ((x >= 0 && x < Utility::PIXEL_COUNT.x)
		&& y >= 0 && y < Utility::PIXEL_COUNT.y) {
		int index = GetPixelIndex(x, y);
		this->pixels[index]->pixel->setFillColor(color);
	}
}






void PixelDraw::ReInitAllPixels(){
	for (std::shared_ptr<PixelsData> pixelData : this->pixels) {
		pixelData->pixel->setFillColor(sf::Color::Black);
		pixelData->alreadyVisited = pixelData->alreadyPushed = false;
	}
}

int PixelDraw::GetPixelIndex(const int x, const int y){
	return y * Utility::PIXEL_COUNT.x + x;
}



std::shared_ptr<PixelsData> PixelDraw::GetPixel(int index){
	return this->pixels[index];
}


