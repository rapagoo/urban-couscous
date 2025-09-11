#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Window");
	window.setVerticalSyncEnabled(true); // ȭ������ ����(����)

	sf::Texture texture("assets/image.png");
	sf::Sprite sprite(texture);

	const float speed = 200.f; // px/s
	sf::Clock clock;           // ��Ÿ Ÿ�� ������

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		const float dt = clock.restart().asSeconds();
		sprite.move(sf::Vector2f(speed * dt, 0.f)); // �� ������ �̵�

		window.clear();
		window.draw(sprite);
		window.display();
	}
}