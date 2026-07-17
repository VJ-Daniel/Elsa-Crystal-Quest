#include "World.h"

#include <cstdlib>
#include <ctime>

#include <glm.hpp>

World::World()
{
    //--------------------------------------------------
    // Terrain
    //--------------------------------------------------

    terrainSize =
        500.0f;

    //--------------------------------------------------
    // Castle
    //--------------------------------------------------

    castlePosition =
    {
        80.0f,
        0.0f,
        80.0f
    };

    //--------------------------------------------------
    // Player Collision
    //--------------------------------------------------

    playerRadius =
        0.4f;

    //--------------------------------------------------
    // Random Seed
    //--------------------------------------------------

    std::srand(
        static_cast<unsigned int>(
            std::time(nullptr)));
}

//--------------------------------------------------
// Generation
//--------------------------------------------------

void World::Generate()
{
    Clear();

    GenerateTrees();

    GenerateCastle();

    GenerateTreasureChests();

    GenerateDragonHeads();

    GenerateArmorStands();

    GenerateTorches();
}

void World::Clear()
{
    trees.clear();

    treasureChests.clear();

    dragonHeads.clear();

    armorStands.clear();

    torches.clear();
}

//--------------------------------------------------
// Terrain
//--------------------------------------------------

void World::SetTerrainSize(
    float size)
{
    terrainSize =
        size;
}

float World::GetTerrainSize() const
{
    return terrainSize;
}

//--------------------------------------------------
// Terrain Height
//--------------------------------------------------

float World::GetHeightAt(
    float x,
    float z) const
{
    (void)x;
    (void)z;

    return 0.0f;
}

//--------------------------------------------------
// Trees
//--------------------------------------------------

std::vector<Tree>&
World::GetTrees()
{
    return trees;
}

const std::vector<Tree>&
World::GetTrees() const
{
    return trees;
}

//--------------------------------------------------
// Castle
//--------------------------------------------------

glm::vec3 World::GetCastlePosition() const
{
    return castlePosition;
}

//--------------------------------------------------
// Door
//--------------------------------------------------

Door& World::GetDoor()
{
    return door;
}

const Door& World::GetDoor() const
{
    return door;
}

//--------------------------------------------------
// Treasure Chests
//--------------------------------------------------

std::vector<TreasureChest>&
World::GetTreasureChests()
{
    return treasureChests;
}

const std::vector<TreasureChest>&
World::GetTreasureChests() const
{
    return treasureChests;
}

//--------------------------------------------------
// Torches
//--------------------------------------------------

std::vector<Torch>& World::GetTorches()
{
    return torches;
}

const std::vector<Torch>& World::GetTorches() const
{
    return torches;
}

Torch* World::GetInteractableTorch(
    const glm::vec3& playerPosition)
{
    const float interactionDistance = 3.0f;

    for (Torch& torch : torches)
    {
        float distance =
            glm::distance(
                playerPosition,
                torch.GetPosition());

        if (distance <= interactionDistance)
        {
            return &torch;
        }
    }

    return nullptr;
}

void World::GenerateTorches()
{
    Torch torch;

    torch.SetPosition(
        {
            castlePosition.x + 2.8f,
            2.5f,
            castlePosition.z - 7.3f
        });

    torches.push_back(torch);
}

//--------------------------------------------------
// Dragon Heads
//--------------------------------------------------

std::vector<DragonHead>&
World::GetDragonHeads()
{
    return dragonHeads;
}

const std::vector<DragonHead>&
World::GetDragonHeads() const
{
    return dragonHeads;
}

void World::GenerateDragonHeads()
{
    DragonHead dragonHead;

    dragonHead.SetPosition(
        {
            castlePosition.x,
            4.5f,
            castlePosition.z + 5.4f
        });

    dragonHead.SetRotation(
        {
            0.0f,
            180.0f,
            0.0f
        });

    dragonHead.SetScale(
        {
            0.8f,
            0.8f,
            0.8f
        });

    dragonHeads.push_back(
        dragonHead);
}

void World::UpdateDragonHeads(
    float deltaTime)
{
    for (DragonHead& dragonHead :
        dragonHeads)
    {
        dragonHead.Update(
            deltaTime);
    }
}

//--------------------------------------------------
// Armor Stands
//--------------------------------------------------

std::vector<ArmorStand>&
World::GetArmorStands()
{
    return armorStands;
}

const std::vector<ArmorStand>&
World::GetArmorStands() const
{
    return armorStands;
}

void World::GenerateArmorStands()
{
    ArmorStand leftArmor;

    leftArmor.SetPosition(
        {
            castlePosition.x - 4.5f,
            0.0f,
            castlePosition.z - 3.5f
        });

    leftArmor.SetRotation(
        {
            0.0f,
            0.0f,
            0.0f
        });

    leftArmor.SetScale(
        {
            0.8f,
            0.8f,
            0.8f
        });

    armorStands.push_back(
        leftArmor);

    ArmorStand rightArmor;

    rightArmor.SetPosition(
        {
            castlePosition.x + 4.5f,
            0.0f,
            castlePosition.z - 3.5f
        });

    rightArmor.SetRotation(
        {
            0.0f,
            0.0f,
            0.0f
        });

    rightArmor.SetScale(
        {
            0.8f,
            0.8f,
            0.8f
        });

    armorStands.push_back(
        rightArmor);
}

