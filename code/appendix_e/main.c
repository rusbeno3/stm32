#include "stm32f0xx.h"

#define SYSTICK_MAX_VALUE 16777215

static volatile uint32_t first, second, third;

short vars_in_func_1(short a, short b);
uint32_t vars_in_func_2(uint32_t a, uint32_t b);

int mean_signed(int a, int b);
unsigned int mean_unsigned(unsigned int a, unsigned int b);

typedef struct {
  uint32_t *x;
  uint32_t *y;
  uint32_t *z;
} COORDINATE_t;

uint32_t solver_1(uint32_t *x, uint32_t *y, uint32_t *z, uint32_t c, uint32_t *arr);
uint32_t solver_2(COORDINATE_t *cor, uint32_t c, uint8_t *arr);

uint32_t swap_word(uint32_t word);

struct {
  char a;
  int b;
  char c;
  short d;
} FIRST;

struct {
  char a;
  char c;
  short d;
  int b;
} SECOND;

//----
typedef struct {
  char a;
  int b;
  char c;
  short d;
} FIRST_t;

typedef struct {
  char a;
  char c;
  short d;
  int b;
} SECOND_t;
//----

int main() {
  // INIT ---------------------------------------------------------------------
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
  SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  // --------------------------------------------------------------------------
  // LOCAL VARIABLES
  // --------------------------------------------------------------------------
  /*
  	    0x80000ee: 0x2000         MOVS      R0, #0	
  	    0x80000f0: 0xe000         B.N       0x80000f4	
  	    0x80000f2: 0x1c40         ADDS      R0, R0, #1
  	    0x80000f4: 0xb2c0         UXTB      R0, R0	
  	    0x80000f6: 0x287f         CMP       R0, #127                ; 0x7f	
  	    0x80000f8: 0xdbfb         BLT.N     0x80000f2	
  
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (char i = 0; i < 127; i++) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*
  	    0x80000fa: 0x2000         MOVS      R0, #0	
  	    0x80000fc: 0xe000         B.N       0x8000100	
  	    0x80000fe: 0x1c40         ADDS      R0, R0, #1	
  	    0x8000100: 0x287f         CMP       R0, #127                ; 0x7f	
  	    0x8000102: 0xd3fc         BCC.N     0x80000fe	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (uint32_t i = 0; i < 127; i++) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*
  	    0x8000288: 0xb200         SXTH      R0, R0	
	    0x800028a: 0xb209         SXTH      R1, R1	
	    0x800028c: 0xeb10 0x0061  ADDS.W    R0, R0, R1, ASR #1	
	    0x8000290: 0xb200         SXTH      R0, R0	
	    0x8000292: 0x4770         BX        LR
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  vars_in_func_1(-3, 2);
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*
  	    0x8000294: 0xeb10 0x0051  ADDS.W    R0, R0, R1, LSR #1	
	    0x8000298: 0x4770         BX        LR	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  vars_in_func_2(3, 2);
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  // --------------------------------------------------------------------------
  // SIGNED AND UNSIGNED VARIAVBLES
  // --------------------------------------------------------------------------
  
  /*
  	    0x8000116: 0x2102         MOVS      R1, #2	
	    0x8000118: 0xf07f 0x0004  MVNS.W    R0, #4	
	    0x800011c: 0xf000 0xf8bf  BL        mean_signed             ; 0x800029e	
	    0x800029e: 0x1808         ADDS      R0, R1, R0	
	    0x80002a0: 0x2102         MOVS      R1, #2	
	    0x80002a2: 0xfb90 0xf0f1  SDIV      R0, R0, R1	
	    0x80002a6: 0x4770         BX        LR	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  mean_signed(-5, 2);
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*
  	    0x8000120: 0x2102         MOVS      R1, #2	
	    0x8000122: 0x2005         MOVS      R0, #5	
	    0x8000124: 0xf000 0xf8c0  BL        mean_unsigned           ; 0x80002a8	
	    0x80002a8: 0x1808         ADDS      R0, R1, R0	
	    0x80002aa: 0x0840         LSRS      R0, R0, #1	
	    0x80002ac: 0x4770         BX        LR	
	    0x80002ae: 0x0000         MOVS      R0, R0	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  mean_unsigned(5, 2);
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  // --------------------------------------------------------------------------
  // LOOPS
  // --------------------------------------------------------------------------
  uint32_t i = 0;
  
  /*	    0x800012a: 0x2000         MOVS      R0, #0	
	    0x800012c: 0xe000         B.N       0x8000130	
	    0x800012e: 0x1c40         ADDS      R0, R0, #1	
	    0x8000130: 0x287f         CMP       R0, #127                ; 0x7f	
	    0x8000132: 0xd3fc         BCC.N     0x800012e	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 0; i < 127; i++) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*	    0x8000134: 0x207f         MOVS      R0, #127                ; 0x7f	
	    0x8000136: 0xe000         B.N       0x800013a	
	    0x8000138: 0x1e40         SUBS      R0, R0, #1	
	    0x800013a: 0x2800         CMP       R0, #0	
	    0x800013c: 0xd1fc         BNE.N     0x8000138	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 127; i != 0; i--) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /*	    0x800013e: 0x207f         MOVS      R0, #127                ; 0x7f	
	    0x8000140: 0xe000         B.N       0x8000144	
	    0x8000142: 0x1e40         SUBS      R0, R0, #1	
	    0x8000144: 0x2800         CMP       R0, #0	
	    0x8000146: 0xd1fc         BNE.N     0x8000142	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 127; i > 0; i--) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  third = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /**/
  uint32_t n = 127;
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (; n != 0; n--) {
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  /**/
  n = 127;
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  do {
  } while (--n != 0);
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  // --------------------------------------------------------------------------
  // STRUCTURES SIZE
  // --------------------------------------------------------------------------
  /**/
  first = sizeof(FIRST);
  /**/
  second = sizeof(SECOND);
  
  // --------------------------------------------------------------------------
  // DIVISION
  // --------------------------------------------------------------------------
  uint32_t offset = 2, increment = 1, buffer_size = 5;
  /*
  	    0x800016c: 0x1808         ADDS      R0, R1, R0	
	    0x800016e: 0x0001         MOVS      R1, R0	
	    0x8000170: 0xfbb1 0xf0f2  UDIV      R0, R1, R2	
	    0x8000174: 0xfb02 0x1010  MLS       R0, R2, R0, R1	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  offset = (offset + increment) % buffer_size;
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  offset = 2, increment = 1, buffer_size = 5;
  /*
            0x800017e: 0x1808         ADDS      R0, R1, R0	
	    0x8000180: 0x4290         CMP       R0, R2	
	    0x8000182: 0xd300         BCC.N     0x8000186	
	    0x8000184: 0x1a80         SUBS      R0, R0, R2	
  */
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  offset += increment;
  if (offset >= buffer_size) {
    offset -= buffer_size;
  }
  // STOP SysTick --------------------------------<
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  // --------------------------------------------------------------------------
  // ADDITIONAL
  // --------------------------------------------------------------------------
  
  uint32_t v = 0xFAAA000F;
  
  // START Systick ------------------------------->
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  
  v = swap_word(v);
//  // swap odd and even bits
//  v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
//  // swap consecutive pairs
//  v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
//  // swap nibbles ...
//  v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
//  // swap bytes
//  v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
//  // swap 2-byte long pairs
//  v = ( v >> 16             ) | ( v               << 16);
  
  // STOP SysTick
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  uint32_t a = 0xFAAA000F;
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  
  // START SysTick
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  //a = __RBIT(a);
  // STOP SysTick
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  // --------------------------------------------------------------------------
  
  FIRST_t x;
  x.a = 1;
  x.b = 2;
  x.c = 3;
  x.d = 4;
  SECOND_t y;
  y.a = 1;
  y.b = 2;
  y.c = 3;
  y.d = 4;
  
  // start
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  x.a += x.a;
  x.b += x.b;
  x.c += x.c;
  x.d += x.d;
  // stop
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  
  // start
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  y.a += y.a;
  y.b += y.b;
  y.c += y.c;
  y.d += y.d;
  // stop
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  third = sizeof(x) - sizeof(y);
  
  
  
  
  char arr_char[12];
  short arr_short[12];
  int arr_int[12];
  
  first = sizeof(arr_char);
  second = sizeof(arr_short);
  third = sizeof(arr_int);
  
  for (int i = 0; i < 12; i++) {
    arr_char[i] = i;
    arr_short[i] = i;
    arr_int[i] = i;
  }
  
  // start
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 0; i < 12; i++) {
    arr_char[i] += arr_char[11 - i];
  }
  // stop
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  first = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  for (int i = 0; i < 12; i++) {
    arr_char[i] = i;
    arr_short[i] = i;
    arr_int[i] = i;
  }
  
  // start
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 0; i < 12; i++) {
    arr_short[i] += arr_short[11 - i];
  }
  // stop
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  second = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  for (int i = 0; i < 12; i++) {
    arr_char[i] = i;
    arr_short[i] = i;
    arr_int[i] = i;
  }
  
  // start
  SysTick->LOAD = SYSTICK_MAX_VALUE;
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  for (i = 0; i < 12; i++) {
    arr_int[i] += arr_int[11 - i];
  }
  // stop
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  third = SYSTICK_MAX_VALUE - SysTick->VAL;
  
  // --------------------------------------------------------------------------
  while(1) {
  }
}

