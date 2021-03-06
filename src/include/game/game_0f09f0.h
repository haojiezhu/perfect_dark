#ifndef IN_GAME_GAME_0F09F0_H
#define IN_GAME_GAME_0F09F0_H
#include <ultra64.h>
#include "types.h"

void func0f0f09f0(s32 arg0);
bool menuIsSoloMissionOrMp(void);
bool currentPlayerIsMenuOpenInSoloOrMp(void);
bool func0f0f0c68(void);
void func0f0f0ca0(s32 value, bool allplayers);
u32 func0f0f0ce8(void);
struct menustackdfc *func0f0f1338(u32 arg0);
void func0f0f139c(s32 arg0, f32 arg1);
void func0f0f13ec(s32 arg0);
void func0f0f1418(void);
void func0f0f1494(void);
char *menuResolveText(u32 thing, struct menu_item *item);
char *menuResolveParam2Text(struct menu_item *item);
char *menuResolveParam1Text(struct menu_item *item);
void func0f0f15a4(u8 *arg0, u32 *arg1);
u32 func0f0f1618(void);
u32 func0f0f1d6c(void);
u32 func0f0f1ef4(void);
u32 func0f0f2134(void);
void func0f0f2354(u32 arg0, u8 *arg1, u32 *arg2, u32 *arg3);
u32 func0f0f2534(void);
bool func0f0f2588(u8 *arg0, u32 arg1);
bool func0f0f2674(u8 *arg0, u32 arg1, u32 arg2);
u32 func0f0f26fc(void);
u32 func0f0f288c(void);
u32 func0f0f2928(void);
u32 func0f0f29cc(void);
u32 func0f0f2b2c(void);
u32 func0f0f2c44(void);
void func0f0f2cf4(struct menu_dialog *dialog, struct menuframe *arg1, struct menustackitem *stackitem);
void menuPushDialog(struct menu_dialog *dialog);
u32 func0f0f3220(void);
u32 func0f0f33bc(void);
void menuUpdateCurFrame(void);
void menuPopDialog(void);
void func0f0f3704(struct menu_dialog *dialog);
void func0f0f372c(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8);
void func0f0f37a4(u8 *arg0);
u32 func0f0f38b0(void);
u32 func0f0f5004(void);
u32 func0f0f50fc(void);
u32 func0f0f5360(void);
u32 func0f0f74a8(void);
u32 func0f0f7594(void);
u32 func0f0f7728(void);
u32 func0f0f7e98(void);
void func0f0f8040(void);
void func0f0f8120(void);
void func0f0f820c(struct menu_dialog *dialog, s32 arg1);
bool func0f0f82a8(s32 arg0);
void func0f0f8300(void);
void menuPushRootDialog(struct menu_dialog *dialog, s32 arg1);
void func0f0f85e0(struct menu_dialog *dialog, s32 root);
u32 func0f0f8634(void);
u32 func0f0f86a8(void);
void func0f0f8bb4(u8 *arg0, u32 arg1, u32 arg2);
void func0f0f8c98(void);
u32 func0f0f9030(void);
u32 func0f0f935c(void);
u32 func0f0fa574(void);
void func0f0fa6ac(void);
u32 func0f0fa704(void);
u32 func0f0fb488(void);
Gfx *func0f0fbba0(Gfx *gdl, u8 param_2, s32 arg2);
u32 func0f0fbc30(void);
u32 menuChooseMusic(void);
u32 menuGetRoot(void);
u32 func0f0fce8c(void);
char *menuTextSaveDeviceName(struct menu_item *item);
u32 func0f0fd118(u32 arg0);
bool func0f0fd1f4(u32 arg0, u32 arg1);
u32 func0f0fd320(void);
void func0f0fd494(struct coord *pos);
void func0f0fd548(s32 arg0);
u32 func0f0fd570(void);
bool currentPlayerGetUnk1c04(void);

extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
