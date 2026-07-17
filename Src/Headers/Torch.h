#pragma once

#include <glm.hpp>

class Torch
{
public:
    Torch();

    void Update(float deltaTime);
    void Toggle();

    void SetPosition(const glm::vec3& newPosition);

    glm::vec3 GetPosition() const;

    bool IsLit() const;

    float GetFlameScale() const;
    float GetFlameOffset() const;
    float GetLightIntensity() const;

private:
    glm::vec3 position;

    bool isLit;

    float animationTime;
    float flameScale;
    float flameOffset;
    float lightIntensity;
};