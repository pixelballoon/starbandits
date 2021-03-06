#pragma once

#include "pixelboost/logic/entity.h"

namespace pb
{
    class Message;
    class PrimitiveRenderableLine;
    class Scene;
}

class PlayerInput;

class Grapple : public pb::Entity
{
    PB_DECLARE_ENTITY
    
public:
    Grapple(pb::Scene* scene, pb::Entity* entity, pb::DbEntity* creationEntity);
    ~Grapple();
    
    void Initialise(pb::Uid playerId, PlayerInput* input, pb::Uid collisionId);
    
public:
    void OnCollision(const pb::Message& message);
    void OnUpdate(const pb::Message& message);
    
private:
    void UpdateData();
    float GetDistance();
    
    enum GrappleState
    {
        kStateFiring,
        kStateAttached,
    };
    
    pb::Uid _PlayerId;
    pb::Uid _CollisionId;
    
    PlayerInput* _Input;
    
    glm::vec3 _ObjectPosition;
    glm::vec3 _PlayerPosition;
    float _StartDistance;
    
    pb::PrimitiveRenderableLine* _Renderable;
};
