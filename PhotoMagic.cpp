/*
Name: Matthew Svenson
Course Name: Computing IV
Assignment Name: PS1b
Instructors Name: James Daly
Due Date: 2/7/2022

Program Description:
Using LFSR to create an encrypted image
*/

#include "FibLFSR.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


//First word = argv[1]
//Second word = argv[2]
//Third word = argv[3]
void transform( sf::Image& image, FibLFSR* f1);
int main(int argc, char* argv[])
{
sf::Image image;
	if (!image.loadFromFile(argv[1]))
		return -1;

	sf::Image image2;
	if (!image2.loadFromFile(argv[1]))
		return -1;


	FibLFSR f1(argv[3]);
	FibLFSR* f = &f1;
	transform(image2, f);


	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");

	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Texture texture2;
	texture2.loadFromImage(image2);
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	while (window1.isOpen() && window2.isOpen()) {
	sf::Event event;
     	while (window1.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
         window1.close();
     	}
     	while (window2.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
         window2.close();
     }
     window1.clear();
     window1.draw(sprite);
     window1.display();
     window2.clear();
     window2.draw(sprite2);
     window2.display();   }

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!image2.saveToFile(argv[2]))
		return -1;

	return 0;
}

void transform( sf::Image& image, FibLFSR* f1)
{
//This function generates the FibLFSR 8 times and XOR's the result
//with the integer of the pixel's red, green, and blue values

	// p is a pixel
	sf::Color p;

	sf::Vector2u size = image.getSize();
	// create photographic negative image of upper-left 200 px square
	for (int x = 0; x<size.x; x++) {
		for (int y = 0; y< size.y; y++) {
			p = image.getPixel(x, y);
			p.r = p.r^f1->generate(8);
			p.g = p.g^f1->generate(8);
			p.b = p.b^f1->generate(8);
			image.setPixel(x, y, p);
		}
	}
}
