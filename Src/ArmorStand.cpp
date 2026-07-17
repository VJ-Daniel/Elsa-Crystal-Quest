#include "Headers/ArmorStand.h"

//--------------------------------------------------
// Constructor
//--------------------------------------------------

ArmorStand::ArmorStand()
{
    position =
    {
        0.0f,
        0.0f,
        0.0f
    };

    rotation =
    {
        0.0f,
        0.0f,
        0.0f
    };

    scale =
    {
        1.0f,
        1.0f,
        1.0f
    };

    width =
        2.0f;

    height =
        5.5f;

    depth =
        1.5f;
}

//--------------------------------------------------
// Position
//--------------------------------------------------

void ArmorStand::SetPosition(
    const glm::vec3& newPosition)
{
    position =
        newPosition;
}

glm::vec3 ArmorStand::GetPosition() const
{
    return position;
}

//--------------------------------------------------
// Rotation
//--------------------------------------------------

void ArmorStand::SetRotation(
    const glm::vec3& newRotation)
{
    rotation =
        newRotation;
}

glm::vec3 ArmorStand::GetRotation() const
{
    return rotation;
}

//--------------------------------------------------
// Scale
//--------------------------------------------------

void ArmorStand::SetScale(
    const glm::vec3& newScale)
{
    scale =
        newScale;
}

glm::vec3 ArmorStand::GetScale() const
{
    return scale;
}

//--------------------------------------------------
// Size
//--------------------------------------------------

void ArmorStand::SetSize(
    float newWidth,
    float newHeight,
    float newDepth)
{
    width =
        newWidth;

    height =
        newHeight;

    depth =
        newDepth;
}

float ArmorStand::GetWidth() const
{
    return
        width *
        scale.x;
}

float ArmorStand::GetHeight() const
{
    return
        height *
        scale.y;
}

float ArmorStand::GetDepth() const
{
    return
        depth *
        scale.z;
}

//--------------------------------------------------
// Bounds
//--------------------------------------------------

glm::vec3 ArmorStand::GetMinBounds() const
{
    return
    {
        position.x -
        GetWidth() * 0.5f,

        position.y,

        position.z -
        GetDepth() * 0.5f
    };
}

glm::vec3 ArmorStand::GetMaxBounds() const
{
    return
    {
        position.x +
        GetWidth() * 0.5f,

        position.y +
        GetHeight(),

        position.z +
        GetDepth() * 0.5f
    };
}

//--------------------------------------------------
// Collision
//--------------------------------------------------

bool ArmorStand::CheckCollision(
    const glm::vec3& playerPosition,
    float playerRadius) const
{
    glm::vec3 minBounds =
        GetMinBounds();

    glm::vec3 maxBounds =
        GetMaxBounds();

    float closestX =
        glm::clamp(
            playerPosition.x,
            minBounds.x,
            maxBounds.x);

    float closestY =
        glm::clamp(
            playerPosition.y,
            minBounds.y,
            maxBounds.y);

    float closestZ =
        glm::clamp(
            playerPosition.z,
            minBounds.z,
            maxBounds.z);

    float dx =
        playerPosition.x -
        closestX;

    float dy =
        playerPosition.y -
        closestY;

    float dz =
        playerPosition.z -
        closestZ;

    float distanceSquared =
        dx * dx +
        dy * dy +
        dz * dz;

    return
        distanceSquared <
        playerRadius *
        playerRadius;
}

//--------------------------------------------------
// Destructor
//--------------------------------------------------

ArmorStand::~ArmorStand()
{}