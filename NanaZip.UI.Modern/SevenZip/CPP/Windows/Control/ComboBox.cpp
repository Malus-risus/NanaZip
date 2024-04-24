// Windows/Control/ComboBox.cpp

#include "StdAfx.h"
#include "OSVersion.h"
#include "ComboBox.h"

namespace NWindows {
namespace NControl {

LRESULT CComboBox::GetLBText(int index, CSysString &s)
{
  s.Empty();
  LRESULT len = GetLBTextLen(index); 
  if (len == CB_ERR)
    return CB_ERR;
  LRESULT len2 = GetLBText(index, s.GetBuf((unsigned)len));
  if (len2 == CB_ERR)
    return CB_ERR;
  if (len > len2)
    len = len2;
  s.ReleaseBuf_CalcLen((unsigned)len);
  return len;
}

#ifndef _UNICODE
LRESULT CComboBox::AddString(LPCWSTR s)
{
  if (g_IsNT)
    return SendMsgW(CB_ADDSTRING, 0, (LPARAM)s);
  return AddString(GetSystemString(s));
}

LRESULT CComboBox::GetLBText(int index, UString &s)
{
  s.Empty();
  if (g_IsNT)
  {
    LRESULT len = SendMsgW(CB_GETLBTEXTLEN, MY__int_TO_WPARAM(index), 0);
    if (len == CB_ERR)
      return CB_ERR;
    LRESULT len2 = SendMsgW(CB_GETLBTEXT, MY__int_TO_WPARAM(index), (LPARAM)s.GetBuf((unsigned)len));
    if (len2 == CB_ERR)
      return CB_ERR;
    if (len > len2)
      len = len2;
    s.ReleaseBuf_CalcLen((unsigned)len);
    return len;
  }
  AString sa;
  LRESULT len = GetLBText(index, sa);
  if (len == CB_ERR)
    return CB_ERR;
  s = GetUnicodeString(sa);
  return s.Len();
}
#endif

}}
