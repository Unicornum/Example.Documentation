
/**
* \page ExternalsWindowsPage ���������� ��� Windows
*  
*  Boost
*  -----
*  �������� ��������: [Boost](http://www.boost.org/).
*
*  ���������� ���� ��������� ���������:
* \code

bootstrap.bat
b2.exe

* \endcode
*  ���������� ������ ������ ���������:
* \code

bootstrap.bat
b2.exe --build-type=minimal msvc stage --with-filesystem

* \endcode
*  ���������� ��� ���������� ������ Visual Studio:
* \code

// ��� VS2008
bootstrap.bat vc9
b2.exe toolset=msvc-9.0

* \endcode
*  [���������� ��� x64](http://devsql.blogspot.ru/2007/05/building-boost-134-for-x86-x64-and-ia64.html).
*
* ### �������� � DLL, ����������� �� ���� MFC
*  ����������� ��� assert'� � ������ dllinit.cpp � dllmodul.cpp ��� �������� DLL.
*
*  ��� ������� ��������, ���������������� � �����
*  ./libs/thread/src/win32/tss_pe.cpp ������
* \code

// extern BOOL (WINAPI * const _pRawDllMain)(HANDLE, DWORD, LPVOID)=&dll_callback;

* \endcode
*  � ����������� lib'�. ����� ����� ����� ��� �������� ���������� �������
* \code

#include <boost/thread/detail/tss_hooks.hpp>
on_process_exit();

* \endcode
*
*  Poco
*  ----
*  �������� �������� [Poco](http://pocoproject.org/).
*
*  ### ����������
*  ������������� buildwin.cmd:
* \include "Solution\Externals\Externals\Poco\Build.txt"
*  ��� ���������� ��� ���������� ���������� ������� ������ ������� � �����
*  Foundation, � ��������� ������� � ������� "C\C++" �������� "������
*  ���������� ������" ���������� � "���".
*
*  wxWidgets
*  ---------
*  �������� ��������: [wxWidgets](https://www.wxwidgets.org/).
*
*  ### ���������� ��� Windows
*  - ������� [�����������](http://www.wxwidgets.org/downloads/).
*  - ���������� ����������.
*  - ������� ������� ��� ������ ������ Visual Studio � ����� build\\msw.
*  - ��������� UniCA (����� ��� �� ���������� Version.rc) � ������� ��� �������
*  (��������� ���������� ����� � ����� lib).
*  - �� ������������ ���������� �������� � Lib.props (�������� "������������
*  ���������� � ������� ����������� -> ����).
*
*  ### �������� ������
*  -# [������� �����](http://wx.cdelta.org/).
*  -# [���������� �������� ����](http://sourceforge.net/projects/wxformbuilder/).
*
*  Crypto++
*  --------
*  �������� �������� [Crypto++](https://www.cryptopp.com/)
*
*  ### ���������� ��� Windows
*  - ������� �����, ����������� ��� � ������� ������� cryptest.sln.
*  - � ��������� ������� cryptlib C\\C++ -> ����� -> ������ ���������� ����������
*  �������� � \b ���, � C\\C++ -> �������� ���� -> ���������� ������� ����������
*  - � '������������� (�������) DLL'.
*  - ������� ������ ������������.
*/
