#pragma once

#ifndef MYDLL_EXPORT
#define DllExport __declspec(dllexport) 
#else
#define DllExport __declspec(dllimport)  
#endif