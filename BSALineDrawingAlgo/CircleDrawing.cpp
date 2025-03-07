#include "CircleDrawing.h"
#include<algorithm>


CircleDrawing::CircleDrawing() :
	isFirst(true), isDone(false), isTakingInput(false), isWorking(false),
	centre(0.0f,0.0f), radius(0), waitForNextFrame(true) {
	this->delay = 0;
}
CircleDrawing::~CircleDrawing() {}


void CircleDrawing::RunAlgo(std::shared_ptr<sf::RenderWindow>window) {
	if (this->isFirst) {
		this->isFirst = false;
		this->isTakingInput = true;
	}
	else if (this->isTakingInput) {
		std::cout << "enter  centre = x1,y1 and radius r \n";
		std::cin >> centre.x >> centre.y >> radius;
		this->isTakingInput = false;
		this->isDone = false;
		this->isWorking = true;
	}
	else if (this->isWorking) {
		Algorithm();
	}
	else {
		WantToRedo(window);
	}
}

void CircleDrawing::WantToRedo(std::shared_ptr<sf::RenderWindow>window) {
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

void CircleDrawing::Algorithm() {
	pixels.PutPixel(int(centre.x), int(centre.y), sf::Color::White);
	sf::Vector2i plotPoint(0, int(this->radius));
	int decision = 1 - int(this->radius);

	while (plotPoint.x <= plotPoint.y) {
		if (decision < 0) {
			PutPixel(plotPoint.x, plotPoint.y);
			++plotPoint.x;
			decision = decision + 2 * plotPoint.x + 1;
		}
		else {
			PutPixel(plotPoint.x, plotPoint.y);
			++plotPoint.x; --plotPoint.y;
			decision = decision + 2 * plotPoint.x - 2 * plotPoint.y + 1;
		}
	}
	this->isTakingInput = false;
	this->isWorking = false;
	this->isDone = true;
}

void CircleDrawing::PutPixel(int x, int y){
	pixels.PutPixel(int(centre.x) + x,int(centre.y) + y, sf::Color::White);
	pixels.PutPixel(int(centre.x) - x,int(centre.y) + y, sf::Color::White);
	pixels.PutPixel(int(centre.x) + x,int(centre.y) - y, sf::Color::White);
	pixels.PutPixel(int(centre.x) - x,int(centre.y) - y, sf::Color::White);
	pixels.PutPixel(int(centre.x) + y,int(centre.y) + x, sf::Color::White);
	pixels.PutPixel(int(centre.x) - y,int(centre.y) - x, sf::Color::White);
	pixels.PutPixel(int(centre.x) + y,int(centre.y) - x, sf::Color::White);
	pixels.PutPixel(int(centre.x) - y,int(centre.y) + x, sf::Color::White);
}
