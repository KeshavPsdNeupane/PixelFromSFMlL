#pragma once
#include<SFML/Graphics.hpp>
#include<memory>
#include"PixelDraw.h"
#include"BSALineDraw.h"
#include"CircleDrawing.h"
#include"FloodFillAlgo.h"

class Runner{
	std::shared_ptr<sf::RenderWindow> window;
	sf::Event event;
	BSALineDraw line;
	CircleDrawing circle;
	FloodFillAlgo floodfill;
public:
	Runner();
	~Runner();
public:
	void Run();
private:
	void Load();
	void SFMLEVENT();
	void Update();
	void Draw();

};

