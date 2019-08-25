#pragma once

#include "CEntity.h"
#include "CLoopbackPacketSender.h"
#include "TextHolder.h"

class Minecraft;
class LevelRenderer {
private:
	char pad_0x0000[0x850]; //0x0000
public:
	vec3_t origin; //0x0850
};
class HitDetectSystem;

class MinecraftGame {
private:
	char filler[0x98];
	uintptr_t goodFont;
	char pad_0x00A8[0x80]; //0x00A8
	bool canUseKeys;
public:
	
	uintptr_t getTheGoodFontThankYou() {
		return goodFont;
	};

	const bool canUseKeybinds() {
		return canUseKeys;
	};
};

class C_GuiData {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	union {
		struct {
			float widthReal; //0x0018 
			float heightReal; //0x001C 
		};
		vec2_t windowSizeReal; //0x0018
	};
	
	float widthReal2; //0x0020 
	float heightReal2; //0x0024 
	union {
		struct {
			float widthGame; //0x0028 
			float heightGame; //0x002C 
		};
		vec2_t windowSize;  //0x0028 
	};
	

	void displayClientMessageVA(const char * fmt, va_list lis) {
		char message[300];
		int numCharacters = vsprintf_s(message, 300, fmt, lis);
		displayClientMessage(&std::string(message));
	}

	void displayClientMessageF(const char * fmt, ...) {
		va_list arg;
		va_start(arg, fmt);
		displayClientMessageVA(fmt, arg);
		va_end(arg);
	}
	void displayClientMessage(std::string* a2) {
		using displayClientMessage = void(__thiscall*)(void*, TextHolder); // This signature actually exists 2 times but we got luck that our function is the first in memory
		static displayClientMessage displayMessageFunc = reinterpret_cast<displayClientMessage>(Utils::FindSignature("40 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ?? 48 81 EC ?? ?? ?? ?? 48 C7 45 ?? FE FF FF FF 48 89 9C 24 ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 ?? 4C 8B FA 4C 8B E9 48 89 4C 24 ?? 48 C7 45 ?? 0F 00 00 00 33 C0 48 89 45 ?? 88 45"));
		
		TextHolder text = TextHolder(*a2);
		
		displayMessageFunc(this, text);
	};
};

