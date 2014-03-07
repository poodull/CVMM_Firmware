//Board = Arduino Mega 2560
#define ARDUINO 23
#define __AVR_ATmega2560__
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {}

//already defined in arduno.h
//already defined in arduno.h
void setTimerInterrupt();
void initializeDriverBoard();
void EnableSolenoids(bool enable);
void EnableSolenoids(uint8_t solenoidId, bool enable);
void solenoidFireImmediate(uint32_t solenoidId, bool state);
void writeBank(uint8_t bankId);
void initializeSwitches();
void sanityTest();
void initalizeSwitchArray();
void check_switches();
bool writeSwitchStatus();
uint8_t arrayToByte(uint8_t src[]);
void arrayToByteArray(volatile uint8_t src[], uint8_t srclength, uint8_t dest[]);
uint32_t* byteToArray(uint8_t in);
bool readCommand(uint8_t out[], uint8_t length);
void printTime();
uint8_t ParseCommand(uint8_t command[]);
void DebugPrint(String val);
void DebugPrintLn(String val);
void DebugPrintByte(uint8_t val);
void DebugPrintLnByte(uint8_t val);
void DebugPrintInt(uint32_t val);
void DebugPrintLnInt(uint32_t val);

#include "C:\Arduino\arduino-0023\hardware\arduino\cores\arduino\wprogram.h"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\CVMM_2.ino"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\Pins.ino"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\SolenoidManager.ino"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\SwitchManager.ino"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\aUtil.ino"
#include "C:\Users\fernando\Documents\Arduino\CVMM_2\zSerial.ino"
