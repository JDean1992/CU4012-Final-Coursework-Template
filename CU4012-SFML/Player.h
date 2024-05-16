#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Player :
    public GameObject
{
    int speed;
    Animation walk;
    Animation* currentAnimation;
    sf::Texture MoleSpriteSheet;

public:
    Player();

    void handleInput(float dt) override;

        
};

