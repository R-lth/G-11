#pragma once

class Actor
{
public:
	Actor();
	~Actor();

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();
};