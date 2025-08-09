/*--------------------------------------------------------------------------
SN8F5702.H

Header file for SNOiX SN8F5702 microcontroller.
Copyright (c) 2015 SONiX Technology Co., Ltd.

Version 1.0    2015-02-13
Version 1.3    2015-09-09
Version 1.7    2015-10-14
--------------------------------------------------------------------------*/

#ifndef __SN8F5702_H__
#define __SN8F5702_H__

/*      Register      */
__sfr    __at (0x80)   P0;
  __sbit __at (0x80+7) P07;
  __sbit __at (0x80+6) P06;
  __sbit __at (0x80+5) P05;
  __sbit __at (0x80+4) P04;
  __sbit __at (0x80+3) P03;
  __sbit __at (0x80+2) P02;
  __sbit __at (0x80+1) P01;
  __sbit __at (0x80+0) P00;
__sfr    __at (0x81)   SP;
__sfr    __at (0x82)   DPL;
__sfr    __at (0x83)   DPH;
__sfr    __at (0x86)   WDTR;
__sfr    __at (0x87)   PCON;
__sfr    __at (0x88)   TCON;
  __sbit __at (0x88+7) TF1;
  __sbit __at (0x88+6) TR1;
  __sbit __at (0x88+5) TF0;
  __sbit __at (0x88+4) TR0;
  __sbit __at (0x88+3) IE1;
  __sbit __at (0x88+1) IE0;
__sfr    __at (0x89)   TMOD;
__sfr    __at (0x8A)   TL0;
__sfr    __at (0x8B)   TL1;
__sfr    __at (0x8C)   TH0;
__sfr    __at (0x8D)   TH1;
__sfr    __at (0x8E)   CKCON;
__sfr    __at (0x8F)   PEDGE;
__sfr    __at (0x90)   P1;
  __sbit __at (0x90+7) P17;
  __sbit __at (0x90+6) P16;
  __sbit __at (0x90+5) P15;
  __sbit __at (0x90+4) P14;
  __sbit __at (0x90+3) P13;
  __sbit __at (0x90+2) P12;
  __sbit __at (0x90+1) P11;
  __sbit __at (0x90+0) P10;
__sfr    __at (0x91)   P1W;
__sfr    __at (0x93)   DPC;
__sfr    __at (0x94)   PECMD;
__sfr16 __at(((0x95+1U)<<8) | 0x95) PEROM;
__sfr    __at (0x95)   PEROML;
__sfr    __at (0x96)   PEROMH;
__sfr    __at (0x97)   PERAM;
__sfr    __at (0x98)   S0CON;
  __sbit __at (0x98+7) SM0;
  __sbit __at (0x98+6) SM1;
  __sbit __at (0x98+5) SM20;
  __sbit __at (0x98+4) REN0;
  __sbit __at (0x98+3) TB80;
  __sbit __at (0x98+2) RB80;
  __sbit __at (0x98+1) TI0;
  __sbit __at (0x98+0) RI0;
__sfr    __at (0x99)   S0BUF;
__sfr    __at (0x9A)   IEN2;
__sfr    __at (0x9D)   P0CON;
__sfr    __at (0x9E)   P2CON;
__sfr    __at (0xA0)   P2;
  __sbit __at (0xA0^1) P21;
  __sbit __at (0xA0^0) P20;
__sfr    __at (0xA8)   IEN0;
  __sbit __at (0xA8+7) EAL;
  __sbit __at (0xA8+5) ET2;
  __sbit __at (0xA8+4) ES0;
  __sbit __at (0xA8+3) ET1;
  __sbit __at (0xA8+1) ET0;
  __sbit __at (0xA8+0) EX0;
__sfr    __at (0xA9)   IP0;
__sfr    __at (0xAA)   S0RELL;
__sfr    __at (0xAB)   PW1M;
__sfr16 __at(((0xAC+1U)<<8) | 0xAC) PW1Y;
__sfr    __at (0xAC)   PW1YL;
__sfr    __at (0xAD)   PW1YH;
__sfr16 __at(((0xAC+1U)<<8) | 0x95) PW1B;
__sfr    __at (0xAE)   PW1BL;
__sfr    __at (0xAF)   PW1BH;
__sfr    __at (0xB8)   IEN1;
  __sbit __at (0xB8+7) ET2RL;
  __sbit __at (0xB8+5) ET2C3;
  __sbit __at (0xB8+4) ET2C2;
  __sbit __at (0xB8+3) ET2C1;
  __sbit __at (0xB8+2) ET2C0;
  __sbit __at (0xB8+1) ESPI;
  __sbit __at (0xB8+0) EI2C;
