#pragma once

class C_RakNetInstance {
private:
	char pad_0x0008[0x358];//0x0008 
public:
	TextHolder serverIp;


private:
	virtual ~C_RakNetInstance();
	virtual __int64 onAppResumed(void);
	virtual __int64 onAppSuspended(void);
public:
	virtual TextHolder* getLocalIps(TextHolder*);
	virtual TextHolder* getLocalIp(TextHolder*);
private:
	virtual __int64 getPort(void)const;
	virtual __int64 getRefinedLocalIps(void)const;
	virtual __int64 getConnectedGameInfo(void)const;
public:
	virtual void setupNatPunch(bool);
private:
	virtual __int64 getNatPunchInfo(void)const;
	virtual __int64 startNatPunchingClient(__int64);
	virtual __int64 addConnectionStateListener(__int64);
	virtual __int64 removeConnectionStateListener(__int64);
public:
	virtual bool isIPv4Supported(void)const;
	virtual bool isIPv6Supported(void)const;
private:
	virtual __int64 getIPv4Port(void)const;
	virtual __int64 getIPv6Port(void)const;
	virtual __int64 getGUID(void)const;
};