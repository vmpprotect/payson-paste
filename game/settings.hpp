#pragma once
#include "../imgui/imgui.h"

struct bone
{
    int bone1;
    int bone2;
    bone(int b1, int b2) : bone1(b1), bone2(b2) {}
};
inline bone boneConnections[] = {
    bone(110, 67), // head to neck
    bone(67, 7), // neck to chest
    bone(7, 2), // chest to pelvis
    bone(7, 9), // chest to right shoulder
    bone(9, 35), // right shoulder to right elbow
    bone(35, 11), // right elbow to right wrist
    bone(7, 38), // chest to left shoulder
    bone(38, 39), // left shoulder to left elbow
    bone(39, 40), // left elbow to left wrist
    bone(2, 71), // pelvis to right hip
    bone(71, 72), // right hip to right knee
    bone(72, 73), // right knee to right shin
    bone(73, 75), // right shin to right ankle
    bone(2, 78), // pelvis to left hip
    bone(78, 79), // left hip to left knee
    bone(79, 80), // left knee to left shin
    bone(80, 82), // left shin to left ankle
};

enum hitboxType : int
{
    head = 110,
    neck = 67,
    chest = 7,
    ass = 69,
};
inline int hitboxValues[] = {
    hitboxType::head,
    hitboxType::neck,
    hitboxType::chest,
    hitboxType::ass,
};
inline const char* getHitboxTypeName(int type)
{
    switch (type)
    {
        case hitboxType::head: return "Head";
        case hitboxType::neck: return "Neck";
        case hitboxType::chest: return "Chest";
        case hitboxType::ass: return "Ass";
        default: return "Unknown";
    }
}

typedef struct
{
    DWORD R;
    DWORD G;
    DWORD B;
    DWORD A;
}RGBA;
class Color
{
public:
    RGBA red = { 255,0,0,255 };
    RGBA redlol = { 255,0,0,200 };
    RGBA Magenta = { 255,0,255,255 };
    RGBA yellow = { 255,255,0,255 };
    RGBA grayblue = { 128,128,255,255 };
    RGBA green = { 128,224,0,255 };
    RGBA limegreen = { 0,255,0,255 };
    RGBA darkgreen = { 0,224,128,255 };
    RGBA brown = { 192,96,0,255 };
    RGBA pink = { 255,168,255,255 };
    RGBA DarkYellow = { 216,216,0,255 };
    RGBA SilverWhite = { 236,236,236,255 };
    RGBA purple = { 144,0,255,255 };
    RGBA Navy = { 88,48,224,255 };
    RGBA skyblue = { 0,136,255,255 };
    RGBA graygreen = { 128,160,128,255 };
    RGBA blue = { 0,96,192,255 };
    RGBA orange = { 255,128,0,255 };
    RGBA peachred = { 255,80,128,255 };
    RGBA reds = { 255,128,192,255 };
    RGBA darkgray = { 96,96,96,255 };
    RGBA Navys = { 0,0,128,255 };
    RGBA cyan = { 0,255,255,255 };
    RGBA darkgreens = { 0,128,0,255 };
    RGBA darkblue = { 0,128,128,255 };
    RGBA redbrown = { 128,0,0,255 };
    RGBA purplered = { 128,0,128,255 };
    RGBA greens = { 0,255,0,255 };
    RGBA envy = { 0,255,255,255 };
    RGBA black = { 100,0,0,0 };
    RGBA gray = { 128,128,128,255 };
    RGBA white = { 255,255,255,255 };
    RGBA blues = { 30,144,255,255 };
    RGBA lightblue = { 135,206,250,160 };
    RGBA Scarlet = { 220, 20, 60, 160 };
    RGBA white_ = { 255,255,255,200 };
    RGBA gray_ = { 128,128,128,200 };
    RGBA black_ = { 100,000, 000, 000 };
    RGBA red_ = { 255,0,0,200 };
    RGBA Magenta_ = { 255,0,255,200 };
    RGBA yellow_ = { 255,255,0,200 };
    RGBA grayblue_ = { 128,128,255,200 };
    RGBA green_ = { 128,224,0,200 };
    RGBA darkgreen_ = { 0,224,128,200 };
    RGBA brown_ = { 192,96,0,200 };
    RGBA pink_ = { 255,168,255,200 };
    RGBA darkyellow_ = { 216,216,0,200 };
    RGBA silverwhite_ = { 236,236,236,200 };
    RGBA purple_ = { 144,0,255,200 };
    RGBA Blue_ = { 88,48,224,200 };
    RGBA skyblue_ = { 0,136,255,200 };
    RGBA graygreen_ = { 128,160,128,200 };
    RGBA blue_ = { 0,96,192,200 };
    RGBA orange_ = { 255,128,0,200 };
    RGBA pinks_ = { 255,80,128,200 };
    RGBA Fuhong_ = { 255,128,192,200 };
    RGBA darkgray_ = { 96,96,96,200 };
    RGBA Navy_ = { 0,0,128,200 };
    RGBA darkgreens_ = { 0,128,0,200 };
    RGBA darkblue_ = { 0,128,128,200 };
    RGBA redbrown_ = { 128,0,0,200 };
    RGBA purplered_ = { 128,0,128,200 };
    RGBA greens_ = { 0,255,0,200 };
    RGBA envy_ = { 0,255,255,200 };

    RGBA glassblack = { 0, 0, 0, 160 };
    RGBA GlassBlue = { 65,105,225,80 };
    RGBA glassyellow = { 255,255,0,160 };
    RGBA glass = { 200,200,200,60 };

