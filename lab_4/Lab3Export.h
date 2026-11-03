#ifndef LAB3EXPORT_H
#define LAB3EXPORT_H

#ifdef LAB3_BUILD_DLL // собираем динамическую библиотеку
#define LAB3_API __declspec(dllexport) // экспортирует классы и функции из DLL
#elif defined(LAB3_USE_DLL) // сообщает, что программа использует DLL
#define LAB3_API __declspec(dllimport) // позволяет программе импортировать классы и функции из DLL
#else
#define LAB3_API
#endif

#endif