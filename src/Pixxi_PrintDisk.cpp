#if (ARDUINO >= 100)
  #include "Arduino.h" // for Arduino 1.0
#else
  #include "WProgram.h" // for Arduino 23
#endif

#include "Pixxi_Serial_4DLib.h"
#include "Pixxi_Const4D.h"

void PrintDisk(Pixxi_Serial_4DLib Display, word hndl, long offset, word msglen, word msgid)
{
  char ch ;
  long res ;
  res = (long)msglen * msgid ;
  res += offset ;
  Display.file_Seek(hndl, res >> 16, res & 0xffff);
  do
  {
    ch = Display.file_GetC(hndl) ;
    Display.putCH(ch) ;
  }
  while (ch != 0) ;
}

void PrintDiskUnicode(Pixxi_Serial_4DLib Display, word hndl, long offset, word msglen, word msgid)
{
  word ch ;
  long res ;
  res = (long)msglen * msgid ;
  res += offset ;
  Display.file_Seek(hndl, res >> 16, res & 0xffff);
  do
  {
    ch = Display.file_GetW(hndl) ;
    Display.putCH(ch) ;
  }
  while (ch != 0) ;
}

