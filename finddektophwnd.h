﻿#ifndef FINDDEKTOPHWND_H
#define FINDDEKTOPHWND_H
#include<qt_windows.h>
class QWidget;
class FindDektopHwnd
{
public:
    FindDektopHwnd();
    static BOOL CALLBACK EnumWindowsProc(_In_ HWND tophandle, _In_ LPARAM topparamhandle);
    static HWND GetDesktopHandle();

    static void SetParent(QWidget*child,HWND parent);

    inline static HWND _workerw = NULL;
};

#endif // FINDDEKTOPHWND_H
