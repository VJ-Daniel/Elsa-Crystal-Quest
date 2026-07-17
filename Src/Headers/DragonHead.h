#ifndef DRAGON_HEAD_H
#define DRAGON_HEAD_H

#include <glm.hpp>

class DragonHead
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

    //--------------------------------------------------
    // Interaction
    //--------------------------------------------------

    bool opened;

    float interactionDistance = 8.0f;

    //--------------------------------------------------
    // Animation
    //--------------------------------------------------

    float currentJawAngle;

    float targetJawAngle;

    float animationSpeed;

public:

    //--------------------------------------------------
    // Constructor
    //--------------------------------------------------

    DragonHead();

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
    // State
    //--------------------------------------------------

    void Open();

    void Close();

    void Toggle();

    bool IsOpened() const;

    //--------------------------------------------------
    // Animation
    //--------------------------------------------------

    void Update(
        float deltaTime);

    float GetCurrentJawAngle() const;

    //--------------------------------------------------
    // Interaction
    //--------------------------------------------------

    void SetInteractionDistance(
        float distance);

    float GetInteractionDistance() const;

    bool CanInteract(
        const glm::vec3& playerPosition) const;

    //--------------------------------------------------
    // Destructor
    //--------------------------------------------------

    ~DragonHead();
};

#endif