class C_ClientInstance {
private:
	char firstPad[0x40]; //0x0000
public:
	MinecraftGame* minecraftGame; //0x0040 
private:
	MinecraftGame* N0000080C; //0x0048 
	MinecraftGame* N0000080D; //0x0050 
	MinecraftGame* N0000080E; //0x0058 
public:
	Minecraft* minecraft; //0x0060 
private:
	char pad_0x0068[0x8]; //0x0068
public:
	LevelRenderer* levelRenderer; //0x0070 
private:
	char pad_0x0078[0x8]; //0x0078
public:
	C_LoopbackPacketSender* loopbackPacketSender; //0x0080 
private:
	char pad_0x0088[0x28]; //0x0088
public:
	HitDetectSystem* hitDetectSystem; //0x00B0 
private:
	char pad_0x00B8[0x28]; //0x00B8
public:
	C_LocalPlayer* localPlayer; //0x00E0 


private:
	virtual __int64 destructorClientInstance();
	// Duplicate destructor
	virtual __int64 onInitMinecraftGame(void);
	virtual __int64 onDestroyMinecraftGame(void);
	virtual __int64 init(__int64 *, __int64 &, __int64 &, __int64 &, __int64 &, int);
	virtual __int64 initSceneFactory(__int64 *);
	virtual __int64 initGraphics(void);
	virtual __int64 stop(void);
	virtual __int64 teardown(void);
	virtual __int64 preShutDown(void);
	virtual __int64 requestLeaveGame(bool, bool);
	virtual __int64 stopPlayScreen(void);
public:
	virtual bool isLeaveGameDone(void)const;
	virtual void setupPlayScreenForLeaveGame(void);
private:
	virtual __int64 resetPrimaryClient(void);
	virtual __int64 resetGameSession(void);
	virtual __int64 tick(void);
	virtual __int64 frameUpdate(__int64 &);
	virtual __int64 update(bool);
	virtual __int64 endFrame(void);
	virtual __int64 startSubClientLateJoin(bool);
public:
	virtual void setupClientGame(__int64 &&, bool);
private:
	virtual __int64 getLocalC_Player(void);
	virtual __int64 getLocalC_Player(void)const;
	virtual __int64 getCameraEntity(void)const;
public:
	virtual void setCameraEntity(C_Entity *);
private:
	virtual __int64 getCameraTargetEntity(void)const;
public:
	virtual void setCameraTargetEntity(C_Entity *);
	virtual bool isLeavingGame(void)const;
	virtual bool isDestroyingGame(void)const;
private:
	virtual __int64 useLowFrequencyUIRender(void)const;
public:
	virtual bool isSplitScreenActive(void)const;
	virtual bool isVRClient(void)const;
	virtual bool isARClient(void)const;
	virtual bool isARVRClient(void)const;
	virtual bool isHoloviewerMode(void)const;
	virtual bool isHoloscreenMode(void)const;
	virtual bool isLivingroomMode(void)const;
	virtual bool isExitingLevel(void)const;
	virtual bool isNotVLRMode(void)const;
	virtual bool isHoloRealityMode(void)const;
	virtual bool isRealityFullVRMode(void)const;
	virtual bool isInBedScreen(void)const;
	virtual bool isKeyboardEnabled(void)const;
	virtual bool isVRTransitioning(void)const;
	virtual bool hasCommands(void)const;
	virtual bool isScriptingEnabled(void)const;
private:
	virtual __int64 getHoloviewerScale(void)const;
	virtual __int64 getSplitScreenCount(void)const;
public:
	virtual bool isStereoRendering(void)const;
	virtual bool isPlatformNX(void)const;
	virtual bool isLocalSplitscreenWith(__int64 const&)const;
	virtual bool isValidCrossPlatformSkin(void)const;
private:
	virtual __int64 getSplitScreenInfo(void)const;
	virtual __int64 getCurrentMaxGUIScaleIndex(void)const;
	virtual __int64 getRealityModeFrameFactor(void)const;
public:
	virtual void setRealityModeFrameFactor(float const&);
private:
	virtual __int64 getRealityModeToggleTriggered(void)const;
public:
	virtual void setRealityModeToggleTriggered(bool);
	virtual void setOpenControllerDisconnectScreen(bool);
private:
	virtual __int64 getClientPlayMode(void)const;
public:
	virtual void setClientPlayMode(__int64 const&);
private:
	virtual __int64 getLivingRoomForCredits(void)const;
public:
	virtual void setLivingRoomForCredits(bool);
private:
	virtual __int64 getCreditsCallback(void);
public:
	virtual void setCreditsCallback(__int64);
	virtual void setupTransitionForCredits(__int64);
private:
	virtual __int64 refreshScreenSizeData(void);
	virtual __int64 onScreenSizeChanged(int, int, float);
	virtual __int64 onGuiScaleOffsetChanged(void);
	virtual __int64 onSafeZoneChanged(void);
	virtual __int64 quit(std::string const&, std::string const&);
	virtual __int64 getMinecraftGame(void)const;
	virtual __int64 getAutomationClient(void)const;
	virtual __int64 getScreenshotStreamer(void)const;
	virtual __int64 getEventing(void)const;
	virtual __int64 getFont(void)const;
	virtual __int64 getRuneFont(void)const;
	virtual __int64 getUnicodeFont(void)const;
	virtual __int64 getGeometryGroup(void)const;
	virtual __int64 getMultiplayerServiceManager(void)const;
	virtual __int64 getLocalServerLevel(void);
	virtual __int64 getResourcePackRepository(void)const;
	virtual __int64 getResourcePackManager(void)const;
	virtual __int64 getPackManifestFactory(void);
	virtual __int64 getKeyProvider(void);
	virtual __int64 getResourcePacksInfoData(void);
	virtual __int64 getSkinGeometryGroup(void)const;
	virtual __int64 getSkinRepository(void)const;
	virtual __int64 getSkinRepositoryClientInterface(void)const;
	virtual __int64 getTextures(void)const;
	virtual __int64 getStoreCacheTextures(void)const;
	virtual __int64 getMinecraftGraphics(void)const;
	virtual __int64 getUIRepository(void)const;
	virtual __int64 getUserManager(void)const;
	virtual __int64 wantToQuit(void)const;
public:
	virtual bool isPrimaryLevelCrossPlatformMultiplayer(void)const;
	virtual bool isPrimaryLevelMultiplayer(void)const;
	virtual bool isAdhocEnabled(void)const;
private:
	virtual __int64 linkToOffer(std::string const&, bool, std::string const&, __int64);
	virtual __int64 linkToAllOffers(std::string const&, std::string const&, bool, std::string const&, bool);
	virtual __int64 navigateToBrazeScreen(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&);
	virtual __int64 navigateToStoreHomeScreen(void);
	virtual __int64 navigateToCoinPurchaseScreen(int, __int64);
	virtual __int64 navigateToPurchaseOfferScreen(__int64, bool);
	virtual __int64 navigateToOfferCollectionScreen(__int64 &);
	virtual __int64 navigateToStoreSeeAllByCreatorScreen(std::string const&, bool);
	virtual __int64 navigateToServersScreen(bool);
	virtual __int64 navigateToHowToPlayScreen(std::string const&);
	virtual __int64 tryPushLeaveGameScreen(void);
public:
	virtual bool isReadyToRender(void)const;
private:
	virtual __int64 onDimensionChanged(void);
	virtual __int64 onGameEventNotification(__int64);
	virtual __int64 getTopScreenName(void)const;
public:
	virtual void setLeaveGameInProgressAsReadyToContinue(void);
private:
	virtual __int64 stopDestroying(void);
	virtual __int64 onClientCreatedLevel(__int64);
	virtual __int64 getClientRandomId(void)const;
	virtual __int64 getUserAuthentication(void);
	virtual __int64 registerToUserManager(__int64 &, int);
	virtual __int64 resumeWithUserManager(__int64 &, int);
	virtual __int64 createUserAuthentication(std::string);
	virtual __int64 createUserAuthentication(unsigned long long, std::string const&);
	virtual __int64 getPlatformId(void)const;
	virtual __int64 getPlatformOnlineId(void)const;
public:
	virtual bool isHoloCursorNeeded(void)const;
private:
	virtual __int64 useController(void)const;
	virtual __int64 useTouchscreen(void)const;
	virtual __int64 getMouseGrabbed(void)const;
	virtual __int64 currentInputModeIsGamePadOrMotionController(void)const;
	virtual __int64 currentInputModeIsMouseAndKeyboard(void)const;
	virtual __int64 getForceMonoscopic(void)const;
	virtual __int64 allowPicking(void)const;
public:
	virtual bool isShowingMenu(void)const;
	virtual bool isShowingProgressScreen(void)const;
	virtual bool isScreenReplaceable(void)const;
	virtual bool isInGame(void)const;
	virtual bool isInRealm(void);
private:
	virtual __int64 readyForShutdown(void)const;
public:
	virtual bool isPrimaryClient(void)const;
	virtual bool isEduMode(void)const;
	virtual bool isGamepadCursorEnabled(void)const;
private:
	virtual __int64 getServerData(void);
	virtual __int64 getServerData(void)const;
public:
	virtual PointingStruct* getLevel(void);
	virtual PointingStruct* getLevel(void)const;
	virtual bool isPreGame(void)const;
	virtual bool isInMultiplayerGame(void)const;
	virtual bool isMultiC_PlayerClient(void)const;
private:
	virtual __int64 getOptions(void);
	virtual __int64 getOptions(void)const;
	virtual __int64 getOptionsPtr(void);
	virtual __int64 getUser(void);
	virtual __int64 getUser(void)const;
	virtual __int64 getGameRenderer(void)const;
	virtual __int64 getHolosceneRenderer(void)const;
	virtual __int64 getLevelRenderer(void)const;
	virtual __int64 getLevelRendererCameraProxy(void)const;
	virtual __int64 getLightTexture(void);
public:
	virtual void setupLevelRendering(__int64 &, C_Entity &);
private:
	virtual __int64 getViewportInfo(void)const;
public:
	virtual void setViewportInfo(__int64 const&);
private:
	virtual __int64 getNormalizedViewportSize(void)const;
	virtual __int64 updateChunkRadius(void);
public:
	virtual void setUITexture(__int64 *);
private:
	virtual __int64 getUITexture(void);
public:
	virtual void setLevelTexture(__int64*);
private:
	virtual __int64 getLevelTexture(void);
public:
	virtual void setUICursorTexture(__int64);
private:
	virtual __int64 getUICursorTexture(void)const;
	virtual __int64 getCamera(void);
	virtual __int64 getShaderColor(void);
	virtual __int64 getDarkShaderColor(void);
	virtual __int64 clearGraphicsCache(void);
	virtual __int64 getNormalizedUICursorTransform(__int64 &, float);
	virtual __int64 shouldRenderUICursor(void)const;
	virtual __int64 onLatencyUpdated(std::chrono::duration<long long, std::ratio<1ll, 1000ll>> const&);
	virtual __int64 getGuiScale(void)const;
	virtual __int64 getGuiScaleOption(void)const;
	virtual __int64 getGuiScaleOffset(void)const;
public:
	virtual void setGuiScaleOffset(int);
private:
	virtual __int64 renderEditorGui(__int64 &, bool);
public:
	virtual C_GuiData* getGuiData(void);
	virtual C_GuiData* getGuiData(void)const;
private:
	virtual __int64 getGuidedFlowManager(void);
	virtual __int64 getDpadScale(void)const;
	virtual __int64 getDateManager(void)const;
	virtual __int64 addOverrideHoursToDateTime(unsigned int);
	virtual __int64 getToastManager(void);
	virtual __int64 getTopScene(void);
	virtual __int64 getTopScene(void)const;
	virtual __int64 getActiveScene(void);
	virtual __int64 getActiveScene(void)const;
	virtual __int64 getSceneFactory(void)const;
	virtual __int64 getClientSceneStack(void)const;
	virtual __int64 getClientSceneStack(void);
	virtual __int64 getMainSceneStack(void);
	virtual __int64 getMainSceneStack(void)const;
	virtual __int64 getCurrentSceneStack(void)const;
	virtual __int64 getCurrentSceneStack(void);
	virtual __int64 getCurrentUIRouter(void);
	virtual __int64 getCurrentUIRouter(void)const;
	virtual __int64 prepareSceneFor(__int64);
	virtual __int64 getCachedScenes(void);
	virtual __int64 getScreenName(void)const;
	virtual __int64 getScreenTelemetry(void)const;
	virtual __int64 getTopSceneType(void)const;
	virtual __int64 getMobEffectsLayout(void);
	virtual __int64 onMobEffectsChange(void);
public:
	virtual void setUISizeAndScale(int, int, float);
private:
	virtual __int64 forEachVisibleScreen(__int64, bool);
	virtual __int64 forEachScreen(__int64, bool);
	virtual __int64 forEachScreenConst(__int64, bool)const;
	virtual __int64 updateSceneStack(void);
	virtual __int64 forEachAlwaysAcceptInputScreen(__int64);
	virtual __int64 forEachAlwaysAcceptInputScreenWithTop(__int64);
	virtual __int64 showC_PlayerProfile(std::string const&, __int64);
	virtual __int64 getCurrentInputMode(void)const;
public:
	virtual bool isTouchGameplayAllowed(void)const;
private:
	virtual __int64 getMinecraftInput(void)const;
public:
	virtual void setHoloInput(__int64);
private:
	virtual __int64 getHoloInput(void)const;
	virtual __int64 getVoiceSystem(void)const;
	virtual __int64 getKeyboardManager(void);
public:
	virtual void setVoiceSystem(__int64);
	virtual void setLastPointerLocation(float, float, float);
private:
	virtual __int64 getLastPointerLocation(void);
	virtual __int64 shouldUseLastPointerLocationOnFocusChange(void);
	virtual __int64 adjustGazeCursorByMouse(float, float);
	virtual __int64 currentScreenShouldStealMouse(void);
	virtual __int64 getInProgressBAI(void)const;
	virtual __int64 newDictationDataAvailable(void)const;
	virtual __int64 clearDictationDataAvailable(void);
	virtual __int64 getDictationText(void)const;
	virtual __int64 getPacketSender(void);
	virtual __int64 getClientNetworkSystem(void);
	virtual __int64 getClientNetworkSystem(void)const;
public:
	virtual void setMoveTurnInput(__int64);
private:
	virtual __int64 getMoveTurnInput(void);
public:
	virtual void setupPersistentControls(__int64);
private:
	virtual __int64 resetC_PlayerMovement(void);
	virtual __int64 onClientInputInitComplete(void);
public:
	virtual void setClientInputHandler(__int64);
private:
	virtual __int64 getInput(void)const;
	virtual __int64 getControllerId(void)const;
public:
	virtual bool hasConnectedController(void)const;
private:
	virtual __int64 getClientSubId(void)const;
public:
	virtual void setSuspendInput(bool);
	virtual void setDisableInput(bool);

