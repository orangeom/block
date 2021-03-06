#pragma once

namespace Blocks
{
    enum
    {
        Air,
        Stone,
        Dirt,
        Grass,
        Bedrock,
        Sand,
        Log,
        Leaves,
        RedFlower,
        YellowFlower,
        GrassPlant,
        Glowstone,
        TNT
    };

    extern int faces[256][6];

    bool isTransparent(int type);
    bool isPlant(int type);
    bool isLight(int type);
    bool isSolid(int type);
}