
/**
* \page BuildBoost ������ Boost ��� Android
*  
*  ������ ��� ������ Clang
*  -----------------------
*  
*  - � ����� \$(BoostRoot) ��������� bootstrap.bat.
*  - � ����� \$(BoostRoot) ������� ���� BuildAndroid.cmd, ����������
*  (\b ANDROID_NDK ������ ���� � (�������!) ANDROID NDK, \b RESULT - � '����������'
*  ����� ���� ��������� ���������):
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
*  � ��������� ��� �� ����������.
*  - ��������� ���������� ����� � ����� \$(BoostRoot)/stage/lib.
*  
* \note
*  ������ �������������:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.61.
*  
*  ������ ��� ������ gcc
*  ---------------------
*
*  - � ����� \$(BoostRoot)/tools/build/src ������� ���� � ������ 
*  user-config.jam, ���������� (�������� ���� � Android NDK ��� �������������):
* \code

ANDROID_NDK = d:/android/ndk ;

using gcc : android : $(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-g++ :
<compileflags>--sysroot=$(ANDROID_NDK)/platforms/android-15/arch-arm
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/include
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/include
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/include/backward
<compileflags>-o
<compileflags>-xc++-header
<compileflags>-xc++
<compileflags>-std=c++1y
<compileflags>-fexceptions
<compileflags>-O3
<compileflags>-DNDEBUG
<compileflags>-D__ANDROID__
<compileflags>-D__SOFTFP__
<compileflags>-D__arm__
<compileflags>-g2
<compileflags>-lstdc++
<compileflags>-D__GLIBC__
<compileflags>-DBOOST_FILESYSTEM_VERSION=3
<linkflags>-r"s"
<archiver>$(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-ar
<ranlib>$(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-ranlib
;

* \endcode
*  - � ����� \$(BoostRoot) ��������� bootstrap.bat.
*  - � ����� \$(BoostRoot) ������� ���� BuildAndroid.cmd, ����������:
* \code

b2 --without-python --without-thread toolset=gcc-android target-os=linux threading=multi link=static runtime-link=static -j 4

* \endcode
*  � ��������� ��� �� ����������.
*  - ��������� ���������� ����� � ����� \$(BoostRoot)/stage/lib.
*  
* \note
*  ������ �������������:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.60.
*
* \warning
*  ��� Boost 1.61 ������ ��� ������ gcc �� ��������, b2.exe ��� ������� ������
*  ����� ���� ������� �������� ����������.
*/
