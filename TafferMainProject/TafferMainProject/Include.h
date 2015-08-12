#pragma once
#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <Windows.h>
#include <tchar.h>
#include <gl\GL.h>
#include <gl\GLU.h>

HWND g_hWnd = NULL;
HDC g_hDC = NULL;
HGLRC g_hRC = NULL;

static TCHAR szWindowClass[] = _T("SeregaApp");

static TCHAR szTitle[] = _T("Serega Application");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CreateOpenGLContext(void);
#endif