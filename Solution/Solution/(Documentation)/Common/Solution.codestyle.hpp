
/**
* \page CodeStylePage ���������� ����
*
*  �������������� ����
*  -------------------
*
* ### ���� �������� AStyle ��� �������������� ����
*
* \include .\Solution\Externals\Utilities\CodeStyle\AStyle\AStyle.ini
*  
* \anchor IdentifiersAnchor
*
* ### ������� ���������� ���������������
*
* \code

class ClassName
class IInterfaceName
template<class TTemplateParam>
using Name_t = ...
  
ClassFunctionName
GlobalFunctionName
IsFunctionReturnBool
(*fnCallBackFunction)
  
m_ClassMemberVariable
_FunctionParamVariable
LocalVariable
IsBoolVariable
pPointerName
itIterator(ritReverseIterator)
iIndexValue
  
MemberEnum
Constant::ConstantVariable
FUCKING_DEFINE_MACROS

* \endcode
*
*  �����
*  -----
*
*  - ������������ RTTI ������������� � ������ ��� ��� ����������� ������
*  ���������.
*  - � �������� ����� ����� ������������ ����, ������������ � \<cstdint\> �
*  size_t.
*  - �� ������������ ����������� ���� ������, ����� ��� uint32_t (��
*  ����������� �����), ��������, ����� �������� ��� �������� ���������� ��
*  ����� ���� �������������. ��� ���� ���� ������������ assert��.
*  - ������������ assert(... && "message");
*  - ������������ ������� ������ � ������ ������� �������������, ������ \#undef
*  ����� ����� �������������.
*  - ��������� ������������� ������ ����� ������ ����� #.
*  - ��� �������� ���������� (debug � release ������, ��������) ������������
*  �� ��������� �����������, � "const bool debug = true;".
*  - ������ �������� � ��������� new[] ������������ std::vector.
*  - ������� � ����������� stl �� �������, � ��������� ��� shared_ptr'�.
*  - ������������ ������������� (i++) ������ ��� ������� �����, ��� ����������
*  � ��������� ����� - ++it.
*  - ��������� �� ������������ ���������� ��� ��������� (���� � ����������
*  �������).
*  - ��� enum'� ����������� � ����� (\ref Example1Anchor "������").
*  - ������������ ����� ������ ��������� ������ ����� ����������� ������� �
*  ����������� ������.
*  - ������������� ������������ ��������� ������ �� ������������ �������.
*  - �������� ������� (��������� ������) ����� ������ �� ������������,
*  � ������������ - �������� ��� ���������� (������� NVI).
*  - � �������� �������� ������� ������������ �������� ���������� � ���������
*  ����������, � �������� - assert��.
*  - ���������� ������������� ���������� ������� ����� ������� ���������
*  ���������. �� ����������� ����������� �������  ��� ������ �����������
*  ������� ��-�� ������� ������������� ���������� ����.
*  - ����������� ���������� ������ ������ "������������" � �������.
*  - �� ����������� ����������� ���������� ������ ������������
*  � ������������� ����.
*  - ���������� ������ ������ ���� ��������� � ������� ������� � ��� �� ������
*  ���� ������ ��� ��� ������ ���� ������ ���� (SetValue() \b ��� GetValue()).
*  - ��� �������� � ������� nullptr, boolean ��� ���������� ����� ��������
*  ������� �� �������������� ��� ������ ��������������������� ��� ���������
*  ��������� (\ref Example2Anchor "������").
*  - ���������� �� ������ ���������� ������� �������/���������.
*  - ��������������� ���� ����������� � ����� Doxygen.
*
*  ������������ �����
*  ------------------
*
*  - ������������ ����� ������ ����� ���������� .hpp.
*  - � ������ ������������� ����� ������� "#pragma once".
*  - �� ������������ \#include, ����� ���������� ���������������� ����������.
*  - ����������� ������ ������ ���������� � �������� �������, ����� ������ ����
*  ���������� ������� � ����������, ����� - ��������. ����� �������� �������
*  ������ ���� ��������� ������������ � �����������.
*  - ���������� ������������� �������� ������� ������ ���������� � ����� �����
*  ���������� ������.
*  - � ����������� ������� ��� ���������� ������ ����� ������� ������ void
*  (����� ��������� �������� ���������� ������� �� �� ������).
*  - � ������ ������������ ����� ������ ���� ������ ���� �������� (�����, �����
*  �������������, ��������� � �.�.).
*
*  ����� �����������
*  -----------------
*
*  - ����� ����������� ������ ����� ���������� .cpp (���� ����������� ���������
*  � inline-������� - .inl).
*  - ������� ���������� ������������ ������: ���������� C, ���������� C++, .hpp
*  ����� ������ ���������, .hpp ����� �������� �������.
*  - ����������� ���������� ������ ������ ���������� � ��������� .cpp �����.
*  - � .cpp ����� ������� ������ ���� ������������ � ����������, ����� ���
*  ��������� ������� � ������� �� ����������.
*  - � ����������� �������, ����������� ��� override (virtual, static) �������
* \code

int ClassName::GetValue(void) /*override*/
{
  // ...
}
  
/*static*/ void ClassName::DoProcess(void) 
{
  // ...
}

* \endcode
*  - � ����������� ������� ������� ������� �������, ����� �������� ���������.
*  - ���������, ���������� ����������� ������ ������� ������ ������������ ����� 
*  ���������(������ - ������ �����������!).
*  - ���������, ���������� ����������� ������ �������, ������ ���� �������� 
*  ������������ \b out
* \code

