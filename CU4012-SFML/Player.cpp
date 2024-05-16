#include "Player.h"

Player::Player()
{
	speed = 200;
	MoleSpriteSheet.loadFromFile("gfx/MinermoleSprite.png");
	setSize(sf::Vector2f(15 * 4, 21 * 3));
	setPosition(100, 100);
	setTexture(&MoleSpriteSheet);


	walk.addFrame(sf::IntRect(405, 68, 40, 35));
	walk.addFrame(sf::IntRect(5, 120, 40, 35));
	walk.addFrame(sf::IntRect(55, 116, 40, 40));
	walk.addFrame(sf::IntRect(104, 114, 40, 40));
	walk.addFrame(sf::IntRect(155, 116, 40, 40));
	walk.addFrame(sf::IntRect(204, 118, 40, 35));
	walk.addFrame(sf::IntRect(255, 120, 40, 35));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;

	
		
}

void Player::handleInput(float dt)
{
	velocity.x = 0.f;

	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(true);
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(true);
	}

	
}


