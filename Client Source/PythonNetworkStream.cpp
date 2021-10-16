// 1. Search for:

void CPythonNetworkStream::SetLoginInfo(const char* c_szID, const char* c_szPassword)

// 1. Change like this:

void CPythonNetworkStream::SetLoginInfo(const char* c_szID, const char* c_szPassword
#ifdef __PIN_CODE_HAKYZZ__
	, const char* c_szPin
#endif
)
{
	m_stID=c_szID;
	m_stPassword=c_szPassword;
#ifdef __PIN_CODE_HAKYZZ__
	m_stPin = c_szPin;
#endif
}

// 2. Search for:

void CPythonNetworkStream::ClearLoginInfo( void )

// 2. Change like this:

void CPythonNetworkStream::ClearLoginInfo( void )
{
	m_stPassword = "";
#ifdef __PIN_CODE_HAKYZZ__
	m_stPin = "";
#endif
}