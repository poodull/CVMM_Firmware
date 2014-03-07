

#if defined(__SAM3X8E__) || defined(__32MX795F512L__)
const	uint8_t	MYPIN_0	=	0;
const	uint8_t	MYPIN_1	=	1;
const	uint8_t	MYPIN_2	=	2;
const	uint8_t	MYPIN_3	=	3;
const	uint8_t	MYPIN_4	=	4;
const	uint8_t	MYPIN_5	=	5;
const	uint8_t	MYPIN_6	=	6;
const	uint8_t	MYPIN_7	=	7;
const	uint8_t	MYPIN_8	=	8;
const	uint8_t	MYPIN_9	=	9;
const	uint8_t	MYPIN_10	=	10;
const	uint8_t	MYPIN_11	=	11;
const	uint8_t	MYPIN_12	=	12;
const	uint8_t	MYPIN_13	=	13;
const	uint8_t	MYPIN_14	=	14;
const	uint8_t	MYPIN_15	=	15;
const	uint8_t	MYPIN_16	=	16;
const	uint8_t	MYPIN_17	=	17;
const	uint8_t	MYPIN_18	=	18;
const	uint8_t	MYPIN_19	=	19;
const	uint8_t	MYPIN_20	=	20;
const	uint8_t	MYPIN_21	=	21;
const	uint8_t	MYPIN_22	=	22;
const	uint8_t	MYPIN_23	=	23;
const	uint8_t	MYPIN_24	=	24;
const	uint8_t	MYPIN_25	=	25;
const	uint8_t	MYPIN_26	=	26;
const	uint8_t	MYPIN_27	=	27;
const	uint8_t	MYPIN_28	=	28;
const	uint8_t	MYPIN_29	=	29;
const	uint8_t	MYPIN_30	=	30;
const	uint8_t	MYPIN_31	=	31;
const	uint8_t	MYPIN_32	=	32;
const	uint8_t	MYPIN_33	=	33;
const	uint8_t	MYPIN_34	=	34;
const	uint8_t	MYPIN_35	=	35;
const	uint8_t	MYPIN_36	=	36;
const	uint8_t	MYPIN_37	=	37;
const	uint8_t	MYPIN_38	=	38;
const	uint8_t	MYPIN_39	=	39;
const	uint8_t	MYPIN_40	=	40;
const	uint8_t	MYPIN_41	=	41;
const	uint8_t	MYPIN_42	=	42;
const	uint8_t	MYPIN_43	=	43;
const	uint8_t	MYPIN_44	=	44;
const	uint8_t	MYPIN_45	=	45;
const	uint8_t	MYPIN_46	=	46;
const	uint8_t	MYPIN_47	=	47;
const	uint8_t	MYPIN_48	=	48;
const	uint8_t	MYPIN_49	=	49;
const	uint8_t	MYPIN_50	=	50;
const	uint8_t	MYPIN_51	=	51;
const	uint8_t	MYPIN_52	=	52;
const	uint8_t	MYPIN_53	=	53;
const	uint8_t	MYPIN_54	=	54;
const	uint8_t	MYPIN_55	=	55;
const	uint8_t	MYPIN_56	=	56;
const	uint8_t	MYPIN_57	=	57;
const	uint8_t	MYPIN_58	=	58;
const	uint8_t	MYPIN_59	=	59;
const	uint8_t	MYPIN_60	=	60;
const	uint8_t	MYPIN_61	=	61;
const	uint8_t	MYPIN_62	=	62;
const	uint8_t	MYPIN_63	=	63;
const	uint8_t	MYPIN_64	=	64;
const	uint8_t	MYPIN_65	=	65;
const	uint8_t	MYPIN_66	=	66;
const	uint8_t	MYPIN_67	=	67;
const	uint8_t	MYPIN_68	=	68;
const	uint8_t	MYPIN_69	=	69;
const	uint8_t	MYPIN_70	=	70;
const	uint8_t	MYPIN_71	=	71;
const	uint8_t	MYPIN_72	=	72;
const	uint8_t	MYPIN_73	=	73;

#elif TEENSYPP
//don't have to do this because teensypp is clearly defined by pin#
#endif

