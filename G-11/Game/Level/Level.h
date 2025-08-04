#pragma once

class Level 
{
public:
	Level();
	virtual ~Level();

	virtual void BeginPlay();
	virtual void Tick(float deltaTime);
	virtual void Render();

	// TODO. AddActor
	//void AddActor(Actor* newActor);

public:
	// std::vector<Actor*> arr;
};