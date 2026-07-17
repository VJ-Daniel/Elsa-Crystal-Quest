#ifndef ARMOR_STAND_H
#define ARMOR_STAND_H

#include <glm.hpp>

class ArmorStand
{
private:

    //--------------------------------------------------
    // Transform
    //--------------------------------------------------

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    //--------------------------------------------------
    // Size
    //--------------------------------------------------

    float width;
    float height;
    float depth;

public:

    //--------------------------------------------------
    // Constructor
    //--------------------------------------------------

    ArmorStand();

    //--------------------------------------------------
    // Position
    //--------------------------------------------------

    void SetPosition(
        const glm::vec3& newPosition);

    glm::vec3 GetPosition() const;

    //--------------------------------------------------
    // Rotation
    //--------------------------------------------------

    void SetRotation(
        const glm::vec3& newRotation);

    glm::vec3 GetRotation() const;

    //--------------------------------------------------
    // Scale
    //--------------------------------------------------

    void SetScale(
        const glm::vec3& newScale);

    glm::vec3 GetScale() const;

    //--------------------------------------------------
    // Size
    //--------------------------------------------------

    void SetSize(
        float newWidth,
        float newHeight,
        float newDepth);

    float GetWidth() const;
    float GetHeight() const;
    float GetDepth() const;

    //--------------------------------------------------
    // Bounds
    //--------------------------------------------------

    glm::vec3 GetMinBounds() const;

    glm::vec3 GetMaxBounds() const;

    //--------------------------------------------------
    // Collision
    //--------------------------------------------------

    bool CheckCollision(
        const glm::vec3& playerPosition,
        float playerRadius) const;

    //--------------------------------------------------
    // Destructor
    //--------------------------------------------------

    ~ArmorStand();
};

#endif