	virtual void grabMouse(void);
	virtual void releaseMouse(void);
	virtual void refocusMouse(void);
private:
	virtual __int64 resetBai(int);
	virtual __int64 clearInProgressBAI(void);
	virtual __int64 tickBuildAction(void);
	virtual __int64 getSoundEngine(void)const;
	virtual __int64 play(std::string const&, vec3_t const&, float, float);
	virtual __int64 playUI(std::string const&, float, float);
	virtual __int64 muteAudio(void);
	virtual __int64 unMuteAudio(void);
	virtual __int64 fadeOutMusic(void)const;
	virtual __int64 getTaskGroup(void);
	virtual __int64 onFullVanillaPackOnStack(void);
public:
	virtual bool isFullVanillaPackOnStack(void)const;
private:
	virtual __int64 onPlayerLoaded(C_Player &);
public:
	virtual void setClientGameMode(__int64);
private:
	virtual __int64 resetToDefaultGameMode(void);
	virtual __int64 connectToThirdParyServer(std::string const&, std::string const&, int);
	virtual __int64 startExternalNetworkWorld(__int64, std::string const&, bool);
	virtual __int64 checkForPiracy(void);
	virtual __int64 updateChatFilterStatus(void);
public:
	virtual void setBehaviorCommandCallback(__int64);
	virtual void setBehaviorCommandStatus(std::string, __int64);
private:
	virtual __int64 requestScreenshot(__int64 &);
	virtual __int64 getDevConsoleLogger(void)const;
	virtual __int64 requestImageFromUrl(std::string const&, __int64);
	virtual __int64 initializeRenderResources(void);
	virtual __int64 postInitRenderResources(void);
	virtual __int64 onAppSuspended(void);
	virtual __int64 onActiveResourcePacksChanged(__int64 const&);
	virtual __int64 reloadEntityRenderers(__int64 const&);
	virtual __int64 getBlockTessellator(void);
	virtual __int64 getBlockEntityRenderDispatcher(void);
	virtual __int64 getEntityRenderDispatcher(void);
	virtual __int64 getEntityBlockRenderer(void);
	virtual __int64 getItemInHandRenderer(void);
	virtual __int64 getItemRenderer(void);
	virtual __int64 getSentMessageHistory(void);
	virtual __int64 getUIProfanityContext(void)const;
	virtual __int64 initTTSClient(__int64 &);
	virtual __int64 getTTSClient(void);
	virtual __int64 getTTSClient(void)const;
	virtual __int64 getTTSEventManager(void);
	virtual __int64 addTTSMessage(std::string const&, __int64, bool, bool, bool);
	virtual __int64 initCommands(void);
	virtual __int64 getUserId(void)const;
	virtual __int64 getServerConnectionTime(void)const;
	virtual __int64 getHMDState(void);
	virtual __int64 getHMDState(void)const;
public:
	virtual void setServerPingTime(unsigned int);
private:
	virtual __int64 getServerPingTime(void)const;
public:
	virtual void setDefaultPlayscreenTab(__int64);
	virtual void setClientInstanceState(__int64 const&);
	virtual void setUIEventCoordinator(__int64 &&);
private:
	virtual __int64 getUIEventCoordinator(void);
	virtual __int64 getEventCoordinator(void);
	virtual __int64 computeScreenCoordsFromScreenNormCoords(float, float, short &, short &);
	virtual __int64 getNoBlockBreakUntil(void);
public:
	virtual void setNoBlockBreakUntil(__int64);
	virtual void setDictation(std::string const&);
	virtual void setNewDictationString(bool);
	virtual void setGameModule(__int64);
private:
	virtual __int64 getGameModule(void);
	virtual __int64 getGameCallbacks(void);
	virtual __int64 getStorageAreaStateListener(void);
	virtual __int64 getScriptEngine(void);
	virtual __int64 sendClientEnteredLevel(void);
	virtual __int64 getHitDetectSystem(void);
public:
	virtual bool isPlaying(void)const;
private:
	virtual __int64 getLatencyGraphDisplay(void)const;
	virtual __int64 createSkin(void);
	virtual __int64 onExtendDiskSpace(bool, __int64 &, unsigned long long const&, __int64);
	virtual __int64 onLowDiskSpace(bool);
	virtual __int64 onOutOfDiskSpace(bool);
	virtual __int64 onCriticalDiskError(bool, __int64 const&);
	virtual __int64 onLevelCorrupt(void);
	virtual __int64 onGameModeChanged(void);
	virtual __int64 onTick(int, int);
	virtual __int64 onInternetUpdate(void);
	virtual __int64 onGameSessionReset(void);
	virtual __int64 onLevelExit(void);
	virtual __int64 updateScreens(void);
public:


	C_LocalPlayer* getLocalPlayer() {
		return localPlayer;
	};

	PointingStruct* getPointerStruct() {
		return this->getLevel();
	}

	glmatrixf* getRefDef() {
		uintptr_t _this = reinterpret_cast<uintptr_t>(this);
		//logF("refderf %llX", _this + 0x258);
		return reinterpret_cast<glmatrixf*>(_this + 0x268);
	};

	vec2_t* getMousePos(){
		uintptr_t _this = reinterpret_cast<uintptr_t>(this);
		return reinterpret_cast<vec2_t*>(_this + 0x3D0);;
	}

	vec2_t getFov() {
		uintptr_t _this = reinterpret_cast<uintptr_t>(this);
		vec2_t fov;
		fov.x = *reinterpret_cast<float*>(_this + 0x5D0);
		fov.y = *reinterpret_cast<float*>(_this + 0x5E4);
		return fov;
	}

	uintptr_t getFont() {
		
		return Utils::CallVFunc<73, uintptr_t>(this);
	}

	uintptr_t getRuneFont() {

		return Utils::CallVFunc<74, uintptr_t>(this);
	}

	uintptr_t getUnicodeFont() {

		return Utils::CallVFunc<75, uintptr_t>(this);
	}
};