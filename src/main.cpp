#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Window");
	window.setVerticalSyncEnabled(true); // 화면찢김 방지(선택)

	sf::Texture texture("assets/image.png");
	sf::Sprite sprite(texture);

	const float speed = 200.f; // px/s
	sf::Clock clock;           // 델타 타임 측정용

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		const float dt = clock.restart().asSeconds();
		sprite.move(sf::Vector2f(speed * dt, 0.f)); // 매 프레임 이동

		window.clear();
		window.draw(sprite);
		window.display();
	}
}