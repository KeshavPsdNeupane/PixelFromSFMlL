#include "Runner.h"
#include"Utility.h"

Runner::Runner():
    window(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(static_cast<int>(Utility::WINDOWSIZE.x),
            static_cast<int>(Utility::WINDOWSIZE.y)),
        "LineDrawingAlgo")),
    event() ,line(), circle(){
}

Runner::~Runner(){}

void Runner::Run(){
	Load();
    while (window->isOpen()){
        SFMLEVENT();
        Update();
        Draw();
    }
}

void Runner::Load(){
    pixels.Load();
}

void Runner::SFMLEVENT(){
    while (this->window->pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)
            window->close();
    }
}

void Runner::Update(){
    if (Utility::BSA_LINE_DRAW) {
        this->line.BsaWork(this->window);
    }
    else if (Utility::CircleDraw) {
        this->circle.RunAlgo(this->window);
    }
    else if (Utility::FloodFill) {
        this->floodfill.FloodFillStart(this->window);
    }
}


void Runner::Draw(){
    window->clear();
    pixels.Draw(window);
    window->display();
}
