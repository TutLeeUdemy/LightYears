#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow renderWindow{sf::VideoMode(100,100), "MyWindow"};

	std::cout << "hello world!" << std::endl;
}