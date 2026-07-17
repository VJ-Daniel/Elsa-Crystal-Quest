#include "Headers/DragonHead.h"

DragonHead::DragonHead()
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
        2.5f;

    height =
        2.0f;

    depth =
        2.0f;

    //--------------------------------------------------
    // Interaction
    //--------------------------------------------------

    opened =
        false;

    interactionDistance =
        8.0f;

    //--------------------------------------------------
    // Jaw Animation
    //--------------------------------------------------

    currentJawAngle =
        0.0f;

    targetJawAngle =
        0.0f;

    animationSpeed =
        20.0f;
}

//--------------------------------------------------
// Position
//--------------------------------------------------

void DragonHead::SetPosition(
    const glm::vec3& newPosition)
{
    position =
        newPosition;
}

glm::vec3 DragonHead::GetPosition() const
{
    return position;
}

//--------------------------------------------------
// Rotation
//--------------------------------------------------

void DragonHead::SetRotation(
    const glm::vec3& newRotation)
{
    rotation =
        newRotation;
}

glm::vec3 DragonHead::GetRotation() const
{
    return rotation;
}

//--------------------------------------------------
// Scale
//--------------------------------------------------

void DragonHead::SetScale(
    const glm::vec3& newScale)
{
    scale =
        newScale;
}

glm::vec3 DragonHead::GetScale() const
{
    return scale;
}

//--------------------------------------------------
// Size
//--------------------------------------------------

void DragonHead::SetSize(
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

float DragonHead::GetWidth() const
{
    return
        width *
        scale.x;
}

float DragonHead::GetHeight() const
{
    return
        height *
        scale.y;
}

float DragonHead::GetDepth() const
{
    return
        depth *
        scale.z;
}

//--------------------------------------------------
// State
//--------------------------------------------------

void DragonHead::Open()
{
    opened =
        true;

    targetJawAngle =
        35.0f;
}

void DragonHead::Close()
{
    opened =
        false;

    targetJawAngle =
        0.0f;
}

void DragonHead::Toggle()
{
    if (opened)
    {
        Close();
    }
    else
    {
        Open();
    }
}

bool DragonHead::IsOpened() const
{
    return opened;
}

//--------------------------------------------------
// Animation
//--------------------------------------------------

void DragonHead::Update(
    float deltaTime)
{
    float step =
        animationSpeed *
        deltaTime;

    if (
        currentJawAngle <
        targetJawAngle)
    {
        currentJawAngle +=
            step;

        if (
            currentJawAngle >
            targetJawAngle)
        {
            currentJawAngle =
                targetJawAngle;
        }
    }

    if (
        currentJawAngle >
        targetJawAngle)
    {
        currentJawAngle -=
            step;

        if (
            currentJawAngle <
            targetJawAngle)
        {
            currentJawAngle =
                targetJawAngle;
        }
    }
}

float DragonHead::GetCurrentJawAngle() const
{
    return currentJawAngle;
}

//--------------------------------------------------
// Interaction
//--------------------------------------------------

void DragonHead::SetInteractionDistance(
    float distance)
{
    interactionDistance =
        distance;
}

float DragonHead::GetInteractionDistance() const
{
    return interactionDistance;
}

bool DragonHead::CanInteract(
    const glm::vec3& playerPosition) const
{
    float distance =
        glm::distance(
            playerPosition,
            position);

    return distance <= interactionDistance;
}

//--------------------------------------------------
// Destructor
//--------------------------------------------------

DragonHead::~DragonHead()
{}