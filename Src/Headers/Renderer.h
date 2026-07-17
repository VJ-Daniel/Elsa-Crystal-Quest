#ifndef RENDERER_H
#define RENDERER_H

#include <glew.h>

#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Mesh.h"

#include "Camera.h"
#include "World.h"
#include "Tree.h"
#include "Door.h"
#include "TreasureChest.h"
#include "DragonHead.h"
#include "ArmorStand.h"
#include "Torch.h"

class Renderer
{
private:

    //--------------------------------------------------
    // Shader
    //--------------------------------------------------

    Shader* shader;

    //--------------------------------------------------
    // Uniforms
    //--------------------------------------------------

    int mvpLocation;

    //--------------------------------------------------
    // Matrices
    //--------------------------------------------------

    glm::mat4 projection;

    //--------------------------------------------------
    // World Meshes
    //--------------------------------------------------

    Mesh* groundMesh;

    //--------------------------------------------------
    // Tree Meshes
    //--------------------------------------------------

    Mesh* trunkMesh;

    Mesh* leavesMesh;

    //--------------------------------------------------
    // Door Mesh
    //--------------------------------------------------

    Mesh* doorMesh;

    //--------------------------------------------------
    // Treasure Chest
    //--------------------------------------------------

    Mesh* treasureChestMesh;

    Mesh* treasureChestInteriorMesh;

    //--------------------------------------------------
    // Castle Meshes
    //--------------------------------------------------

    Mesh* castleWallMesh;

    Mesh* castleTowerMesh;

    Mesh* castleRoofMesh;

    //--------------------------------------------------
	// Dragon Head Mesh
    //--------------------------------------------------

    Mesh* dragonHeadMesh;

    //--------------------------------------------------
	// Armor Stand Mesh
    //--------------------------------------------------

	Mesh* armorStandMesh;

    //--------------------------------------------------
    // Torch Meshes
    //--------------------------------------------------

    Mesh* torchWoodMesh;

    Mesh* torchMetalMesh;

    Mesh* torchOuterFlameMesh;

    Mesh* torchInnerFlameMesh;

private:

    //--------------------------------------------------
    // Internal Draw
    //--------------------------------------------------

    void DrawMesh(
        Mesh* mesh,
        const glm::mat4& model,
        const glm::mat4& view);

    //--------------------------------------------------
    // Cube Helper
    //--------------------------------------------------

    void DrawCubePart(
        Mesh* mesh,
        const glm::vec3& offset,
        const glm::vec3& size,
        const glm::mat4& parent,
        const glm::mat4& view);


    //--------------------------------------------------
    // Terrain
    //--------------------------------------------------

    void DrawGround(
        const glm::mat4& view);

    //--------------------------------------------------
    // Environment
    //--------------------------------------------------

    void DrawTree(
        const Tree& tree,
        const glm::mat4& view);

    void DrawDoor(
        const Door& door,
        const glm::mat4& view);

    void DrawTreasureChest(
        const TreasureChest& chest,
        const glm::mat4& view);

    void DrawCastle(
        const World& world,
        const glm::mat4& view);

    void DrawDragonHead(
        const DragonHead& dragonHead,
        const glm::mat4& view);

    void DrawArmorStand(
        const ArmorStand& armorStand,
        const glm::mat4& view);

    void DrawTorch(
        const Torch& torch,
        const glm::mat4& view);

public:

    //--------------------------------------------------
    // Constructor
    //--------------------------------------------------

    Renderer();

    //--------------------------------------------------
    // Initialization
    //--------------------------------------------------

    bool Initialize(
        int screenWidth,
        int screenHeight);

    //--------------------------------------------------
    // Shader
    //--------------------------------------------------

    void SetShader(
        Shader* shaderProgram);

    //--------------------------------------------------
    // Frame
    //--------------------------------------------------

    void BeginFrame();

    void EndFrame();

    //--------------------------------------------------
    // Render Pass
    //--------------------------------------------------

    void RenderWorld(
        const World& world,
        const Camera& camera);

    //--------------------------------------------------
    // Cleanup
    //--------------------------------------------------

    void Shutdown();

    //--------------------------------------------------
    // Destructor
    //--------------------------------------------------

    ~Renderer();
};

#endif