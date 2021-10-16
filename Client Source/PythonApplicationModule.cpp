// 1. Search for:

PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);

// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	PyModule_AddIntConstant(poModule, "__PIN_CODE_HAKYZZ__", 1);
#else
	PyModule_AddIntConstant(poModule, "__PIN_CODE_HAKYZZ__", 0);
#endif