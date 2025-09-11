#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Window");
	window.setVerticalSyncEnabled(true); // ȭ������ ����

	sf::Texture texture("assets/image.png");
	sf::Sprite sprite(texture);
	sprite.scale({ 0.5f, 0.5f });

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

		// �ǽð� �Է����� ���� ���� ��� (WASD + ����Ű)
		sf::Vector2f dir{ 0.f, 0.f };
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
			dir.x -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right))
			dir.x += 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
			dir.y -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
			dir.y += 1.f;

		// �밢�� �ӵ� ����(����ȭ)
		if (dir.x != 0.f || dir.y != 0.f)
		{
			const float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
			dir.x /= len;
			dir.y /= len;
			sprite.move(sf::Vector2f(dir.x * speed * dt, dir.y * speed * dt));
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}