//--------------------------------------------------
// Player Collision
//--------------------------------------------------

void World::SetPlayerRadius(
    float radius)
{
    playerRadius =
        radius;
}

float World::GetPlayerRadius() const
{
    return playerRadius;
}
//--------------------------------------------------
// Tree Collision
//--------------------------------------------------

bool World::CheckTreeCollision(
    const glm::vec3& position) const
{
    for (const Tree& tree : trees)
    {
        if (
            tree.CheckCollision(
                position,
                playerRadius))
        {
            return true;
        }
    }

    return false;
}

//--------------------------------------------------
// Door Collision
//--------------------------------------------------

bool World::CheckDoorCollision(
    const glm::vec3& position) const
{
    return
        door.CheckCollision(
            position,
            playerRadius);
}

//--------------------------------------------------
// Treasure Chest Collision
//--------------------------------------------------

bool World::CheckTreasureChestCollision(
    const glm::vec3& position) const
{
    for (const TreasureChest& chest :
        treasureChests)
    {
        if (
            chest.CheckCollision(
                position,
                playerRadius))
        {
            return true;
        }
    }

    return false;
}

//--------------------------------------------------
// Armor Stand Collision
//--------------------------------------------------

bool World::CheckArmorStandCollision(
    const glm::vec3& position) const
{
    for (
        const ArmorStand& armorStand :
        armorStands)
    {
        if (
            armorStand.CheckCollision(
                position,
                playerRadius))
        {
            return true;
        }
    }

    return false;
}

//--------------------------------------------------
// Castle Interior
//--------------------------------------------------

bool World::IsInsideCastle(
    const glm::vec3& position) const
{
    float minX =
        castlePosition.x - 7.0f;

    float maxX =
        castlePosition.x + 7.0f;

    float minZ =
        castlePosition.z - 5.0f;

    float maxZ =
        castlePosition.z + 5.0f;

    return
        position.x > minX &&
        position.x < maxX &&
        position.z > minZ &&
        position.z < maxZ;
}

//--------------------------------------------------
// Castle Collision
//--------------------------------------------------

bool World::CheckCastleCollision(
    const glm::vec3& position) const
{
    const float halfWidth =
        8.0f;

    const float halfDepth =
        6.0f;

    const float wallThickness =
        0.5f;

    //--------------------------------------------------
    // Front Wall
    //--------------------------------------------------

    bool insideFrontWall =
        position.x >
        castlePosition.x - halfWidth

        &&

        position.x <
        castlePosition.x + halfWidth

        &&

        position.z >
        castlePosition.z -
        halfDepth -
        wallThickness

        &&

        position.z <
        castlePosition.z -
        halfDepth +
        wallThickness;

    //--------------------------------------------------
    // Door Opening
    //--------------------------------------------------

    bool insideDoorGap =
        position.x >
        castlePosition.x - 1.8f

        &&

        position.x <
        castlePosition.x + 1.8f;
    //--------------------------------------------------
    // Door Closed
    //--------------------------------------------------

    if (
        door.GetCurrentAngle()
        <
        70.0f)
    {
        if (
            insideFrontWall)
        {
            return true;
        }
    }
    else
    {
        if (
            insideFrontWall
            &&
            !insideDoorGap)
        {
            return true;
        }
    }

    //--------------------------------------------------
    // Back Wall
    //--------------------------------------------------

    bool insideBackWall =
        position.x >
        castlePosition.x - halfWidth

        &&

        position.x <
        castlePosition.x + halfWidth

        &&

        position.z >
        castlePosition.z +
        halfDepth -
        wallThickness

        &&

        position.z <
        castlePosition.z +
        halfDepth +
        wallThickness;

    if (insideBackWall)
    {
        return true;
    }

    //--------------------------------------------------
    // Left Wall
    //--------------------------------------------------

    bool insideLeftWall =
        position.z >
        castlePosition.z - halfDepth

        &&

        position.z <
        castlePosition.z + halfDepth

        &&

        position.x >
        castlePosition.x -
        halfWidth -
        wallThickness

        &&

        position.x <
        castlePosition.x -
        halfWidth +
        wallThickness;

    if (insideLeftWall)
    {
        return true;
    }

    //--------------------------------------------------
    // Right Wall
    //--------------------------------------------------

    bool insideRightWall =
        position.z >
        castlePosition.z - halfDepth

        &&

        position.z <
        castlePosition.z + halfDepth

        &&

        position.x >
        castlePosition.x +
        halfWidth -
        wallThickness

        &&

        position.x <
        castlePosition.x +
        halfWidth +
        wallThickness;

    if (insideRightWall)
    {
        return true;
    }

    return false;
}

//--------------------------------------------------
// Collision
//--------------------------------------------------

