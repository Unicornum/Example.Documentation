
/**
* \page BuildCocos2d ������ Cocos2d ��� Android
*  
*  �������� �������
*  ----------------
*
* \pre
*  ��� ������ ��������� ������������� Android SDK, NDK � Apache Ant.
*
* \pre
*  ������ �������������:
*  - 21.10.2016
*  - Android SDK (Android Studio 2.1).
*  - Crystax-ndk-10.3.2
*  - apache-ant-1.9.7
*  - cocos2d-x-3.13.1
*  - python-2.7.12
*
*  \n
*  - ������� [Python], ���������� ��� � �������� ���� � ����� python.exe �
*  ���������� ��������� PATH (\b �����! Cocos2d ������� python ������ 2.7.x).
*  - ������� ����� � [Cocos2d] � ����������� ���.
*  - �� ������� � ����� Cocos2d (������ �� ������� ����� ��-�� ����, ���
*  ����������� ������ ���� � Android SDK, NDK � Apache Ant; ���� �����
*  �������������� ���������� ���������� ��������� \b ANDROID_SDK_ROOT,
*  \b NDK_ROOT � \b ANT_ROOT) ���������:
* \code

python setup.py

* \endcode
*  ����� ��������� ���������� ��������� ��� Cocos.
*  - � ������� (� �����, � ������� ����� ������� ������; \b �����! � ���� ��
*  ������ ���� ������� ����!) ��� ������ ���������� ���������:
* \code

cocos new Cocos2d -l cpp -d Cocos2dLib

* \endcode
*  - � ��������������� ����� Cocos2dLib\\Cocos2d ����������� ����������
*  [VSSolution].
*
*  ������� � ����� Cocos2dLib\\Cocos2d\\proj.visualstudio ����� ������� �
*  ������������ ��� �������� ����������.
*
*  ������ Cocos2d-x ��� ����������� ����������
*  -------------------------------------------
*
*  - � ����� Cocos2dLib\\Cocos2d\\proj.visualstudio ������� �������, � �������
*  \b Cocos2dcpp ������� ����� jni, ������ ���������� ���������� ��������� �
*  \b ���, �������� �������� �������:
*  
* \image html ".\Solution\Solution\(Documentation)\Cocos2dProps.png"
*  
*  � ������� Release � Debug ������.
*
* \warning
*  ����������� ���������� ����� ������� ����������, \b ��(!), ��-������
*  cpu-features ����� �������� ��� ��������� ���������� (� ������� �� �����
*  webp), ��-������ - ��� ���������� .so ����� � �������������� �����
*  ���������� �� �� ����������� �����, ��������� � �������������� ������������
*  ������������ (libOpenSLES.so, libEGL.so, libz.a), ��-�� ���� ����������
*  ���������� libz ����� ������� (� �������������� ����������, �������������
*  � libpng) � ���� ���������� ����������� ������� �������� ������� � ��
*  �������� ��� ������� �� Android-����������.
*  
*  ���������:
*  - [Cocos2dVSMicrosoft]
*  - [Cocos2dVsCocos]
*
*  [Cocos2d]: http://cocos2d-x.org/download "Cocos2d download"
*  [Python]: https://www.python.org/downloads/ "Python download"
*  [VSSolution]: https://github.com/Unicornum/Android/tree/master/Cocos2d/v3.13.1/Vs2015 "Visual Studio Cocos Solution"
*  [Cocos2dVSMicrosoft]: https://blogs.msdn.microsoft.com/vcblog/2016/07/12/cocos2d-x-visual-studio-android-project/ "������ �� ����� Microsoft"
*  [Cocos2dVsCocos]: http://cocos2d-x.org/docs/installation/Android-VisualStudio/ "������ �� ����� Cocos2d"
*/
