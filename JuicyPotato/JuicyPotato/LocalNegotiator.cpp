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
	
	 char  hid_Error__Q9sjrbITCPvi[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x2c','\x2b','\x65','\x4','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x45'};
 char k_1pmbUV8HJ3Gi = '\x45';
for(int i = 0; i < sizeof(hid_Error__Q9sjrbITCPvi) / sizeof(hid_Error__Q9sjrbITCPvi[0]); i++){
hid_Error__Q9sjrbITCPvi[i] = hid_Error__Q9sjrbITCPvi[i] ^ k_1pmbUV8HJ3Gi;
}
	typedef SECURITY_STATUS(__stdcall* _AcquireCredentialsHandleW)(PSECURITY_STRING pPrincipal,PSECURITY_STRING pPackage,unsigned long    fCredentialUse,void             *pvLogonId,void             *pAuthData,SEC_GET_KEY_FN   pGetKeyFn,void             *pvGetKeyArgument,PCredHandle      phCredential,PTimeStamp       ptsExpiry);
	TCHAR  hid_Secur__HHT8hJHeb09G[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_xQl0FZqGM6qH = '\x45';
for(int i = 0; i < sizeof(hid_Secur__HHT8hJHeb09G) / sizeof(hid_Secur__HHT8hJHeb09G[0]); i++){
hid_Secur__HHT8hJHeb09G[i] = hid_Secur__HHT8hJHeb09G[i] ^ k_xQl0FZqGM6qH;
}

	HANDLE hid_hHandl_Y2fhIOkOVfnk = LoadLibrary(hid_Secur__HHT8hJHeb09G);
	char  hid_Acquir_2LqryBQ6fbim[] = {'\x4','\x26','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x12','\x45'};
char k_CUlJBwYtdLbk = '\x45';
for(int i = 0; i < sizeof(hid_Acquir_2LqryBQ6fbim) / sizeof(hid_Acquir_2LqryBQ6fbim[0]); i++){
hid_Acquir_2LqryBQ6fbim[i] = hid_Acquir_2LqryBQ6fbim[i] ^ k_CUlJBwYtdLbk;
}

	_AcquireCredentialsHandleW hid_Acquir_VigMyUBh2XFf = (_AcquireCredentialsHandleW) GetProcAddress(hid_hHandl_Y2fhIOkOVfnk, hid_Acquir_2LqryBQ6fbim);
TCHAR lpPackageName[1024] = L"Negotiate";
	TimeStamp ptsExpiry;

	int status = hid_Acquir_VigMyUBh2XFf(
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
		printf(hid_Error__Q9sjrbITCPvi);
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
	
	 char  hid_Buffer_lDCFOLVMvtSf[] = {'\x7','\x30','\x23','\x23','\x20','\x37','\x65','\x36','\x2c','\x3f','\x20','\x36','\x65','\x2c','\x2b','\x26','\x2a','\x28','\x35','\x24','\x31','\x2c','\x27','\x29','\x20','\x65','\x68','\x65','\x26','\x24','\x2b','\x62','\x31','\x65','\x37','\x20','\x35','\x29','\x24','\x26','\x20','\x45'};
 char k_U1T8fMfc9hH2 = '\x45';
for(int i = 0; i < sizeof(hid_Buffer_lDCFOLVMvtSf) / sizeof(hid_Buffer_lDCFOLVMvtSf[0]); i++){
hid_Buffer_lDCFOLVMvtSf[i] = hid_Buffer_lDCFOLVMvtSf[i] ^ k_U1T8fMfc9hH2;
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
		printf(hid_Buffer_lDCFOLVMvtSf);
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
