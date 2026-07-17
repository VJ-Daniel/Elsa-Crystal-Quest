#include "Torch.h"

#include <cmath>

Torch::Torch()
{
    position = glm::vec3(0.0f);

    isLit = false;

    animationTime = 0.0f;
    flameScale = 1.0f;
    flameOffset = 0.0f;
    lightIntensity = 1.0f;
}

void Torch::Update(float deltaTime)
{
    if (!isLit)
    {
        return;
    }

    animationTime += deltaTime;

    flameScale =
        1.0f +
        std::sin(animationTime * 8.0f) * 0.12f;

    flameOffset =
        std::sin(animationTime * 12.0f) * 0.03f;

    lightIntensity =
        1.0f +
        std::sin(animationTime * 10.0f) * 0.15f;
}

void Torch::Toggle()
{
    isLit = !isLit;

    if (!isLit)
    {
        animationTime = 0.0f;
        flameScale = 1.0f;
        flameOffset = 0.0f;
        lightIntensity = 1.0f;
    }
}

void Torch::SetPosition(
    const glm::vec3& newPosition)
{
    position = newPosition;
}

glm::vec3 Torch::GetPosition() const
{
    return position;
}

bool Torch::IsLit() const
{
    return isLit;
}

float Torch::GetFlameScale() const
{
    return flameScale;
}

float Torch::GetFlameOffset() const
{
    return flameOffset;
}

float Torch::GetLightIntensity() const
{
    return lightIntensity;
}