//************************
//* SOLENOID OUTPUT PIN DEFINITIONS
//************************
#if defined(__SAM3X8E__) || defined(__32MX795F512L__)
    const   uint8_t PO_SOLD0 =  MYPIN_54;    //Solenoid Data 0
    const   uint8_t PO_SOLD1 =  MYPIN_55;    //Solenoid Data 1
    const   uint8_t PO_SOLD2 =  MYPIN_56;    //Solenoid Data 2
    const   uint8_t PO_SOLD3 =  MYPIN_57;    //Solenoid Data 3
    const   uint8_t PO_SOLD4 =  MYPIN_58;    //Solenoid Data 4
    const   uint8_t PO_SOLD5 =  MYPIN_59;   //Solenoid Data 5
    const   uint8_t PO_SOLD6 =  MYPIN_60;   //Solenoid Data 6
    const   uint8_t PO_SOLD7 =  MYPIN_61;   //Solenoid Data 7
    const   uint8_t PO_SOLEN =  MYPIN_62;   //Solenoid Enable Latch
    const   uint8_t PO_SOLBK0 = MYPIN_63;   //Solenoid Bank 0 Enable
    const   uint8_t PO_SOLBK1 = MYPIN_64;   //Solenoid Bank 1 Enable
    const   uint8_t PO_SOLBK2 = MYPIN_65;   //Solenoid Bank 2 Enable
    const   uint8_t PO_SOLBK3 = MYPIN_66;   //Solenoid Bank 3 Enable
#elif TEENSYPP
    byte PO_STATUS = PIN_D6;  //Status LED

    byte PO_SOLD0 = PIN_C1;   //Solenoid Data 0
    byte PO_SOLD1 = PIN_C2;   //Solenoid Data 1
    byte PO_SOLD2 = PIN_C3;   //Solenoid Data 2
    byte PO_SOLD3 = PIN_C4;   //Solenoid Data 3
    byte PO_SOLD4 = PIN_C5;   //Solenoid Data 4
    byte PO_SOLD5 = PIN_C6;   //Solenoid Data 5
    byte PO_SOLD6 = PIN_C7;   //Solenoid Data 6
    byte PO_SOLD7 = PIN_E6;   //Solenoid Data 7
    byte PO_SOLEN = PIN_E7;   //Solenoid Enable Latch
    byte PO_SOLBK0 = PIN_B0;  //Solenoid Bank 0 Enable
    byte PO_SOLBK1 = PIN_B1;  //Solenoid Bank 1 Enable
    byte PO_SOLBK2 = PIN_B2;  //Solenoid Bank 2 Enable
    byte PO_SOLBK3 = PIN_B3;  //Solenoid Bank 3 Enable
#endif 
    
// here is the powerboard pins we're using.
uint8_t _powerBoardPins[] = {PO_SOLD0, PO_SOLD1, PO_SOLD2, PO_SOLD3, PO_SOLD4, PO_SOLD5, PO_SOLD6, 
  PO_SOLD7, PO_SOLEN, PO_SOLBK0, PO_SOLBK1, PO_SOLBK2, PO_SOLBK3};
    
//***********************
//* INPUT PIN DEFINITIONS
//***********************

#if defined(__SAM3X8E__) || defined(__32MX795F512L__)
const uint8_t   PO_STATUS   =   MYPIN_72;   //Status LED
const uint8_t	PI_OUTH     =	MYPIN_48;	//	Outhole                     1.1
const uint8_t	PI_TROR     =	MYPIN_47;	//	Right Trough                1.2
const uint8_t	PI_TROMR    =	MYPIN_46;	//	Middle Right Trough         1.4
const uint8_t	PI_TROM     =	MYPIN_45;	//	Middle Trough               1.8   analog 13
const uint8_t	PI_TROML    =	MYPIN_44;	//	Middle Left Trough          1.16  analog 12
const uint8_t	PI_TROL     =	MYPIN_43;	//	Left Trough                 1.32  analog 11
const uint8_t	PI_SLANE	=	MYPIN_42;	//	Shooter Lane                1.64  analog 10

const uint8_t	PI_REOS     =	MYPIN_38;	//	Right Flipper EOS           2.1   analog 9
const uint8_t	PI_LEOS     =	MYPIN_39;	//	LeftFlipper EOS             2.2   analog 8
const uint8_t	PI_OPTLDRN	=	MYPIN_41;	//	Opto Left Drain             2.4   analog 7
const uint8_t	PI_OPTLRET	=	MYPIN_25;	//	Opto Left Return            2.8   analog 6
const uint8_t	PI_LSLING	=	MYPIN_40;	//	Left Slingshot              2.16  analog 5
const uint8_t	PI_RSLING	=	MYPIN_37;	//	Right Slingshot             2.32  analog 4
const uint8_t	PI_OPTRRET	=	MYPIN_36;	//	Opto Right Return           2.64  analog 3

