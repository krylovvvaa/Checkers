#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

void menu(RenderWindow & window) {
	Game game;
	bool start = 1;
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, aboutTexture, menuBackground, titleTexture, ramkaTexture, optionsTexture, boardOptionsTexture, authorTexture;
	menuTexture1.loadFromFile("sources/menu/button1.png");
	menuTexture2.loadFromFile("sources/menu/button2.png");
	menuTexture3.loadFromFile("sources/menu/button3.png");
	menuTexture4.loadFromFile("sources/menu/button4.png");
	aboutTexture.loadFromFile("sources/menu/about.png");
	optionsTexture.loadFromFile("sources/menu/options.png");
	menuBackground.loadFromFile("sources/menu/background.png");
	titleTexture.loadFromFile("sources/menu/title.png");
	ramkaTexture.loadFromFile("sources/menu/shapka.png");
	authorTexture.loadFromFile("sources/board/author.png");
	boardOptionsTexture.loadFromFile("sources/board/options.png");


	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), about(aboutTexture), menuBg(menuBackground), title(titleTexture), ramka(ramkaTexture), options(optionsTexture), boardOptions(boardOptionsTexture), author(authorTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menuBg.setPosition(0, 0);
	menu1.setPosition(105, 200);
	menu2.setPosition(126, 260);
	menu3.setPosition(154, 380);
	menu4.setPosition(27, 300);
	title.setPosition(-186, -160);
	ramka.setPosition(-242, 50);
	about.setPosition(-252, -36);
	options.setPosition(-340, -25);
	boardOptions.setPosition(20, 510);
	author.setPosition(100, 510);


	while (isMenu)
	{
		Event event;
		menuNum = 0;

		if (IntRect(105, 200, 200, 70).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); menuNum = 1; }
		else { menu1.setColor(Color::White); }
		if (IntRect(126, 300, 220, 30).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); menuNum = 2; }
		else { menu2.setColor(Color::White); }
		if (IntRect(124, 345, 200, 45).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Yellow); menuNum = 3; }
		else { menu4.setColor(Color::White); }
		if (IntRect(154, 390, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); menuNum = 4; }
		else { menu3.setColor(Color::White); }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
					Event event;
					while (window.pollEvent(event)) {
						if (event.type == Event::Closed)
							window.close();
						game.make_move(window, event);
					}
					window.draw(menuBg);
					if (start) {
						game.start_game(window, event, start);
					}
					game.get_checkers_on_board().draw_checkers(window);//рисую поле и шашки
					game.end_game(window, event);
		
					if (IntRect(20, 510, 80, 50).contains(Mouse::getPosition(window))) { boardOptions.setColor(Color::Green); menuNum = 3; }
					else { boardOptions.setColor(Color::White); }

					if (Mouse::isButtonPressed(Mouse::Left)) {
						if (menuNum == 3) { window.clear(); window.draw(menuBg); window.draw(options); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
					}

					if (IntRect(100, 510, 200, 50).contains(Mouse::getPosition(window))) { author.setColor(Color::Green); menuNum = 2; }
					else { author.setColor(Color::White); }

					if (Mouse::isButtonPressed(Mouse::Left)) {
						if (menuNum == 2) { window.clear(); window.draw(menuBg); window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape));}
					}

					window.draw(boardOptions);
					window.draw(author);
					window.display();
				}
			}

			if (menuNum == 2) { window.clear(); window.draw(menuBg); window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.clear(); window.draw(menuBg); window.draw(options); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 4) { window.close(); isMenu = false; }
			

		}
		
		window.draw(menuBg);
		window.draw(title);
		window.draw(ramka);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}
int main() {
	RenderWindow window(sf::VideoMode(482, 600), "Checkers");
	menu(window);//вызов меню
	return 0;
}