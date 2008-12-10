#ifndef WINPRIV_H
#define WINPRIV_H

#include "win.h"
#include "winids.h"
#include "term.h"

#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>

extern HWND hwnd;       // the main terminal window
extern HINSTANCE hinst; // The all-important instance handle
extern HMENU hmenu;
extern HDC hdc;

enum {
  WM_IGNORE_CLIP = WM_APP + 2,
  WM_FULLSCR_ON_MAX = WM_APP + 3
};

enum {
  NCFGCOLOURS = 22, 
  NEXTCOLOURS = 240,
  NALLCOLOURS = NCFGCOLOURS + NEXTCOLOURS
};
extern COLORREF colours[NALLCOLOURS];

extern LOGFONT lfont;

extern int font_width, font_height;
extern int offset_width, offset_height;

void win_init_fonts(void);
void win_deinit_fonts(void);

void win_init_palette(void);
void win_reconfig_palette(void);

void win_about(void);
bool win_config(void);

void win_enable_tip(void);
void win_disable_tip(void);
void win_update_tip(HWND src, int cx, int cy);

void win_show_mouse(void);
void win_hide_mouse(void);
void win_mouse_click(mouse_button, WPARAM, LPARAM);
void win_mouse_release(mouse_button, WPARAM, LPARAM);
void win_mouse_wheel(WPARAM, LPARAM);
void win_mouse_move(bool nc, WPARAM, LPARAM);
bool win_key_press(WPARAM, LPARAM);

#endif