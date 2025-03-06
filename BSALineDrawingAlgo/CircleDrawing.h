#pragma once
#include"PixelDraw.h"

class CircleDrawing {
	bool isFirst;
	bool isDone;
	bool isWorking;
	bool isTakingInput;
	sf::Vector2f centre;
	float radius;
	int delay;
	bool waitForNextFrame;
public:
	CircleDrawing();
	~CircleDrawing();

public:
	void RunAlgo();

	void WantToRedo(std::shared_ptr<sf::RenderWindow>window);


private:
	void Algorithm();
	void PutPixel(int x, int y);
};
