#include <Arduino.h>
static uint8_t logo[32 * 38 / 8]  = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03,
  0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0xC0, 0x00,
  0x00, 0x00, 0x40, 0x00, 0x00, 0xC0, 0x4F, 0x00, 0x00, 0xC0, 0x7F, 0x00,
  0x00, 0xF0, 0xFF, 0x00, 0x00, 0xF8, 0xFF, 0x01, 0x00, 0xF8, 0xFF, 0x01,
  0x00, 0xEC, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x07,
  0x00, 0xFE, 0xFE, 0x0F, 0x00, 0xFE, 0xFF, 0x05, 0x00, 0xFC, 0xFF, 0x03,
  0x00, 0xFE, 0xFF, 0x07, 0x00, 0x9C, 0x9F, 0x03, 0x00, 0xFC, 0xFF, 0x01,
  0x00, 0xF8, 0xFF, 0x01, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0xF0, 0xFF, 0x03,
  0x00, 0xFC, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0x0F, 0x00, 0xFF, 0xFF, 0x0F,
  0x00, 0xFF, 0xFF, 0x0D, 0x80, 0xFB, 0xFF, 0x1D, 0xB0, 0xFE, 0xFF, 0x17,
  0xF8, 0xFA, 0xFF, 0x05, 0x3C, 0xF8, 0xFF, 0x00, 0x3E, 0x30, 0xC0, 0x00,
  0x0F, 0x20, 0x40, 0x00, 0x03, 0x20, 0x40, 0x00, 0x00, 0x38, 0xC0, 0x07,
  0x00, 0x3C, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, };