void GetValue(/*out*/ int * _pValue);

* \endcode
*  
*  ������� ���������� ����������/�������/�������/������
*  ----------------------------------------------------
*  
*  - ����� ���������� ������ ���� ����������������, ������� - 
*  ���������/���������.
*  - ����� ������ ������ ��������� � ������� ����������� � ��� ������� (������� 
*  ������������ ����).
*  - \ref IdentifiersAnchor "������� ���������� ���������������".
*  
*  ������������ ����
*  -----------------
*  
*  - ������ ��������� ������ ��������� ������ ����� ���� ������������ ����.
*  - �� ������������ ��������� using namespace ��� �������.
*  - ������������ ���� ������ ����������� ������������ "} // namespace <name>".
*  - ��� ������ ������������ ���� ������ ���� �� ������ ����.
*  - ������ ����������� �������� ������������ ��������� � �� ����������� 
*  ������������� ���� (������������ �� � ������������ ������ ������ ��� 
*  ���������� ��������!).
*  
*  ������������/�����������
*  ------------------------
*  
*  - ������ ����� ������� ���������� ����������� �� ���������, ������������ 
*  ���������� ���������� ������.
*  - ������������ �������� ����� explicit ��� ������������� � ����� ����������.
*  - ���� ����� �� ����� ������ ������������ �����������, ����������� ��� �� 
*  boost::noncopyable.
*  - ����������� ������ ����� ������� ��������� noexcept.
*  
*  �������
*  =======
*  
* \anchor Example1Anchor
*  
*  ������ 1: ������������
*  ----------------------
*  
* \code

// ����������:
class Status
{
public:
  enum Value : size_t
  {
    Unknown = 0,
    Play,
    Pause,
    Stop,
      
    Illegal
  };
};
  
// �������������
Status::Value CurrentStatatus = Status::Stop;

* \endcode
*  
*  ������ 2: ���������
*  -------------------
*  
* \code

namespace 
{
  
// ����������
template<class T>
class Constant final
{
public:
  static constexpr T PI = static_cast<T>(math::PI);
};
  
} // unnamed namespace
  
// �������������
auto DoublePI = 2.0f * Constant<float>::PI;

* \endcode
*  
* \anchor Example2Anchor
*
*  ������ 3: ���������� ����������
*  -------------------------------
*  
* \code

const bool IsSsuccess = CalculateSomething(InterestingValue,
  10,
  false,
  NULL); // ��� �������� ��� ��� ���������??

* \endcode
*  
*  ������:
*  
* \code

const bool IsSuccess = CalculateSomething(InterestingValue,
  10,       // ������� �������� �� ���������
  false,    // ������� ���������� �� � ������ ���.
  nullptr); // ��� ���������� �������.

* \endcode
*  
*  ���, � �������� ������������, ��������� ��������� ��� ����-����������� ����������:
*  
* \code

const int DefaultBaseValue = 10;
const bool IsFirstTimeCalling = false;
Callback * fnNullCallback = nullptr;
  
const bool IsSuccess = CalculateSomething(InterestingValue,
  DefaultBaseValue,
  IsFirstTimeCalling,
  fnNullCallback);

* \endcode
*  
*  ��� ��������
*  ============
*  
*  - ������� � ������ ������������� ���������� � ������������ ������� ����� 
*  ����������.
*  - ������ \<iostream\> � ������������ ������ ������ \<iosfwd\> ��� ��������� 
*  ����������.
*  - ��� �������� ����������� ������� ����� - ������(�� ������ � ������), 
*  ������������ ������� ������ .rdbuf() (cout << file.rdbuf()).
*  - � ������� ������� std::uncaught_exception ����� ���������, ��� ��������� 
*  ������ �������: ��� ���������� ������� ��� ���� ��������� ����������.
*  - ���������������� ��� ����� � ��������� ������ � ������������� ��� 
*  ������������� ����� ������� ����������� ����������(�round�, �floor�, �ceil� 
*  � �.�.)
*  - ��� ������������� ���������� ������������ ������ ������������� (��� �� 
*  ��������� ������� �����: int x1 = { 7.3 }; //compilation error).
*  - ��������� �� ����� ����������, ����� inline ������� �� ������ ���� 
*  �������������!
*  - ������ ������� � ��������� ����� (�����.cpp).
*  - ���������� �� ������ �������� ���������� (�������� ��� �������� ������ 
*  � ������������ STL).
*  - ��� ������ ������������� ������� swap() (��� ������ ���� ����������!), 
*  ������� ����� ������������ ��� ������������ �� �������� ���������� 
*  ������������ (��� ����������� ����� ������������ std::swap())
* \code

T & T::operator= (T Temp) // �� ��������!
{
  swap(Temp);
  return *this;
}

* \endcode
*  - ��� ���������������� ������ �������� ����� ������������ ��������� 
*  ����������, ���������� ��������� �� �������� ���������.
*  - ��� ���������� ��������� � ��������� ���������������� ������������ �������� 
*  � �����������.
*  - container<T>(c).swap(c); // �������� ���� ������ (�����������������) 
*  ������� ����������.
*  - container<T>().swap(c); // �������� ���� ��������� � ������� ������ 
*  ����������.
*  - find / find_if � count / count_if - ����� � ����������������� ���������.
*  - lower_bound, upper_bound, equal_range(���� binary_search) - ����� 
*  � ��������������� ���������.
*  - �������������� ������� ������ ��������� ����������� operator().
*  - �������� ��������� �������� � ��������� ���.
*/