#include "BSALineDraw.h"
#include<algorithm>


BSALineDraw::BSALineDraw():
	isFirst(true), isDone(false), isTakingInput(false), isWorking(false),
	position1(),position2() , waitForNextFrame(true){
	this->delay = 0;
}

BSALineDraw::~BSALineDraw(){}


void BSALineDraw::BsaWork(){
	if (this->isFirst) {
		this->isFirst = false;
		this->isTakingInput = true;
	} 
	else if (this->isTakingInput) {
		std::cout << "enter  two pixel positions = x1,y1 , x2,y2 \n";
		std::cin >> position1.x >> position1.y >> position2.x >> position2.y;
		this->isTakingInput = false;
		this->isDone = false;
		this->isWorking = true;
	}
	else if (this->isWorking) {
		BSALineALgo();
	}
}

void BSALineDraw::WantToRedo(std::shared_ptr<sf::RenderWindow>window){
	if (this->isDone) {
		if (this->waitForNextFrame) {
			this->waitForNextFrame = false;
		}
		else {
			char c;
			std::cout << "do you want  to redo = y/n  this is case sensitive \n ";
			std::cin >> c;
			if (c == 'y' || c == 'Y') {
				this->isDone = false;
				this->isWorking = false;
				this->isTakingInput = false;
				this->isFirst = true;
				this->waitForNextFrame = true;
				pixels.ReInitAllPixels();
			}
			else {
				window->close();
			}
		}
	}
}

void BSALineDraw::BSALineALgo(){
	int dx = int(position2.x - position1.x);
	int dy = int(position2.y - position1.y);

	int steps = std::max(abs(dx), abs(dy));
	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;

	float x = position2.x , y = position2.y;

	for (int i = 0; i <= steps; i++) {
		pixels.PutPixel(int(x), int(y), sf::Color::White);
		x += xIncrement;
		y += yIncrement;
	}

	this->isTakingInput = false;
	this->isWorking = false;
	this->isDone = true;
}
