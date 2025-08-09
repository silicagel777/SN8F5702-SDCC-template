// Sample SDCC program for SN85702 series MCUs

#include "sn8f5702.h"

#define F_OSC 32000000
#define F_CPU F_OSC / 4
#define F_TIMER F_OSC / 128
#define TIMER_TICKS_PER_MS F_TIMER / 1000

#define BLINK_PORT_MODE_REG P0M
#define BLINK_PORT_REG P0
#define BLINK_PORT_PIN 0
#define BLINK_DELAY_MS 500

static volatile uint16_t milliseconds;

// System clock setup routines ================================================

void setup_system_clock(void) {
  CKCON = 0x70;  // To change system clock safely
  CLKSEL = 0x05; // Set F_CPU = F_OSC / 4
  CLKCMD = 0x69; // Apply CLKSEL setting
  CKCON = 0x00;  // IROM fetch = fcpu / 1
}

// Timer setup routines =======================================================

inline void set_timer_delay(uint16_t ticks) {
  TR0 = 0;
  TL0 = 65535 - ticks;
  TH0 = (65535 - ticks) >> 8;
  TR0 = 1;
}

void timer_interrupt(void) __interrupt(ISRTimer0) __using(1) {
  set_timer_delay(TIMER_TICKS_PER_MS);
  milliseconds++;
}

void setup_timer(void) {
  // Timer 0 setup
  TMOD = (TMOD & 0xF0) | 0x05; // mode 1, F_OSC clock
  TCON0 |= 0;                  // Set frequency to F_OSC/128
  ET0 = 1;                     // Enable ISR for timer 0
  EAL = 1;                     // Enable global interrupts
  set_timer_delay(TIMER_TICKS_PER_MS);
}

// Timekeeping routines =======================================================

uint16_t get_milliseconds(void) {
  uint16_t result;
  do {
    result = milliseconds;
  } while (result != milliseconds);
  return result;
}

void delay_milliseconds(uint16_t milliseconds) {
  uint16_t start_time = get_milliseconds();
  while (get_milliseconds() - start_time < milliseconds) {};
}

// Blink routines =============================================================

void setup_blink(void) {
  BLINK_PORT_MODE_REG |= (1 << BLINK_PORT_PIN);
}

inline void toggle_blink(void) {
  BLINK_PORT_REG ^= (1 << BLINK_PORT_PIN);
}

// Main code ==================================================================

void main(void) {
  setup_system_clock();
  setup_timer();
  setup_blink();
  for (;;) {
    toggle_blink();
    delay_milliseconds(BLINK_DELAY_MS);
  }
}
