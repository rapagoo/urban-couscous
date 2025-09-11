#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Window");
	window.setVerticalSyncEnabled(true); // 화면찢김 방지

	sf::Texture texture("assets/image.png");
	sf::Sprite sprite(texture);
	sprite.scale({ 0.5f, 0.5f });

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

		// 실시간 입력으로 방향 벡터 계산 (WASD + 방향키)
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

		// 대각선 속도 보정(정규화)
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