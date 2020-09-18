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
	
	 char  hid_Error__hEIbUjtmr6FD[] = {'\x0','\x37','\x37','\x2a','\x37','\x65','\x2c','\x2b','\x65','\x4','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x45'};
 char k_e3EwWyuPkksb = '\x45';
for(int i = 0; i < sizeof(hid_Error__hEIbUjtmr6FD) / sizeof(hid_Error__hEIbUjtmr6FD[0]); i++){
hid_Error__hEIbUjtmr6FD[i] = hid_Error__hEIbUjtmr6FD[i] ^ k_e3EwWyuPkksb;
}
	typedef SECURITY_STATUS(__stdcall* _AcceptSecurityContext)(PCredHandle phCredential, PCtxtHandle phContext, PSecBufferDesc pInput, unsigned long fContextReq, unsigned long TargetDataRep, PCtxtHandle phNewContext, PSecBufferDesc pOutput, unsigned long *pfContextAttr, PTimeStamp ptsExpiry);
	TCHAR  hid_Secur__hPIOxoGtHJzx[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_zewbWQq5g5hp = '\x45';
for(int i = 0; i < sizeof(hid_Secur__hPIOxoGtHJzx) / sizeof(hid_Secur__hPIOxoGtHJzx[0]); i++){
hid_Secur__hPIOxoGtHJzx[i] = hid_Secur__hPIOxoGtHJzx[i] ^ k_zewbWQq5g5hp;
}

	HMODULE hid_hHandl_sqpueW9UrvOn = LoadLibrary(hid_Secur__hPIOxoGtHJzx);
	char  hid_Accept_4pcTs3DYoSez[] = {'\x4','\x26','\x26','\x20','\x35','\x31','\x16','\x20','\x26','\x30','\x37','\x2c','\x31','\x3c','\x6','\x2a','\x2b','\x31','\x20','\x3d','\x31','\x45'};
char k_mYvQ10KvtPa8 = '\x45';
for(int i = 0; i < sizeof(hid_Accept_4pcTs3DYoSez) / sizeof(hid_Accept_4pcTs3DYoSez[0]); i++){
hid_Accept_4pcTs3DYoSez[i] = hid_Accept_4pcTs3DYoSez[i] ^ k_mYvQ10KvtPa8;
}

	_AcceptSecurityContext hid_Accept_ReE3YEuFZ0gU = (_AcceptSecurityContext) GetProcAddress(hid_hHandl_sqpueW9UrvOn, hid_Accept_4pcTs3DYoSez);
	typedef SECURITY_STATUS(__stdcall* _AcquireCredentialsHandleW)(LPWSTR pPrincipal,LPWSTR pPackage,unsigned long fCredentialUse,void *pvLogonId,void *pAuthData,SEC_GET_KEY_FN pGetKeyFn,void *pvGetKeyArgument,PCredHandle phCredential,PTimeStamp ptsExpiry);
	TCHAR  hid_Secur__UC7jQGcQvg6Z[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_pMl9iIjL6UsA = '\x45';
for(int i = 0; i < sizeof(hid_Secur__UC7jQGcQvg6Z) / sizeof(hid_Secur__UC7jQGcQvg6Z[0]); i++){
hid_Secur__UC7jQGcQvg6Z[i] = hid_Secur__UC7jQGcQvg6Z[i] ^ k_pMl9iIjL6UsA;
}

	HMODULE hid_hHandl_WUEHhNPttJWv = LoadLibrary(hid_Secur__UC7jQGcQvg6Z);
	char  hid_Acquir_5w3fEGR9qgso[] = {'\x4','\x26','\x34','\x30','\x2c','\x37','\x20','\x6','\x37','\x20','\x21','\x20','\x2b','\x31','\x2c','\x24','\x29','\x36','\xd','\x24','\x2b','\x21','\x29','\x20','\x12','\x45'};
char k_qmPg4zWpnMSb = '\x45';
for(int i = 0; i < sizeof(hid_Acquir_5w3fEGR9qgso) / sizeof(hid_Acquir_5w3fEGR9qgso[0]); i++){
hid_Acquir_5w3fEGR9qgso[i] = hid_Acquir_5w3fEGR9qgso[i] ^ k_qmPg4zWpnMSb;
}

	_AcquireCredentialsHandleW AcquireCredentialsHandle = (_AcquireCredentialsHandleW) GetProcAddress(hid_hHandl_WUEHhNPttJWv, hid_Acquir_5w3fEGR9qgso);
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
		printf(hid_Error__hEIbUjtmr6FD);
		return -1;
	}

	InitTokenContextBuffer(&secClientBufferDesc, &secClientBuffer);
	InitTokenContextBuffer(&secServerBufferDesc, &secServerBuffer);

	phContext = new CtxtHandle();

	secClientBuffer.cbBuffer = static_cast<unsigned long>(len);
	secClientBuffer.pvBuffer = ntlmBytes;

	ULONG fContextAttr;
	TimeStamp tsContextExpiry;

	status = hid_Accept_ReE3YEuFZ0gU(
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
	
	 char  hid_Buffer_BwecQ9Pah8BM[] = {'\x7','\x30','\x23','\x23','\x20','\x37','\x65','\x36','\x2c','\x3f','\x20','\x36','\x65','\x2c','\x2b','\x26','\x2a','\x28','\x35','\x24','\x31','\x2c','\x27','\x29','\x20','\x65','\x68','\x65','\x26','\x24','\x2b','\x62','\x31','\x65','\x37','\x20','\x35','\x29','\x24','\x26','\x20','\x45'};
 char k_YfqA76fuvpPw = '\x45';
for(int i = 0; i < sizeof(hid_Buffer_BwecQ9Pah8BM) / sizeof(hid_Buffer_BwecQ9Pah8BM[0]); i++){
hid_Buffer_BwecQ9Pah8BM[i] = hid_Buffer_BwecQ9Pah8BM[i] ^ k_YfqA76fuvpPw;
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
		printf(hid_Buffer_BwecQ9Pah8BM);
	}

	return 0;
}

int LocalNegotiator::handleType3(char * ntlmBytes, int len)
{
		typedef SECURITY_STATUS(__stdcall* _AcceptSecurityContext)(PCredHandle phCredential, PCtxtHandle phContext, PSecBufferDesc pInput, unsigned long fContextReq, unsigned long TargetDataRep, PCtxtHandle phNewContext, PSecBufferDesc pOutput, unsigned long *pfContextAttr, PTimeStamp ptsExpiry);
	TCHAR  hid_Secur__lj6AqHCThQ6X[] = {'\x16','\x20','\x26','\x30','\x37','\x76','\x77','\x6b','\x21','\x29','\x29','\x45'};
TCHAR k_GW3fSsg04Of3 = '\x45';
for(int i = 0; i < sizeof(hid_Secur__lj6AqHCThQ6X) / sizeof(hid_Secur__lj6AqHCThQ6X[0]); i++){
hid_Secur__lj6AqHCThQ6X[i] = hid_Secur__lj6AqHCThQ6X[i] ^ k_GW3fSsg04Of3;
}

	HMODULE hid_hHandl_7WxTxT7qTbLi = LoadLibrary(hid_Secur__lj6AqHCThQ6X);
	char  hid_Accept_WBjtyO0mo0CO[] = {'\x4','\x26','\x26','\x20','\x35','\x31','\x16','\x20','\x26','\x30','\x37','\x2c','\x31','\x3c','\x6','\x2a','\x2b','\x31','\x20','\x3d','\x31','\x45'};
char k_NdsLqox3Zq2C = '\x45';
for(int i = 0; i < sizeof(hid_Accept_WBjtyO0mo0CO) / sizeof(hid_Accept_WBjtyO0mo0CO[0]); i++){
hid_Accept_WBjtyO0mo0CO[i] = hid_Accept_WBjtyO0mo0CO[i] ^ k_NdsLqox3Zq2C;
}

	_AcceptSecurityContext hid_Accept_usv1wFe7fjJ7 = (_AcceptSecurityContext) GetProcAddress(hid_hHandl_7WxTxT7qTbLi, hid_Accept_WBjtyO0mo0CO);
InitTokenContextBuffer(&secClientBufferDesc, &secClientBuffer);
	InitTokenContextBuffer(&secServerBufferDesc, &secServerBuffer);

	secClientBuffer.cbBuffer = static_cast<unsigned long>(len);
	secClientBuffer.pvBuffer = ntlmBytes;

	ULONG fContextAttr;
	TimeStamp tsContextExpiry;
	int status = hid_Accept_usv1wFe7fjJ7(
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
