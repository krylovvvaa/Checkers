#include <SFML/Graphics.hpp>
using namespace sf;

class Checker {
private:
	CircleShape checker = CircleShape(16);
	bool checker_color;// 0 для белых, 1 для черных
	bool select = 0;//1 если выбрана, 0 если нет
	bool queen = 0;//1 если шашка дамка, 0 если нет
	Texture texture;//текстура значка дамки
	Sprite sprite;//спрайт значка дамки
public:
	CircleShape &get_checker() {
		return this->checker;
	}
	Vector2f get_position() {
		return this->checker.getPosition();
	}
	float get_x() {
		return (this->get_position().x - 52) / 50;
	}
	float get_y() {
		return (this->get_position().y - 88) / 50;
	}
	bool get_color() {
		return this->checker_color;
	}
	bool get_select() {
		return this->select;
	}
	bool get_queen() {
		return this->queen;
	}

	void make_queen() { //дамка
		this->queen = 1;
	}
	void set_position(float _x_position, float _y_position) {
		this->checker.setPosition(_x_position, _y_position);
	}
	void set_color(Color _color) {
		this->checker.setFillColor(_color);
	}
	void select_checker() {//выбор фигуры
		this->select = 1;
	}
	void leave_checker() {//отмена выбора фигуры
		this->select = 0;
	}

	Checker(float _x_position, float _y_position, bool _color) {
		this->checker.setOutlineThickness(5);
		this->checker_color = _color;
		if (_color == 0) {
			this->checker.setOutlineColor(Color(255, 255, 255));
			this->set_color(Color(218, 218, 218));
		}
		else if (_color == 1) {
			this->checker.setOutlineColor(sf::Color(0, 0, 0));
			this->set_color(Color(35, 35, 35));
		}
		this->set_position(_x_position, _y_position);
		this->select = 0;
	}

	void draw_checker(RenderWindow  &_window) {
		_window.draw(this->checker);
		if (queen == 1) {
			this->texture.loadFromFile("sources/board/queen.png");
			this->sprite.setTexture(texture);
			this->sprite.setPosition(this->get_position().x + 4, this->get_position().y + 4);
		}
		_window.draw(this->sprite);
	}

	Checker operator = (Checker _checker) {
		this->texture = _checker.texture;
		this->sprite = _checker.sprite;
		this->select = _checker.select;
		this->queen = _checker.queen;
		this->checker_color = _checker.checker_color;
		if (_checker.checker_color == 0) {
			this->checker.setOutlineColor(sf::Color(255, 255, 255));
			this->set_color(Color(218, 218, 218));
		}
		else if (_checker.checker_color == 1) {
			this->checker.setOutlineColor(sf::Color(0, 0, 0));
			this->set_color(Color(35, 35, 35));
		}
		this->set_position(_checker.get_position().x, _checker.get_position().y);
		return (*this);
	}
};