bool World::CheckCollision(
    const glm::vec3& position) const
{
    if (
        CheckTreeCollision(
            position))
    {
        return true;
    }

    if (
        CheckDoorCollision(
            position))
    {
        return true;
    }

    if (
        CheckTreasureChestCollision(
            position))
    {
        return true;
    }

    if (
        CheckArmorStandCollision(
            position))
    {
        return true;
    }

    if (
        CheckCastleCollision(
            position))
    {
        return true;
    }

    return false;
}

//--------------------------------------------------
// Ground
//--------------------------------------------------

bool World::IsBelowGround(
    const glm::vec3& position,
    float playerHeight) const
{
    return
        position.y
        <=
        playerHeight;
}

//--------------------------------------------------
// Interaction
//--------------------------------------------------

bool World::CanInteractWithDoor(
    const glm::vec3& playerPosition) const
{
    return
        door.CanInteract(
            playerPosition);
}

//--------------------------------------------------
// Treasure Chest Interaction
//--------------------------------------------------

TreasureChest*
World::GetInteractableTreasureChest(
    const glm::vec3& playerPosition)
{
    for (TreasureChest& chest :
        treasureChests)
    {
        if (
            chest.CanInteract(
                playerPosition))
        {
            return &chest;
        }
    }

    return nullptr;
}

//--------------------------------------------------
// Dragon Head Interaction
//--------------------------------------------------
DragonHead* World::GetInteractableDragonHead(
    const glm::vec3& playerPosition)
{
    for (
        DragonHead& dragonHead :
        dragonHeads)
    {
        if (
            dragonHead.CanInteract(
                playerPosition))
        {
            return &dragonHead;
        }
    }

    return nullptr;
}

//--------------------------------------------------
// Tree Generation
//--------------------------------------------------

void World::GenerateTrees()
{
    const int treeCount =
        550;

    for (
        int i = 0;
        i < treeCount;
        i++)
    {
        Tree tree;

        float x =
            static_cast<float>(
                (std::rand()
                    %
                    static_cast<int>(
                        terrainSize * 10.0f))
                -
                static_cast<int>(
                    terrainSize * 5.0f))
            / 10.0f;

        float z =
            static_cast<float>(
                (std::rand()
                    %
                    static_cast<int>(
                        terrainSize * 10.0f))
                -
                static_cast<int>(
                    terrainSize * 5.0f))
            / 10.0f;

        //--------------------------------------------------
        // Keep Spawn Area Clear
        //--------------------------------------------------

        if (
            glm::length(
                glm::vec2(
                    x,
                    z))
            <
            10.0f)
        {
            i--;
            continue;
        }

        //--------------------------------------------------
        // Keep Castle Area Clear
        //--------------------------------------------------

        if (
            glm::distance(
                glm::vec2(
                    x,
                    z),

                glm::vec2(
                    castlePosition.x,
                    castlePosition.z))
            <
            25.0f)
        {
            i--;
            continue;
        }

        tree.SetPosition(
            {
                x,
                0.0f,
                z
            });

        tree.SetRotation(
            static_cast<float>(
                rand() % 360));

        tree.SetTreeType(
            rand() % 5);

        tree.SetTrunkSize(
            0.60f +
            static_cast<float>(
                rand()) /
            static_cast<float>(
                RAND_MAX) *
            0.60f,

            3.50f +
            static_cast<float>(
                rand()) /
            static_cast<float>(
                RAND_MAX) *
            3.00f);

        tree.SetLeavesSize(
            2.80f +
            static_cast<float>(
                rand()) /
            static_cast<float>(
                RAND_MAX) *
            2.50f);

        tree.SetScale(
            0.60f +
            static_cast<float>(rand()) /
            RAND_MAX * 1.60f);

        trees.push_back(
            tree);
    }
}

//--------------------------------------------------
// Castle Generation
//--------------------------------------------------

void World::GenerateCastle()
{
    castlePosition.y =
        0.0f;

    //--------------------------------------------------
    // Door Position
    //--------------------------------------------------

    door.SetPosition(
        {
            castlePosition.x,
            0.0f,
            castlePosition.z - 6.0f
        });

    //--------------------------------------------------
    // Start Closed
    //--------------------------------------------------

    door.Close();
}

//--------------------------------------------------
// Destructor
//--------------------------------------------------

//--------------------------------------------------
// Treasure Chest Generation
//--------------------------------------------------

void World::GenerateTreasureChests()
{
    TreasureChest chest;

    //--------------------------------------------------
    // Position
    //--------------------------------------------------

    chest.SetPosition(
        {
            castlePosition.x + 4.5f,
            0.0f,
            castlePosition.z + 2.5f
        });

    //--------------------------------------------------
    // Rotation
    //--------------------------------------------------

    chest.SetRotation(
        -93.0f);

    //--------------------------------------------------
    // Scale
    //--------------------------------------------------

    chest.SetScale(
        {
            1.0f,
            1.0f,
            1.0f
        });

    treasureChests.push_back(
        chest);
}

World::~World()
{
}