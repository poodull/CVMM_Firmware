/* 
	Editor: http://www.visualmicro.com
	        arduino debugger, visual micro +, free forum and wiki
	        both visualmicro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Due (Programming Port), Platform=sam, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __SAM3X8E__
#define USB_VID 0x2341
#define USB_PID 0x003e
#define USBCON
#define USB_MANUFACTURER "\"Unknown\""
#define USB_PRODUCT "\"Arduino Due\""
#define ARDUINO 155
#define ARDUINO_MAIN
#define printf iprintf
#define __SAM__
#define __sam__
#define F_CPU 84000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __ICCARM__
#define __ASM
#define __INLINE
#define __GNUC__ 0
#define __ICCARM__
#define __ARMCC_VERSION 400678
#define __attribute__(noinline)

#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}




//
//
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
uint32_t boardFreqHz();
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

#include "C:\Program Files (x86)\Arduino\hardware\arduino\sam\cores\arduino\arduino.h"
#include "C:\Program Files (x86)\Arduino\hardware\arduino\sam\variants\arduino_due_x\pins_arduino.h" 
#include "C:\Program Files (x86)\Arduino\hardware\arduino\sam\variants\arduino_due_x\variant.h" 
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\CVMM.ino"
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\Pins.ino"
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\SolenoidManager.ino"
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\SwitchManager.ino"
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\aUtil.ino"
#include "C:\Users\Fernando\Dropbox\GitHub\fcucci\CVMM_3\zSerial.ino"
#endif
