#pragma once
#include"PixelDraw.h"

class BSALineDraw{
	bool isFirst;
	bool isDone;
	bool isWorking;
	bool isTakingInput;
	sf::Vector2f position1;
	sf::Vector2f position2;
	int delay;
	bool waitForNextFrame;


public:
	BSALineDraw();
	~BSALineDraw();

public:
	void BsaWork();

	void WantToRedo(std::shared_ptr<sf::RenderWindow>window);


private:
	void BSALineALgo();

};