// functions
short vars_in_func_1(short a, short b) {
  return a + (b >> 1);
}

uint32_t vars_in_func_2(uint32_t a, uint32_t b) {
  return a + (b >> 1);
}

int mean_signed(int a, int b) {
  return (a + b) / 2;
}

unsigned int mean_unsigned(unsigned int a, unsigned int b) {
  return (a + b) / 2;
}

uint32_t solver_1(uint32_t *x, uint32_t *y, uint32_t *z, uint32_t c, uint32_t *arr) {
  // do something
  return 0;
}

uint32_t solver_2(COORDINATE_t *cor, uint32_t c, uint8_t *arr) {
  // do something
  return 0;
}

uint32_t swap_word(uint32_t word) {
  // swap odd and even bits
  word = ((word >> 1) & 0x55555555) | ((word & 0x55555555) << 1);
  // swap consecutive pairs
  word = ((word >> 2) & 0x33333333) | ((word & 0x33333333) << 2);
  // swap nibbles ...
  word = ((word >> 4) & 0x0F0F0F0F) | ((word & 0x0F0F0F0F) << 4);
  // swap bytes
  word = ((word >> 8) & 0x00FF00FF) | ((word & 0x00FF00FF) << 8);
  // swap 2-byte long pairs
  word = ( word >> 16             ) | ( word               << 16);
  return word;
}
