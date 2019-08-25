#pragma once
#include "../Utils/HMath.h"
#include "../Utils/Logger.h"
#include "TextHolder.h"

class C_Packet {
public:
	uintptr_t** vTable; //0x0000
};

class C_InteractPacket : public C_Packet
{
private:
	char filler[0x20]; //x0x00008
public:
	__int64 entityRuntimeID; //0x28
	vec3_t pos; //0x30
};




class C_TextPacket : public C_Packet
{
public:
	C_TextPacket() {
		static uintptr_t** textPacketVtable = 0x0;
		if (textPacketVtable == 0x0) {
			uintptr_t sigOffset = Utils::FindSignature("48 8D 05 ?? ?? ?? ?? 48 89 85 ?? ?? ?? ?? C6 85 ?? ?? ?? ?? 01 4C");
			int offset = *reinterpret_cast<int*>(sigOffset + 3);
			textPacketVtable = reinterpret_cast<uintptr_t * *>(sigOffset + offset + /*length of instruction*/ 7);
			if (textPacketVtable == 0x0 || sigOffset == 0x0)
				logF("C_TextPacket signature not working!!!");
		}
		memset(this, 0, sizeof(C_TextPacket)); // Avoid overwriting vtable
		vTable = textPacketVtable;

		messageType = 1; // TYPE_CHAT
	}

	unsigned char gap0[24];
	unsigned __int8 messageType;

	unsigned char gap[3];
	unsigned char field_24[4];
	
	TextHolder sourceName;
	TextHolder message;
	unsigned char field_24222[24];
	bool translationNeeded = false;

	unsigned char ga2p[7];
	TextHolder xboxUserId;
	TextHolder platformChatId;
};

#pragma pack(push,8)

__declspec(align(8))
class C_MovePlayerPacket : public C_Packet
{
public:
	C_MovePlayerPacket() {
		static uintptr_t** movePlayerPacketVtable = 0x0;
		if (movePlayerPacketVtable == 0x0) {
			uintptr_t sigOffset = Utils::FindSignature("48 8D 05 ?? ?? ?? ?? 48 89 01 48 8B 82 ?? ?? ?? ?? 48 89 41 ?? 48 8B 02 48 8B CA FF 50");
			int offset = *reinterpret_cast<int*>(sigOffset + 3);
			movePlayerPacketVtable = reinterpret_cast<uintptr_t**>(sigOffset  + offset + /*length of instruction*/ 7);
			if (movePlayerPacketVtable == 0x0 || sigOffset == 0x0)
				logF("C_MovePlayerPacket signature not working!!!");
		}
		memset(this, 0, sizeof(C_MovePlayerPacket)); // Avoid overwriting vtable
		vTable = movePlayerPacketVtable;
	}
	C_MovePlayerPacket(C_LocalPlayer* player,vec3_t pos) {
		static uintptr_t** movePlayerPacketVtable = 0x0;
		if (movePlayerPacketVtable == 0x0) {
			uintptr_t sigOffset = Utils::FindSignature("48 8D 05 ?? ?? ?? ?? 48 89 01 48 8B 82 ?? ?? ?? ?? 48 89 41 ?? 48 8B 02 48 8B CA FF 50");
			int offset = *reinterpret_cast<int*>(sigOffset + 3);
			movePlayerPacketVtable = reinterpret_cast<uintptr_t**>(sigOffset + offset + /*length of instruction*/ 7);
			if (movePlayerPacketVtable == 0x0 || sigOffset == 0x0)
				logF("C_MovePlayerPacket signature not working!!!");
		}
		memset(this, 0, sizeof(C_MovePlayerPacket)); // Avoid overwriting vtable
		vTable = movePlayerPacketVtable;
		entityRuntimeID = player->entityRuntimeId;
		Position = pos;
		pitch = player->pitch;
		yaw = player->yaw;
		headYaw = player->yaw;
		onGround = true;
		mode = 0;
	}


	//uintptr_t** vTable;		// 0x0
private:
	char filler[0x18];		// 0x8
public:
	__int64 entityRuntimeID;// 0x20
	vec3_t Position;		// 0x28
	float pitch;			// 0x34
	float yaw;				// 0x38
	float headYaw;			// 0x3C
	uint8_t mode;			// 0x40
	bool onGround;			// 0x41
	__int64 ridingEid;		// 0x48 // works because aligning
	int int1;				// 0x50
	int int2;				// 0x50
};

#pragma pack(pop)