    RGBA filled = { 0, 0, 0, 150 };

    RGBA Plum = { 221,160,221,160 };

    RGBA VisibleColor = { 255 / 255, 0, 0 };
    RGBA InvisibleColor = { 0, 255 / 255, 0 };
    RGBA FilledFov = { 0,0,0,160 };

    RGBA rainbow() {

        static float x = 0, y = 0;
        static float r = 0, g = 0, b = 0;

        if (y >= 0.0f && y < 255.0f) {
            r = 255.0f;
            g = 0.0f;
            b = x;
        }
        else if (y >= 255.0f && y < 510.0f) {
            r = 255.0f - x;
            g = 0.0f;
            b = 255.0f;
        }
        else if (y >= 510.0f && y < 765.0f) {
            r = 0.0f;
            g = x;
            b = 255.0f;
        }
        else if (y >= 765.0f && y < 1020.0f) {
            r = 0.0f;
            g = 255.0f;
            b = 255.0f - x;
        }
        else if (y >= 1020.0f && y < 1275.0f) {
            r = x;
            g = 255.0f;
            b = 0.0f;
        }
        else if (y >= 1275.0f && y < 1530.0f) {
            r = 255.0f;
            g = 255.0f - x;
            b = 0.0f;
        }

        float rainbow_speed = 0.25f;

        x += rainbow_speed; //increase this value to switch colors faster
        if (x >= 255.0f)
            x = 0.0f;

        y += rainbow_speed; //increase this value to switch colors faster
        if (y > 1530.0f)
            y = 0.0f;


        return RGBA{ (DWORD)r, (DWORD)g, (DWORD)b, 255 };
    }


};

enum boxType : int
{
    normal = 0,
    corner = 1,
    filled = 2,
};
inline int boxValues[] = {
    boxType::normal,
    boxType::corner,
};
inline const char* getBoxTypeName(int type)
{
    switch (type)
    {
    case boxType::normal: return "Normal";
    case boxType::corner: return "Corner";
    default: return "Unknown";
    }
}
int bigfovballs = 25;
float fovv_value = bigfovballs;
inline int iVehicleSpin = 0;
inline int iVehicleVelo1 = 0;
inline int iVehicleVelo2 = 15;
inline int iVehicleVelo3 = 0;
namespace settings
{
    inline int width = GetSystemMetrics(SM_CXSCREEN);
    inline int height = GetSystemMetrics(SM_CYSCREEN);
    inline int screen_center_x = width / 2;
    inline int screen_center_y = height / 2;
    inline bool debug = false;
    inline bool show_menu = true;
    inline int tab = 0;

    namespace aimbot
    {
        inline bool controller = false;
        inline bool enable = false;
        inline bool mouseAim = false;
        inline bool silentAim = false;
        inline bool playerfreeze = false;
        inline bool show_fovfilled = false;
        inline bool visiblecheck = false;
        inline bool bulletPrediction = false;
        inline bool crosshair = false;
        inline bool show_fov = false;
        inline float fov = 150;
        inline float smoothness = 3;
        inline static const char* aimkey[] = { "Left Mouse Button", "Right Mouse Button", "Mouse Button 4", "Mouse Button 5", "Shift", "Ctrl", "ALT", "Caps Lock" };
        inline static int current_aimkey = 1; // default to Right Mouse Button
        inline static int current_key;
        inline static int current_hitbox = hitboxType::head;
    }
    namespace visuals
    {
        inline bool enable = false;
        inline bool radar = false;
        inline bool weapon = false;
        inline bool box = false;
        inline bool niggasud = false;
        inline bool skeleton = false;
        inline bool line = false;
        inline bool name = false;
        inline bool platform = false;
        inline bool distance = false;
        inline bool crounchedesp = false;
        inline bool rank = false;
        inline float renderDistance = 300.0f;
        inline int boxType = boxType::normal;
    }
    namespace colors
    {
        inline ImColor icCrosshairColor = ImColor(255, 0, 255);
        inline ImColor icFovColor = ImColor(255, 0, 255);
        inline ImColor icBoxColorVisible = ImColor(255, 0, 255);
        inline ImColor icBoxColorInvisible = ImColor(0, 255, 255);
        inline ImColor icSkeletonColorVisible = ImColor(255, 0, 255);
        inline ImColor icSkeletonColorInvisible = ImColor(0, 255, 255);
        inline ImColor icTracerColorVisible = ImColor(255, 0, 255);
        inline ImColor icTracerColorInvisible = ImColor(0, 255, 255);
    }
    namespace exploits
    {
        bool spinbot = false;
        bool tinyplayers = false;
        bool fovchanger = false;
        bool instaReboot = false;
        bool bClientLocMod = false;
        bool FirstPerson = false;
        bool norecoil = false;
        bool NoEquipAnimation = false;
        bool autorun = false;
        bool bVehicleTestAttributesTwo = false;
        bool instantrevive = false;
        bool bNoWeaponCooldown = false;
        bool magicbullet = false;
        bool bRapidFire = false;
        bool bTPose = false;
        bool bFullAutoWeapons = false;
        bool playerFly = false;
        bool aimwhilejumping = false;
        inline float fovchanger_value = 90;
        bool doublepump = false;
        bool overheat = false;
        bool noreload = false;
        bool carfly = false;
        bool AirStuck = false;
        bool vehicle_nocooldodwn = false;
        bool creative_fly = false;
    }
}