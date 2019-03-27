#pragma once
#include <set>
#include "../Core/Vector2D.h"
#include "../Core/Component.h"
#include <Box2D/Box2D.h>
#include "PhysObjectType.h"
#include "../Event/Subject.h"
#include "PhysicsManager.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(PhysObjectType::PhysObjectType t, float z, float r, float w, float h);
	~PhysicsComponent();
	void initPosition();
	void moveBody(Vector2D* pos, float angle);
	std::vector<PhysicsComponent*> areaCheck(std::set<PhysObjectType::PhysObjectType> toCheck, Vector2D* p1, Vector2D* p2);
	PhysicsComponent* rayCheck(std::set<PhysObjectType::PhysObjectType> toCheck, Vector2D* p1, Vector2D* p2, Vector2D& hit);
	bool updateFalling();

	Vector2D velocity;
	float zPos, rotation, width, height;
	bool isJumping, isFalling, isUp;
	b2Body* body;
	PhysObjectType::PhysObjectType type;
	Subject<PhysicsComponent*> onCollide; //for collision between bodies
	Subject<PhysicsComponent*> onHit; //for hitbox checking
	Subject<PhysicsComponent*> onBounce; //for hitbox checking
private:
	
};