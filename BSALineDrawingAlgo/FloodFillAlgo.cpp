#include "FloodFillAlgo.h"
#include<algorithm>


FloodFillAlgo::FloodFillAlgo() :
	isFirst(true), isDone(false), isTakingInput(false), isWorking(false),
	waitForNextFrame(true) , rectanglePosition() ,rectangleSize(){}

FloodFillAlgo::~FloodFillAlgo() {}


void FloodFillAlgo::FloodFillStart() {
	if (this->isFirst) {
		this->isFirst = false;
		this->isTakingInput = true;
	}
	else if (this->isTakingInput) {
		std::cout << "enter  rectangle position and size = x,y , w ,h \n";
		std::cin >> rectanglePosition.x >> rectanglePosition.y >> rectangleSize.x >> rectangleSize.y;
		this->isTakingInput = false;
		this->isDone = false;
		this->isWorking = true;
		this->initialPos = sf::Vector2i(int(this->rectanglePosition.x + this->rectangleSize.x * 0.5f),
			int(this->rectanglePosition.y + this->rectangleSize.y * 0.5f));
		stack.push(pixels.GetPixel(pixels.GetPixelIndex(this->initialPos.x, this->initialPos.y)));
	}
	else if (this->isWorking) {
		FloodFillAlgoStart();
	}
}

void FloodFillAlgo::WantToRedo(std::shared_ptr<sf::RenderWindow>window) {
	if (this->isDone) {
		if (this->waitForNextFrame) {
			this->waitForNextFrame = false;
		}
		else {
			char c;
			std::cout << " \n do you want  to redo = y/n  this is case sensitive \n ";
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

void FloodFillAlgo::FloodFillAlgoStart() {
	std::cout << stack.size() << ",";
	if (!stack.empty()) {
		std::shared_ptr<PixelsData> top = stack.top();
		stack.pop();
		if (!top->alreadyVisited) {
			FillThePixel(top);
			Propagate(top);
		}
	}
	else { B(); }
}

bool FloodFillAlgo::CheckIsValid(const int x, const int y)const {
	return  (x >= rectanglePosition.x && x < rectanglePosition.x + rectangleSize.x) &&
		(y >= rectanglePosition.y && y < rectanglePosition.y + rectangleSize.y);
}

void FloodFillAlgo::B(){
	this->isTakingInput = false;
	this->isWorking = false;
	this->isDone = true;
}

void FloodFillAlgo::FillThePixel(std::shared_ptr<PixelsData> pixel){
	pixel->alreadyVisited = true;
	pixel->pixel->setFillColor(sf::Color::White);
}

void FloodFillAlgo::Propagate(std::shared_ptr<PixelsData> pixel){
	sf::Vector2i position(pixel->position);
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			sf::Vector2i newpos(position + sf::Vector2i(i, j));
			if (CheckIsValid(newpos.x, newpos.y)) {
				auto newPixe = pixels.GetPixel(pixels.GetPixelIndex(newpos.x, newpos.y));
				if (!newPixe->alreadyVisited && !newPixe->alreadyPushed) {
					newPixe->alreadyPushed = true;
					stack.push(newPixe);
				}
			}
		}
	}

}

