#pragma once
#include"PixelDraw.h"
#include<SFML/Graphics.hpp>
#include<memory>
#include<vector>
#include<stack> 

class FloodFillAlgo {
	bool isFirst;
	bool isDone;
	bool isWorking;
	bool isTakingInput;
	bool waitForNextFrame;

	sf::Vector2f rectanglePosition;
	sf::Vector2f rectangleSize;
	sf::Vector2i initialPos;

	std::stack<std::shared_ptr<PixelsData>> stack;

public:
	FloodFillAlgo();
	~FloodFillAlgo();

public:
	void FloodFillStart();
	void WantToRedo(std::shared_ptr<sf::RenderWindow>window);


private:
	void FloodFillAlgoStart();
	bool CheckIsValid(const int x, const int y)const;
	void B();

	void FillThePixel(std::shared_ptr<PixelsData> pixel);
	void Propagate(std::shared_ptr<PixelsData>pixel);

};
