// 1. Search for:

PyObject* netSetLoginInfo(PyObject* poSelf, PyObject* poArgs)

// 1. Change like this:

PyObject* netSetLoginInfo(PyObject* poSelf, PyObject* poArgs)
{
	char* szName;
	if (!PyTuple_GetString(poArgs, 0, &szName))
		return Py_BuildException();

	char* szPwd;
	if (!PyTuple_GetString(poArgs, 1, &szPwd))
		return Py_BuildException();

#ifdef __PIN_CODE_HAKYZZ__
	char* szPin;
	if (!PyTuple_GetString(poArgs, 2, &szPin))
		return Py_BuildException();
#endif

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	CAccountConnector & rkAccountConnector = CAccountConnector::Instance();
	rkNetStream.SetLoginInfo(szName, szPwd
#ifdef __PIN_CODE_HAKYZZ__
		, szPin
#endif
	);
	rkAccountConnector.SetLoginInfo(szName, szPwd
#ifdef __PIN_CODE_HAKYZZ__
		, szPin
#endif
	);
	return Py_BuildNone();
}