__sfr    __at (0xB9)   IP1;
__sfr    __at (0xBA)   S0RELH;
__sfr16 __at(((0xBB+1U)<<8) | 0xBB) PW1D;
__sfr    __at (0xBB)   PW1DL;
__sfr    __at (0xBC)   PW1DH;
__sfr    __at (0xBD)   PW1A;
__sfr    __at (0xBE)   PW1CH;
__sfr    __at (0xBF)   IRCON2;
__sfr    __at (0xC0)   IRCON;
  __sbit __at (0xC0+7) TF2RL;
  __sbit __at (0xC0+6) TF2;
  __sbit __at (0xC0+5) TF2C3;
  __sbit __at (0xC0+4) TF2C2;
  __sbit __at (0xC0+3) TF2C1;
  __sbit __at (0xC0+2) TF2C0;
__sfr    __at (0xC1)   CCEN;
__sfr    __at (0xC2)   CCL1;
__sfr    __at (0xC3)   CCH1;
__sfr    __at (0xC4)   CCL2;
__sfr    __at (0xC5)   CCH2;
__sfr    __at (0xC6)   CCL3;
__sfr    __at (0xC7)   CCH3;
__sfr    __at (0xC8)   T2CON;
  __sbit __at (0xC8+7) T2PS;
  __sbit __at (0xC8+6) I3FR;
  __sbit __at (0xC8+5) GF1;
  __sbit __at (0xC8+4) T2R1;
  __sbit __at (0xC8+3) T2R0;
  __sbit __at (0xC8+2) T2CM;
  __sbit __at (0xC8+1) T2I1;
  __sbit __at (0xC8+0) T2I0;
__sfr    __at (0xCA)   CRCL;
__sfr    __at (0xCB)   CRCH;
__sfr    __at (0xCC)   TL2;
__sfr    __at (0xCD)   TH2;
__sfr    __at (0xD0)   PSW;
  __sbit __at (0xD0+7) CY;
  __sbit __at (0xD0+6) AC;
  __sbit __at (0xD0+5) F0;
  __sbit __at (0xD0+4) RS1;
  __sbit __at (0xD0+3) RS0;
  __sbit __at (0xD0+2) OV;
  __sbit __at (0xD0+1) F1;
  __sbit __at (0xD0+0) P;
__sfr    __at (0xD1)   IEN4;
__sfr    __at (0xD2)   ADM;
__sfr    __at (0xD3)   ADB;
__sfr    __at (0xD4)   ADR;
__sfr    __at (0xD5)   VREFH;
__sfr    __at (0xD6)   P1CON;
__sfr    __at (0xD8)   S0CON2;
  __sbit __at (0xD8+7) BD;
__sfr    __at (0xD9)   ADT;
__sfr    __at (0xDA)   I2CDAT;
__sfr    __at (0xDB)   I2CADR;
__sfr    __at (0xDC)   I2CCON;
__sfr    __at (0xDD)   I2CSTA;
__sfr    __at (0xDE)   SMBSEL;
__sfr    __at (0xDF)   SMBDST;
__sfr    __at (0xE0)   ACC;
__sfr    __at (0xE1)   SPSTA;
__sfr    __at (0xE2)   SPCON;
__sfr    __at (0xE3)   SPDAT;
__sfr    __at (0xE4)   P0OC;
__sfr    __at (0xE5)   CLKSEL;
__sfr    __at (0xE6)   CLKCMD;
__sfr    __at (0xE7)   TCON0;
__sfr    __at (0xF0)   B;
__sfr    __at (0xF1)   P0UR;
__sfr    __at (0xF2)   P1UR;
__sfr    __at (0xF3)   P2UR;
__sfr    __at (0xF7)   SRST;
__sfr    __at (0xF9)   P0M;
__sfr    __at (0xFA)   P1M;
__sfr    __at (0xFB)   P2M;
__sfr    __at (0xFF)   PFLAG;

/*      Interrupt Vector      */
#define ISRInt0    0
#define ISRTimer0  1
#define ISRTimer1  3
#define ISRUart    4
#define ISRTimer2  5
#define ISRI2c     8
#define ISRSpi     9
#define ISRCom1    10
#define ISRCom2    11
#define ISRCom3    12
#define ISRCom4    13
#define ISRPwm1    16
#define ISRAdc     17

/*      C51 Macros      */
#ifdef __C51__
#include <intrins.h>
#define IDLE() {unsigned char data var_idle=PCON; var_idle |= 0x01; PCON = var_idle; }
#define STOP() {if (EAL == 0) {PCON |= 0x02;} else {EAL = 0; PCON |= 0x02; EAL = 1;}}
#define ISP(ROM_ADDRESS, RAM_ADDRESS) {PERAM = (RAM_ADDRESS); PEROM = ((ROM_ADDRESS) & 0xFFE0 | 0x0A); if (EAL == 0) {PECMD = 0x5A; _nop_(); _nop_();} else {EAL = 0; PECMD = 0x5A; _nop_(); _nop_(); EAL = 1;} PEROML = 0x00;}
#endif  // __C51__

#ifndef uint8_t
#define uint8_t unsigned char
#endif  // uint8_t

#ifndef uint16_t
#define uint16_t unsigned int
#endif  // uint16_t

#ifndef uint32_t
#define uint32_t unsigned long
#endif  // uint32_t

#endif  // __SN8F5702_H__
