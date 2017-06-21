
/**
* \page BuildBoost ������ Boost ��� Android
*  
*  ������ ��� ������ gcc
*  ---------------------
*  
* \note
*  ������ �������������:
*  - 3.05.2017.
*  - crystax-ndk-10.3.2.
*  - Boost 1.64.
*  
*  ������:
*  - � ����� \$(BoostRoot) ��������� bootstrap.bat (����� �������� ���� b2.exe).
*  - � ����� \$(BoostRoot)/tools/build/src ������� ���� � ������
*  user-config.jam, ���������� (��� ������������� �������� ���� � ANDROID_NDK �
*  ������ ANDROID_API):
* \include ".\Solution\(Documentation)\user-config.jam"
*  
*  - � ����� \$(BoostRoot) ������� � ��������� �� ���������� ���� 
*  BuildAndroid.cmd (��� ������������� �������� ���� � ANDROID_NDK � ����������
*  icu):
* \include ".\Solution\(Documentation)\BuildAndroid.cmd"
*  
*  - ��������� ���������� ����� � ����� \$(BoostRoot)/android/lib.
*  
* \warning
*  ����� ������� ������� �� ����� ��������� ���������� Boost.Locale, �.�. 
*  ������� Boost �� ������ ������� ���� 
*  \$(BoostRoot)/libs/locale/build/has_icu_test.cpp (� ��� ��������, ������,
*  ���� ������, ��� ��� ������ ����� ����� �� ������������ ��������� ��
*  user-config.jam, � ������������ ��������� �� ���������); ��� ����, �����
*  ������� Boost.Locale, ����� � ����� \$(BoostRoot)/bin.v2/project-cache.jam
*  �������� \b false �� \b true � ������
* \code

set "icu-<address-model>32-<architecture>arm-<target-os>linux-<toolset-clang:version>android-<toolset>clang" : "false" ;

* \endcode
*  ����� ���� ��������� ������ BuildAndroid.cmd ��� ���.
*  
* \note
*  �� ���� ������ ���� ������������ ����� \b clang, ���� ������ ������������ 
*  ��� ������ \b gcc. ��� ��-�� ����, ���, ������� � ������ 1.61, ������
*  ���������� ��� ��������� ����� user-config.jam, ���������� 
*  "using gcc : android :", ������ ������ ��������.
*
*  ������ ��� ������ Clang
*  -----------------------
*  
* \note
*  ������ �������������:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.61.
*  
*  ������:
*  - � ����� \$(BoostRoot) ��������� bootstrap.bat.
*  - � ����� \$(BoostRoot) ������� � ��������� �� ���������� ���� 
*  BuildAndroid.cmd, ���������� (\b ANDROID_NDK ������ ���� � (�������!) 
*  ANDROID NDK, \b RESULT - � '����������' ����� ���� ��������� ���������):
* \code
  
set ANDROID_NDK=d:/android/ndk
set RESULT=./stage/lib/libboost.a
  
rmdir bin.v2 /s /q
rmdir stage /s /q
  
set PATH=%PATH%;%ANDROID_NDK%/toolchains/llvm/prebuilt/windows/bin;%ANDROID_NDK%/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/arm-linux-androideabi/bin;
  
b2 toolset=clang-linux target-os=android link=static runtime-link=static -j 4 ^
--without-python ^
cxxflags="-target armv7a-linux-android" ^
cxxflags="--sysroot=%ANDROID_NDK%/platforms/android-15/arch-arm" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/include" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/include" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/include/backward" ^
cxxflags="-std=c++1y -frtti -fexceptions -fshort-wchar -O3 -g0" ^
cxxflags="-DNDEBUG -D__ANDROID__ -D__SOFTFP__ -D__arm__ -DBOOST_FILESYSTEM_VERSION=3"
  
set OUT_TMP_DIR=out_tmp_arm
  
rmdir %OUT_TMP_DIR% /s /q
mkdir %OUT_TMP_DIR%
cd %OUT_TMP_DIR%
  
FOR %%f in (..\stage\lib\*) DO ar xv %%f
  
cd ..
  
ar qv %RESULT% %OUT_TMP_DIR%/*.o
  
* \endcode
*  - ��������� ���������� ����� � ����� \$(BoostRoot)/stage/lib.
*/