const uint8_t	PI_OPTRDRN	=	MYPIN_35;	//	Opto Right Drain            3.1   analog 2
const uint8_t	PI_DRACD	=	MYPIN_21;	//	Dracula Target D            3.2   analog 1
const uint8_t	PI_DRACR	=	MYPIN_22;	//	Dracula Target R            3.4   analog 0
const uint8_t	PI_DRACA	=	MYPIN_23;	//	Dracula Target A            3.8
const uint8_t	PI_DRACC	=	MYPIN_24;	//	Dracula Target C            3.16
const uint8_t	PI_DRACU	=	MYPIN_33;	//	Dracula Target U            3.32
const uint8_t	PI_DRACL	=	MYPIN_32;	//	Dracula Target L            3.64

const uint8_t	PI_DRACA2	=	MYPIN_31;	//	Dracula Target A2           4.1
const uint8_t	PI_VUK      =	MYPIN_34;	//	Ball Elevator               4.2
const uint8_t	PI_DROPA	=	MYPIN_20;	//	Drop Target A               4.4
const uint8_t	PI_DROPB	=	MYPIN_29;	//	Drop Target B               4.8
const uint8_t	PI_DROPC	=	MYPIN_30;	//	Drop Target C               4.16
const uint8_t	PI_BELMB	=	MYPIN_19;	//	Belmont Target B            4.32
const uint8_t	PI_BELME	=	MYPIN_18;	//	Belmont Target E            4.64

const uint8_t	PI_BELML	=	MYPIN_9;	//	Belmont Target L            5.1
const uint8_t	PI_BELMM	=	MYPIN_17;	//	Belmont Target M            5.2
const uint8_t	PI_BELMO	=	MYPIN_26;	//	Belmont Target O            5.4
const uint8_t	PI_BELMN	=	MYPIN_27;	//	Belmont Target N            5.8
const uint8_t	PI_BELMT	=	MYPIN_28;	//	Belmont Target T            5.16
const uint8_t	PI_ORBLO	=	MYPIN_8;	//	Orbit Left Outer            5.32
const uint8_t	PI_RAMPEX	=	MYPIN_3;	//	Ramp Exit (nav upstairs)    5.64

const uint8_t	PI_ORBLI	=	MYPIN_7;	//	Orbit Left Inner            6.1
const uint8_t	PI_BOSS     =	MYPIN_6;	//	Boss Target                 6.2
const uint8_t	PI_CENTEX	=	MYPIN_4;	//	Center Exit (nav forward)   6.4
const uint8_t	PI_CENTSC	=	MYPIN_5;	//	Center Scoop                6.8
const uint8_t	PI_ORBRI	=	MYPIN_13;	//	Orbit Right Inner           6.16
const uint8_t	PI_CANDLE	=	MYPIN_14;	//	Captured Ball Target        6.32
const uint8_t	PI_RIGHTEX	=	MYPIN_16;	//	Right Scoop (nav down)      6.64

const uint8_t	PI_ORBRO	=	MYPIN_15;	//	Orbit Right Outer           7.1
const uint8_t	PI_ORBTO	=	MYPIN_2;	//	Orbit Top Outer             7.2
const uint8_t	PI_LPOP     =	MYPIN_11;	//	Left Pop Bumper             7.4
const uint8_t	PI_TPOP     =	MYPIN_10;	//	Top Pop Bumper              7.8
const uint8_t	PI_RPOP     =	MYPIN_12;	//	Lower Pop Bumper            7.16
const uint8_t	PI_LFLIP	=	MYPIN_50;	//	Left Flipper                7.32
const uint8_t	PI_RFLIP	=	MYPIN_51;	//	Right Flipper               7.64

#elif TEENSYPP
    byte PI_LFLIP = PIN_D1;  //Left Flipper Switch
    byte PI_RFLIP = PIN_D2;  //Right Flipper Switch
    byte PI_LEOS = PIN_D3;   //Left Flipper EOS Switch
    byte PI_REOS = PIN_D4;   //Right Flipper EOS Switch
    byte PI_LSLING = PIN_D5; //Left Slingshot Switch
    byte PI_RSLING = PIN_D7; //Right Slingshot Switch
    byte PI_TPOP = PIN_E0;   //Top Popper Switch
    byte PI_LPOP = PIN_E1;   //Left Popper Switch
    byte PI_RPOP = PIN_C0;   //Right Popper Switch
#endif 
    
//***********************
//* PWM (SERVO) PIN DEFINITIONS
//***********************
#if defined(__SAM3X8E__) || defined(__32MX795F512L__)
    #define PWM_CENTER  MYPIN_67
    #define PWM_ELEV    MYPIN_68
#elif TEENSYPP
#endif
