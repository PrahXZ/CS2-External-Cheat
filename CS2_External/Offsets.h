#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"

// From: https://github.com/a2x/cs2-dumper/blob/main/generated/client.dll.hpp
namespace Offset
{
	inline DWORD EntityList;
	inline DWORD Matrix;
	inline DWORD ViewAngle;
	inline DWORD LocalPlayerController;
	inline DWORD LocalPlayerPawn;
	inline DWORD ForceJump;
	inline DWORD GlobalVars;

	struct
	{
		DWORD Health = 0x32C;
		DWORD TeamID = 0x3BF;
		DWORD IsAlive = 0x7F4;
		DWORD PlayerPawn = 0x7EC;
		DWORD iszPlayerName = 0x640;
	}Entity;

	struct
	{
		DWORD Pos = 0x1224;
		DWORD MaxHealth = 0x328;
		DWORD CurrentHealth = 0x32C;
		DWORD GameSceneNode = 0x310;
		DWORD BoneArray = 0x1E0;
		DWORD angEyeAngles = 0x1518;
		DWORD vecLastClipCameraPos = 0x1294;
		DWORD pClippingWeapon = 0x12B0;
		DWORD iShotsFired = 0x1420;
		DWORD flFlashDuration = 0x1470;
		DWORD aimPunchAngle = 0x171C;
		DWORD aimPunchCache = 0x1740;
		DWORD iIDEntIndex = 0x1544;
		DWORD iTeamNum = 0x3BF;
		DWORD CameraServices = 0x10E0;
		DWORD iFovStart = 0x214;
		DWORD fFlags = 0x3C8;
		DWORD bSpottedByMask = 0x1644; 
	}Pawn;

	struct // C_BaseCSGrenadeProjectile
	{
		DWORD nSmokeEffectTickBegin = 0x1108; // int32_t
		DWORD bDidSmokeEffect = 0x110C; // bool
		DWORD nRandomSeed = 0x1110; // int32_t
		DWORD vSmokeColor = 0x1114; // Vector
		DWORD vSmokeDetonationPos = 0x1120; // Vector
		DWORD VoxelFrameData = 0x1130; // CUtlVector<uint8_t>
		DWORD bSmokeVolumeDataReceived = 0x1148; // bool
		uintptr_t bSmokeEffectSpawned = 0x1149; // bool
	} SmokeGrenadeProjectile;


	struct
	{
		DWORD RealTime = 0x00;
		DWORD FrameCount = 0x04;
		DWORD MaxClients = 0x10;
		DWORD IntervalPerTick = 0x14;
		DWORD CurrentTime = 0x2C;
		DWORD CurrentTime2 = 0x30;
		DWORD TickCount = 0x40;
		DWORD IntervalPerTick2 = 0x44;
		DWORD CurrentNetchan = 0x0048;
		DWORD CurrentMap = 0x0180;
		DWORD CurrentMapName = 0x0188;
	} GlobalVar;

	namespace Signatures
	{
		const std::string GlobalVars = "48 89 0D ?? ?? ?? ?? 48 89 41";
		const std::string ViewMatrix = "48 8D 0D ?? ?? ?? ?? 48 C1 E0 06";
		const std::string ViewAngles = "48 8B 0D ?? ?? ?? ?? E9 ?? ?? ?? ?? CC CC CC CC 48 C7 02";
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string ForceJump = "48 8B 05 ?? ?? ?? ?? 48 8D 1D ?? ?? ?? ?? 48 89 45";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
	}

	bool UpdateOffsets();
}
