#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/chr/chr.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_127910.h"
#include "game/game_1668e0.h"
#include "game/game_166e40.h"
#include "game/pdoptions.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_0d520.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b480.h"
#include "types.h"

const char var7f1b5a10[] = "WallHit_MakeSpaceRoom : ERROR - Couldn't find any space in room %d\n";
const char var7f1b5a54[] = "wallhit";
const char var7f1b5a5c[] = "g_MaxRound = %s%s%f";
const char var7f1b5a70[] = "";
const char var7f1b5a74[] = "";
const char var7f1b5a78[] = "g_MinRound = %s%s%f";
const char var7f1b5a8c[] = "";
const char var7f1b5a90[] = "";
const char var7f1b5a94[] = "Done %d Z buffer calcs";
const char var7f1b5aac[] = "ZOOM : g_ZoomFactor=%s%s%f";
const char var7f1b5ac8[] = "";
const char var7f1b5acc[] = "";
const char var7f1b5ad0[] = "ZOOM : g_ZoomScalar=%s%s%f";
const char var7f1b5aec[] = "";
const char var7f1b5af0[] = "";
const char var7f1b5af4[] = "ZOOM : scale=%s%s%f";
const char var7f1b5b08[] = "";
const char var7f1b5b0c[] = "";
const char var7f1b5b10[] = "WallHit_Tick : Status - RED";
const char var7f1b5b2c[] = "WallHit_Tick : Status - YELLOW (%u)";
const char var7f1b5b50[] = "WallHit_Tick : Status - GREEN";
const char var7f1b5b70[] = "WallHit_Tick : %d Used";
const char var7f1b5b88[] = "WallHit_Tick : %d Free";
const char var7f1b5ba0[] = "WallHit_Tick : %d Pending";
const char var7f1b5bbc[] = "WallHit_Tick : %d Blood";
const char var7f1b5bd4[] = "WallHit_Tick : %d Other";
const char var7f1b5bec[] = "WallHit_Tick : %d Ratio";
const char var7f1b5c04[] = "WallHit_Tick : %d(%d) Prop Hits";
const char var7f1b5c24[] = "tLifeTime=%s%s%f, tScalarGbl=%f";
const char var7f1b5c44[] = "";
const char var7f1b5c48[] = "";
const char var7f1b5c4c[] = "wallhit.c";
const char var7f1b5c58[] = "wallhit.c";
const char var7f1b5c64[] = "wallhit.c";
const char var7f1b5c70[] = "AFT : tVecU (along) = (%s%s%f,%f,%f)\n";
const char var7f1b5c98[] = "";
const char var7f1b5c9c[] = "";
const char var7f1b5ca0[] = "AFT : tVecV (up)    = (%s%s%f,%f,%f)\n";
const char var7f1b5cc8[] = "";
const char var7f1b5ccc[] = "";
const char var7f1b5cd0[] = "Wallhit colour %d not implemented, substituting black\n";

GLOBAL_ASM(
glabel func0f13e0e0
/*  f13e0e0:	3c028008 */ 	lui	$v0,%hi(var8007f754)
/*  f13e0e4:	2442f754 */ 	addiu	$v0,$v0,%lo(var8007f754)
/*  f13e0e8:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f13e0ec:	460c203c */ 	c.lt.s	$f4,$f12
/*  f13e0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e0f4:	45000003 */ 	bc1f	.L0f13e104
/*  f13e0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e0fc:	1000000a */ 	beqz	$zero,.L0f13e128
/*  f13e100:	e44c0000 */ 	swc1	$f12,0x0($v0)
.L0f13e104:
/*  f13e104:	3c028008 */ 	lui	$v0,%hi(var8007f758)
/*  f13e108:	2442f758 */ 	addiu	$v0,$v0,%lo(var8007f758)
/*  f13e10c:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f13e110:	46006007 */ 	neg.s	$f0,$f12
/*  f13e114:	4600303c */ 	c.lt.s	$f6,$f0
/*  f13e118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e11c:	45020003 */ 	bc1fl	.L0f13e12c
/*  f13e120:	3c0145fa */ 	lui	$at,0x45fa
/*  f13e124:	e4400000 */ 	swc1	$f0,0x0($v0)
.L0f13e128:
/*  f13e128:	3c0145fa */ 	lui	$at,0x45fa
.L0f13e12c:
/*  f13e12c:	44810000 */ 	mtc1	$at,$f0
/*  f13e130:	44804000 */ 	mtc1	$zero,$f8
/*  f13e134:	460c003c */ 	c.lt.s	$f0,$f12
/*  f13e138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e13c:	45020004 */ 	bc1fl	.L0f13e150
/*  f13e140:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f13e144:	10000009 */ 	beqz	$zero,.L0f13e16c
/*  f13e148:	46000306 */ 	mov.s	$f12,$f0
/*  f13e14c:	3c01c5fa */ 	lui	$at,0xc5fa
.L0f13e150:
/*  f13e150:	44810000 */ 	mtc1	$at,$f0
/*  f13e154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e158:	4600603c */ 	c.lt.s	$f12,$f0
/*  f13e15c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e160:	45020003 */ 	bc1fl	.L0f13e170
/*  f13e164:	460c403c */ 	c.lt.s	$f8,$f12
/*  f13e168:	46000306 */ 	mov.s	$f12,$f0
.L0f13e16c:
/*  f13e16c:	460c403c */ 	c.lt.s	$f8,$f12
.L0f13e170:
/*  f13e170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e174:	45000004 */ 	bc1f	.L0f13e188
/*  f13e178:	3c013f00 */ 	lui	$at,0x3f00
/*  f13e17c:	44815000 */ 	mtc1	$at,$f10
/*  f13e180:	10000005 */ 	beqz	$zero,.L0f13e198
/*  f13e184:	460a6300 */ 	add.s	$f12,$f12,$f10
.L0f13e188:
/*  f13e188:	3c013f00 */ 	lui	$at,0x3f00
/*  f13e18c:	44818000 */ 	mtc1	$at,$f16
/*  f13e190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e194:	46106301 */ 	sub.s	$f12,$f12,$f16
.L0f13e198:
/*  f13e198:	4600648d */ 	trunc.w.s	$f18,$f12
/*  f13e19c:	44029000 */ 	mfc1	$v0,$f18
/*  f13e1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e1a4:	00027c00 */ 	sll	$t7,$v0,0x10
/*  f13e1a8:	03e00008 */ 	jr	$ra
/*  f13e1ac:	000f1403 */ 	sra	$v0,$t7,0x10
);

GLOBAL_ASM(
glabel func0f13e1b0
/*  f13e1b0:	908e006f */ 	lbu	$t6,0x6f($a0)
/*  f13e1b4:	3c03800a */ 	lui	$v1,%hi(var800a41b8)
/*  f13e1b8:	246341b8 */ 	addiu	$v1,$v1,%lo(var800a41b8)
/*  f13e1bc:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f13e1c0:	a080006d */ 	sb	$zero,0x6d($a0)
/*  f13e1c4:	a080006e */ 	sb	$zero,0x6e($a0)
/*  f13e1c8:	a08f006f */ 	sb	$t7,0x6f($a0)
/*  f13e1cc:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f13e1d0:	54820006 */ 	bnel	$a0,$v0,.L0f13e1ec
/*  f13e1d4:	8c450074 */ 	lw	$a1,0x74($v0)
/*  f13e1d8:	8c980074 */ 	lw	$t8,0x74($a0)
/*  f13e1dc:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f13e1e0:	1000000b */ 	beqz	$zero,.L0f13e210
/*  f13e1e4:	ac800074 */ 	sw	$zero,0x74($a0)
/*  f13e1e8:	8c450074 */ 	lw	$a1,0x74($v0)
.L0f13e1ec:
/*  f13e1ec:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e1f0:	50850006 */ 	beql	$a0,$a1,.L0f13e20c
/*  f13e1f4:	8c990074 */ 	lw	$t9,0x74($a0)
/*  f13e1f8:	00a01825 */ 	or	$v1,$a1,$zero
.L0f13e1fc:
/*  f13e1fc:	8ca50074 */ 	lw	$a1,0x74($a1)
/*  f13e200:	5485fffe */ 	bnel	$a0,$a1,.L0f13e1fc
/*  f13e204:	00a01825 */ 	or	$v1,$a1,$zero
/*  f13e208:	8c990074 */ 	lw	$t9,0x74($a0)
.L0f13e20c:
/*  f13e20c:	ac790074 */ 	sw	$t9,0x74($v1)
.L0f13e210:
/*  f13e210:	3c03800a */ 	lui	$v1,%hi(var800a41b4)
/*  f13e214:	246341b4 */ 	addiu	$v1,$v1,%lo(var800a41b4)
/*  f13e218:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f13e21c:	3c06800a */ 	lui	$a2,%hi(var8009cc4c)
/*  f13e220:	24c6cc4c */ 	addiu	$a2,$a2,%lo(var8009cc4c)
/*  f13e224:	ac880074 */ 	sw	$t0,0x74($a0)
/*  f13e228:	ac640000 */ 	sw	$a0,0x0($v1)
/*  f13e22c:	8c820060 */ 	lw	$v0,0x60($a0)
/*  f13e230:	5440003c */ 	bnezl	$v0,.L0f13e324
/*  f13e234:	8c8d006c */ 	lw	$t5,0x6c($a0)
/*  f13e238:	8c89006c */ 	lw	$t1,0x6c($a0)
/*  f13e23c:	00095f00 */ 	sll	$t3,$t1,0x1c
/*  f13e240:	0563001d */ 	bgezl	$t3,.L0f13e2b8
/*  f13e244:	84880068 */ 	lh	$t0,0x68($a0)
/*  f13e248:	848d0068 */ 	lh	$t5,0x68($a0)
/*  f13e24c:	3c0c800a */ 	lui	$t4,%hi(g_Rooms)
/*  f13e250:	8d8c4928 */ 	lw	$t4,%lo(g_Rooms)($t4)
/*  f13e254:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f13e258:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f13e25c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13e260:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f13e264:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13e268:	018e1021 */ 	addu	$v0,$t4,$t6
/*  f13e26c:	8c450088 */ 	lw	$a1,0x88($v0)
/*  f13e270:	54850005 */ 	bnel	$a0,$a1,.L0f13e288
/*  f13e274:	8ca20078 */ 	lw	$v0,0x78($a1)
/*  f13e278:	8c8f0078 */ 	lw	$t7,0x78($a0)
/*  f13e27c:	1000000b */ 	beqz	$zero,.L0f13e2ac
/*  f13e280:	ac4f0088 */ 	sw	$t7,0x88($v0)
/*  f13e284:	8ca20078 */ 	lw	$v0,0x78($a1)
.L0f13e288:
/*  f13e288:	00a01825 */ 	or	$v1,$a1,$zero
/*  f13e28c:	50820006 */ 	beql	$a0,$v0,.L0f13e2a8
/*  f13e290:	8c980078 */ 	lw	$t8,0x78($a0)
/*  f13e294:	00401825 */ 	or	$v1,$v0,$zero
.L0f13e298:
/*  f13e298:	8c420078 */ 	lw	$v0,0x78($v0)
/*  f13e29c:	5482fffe */ 	bnel	$a0,$v0,.L0f13e298
/*  f13e2a0:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e2a4:	8c980078 */ 	lw	$t8,0x78($a0)
.L0f13e2a8:
/*  f13e2a8:	ac780078 */ 	sw	$t8,0x78($v1)
.L0f13e2ac:
/*  f13e2ac:	10000044 */ 	beqz	$zero,.L0f13e3c0
/*  f13e2b0:	ac800078 */ 	sw	$zero,0x78($a0)
/*  f13e2b4:	84880068 */ 	lh	$t0,0x68($a0)
.L0f13e2b8:
/*  f13e2b8:	3c19800a */ 	lui	$t9,%hi(g_Rooms)
/*  f13e2bc:	8f394928 */ 	lw	$t9,%lo(g_Rooms)($t9)
/*  f13e2c0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f13e2c4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f13e2c8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f13e2cc:	01284823 */ 	subu	$t1,$t1,$t0
/*  f13e2d0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f13e2d4:	03291021 */ 	addu	$v0,$t9,$t1
/*  f13e2d8:	8c450084 */ 	lw	$a1,0x84($v0)
/*  f13e2dc:	54850005 */ 	bnel	$a0,$a1,.L0f13e2f4
/*  f13e2e0:	8ca20078 */ 	lw	$v0,0x78($a1)
/*  f13e2e4:	8c8a0078 */ 	lw	$t2,0x78($a0)
/*  f13e2e8:	1000000b */ 	beqz	$zero,.L0f13e318
/*  f13e2ec:	ac4a0084 */ 	sw	$t2,0x84($v0)
/*  f13e2f0:	8ca20078 */ 	lw	$v0,0x78($a1)
.L0f13e2f4:
/*  f13e2f4:	00a01825 */ 	or	$v1,$a1,$zero
/*  f13e2f8:	50820006 */ 	beql	$a0,$v0,.L0f13e314
/*  f13e2fc:	8c8b0078 */ 	lw	$t3,0x78($a0)
/*  f13e300:	00401825 */ 	or	$v1,$v0,$zero
.L0f13e304:
/*  f13e304:	8c420078 */ 	lw	$v0,0x78($v0)
/*  f13e308:	5482fffe */ 	bnel	$a0,$v0,.L0f13e304
/*  f13e30c:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e310:	8c8b0078 */ 	lw	$t3,0x78($a0)
.L0f13e314:
/*  f13e314:	ac6b0078 */ 	sw	$t3,0x78($v1)
.L0f13e318:
/*  f13e318:	10000029 */ 	beqz	$zero,.L0f13e3c0
/*  f13e31c:	ac800078 */ 	sw	$zero,0x78($a0)
/*  f13e320:	8c8d006c */ 	lw	$t5,0x6c($a0)
.L0f13e324:
/*  f13e324:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e328:	000d7700 */ 	sll	$t6,$t5,0x1c
/*  f13e32c:	05c30014 */ 	bgezl	$t6,.L0f13e380
/*  f13e330:	8c650040 */ 	lw	$a1,0x40($v1)
/*  f13e334:	8c450044 */ 	lw	$a1,0x44($v0)
/*  f13e338:	54850005 */ 	bnel	$a0,$a1,.L0f13e350
/*  f13e33c:	8ca20078 */ 	lw	$v0,0x78($a1)
/*  f13e340:	8c8f0078 */ 	lw	$t7,0x78($a0)
/*  f13e344:	1000000b */ 	beqz	$zero,.L0f13e374
/*  f13e348:	ac4f0044 */ 	sw	$t7,0x44($v0)
/*  f13e34c:	8ca20078 */ 	lw	$v0,0x78($a1)
.L0f13e350:
/*  f13e350:	00a01825 */ 	or	$v1,$a1,$zero
/*  f13e354:	50820006 */ 	beql	$a0,$v0,.L0f13e370
/*  f13e358:	8c980078 */ 	lw	$t8,0x78($a0)
/*  f13e35c:	00401825 */ 	or	$v1,$v0,$zero
.L0f13e360:
/*  f13e360:	8c420078 */ 	lw	$v0,0x78($v0)
/*  f13e364:	5482fffe */ 	bnel	$a0,$v0,.L0f13e360
/*  f13e368:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e36c:	8c980078 */ 	lw	$t8,0x78($a0)
.L0f13e370:
/*  f13e370:	ac780078 */ 	sw	$t8,0x78($v1)
.L0f13e374:
/*  f13e374:	10000012 */ 	beqz	$zero,.L0f13e3c0
/*  f13e378:	ac800078 */ 	sw	$zero,0x78($a0)
/*  f13e37c:	8c650040 */ 	lw	$a1,0x40($v1)
.L0f13e380:
/*  f13e380:	54850005 */ 	bnel	$a0,$a1,.L0f13e398
/*  f13e384:	8ca20078 */ 	lw	$v0,0x78($a1)
/*  f13e388:	8c880078 */ 	lw	$t0,0x78($a0)
/*  f13e38c:	1000000b */ 	beqz	$zero,.L0f13e3bc
/*  f13e390:	ac680040 */ 	sw	$t0,0x40($v1)
/*  f13e394:	8ca20078 */ 	lw	$v0,0x78($a1)
.L0f13e398:
/*  f13e398:	00a01825 */ 	or	$v1,$a1,$zero
/*  f13e39c:	50820006 */ 	beql	$a0,$v0,.L0f13e3b8
/*  f13e3a0:	8c990078 */ 	lw	$t9,0x78($a0)
/*  f13e3a4:	00401825 */ 	or	$v1,$v0,$zero
.L0f13e3a8:
/*  f13e3a8:	8c420078 */ 	lw	$v0,0x78($v0)
/*  f13e3ac:	5482fffe */ 	bnel	$a0,$v0,.L0f13e3a8
/*  f13e3b0:	00401825 */ 	or	$v1,$v0,$zero
/*  f13e3b4:	8c990078 */ 	lw	$t9,0x78($a0)
.L0f13e3b8:
/*  f13e3b8:	ac790078 */ 	sw	$t9,0x78($v1)
.L0f13e3bc:
/*  f13e3bc:	ac800078 */ 	sw	$zero,0x78($a0)
.L0f13e3c0:
/*  f13e3c0:	3c05800a */ 	lui	$a1,%hi(var8009cc50)
/*  f13e3c4:	ac800060 */ 	sw	$zero,0x60($a0)
/*  f13e3c8:	24a5cc50 */ 	addiu	$a1,$a1,%lo(var8009cc50)
/*  f13e3cc:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f13e3d0:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f13e3d4:	00801825 */ 	or	$v1,$a0,$zero
/*  f13e3d8:	252affff */ 	addiu	$t2,$t1,-1
/*  f13e3dc:	256d0001 */ 	addiu	$t5,$t3,0x1
/*  f13e3e0:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f13e3e4:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f13e3e8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f13e3ec:	00001025 */ 	or	$v0,$zero,$zero
.L0f13e3f0:
/*  f13e3f0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13e3f4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f13e3f8:	a060002f */ 	sb	$zero,0x2f($v1)
/*  f13e3fc:	1444fffc */ 	bne	$v0,$a0,.L0f13e3f0
/*  f13e400:	a060003f */ 	sb	$zero,0x3f($v1)
/*  f13e404:	03e00008 */ 	jr	$ra
/*  f13e408:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13e40c
/*  f13e40c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f13e410:	00057600 */ 	sll	$t6,$a1,0x18
/*  f13e414:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f13e418:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f13e41c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f13e420:	00808025 */ 	or	$s0,$a0,$zero
/*  f13e424:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f13e428:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f13e42c:	11e0000e */ 	beqz	$t7,.L0f13e468
/*  f13e430:	00808825 */ 	or	$s1,$a0,$zero
/*  f13e434:	8c980044 */ 	lw	$t8,0x44($a0)
/*  f13e438:	53000017 */ 	beqzl	$t8,.L0f13e498
/*  f13e43c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f13e440:	8e040044 */ 	lw	$a0,0x44($s0)
.L0f13e444:
/*  f13e444:	0fc4f990 */ 	jal	func0f13e640
/*  f13e448:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f13e44c:	0fc4f86c */ 	jal	func0f13e1b0
/*  f13e450:	8e040044 */ 	lw	$a0,0x44($s0)
/*  f13e454:	8e390044 */ 	lw	$t9,0x44($s1)
/*  f13e458:	5720fffa */ 	bnezl	$t9,.L0f13e444
/*  f13e45c:	8e040044 */ 	lw	$a0,0x44($s0)
/*  f13e460:	1000000d */ 	beqz	$zero,.L0f13e498
/*  f13e464:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f13e468:
/*  f13e468:	8e080040 */ 	lw	$t0,0x40($s0)
/*  f13e46c:	5100000a */ 	beqzl	$t0,.L0f13e498
/*  f13e470:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f13e474:	8e040040 */ 	lw	$a0,0x40($s0)
.L0f13e478:
/*  f13e478:	0fc4f990 */ 	jal	func0f13e640
/*  f13e47c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f13e480:	0fc4f86c */ 	jal	func0f13e1b0
/*  f13e484:	8e040040 */ 	lw	$a0,0x40($s0)
/*  f13e488:	8e290040 */ 	lw	$t1,0x40($s1)
/*  f13e48c:	5520fffa */ 	bnezl	$t1,.L0f13e478
/*  f13e490:	8e040040 */ 	lw	$a0,0x40($s0)
/*  f13e494:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f13e498:
/*  f13e498:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f13e49c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f13e4a0:	03e00008 */ 	jr	$ra
/*  f13e4a4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f13e4a8
/*  f13e4a8:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f13e4ac:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f13e4b0:	8cee028c */ 	lw	$t6,0x28c($a3)
/*  f13e4b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f13e4b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13e4bc:	1080000f */ 	beqz	$a0,.L0f13e4fc
/*  f13e4c0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f13e4c4:	8c84001c */ 	lw	$a0,0x1c($a0)
/*  f13e4c8:	1080000c */ 	beqz	$a0,.L0f13e4fc
/*  f13e4cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4d0:	908f0000 */ 	lbu	$t7,0x0($a0)
/*  f13e4d4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f13e4d8:	15e10008 */ 	bne	$t7,$at,.L0f13e4fc
/*  f13e4dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4e0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f13e4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4e8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f13e4ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f13e4f0:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f13e4f4:	10000029 */ 	beqz	$zero,.L0f13e59c
/*  f13e4f8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
.L0f13e4fc:
/*  f13e4fc:	0c004b70 */ 	jal	random
/*  f13e500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e504:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f13e508:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f13e50c:	8cf8006c */ 	lw	$t8,0x6c($a3)
/*  f13e510:	00404025 */ 	or	$t0,$v0,$zero
/*  f13e514:	00003025 */ 	or	$a2,$zero,$zero
/*  f13e518:	13000003 */ 	beqz	$t8,.L0f13e528
/*  f13e51c:	00001825 */ 	or	$v1,$zero,$zero
/*  f13e520:	10000001 */ 	beqz	$zero,.L0f13e528
/*  f13e524:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f13e528:
/*  f13e528:	8cf90068 */ 	lw	$t9,0x68($a3)
/*  f13e52c:	00002825 */ 	or	$a1,$zero,$zero
/*  f13e530:	00001025 */ 	or	$v0,$zero,$zero
/*  f13e534:	13200003 */ 	beqz	$t9,.L0f13e544
/*  f13e538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e53c:	10000001 */ 	beqz	$zero,.L0f13e544
/*  f13e540:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f13e544:
/*  f13e544:	8ce90064 */ 	lw	$t1,0x64($a3)
/*  f13e548:	11200003 */ 	beqz	$t1,.L0f13e558
/*  f13e54c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e550:	10000001 */ 	beqz	$zero,.L0f13e558
/*  f13e554:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f13e558:
/*  f13e558:	8cea0070 */ 	lw	$t2,0x70($a3)
/*  f13e55c:	11400003 */ 	beqz	$t2,.L0f13e56c
/*  f13e560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e564:	10000001 */ 	beqz	$zero,.L0f13e56c
/*  f13e568:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f13e56c:
/*  f13e56c:	00455821 */ 	addu	$t3,$v0,$a1
/*  f13e570:	01636021 */ 	addu	$t4,$t3,$v1
/*  f13e574:	01866821 */ 	addu	$t5,$t4,$a2
/*  f13e578:	010d001b */ 	divu	$zero,$t0,$t5
/*  f13e57c:	00002010 */ 	mfhi	$a0
/*  f13e580:	15a00002 */ 	bnez	$t5,.L0f13e58c
/*  f13e584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e588:	0007000d */ 	break	0x7
.L0f13e58c:
/*  f13e58c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f13e590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e594:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f13e598:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
.L0f13e59c:
/*  f13e59c:	8cee0288 */ 	lw	$t6,0x288($a3)
/*  f13e5a0:	0fc54a31 */ 	jal	optionsGetPaintball
/*  f13e5a4:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f13e5a8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f13e5ac:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f13e5b0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f13e5b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f13e5b8:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f13e5bc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f13e5c0:	03e00008 */ 	jr	$ra
/*  f13e5c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13e5c8
/*  f13e5c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f13e5cc:	10800011 */ 	beqz	$a0,.L0f13e614
/*  f13e5d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13e5d4:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f13e5d8:	1060000e */ 	beqz	$v1,.L0f13e614
/*  f13e5dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e5e0:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f13e5e4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13e5e8:	3c058008 */ 	lui	$a1,%hi(var8007f744)
/*  f13e5ec:	10410004 */ 	beq	$v0,$at,.L0f13e600
/*  f13e5f0:	24a5f744 */ 	addiu	$a1,$a1,%lo(var8007f744)
/*  f13e5f4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f13e5f8:	14410006 */ 	bne	$v0,$at,.L0f13e614
/*  f13e5fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13e600:
/*  f13e600:	84640010 */ 	lh	$a0,0x10($v1)
/*  f13e604:	0fc09451 */ 	jal	bodyGetBloodColour
/*  f13e608:	00003025 */ 	or	$a2,$zero,$zero
/*  f13e60c:	10000009 */ 	beqz	$zero,.L0f13e634
/*  f13e610:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f13e614:
/*  f13e614:	3c058008 */ 	lui	$a1,%hi(var8007f744)
/*  f13e618:	24a5f744 */ 	addiu	$a1,$a1,%lo(var8007f744)
/*  f13e61c:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f13e620:	240e0040 */ 	addiu	$t6,$zero,0x40
/*  f13e624:	a0ae0000 */ 	sb	$t6,0x0($a1)
/*  f13e628:	a0a20001 */ 	sb	$v0,0x1($a1)
/*  f13e62c:	a0a20002 */ 	sb	$v0,0x2($a1)
/*  f13e630:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f13e634:
/*  f13e634:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f13e638:	03e00008 */ 	jr	$ra
/*  f13e63c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13e640
/*  f13e640:	8c8e006c */ 	lw	$t6,0x6c($a0)
/*  f13e644:	3c03800a */ 	lui	$v1,%hi(var8009cc50)
/*  f13e648:	2463cc50 */ 	addiu	$v1,$v1,%lo(var8009cc50)
/*  f13e64c:	000ec680 */ 	sll	$t8,$t6,0x1a
/*  f13e650:	0700003a */ 	bltz	$t8,.L0f13e73c
/*  f13e654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e658:	8c990060 */ 	lw	$t9,0x60($a0)
/*  f13e65c:	3c02800a */ 	lui	$v0,%hi(var8009cc40)
/*  f13e660:	3c0a800a */ 	lui	$t2,%hi(var8009cc40)
/*  f13e664:	53200007 */ 	beqzl	$t9,.L0f13e684
/*  f13e668:	848b0068 */ 	lh	$t3,0x68($a0)
/*  f13e66c:	8c42cc40 */ 	lw	$v0,%lo(var8009cc40)($v0)
/*  f13e670:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f13e674:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f13e678:	10000008 */ 	beqz	$zero,.L0f13e69c
/*  f13e67c:	a4490000 */ 	sh	$t1,0x0($v0)
/*  f13e680:	848b0068 */ 	lh	$t3,0x68($a0)
.L0f13e684:
/*  f13e684:	8d4acc40 */ 	lw	$t2,%lo(var8009cc40)($t2)
/*  f13e688:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f13e68c:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f13e690:	944d0000 */ 	lhu	$t5,0x0($v0)
/*  f13e694:	25aeffff */ 	addiu	$t6,$t5,-1
/*  f13e698:	a44e0000 */ 	sh	$t6,0x0($v0)
.L0f13e69c:
/*  f13e69c:	908f006d */ 	lbu	$t7,0x6d($a0)
/*  f13e6a0:	55e00004 */ 	bnezl	$t7,.L0f13e6b4
/*  f13e6a4:	9099006f */ 	lbu	$t9,0x6f($a0)
/*  f13e6a8:	a085006d */ 	sb	$a1,0x6d($a0)
/*  f13e6ac:	a085006e */ 	sb	$a1,0x6e($a0)
/*  f13e6b0:	9099006f */ 	lbu	$t9,0x6f($a0)
.L0f13e6b4:
/*  f13e6b4:	3c02800a */ 	lui	$v0,%hi(var8009cc48)
/*  f13e6b8:	2442cc48 */ 	addiu	$v0,$v0,%lo(var8009cc48)
/*  f13e6bc:	37280020 */ 	ori	$t0,$t9,0x20
/*  f13e6c0:	a088006f */ 	sb	$t0,0x6f($a0)
/*  f13e6c4:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f13e6c8:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f13e6cc:	3c0f8008 */ 	lui	$t7,%hi(var8007f764)
/*  f13e6d0:	252bffff */ 	addiu	$t3,$t1,-1
/*  f13e6d4:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f13e6d8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f13e6dc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f13e6e0:	908d006a */ 	lbu	$t5,0x6a($a0)
/*  f13e6e4:	3c02800a */ 	lui	$v0,%hi(var8009cc54)
/*  f13e6e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13e6ec:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f13e6f0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f13e6f4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13e6f8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f13e6fc:	91eff764 */ 	lbu	$t7,%lo(var8007f764)($t7)
/*  f13e700:	2442cc54 */ 	addiu	$v0,$v0,%lo(var8009cc54)
/*  f13e704:	15e10005 */ 	bne	$t7,$at,.L0f13e71c
/*  f13e708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e70c:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f13e710:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f13e714:	10000006 */ 	beqz	$zero,.L0f13e730
/*  f13e718:	ac590000 */ 	sw	$t9,0x0($v0)
.L0f13e71c:
/*  f13e71c:	3c02800a */ 	lui	$v0,%hi(var8009cc58)
/*  f13e720:	2442cc58 */ 	addiu	$v0,$v0,%lo(var8009cc58)
/*  f13e724:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f13e728:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f13e72c:	ac490000 */ 	sw	$t1,0x0($v0)
.L0f13e730:
/*  f13e730:	908b006f */ 	lbu	$t3,0x6f($a0)
/*  f13e734:	316affef */ 	andi	$t2,$t3,0xffef
/*  f13e738:	a08a006f */ 	sb	$t2,0x6f($a0)
.L0f13e73c:
/*  f13e73c:	03e00008 */ 	jr	$ra
/*  f13e740:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13e744
/*  f13e744:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f13e748:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f13e74c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f13e750:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f13e754:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f13e758:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f13e75c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f13e760:	10930007 */ 	beq	$a0,$s3,.L0f13e780
/*  f13e764:	00803025 */ 	or	$a2,$a0,$zero
/*  f13e768:	3c0e800a */ 	lui	$t6,%hi(var8009cc40)
/*  f13e76c:	8dcecc40 */ 	lw	$t6,%lo(var8009cc40)($t6)
/*  f13e770:	00047840 */ 	sll	$t7,$a0,0x1
/*  f13e774:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13e778:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f13e77c:	1320007d */ 	beqz	$t9,.L0f13e974
.L0f13e780:
/*  f13e780:	3c0c800a */ 	lui	$t4,%hi(var8009cc44)
/*  f13e784:	8d8ccc44 */ 	lw	$t4,%lo(var8009cc44)($t4)
/*  f13e788:	44800000 */ 	mtc1	$zero,$f0
/*  f13e78c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f13e790:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f13e794:	240affff */ 	addiu	$t2,$zero,-1
/*  f13e798:	02608025 */ 	or	$s0,$s3,$zero
/*  f13e79c:	02608825 */ 	or	$s1,$s3,$zero
/*  f13e7a0:	02609025 */ 	or	$s2,$s3,$zero
/*  f13e7a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f13e7a8:	00005825 */ 	or	$t3,$zero,$zero
/*  f13e7ac:	19800043 */ 	blez	$t4,.L0f13e8bc
/*  f13e7b0:	00003825 */ 	or	$a3,$zero,$zero
/*  f13e7b4:	3c04800a */ 	lui	$a0,%hi(var800a41b0)
/*  f13e7b8:	3c1f8008 */ 	lui	$ra,%hi(var8007f75c)
/*  f13e7bc:	27fff75c */ 	addiu	$ra,$ra,%lo(var8007f75c)
/*  f13e7c0:	8c8441b0 */ 	lw	$a0,%lo(var800a41b0)($a0)
/*  f13e7c4:	240d0003 */ 	addiu	$t5,$zero,0x3
.L0f13e7c8:
/*  f13e7c8:	808f006f */ 	lb	$t7,0x6f($a0)
/*  f13e7cc:	05e30038 */ 	bgezl	$t7,.L0f13e8b0
/*  f13e7d0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e7d4:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f13e7d8:	00187680 */ 	sll	$t6,$t8,0x1a
/*  f13e7dc:	05c20034 */ 	bltzl	$t6,.L0f13e8b0
/*  f13e7e0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e7e4:	50d3000c */ 	beql	$a2,$s3,.L0f13e818
/*  f13e7e8:	9082006a */ 	lbu	$v0,0x6a($a0)
/*  f13e7ec:	14c00004 */ 	bnez	$a2,.L0f13e800
/*  f13e7f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e7f4:	8c8f0060 */ 	lw	$t7,0x60($a0)
/*  f13e7f8:	55e00007 */ 	bnezl	$t7,.L0f13e818
/*  f13e7fc:	9082006a */ 	lbu	$v0,0x6a($a0)
.L0f13e800:
/*  f13e800:	50c0002b */ 	beqzl	$a2,.L0f13e8b0
/*  f13e804:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e808:	84980068 */ 	lh	$t8,0x68($a0)
/*  f13e80c:	54d80028 */ 	bnel	$a2,$t8,.L0f13e8b0
/*  f13e810:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e814:	9082006a */ 	lbu	$v0,0x6a($a0)
.L0f13e818:
/*  f13e818:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f13e81c:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f13e820:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13e824:	03f97021 */ 	addu	$t6,$ra,$t9
/*  f13e828:	91cf0008 */ 	lbu	$t7,0x8($t6)
/*  f13e82c:	2841000c */ 	slti	$at,$v0,0xc
/*  f13e830:	55af0017 */ 	bnel	$t5,$t7,.L0f13e890
/*  f13e834:	8c820070 */ 	lw	$v0,0x70($a0)
/*  f13e838:	1420000c */ 	bnez	$at,.L0f13e86c
/*  f13e83c:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f13e840:	2841000d */ 	slti	$at,$v0,0xd
/*  f13e844:	5020000a */ 	beqzl	$at,.L0f13e870
/*  f13e848:	8c820070 */ 	lw	$v0,0x70($a0)
/*  f13e84c:	8c820070 */ 	lw	$v0,0x70($a0)
/*  f13e850:	0002c102 */ 	srl	$t8,$v0,0x4
/*  f13e854:	0308082b */ 	sltu	$at,$t8,$t0
/*  f13e858:	50200015 */ 	beqzl	$at,.L0f13e8b0
/*  f13e85c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e860:	03004025 */ 	or	$t0,$t8,$zero
/*  f13e864:	10000011 */ 	beqz	$zero,.L0f13e8ac
/*  f13e868:	00a08025 */ 	or	$s0,$a1,$zero
.L0f13e86c:
/*  f13e86c:	8c820070 */ 	lw	$v0,0x70($a0)
.L0f13e870:
/*  f13e870:	0002c902 */ 	srl	$t9,$v0,0x4
/*  f13e874:	0329082b */ 	sltu	$at,$t9,$t1
/*  f13e878:	5020000d */ 	beqzl	$at,.L0f13e8b0
/*  f13e87c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e880:	03204825 */ 	or	$t1,$t9,$zero
/*  f13e884:	10000009 */ 	beqz	$zero,.L0f13e8ac
/*  f13e888:	00a08825 */ 	or	$s1,$a1,$zero
/*  f13e88c:	8c820070 */ 	lw	$v0,0x70($a0)
.L0f13e890:
/*  f13e890:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f13e894:	00027102 */ 	srl	$t6,$v0,0x4
/*  f13e898:	01ca082b */ 	sltu	$at,$t6,$t2
/*  f13e89c:	50200004 */ 	beqzl	$at,.L0f13e8b0
/*  f13e8a0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13e8a4:	01c05025 */ 	or	$t2,$t6,$zero
/*  f13e8a8:	00a09025 */ 	or	$s2,$a1,$zero
.L0f13e8ac:
/*  f13e8ac:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f13e8b0:
/*  f13e8b0:	00ac082a */ 	slt	$at,$a1,$t4
/*  f13e8b4:	1420ffc4 */ 	bnez	$at,.L0f13e7c8
/*  f13e8b8:	2484007c */ 	addiu	$a0,$a0,124
.L0f13e8bc:
/*  f13e8bc:	01671021 */ 	addu	$v0,$t3,$a3
/*  f13e8c0:	18400006 */ 	blez	$v0,.L0f13e8dc
/*  f13e8c4:	3c01800a */ 	lui	$at,0x800a
/*  f13e8c8:	448b2000 */ 	mtc1	$t3,$f4
/*  f13e8cc:	44824000 */ 	mtc1	$v0,$f8
/*  f13e8d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13e8d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13e8d8:	460a3003 */ 	div.s	$f0,$f6,$f10
.L0f13e8dc:
/*  f13e8dc:	c430cc78 */ 	lwc1	$f16,-0x3388($at)
/*  f13e8e0:	4600803c */ 	c.lt.s	$f16,$f0
/*  f13e8e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e8e8:	45000017 */ 	bc1f	.L0f13e948
/*  f13e8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e8f0:	16130003 */ 	bne	$s0,$s3,.L0f13e900
/*  f13e8f4:	3c02800a */ 	lui	$v0,%hi(var800a41b0)
/*  f13e8f8:	12330013 */ 	beq	$s1,$s3,.L0f13e948
/*  f13e8fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13e900:
/*  f13e900:	12130009 */ 	beq	$s0,$s3,.L0f13e928
/*  f13e904:	8c4241b0 */ 	lw	$v0,%lo(var800a41b0)($v0)
/*  f13e908:	00107940 */ 	sll	$t7,$s0,0x5
/*  f13e90c:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f13e910:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13e914:	01e22021 */ 	addu	$a0,$t7,$v0
/*  f13e918:	0fc4f990 */ 	jal	func0f13e640
/*  f13e91c:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f13e920:	10000015 */ 	beqz	$zero,.L0f13e978
/*  f13e924:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f13e928:
/*  f13e928:	0011c140 */ 	sll	$t8,$s1,0x5
/*  f13e92c:	0311c023 */ 	subu	$t8,$t8,$s1
/*  f13e930:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13e934:	03022021 */ 	addu	$a0,$t8,$v0
/*  f13e938:	0fc4f990 */ 	jal	func0f13e640
/*  f13e93c:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f13e940:	1000000d */ 	beqz	$zero,.L0f13e978
/*  f13e944:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f13e948:
/*  f13e948:	1253000a */ 	beq	$s2,$s3,.L0f13e974
/*  f13e94c:	0012c940 */ 	sll	$t9,$s2,0x5
/*  f13e950:	3c0e800a */ 	lui	$t6,%hi(var800a41b0)
/*  f13e954:	8dce41b0 */ 	lw	$t6,%lo(var800a41b0)($t6)
/*  f13e958:	0332c823 */ 	subu	$t9,$t9,$s2
/*  f13e95c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13e960:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f13e964:	0fc4f990 */ 	jal	func0f13e640
/*  f13e968:	032e2021 */ 	addu	$a0,$t9,$t6
/*  f13e96c:	10000002 */ 	beqz	$zero,.L0f13e978
/*  f13e970:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f13e974:
/*  f13e974:	00001025 */ 	or	$v0,$zero,$zero
.L0f13e978:
/*  f13e978:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f13e97c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f13e980:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f13e984:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f13e988:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f13e98c:	03e00008 */ 	jr	$ra
/*  f13e990:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f13e994
/*  f13e994:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f13e998:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f13e99c:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f13e9a0:	3c0a800a */ 	lui	$t2,%hi(g_Rooms)
/*  f13e9a4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f13e9a8:	0000f825 */ 	or	$ra,$zero,$zero
/*  f13e9ac:	254a4928 */ 	addiu	$t2,$t2,%lo(g_Rooms)
/*  f13e9b0:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f13e9b4:	00004025 */ 	or	$t0,$zero,$zero
/*  f13e9b8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f13e9bc:	240b008c */ 	addiu	$t3,$zero,0x8c
.L0f13e9c0:
/*  f13e9c0:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x2bc)
/*  f13e9c4:	8d29a27c */ 	lw	$t1,%lo(g_Vars+0x2bc)($t1)
/*  f13e9c8:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f13e9cc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f13e9d0:	19200031 */ 	blez	$t1,.L0f13ea98
/*  f13e9d4:	00001825 */ 	or	$v1,$zero,$zero
.L0f13e9d8:
/*  f13e9d8:	14600003 */ 	bnez	$v1,.L0f13e9e8
/*  f13e9dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e9e0:	10000008 */ 	beqz	$zero,.L0f13ea04
/*  f13e9e4:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f13e9e8:
/*  f13e9e8:	006b0019 */ 	multu	$v1,$t3
/*  f13e9ec:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f13e9f0:	00007812 */ 	mflo	$t7
/*  f13e9f4:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13e9f8:	97060000 */ 	lhu	$a2,0x0($t8)
/*  f13e9fc:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f13ea00:	03203025 */ 	or	$a2,$t9,$zero
.L0f13ea04:
/*  f13ea04:	14600003 */ 	bnez	$v1,.L0f13ea14
/*  f13ea08:	2cc50001 */ 	sltiu	$a1,$a2,0x1
/*  f13ea0c:	10000008 */ 	beqz	$zero,.L0f13ea30
/*  f13ea10:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f13ea14:
/*  f13ea14:	006b0019 */ 	multu	$v1,$t3
/*  f13ea18:	8d4e0000 */ 	lw	$t6,0x0($t2)
/*  f13ea1c:	00007812 */ 	mflo	$t7
/*  f13ea20:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13ea24:	97040000 */ 	lhu	$a0,0x0($t8)
/*  f13ea28:	30990008 */ 	andi	$t9,$a0,0x8
/*  f13ea2c:	03202025 */ 	or	$a0,$t9,$zero
.L0f13ea30:
/*  f13ea30:	15000006 */ 	bnez	$t0,.L0f13ea4c
/*  f13ea34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea38:	10a00002 */ 	beqz	$a1,.L0f13ea44
/*  f13ea3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea40:	2c850001 */ 	sltiu	$a1,$a0,0x1
.L0f13ea44:
/*  f13ea44:	10000005 */ 	beqz	$zero,.L0f13ea5c
/*  f13ea48:	00a01025 */ 	or	$v0,$a1,$zero
.L0f13ea4c:
/*  f13ea4c:	150d0003 */ 	bne	$t0,$t5,.L0f13ea5c
/*  f13ea50:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13ea54:	10000001 */ 	beqz	$zero,.L0f13ea5c
/*  f13ea58:	2cc20001 */ 	sltiu	$v0,$a2,0x1
.L0f13ea5c:
/*  f13ea5c:	5040000b */ 	beqzl	$v0,.L0f13ea8c
/*  f13ea60:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13ea64:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f13ea68:	00037840 */ 	sll	$t7,$v1,0x1
/*  f13ea6c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f13ea70:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f13ea74:	00e2082a */ 	slt	$at,$a3,$v0
/*  f13ea78:	50200004 */ 	beqzl	$at,.L0f13ea8c
/*  f13ea7c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13ea80:	00403825 */ 	or	$a3,$v0,$zero
/*  f13ea84:	00608025 */ 	or	$s0,$v1,$zero
/*  f13ea88:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f13ea8c:
/*  f13ea8c:	0069082a */ 	slt	$at,$v1,$t1
/*  f13ea90:	1420ffd1 */ 	bnez	$at,.L0f13e9d8
/*  f13ea94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13ea98:
/*  f13ea98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f13ea9c:	1201001b */ 	beq	$s0,$at,.L0f13eb0c
/*  f13eaa0:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f13eaa4:	16000004 */ 	bnez	$s0,.L0f13eab8
/*  f13eaa8:	8d830000 */ 	lw	$v1,0x0($t4)
/*  f13eaac:	3c02800a */ 	lui	$v0,%hi(var8009cc5c)
/*  f13eab0:	10000003 */ 	beqz	$zero,.L0f13eac0
/*  f13eab4:	8c42cc5c */ 	lw	$v0,%lo(var8009cc5c)($v0)
.L0f13eab8:
/*  f13eab8:	3c02800a */ 	lui	$v0,%hi(var8009cc64)
/*  f13eabc:	8c42cc64 */ 	lw	$v0,%lo(var8009cc64)($v0)
.L0f13eac0:
/*  f13eac0:	00797021 */ 	addu	$t6,$v1,$t9
/*  f13eac4:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f13eac8:	02002025 */ 	or	$a0,$s0,$zero
/*  f13eacc:	004f082a */ 	slt	$at,$v0,$t7
/*  f13ead0:	1020000e */ 	beqz	$at,.L0f13eb0c
/*  f13ead4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ead8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f13eadc:	0fc4f9d1 */ 	jal	func0f13e744
/*  f13eae0:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f13eae4:	3c0a800a */ 	lui	$t2,%hi(g_Rooms)
/*  f13eae8:	3c0c800a */ 	lui	$t4,%hi(var8009cc40)
/*  f13eaec:	258ccc40 */ 	addiu	$t4,$t4,%lo(var8009cc40)
/*  f13eaf0:	254a4928 */ 	addiu	$t2,$t2,%lo(g_Rooms)
/*  f13eaf4:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f13eaf8:	240b008c */ 	addiu	$t3,$zero,0x8c
/*  f13eafc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f13eb00:	10400002 */ 	beqz	$v0,.L0f13eb0c
/*  f13eb04:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f13eb08:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f13eb0c:
/*  f13eb0c:	17e00004 */ 	bnez	$ra,.L0f13eb20
/*  f13eb10:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f13eb14:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13eb18:	1501ffa9 */ 	bne	$t0,$at,.L0f13e9c0
/*  f13eb1c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13eb20:
/*  f13eb20:	57e00004 */ 	bnezl	$ra,.L0f13eb34
/*  f13eb24:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f13eb28:	0fc4f9d1 */ 	jal	func0f13e744
/*  f13eb2c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f13eb30:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f13eb34:
/*  f13eb34:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f13eb38:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f13eb3c:	03e00008 */ 	jr	$ra
/*  f13eb40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13eb44
.late_rodata
glabel var7f1b5d08
.word 0x3f19999a
glabel var7f1b5d0c
.word 0x3fc90fdb
glabel var7f1b5d10
.word 0x3e4ccccd
glabel var7f1b5d14
.word 0x3f19999a
glabel var7f1b5d18
.word 0x3e4ccccd
.text
/*  f13eb44:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f13eb48:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f13eb4c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f13eb50:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f13eb54:	8e0e0034 */ 	lw	$t6,0x34($s0)
/*  f13eb58:	3c014000 */ 	lui	$at,0x4000
/*  f13eb5c:	44814000 */ 	mtc1	$at,$f8
/*  f13eb60:	448e2000 */ 	mtc1	$t6,$f4
/*  f13eb64:	3c013e80 */ 	lui	$at,0x3e80
/*  f13eb68:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f13eb6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13eb70:	44812000 */ 	mtc1	$at,$f4
/*  f13eb74:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f13eb78:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f13eb7c:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f13eb80:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f13eb84:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f13eb88:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f13eb8c:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f13eb90:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f13eb94:	46045702 */ 	mul.s	$f28,$f10,$f4
/*  f13eb98:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f13eb9c:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f13eba0:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f13eba4:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f13eba8:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f13ebac:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f13ebb0:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f13ebb4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f13ebb8:	3c047f1b */ 	lui	$a0,%hi(var7f1b5a54)
/*  f13ebbc:	3c058008 */ 	lui	$a1,%hi(var8007f750)
/*  f13ebc0:	46000506 */ 	mov.s	$f20,$f0
/*  f13ebc4:	24a5f750 */ 	addiu	$a1,$a1,%lo(var8007f750)
/*  f13ebc8:	0c0036cc */ 	jal	func0000db30
/*  f13ebcc:	24845a54 */ 	addiu	$a0,$a0,%lo(var7f1b5a54)
/*  f13ebd0:	44803000 */ 	mtc1	$zero,$f6
/*  f13ebd4:	3c018008 */ 	lui	$at,%hi(var8007f740)
/*  f13ebd8:	ac20f740 */ 	sw	$zero,%lo(var8007f740)($at)
/*  f13ebdc:	4606a032 */ 	c.eq.s	$f20,$f6
/*  f13ebe0:	3c014270 */ 	lui	$at,0x4270
/*  f13ebe4:	3c038008 */ 	lui	$v1,%hi(var8007f748)
/*  f13ebe8:	3c09800a */ 	lui	$t1,%hi(var8009cc74)
/*  f13ebec:	45030008 */ 	bc1tl	.L0f13ec10
/*  f13ebf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ebf4:	44811000 */ 	mtc1	$at,$f2
/*  f13ebf8:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ebfc:	4602a032 */ 	c.eq.s	$f20,$f2
/*  f13ec00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ec04:	45020007 */ 	bc1fl	.L0f13ec24
/*  f13ec08:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f13ec0c:	3c013f80 */ 	lui	$at,0x3f80
.L0f13ec10:
/*  f13ec10:	44814000 */ 	mtc1	$at,$f8
/*  f13ec14:	2463f748 */ 	addiu	$v1,$v1,%lo(var8007f748)
/*  f13ec18:	1000000d */ 	beqz	$zero,.L0f13ec50
/*  f13ec1c:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f13ec20:	8e0f0284 */ 	lw	$t7,0x284($s0)
.L0f13ec24:
/*  f13ec24:	44813000 */ 	mtc1	$at,$f6
/*  f13ec28:	46141103 */ 	div.s	$f4,$f2,$f20
/*  f13ec2c:	c5ea1848 */ 	lwc1	$f10,0x1848($t7)
/*  f13ec30:	3c038008 */ 	lui	$v1,%hi(var8007f748)
/*  f13ec34:	2463f748 */ 	addiu	$v1,$v1,%lo(var8007f748)
/*  f13ec38:	460aa003 */ 	div.s	$f0,$f20,$f10
/*  f13ec3c:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f13ec40:	44813000 */ 	mtc1	$at,$f6
/*  f13ec44:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f13ec48:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f13ec4c:	e4640000 */ 	swc1	$f4,0x0($v1)
.L0f13ec50:
/*  f13ec50:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ec54:	4481d000 */ 	mtc1	$at,$f26
/*  f13ec58:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f13ec5c:	3c18800a */ 	lui	$t8,%hi(var8009cc4c)
/*  f13ec60:	3c19800a */ 	lui	$t9,%hi(var8009cc50)
/*  f13ec64:	4608d283 */ 	div.s	$f10,$f26,$f8
/*  f13ec68:	8f39cc50 */ 	lw	$t9,%lo(var8009cc50)($t9)
/*  f13ec6c:	8f18cc4c */ 	lw	$t8,%lo(var8009cc4c)($t8)
/*  f13ec70:	3c08800a */ 	lui	$t0,%hi(var8009cc70)
/*  f13ec74:	8d08cc70 */ 	lw	$t0,%lo(var8009cc70)($t0)
/*  f13ec78:	3c018008 */ 	lui	$at,0x8008
/*  f13ec7c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f13ec80:	e42af74c */ 	swc1	$f10,-0x8b4($at)
/*  f13ec84:	0048082a */ 	slt	$at,$v0,$t0
/*  f13ec88:	10200005 */ 	beqz	$at,.L0f13eca0
/*  f13ec8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ec90:	0fc4fa65 */ 	jal	func0f13e994
/*  f13ec94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ec98:	1000000e */ 	beqz	$zero,.L0f13ecd4
/*  f13ec9c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13eca0:
/*  f13eca0:	8d29cc74 */ 	lw	$t1,%lo(var8009cc74)($t1)
/*  f13eca4:	0049082a */ 	slt	$at,$v0,$t1
/*  f13eca8:	1020000a */ 	beqz	$at,.L0f13ecd4
/*  f13ecac:	3c028008 */ 	lui	$v0,%hi(var8007f834)
/*  f13ecb0:	8c42f834 */ 	lw	$v0,%lo(var8007f834)($v0)
/*  f13ecb4:	3c018008 */ 	lui	$at,%hi(var8007f834)
/*  f13ecb8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13ecbc:	ac22f834 */ 	sw	$v0,%lo(var8007f834)($at)
/*  f13ecc0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f13ecc4:	14410003 */ 	bne	$v0,$at,.L0f13ecd4
/*  f13ecc8:	3c018008 */ 	lui	$at,%hi(var8007f834)
/*  f13eccc:	0fc4fa65 */ 	jal	func0f13e994
/*  f13ecd0:	ac20f834 */ 	sw	$zero,%lo(var8007f834)($at)
.L0f13ecd4:
/*  f13ecd4:	3c02800a */ 	lui	$v0,%hi(var8009cc44)
/*  f13ecd8:	8c42cc44 */ 	lw	$v0,%lo(var8009cc44)($v0)
/*  f13ecdc:	3c11800a */ 	lui	$s1,%hi(var800a41b0)
/*  f13ece0:	8e3141b0 */ 	lw	$s1,%lo(var800a41b0)($s1)
/*  f13ece4:	184001b1 */ 	blez	$v0,.L0f13f3ac
/*  f13ece8:	0000b825 */ 	or	$s7,$zero,$zero
/*  f13ecec:	3c013f00 */ 	lui	$at,0x3f00
/*  f13ecf0:	3c1e8008 */ 	lui	$s8,%hi(var800845dc)
/*  f13ecf4:	27b300f8 */ 	addiu	$s3,$sp,0xf8
/*  f13ecf8:	4481a000 */ 	mtc1	$at,$f20
/*  f13ecfc:	0260b025 */ 	or	$s6,$s3,$zero
/*  f13ed00:	27de45dc */ 	addiu	$s8,$s8,%lo(var800845dc)
/*  f13ed04:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f13ed08:	27b400c8 */ 	addiu	$s4,$sp,0xc8
/*  f13ed0c:	24120004 */ 	addiu	$s2,$zero,0x4
.L0f13ed10:
/*  f13ed10:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13ed14:	4600e006 */ 	mov.s	$f0,$f28
/*  f13ed18:	000459c2 */ 	srl	$t3,$a0,0x7
/*  f13ed1c:	516001a0 */ 	beqzl	$t3,.L0f13f3a0
/*  f13ed20:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f13ed24:	8e220070 */ 	lw	$v0,0x70($s1)
/*  f13ed28:	24010008 */ 	addiu	$at,$zero,0x8
/*  f13ed2c:	304c000f */ 	andi	$t4,$v0,0xf
/*  f13ed30:	11810015 */ 	beq	$t4,$at,.L0f13ed88
/*  f13ed34:	01801025 */ 	or	$v0,$t4,$zero
/*  f13ed38:	44823000 */ 	mtc1	$v0,$f6
/*  f13ed3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ed40:	05810004 */ 	bgez	$t4,.L0f13ed54
/*  f13ed44:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13ed48:	44814000 */ 	mtc1	$at,$f8
/*  f13ed4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ed50:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f13ed54:
/*  f13ed54:	3c014100 */ 	lui	$at,0x4100
/*  f13ed58:	44815000 */ 	mtc1	$at,$f10
/*  f13ed5c:	3c013e00 */ 	lui	$at,0x3e00
/*  f13ed60:	44814000 */ 	mtc1	$at,$f8
/*  f13ed64:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f13ed68:	3c017f1b */ 	lui	$at,%hi(var7f1b5d08)
/*  f13ed6c:	c42a5d08 */ 	lwc1	$f10,%lo(var7f1b5d08)($at)
/*  f13ed70:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f13ed74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ed78:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f13ed7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ed80:	4606e002 */ 	mul.s	$f0,$f28,$f6
/*  f13ed84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13ed88:
/*  f13ed88:	9222006d */ 	lbu	$v0,0x6d($s1)
/*  f13ed8c:	50400180 */ 	beqzl	$v0,.L0f13f390
/*  f13ed90:	34890004 */ 	ori	$t1,$a0,0x4
/*  f13ed94:	8e2d006c */ 	lw	$t5,0x6c($s1)
/*  f13ed98:	000d7ec0 */ 	sll	$t7,$t5,0x1b
/*  f13ed9c:	05e3002e */ 	bgezl	$t7,.L0f13ee58
/*  f13eda0:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f13eda4:	9223006e */ 	lbu	$v1,0x6e($s1)
/*  f13eda8:	34990080 */ 	ori	$t9,$a0,0x80
/*  f13edac:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f13edb0:	0043082a */ 	slt	$at,$v0,$v1
/*  f13edb4:	10200005 */ 	beqz	$at,.L0f13edcc
/*  f13edb8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13edbc:	a220006d */ 	sb	$zero,0x6d($s1)
/*  f13edc0:	a220006e */ 	sb	$zero,0x6e($s1)
/*  f13edc4:	a239006f */ 	sb	$t9,0x6f($s1)
/*  f13edc8:	300300ff */ 	andi	$v1,$zero,0xff
.L0f13edcc:
/*  f13edcc:	4448f800 */ 	cfc1	$t0,$31
/*  f13edd0:	44c9f800 */ 	ctc1	$t1,$31
/*  f13edd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f13edd8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f13eddc:	4449f800 */ 	cfc1	$t1,$31
/*  f13ede0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ede4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13ede8:	51200013 */ 	beqzl	$t1,.L0f13ee38
/*  f13edec:	44095000 */ 	mfc1	$t1,$f10
/*  f13edf0:	44815000 */ 	mtc1	$at,$f10
/*  f13edf4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13edf8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f13edfc:	44c9f800 */ 	ctc1	$t1,$31
/*  f13ee00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee04:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13ee08:	4449f800 */ 	cfc1	$t1,$31
/*  f13ee0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee10:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13ee14:	15200005 */ 	bnez	$t1,.L0f13ee2c
/*  f13ee18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee1c:	44095000 */ 	mfc1	$t1,$f10
/*  f13ee20:	3c018000 */ 	lui	$at,0x8000
/*  f13ee24:	10000007 */ 	beqz	$zero,.L0f13ee44
/*  f13ee28:	01214825 */ 	or	$t1,$t1,$at
.L0f13ee2c:
/*  f13ee2c:	10000005 */ 	beqz	$zero,.L0f13ee44
/*  f13ee30:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f13ee34:	44095000 */ 	mfc1	$t1,$f10
.L0f13ee38:
/*  f13ee38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee3c:	0520fffb */ 	bltz	$t1,.L0f13ee2c
/*  f13ee40:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13ee44:
/*  f13ee44:	44c8f800 */ 	ctc1	$t0,$31
/*  f13ee48:	00695021 */ 	addu	$t2,$v1,$t1
/*  f13ee4c:	1000002b */ 	beqz	$zero,.L0f13eefc
/*  f13ee50:	a22a006e */ 	sb	$t2,0x6e($s1)
/*  f13ee54:	46140100 */ 	add.s	$f4,$f0,$f20
.L0f13ee58:
/*  f13ee58:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13ee5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f13ee60:	444bf800 */ 	cfc1	$t3,$31
/*  f13ee64:	44c2f800 */ 	ctc1	$v0,$31
/*  f13ee68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee6c:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f13ee70:	4442f800 */ 	cfc1	$v0,$31
/*  f13ee74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee78:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13ee7c:	50400013 */ 	beqzl	$v0,.L0f13eecc
/*  f13ee80:	44023000 */ 	mfc1	$v0,$f6
/*  f13ee84:	44813000 */ 	mtc1	$at,$f6
/*  f13ee88:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13ee8c:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f13ee90:	44c2f800 */ 	ctc1	$v0,$31
/*  f13ee94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ee98:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13ee9c:	4442f800 */ 	cfc1	$v0,$31
/*  f13eea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eea4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13eea8:	14400005 */ 	bnez	$v0,.L0f13eec0
/*  f13eeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eeb0:	44023000 */ 	mfc1	$v0,$f6
/*  f13eeb4:	3c018000 */ 	lui	$at,0x8000
/*  f13eeb8:	10000007 */ 	beqz	$zero,.L0f13eed8
/*  f13eebc:	00411025 */ 	or	$v0,$v0,$at
.L0f13eec0:
/*  f13eec0:	10000005 */ 	beqz	$zero,.L0f13eed8
/*  f13eec4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f13eec8:	44023000 */ 	mfc1	$v0,$f6
.L0f13eecc:
/*  f13eecc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eed0:	0440fffb */ 	bltz	$v0,.L0f13eec0
/*  f13eed4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13eed8:
/*  f13eed8:	9223006e */ 	lbu	$v1,0x6e($s1)
/*  f13eedc:	44cbf800 */ 	ctc1	$t3,$31
/*  f13eee0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f13eee4:	10200003 */ 	beqz	$at,.L0f13eef4
/*  f13eee8:	00626023 */ 	subu	$t4,$v1,$v0
/*  f13eeec:	10000003 */ 	beqz	$zero,.L0f13eefc
/*  f13eef0:	a22c006e */ 	sb	$t4,0x6e($s1)
.L0f13eef4:
/*  f13eef4:	0fc4f86c */ 	jal	func0f13e1b0
/*  f13eef8:	02202025 */ 	or	$a0,$s1,$zero
.L0f13eefc:
/*  f13eefc:	9222006d */ 	lbu	$v0,0x6d($s1)
/*  f13ef00:	50400114 */ 	beqzl	$v0,.L0f13f354
/*  f13ef04:	8238006f */ 	lb	$t8,0x6f($s1)
/*  f13ef08:	922d006e */ 	lbu	$t5,0x6e($s1)
/*  f13ef0c:	44823000 */ 	mtc1	$v0,$f6
/*  f13ef10:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ef14:	448d4000 */ 	mtc1	$t5,$f8
/*  f13ef18:	05a10004 */ 	bgez	$t5,.L0f13ef2c
/*  f13ef1c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13ef20:	44812000 */ 	mtc1	$at,$f4
/*  f13ef24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ef28:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f13ef2c:
/*  f13ef2c:	04410005 */ 	bgez	$v0,.L0f13ef44
/*  f13ef30:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13ef34:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ef38:	44812000 */ 	mtc1	$at,$f4
/*  f13ef3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ef40:	46044200 */ 	add.s	$f8,$f8,$f4
.L0f13ef44:
/*  f13ef44:	46085603 */ 	div.s	$f24,$f10,$f8
/*  f13ef48:	3c017f1b */ 	lui	$at,%hi(var7f1b5d0c)
/*  f13ef4c:	4618d03c */ 	c.lt.s	$f26,$f24
/*  f13ef50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ef54:	45020003 */ 	bc1fl	.L0f13ef64
/*  f13ef58:	8e2e006c */ 	lw	$t6,0x6c($s1)
/*  f13ef5c:	4600d606 */ 	mov.s	$f24,$f26
/*  f13ef60:	8e2e006c */ 	lw	$t6,0x6c($s1)
.L0f13ef64:
/*  f13ef64:	4600c586 */ 	mov.s	$f22,$f24
/*  f13ef68:	000ec6c0 */ 	sll	$t8,$t6,0x1b
/*  f13ef6c:	070300bf */ 	bgezl	$t8,.L0f13f26c
/*  f13ef70:	00001825 */ 	or	$v1,$zero,$zero
/*  f13ef74:	c4265d0c */ 	lwc1	$f6,%lo(var7f1b5d0c)($at)
/*  f13ef78:	3c017f1b */ 	lui	$at,%hi(var7f1b5d10)
/*  f13ef7c:	c4245d10 */ 	lwc1	$f4,%lo(var7f1b5d10)($at)
/*  f13ef80:	46183502 */ 	mul.s	$f20,$f6,$f24
/*  f13ef84:	e7bc012c */ 	swc1	$f28,0x12c($sp)
/*  f13ef88:	00008025 */ 	or	$s0,$zero,$zero
/*  f13ef8c:	4604d701 */ 	sub.s	$f28,$f26,$f4
/*  f13ef90:	0c0068f7 */ 	jal	sinf
/*  f13ef94:	4600a306 */ 	mov.s	$f12,$f20
/*  f13ef98:	461c0782 */ 	mul.s	$f30,$f0,$f28
/*  f13ef9c:	4614d481 */ 	sub.s	$f18,$f26,$f20
/*  f13efa0:	3c017f1b */ 	lui	$at,%hi(var7f1b5d14)
/*  f13efa4:	c4305d14 */ 	lwc1	$f16,%lo(var7f1b5d14)($at)
/*  f13efa8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f13efac:	0fc59e59 */ 	jal	func0f167964
/*  f13efb0:	46109580 */ 	add.s	$f22,$f18,$f16
/*  f13efb4:	ae220064 */ 	sw	$v0,0x64($s1)
/*  f13efb8:	c7d00008 */ 	lwc1	$f16,0x8($s8)
/*  f13efbc:	c7ce0004 */ 	lwc1	$f14,0x4($s8)
/*  f13efc0:	c7cc0000 */ 	lwc1	$f12,0x0($s8)
/*  f13efc4:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f13efc8:	02201825 */ 	or	$v1,$s1,$zero
/*  f13efcc:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13efd0:	0093082b */ 	sltu	$at,$a0,$s3
/*  f13efd4:	10200013 */ 	beqz	$at,.L0f13f024
/*  f13efd8:	84790000 */ 	lh	$t9,0x0($v1)
.L0f13efdc:
/*  f13efdc:	4499e000 */ 	mtc1	$t9,$f28
/*  f13efe0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13efe4:	0093082b */ 	sltu	$at,$a0,$s3
/*  f13efe8:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13efec:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13eff0:	e49cffe8 */ 	swc1	$f28,-0x18($a0)
/*  f13eff4:	8468fff6 */ 	lh	$t0,-0xa($v1)
/*  f13eff8:	4488e000 */ 	mtc1	$t0,$f28
/*  f13effc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f000:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f004:	e49cffec */ 	swc1	$f28,-0x14($a0)
/*  f13f008:	8469fff8 */ 	lh	$t1,-0x8($v1)
/*  f13f00c:	4489e000 */ 	mtc1	$t1,$f28
/*  f13f010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f014:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f018:	e49cfff0 */ 	swc1	$f28,-0x10($a0)
/*  f13f01c:	1420ffef */ 	bnez	$at,.L0f13efdc
/*  f13f020:	84790000 */ 	lh	$t9,0x0($v1)
.L0f13f024:
/*  f13f024:	4499e000 */ 	mtc1	$t9,$f28
/*  f13f028:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f02c:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f030:	e49cfff4 */ 	swc1	$f28,-0xc($a0)
/*  f13f034:	8468fff6 */ 	lh	$t0,-0xa($v1)
/*  f13f038:	4488e000 */ 	mtc1	$t0,$f28
/*  f13f03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f040:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f044:	e49cfff8 */ 	swc1	$f28,-0x8($a0)
/*  f13f048:	8469fff8 */ 	lh	$t1,-0x8($v1)
/*  f13f04c:	4489e000 */ 	mtc1	$t1,$f28
/*  f13f050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f054:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f058:	e49cfffc */ 	swc1	$f28,-0x4($a0)
/*  f13f05c:	00002825 */ 	or	$a1,$zero,$zero
/*  f13f060:	27a400c8 */ 	addiu	$a0,$sp,0xc8
.L0f13f064:
/*  f13f064:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f13f068:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f13f06c:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f13f070:	460c5300 */ 	add.s	$f12,$f10,$f12
/*  f13f074:	460e0380 */ 	add.s	$f14,$f0,$f14
/*  f13f078:	1200000a */ 	beqz	$s0,.L0f13f0a4
/*  f13f07c:	46104400 */ 	add.s	$f16,$f8,$f16
/*  f13f080:	02150019 */ 	multu	$s0,$s5
/*  f13f084:	00005012 */ 	mflo	$t2
/*  f13f088:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f13f08c:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f13f090:	4606003c */ 	c.lt.s	$f0,$f6
/*  f13f094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f098:	45020003 */ 	bc1fl	.L0f13f0a8
/*  f13f09c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13f0a0:	00a08025 */ 	or	$s0,$a1,$zero
.L0f13f0a4:
/*  f13f0a4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f13f0a8:
/*  f13f0a8:	28a10004 */ 	slti	$at,$a1,0x4
/*  f13f0ac:	1420ffed */ 	bnez	$at,.L0f13f064
/*  f13f0b0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f0b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f13f0b8:	44810000 */ 	mtc1	$at,$f0
/*  f13f0bc:	3c017f1b */ 	lui	$at,%hi(var7f1b5d18)
/*  f13f0c0:	c4245d18 */ 	lwc1	$f4,%lo(var7f1b5d18)($at)
/*  f13f0c4:	460c0302 */ 	mul.s	$f12,$f0,$f12
/*  f13f0c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f13f0cc:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f13f0d0:	460e0382 */ 	mul.s	$f14,$f0,$f14
/*  f13f0d4:	02201825 */ 	or	$v1,$s1,$zero
/*  f13f0d8:	461e2080 */ 	add.s	$f2,$f4,$f30
/*  f13f0dc:	46100402 */ 	mul.s	$f16,$f0,$f16
/*  f13f0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f0e4:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f13f0e8:	c4940004 */ 	lwc1	$f20,0x4($a0)
/*  f13f0ec:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f0f0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f13f0f4:	460ea701 */ 	sub.s	$f28,$f20,$f14
/*  f13f0f8:	460a1782 */ 	mul.s	$f30,$f2,$f10
/*  f13f0fc:	5096002e */ 	beql	$a0,$s6,.L0f13f1b8
/*  f13f100:	c48afffc */ 	lwc1	$f10,-0x4($a0)
.L0f13f104:
/*  f13f104:	461c1502 */ 	mul.s	$f20,$f2,$f28
/*  f13f108:	460cf480 */ 	add.s	$f18,$f30,$f12
/*  f13f10c:	c48afffc */ 	lwc1	$f10,-0x4($a0)
/*  f13f110:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f13f114:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f118:	46105281 */ 	sub.s	$f10,$f10,$f16
/*  f13f11c:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13f120:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f124:	4600948d */ 	trunc.w.s	$f18,$f18
/*  f13f128:	460a1282 */ 	mul.s	$f10,$f2,$f10
/*  f13f12c:	460ea500 */ 	add.s	$f20,$f20,$f14
/*  f13f130:	440d9000 */ 	mfc1	$t5,$f18
/*  f13f134:	4600a50d */ 	trunc.w.s	$f20,$f20
/*  f13f138:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f13f13c:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f13f140:	46105280 */ 	add.s	$f10,$f10,$f16
/*  f13f144:	4419a000 */ 	mfc1	$t9,$f20
/*  f13f148:	01024821 */ 	addu	$t1,$t0,$v0
/*  f13f14c:	4600528d */ 	trunc.w.s	$f10,$f10
/*  f13f150:	a5390002 */ 	sh	$t9,0x2($t1)
/*  f13f154:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f158:	440b5000 */ 	mfc1	$t3,$f10
/*  f13f15c:	01827021 */ 	addu	$t6,$t4,$v0
/*  f13f160:	a5cb0004 */ 	sh	$t3,0x4($t6)
/*  f13f164:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f13f168:	846dfffc */ 	lh	$t5,-0x4($v1)
/*  f13f16c:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13f170:	a70d0008 */ 	sh	$t5,0x8($t8)
/*  f13f174:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f13f178:	8468fffe */ 	lh	$t0,-0x2($v1)
/*  f13f17c:	03224821 */ 	addu	$t1,$t9,$v0
/*  f13f180:	a528000a */ 	sh	$t0,0xa($t1)
/*  f13f184:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f188:	906afffb */ 	lbu	$t2,-0x5($v1)
/*  f13f18c:	01825821 */ 	addu	$t3,$t4,$v0
/*  f13f190:	a16a0007 */ 	sb	$t2,0x7($t3)
/*  f13f194:	c48afff4 */ 	lwc1	$f10,-0xc($a0)
/*  f13f198:	c494fff8 */ 	lwc1	$f20,-0x8($a0)
/*  f13f19c:	2442000c */ 	addiu	$v0,$v0,12
/*  f13f1a0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f13f1a4:	460ea701 */ 	sub.s	$f28,$f20,$f14
/*  f13f1a8:	460a1782 */ 	mul.s	$f30,$f2,$f10
/*  f13f1ac:	1496ffd5 */ 	bne	$a0,$s6,.L0f13f104
/*  f13f1b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f1b4:	c48afffc */ 	lwc1	$f10,-0x4($a0)
.L0f13f1b8:
/*  f13f1b8:	461c1502 */ 	mul.s	$f20,$f2,$f28
/*  f13f1bc:	460cf480 */ 	add.s	$f18,$f30,$f12
/*  f13f1c0:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f13f1c4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f1c8:	46105281 */ 	sub.s	$f10,$f10,$f16
/*  f13f1cc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13f1d0:	4600948d */ 	trunc.w.s	$f18,$f18
/*  f13f1d4:	460a1282 */ 	mul.s	$f10,$f2,$f10
/*  f13f1d8:	460ea500 */ 	add.s	$f20,$f20,$f14
/*  f13f1dc:	440d9000 */ 	mfc1	$t5,$f18
/*  f13f1e0:	4600a50d */ 	trunc.w.s	$f20,$f20
/*  f13f1e4:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f13f1e8:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f13f1ec:	46105280 */ 	add.s	$f10,$f10,$f16
/*  f13f1f0:	4419a000 */ 	mfc1	$t9,$f20
/*  f13f1f4:	01024821 */ 	addu	$t1,$t0,$v0
/*  f13f1f8:	4600528d */ 	trunc.w.s	$f10,$f10
/*  f13f1fc:	a5390002 */ 	sh	$t9,0x2($t1)
/*  f13f200:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f204:	440b5000 */ 	mfc1	$t3,$f10
/*  f13f208:	01827021 */ 	addu	$t6,$t4,$v0
/*  f13f20c:	a5cb0004 */ 	sh	$t3,0x4($t6)
/*  f13f210:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f13f214:	846dfffc */ 	lh	$t5,-0x4($v1)
/*  f13f218:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13f21c:	a70d0008 */ 	sh	$t5,0x8($t8)
/*  f13f220:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f13f224:	8468fffe */ 	lh	$t0,-0x2($v1)
/*  f13f228:	03224821 */ 	addu	$t1,$t9,$v0
/*  f13f22c:	a528000a */ 	sh	$t0,0xa($t1)
/*  f13f230:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f234:	906afffb */ 	lbu	$t2,-0x5($v1)
/*  f13f238:	01825821 */ 	addu	$t3,$t4,$v0
/*  f13f23c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f13f240:	a16a0007 */ 	sb	$t2,0x7($t3)
/*  f13f244:	4618c600 */ 	add.s	$f24,$f24,$f24
/*  f13f248:	3c013f00 */ 	lui	$at,0x3f00
/*  f13f24c:	4481a000 */ 	mtc1	$at,$f20
/*  f13f250:	4618d03c */ 	c.lt.s	$f26,$f24
/*  f13f254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f258:	45020003 */ 	bc1fl	.L0f13f268
/*  f13f25c:	c7bc012c */ 	lwc1	$f28,0x12c($sp)
/*  f13f260:	4600d606 */ 	mov.s	$f24,$f26
/*  f13f264:	c7bc012c */ 	lwc1	$f28,0x12c($sp)
.L0f13f268:
/*  f13f268:	00001825 */ 	or	$v1,$zero,$zero
.L0f13f26c:
/*  f13f26c:	02201025 */ 	or	$v0,$s1,$zero
.L0f13f270:
/*  f13f270:	4616d03c */ 	c.lt.s	$f26,$f22
/*  f13f274:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13f278:	3c014f80 */ 	lui	$at,0x4f80
/*  f13f27c:	45020003 */ 	bc1fl	.L0f13f28c
/*  f13f280:	904e0033 */ 	lbu	$t6,0x33($v0)
/*  f13f284:	4600d586 */ 	mov.s	$f22,$f26
/*  f13f288:	904e0033 */ 	lbu	$t6,0x33($v0)
.L0f13f28c:
/*  f13f28c:	448e5000 */ 	mtc1	$t6,$f10
/*  f13f290:	05c10004 */ 	bgez	$t6,.L0f13f2a4
/*  f13f294:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f13f298:	44813000 */ 	mtc1	$at,$f6
/*  f13f29c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f2a0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f13f2a4:
/*  f13f2a4:	46184102 */ 	mul.s	$f4,$f8,$f24
/*  f13f2a8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13f2ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f13f2b0:	444ff800 */ 	cfc1	$t7,$31
/*  f13f2b4:	44c4f800 */ 	ctc1	$a0,$31
/*  f13f2b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f2bc:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f13f2c0:	4444f800 */ 	cfc1	$a0,$31
/*  f13f2c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f2c8:	30840078 */ 	andi	$a0,$a0,0x78
/*  f13f2cc:	50800013 */ 	beqzl	$a0,.L0f13f31c
/*  f13f2d0:	44045000 */ 	mfc1	$a0,$f10
/*  f13f2d4:	44815000 */ 	mtc1	$at,$f10
/*  f13f2d8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13f2dc:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f13f2e0:	44c4f800 */ 	ctc1	$a0,$31
/*  f13f2e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f2e8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13f2ec:	4444f800 */ 	cfc1	$a0,$31
/*  f13f2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f2f4:	30840078 */ 	andi	$a0,$a0,0x78
/*  f13f2f8:	14800005 */ 	bnez	$a0,.L0f13f310
/*  f13f2fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f300:	44045000 */ 	mfc1	$a0,$f10
/*  f13f304:	3c018000 */ 	lui	$at,0x8000
/*  f13f308:	10000007 */ 	beqz	$zero,.L0f13f328
/*  f13f30c:	00812025 */ 	or	$a0,$a0,$at
.L0f13f310:
/*  f13f310:	10000005 */ 	beqz	$zero,.L0f13f328
/*  f13f314:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f13f318:	44045000 */ 	mfc1	$a0,$f10
.L0f13f31c:
/*  f13f31c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f320:	0480fffb */ 	bltz	$a0,.L0f13f310
/*  f13f324:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13f328:
/*  f13f328:	44cff800 */ 	ctc1	$t7,$31
/*  f13f32c:	2c810100 */ 	sltiu	$at,$a0,0x100
/*  f13f330:	54200003 */ 	bnezl	$at,.L0f13f340
/*  f13f334:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f13f338:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f13f33c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f13f340:
/*  f13f340:	1472ffcb */ 	bne	$v1,$s2,.L0f13f270
/*  f13f344:	a044003f */ 	sb	$a0,0x3f($v0)
/*  f13f348:	10000010 */ 	beqz	$zero,.L0f13f38c
/*  f13f34c:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13f350:	8238006f */ 	lb	$t8,0x6f($s1)
.L0f13f354:
/*  f13f354:	00001825 */ 	or	$v1,$zero,$zero
/*  f13f358:	02201025 */ 	or	$v0,$s1,$zero
/*  f13f35c:	0703000a */ 	bgezl	$t8,.L0f13f388
/*  f13f360:	ae200064 */ 	sw	$zero,0x64($s1)
/*  f13f364:	ae200064 */ 	sw	$zero,0x64($s1)
.L0f13f368:
/*  f13f368:	90590033 */ 	lbu	$t9,0x33($v0)
/*  f13f36c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13f370:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f13f374:	1472fffc */ 	bne	$v1,$s2,.L0f13f368
/*  f13f378:	a059003f */ 	sb	$t9,0x3f($v0)
/*  f13f37c:	10000003 */ 	beqz	$zero,.L0f13f38c
/*  f13f380:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13f384:	ae200064 */ 	sw	$zero,0x64($s1)
.L0f13f388:
/*  f13f388:	9224006f */ 	lbu	$a0,0x6f($s1)
.L0f13f38c:
/*  f13f38c:	34890004 */ 	ori	$t1,$a0,0x4
.L0f13f390:
/*  f13f390:	3c02800a */ 	lui	$v0,%hi(var8009cc44)
/*  f13f394:	a229006f */ 	sb	$t1,0x6f($s1)
/*  f13f398:	8c42cc44 */ 	lw	$v0,%lo(var8009cc44)($v0)
/*  f13f39c:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0f13f3a0:
/*  f13f3a0:	02e2082a */ 	slt	$at,$s7,$v0
/*  f13f3a4:	1420fe5a */ 	bnez	$at,.L0f13ed10
/*  f13f3a8:	2631007c */ 	addiu	$s1,$s1,124
.L0f13f3ac:
/*  f13f3ac:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f13f3b0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f13f3b4:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f13f3b8:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f13f3bc:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f13f3c0:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f13f3c4:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f13f3c8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f13f3cc:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f13f3d0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f13f3d4:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f13f3d8:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f13f3dc:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f13f3e0:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f13f3e4:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f13f3e8:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f13f3ec:	03e00008 */ 	jr	$ra
/*  f13f3f0:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f13f3f4
.late_rodata
glabel var7f1b5d1c
.word 0x3dcccccd
glabel var7f1b5d20
.word 0x3f19999a
.text
/*  f13f3f4:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f13f3f8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f13f3fc:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f13f400:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f13f404:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f13f408:	0c004b70 */ 	jal	random
/*  f13f40c:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f13f410:	87a8006e */ 	lh	$t0,0x6e($sp)
/*  f13f414:	44822000 */ 	mtc1	$v0,$f4
/*  f13f418:	3c0f8008 */ 	lui	$t7,%hi(var8007f75c)
/*  f13f41c:	00087080 */ 	sll	$t6,$t0,0x2
/*  f13f420:	01c87023 */ 	subu	$t6,$t6,$t0
/*  f13f424:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13f428:	25eff75c */ 	addiu	$t7,$t7,%lo(var8007f75c)
/*  f13f42c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f13f430:	04410005 */ 	bgez	$v0,.L0f13f448
/*  f13f434:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13f438:	3c014f80 */ 	lui	$at,0x4f80
/*  f13f43c:	44814000 */ 	mtc1	$at,$f8
/*  f13f440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f444:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f13f448:
/*  f13f448:	3c012f80 */ 	lui	$at,0x2f80
/*  f13f44c:	44815000 */ 	mtc1	$at,$f10
/*  f13f450:	3c017f1b */ 	lui	$at,%hi(var7f1b5d1c)
/*  f13f454:	c4325d1c */ 	lwc1	$f18,%lo(var7f1b5d1c)($at)
/*  f13f458:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f13f45c:	3c017f1b */ 	lui	$at,%hi(var7f1b5d20)
/*  f13f460:	c4285d20 */ 	lwc1	$f8,%lo(var7f1b5d20)($at)
/*  f13f464:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f13f468:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f13f46c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f13f470:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f13f474:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f13f478:	8fa90074 */ 	lw	$t1,0x74($sp)
/*  f13f47c:	83aa007b */ 	lb	$t2,0x7b($sp)
/*  f13f480:	83ab007f */ 	lb	$t3,0x7f($sp)
/*  f13f484:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f13f488:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f13f48c:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f13f490:	46082000 */ 	add.s	$f0,$f4,$f8
/*  f13f494:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f13f498:	afae003c */ 	sw	$t6,0x3c($sp)
/*  f13f49c:	afad0038 */ 	sw	$t5,0x38($sp)
/*  f13f4a0:	46003082 */ 	mul.s	$f2,$f6,$f0
/*  f13f4a4:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f13f4a8:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f13f4ac:	46005302 */ 	mul.s	$f12,$f10,$f0
/*  f13f4b0:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f13f4b4:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f13f4b8:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f13f4bc:	e7a20030 */ 	swc1	$f2,0x30($sp)
/*  f13f4c0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f13f4c4:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f13f4c8:	e7ac0034 */ 	swc1	$f12,0x34($sp)
/*  f13f4cc:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f13f4d0:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f13f4d4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f4d8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f13f4dc:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f13f4e0:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f13f4e4:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f13f4e8:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f13f4ec:	0fc4fd41 */ 	jal	func0f13f504
/*  f13f4f0:	afaf004c */ 	sw	$t7,0x4c($sp)
/*  f13f4f4:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f13f4f8:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f13f4fc:	03e00008 */ 	jr	$ra
/*  f13f500:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f13f504
.late_rodata
glabel var7f1b5d24
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d28
.word func0f13f504+0xe8 # f13f5ec
glabel var7f1b5d2c
.word func0f13f504+0xe8 # f13f5ec
glabel var7f1b5d30
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d34
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d38
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d3c
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d40
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d44
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d48
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d4c
.word func0f13f504+0xe8 # f13f5ec
glabel var7f1b5d50
.word func0f13f504+0x104 # f13f608
glabel var7f1b5d54
.word 0x3c8efa35
glabel var7f1b5d58
.word 0x3b808081
glabel var7f1b5d5c
.word func0f13f504+0xe48 # f14034c
glabel var7f1b5d60
.word func0f13f504+0xdfc # f140300
glabel var7f1b5d64
.word func0f13f504+0xec0 # f1403c4
glabel var7f1b5d68
.word func0f13f504+0xf38 # f14043c
glabel var7f1b5d6c
.word func0f13f504+0xf58 # f14045c
.text
/*  f13f504:	27bdfe00 */ 	addiu	$sp,$sp,-512
/*  f13f508:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f13f50c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f13f510:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f13f514:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f13f518:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f13f51c:	afa40200 */ 	sw	$a0,0x200($sp)
/*  f13f520:	afa60208 */ 	sw	$a2,0x208($sp)
/*  f13f524:	afa7020c */ 	sw	$a3,0x20c($sp)
/*  f13f528:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f13f52c:	27a401b8 */ 	addiu	$a0,$sp,0x1b8
/*  f13f530:	00a08825 */ 	or	$s1,$a1,$zero
/*  f13f534:	e7a601b8 */ 	swc1	$f6,0x1b8($sp)
/*  f13f538:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f13f53c:	3c077f1b */ 	lui	$a3,%hi(var7f1b5c4c)
/*  f13f540:	24e75c4c */ 	addiu	$a3,$a3,%lo(var7f1b5c4c)
/*  f13f544:	e7aa01bc */ 	swc1	$f10,0x1bc($sp)
/*  f13f548:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f13f54c:	00802825 */ 	or	$a1,$a0,$zero
/*  f13f550:	240603bc */ 	addiu	$a2,$zero,0x3bc
/*  f13f554:	0fc5dc59 */ 	jal	func0f177164
/*  f13f558:	e7a401c0 */ 	swc1	$f4,0x1c0($sp)
/*  f13f55c:	0fc4f92a */ 	jal	func0f13e4a8
/*  f13f560:	8fa4022c */ 	lw	$a0,0x22c($sp)
/*  f13f564:	10400017 */ 	beqz	$v0,.L0f13f5c4
/*  f13f568:	00408025 */ 	or	$s0,$v0,$zero
/*  f13f56c:	87aa0216 */ 	lh	$t2,0x216($sp)
/*  f13f570:	3c0e8008 */ 	lui	$t6,%hi(var8007f75c)
/*  f13f574:	25cef75c */ 	addiu	$t6,$t6,%lo(var8007f75c)
/*  f13f578:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f13f57c:	012a4823 */ 	subu	$t1,$t1,$t2
/*  f13f580:	00094880 */ 	sll	$t1,$t1,0x2
/*  f13f584:	012e1021 */ 	addu	$v0,$t1,$t6
/*  f13f588:	904d0008 */ 	lbu	$t5,0x8($v0)
/*  f13f58c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13f590:	3c0b8008 */ 	lui	$t3,%hi(var8007f7b0)
/*  f13f594:	11a1000b */ 	beq	$t5,$at,.L0f13f5c4
/*  f13f598:	256bf7b0 */ 	addiu	$t3,$t3,%lo(var8007f7b0)
/*  f13f59c:	104b0006 */ 	beq	$v0,$t3,.L0f13f5b8
/*  f13f5a0:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f13f5a4:	3c014170 */ 	lui	$at,0x4170
/*  f13f5a8:	44810000 */ 	mtc1	$at,$f0
/*  f13f5ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f5b0:	e7a00230 */ 	swc1	$f0,0x230($sp)
/*  f13f5b4:	e7a00234 */ 	swc1	$f0,0x234($sp)
.L0f13f5b8:
/*  f13f5b8:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f13f5bc:	a7b80216 */ 	sh	$t8,0x216($sp)
/*  f13f5c0:	afaf0244 */ 	sw	$t7,0x244($sp)
.L0f13f5c4:
/*  f13f5c4:	87b90216 */ 	lh	$t9,0x216($sp)
/*  f13f5c8:	272cfffa */ 	addiu	$t4,$t9,-6
/*  f13f5cc:	2d81000c */ 	sltiu	$at,$t4,0xc
/*  f13f5d0:	10200006 */ 	beqz	$at,.L0f13f5ec
/*  f13f5d4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f13f5d8:	3c017f1b */ 	lui	$at,%hi(var7f1b5d24)
/*  f13f5dc:	002c0821 */ 	addu	$at,$at,$t4
/*  f13f5e0:	8c2c5d24 */ 	lw	$t4,%lo(var7f1b5d24)($at)
/*  f13f5e4:	01800008 */ 	jr	$t4
/*  f13f5e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13f5ec:
/*  f13f5ec:	0c004b70 */ 	jal	random
/*  f13f5f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f5f4:	24010168 */ 	addiu	$at,$zero,0x168
/*  f13f5f8:	0041001b */ 	divu	$zero,$v0,$at
/*  f13f5fc:	00004010 */ 	mfhi	$t0
/*  f13f600:	afa80240 */ 	sw	$t0,0x240($sp)
/*  f13f604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f608:	12000004 */ 	beqz	$s0,.L0f13f61c
/*  f13f60c:	3c05800a */ 	lui	$a1,%hi(var800a41b4)
/*  f13f610:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f13f614:	10000009 */ 	beqz	$zero,.L0f13f63c
/*  f13f618:	afaa0178 */ 	sw	$t2,0x178($sp)
.L0f13f61c:
/*  f13f61c:	87a90216 */ 	lh	$t1,0x216($sp)
/*  f13f620:	3c0d8008 */ 	lui	$t5,%hi(var8007f764)
/*  f13f624:	00097080 */ 	sll	$t6,$t1,0x2
/*  f13f628:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f13f62c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f13f630:	01ae6821 */ 	addu	$t5,$t5,$t6
/*  f13f634:	91adf764 */ 	lbu	$t5,%lo(var8007f764)($t5)
/*  f13f638:	afad0178 */ 	sw	$t5,0x178($sp)
.L0f13f63c:
/*  f13f63c:	24a541b4 */ 	addiu	$a1,$a1,%lo(var800a41b4)
/*  f13f640:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f13f644:	3c13800a */ 	lui	$s3,%hi(var8009cc40)
/*  f13f648:	8fb2021c */ 	lw	$s2,0x21c($sp)
/*  f13f64c:	11600439 */ 	beqz	$t3,.L0f140734
/*  f13f650:	2673cc40 */ 	addiu	$s3,$s3,%lo(var8009cc40)
/*  f13f654:	12400003 */ 	beqz	$s2,.L0f13f664
/*  f13f658:	87a4021a */ 	lh	$a0,0x21a($sp)
/*  f13f65c:	10000001 */ 	beqz	$zero,.L0f13f664
/*  f13f660:	00002025 */ 	or	$a0,$zero,$zero
.L0f13f664:
/*  f13f664:	12400005 */ 	beqz	$s2,.L0f13f67c
/*  f13f668:	3c02800a */ 	lui	$v0,%hi(g_MenuStack+0x1fff)
/*  f13f66c:	3c02800a */ 	lui	$v0,%hi(var8009cc60)
/*  f13f670:	8c42cc60 */ 	lw	$v0,%lo(var8009cc60)($v0)
/*  f13f674:	10000003 */ 	beqz	$zero,.L0f13f684
/*  f13f678:	2442ffff */ 	addiu	$v0,$v0,%lo(g_MenuStack+0x1fff)
.L0f13f67c:
/*  f13f67c:	8c42cc68 */ 	lw	$v0,-0x3398($v0)
/*  f13f680:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f13f684:
/*  f13f684:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f13f688:	00048040 */ 	sll	$s0,$a0,0x1
/*  f13f68c:	87ac021a */ 	lh	$t4,0x21a($sp)
/*  f13f690:	0070c021 */ 	addu	$t8,$v1,$s0
/*  f13f694:	970f0000 */ 	lhu	$t7,0x0($t8)
/*  f13f698:	000c4040 */ 	sll	$t0,$t4,0x1
/*  f13f69c:	00685021 */ 	addu	$t2,$v1,$t0
/*  f13f6a0:	004f082a */ 	slt	$at,$v0,$t7
/*  f13f6a4:	10200007 */ 	beqz	$at,.L0f13f6c4
/*  f13f6a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f6ac:	0fc4f9d1 */ 	jal	func0f13e744
/*  f13f6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f6b4:	5440000e */ 	bnezl	$v0,.L0f13f6f0
/*  f13f6b8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f13f6bc:	1000041e */ 	beqz	$zero,.L0f140738
/*  f13f6c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f13f6c4:
/*  f13f6c4:	3c19800a */ 	lui	$t9,%hi(var8009cc68)
/*  f13f6c8:	8f39cc68 */ 	lw	$t9,%lo(var8009cc68)($t9)
/*  f13f6cc:	95490000 */ 	lhu	$t1,0x0($t2)
/*  f13f6d0:	0329082a */ 	slt	$at,$t9,$t1
/*  f13f6d4:	50200006 */ 	beqzl	$at,.L0f13f6f0
/*  f13f6d8:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f13f6dc:	0fc4f9d1 */ 	jal	func0f13e744
/*  f13f6e0:	01802025 */ 	or	$a0,$t4,$zero
/*  f13f6e4:	50400414 */ 	beqzl	$v0,.L0f140738
/*  f13f6e8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f13f6ec:	8e6e0000 */ 	lw	$t6,0x0($s3)
.L0f13f6f0:
/*  f13f6f0:	3c03800a */ 	lui	$v1,%hi(var8009cc4c)
/*  f13f6f4:	3c04800a */ 	lui	$a0,%hi(var8009cc48)
/*  f13f6f8:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f13f6fc:	944d0000 */ 	lhu	$t5,0x0($v0)
/*  f13f700:	2484cc48 */ 	addiu	$a0,$a0,%lo(var8009cc48)
/*  f13f704:	2463cc4c */ 	addiu	$v1,$v1,%lo(var8009cc4c)
/*  f13f708:	25ab0001 */ 	addiu	$t3,$t5,0x1
/*  f13f70c:	a44b0000 */ 	sh	$t3,0x0($v0)
/*  f13f710:	87b90216 */ 	lh	$t9,0x216($sp)
/*  f13f714:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f13f718:	8c880000 */ 	lw	$t0,0x0($a0)
/*  f13f71c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f13f720:	01394823 */ 	subu	$t1,$t1,$t9
/*  f13f724:	00094880 */ 	sll	$t1,$t1,0x2
/*  f13f728:	3c0c8008 */ 	lui	$t4,%hi(var8007f764)
/*  f13f72c:	270fffff */ 	addiu	$t7,$t8,-1
/*  f13f730:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f13f734:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f13f738:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f13f73c:	01896021 */ 	addu	$t4,$t4,$t1
/*  f13f740:	918cf764 */ 	lbu	$t4,%lo(var8007f764)($t4)
/*  f13f744:	3c05800a */ 	lui	$a1,%hi(var800a41b4)
/*  f13f748:	24010003 */ 	addiu	$at,$zero,0x3
/*  f13f74c:	24a541b4 */ 	addiu	$a1,$a1,%lo(var800a41b4)
/*  f13f750:	15810007 */ 	bne	$t4,$at,.L0f13f770
/*  f13f754:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f13f758:	3c02800a */ 	lui	$v0,%hi(var8009cc54)
/*  f13f75c:	2442cc54 */ 	addiu	$v0,$v0,%lo(var8009cc54)
/*  f13f760:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f13f764:	25cd0001 */ 	addiu	$t5,$t6,0x1
/*  f13f768:	10000006 */ 	beqz	$zero,.L0f13f784
/*  f13f76c:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f13f770:
/*  f13f770:	3c02800a */ 	lui	$v0,%hi(var8009cc58)
/*  f13f774:	2442cc58 */ 	addiu	$v0,$v0,%lo(var8009cc58)
/*  f13f778:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f13f77c:	25780001 */ 	addiu	$t8,$t3,0x1
/*  f13f780:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f13f784:
/*  f13f784:	8cb30000 */ 	lw	$s3,0x0($a1)
/*  f13f788:	3c02800a */ 	lui	$v0,%hi(var800a41b8)
/*  f13f78c:	244241b8 */ 	addiu	$v0,$v0,%lo(var800a41b8)
/*  f13f790:	8e6f0074 */ 	lw	$t7,0x74($s3)
/*  f13f794:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f13f798:	3c018008 */ 	lui	$at,0x8008
/*  f13f79c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f13f7a0:	ae680074 */ 	sw	$t0,0x74($s3)
/*  f13f7a4:	8fb9024c */ 	lw	$t9,0x24c($sp)
/*  f13f7a8:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f13f7ac:	926e006f */ 	lbu	$t6,0x6f($s3)
/*  f13f7b0:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f13f7b4:	312c0008 */ 	andi	$t4,$t1,0x8
/*  f13f7b8:	31cdfff7 */ 	andi	$t5,$t6,0xfff7
/*  f13f7bc:	018d5825 */ 	or	$t3,$t4,$t5
/*  f13f7c0:	a26b006f */ 	sb	$t3,0x6f($s3)
/*  f13f7c4:	1240000d */ 	beqz	$s2,.L0f13f7fc
/*  f13f7c8:	ae600078 */ 	sw	$zero,0x78($s3)
/*  f13f7cc:	8fb8024c */ 	lw	$t8,0x24c($sp)
/*  f13f7d0:	53000006 */ 	beqzl	$t8,.L0f13f7ec
/*  f13f7d4:	8e480040 */ 	lw	$t0,0x40($s2)
/*  f13f7d8:	8e4f0044 */ 	lw	$t7,0x44($s2)
/*  f13f7dc:	ae6f0078 */ 	sw	$t7,0x78($s3)
/*  f13f7e0:	10000004 */ 	beqz	$zero,.L0f13f7f4
/*  f13f7e4:	ae530044 */ 	sw	$s3,0x44($s2)
/*  f13f7e8:	8e480040 */ 	lw	$t0,0x40($s2)
.L0f13f7ec:
/*  f13f7ec:	ae680078 */ 	sw	$t0,0x78($s3)
/*  f13f7f0:	ae530040 */ 	sw	$s3,0x40($s2)
.L0f13f7f4:
/*  f13f7f4:	10000023 */ 	beqz	$zero,.L0f13f884
/*  f13f7f8:	ae720060 */ 	sw	$s2,0x60($s3)
.L0f13f7fc:
/*  f13f7fc:	8faa024c */ 	lw	$t2,0x24c($sp)
/*  f13f800:	87a2021a */ 	lh	$v0,0x21a($sp)
/*  f13f804:	3c03800a */ 	lui	$v1,%hi(g_Rooms)
/*  f13f808:	11400011 */ 	beqz	$t2,.L0f13f850
/*  f13f80c:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f13f810:	87a2021a */ 	lh	$v0,0x21a($sp)
/*  f13f814:	3c03800a */ 	lui	$v1,%hi(g_Rooms)
/*  f13f818:	24634928 */ 	addiu	$v1,$v1,%lo(g_Rooms)
/*  f13f81c:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f13f820:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f13f824:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f13f828:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13f82c:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f13f830:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13f834:	01397021 */ 	addu	$t6,$t1,$t9
/*  f13f838:	8dcc0088 */ 	lw	$t4,0x88($t6)
/*  f13f83c:	ae6c0078 */ 	sw	$t4,0x78($s3)
/*  f13f840:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f13f844:	01b95821 */ 	addu	$t3,$t5,$t9
/*  f13f848:	1000000d */ 	beqz	$zero,.L0f13f880
/*  f13f84c:	ad730088 */ 	sw	$s3,0x88($t3)
.L0f13f850:
/*  f13f850:	24634928 */ 	addiu	$v1,$v1,%lo(g_Rooms)
/*  f13f854:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f13f858:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f13f85c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13f860:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f13f864:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13f868:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f13f86c:	8d0a0084 */ 	lw	$t2,0x84($t0)
/*  f13f870:	ae6a0078 */ 	sw	$t2,0x78($s3)
/*  f13f874:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f13f878:	03384821 */ 	addu	$t1,$t9,$t8
/*  f13f87c:	ad330084 */ 	sw	$s3,0x84($t1)
.L0f13f880:
/*  f13f880:	ae600060 */ 	sw	$zero,0x60($s3)
.L0f13f884:
/*  f13f884:	8fae0200 */ 	lw	$t6,0x200($sp)
/*  f13f888:	44809000 */ 	mtc1	$zero,$f18
/*  f13f88c:	c5c80000 */ 	lwc1	$f8,0x0($t6)
/*  f13f890:	e7a801ac */ 	swc1	$f8,0x1ac($sp)
/*  f13f894:	c5c60004 */ 	lwc1	$f6,0x4($t6)
/*  f13f898:	e7a601b0 */ 	swc1	$f6,0x1b0($sp)
/*  f13f89c:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f13f8a0:	e7aa01b4 */ 	swc1	$f10,0x1b4($sp)
/*  f13f8a4:	c6300000 */ 	lwc1	$f16,0x0($s1)
/*  f13f8a8:	4610903c */ 	c.lt.s	$f18,$f16
/*  f13f8ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f8b0:	45020004 */ 	bc1fl	.L0f13f8c4
/*  f13f8b4:	46008007 */ 	neg.s	$f0,$f16
/*  f13f8b8:	10000002 */ 	beqz	$zero,.L0f13f8c4
/*  f13f8bc:	46008006 */ 	mov.s	$f0,$f16
/*  f13f8c0:	46008007 */ 	neg.s	$f0,$f16
.L0f13f8c4:
/*  f13f8c4:	c42e45d4 */ 	lwc1	$f14,0x45d4($at)
/*  f13f8c8:	460e003c */ 	c.lt.s	$f0,$f14
/*  f13f8cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f8d0:	45020004 */ 	bc1fl	.L0f13f8e4
/*  f13f8d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f13f8d8:	10000002 */ 	beqz	$zero,.L0f13f8e4
/*  f13f8dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13f8e0:	00002025 */ 	or	$a0,$zero,$zero
.L0f13f8e4:
/*  f13f8e4:	c62c0004 */ 	lwc1	$f12,0x4($s1)
/*  f13f8e8:	460c903c */ 	c.lt.s	$f18,$f12
/*  f13f8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f8f0:	45020004 */ 	bc1fl	.L0f13f904
/*  f13f8f4:	46006007 */ 	neg.s	$f0,$f12
/*  f13f8f8:	10000002 */ 	beqz	$zero,.L0f13f904
/*  f13f8fc:	46006006 */ 	mov.s	$f0,$f12
/*  f13f900:	46006007 */ 	neg.s	$f0,$f12
.L0f13f904:
/*  f13f904:	460e003c */ 	c.lt.s	$f0,$f14
/*  f13f908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f90c:	45020004 */ 	bc1fl	.L0f13f920
/*  f13f910:	00001825 */ 	or	$v1,$zero,$zero
/*  f13f914:	10000002 */ 	beqz	$zero,.L0f13f920
/*  f13f918:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f13f91c:	00001825 */ 	or	$v1,$zero,$zero
.L0f13f920:
/*  f13f920:	c6220008 */ 	lwc1	$f2,0x8($s1)
/*  f13f924:	4602903c */ 	c.lt.s	$f18,$f2
/*  f13f928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f92c:	45020004 */ 	bc1fl	.L0f13f940
/*  f13f930:	46001007 */ 	neg.s	$f0,$f2
/*  f13f934:	10000002 */ 	beqz	$zero,.L0f13f940
/*  f13f938:	46001006 */ 	mov.s	$f0,$f2
/*  f13f93c:	46001007 */ 	neg.s	$f0,$f2
.L0f13f940:
/*  f13f940:	460e003c */ 	c.lt.s	$f0,$f14
/*  f13f944:	00001025 */ 	or	$v0,$zero,$zero
/*  f13f948:	45000003 */ 	bc1f	.L0f13f958
/*  f13f94c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f950:	10000001 */ 	beqz	$zero,.L0f13f958
/*  f13f954:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f13f958:
/*  f13f958:	10800014 */ 	beqz	$a0,.L0f13f9ac
/*  f13f95c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f960:	10400012 */ 	beqz	$v0,.L0f13f9ac
/*  f13f964:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f968:	44809000 */ 	mtc1	$zero,$f18
/*  f13f96c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13f970:	44817000 */ 	mtc1	$at,$f14
/*  f13f974:	460c903e */ 	c.le.s	$f18,$f12
/*  f13f978:	46009406 */ 	mov.s	$f16,$f18
/*  f13f97c:	e7b201e8 */ 	swc1	$f18,0x1e8($sp)
/*  f13f980:	e7b201ec */ 	swc1	$f18,0x1ec($sp)
/*  f13f984:	45000005 */ 	bc1f	.L0f13f99c
/*  f13f988:	e7ae01f4 */ 	swc1	$f14,0x1f4($sp)
/*  f13f98c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13f990:	44810000 */ 	mtc1	$at,$f0
/*  f13f994:	10000002 */ 	beqz	$zero,.L0f13f9a0
/*  f13f998:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13f99c:
/*  f13f99c:	46007006 */ 	mov.s	$f0,$f14
.L0f13f9a0:
/*  f13f9a0:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f13f9a4:	1000009f */ 	beqz	$zero,.L0f13fc24
/*  f13f9a8:	e7a401f0 */ 	swc1	$f4,0x1f0($sp)
.L0f13f9ac:
/*  f13f9ac:	10800017 */ 	beqz	$a0,.L0f13fa0c
/*  f13f9b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f9b4:	10600015 */ 	beqz	$v1,.L0f13fa0c
/*  f13f9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f9bc:	44800000 */ 	mtc1	$zero,$f0
/*  f13f9c0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13f9c4:	4602003e */ 	c.le.s	$f0,$f2
/*  f13f9c8:	46000406 */ 	mov.s	$f16,$f0
/*  f13f9cc:	46000486 */ 	mov.s	$f18,$f0
/*  f13f9d0:	45020006 */ 	bc1fl	.L0f13f9ec
/*  f13f9d4:	44813000 */ 	mtc1	$at,$f6
/*  f13f9d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f13f9dc:	44814000 */ 	mtc1	$at,$f8
/*  f13f9e0:	10000004 */ 	beqz	$zero,.L0f13f9f4
/*  f13f9e4:	e7a801f4 */ 	swc1	$f8,0x1f4($sp)
/*  f13f9e8:	44813000 */ 	mtc1	$at,$f6
.L0f13f9ec:
/*  f13f9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f9f0:	e7a601f4 */ 	swc1	$f6,0x1f4($sp)
.L0f13f9f4:
/*  f13f9f4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13f9f8:	44815000 */ 	mtc1	$at,$f10
/*  f13f9fc:	e7a001e8 */ 	swc1	$f0,0x1e8($sp)
/*  f13fa00:	e7a001f0 */ 	swc1	$f0,0x1f0($sp)
/*  f13fa04:	10000087 */ 	beqz	$zero,.L0f13fc24
/*  f13fa08:	e7aa01ec */ 	swc1	$f10,0x1ec($sp)
.L0f13fa0c:
/*  f13fa0c:	5060001a */ 	beqzl	$v1,.L0f13fa78
/*  f13fa10:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f13fa14:	50400018 */ 	beqzl	$v0,.L0f13fa78
/*  f13fa18:	8fa3020c */ 	lw	$v1,0x20c($sp)
/*  f13fa1c:	44801000 */ 	mtc1	$zero,$f2
/*  f13fa20:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13fa24:	4610103e */ 	c.le.s	$f2,$f16
/*  f13fa28:	e7a201f4 */ 	swc1	$f2,0x1f4($sp)
/*  f13fa2c:	46001486 */ 	mov.s	$f18,$f2
/*  f13fa30:	45020006 */ 	bc1fl	.L0f13fa4c
/*  f13fa34:	44810000 */ 	mtc1	$at,$f0
/*  f13fa38:	3c013f80 */ 	lui	$at,0x3f80
/*  f13fa3c:	44810000 */ 	mtc1	$at,$f0
/*  f13fa40:	10000004 */ 	beqz	$zero,.L0f13fa54
/*  f13fa44:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13fa48:	44810000 */ 	mtc1	$at,$f0
.L0f13fa4c:
/*  f13fa4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fa50:	3c01bf80 */ 	lui	$at,0xbf80
.L0f13fa54:
/*  f13fa54:	44812000 */ 	mtc1	$at,$f4
/*  f13fa58:	3c013f80 */ 	lui	$at,0x3f80
/*  f13fa5c:	44814000 */ 	mtc1	$at,$f8
/*  f13fa60:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f13fa64:	e7a201e8 */ 	swc1	$f2,0x1e8($sp)
/*  f13fa68:	e7a201ec */ 	swc1	$f2,0x1ec($sp)
/*  f13fa6c:	1000006d */ 	beqz	$zero,.L0f13fc24
/*  f13fa70:	e7a801f0 */ 	swc1	$f8,0x1f0($sp)
/*  f13fa74:	8fa3020c */ 	lw	$v1,0x20c($sp)
.L0f13fa78:
/*  f13fa78:	8fa20210 */ 	lw	$v0,0x210($sp)
/*  f13fa7c:	c7a001b8 */ 	lwc1	$f0,0x1b8($sp)
/*  f13fa80:	10600055 */ 	beqz	$v1,.L0f13fbd8
/*  f13fa84:	c7a201c0 */ 	lwc1	$f2,0x1c0($sp)
/*  f13fa88:	10400053 */ 	beqz	$v0,.L0f13fbd8
/*  f13fa8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fa90:	846c0000 */ 	lh	$t4,0x0($v1)
/*  f13fa94:	27b0013c */ 	addiu	$s0,$sp,0x13c
/*  f13fa98:	3c077f1b */ 	lui	$a3,%hi(var7f1b5c58)
/*  f13fa9c:	448c3000 */ 	mtc1	$t4,$f6
/*  f13faa0:	24e75c58 */ 	addiu	$a3,$a3,%lo(var7f1b5c58)
/*  f13faa4:	02002025 */ 	or	$a0,$s0,$zero
/*  f13faa8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13faac:	02002825 */ 	or	$a1,$s0,$zero
/*  f13fab0:	2406047f */ 	addiu	$a2,$zero,0x47f
/*  f13fab4:	e7aa013c */ 	swc1	$f10,0x13c($sp)
/*  f13fab8:	846d0002 */ 	lh	$t5,0x2($v1)
/*  f13fabc:	448d2000 */ 	mtc1	$t5,$f4
/*  f13fac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fac4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13fac8:	e7a80140 */ 	swc1	$f8,0x140($sp)
/*  f13facc:	846b0004 */ 	lh	$t3,0x4($v1)
/*  f13fad0:	448b3000 */ 	mtc1	$t3,$f6
/*  f13fad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fad8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13fadc:	e7aa0144 */ 	swc1	$f10,0x144($sp)
/*  f13fae0:	84580000 */ 	lh	$t8,0x0($v0)
/*  f13fae4:	44982000 */ 	mtc1	$t8,$f4
/*  f13fae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13faec:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13faf0:	e7a80130 */ 	swc1	$f8,0x130($sp)
/*  f13faf4:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f13faf8:	448f3000 */ 	mtc1	$t7,$f6
/*  f13fafc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fb00:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f13fb04:	e7aa0134 */ 	swc1	$f10,0x134($sp)
/*  f13fb08:	84480004 */ 	lh	$t0,0x4($v0)
/*  f13fb0c:	44882000 */ 	mtc1	$t0,$f4
/*  f13fb10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fb14:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f13fb18:	0fc5dc59 */ 	jal	func0f177164
/*  f13fb1c:	e7a80138 */ 	swc1	$f8,0x138($sp)
/*  f13fb20:	27a40130 */ 	addiu	$a0,$sp,0x130
/*  f13fb24:	3c077f1b */ 	lui	$a3,%hi(var7f1b5c64)
/*  f13fb28:	24e75c64 */ 	addiu	$a3,$a3,%lo(var7f1b5c64)
/*  f13fb2c:	00802825 */ 	or	$a1,$a0,$zero
/*  f13fb30:	0fc5dc59 */ 	jal	func0f177164
/*  f13fb34:	24060480 */ 	addiu	$a2,$zero,0x480
/*  f13fb38:	c7a20130 */ 	lwc1	$f2,0x130($sp)
/*  f13fb3c:	c7b0013c */ 	lwc1	$f16,0x13c($sp)
/*  f13fb40:	c7ac0134 */ 	lwc1	$f12,0x134($sp)
/*  f13fb44:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*  f13fb48:	46028182 */ 	mul.s	$f6,$f16,$f2
/*  f13fb4c:	c7ae0138 */ 	lwc1	$f14,0x138($sp)
/*  f13fb50:	c7a80144 */ 	lwc1	$f8,0x144($sp)
/*  f13fb54:	460c9282 */ 	mul.s	$f10,$f18,$f12
/*  f13fb58:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13fb5c:	02002025 */ 	or	$a0,$s0,$zero
/*  f13fb60:	27a50118 */ 	addiu	$a1,$sp,0x118
/*  f13fb64:	27a60100 */ 	addiu	$a2,$sp,0x100
/*  f13fb68:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f13fb6c:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f13fb70:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f13fb74:	44812000 */ 	mtc1	$at,$f4
/*  f13fb78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fb7c:	46045002 */ 	mul.s	$f0,$f10,$f4
/*  f13fb80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fb84:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f13fb88:	46023280 */ 	add.s	$f10,$f6,$f2
/*  f13fb8c:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f13fb90:	e7aa0118 */ 	swc1	$f10,0x118($sp)
/*  f13fb94:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f13fb98:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f13fb9c:	460e5100 */ 	add.s	$f4,$f10,$f14
/*  f13fba0:	e7a6011c */ 	swc1	$f6,0x11c($sp)
/*  f13fba4:	0fc5dc2b */ 	jal	func0f1770ac
/*  f13fba8:	e7a40120 */ 	swc1	$f4,0x120($sp)
/*  f13fbac:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*  f13fbb0:	c7a80118 */ 	lwc1	$f8,0x118($sp)
/*  f13fbb4:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f13fbb8:	c7a40120 */ 	lwc1	$f4,0x120($sp)
/*  f13fbbc:	c7b00140 */ 	lwc1	$f16,0x140($sp)
/*  f13fbc0:	c7b20144 */ 	lwc1	$f18,0x144($sp)
/*  f13fbc4:	e7a601f4 */ 	swc1	$f6,0x1f4($sp)
/*  f13fbc8:	e7a801e8 */ 	swc1	$f8,0x1e8($sp)
/*  f13fbcc:	e7aa01ec */ 	swc1	$f10,0x1ec($sp)
/*  f13fbd0:	10000014 */ 	beqz	$zero,.L0f13fc24
/*  f13fbd4:	e7a401f0 */ 	swc1	$f4,0x1f0($sp)
.L0f13fbd8:
/*  f13fbd8:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f13fbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fbe0:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f13fbe4:	0c012974 */ 	jal	sqrtf
/*  f13fbe8:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f13fbec:	c7a401b8 */ 	lwc1	$f4,0x1b8($sp)
/*  f13fbf0:	c7aa01c0 */ 	lwc1	$f10,0x1c0($sp)
/*  f13fbf4:	c7ae01bc */ 	lwc1	$f14,0x1bc($sp)
/*  f13fbf8:	46002083 */ 	div.s	$f2,$f4,$f0
/*  f13fbfc:	44808000 */ 	mtc1	$zero,$f16
/*  f13fc00:	46000207 */ 	neg.s	$f8,$f0
/*  f13fc04:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f13fc08:	46005303 */ 	div.s	$f12,$f10,$f0
/*  f13fc0c:	46027182 */ 	mul.s	$f6,$f14,$f2
/*  f13fc10:	46001487 */ 	neg.s	$f18,$f2
/*  f13fc14:	e7a601e8 */ 	swc1	$f6,0x1e8($sp)
/*  f13fc18:	460c7282 */ 	mul.s	$f10,$f14,$f12
/*  f13fc1c:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f13fc20:	e7aa01f0 */ 	swc1	$f10,0x1f0($sp)
.L0f13fc24:
/*  f13fc24:	8faa0240 */ 	lw	$t2,0x240($sp)
/*  f13fc28:	c7a401f4 */ 	lwc1	$f4,0x1f4($sp)
/*  f13fc2c:	51400034 */ 	beqzl	$t2,.L0f13fd00
/*  f13fc30:	c7aa01ec */ 	lwc1	$f10,0x1ec($sp)
/*  f13fc34:	448a2000 */ 	mtc1	$t2,$f4
/*  f13fc38:	3c017f1b */ 	lui	$at,%hi(var7f1b5d54)
/*  f13fc3c:	c4285d54 */ 	lwc1	$f8,%lo(var7f1b5d54)($at)
/*  f13fc40:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13fc44:	e7b001f8 */ 	swc1	$f16,0x1f8($sp)
/*  f13fc48:	e7b201fc */ 	swc1	$f18,0x1fc($sp)
/*  f13fc4c:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f13fc50:	0c0068f7 */ 	jal	sinf
/*  f13fc54:	e7ac0040 */ 	swc1	$f12,0x40($sp)
/*  f13fc58:	c7ac0040 */ 	lwc1	$f12,0x40($sp)
/*  f13fc5c:	0c0068f4 */ 	jal	cosf
/*  f13fc60:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
/*  f13fc64:	c7aa01f4 */ 	lwc1	$f10,0x1f4($sp)
/*  f13fc68:	c7ac01e8 */ 	lwc1	$f12,0x1e8($sp)
/*  f13fc6c:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f13fc70:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f13fc74:	c7b001f8 */ 	lwc1	$f16,0x1f8($sp)
/*  f13fc78:	c7b201fc */ 	lwc1	$f18,0x1fc($sp)
/*  f13fc7c:	460c7182 */ 	mul.s	$f6,$f14,$f12
/*  f13fc80:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f13fc84:	46007087 */ 	neg.s	$f2,$f14
/*  f13fc88:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f13fc8c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f13fc90:	c7a601ec */ 	lwc1	$f6,0x1ec($sp)
/*  f13fc94:	e7a801dc */ 	swc1	$f8,0x1dc($sp)
/*  f13fc98:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f13fc9c:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f13fca0:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f13fca4:	e7a401e0 */ 	swc1	$f4,0x1e0($sp)
/*  f13fca8:	c7a401f0 */ 	lwc1	$f4,0x1f0($sp)
/*  f13fcac:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f13fcb0:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f13fcb4:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*  f13fcb8:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
/*  f13fcbc:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f13fcc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fcc4:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f13fcc8:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f13fccc:	46101282 */ 	mul.s	$f10,$f2,$f16
/*  f13fcd0:	e7a801d0 */ 	swc1	$f8,0x1d0($sp)
/*  f13fcd4:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f13fcd8:	c7ae01d0 */ 	lwc1	$f14,0x1d0($sp)
/*  f13fcdc:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f13fce0:	46121282 */ 	mul.s	$f10,$f2,$f18
/*  f13fce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fce8:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f13fcec:	e7a601d4 */ 	swc1	$f6,0x1d4($sp)
/*  f13fcf0:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f13fcf4:	10000009 */ 	beqz	$zero,.L0f13fd1c
/*  f13fcf8:	e7a601d8 */ 	swc1	$f6,0x1d8($sp)
/*  f13fcfc:	c7aa01ec */ 	lwc1	$f10,0x1ec($sp)
.L0f13fd00:
/*  f13fd00:	c7a801f0 */ 	lwc1	$f8,0x1f0($sp)
/*  f13fd04:	e7a401dc */ 	swc1	$f4,0x1dc($sp)
/*  f13fd08:	e7b001e0 */ 	swc1	$f16,0x1e0($sp)
/*  f13fd0c:	e7b201e4 */ 	swc1	$f18,0x1e4($sp)
/*  f13fd10:	c7ae01e8 */ 	lwc1	$f14,0x1e8($sp)
/*  f13fd14:	e7aa01d4 */ 	swc1	$f10,0x1d4($sp)
/*  f13fd18:	e7a801d8 */ 	swc1	$f8,0x1d8($sp)
.L0f13fd1c:
/*  f13fd1c:	12400052 */ 	beqz	$s2,.L0f13fe68
/*  f13fd20:	87a4021a */ 	lh	$a0,0x21a($sp)
/*  f13fd24:	8e420004 */ 	lw	$v0,0x4($s2)
/*  f13fd28:	83ae0227 */ 	lb	$t6,0x227($sp)
/*  f13fd2c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13fd30:	8c590018 */ 	lw	$t9,0x18($v0)
/*  f13fd34:	904d0003 */ 	lbu	$t5,0x3($v0)
/*  f13fd38:	000e6180 */ 	sll	$t4,$t6,0x6
/*  f13fd3c:	8f29000c */ 	lw	$t1,0xc($t9)
/*  f13fd40:	00408025 */ 	or	$s0,$v0,$zero
/*  f13fd44:	15a10010 */ 	bne	$t5,$at,.L0f13fd88
/*  f13fd48:	012c8821 */ 	addu	$s1,$t1,$t4
/*  f13fd4c:	944b0070 */ 	lhu	$t3,0x70($v0)
/*  f13fd50:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13fd54:	31780008 */ 	andi	$t8,$t3,0x8
/*  f13fd58:	5300000c */ 	beqzl	$t8,.L0f13fd8c
/*  f13fd5c:	c7b001d4 */ 	lwc1	$f16,0x1d4($sp)
/*  f13fd60:	44810000 */ 	mtc1	$at,$f0
/*  f13fd64:	c7a601d4 */ 	lwc1	$f6,0x1d4($sp)
/*  f13fd68:	c7aa01d8 */ 	lwc1	$f10,0x1d8($sp)
/*  f13fd6c:	460e0382 */ 	mul.s	$f14,$f0,$f14
/*  f13fd70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fd74:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f13fd78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fd7c:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f13fd80:	e7a401d4 */ 	swc1	$f4,0x1d4($sp)
/*  f13fd84:	e7a801d8 */ 	swc1	$f8,0x1d8($sp)
.L0f13fd88:
/*  f13fd88:	c7b001d4 */ 	lwc1	$f16,0x1d4($sp)
.L0f13fd8c:
/*  f13fd8c:	c7b201d8 */ 	lwc1	$f18,0x1d8($sp)
/*  f13fd90:	c7a001dc */ 	lwc1	$f0,0x1dc($sp)
/*  f13fd94:	c7a201e0 */ 	lwc1	$f2,0x1e0($sp)
/*  f13fd98:	c7a601e4 */ 	lwc1	$f6,0x1e4($sp)
/*  f13fd9c:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f13fda0:	02202025 */ 	or	$a0,$s1,$zero
/*  f13fda4:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f13fda8:	e7ae01d0 */ 	swc1	$f14,0x1d0($sp)
/*  f13fdac:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f13fdb0:	e7b20080 */ 	swc1	$f18,0x80($sp)
/*  f13fdb4:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f13fdb8:	e7a20088 */ 	swc1	$f2,0x88($sp)
/*  f13fdbc:	0c0056c4 */ 	jal	func00015b10
/*  f13fdc0:	e7a6008c */ 	swc1	$f6,0x8c($sp)
/*  f13fdc4:	02202025 */ 	or	$a0,$s1,$zero
/*  f13fdc8:	0c0056c4 */ 	jal	func00015b10
/*  f13fdcc:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f13fdd0:	c7a00084 */ 	lwc1	$f0,0x84($sp)
/*  f13fdd4:	c7a20088 */ 	lwc1	$f2,0x88($sp)
/*  f13fdd8:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f13fddc:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f13fde0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fde4:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f13fde8:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f13fdec:	46063102 */ 	mul.s	$f4,$f6,$f6
/*  f13fdf0:	0c012974 */ 	jal	sqrtf
/*  f13fdf4:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f13fdf8:	c7aa0230 */ 	lwc1	$f10,0x230($sp)
/*  f13fdfc:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f13fe00:	c7a20078 */ 	lwc1	$f2,0x78($sp)
/*  f13fe04:	46005183 */ 	div.s	$f6,$f10,$f0
/*  f13fe08:	46084102 */ 	mul.s	$f4,$f8,$f8
/*  f13fe0c:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f13fe10:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f13fe14:	e7a60230 */ 	swc1	$f6,0x230($sp)
/*  f13fe18:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f13fe1c:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f13fe20:	0c012974 */ 	jal	sqrtf
/*  f13fe24:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f13fe28:	c7a40234 */ 	lwc1	$f4,0x234($sp)
/*  f13fe2c:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f13fe30:	c7ae01d0 */ 	lwc1	$f14,0x1d0($sp)
/*  f13fe34:	46002203 */ 	div.s	$f8,$f4,$f0
/*  f13fe38:	c7b001d4 */ 	lwc1	$f16,0x1d4($sp)
/*  f13fe3c:	c7b201d8 */ 	lwc1	$f18,0x1d8($sp)
/*  f13fe40:	11e00005 */ 	beqz	$t7,.L0f13fe58
/*  f13fe44:	e7a80234 */ 	swc1	$f8,0x234($sp)
/*  f13fe48:	92080002 */ 	lbu	$t0,0x2($s0)
/*  f13fe4c:	350a0002 */ 	ori	$t2,$t0,0x2
/*  f13fe50:	10000049 */ 	beqz	$zero,.L0f13ff78
/*  f13fe54:	a20a0002 */ 	sb	$t2,0x2($s0)
.L0f13fe58:
/*  f13fe58:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f13fe5c:	372e0001 */ 	ori	$t6,$t9,0x1
/*  f13fe60:	10000045 */ 	beqz	$zero,.L0f13ff78
/*  f13fe64:	a20e0002 */ 	sb	$t6,0x2($s0)
.L0f13fe68:
/*  f13fe68:	0fc59b74 */ 	jal	func0f166dd0
/*  f13fe6c:	e7ae01d0 */ 	swc1	$f14,0x1d0($sp)
/*  f13fe70:	8fa30208 */ 	lw	$v1,0x208($sp)
/*  f13fe74:	c7ae01d0 */ 	lwc1	$f14,0x1d0($sp)
/*  f13fe78:	c7b001d4 */ 	lwc1	$f16,0x1d4($sp)
/*  f13fe7c:	10600021 */ 	beqz	$v1,.L0f13ff04
/*  f13fe80:	c7b201d8 */ 	lwc1	$f18,0x1d8($sp)
/*  f13fe84:	8fa90200 */ 	lw	$t1,0x200($sp)
/*  f13fe88:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f13fe8c:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f13fe90:	c52a0000 */ 	lwc1	$f10,0x0($t1)
/*  f13fe94:	c5280004 */ 	lwc1	$f8,0x4($t1)
/*  f13fe98:	3c01bf80 */ 	lui	$at,0xbf80
/*  f13fe9c:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f13fea0:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f13fea4:	c52a0008 */ 	lwc1	$f10,0x8($t1)
/*  f13fea8:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f13feac:	c7a401b8 */ 	lwc1	$f4,0x1b8($sp)
/*  f13feb0:	460a3301 */ 	sub.s	$f12,$f6,$f10
/*  f13feb4:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f13feb8:	c7a601bc */ 	lwc1	$f6,0x1bc($sp)
/*  f13febc:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f13fec0:	c7a601c0 */ 	lwc1	$f6,0x1c0($sp)
/*  f13fec4:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f13fec8:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f13fecc:	44803000 */ 	mtc1	$zero,$f6
/*  f13fed0:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f13fed4:	4606503c */ 	c.lt.s	$f10,$f6
/*  f13fed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fedc:	4502000a */ 	bc1fl	.L0f13ff08
/*  f13fee0:	3c013f80 */ 	lui	$at,0x3f80
/*  f13fee4:	44810000 */ 	mtc1	$at,$f0
/*  f13fee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13feec:	460e0382 */ 	mul.s	$f14,$f0,$f14
/*  f13fef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fef4:	46100402 */ 	mul.s	$f16,$f0,$f16
/*  f13fef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fefc:	46120482 */ 	mul.s	$f18,$f0,$f18
/*  f13ff00:	00000000 */ 	sll	$zero,$zero,0x0
.L0f13ff04:
/*  f13ff04:	3c013f80 */ 	lui	$at,0x3f80
.L0f13ff08:
/*  f13ff08:	44810000 */ 	mtc1	$at,$f0
/*  f13ff0c:	c7a401ac */ 	lwc1	$f4,0x1ac($sp)
/*  f13ff10:	c7aa01b0 */ 	lwc1	$f10,0x1b0($sp)
/*  f13ff14:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f13ff18:	c7a401b4 */ 	lwc1	$f4,0x1b4($sp)
/*  f13ff1c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f13ff20:	e7a801ac */ 	swc1	$f8,0x1ac($sp)
/*  f13ff24:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f13ff28:	c7aa01ac */ 	lwc1	$f10,0x1ac($sp)
/*  f13ff2c:	e7a601b0 */ 	swc1	$f6,0x1b0($sp)
/*  f13ff30:	e7a801b4 */ 	swc1	$f8,0x1b4($sp)
/*  f13ff34:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f13ff38:	c7a801b0 */ 	lwc1	$f8,0x1b0($sp)
/*  f13ff3c:	46065101 */ 	sub.s	$f4,$f10,$f6
/*  f13ff40:	e7a401ac */ 	swc1	$f4,0x1ac($sp)
/*  f13ff44:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f13ff48:	c7a401b4 */ 	lwc1	$f4,0x1b4($sp)
/*  f13ff4c:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f13ff50:	e7a601b0 */ 	swc1	$f6,0x1b0($sp)
/*  f13ff54:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f13ff58:	c7a60230 */ 	lwc1	$f6,0x230($sp)
/*  f13ff5c:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f13ff60:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f13ff64:	c7a80234 */ 	lwc1	$f8,0x234($sp)
/*  f13ff68:	e7aa01b4 */ 	swc1	$f10,0x1b4($sp)
/*  f13ff6c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f13ff70:	e7a40230 */ 	swc1	$f4,0x230($sp)
/*  f13ff74:	e7aa0234 */ 	swc1	$f10,0x234($sp)
.L0f13ff78:
/*  f13ff78:	c7a001dc */ 	lwc1	$f0,0x1dc($sp)
/*  f13ff7c:	c7a60230 */ 	lwc1	$f6,0x230($sp)
/*  f13ff80:	c7a201e0 */ 	lwc1	$f2,0x1e0($sp)
/*  f13ff84:	c7ac01e4 */ 	lwc1	$f12,0x1e4($sp)
/*  f13ff88:	46003002 */ 	mul.s	$f0,$f6,$f0
/*  f13ff8c:	c7a40234 */ 	lwc1	$f4,0x234($sp)
/*  f13ff90:	8fac0200 */ 	lw	$t4,0x200($sp)
/*  f13ff94:	46023082 */ 	mul.s	$f2,$f6,$f2
/*  f13ff98:	3c010fff */ 	lui	$at,0xfff
/*  f13ff9c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f13ffa0:	460c3302 */ 	mul.s	$f12,$f6,$f12
/*  f13ffa4:	27a4017c */ 	addiu	$a0,$sp,0x17c
/*  f13ffa8:	02601825 */ 	or	$v1,$s3,$zero
/*  f13ffac:	460e2382 */ 	mul.s	$f14,$f4,$f14
/*  f13ffb0:	24100010 */ 	addiu	$s0,$zero,0x10
/*  f13ffb4:	46102402 */ 	mul.s	$f16,$f4,$f16
/*  f13ffb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ffbc:	46122482 */ 	mul.s	$f18,$f4,$f18
/*  f13ffc0:	460e0200 */ 	add.s	$f8,$f0,$f14
/*  f13ffc4:	46101280 */ 	add.s	$f10,$f2,$f16
/*  f13ffc8:	e7a8017c */ 	swc1	$f8,0x17c($sp)
/*  f13ffcc:	46126180 */ 	add.s	$f6,$f12,$f18
/*  f13ffd0:	e7aa0180 */ 	swc1	$f10,0x180($sp)
/*  f13ffd4:	46101201 */ 	sub.s	$f8,$f2,$f16
/*  f13ffd8:	e7a60184 */ 	swc1	$f6,0x184($sp)
/*  f13ffdc:	c7a6017c */ 	lwc1	$f6,0x17c($sp)
/*  f13ffe0:	460e0101 */ 	sub.s	$f4,$f0,$f14
/*  f13ffe4:	e7a8018c */ 	swc1	$f8,0x18c($sp)
/*  f13ffe8:	c7a80180 */ 	lwc1	$f8,0x180($sp)
/*  f13ffec:	46126281 */ 	sub.s	$f10,$f12,$f18
/*  f13fff0:	e7a40188 */ 	swc1	$f4,0x188($sp)
/*  f13fff4:	46003107 */ 	neg.s	$f4,$f6
/*  f13fff8:	c7a60184 */ 	lwc1	$f6,0x184($sp)
/*  f13fffc:	e7aa0190 */ 	swc1	$f10,0x190($sp)
/*  f140000:	46004287 */ 	neg.s	$f10,$f8
/*  f140004:	e7a40194 */ 	swc1	$f4,0x194($sp)
/*  f140008:	46003107 */ 	neg.s	$f4,$f6
/*  f14000c:	e7aa0198 */ 	swc1	$f10,0x198($sp)
/*  f140010:	46028281 */ 	sub.s	$f10,$f16,$f2
/*  f140014:	e7a4019c */ 	swc1	$f4,0x19c($sp)
/*  f140018:	460c9181 */ 	sub.s	$f6,$f18,$f12
/*  f14001c:	e7aa01a4 */ 	swc1	$f10,0x1a4($sp)
/*  f140020:	46007201 */ 	sub.s	$f8,$f14,$f0
/*  f140024:	e7a601a8 */ 	swc1	$f6,0x1a8($sp)
/*  f140028:	e7a801a0 */ 	swc1	$f8,0x1a0($sp)
/*  f14002c:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f140030:	926e006f */ 	lbu	$t6,0x6f($s3)
/*  f140034:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0xc)
/*  f140038:	e6640050 */ 	swc1	$f4,0x50($s3)
/*  f14003c:	8fad0200 */ 	lw	$t5,0x200($sp)
/*  f140040:	31c9ffbf */ 	andi	$t1,$t6,0xffbf
/*  f140044:	c5a80004 */ 	lwc1	$f8,0x4($t5)
/*  f140048:	e6680054 */ 	swc1	$f8,0x54($s3)
/*  f14004c:	8fab0200 */ 	lw	$t3,0x200($sp)
/*  f140050:	c56a0008 */ 	lwc1	$f10,0x8($t3)
/*  f140054:	e66a0058 */ 	swc1	$f10,0x58($s3)
/*  f140058:	83b80227 */ 	lb	$t8,0x227($sp)
/*  f14005c:	a278006c */ 	sb	$t8,0x6c($s3)
/*  f140060:	83a8022b */ 	lb	$t0,0x22b($sp)
/*  f140064:	00085180 */ 	sll	$t2,$t0,0x6
/*  f140068:	31590040 */ 	andi	$t9,$t2,0x40
/*  f14006c:	0329c025 */ 	or	$t8,$t9,$t1
/*  f140070:	a278006f */ 	sb	$t8,0x6f($s3)
/*  f140074:	87ad021a */ 	lh	$t5,0x21a($sp)
/*  f140078:	8fa20248 */ 	lw	$v0,0x248($sp)
/*  f14007c:	37080080 */ 	ori	$t0,$t8,0x80
/*  f140080:	a66d0068 */ 	sh	$t5,0x68($s3)
/*  f140084:	a268006f */ 	sb	$t0,0x6f($s3)
/*  f140088:	310d00df */ 	andi	$t5,$t0,0xdf
/*  f14008c:	a26d006f */ 	sb	$t5,0x6f($s3)
/*  f140090:	87ae0216 */ 	lh	$t6,0x216($sp)
/*  f140094:	35ab0010 */ 	ori	$t3,$t5,0x10
/*  f140098:	a26e006a */ 	sb	$t6,0x6a($s3)
/*  f14009c:	8fb90220 */ 	lw	$t9,0x220($sp)
/*  f1400a0:	ae720060 */ 	sw	$s2,0x60($s3)
/*  f1400a4:	ae600064 */ 	sw	$zero,0x64($s3)
/*  f1400a8:	ae79005c */ 	sw	$t9,0x5c($s3)
/*  f1400ac:	8fa90244 */ 	lw	$t1,0x244($sp)
/*  f1400b0:	a260006e */ 	sb	$zero,0x6e($s3)
/*  f1400b4:	a26b006f */ 	sb	$t3,0x6f($s3)
/*  f1400b8:	10400007 */ 	beqz	$v0,.L0f1400d8
/*  f1400bc:	a269006d */ 	sb	$t1,0x6d($s3)
/*  f1400c0:	926f0073 */ 	lbu	$t7,0x73($s3)
/*  f1400c4:	3058000f */ 	andi	$t8,$v0,0xf
/*  f1400c8:	31e8fff0 */ 	andi	$t0,$t7,0xfff0
/*  f1400cc:	03085025 */ 	or	$t2,$t8,$t0
/*  f1400d0:	10000005 */ 	beqz	$zero,.L0f1400e8
/*  f1400d4:	a26a0073 */ 	sb	$t2,0x73($s3)
.L0f1400d8:
/*  f1400d8:	926e0073 */ 	lbu	$t6,0x73($s3)
/*  f1400dc:	31d9fff0 */ 	andi	$t9,$t6,0xfff0
/*  f1400e0:	37290008 */ 	ori	$t1,$t9,0x8
/*  f1400e4:	a2690073 */ 	sb	$t1,0x73($s3)
.L0f1400e8:
/*  f1400e8:	8e620070 */ 	lw	$v0,0x70($s3)
/*  f1400ec:	8d8c9fcc */ 	lw	$t4,%lo(g_Vars+0xc)($t4)
/*  f1400f0:	926a006f */ 	lbu	$t2,0x6f($s3)
/*  f1400f4:	00025902 */ 	srl	$t3,$v0,0x4
/*  f1400f8:	01816824 */ 	and	$t5,$t4,$at
/*  f1400fc:	01ab7826 */ 	xor	$t7,$t5,$t3
/*  f140100:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f140104:	03024026 */ 	xor	$t0,$t8,$v0
/*  f140108:	314efffb */ 	andi	$t6,$t2,0xfffb
/*  f14010c:	ae680070 */ 	sw	$t0,0x70($s3)
/*  f140110:	a26e006f */ 	sb	$t6,0x6f($s3)
/*  f140114:	00009025 */ 	or	$s2,$zero,$zero
.L0f140118:
/*  f140118:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f14011c:	c7a401ac */ 	lwc1	$f4,0x1ac($sp)
/*  f140120:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f140124:	c7aa01b0 */ 	lwc1	$f10,0x1b0($sp)
/*  f140128:	46043300 */ 	add.s	$f12,$f6,$f4
/*  f14012c:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f140130:	c7a801b4 */ 	lwc1	$f8,0x1b4($sp)
/*  f140134:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f140138:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f14013c:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f140140:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f140144:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f140148:	0fc4f838 */ 	jal	func0f13e0e0
/*  f14014c:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f140150:	a7a20056 */ 	sh	$v0,0x56($sp)
/*  f140154:	0fc4f838 */ 	jal	func0f13e0e0
/*  f140158:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f14015c:	a7a20054 */ 	sh	$v0,0x54($sp)
/*  f140160:	0fc4f838 */ 	jal	func0f13e0e0
/*  f140164:	c7ac0060 */ 	lwc1	$f12,0x60($sp)
/*  f140168:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f14016c:	87b90056 */ 	lh	$t9,0x56($sp)
/*  f140170:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f140174:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f140178:	a479fff4 */ 	sh	$t9,-0xc($v1)
/*  f14017c:	87a90054 */ 	lh	$t1,0x54($sp)
/*  f140180:	a072fffb */ 	sb	$s2,-0x5($v1)
/*  f140184:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f140188:	a462fff8 */ 	sh	$v0,-0x8($v1)
/*  f14018c:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f140190:	1650ffe1 */ 	bne	$s2,$s0,.L0f140118
/*  f140194:	a469fff6 */ 	sh	$t1,-0xa($v1)
/*  f140198:	3c02800b */ 	lui	$v0,%hi(var800ab560)
/*  f14019c:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f1401a0:	2442b560 */ 	addiu	$v0,$v0,%lo(var800ab560)
/*  f1401a4:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f1401a8:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f1401ac:	8e640060 */ 	lw	$a0,0x60($s3)
/*  f1401b0:	018d5821 */ 	addu	$t3,$t4,$t5
/*  f1401b4:	916f0005 */ 	lbu	$t7,0x5($t3)
/*  f1401b8:	a6600014 */ 	sh	$zero,0x14($s3)
/*  f1401bc:	a6600016 */ 	sh	$zero,0x16($s3)
/*  f1401c0:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f1401c4:	a678000a */ 	sh	$t8,0xa($s3)
/*  f1401c8:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f1401cc:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f1401d0:	010a7021 */ 	addu	$t6,$t0,$t2
/*  f1401d4:	91d90004 */ 	lbu	$t9,0x4($t6)
/*  f1401d8:	a6600022 */ 	sh	$zero,0x22($s3)
/*  f1401dc:	00194940 */ 	sll	$t1,$t9,0x5
/*  f1401e0:	a6690020 */ 	sh	$t1,0x20($s3)
/*  f1401e4:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f1401e8:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f1401ec:	018d5821 */ 	addu	$t3,$t4,$t5
/*  f1401f0:	916f0004 */ 	lbu	$t7,0x4($t3)
/*  f1401f4:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f1401f8:	a678002c */ 	sh	$t8,0x2c($s3)
/*  f1401fc:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f140200:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f140204:	010a7021 */ 	addu	$t6,$t0,$t2
/*  f140208:	91d90005 */ 	lbu	$t9,0x5($t6)
/*  f14020c:	00194940 */ 	sll	$t1,$t9,0x5
/*  f140210:	1080000b */ 	beqz	$a0,.L0f140240
/*  f140214:	a669002e */ 	sh	$t1,0x2e($s3)
/*  f140218:	8c820018 */ 	lw	$v0,0x18($a0)
/*  f14021c:	00801825 */ 	or	$v1,$a0,$zero
/*  f140220:	10400005 */ 	beqz	$v0,.L0f140238
/*  f140224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140228:	00401825 */ 	or	$v1,$v0,$zero
.L0f14022c:
/*  f14022c:	8c420018 */ 	lw	$v0,0x18($v0)
/*  f140230:	5440fffe */ 	bnezl	$v0,.L0f14022c
/*  f140234:	00401825 */ 	or	$v1,$v0,$zero
.L0f140238:
/*  f140238:	10000002 */ 	beqz	$zero,.L0f140244
/*  f14023c:	84640028 */ 	lh	$a0,0x28($v1)
.L0f140240:
/*  f140240:	86640068 */ 	lh	$a0,0x68($s3)
.L0f140244:
/*  f140244:	0fc00284 */ 	jal	func0f000a10
/*  f140248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14024c:	44823000 */ 	mtc1	$v0,$f6
/*  f140250:	93b2023b */ 	lbu	$s2,0x23b($sp)
/*  f140254:	04410005 */ 	bgez	$v0,.L0f14026c
/*  f140258:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f14025c:	3c014f80 */ 	lui	$at,0x4f80
/*  f140260:	44814000 */ 	mtc1	$at,$f8
/*  f140264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140268:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f14026c:
/*  f14026c:	3c017f1b */ 	lui	$at,%hi(var7f1b5d58)
/*  f140270:	c42a5d58 */ 	lwc1	$f10,%lo(var7f1b5d58)($at)
/*  f140274:	93ac023f */ 	lbu	$t4,0x23f($sp)
/*  f140278:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f14027c:	01928823 */ 	subu	$s1,$t4,$s2
/*  f140280:	1220000d */ 	beqz	$s1,.L0f1402b8
/*  f140284:	e7a60164 */ 	swc1	$f6,0x164($sp)
/*  f140288:	0c004b70 */ 	jal	random
/*  f14028c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140290:	0051001b */ 	divu	$zero,$v0,$s1
/*  f140294:	00006810 */ 	mfhi	$t5
/*  f140298:	01b28021 */ 	addu	$s0,$t5,$s2
/*  f14029c:	320b00ff */ 	andi	$t3,$s0,0xff
/*  f1402a0:	16200002 */ 	bnez	$s1,.L0f1402ac
/*  f1402a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1402a8:	0007000d */ 	break	0x7
.L0f1402ac:
/*  f1402ac:	01608025 */ 	or	$s0,$t3,$zero
/*  f1402b0:	10000003 */ 	beqz	$zero,.L0f1402c0
/*  f1402b4:	8faf0178 */ 	lw	$t7,0x178($sp)
.L0f1402b8:
/*  f1402b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1402bc:	8faf0178 */ 	lw	$t7,0x178($sp)
.L0f1402c0:
/*  f1402c0:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f1402c4:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
/*  f1402c8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1402cc:	02608825 */ 	or	$s1,$s3,$zero
/*  f1402d0:	afaf0040 */ 	sw	$t7,0x40($sp)
.L0f1402d4:
/*  f1402d4:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f1402d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1402dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f1402e0:	2f010005 */ 	sltiu	$at,$t8,0x5
/*  f1402e4:	1020007f */ 	beqz	$at,.L0f1404e4
/*  f1402e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1402ec:	3c017f1b */ 	lui	$at,%hi(var7f1b5d5c)
/*  f1402f0:	00380821 */ 	addu	$at,$at,$t8
/*  f1402f4:	8c385d5c */ 	lw	$t8,%lo(var7f1b5d5c)($at)
/*  f1402f8:	03000008 */ 	jr	$t8
/*  f1402fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140300:	0c004b70 */ 	jal	random
/*  f140304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140308:	24010028 */ 	addiu	$at,$zero,0x28
/*  f14030c:	0041001b */ 	divu	$zero,$v0,$at
/*  f140310:	00004010 */ 	mfhi	$t0
/*  f140314:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f140318:	01481823 */ 	subu	$v1,$t2,$t0
/*  f14031c:	306400ff */ 	andi	$a0,$v1,0xff
/*  f140320:	306500ff */ 	andi	$a1,$v1,0xff
/*  f140324:	12000005 */ 	beqz	$s0,.L0f14033c
/*  f140328:	306600ff */ 	andi	$a2,$v1,0xff
/*  f14032c:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f140330:	320300ff */ 	andi	$v1,$s0,0xff
/*  f140334:	10000070 */ 	beqz	$zero,.L0f1404f8
/*  f140338:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
.L0f14033c:
/*  f14033c:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f140340:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f140344:	1000006c */ 	beqz	$zero,.L0f1404f8
/*  f140348:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
/*  f14034c:	0c004b70 */ 	jal	random
/*  f140350:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140354:	24010046 */ 	addiu	$at,$zero,0x46
/*  f140358:	0041001b */ 	divu	$zero,$v0,$at
/*  f14035c:	00001810 */ 	mfhi	$v1
/*  f140360:	306400ff */ 	andi	$a0,$v1,0xff
/*  f140364:	306500ff */ 	andi	$a1,$v1,0xff
/*  f140368:	12000005 */ 	beqz	$s0,.L0f140380
/*  f14036c:	306600ff */ 	andi	$a2,$v1,0xff
/*  f140370:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f140374:	320300ff */ 	andi	$v1,$s0,0xff
/*  f140378:	1000005f */ 	beqz	$zero,.L0f1404f8
/*  f14037c:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
.L0f140380:
/*  f140380:	a3a40049 */ 	sb	$a0,0x49($sp)
/*  f140384:	a3a5004a */ 	sb	$a1,0x4a($sp)
/*  f140388:	0c004b70 */ 	jal	random
/*  f14038c:	a3a6004b */ 	sb	$a2,0x4b($sp)
/*  f140390:	24010032 */ 	addiu	$at,$zero,0x32
/*  f140394:	0041001b */ 	divu	$zero,$v0,$at
/*  f140398:	00007010 */ 	mfhi	$t6
/*  f14039c:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f1403a0:	032e1823 */ 	subu	$v1,$t9,$t6
/*  f1403a4:	306900ff */ 	andi	$t1,$v1,0xff
/*  f1403a8:	01201825 */ 	or	$v1,$t1,$zero
/*  f1403ac:	93a40049 */ 	lbu	$a0,0x49($sp)
/*  f1403b0:	93a5004a */ 	lbu	$a1,0x4a($sp)
/*  f1403b4:	93a6004b */ 	lbu	$a2,0x4b($sp)
/*  f1403b8:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f1403bc:	1000004e */ 	beqz	$zero,.L0f1404f8
/*  f1403c0:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
/*  f1403c4:	0c004b70 */ 	jal	random
/*  f1403c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1403cc:	24010032 */ 	addiu	$at,$zero,0x32
/*  f1403d0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1403d4:	00001810 */ 	mfhi	$v1
/*  f1403d8:	306400ff */ 	andi	$a0,$v1,0xff
/*  f1403dc:	306500ff */ 	andi	$a1,$v1,0xff
/*  f1403e0:	12000005 */ 	beqz	$s0,.L0f1403f8
/*  f1403e4:	306600ff */ 	andi	$a2,$v1,0xff
/*  f1403e8:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f1403ec:	320300ff */ 	andi	$v1,$s0,0xff
/*  f1403f0:	10000041 */ 	beqz	$zero,.L0f1404f8
/*  f1403f4:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
.L0f1403f8:
/*  f1403f8:	a3a40049 */ 	sb	$a0,0x49($sp)
/*  f1403fc:	a3a5004a */ 	sb	$a1,0x4a($sp)
/*  f140400:	0c004b70 */ 	jal	random
/*  f140404:	a3a6004b */ 	sb	$a2,0x4b($sp)
/*  f140408:	24010050 */ 	addiu	$at,$zero,0x50
/*  f14040c:	0041001b */ 	divu	$zero,$v0,$at
/*  f140410:	00006010 */ 	mfhi	$t4
/*  f140414:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f140418:	01ac1823 */ 	subu	$v1,$t5,$t4
/*  f14041c:	306b00ff */ 	andi	$t3,$v1,0xff
/*  f140420:	01601825 */ 	or	$v1,$t3,$zero
/*  f140424:	93a40049 */ 	lbu	$a0,0x49($sp)
/*  f140428:	93a5004a */ 	lbu	$a1,0x4a($sp)
/*  f14042c:	93a6004b */ 	lbu	$a2,0x4b($sp)
/*  f140430:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f140434:	10000030 */ 	beqz	$zero,.L0f1404f8
/*  f140438:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
/*  f14043c:	90460000 */ 	lbu	$a2,0x0($v0)
/*  f140440:	90450001 */ 	lbu	$a1,0x1($v0)
/*  f140444:	12000003 */ 	beqz	$s0,.L0f140454
/*  f140448:	90440002 */ 	lbu	$a0,0x2($v0)
/*  f14044c:	1000002a */ 	beqz	$zero,.L0f1404f8
/*  f140450:	320300ff */ 	andi	$v1,$s0,0xff
.L0f140454:
/*  f140454:	10000028 */ 	beqz	$zero,.L0f1404f8
/*  f140458:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f14045c:	0c004b70 */ 	jal	random
/*  f140460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140464:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f140468:	11e00003 */ 	beqz	$t7,.L0f140478
/*  f14046c:	00003025 */ 	or	$a2,$zero,$zero
/*  f140470:	10000001 */ 	beqz	$zero,.L0f140478
/*  f140474:	240600ff */ 	addiu	$a2,$zero,0xff
.L0f140478:
/*  f140478:	0c004b70 */ 	jal	random
/*  f14047c:	a3a6004b */ 	sb	$a2,0x4b($sp)
/*  f140480:	30580001 */ 	andi	$t8,$v0,0x1
/*  f140484:	13000003 */ 	beqz	$t8,.L0f140494
/*  f140488:	93a6004b */ 	lbu	$a2,0x4b($sp)
/*  f14048c:	10000002 */ 	beqz	$zero,.L0f140498
/*  f140490:	240500ff */ 	addiu	$a1,$zero,0xff
.L0f140494:
/*  f140494:	00002825 */ 	or	$a1,$zero,$zero
.L0f140498:
/*  f140498:	a3a5004a */ 	sb	$a1,0x4a($sp)
/*  f14049c:	0c004b70 */ 	jal	random
/*  f1404a0:	a3a6004b */ 	sb	$a2,0x4b($sp)
/*  f1404a4:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f1404a8:	93a5004a */ 	lbu	$a1,0x4a($sp)
/*  f1404ac:	11400003 */ 	beqz	$t2,.L0f1404bc
/*  f1404b0:	93a6004b */ 	lbu	$a2,0x4b($sp)
/*  f1404b4:	10000002 */ 	beqz	$zero,.L0f1404c0
/*  f1404b8:	240400ff */ 	addiu	$a0,$zero,0xff
.L0f1404bc:
/*  f1404bc:	00002025 */ 	or	$a0,$zero,$zero
.L0f1404c0:
/*  f1404c0:	12000005 */ 	beqz	$s0,.L0f1404d8
/*  f1404c4:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f1404c8:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f1404cc:	320300ff */ 	andi	$v1,$s0,0xff
/*  f1404d0:	10000009 */ 	beqz	$zero,.L0f1404f8
/*  f1404d4:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
.L0f1404d8:
/*  f1404d8:	3c028008 */ 	lui	$v0,%hi(var8007f744)
/*  f1404dc:	10000006 */ 	beqz	$zero,.L0f1404f8
/*  f1404e0:	2442f744 */ 	addiu	$v0,$v0,%lo(var8007f744)
.L0f1404e4:
/*  f1404e4:	12000003 */ 	beqz	$s0,.L0f1404f4
/*  f1404e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f1404ec:	10000002 */ 	beqz	$zero,.L0f1404f8
/*  f1404f0:	320300ff */ 	andi	$v1,$s0,0xff
.L0f1404f4:
/*  f1404f4:	240300ff */ 	addiu	$v1,$zero,0xff
.L0f1404f8:
/*  f1404f8:	44864000 */ 	mtc1	$a2,$f8
/*  f1404fc:	a2260030 */ 	sb	$a2,0x30($s1)
/*  f140500:	a2250031 */ 	sb	$a1,0x31($s1)
/*  f140504:	a2240032 */ 	sb	$a0,0x32($s1)
/*  f140508:	a2230033 */ 	sb	$v1,0x33($s1)
/*  f14050c:	04c10005 */ 	bgez	$a2,.L0f140524
/*  f140510:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f140514:	3c014f80 */ 	lui	$at,0x4f80
/*  f140518:	44815000 */ 	mtc1	$at,$f10
/*  f14051c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140520:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f140524:
/*  f140524:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f140528:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f14052c:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f140530:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f140534:	3c014f00 */ 	lui	$at,0x4f00
/*  f140538:	4448f800 */ 	cfc1	$t0,$31
/*  f14053c:	44d9f800 */ 	ctc1	$t9,$31
/*  f140540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140544:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f140548:	4459f800 */ 	cfc1	$t9,$31
/*  f14054c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140550:	33390078 */ 	andi	$t9,$t9,0x78
/*  f140554:	53200013 */ 	beqzl	$t9,.L0f1405a4
/*  f140558:	44195000 */ 	mfc1	$t9,$f10
/*  f14055c:	44815000 */ 	mtc1	$at,$f10
/*  f140560:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f140564:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f140568:	44d9f800 */ 	ctc1	$t9,$31
/*  f14056c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140570:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f140574:	4459f800 */ 	cfc1	$t9,$31
/*  f140578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14057c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f140580:	17200005 */ 	bnez	$t9,.L0f140598
/*  f140584:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140588:	44195000 */ 	mfc1	$t9,$f10
/*  f14058c:	3c018000 */ 	lui	$at,0x8000
/*  f140590:	10000007 */ 	beqz	$zero,.L0f1405b0
/*  f140594:	0321c825 */ 	or	$t9,$t9,$at
.L0f140598:
/*  f140598:	10000005 */ 	beqz	$zero,.L0f1405b0
/*  f14059c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1405a0:	44195000 */ 	mfc1	$t9,$f10
.L0f1405a4:
/*  f1405a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1405a8:	0720fffb */ 	bltz	$t9,.L0f140598
/*  f1405ac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1405b0:
/*  f1405b0:	44c8f800 */ 	ctc1	$t0,$31
/*  f1405b4:	44852000 */ 	mtc1	$a1,$f4
/*  f1405b8:	a2390040 */ 	sb	$t9,0x40($s1)
/*  f1405bc:	04a10005 */ 	bgez	$a1,.L0f1405d4
/*  f1405c0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1405c4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1405c8:	44814000 */ 	mtc1	$at,$f8
/*  f1405cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1405d0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1405d4:
/*  f1405d4:	c7aa0164 */ 	lwc1	$f10,0x164($sp)
/*  f1405d8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1405dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f1405e0:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f1405e4:	444ef800 */ 	cfc1	$t6,$31
/*  f1405e8:	44c9f800 */ 	ctc1	$t1,$31
/*  f1405ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1405f0:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f1405f4:	4449f800 */ 	cfc1	$t1,$31
/*  f1405f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1405fc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f140600:	51200013 */ 	beqzl	$t1,.L0f140650
/*  f140604:	44094000 */ 	mfc1	$t1,$f8
/*  f140608:	44814000 */ 	mtc1	$at,$f8
/*  f14060c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f140610:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f140614:	44c9f800 */ 	ctc1	$t1,$31
/*  f140618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14061c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f140620:	4449f800 */ 	cfc1	$t1,$31
/*  f140624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140628:	31290078 */ 	andi	$t1,$t1,0x78
/*  f14062c:	15200005 */ 	bnez	$t1,.L0f140644
/*  f140630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140634:	44094000 */ 	mfc1	$t1,$f8
/*  f140638:	3c018000 */ 	lui	$at,0x8000
/*  f14063c:	10000007 */ 	beqz	$zero,.L0f14065c
/*  f140640:	01214825 */ 	or	$t1,$t1,$at
.L0f140644:
/*  f140644:	10000005 */ 	beqz	$zero,.L0f14065c
/*  f140648:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f14064c:	44094000 */ 	mfc1	$t1,$f8
.L0f140650:
/*  f140650:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140654:	0520fffb */ 	bltz	$t1,.L0f140644
/*  f140658:	00000000 */ 	sll	$zero,$zero,0x0
.L0f14065c:
/*  f14065c:	44cef800 */ 	ctc1	$t6,$31
/*  f140660:	44843000 */ 	mtc1	$a0,$f6
/*  f140664:	a2290041 */ 	sb	$t1,0x41($s1)
/*  f140668:	04810005 */ 	bgez	$a0,.L0f140680
/*  f14066c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f140670:	3c014f80 */ 	lui	$at,0x4f80
/*  f140674:	44812000 */ 	mtc1	$at,$f4
/*  f140678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14067c:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f140680:
/*  f140680:	c7a80164 */ 	lwc1	$f8,0x164($sp)
/*  f140684:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f140688:	3c014f00 */ 	lui	$at,0x4f00
/*  f14068c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f140690:	444df800 */ 	cfc1	$t5,$31
/*  f140694:	44ccf800 */ 	ctc1	$t4,$31
/*  f140698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14069c:	46003124 */ 	cvt.w.s	$f4,$f6
/*  f1406a0:	444cf800 */ 	cfc1	$t4,$31
/*  f1406a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1406a8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1406ac:	51800013 */ 	beqzl	$t4,.L0f1406fc
/*  f1406b0:	440c2000 */ 	mfc1	$t4,$f4
/*  f1406b4:	44812000 */ 	mtc1	$at,$f4
/*  f1406b8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1406bc:	46043101 */ 	sub.s	$f4,$f6,$f4
/*  f1406c0:	44ccf800 */ 	ctc1	$t4,$31
/*  f1406c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1406c8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1406cc:	444cf800 */ 	cfc1	$t4,$31
/*  f1406d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1406d4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1406d8:	15800005 */ 	bnez	$t4,.L0f1406f0
/*  f1406dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1406e0:	440c2000 */ 	mfc1	$t4,$f4
/*  f1406e4:	3c018000 */ 	lui	$at,0x8000
/*  f1406e8:	10000007 */ 	beqz	$zero,.L0f140708
/*  f1406ec:	01816025 */ 	or	$t4,$t4,$at
.L0f1406f0:
/*  f1406f0:	10000005 */ 	beqz	$zero,.L0f140708
/*  f1406f4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1406f8:	440c2000 */ 	mfc1	$t4,$f4
.L0f1406fc:
/*  f1406fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140700:	0580fffb */ 	bltz	$t4,.L0f1406f0
/*  f140704:	00000000 */ 	sll	$zero,$zero,0x0
.L0f140708:
/*  f140708:	a22c0042 */ 	sb	$t4,0x42($s1)
/*  f14070c:	926b006d */ 	lbu	$t3,0x6d($s3)
/*  f140710:	44cdf800 */ 	ctc1	$t5,$31
/*  f140714:	24010010 */ 	addiu	$at,$zero,0x10
/*  f140718:	51600004 */ 	beqzl	$t3,.L0f14072c
/*  f14071c:	a2230043 */ 	sb	$v1,0x43($s1)
/*  f140720:	10000002 */ 	beqz	$zero,.L0f14072c
/*  f140724:	a2200043 */ 	sb	$zero,0x43($s1)
/*  f140728:	a2230043 */ 	sb	$v1,0x43($s1)
.L0f14072c:
/*  f14072c:	1641fee9 */ 	bne	$s2,$at,.L0f1402d4
/*  f140730:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f140734:
/*  f140734:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f140738:
/*  f140738:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14073c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f140740:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f140744:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f140748:	03e00008 */ 	jr	$ra
/*  f14074c:	27bd0200 */ 	addiu	$sp,$sp,0x200
);

GLOBAL_ASM(
glabel func0f140750
/*  f140750:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f140754:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f140758:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f14075c:	44807000 */ 	mtc1	$zero,$f14
/*  f140760:	8dc2174c */ 	lw	$v0,0x174c($t6)
/*  f140764:	3c038008 */ 	lui	$v1,%hi(var8007f740)
/*  f140768:	2463f740 */ 	addiu	$v1,$v1,%lo(var8007f740)
/*  f14076c:	c4440030 */ 	lwc1	$f4,0x30($v0)
/*  f140770:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f140774:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f140778:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f14077c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f140780:	c4480034 */ 	lwc1	$f8,0x34($v0)
/*  f140784:	c4500038 */ 	lwc1	$f16,0x38($v0)
/*  f140788:	460e003c */ 	c.lt.s	$f0,$f14
/*  f14078c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f140790:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f140794:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f140798:	45000002 */ 	bc1f	.L0f1407a4
/*  f14079c:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f1407a0:	46000007 */ 	neg.s	$f0,$f0
.L0f1407a4:
/*  f1407a4:	460e103c */ 	c.lt.s	$f2,$f14
/*  f1407a8:	3c018008 */ 	lui	$at,0x8008
/*  f1407ac:	45020003 */ 	bc1fl	.L0f1407bc
/*  f1407b0:	460e603c */ 	c.lt.s	$f12,$f14
/*  f1407b4:	46001087 */ 	neg.s	$f2,$f2
/*  f1407b8:	460e603c */ 	c.lt.s	$f12,$f14
.L0f1407bc:
/*  f1407bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1407c0:	45020003 */ 	bc1fl	.L0f1407d0
/*  f1407c4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1407c8:	46006307 */ 	neg.s	$f12,$f12
/*  f1407cc:	4602003c */ 	c.lt.s	$f0,$f2
.L0f1407d0:
/*  f1407d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1407d4:	45020003 */ 	bc1fl	.L0f1407e4
/*  f1407d8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1407dc:	46001006 */ 	mov.s	$f0,$f2
/*  f1407e0:	460c003c */ 	c.lt.s	$f0,$f12
.L0f1407e4:
/*  f1407e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1407e8:	45000002 */ 	bc1f	.L0f1407f4
/*  f1407ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1407f0:	46006006 */ 	mov.s	$f0,$f12
.L0f1407f4:
/*  f1407f4:	c424f74c */ 	lwc1	$f4,-0x8b4($at)
/*  f1407f8:	3c0144c8 */ 	lui	$at,0x44c8
/*  f1407fc:	44813000 */ 	mtc1	$at,$f6
/*  f140800:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f140804:	3c0143c8 */ 	lui	$at,0x43c8
/*  f140808:	4602303c */ 	c.lt.s	$f6,$f2
/*  f14080c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140810:	45020004 */ 	bc1fl	.L0f140824
/*  f140814:	44814000 */ 	mtc1	$at,$f8
/*  f140818:	03e00008 */ 	jr	$ra
/*  f14081c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f140820:	44814000 */ 	mtc1	$at,$f8
.L0f140824:
/*  f140824:	3c014396 */ 	lui	$at,0x4396
/*  f140828:	4602403c */ 	c.lt.s	$f8,$f2
/*  f14082c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140830:	45020004 */ 	bc1fl	.L0f140844
/*  f140834:	44815000 */ 	mtc1	$at,$f10
/*  f140838:	03e00008 */ 	jr	$ra
/*  f14083c:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f140840:	44815000 */ 	mtc1	$at,$f10
.L0f140844:
/*  f140844:	3c014348 */ 	lui	$at,0x4348
/*  f140848:	4602503c */ 	c.lt.s	$f10,$f2
/*  f14084c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140850:	45020004 */ 	bc1fl	.L0f140864
/*  f140854:	44818000 */ 	mtc1	$at,$f16
/*  f140858:	03e00008 */ 	jr	$ra
/*  f14085c:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f140860:	44818000 */ 	mtc1	$at,$f16
.L0f140864:
/*  f140864:	3c0142c8 */ 	lui	$at,0x42c8
/*  f140868:	4602803c */ 	c.lt.s	$f16,$f2
/*  f14086c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140870:	45020004 */ 	bc1fl	.L0f140884
/*  f140874:	44819000 */ 	mtc1	$at,$f18
/*  f140878:	03e00008 */ 	jr	$ra
/*  f14087c:	24020020 */ 	addiu	$v0,$zero,0x20
/*  f140880:	44819000 */ 	mtc1	$at,$f18
.L0f140884:
/*  f140884:	24020080 */ 	addiu	$v0,$zero,0x80
/*  f140888:	4602903c */ 	c.lt.s	$f18,$f2
/*  f14088c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140890:	45000003 */ 	bc1f	.L0f1408a0
/*  f140894:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140898:	03e00008 */ 	jr	$ra
/*  f14089c:	24020040 */ 	addiu	$v0,$zero,0x40
.L0f1408a0:
/*  f1408a0:	03e00008 */ 	jr	$ra
/*  f1408a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1408a8
/*  f1408a8:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1408ac:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f1408b0:	24af0008 */ 	addiu	$t7,$a1,0x8
/*  f1408b4:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f1408b8:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f1408bc:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f1408c0:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f1408c4:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f1408c8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f1408cc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f1408d0:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1408d4:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1408d8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1408dc:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f1408e0:	3c18b600 */ 	lui	$t8,0xb600
/*  f1408e4:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f1408e8:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1408ec:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1408f0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f1408f4:	24082000 */ 	addiu	$t0,$zero,0x2000
/*  f1408f8:	3c0bb700 */ 	lui	$t3,0xb700
/*  f1408fc:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f140900:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f140904:	ad280004 */ 	sw	$t0,0x4($t1)
/*  f140908:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f14090c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f140910:	3c0eba00 */ 	lui	$t6,0xba00
/*  f140914:	35ce1102 */ 	ori	$t6,$t6,0x1102
/*  f140918:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f14091c:	afad0054 */ 	sw	$t5,0x54($sp)
/*  f140920:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f140924:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f140928:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f14092c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f140930:	37390602 */ 	ori	$t9,$t9,0x602
/*  f140934:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f140938:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f14093c:	24090080 */ 	addiu	$t1,$zero,0x80
/*  f140940:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f140944:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f140948:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f14094c:	3c0cba00 */ 	lui	$t4,0xba00
/*  f140950:	358c0c02 */ 	ori	$t4,$t4,0xc02
/*  f140954:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f140958:	afab0054 */ 	sw	$t3,0x54($sp)
/*  f14095c:	00808825 */ 	or	$s1,$a0,$zero
/*  f140960:	ad480004 */ 	sw	$t0,0x4($t2)
/*  f140964:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f140968:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f14096c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f140970:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f140974:	0fc59b5f */ 	jal	func0f166d7c
/*  f140978:	02202825 */ 	or	$a1,$s1,$zero
/*  f14097c:	001170c0 */ 	sll	$t6,$s1,0x3
/*  f140980:	01d17021 */ 	addu	$t6,$t6,$s1
/*  f140984:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f140988:	8dad4928 */ 	lw	$t5,%lo(g_Rooms)($t5)
/*  f14098c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f140990:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f140994:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f140998:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f14099c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1409a0:	8df00084 */ 	lw	$s0,0x84($t7)
/*  f1409a4:	3c1e800b */ 	lui	$s8,%hi(var800ab560)
/*  f1409a8:	27deb560 */ 	addiu	$s8,$s8,%lo(var800ab560)
/*  f1409ac:	12000057 */ 	beqz	$s0,.L0f140b0c
/*  f1409b0:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f1409b4:	3c140430 */ 	lui	$s4,0x430
/*  f1409b8:	36940030 */ 	ori	$s4,$s4,0x30
/*  f1409bc:	27b60054 */ 	addiu	$s6,$sp,0x54
/*  f1409c0:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f1409c4:	8219006f */ 	lb	$t9,0x6f($s0)
.L0f1409c8:
/*  f1409c8:	0723004e */ 	bgezl	$t9,.L0f140b04
/*  f1409cc:	8e100078 */ 	lw	$s0,0x78($s0)
/*  f1409d0:	8e02006c */ 	lw	$v0,0x6c($s0)
/*  f1409d4:	00025740 */ 	sll	$t2,$v0,0x1d
/*  f1409d8:	05410049 */ 	bgez	$t2,.L0f140b00
/*  f1409dc:	00026700 */ 	sll	$t4,$v0,0x1c
/*  f1409e0:	05810003 */ 	bgez	$t4,.L0f1409f0
/*  f1409e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1409e8:	10000004 */ 	beqz	$zero,.L0f1409fc
/*  f1409ec:	a215006b */ 	sb	$s5,0x6b($s0)
.L0f1409f0:
/*  f1409f0:	0fc501d4 */ 	jal	func0f140750
/*  f1409f4:	26040050 */ 	addiu	$a0,$s0,0x50
/*  f1409f8:	a202006b */ 	sb	$v0,0x6b($s0)
.L0f1409fc:
/*  f1409fc:	9202006a */ 	lbu	$v0,0x6a($s0)
/*  f140a00:	16420004 */ 	bne	$s2,$v0,.L0f140a14
/*  f140a04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140a08:	920d006b */ 	lbu	$t5,0x6b($s0)
/*  f140a0c:	126d0011 */ 	beq	$s3,$t5,.L0f140a54
/*  f140a10:	00000000 */ 	sll	$zero,$zero,0x0
.L0f140a14:
/*  f140a14:	00570019 */ 	multu	$v0,$s7
/*  f140a18:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*  f140a1c:	9207006b */ 	lbu	$a3,0x6b($s0)
/*  f140a20:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f140a24:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f140a28:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f140a2c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f140a30:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f140a34:	02c02025 */ 	or	$a0,$s6,$zero
/*  f140a38:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f140a3c:	00007012 */ 	mflo	$t6
/*  f140a40:	01cf2821 */ 	addu	$a1,$t6,$t7
/*  f140a44:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f140a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140a4c:	9212006a */ 	lbu	$s2,0x6a($s0)
/*  f140a50:	9213006b */ 	lbu	$s3,0x6b($s0)
.L0f140a54:
/*  f140a54:	0fc59e73 */ 	jal	func0f1679cc
/*  f140a58:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f140a5c:	8e010040 */ 	lw	$at,0x40($s0)
/*  f140a60:	3c0a070c */ 	lui	$t2,0x70c
/*  f140a64:	354a0010 */ 	ori	$t2,$t2,0x10
/*  f140a68:	ac410000 */ 	sw	$at,0x0($v0)
/*  f140a6c:	8e010044 */ 	lw	$at,0x44($s0)
/*  f140a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f140a74:	ac410004 */ 	sw	$at,0x4($v0)
/*  f140a78:	8e010048 */ 	lw	$at,0x48($s0)
/*  f140a7c:	ac410008 */ 	sw	$at,0x8($v0)
/*  f140a80:	8e01004c */ 	lw	$at,0x4c($s0)
/*  f140a84:	ac41000c */ 	sw	$at,0xc($v0)
/*  f140a88:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f140a8c:	26290008 */ 	addiu	$t1,$s1,0x8
/*  f140a90:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f140a94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f140a98:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f140a9c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f140aa0:	8e0b0064 */ 	lw	$t3,0x64($s0)
/*  f140aa4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f140aa8:	02002025 */ 	or	$a0,$s0,$zero
/*  f140aac:	11600008 */ 	beqz	$t3,.L0f140ad0
/*  f140ab0:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f140ab4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f140ab8:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f140abc:	afad0054 */ 	sw	$t5,0x54($sp)
/*  f140ac0:	ad940000 */ 	sw	$s4,0x0($t4)
/*  f140ac4:	8e0e0064 */ 	lw	$t6,0x64($s0)
/*  f140ac8:	10000005 */ 	beqz	$zero,.L0f140ae0
/*  f140acc:	ad8e0004 */ 	sw	$t6,0x4($t4)
.L0f140ad0:
/*  f140ad0:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f140ad4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f140ad8:	ae340000 */ 	sw	$s4,0x0($s1)
/*  f140adc:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f140ae0:
/*  f140ae0:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f140ae4:	3c0ab100 */ 	lui	$t2,0xb100
/*  f140ae8:	354a0032 */ 	ori	$t2,$t2,0x32
/*  f140aec:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f140af0:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f140af4:	240b2010 */ 	addiu	$t3,$zero,0x2010
/*  f140af8:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f140afc:	af2a0000 */ 	sw	$t2,0x0($t9)
.L0f140b00:
/*  f140b00:	8e100078 */ 	lw	$s0,0x78($s0)
.L0f140b04:
/*  f140b04:	5600ffb0 */ 	bnezl	$s0,.L0f1409c8
/*  f140b08:	8219006f */ 	lb	$t9,0x6f($s0)
.L0f140b0c:
/*  f140b0c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f140b10:	3c0eb600 */ 	lui	$t6,0xb600
/*  f140b14:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f140b18:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f140b1c:	afad0054 */ 	sw	$t5,0x54($sp)
/*  f140b20:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f140b24:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f140b28:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f140b2c:	3c09ba00 */ 	lui	$t1,0xba00
/*  f140b30:	35290602 */ 	ori	$t1,$t1,0x602
/*  f140b34:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f140b38:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f140b3c:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f140b40:	af0a0004 */ 	sw	$t2,0x4($t8)
/*  f140b44:	af090000 */ 	sw	$t1,0x0($t8)
/*  f140b48:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f140b4c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f140b50:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f140b54:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f140b58:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f140b5c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f140b60:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f140b64:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f140b68:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f140b6c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f140b70:	8fa20054 */ 	lw	$v0,0x54($sp)
/*  f140b74:	03e00008 */ 	jr	$ra
/*  f140b78:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f140b7c
/*  f140b7c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f140b80:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f140b84:	24af0008 */ 	addiu	$t7,$a1,0x8
/*  f140b88:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f140b8c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f140b90:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f140b94:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f140b98:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f140b9c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f140ba0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f140ba4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f140ba8:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f140bac:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f140bb0:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f140bb4:	3c18b600 */ 	lui	$t8,0xb600
/*  f140bb8:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f140bbc:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f140bc0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f140bc4:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f140bc8:	3c0aba00 */ 	lui	$t2,0xba00
/*  f140bcc:	354a1102 */ 	ori	$t2,$t2,0x1102
/*  f140bd0:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f140bd4:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f140bd8:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f140bdc:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f140be0:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f140be4:	3c0dba00 */ 	lui	$t5,0xba00
/*  f140be8:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f140bec:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f140bf0:	afac0054 */ 	sw	$t4,0x54($sp)
/*  f140bf4:	240e0080 */ 	addiu	$t6,$zero,0x80
/*  f140bf8:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f140bfc:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f140c00:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f140c04:	3c19ba00 */ 	lui	$t9,0xba00
/*  f140c08:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f140c0c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f140c10:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f140c14:	24082000 */ 	addiu	$t0,$zero,0x2000
/*  f140c18:	00808825 */ 	or	$s1,$a0,$zero
/*  f140c1c:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f140c20:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f140c24:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f140c28:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f140c2c:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f140c30:	0fc59b5f */ 	jal	func0f166d7c
/*  f140c34:	02202825 */ 	or	$a1,$s1,$zero
/*  f140c38:	001150c0 */ 	sll	$t2,$s1,0x3
/*  f140c3c:	01515021 */ 	addu	$t2,$t2,$s1
/*  f140c40:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f140c44:	8d294928 */ 	lw	$t1,%lo(g_Rooms)($t1)
/*  f140c48:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f140c4c:	01515023 */ 	subu	$t2,$t2,$s1
/*  f140c50:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f140c54:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f140c58:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f140c5c:	8d700088 */ 	lw	$s0,0x88($t3)
/*  f140c60:	3c1e800b */ 	lui	$s8,%hi(var800ab560)
/*  f140c64:	27deb560 */ 	addiu	$s8,$s8,%lo(var800ab560)
/*  f140c68:	12000051 */ 	beqz	$s0,.L0f140db0
/*  f140c6c:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f140c70:	3c140430 */ 	lui	$s4,0x430
/*  f140c74:	36940030 */ 	ori	$s4,$s4,0x30
/*  f140c78:	27b60054 */ 	addiu	$s6,$sp,0x54
/*  f140c7c:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f140c80:	820d006f */ 	lb	$t5,0x6f($s0)
.L0f140c84:
/*  f140c84:	05a30048 */ 	bgezl	$t5,.L0f140da8
/*  f140c88:	8e100078 */ 	lw	$s0,0x78($s0)
/*  f140c8c:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f140c90:	000ec740 */ 	sll	$t8,$t6,0x1d
/*  f140c94:	07030044 */ 	bgezl	$t8,.L0f140da8
/*  f140c98:	8e100078 */ 	lw	$s0,0x78($s0)
/*  f140c9c:	9202006a */ 	lbu	$v0,0x6a($s0)
/*  f140ca0:	a215006b */ 	sb	$s5,0x6b($s0)
/*  f140ca4:	32b900ff */ 	andi	$t9,$s5,0xff
/*  f140ca8:	16420003 */ 	bne	$s2,$v0,.L0f140cb8
/*  f140cac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140cb0:	12790011 */ 	beq	$s3,$t9,.L0f140cf8
/*  f140cb4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f140cb8:
/*  f140cb8:	00570019 */ 	multu	$v0,$s7
/*  f140cbc:	8fc90000 */ 	lw	$t1,0x0($s8)
/*  f140cc0:	9207006b */ 	lbu	$a3,0x6b($s0)
/*  f140cc4:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f140cc8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f140ccc:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f140cd0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f140cd4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f140cd8:	02c02025 */ 	or	$a0,$s6,$zero
/*  f140cdc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f140ce0:	00004012 */ 	mflo	$t0
/*  f140ce4:	01092821 */ 	addu	$a1,$t0,$t1
/*  f140ce8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f140cec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140cf0:	9212006a */ 	lbu	$s2,0x6a($s0)
/*  f140cf4:	9213006b */ 	lbu	$s3,0x6b($s0)
.L0f140cf8:
/*  f140cf8:	0fc59e73 */ 	jal	func0f1679cc
/*  f140cfc:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f140d00:	8e010040 */ 	lw	$at,0x40($s0)
/*  f140d04:	3c0c070c */ 	lui	$t4,0x70c
/*  f140d08:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f140d0c:	ac410000 */ 	sw	$at,0x0($v0)
/*  f140d10:	8e010044 */ 	lw	$at,0x44($s0)
/*  f140d14:	00402025 */ 	or	$a0,$v0,$zero
/*  f140d18:	ac410004 */ 	sw	$at,0x4($v0)
/*  f140d1c:	8e010048 */ 	lw	$at,0x48($s0)
/*  f140d20:	ac410008 */ 	sw	$at,0x8($v0)
/*  f140d24:	8e01004c */ 	lw	$at,0x4c($s0)
/*  f140d28:	ac41000c */ 	sw	$at,0xc($v0)
/*  f140d2c:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f140d30:	262b0008 */ 	addiu	$t3,$s1,0x8
/*  f140d34:	afab0054 */ 	sw	$t3,0x54($sp)
/*  f140d38:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f140d3c:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f140d40:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f140d44:	8e0d0064 */ 	lw	$t5,0x64($s0)
/*  f140d48:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f140d4c:	02002025 */ 	or	$a0,$s0,$zero
/*  f140d50:	11a00008 */ 	beqz	$t5,.L0f140d74
/*  f140d54:	26280008 */ 	addiu	$t0,$s1,0x8
/*  f140d58:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f140d5c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f140d60:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f140d64:	add40000 */ 	sw	$s4,0x0($t6)
/*  f140d68:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f140d6c:	10000005 */ 	beqz	$zero,.L0f140d84
/*  f140d70:	add80004 */ 	sw	$t8,0x4($t6)
.L0f140d74:
/*  f140d74:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f140d78:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f140d7c:	ae340000 */ 	sw	$s4,0x0($s1)
/*  f140d80:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f140d84:
/*  f140d84:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f140d88:	3c0bb100 */ 	lui	$t3,0xb100
/*  f140d8c:	356b0032 */ 	ori	$t3,$t3,0x32
/*  f140d90:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f140d94:	afaa0054 */ 	sw	$t2,0x54($sp)
/*  f140d98:	240c2010 */ 	addiu	$t4,$zero,0x2010
/*  f140d9c:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f140da0:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f140da4:	8e100078 */ 	lw	$s0,0x78($s0)
.L0f140da8:
/*  f140da8:	5600ffb6 */ 	bnezl	$s0,.L0f140c84
/*  f140dac:	820d006f */ 	lb	$t5,0x6f($s0)
.L0f140db0:
/*  f140db0:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f140db4:	3c0fb600 */ 	lui	$t7,0xb600
/*  f140db8:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f140dbc:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f140dc0:	afae0054 */ 	sw	$t6,0x54($sp)
/*  f140dc4:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f140dc8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f140dcc:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f140dd0:	3c09ba00 */ 	lui	$t1,0xba00
/*  f140dd4:	35290602 */ 	ori	$t1,$t1,0x602
/*  f140dd8:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f140ddc:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f140de0:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f140de4:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f140de8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f140dec:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f140df0:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f140df4:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f140df8:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f140dfc:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f140e00:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f140e04:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f140e08:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f140e0c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f140e10:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f140e14:	8fa20054 */ 	lw	$v0,0x54($sp)
/*  f140e18:	03e00008 */ 	jr	$ra
/*  f140e1c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f140e20
/*  f140e20:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f140e24:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f140e28:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f140e2c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f140e30:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f140e34:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f140e38:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f140e3c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f140e40:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f140e44:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f140e48:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f140e4c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f140e50:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f140e54:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f140e58:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f140e5c:	8cbe0004 */ 	lw	$s8,0x4($a1)
/*  f140e60:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f140e64:	95cf0010 */ 	lhu	$t7,0x10($t6)
/*  f140e68:	24010001 */ 	addiu	$at,$zero,0x1
/*  f140e6c:	00a09025 */ 	or	$s2,$a1,$zero
/*  f140e70:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f140e74:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f140e78:	15e10003 */ 	bne	$t7,$at,.L0f140e88
/*  f140e7c:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f140e80:	100000bf */ 	beqz	$zero,.L0f141180
/*  f140e84:	00801025 */ 	or	$v0,$a0,$zero
.L0f140e88:
/*  f140e88:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f140e8c:	3c08b600 */ 	lui	$t0,0xb600
/*  f140e90:	24093000 */ 	addiu	$t1,$zero,0x3000
/*  f140e94:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f140e98:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f140e9c:	af090004 */ 	sw	$t1,0x4($t8)
/*  f140ea0:	af080000 */ 	sw	$t0,0x0($t8)
/*  f140ea4:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f140ea8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f140eac:	8fab00b8 */ 	lw	$t3,0xb8($sp)
/*  f140eb0:	15400007 */ 	bnez	$t2,.L0f140ed0
/*  f140eb4:	37391102 */ 	ori	$t9,$t9,0x1102
/*  f140eb8:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f140ebc:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f140ec0:	3c0db700 */ 	lui	$t5,0xb700
/*  f140ec4:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f140ec8:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f140ecc:	ad6d0000 */ 	sw	$t5,0x0($t3)
.L0f140ed0:
/*  f140ed0:	8faf00b8 */ 	lw	$t7,0xb8($sp)
/*  f140ed4:	3c0aba00 */ 	lui	$t2,0xba00
/*  f140ed8:	354a0602 */ 	ori	$t2,$t2,0x602
/*  f140edc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f140ee0:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f140ee4:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f140ee8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f140eec:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*  f140ef0:	240b0080 */ 	addiu	$t3,$zero,0x80
/*  f140ef4:	3c0eba00 */ 	lui	$t6,0xba00
/*  f140ef8:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f140efc:	afa900b8 */ 	sw	$t1,0xb8($sp)
/*  f140f00:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f140f04:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f140f08:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f140f0c:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f140f10:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f140f14:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f140f18:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f140f1c:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f140f20:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f140f24:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f140f28:	3c140430 */ 	lui	$s4,0x430
/*  f140f2c:	36940030 */ 	ori	$s4,$s4,0x30
/*  f140f30:	13000003 */ 	beqz	$t8,.L0f140f40
/*  f140f34:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f140f38:	10000002 */ 	beqz	$zero,.L0f140f44
/*  f140f3c:	8e500044 */ 	lw	$s0,0x44($s2)
.L0f140f40:
/*  f140f40:	8e500040 */ 	lw	$s0,0x40($s2)
.L0f140f44:
/*  f140f44:	52000076 */ 	beqzl	$s0,.L0f141120
/*  f140f48:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f140f4c:	8208006f */ 	lb	$t0,0x6f($s0)
.L0f140f50:
/*  f140f50:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f140f54:	0503006f */ 	bgezl	$t0,.L0f141114
/*  f140f58:	8e100078 */ 	lw	$s0,0x78($s0)
/*  f140f5c:	afa900ac */ 	sw	$t1,0xac($sp)
/*  f140f60:	9202006c */ 	lbu	$v0,0x6c($s0)
/*  f140f64:	8fb100b8 */ 	lw	$s1,0xb8($sp)
/*  f140f68:	3c180102 */ 	lui	$t8,0x102
/*  f140f6c:	12a2000d */ 	beq	$s5,$v0,.L0f140fa4
/*  f140f70:	00026180 */ 	sll	$t4,$v0,0x6
/*  f140f74:	8fca0018 */ 	lw	$t2,0x18($s8)
/*  f140f78:	0002ac00 */ 	sll	$s5,$v0,0x10
/*  f140f7c:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f140f80:	8d4b000c */ 	lw	$t3,0xc($t2)
/*  f140f84:	00156c03 */ 	sra	$t5,$s5,0x10
/*  f140f88:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f140f8c:	37180040 */ 	ori	$t8,$t8,0x40
/*  f140f90:	01a0a825 */ 	or	$s5,$t5,$zero
/*  f140f94:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f140f98:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f140f9c:	016c2021 */ 	addu	$a0,$t3,$t4
/*  f140fa0:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f140fa4:
/*  f140fa4:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f140fa8:	57200018 */ 	bnezl	$t9,.L0f14100c
/*  f140fac:	a213006b */ 	sb	$s3,0x6b($s0)
/*  f140fb0:	8e08006c */ 	lw	$t0,0x6c($s0)
/*  f140fb4:	00085700 */ 	sll	$t2,$t0,0x1c
/*  f140fb8:	05430004 */ 	bgezl	$t2,.L0f140fcc
/*  f140fbc:	c6040050 */ 	lwc1	$f4,0x50($s0)
/*  f140fc0:	10000012 */ 	beqz	$zero,.L0f14100c
/*  f140fc4:	a213006b */ 	sb	$s3,0x6b($s0)
/*  f140fc8:	c6040050 */ 	lwc1	$f4,0x50($s0)
.L0f140fcc:
/*  f140fcc:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f140fd0:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f140fd4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f140fd8:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f140fdc:	c650000c */ 	lwc1	$f16,0xc($s2)
/*  f140fe0:	c60a0054 */ 	lwc1	$f10,0x54($s0)
/*  f140fe4:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f140fe8:	e7b20078 */ 	swc1	$f18,0x78($sp)
/*  f140fec:	c6460010 */ 	lwc1	$f6,0x10($s2)
/*  f140ff0:	c6040058 */ 	lwc1	$f4,0x58($s0)
/*  f140ff4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f140ff8:	0fc501d4 */ 	jal	func0f140750
/*  f140ffc:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f141000:	10000002 */ 	beqz	$zero,.L0f14100c
/*  f141004:	a202006b */ 	sb	$v0,0x6b($s0)
/*  f141008:	a213006b */ 	sb	$s3,0x6b($s0)
.L0f14100c:
/*  f14100c:	9202006a */ 	lbu	$v0,0x6a($s0)
/*  f141010:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f141014:	3c0d800b */ 	lui	$t5,%hi(var800ab560)
/*  f141018:	16c20004 */ 	bne	$s6,$v0,.L0f14102c
/*  f14101c:	00026080 */ 	sll	$t4,$v0,0x2
/*  f141020:	920b006b */ 	lbu	$t3,0x6b($s0)
/*  f141024:	12eb000f */ 	beq	$s7,$t3,.L0f141064
/*  f141028:	00000000 */ 	sll	$zero,$zero,0x0
.L0f14102c:
/*  f14102c:	8dadb560 */ 	lw	$t5,%lo(var800ab560)($t5)
/*  f141030:	01826023 */ 	subu	$t4,$t4,$v0
/*  f141034:	9207006b */ 	lbu	$a3,0x6b($s0)
/*  f141038:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f14103c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f141040:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f141044:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f141048:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f14104c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f141050:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f141054:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f141058:	018d2821 */ 	addu	$a1,$t4,$t5
/*  f14105c:	9216006a */ 	lbu	$s6,0x6a($s0)
/*  f141060:	9217006b */ 	lbu	$s7,0x6b($s0)
.L0f141064:
/*  f141064:	0fc59e73 */ 	jal	func0f1679cc
/*  f141068:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f14106c:	8e010040 */ 	lw	$at,0x40($s0)
/*  f141070:	3c18070c */ 	lui	$t8,0x70c
/*  f141074:	37180010 */ 	ori	$t8,$t8,0x10
/*  f141078:	ac410000 */ 	sw	$at,0x0($v0)
/*  f14107c:	8e010044 */ 	lw	$at,0x44($s0)
/*  f141080:	00402025 */ 	or	$a0,$v0,$zero
/*  f141084:	ac410004 */ 	sw	$at,0x4($v0)
/*  f141088:	8e010048 */ 	lw	$at,0x48($s0)
/*  f14108c:	ac410008 */ 	sw	$at,0x8($v0)
/*  f141090:	8e01004c */ 	lw	$at,0x4c($s0)
/*  f141094:	ac41000c */ 	sw	$at,0xc($v0)
/*  f141098:	8fb100b8 */ 	lw	$s1,0xb8($sp)
/*  f14109c:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f1410a0:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f1410a4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1410a8:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f1410ac:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f1410b0:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f1410b4:	8fb100b8 */ 	lw	$s1,0xb8($sp)
/*  f1410b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1410bc:	13200008 */ 	beqz	$t9,.L0f1410e0
/*  f1410c0:	262c0008 */ 	addiu	$t4,$s1,0x8
/*  f1410c4:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*  f1410c8:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f1410cc:	afa900b8 */ 	sw	$t1,0xb8($sp)
/*  f1410d0:	ad140000 */ 	sw	$s4,0x0($t0)
/*  f1410d4:	8e0a0064 */ 	lw	$t2,0x64($s0)
/*  f1410d8:	10000005 */ 	beqz	$zero,.L0f1410f0
/*  f1410dc:	ad0a0004 */ 	sw	$t2,0x4($t0)
.L0f1410e0:
/*  f1410e0:	afac00b8 */ 	sw	$t4,0xb8($sp)
/*  f1410e4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f1410e8:	ae340000 */ 	sw	$s4,0x0($s1)
/*  f1410ec:	ae220004 */ 	sw	$v0,0x4($s1)
.L0f1410f0:
/*  f1410f0:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f1410f4:	3c0fb100 */ 	lui	$t7,0xb100
/*  f1410f8:	35ef0032 */ 	ori	$t7,$t7,0x32
/*  f1410fc:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f141100:	afae00b8 */ 	sw	$t6,0xb8($sp)
/*  f141104:	24182010 */ 	addiu	$t8,$zero,0x2010
/*  f141108:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f14110c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f141110:	8e100078 */ 	lw	$s0,0x78($s0)
.L0f141114:
/*  f141114:	5600ff8e */ 	bnezl	$s0,.L0f140f50
/*  f141118:	8208006f */ 	lb	$t0,0x6f($s0)
/*  f14111c:	8fb900ac */ 	lw	$t9,0xac($sp)
.L0f141120:
/*  f141120:	8fa900c0 */ 	lw	$t1,0xc0($sp)
/*  f141124:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f141128:	17200006 */ 	bnez	$t9,.L0f141144
/*  f14112c:	3c18b600 */ 	lui	$t8,0xb600
/*  f141130:	93c80002 */ 	lbu	$t0,0x2($s8)
/*  f141134:	012a5804 */ 	sllv	$t3,$t2,$t1
/*  f141138:	01606027 */ 	nor	$t4,$t3,$zero
/*  f14113c:	010c6824 */ 	and	$t5,$t0,$t4
/*  f141140:	a3cd0002 */ 	sb	$t5,0x2($s8)
.L0f141144:
/*  f141144:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*  f141148:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f14114c:	3c0bba00 */ 	lui	$t3,0xba00
/*  f141150:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f141154:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f141158:	add90004 */ 	sw	$t9,0x4($t6)
/*  f14115c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f141160:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f141164:	356b0602 */ 	ori	$t3,$t3,0x602
/*  f141168:	24080040 */ 	addiu	$t0,$zero,0x40
/*  f14116c:	25490008 */ 	addiu	$t1,$t2,0x8
/*  f141170:	afa900b8 */ 	sw	$t1,0xb8($sp)
/*  f141174:	ad480004 */ 	sw	$t0,0x4($t2)
/*  f141178:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f14117c:	8fa200b8 */ 	lw	$v0,0xb8($sp)
.L0f141180:
/*  f141180:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f141184:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f141188:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f14118c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f141190:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f141194:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f141198:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f14119c:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f1411a0:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f1411a4:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f1411a8:	03e00008 */ 	jr	$ra
/*  f1411ac:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func0f1411b0
/*  f1411b0:	000430c0 */ 	sll	$a2,$a0,0x3
/*  f1411b4:	00c43021 */ 	addu	$a2,$a2,$a0
/*  f1411b8:	3c0e800a */ 	lui	$t6,%hi(g_Rooms)
/*  f1411bc:	8dce4928 */ 	lw	$t6,%lo(g_Rooms)($t6)
/*  f1411c0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1411c4:	00c43023 */ 	subu	$a2,$a2,$a0
/*  f1411c8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1411cc:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1411d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1411d4:	01c61821 */ 	addu	$v1,$t6,$a2
/*  f1411d8:	8c6f0084 */ 	lw	$t7,0x84($v1)
/*  f1411dc:	51e0000b */ 	beqzl	$t7,.L0f14120c
/*  f1411e0:	8c790088 */ 	lw	$t9,0x88($v1)
/*  f1411e4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1411e8:	0fc5022a */ 	jal	func0f1408a8
/*  f1411ec:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f1411f0:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f1411f4:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f1411f8:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f1411fc:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f141200:	00402825 */ 	or	$a1,$v0,$zero
/*  f141204:	03061821 */ 	addu	$v1,$t8,$a2
/*  f141208:	8c790088 */ 	lw	$t9,0x88($v1)
.L0f14120c:
/*  f14120c:	53200005 */ 	beqzl	$t9,.L0f141224
/*  f141210:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f141214:	0fc502df */ 	jal	func0f140b7c
/*  f141218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14121c:	00402825 */ 	or	$a1,$v0,$zero
/*  f141220:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f141224:
/*  f141224:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f141228:	00a01025 */ 	or	$v0,$a1,$zero
/*  f14122c:	03e00008 */ 	jr	$ra
/*  f141230:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f141234
/*  f141234:	3c04800a */ 	lui	$a0,%hi(var8009cc44)
/*  f141238:	8c84cc44 */ 	lw	$a0,%lo(var8009cc44)($a0)
/*  f14123c:	3c03800a */ 	lui	$v1,%hi(var800a41b0)
/*  f141240:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f141244:	8c6341b0 */ 	lw	$v1,%lo(var800a41b0)($v1)
/*  f141248:	188000d2 */ 	blez	$a0,.L0f141594
/*  f14124c:	00001025 */ 	or	$v0,$zero,$zero
/*  f141250:	3c0d800a */ 	lui	$t5,%hi(g_Rooms)
/*  f141254:	25ad4928 */ 	addiu	$t5,$t5,%lo(g_Rooms)
/*  f141258:	c7ac0004 */ 	lwc1	$f12,0x4($sp)
/*  f14125c:	c7a20008 */ 	lwc1	$f2,0x8($sp)
/*  f141260:	c7a0000c */ 	lwc1	$f0,0xc($sp)
/*  f141264:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f141268:	240b008c */ 	addiu	$t3,$zero,0x8c
/*  f14126c:	240affff */ 	addiu	$t2,$zero,-1
.L0f141270:
/*  f141270:	84650068 */ 	lh	$a1,0x68($v1)
/*  f141274:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f141278:	58a000c1 */ 	blezl	$a1,.L0f141580
/*  f14127c:	0044082a */ 	slt	$at,$v0,$a0
/*  f141280:	8c670060 */ 	lw	$a3,0x60($v1)
/*  f141284:	01403025 */ 	or	$a2,$t2,$zero
/*  f141288:	10e00024 */ 	beqz	$a3,.L0f14131c
/*  f14128c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141290:	8ce80018 */ 	lw	$t0,0x18($a3)
/*  f141294:	00e02825 */ 	or	$a1,$a3,$zero
/*  f141298:	51000006 */ 	beqzl	$t0,.L0f1412b4
/*  f14129c:	84ae0028 */ 	lh	$t6,0x28($a1)
/*  f1412a0:	01002825 */ 	or	$a1,$t0,$zero
.L0f1412a4:
/*  f1412a4:	8d080018 */ 	lw	$t0,0x18($t0)
/*  f1412a8:	5500fffe */ 	bnezl	$t0,.L0f1412a4
/*  f1412ac:	01002825 */ 	or	$a1,$t0,$zero
/*  f1412b0:	84ae0028 */ 	lh	$t6,0x28($a1)
.L0f1412b4:
/*  f1412b4:	00a04025 */ 	or	$t0,$a1,$zero
/*  f1412b8:	114e0027 */ 	beq	$t2,$t6,.L0f141358
/*  f1412bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1412c0:	8da70000 */ 	lw	$a3,0x0($t5)
/*  f1412c4:	84a90028 */ 	lh	$t1,0x28($a1)
.L0f1412c8:
/*  f1412c8:	012b0019 */ 	multu	$t1,$t3
/*  f1412cc:	00007812 */ 	mflo	$t7
/*  f1412d0:	00efc021 */ 	addu	$t8,$a3,$t7
/*  f1412d4:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f1412d8:	332e1000 */ 	andi	$t6,$t9,0x1000
/*  f1412dc:	51c0000a */ 	beqzl	$t6,.L0f141308
/*  f1412e0:	8509002a */ 	lh	$t1,0x2a($t0)
/*  f1412e4:	012b0019 */ 	multu	$t1,$t3
/*  f1412e8:	01203025 */ 	or	$a2,$t1,$zero
/*  f1412ec:	00007812 */ 	mflo	$t7
/*  f1412f0:	00ef4021 */ 	addu	$t0,$a3,$t7
/*  f1412f4:	c5000074 */ 	lwc1	$f0,0x74($t0)
/*  f1412f8:	c5020078 */ 	lwc1	$f2,0x78($t0)
/*  f1412fc:	10000016 */ 	beqz	$zero,.L0f141358
/*  f141300:	c50c007c */ 	lwc1	$f12,0x7c($t0)
/*  f141304:	8509002a */ 	lh	$t1,0x2a($t0)
.L0f141308:
/*  f141308:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f14130c:	1549ffee */ 	bne	$t2,$t1,.L0f1412c8
/*  f141310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141314:	10000010 */ 	beqz	$zero,.L0f141358
/*  f141318:	00000000 */ 	sll	$zero,$zero,0x0
.L0f14131c:
/*  f14131c:	00ab0019 */ 	multu	$a1,$t3
/*  f141320:	8da70000 */ 	lw	$a3,0x0($t5)
/*  f141324:	0000c012 */ 	mflo	$t8
/*  f141328:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f14132c:	972e0000 */ 	lhu	$t6,0x0($t9)
/*  f141330:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f141334:	11e00008 */ 	beqz	$t7,.L0f141358
/*  f141338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14133c:	00ab0019 */ 	multu	$a1,$t3
/*  f141340:	00a03025 */ 	or	$a2,$a1,$zero
/*  f141344:	0000c012 */ 	mflo	$t8
/*  f141348:	00f84021 */ 	addu	$t0,$a3,$t8
/*  f14134c:	c5000074 */ 	lwc1	$f0,0x74($t0)
/*  f141350:	c5020078 */ 	lwc1	$f2,0x78($t0)
/*  f141354:	c50c007c */ 	lwc1	$f12,0x7c($t0)
.L0f141358:
/*  f141358:	18c00088 */ 	blez	$a2,.L0f14157c
/*  f14135c:	00004825 */ 	or	$t1,$zero,$zero
/*  f141360:	00602025 */ 	or	$a0,$v1,$zero
.L0f141364:
/*  f141364:	90990030 */ 	lbu	$t9,0x30($a0)
/*  f141368:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f14136c:	3c014f80 */ 	lui	$at,0x4f80
/*  f141370:	44992000 */ 	mtc1	$t9,$f4
/*  f141374:	07210004 */ 	bgez	$t9,.L0f141388
/*  f141378:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14137c:	44814000 */ 	mtc1	$at,$f8
/*  f141380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141384:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f141388:
/*  f141388:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f14138c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f141390:	3c014f00 */ 	lui	$at,0x4f00
/*  f141394:	444ef800 */ 	cfc1	$t6,$31
/*  f141398:	44cff800 */ 	ctc1	$t7,$31
/*  f14139c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1413a0:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f1413a4:	444ff800 */ 	cfc1	$t7,$31
/*  f1413a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1413ac:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1413b0:	51e00013 */ 	beqzl	$t7,.L0f141400
/*  f1413b4:	440f8000 */ 	mfc1	$t7,$f16
/*  f1413b8:	44818000 */ 	mtc1	$at,$f16
/*  f1413bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1413c0:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f1413c4:	44cff800 */ 	ctc1	$t7,$31
/*  f1413c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1413cc:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f1413d0:	444ff800 */ 	cfc1	$t7,$31
/*  f1413d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1413d8:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1413dc:	15e00005 */ 	bnez	$t7,.L0f1413f4
/*  f1413e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1413e4:	440f8000 */ 	mfc1	$t7,$f16
/*  f1413e8:	3c018000 */ 	lui	$at,0x8000
/*  f1413ec:	10000007 */ 	beqz	$zero,.L0f14140c
/*  f1413f0:	01e17825 */ 	or	$t7,$t7,$at
.L0f1413f4:
/*  f1413f4:	10000005 */ 	beqz	$zero,.L0f14140c
/*  f1413f8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1413fc:	440f8000 */ 	mfc1	$t7,$f16
.L0f141400:
/*  f141400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141404:	05e0fffb */ 	bltz	$t7,.L0f1413f4
/*  f141408:	00000000 */ 	sll	$zero,$zero,0x0
.L0f14140c:
/*  f14140c:	90980031 */ 	lbu	$t8,0x31($a0)
/*  f141410:	44cef800 */ 	ctc1	$t6,$31
/*  f141414:	a08f0040 */ 	sb	$t7,0x40($a0)
/*  f141418:	44989000 */ 	mtc1	$t8,$f18
/*  f14141c:	3c014f80 */ 	lui	$at,0x4f80
/*  f141420:	07010004 */ 	bgez	$t8,.L0f141434
/*  f141424:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f141428:	44814000 */ 	mtc1	$at,$f8
/*  f14142c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141430:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f141434:
/*  f141434:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f141438:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f14143c:	3c014f00 */ 	lui	$at,0x4f00
/*  f141440:	4459f800 */ 	cfc1	$t9,$31
/*  f141444:	44cef800 */ 	ctc1	$t6,$31
/*  f141448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14144c:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f141450:	444ef800 */ 	cfc1	$t6,$31
/*  f141454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141458:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f14145c:	51c00013 */ 	beqzl	$t6,.L0f1414ac
/*  f141460:	440e5000 */ 	mfc1	$t6,$f10
/*  f141464:	44815000 */ 	mtc1	$at,$f10
/*  f141468:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f14146c:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f141470:	44cef800 */ 	ctc1	$t6,$31
/*  f141474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141478:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f14147c:	444ef800 */ 	cfc1	$t6,$31
/*  f141480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141484:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f141488:	15c00005 */ 	bnez	$t6,.L0f1414a0
/*  f14148c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141490:	440e5000 */ 	mfc1	$t6,$f10
/*  f141494:	3c018000 */ 	lui	$at,0x8000
/*  f141498:	10000007 */ 	beqz	$zero,.L0f1414b8
/*  f14149c:	01c17025 */ 	or	$t6,$t6,$at
.L0f1414a0:
/*  f1414a0:	10000005 */ 	beqz	$zero,.L0f1414b8
/*  f1414a4:	240effff */ 	addiu	$t6,$zero,-1
/*  f1414a8:	440e5000 */ 	mfc1	$t6,$f10
.L0f1414ac:
/*  f1414ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1414b0:	05c0fffb */ 	bltz	$t6,.L0f1414a0
/*  f1414b4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1414b8:
/*  f1414b8:	908f0032 */ 	lbu	$t7,0x32($a0)
/*  f1414bc:	44d9f800 */ 	ctc1	$t9,$31
/*  f1414c0:	a08e0041 */ 	sb	$t6,0x41($a0)
/*  f1414c4:	448f8000 */ 	mtc1	$t7,$f16
/*  f1414c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1414cc:	05e10004 */ 	bgez	$t7,.L0f1414e0
/*  f1414d0:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1414d4:	44814000 */ 	mtc1	$at,$f8
/*  f1414d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1414dc:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f1414e0:
/*  f1414e0:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f1414e4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1414e8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1414ec:	4458f800 */ 	cfc1	$t8,$31
/*  f1414f0:	44d9f800 */ 	ctc1	$t9,$31
/*  f1414f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1414f8:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f1414fc:	4459f800 */ 	cfc1	$t9,$31
/*  f141500:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141504:	33390078 */ 	andi	$t9,$t9,0x78
/*  f141508:	53200013 */ 	beqzl	$t9,.L0f141558
/*  f14150c:	44193000 */ 	mfc1	$t9,$f6
/*  f141510:	44813000 */ 	mtc1	$at,$f6
/*  f141514:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f141518:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f14151c:	44d9f800 */ 	ctc1	$t9,$31
/*  f141520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141524:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f141528:	4459f800 */ 	cfc1	$t9,$31
/*  f14152c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141530:	33390078 */ 	andi	$t9,$t9,0x78
/*  f141534:	17200005 */ 	bnez	$t9,.L0f14154c
/*  f141538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14153c:	44193000 */ 	mfc1	$t9,$f6
/*  f141540:	3c018000 */ 	lui	$at,0x8000
/*  f141544:	10000007 */ 	beqz	$zero,.L0f141564
/*  f141548:	0321c825 */ 	or	$t9,$t9,$at
.L0f14154c:
/*  f14154c:	10000005 */ 	beqz	$zero,.L0f141564
/*  f141550:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f141554:	44193000 */ 	mfc1	$t9,$f6
.L0f141558:
/*  f141558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14155c:	0720fffb */ 	bltz	$t9,.L0f14154c
/*  f141560:	00000000 */ 	sll	$zero,$zero,0x0
.L0f141564:
/*  f141564:	44d8f800 */ 	ctc1	$t8,$31
/*  f141568:	24840004 */ 	addiu	$a0,$a0,4
/*  f14156c:	152cff7d */ 	bne	$t1,$t4,.L0f141364
/*  f141570:	a099003e */ 	sb	$t9,0x3e($a0)
/*  f141574:	3c04800a */ 	lui	$a0,%hi(var8009cc44)
/*  f141578:	8c84cc44 */ 	lw	$a0,%lo(var8009cc44)($a0)
.L0f14157c:
/*  f14157c:	0044082a */ 	slt	$at,$v0,$a0
.L0f141580:
/*  f141580:	1420ff3b */ 	bnez	$at,.L0f141270
/*  f141584:	2463007c */ 	addiu	$v1,$v1,124
/*  f141588:	e7ac0004 */ 	swc1	$f12,0x4($sp)
/*  f14158c:	e7a20008 */ 	swc1	$f2,0x8($sp)
/*  f141590:	e7a0000c */ 	swc1	$f0,0xc($sp)
.L0f141594:
/*  f141594:	03e00008 */ 	jr	$ra
/*  f141598:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f14159c
/*  f14159c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1415a0:	3c03800a */ 	lui	$v1,%hi(var8009cc44)
/*  f1415a4:	8c63cc44 */ 	lw	$v1,%lo(var8009cc44)($v1)
/*  f1415a8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1415ac:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1415b0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1415b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1415b8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1415bc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1415c0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1415c4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1415c8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1415cc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1415d0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1415d4:	1860003f */ 	blez	$v1,.L0f1416d4
/*  f1415d8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1415dc:	3c168008 */ 	lui	$s6,%hi(var8007f75c)
/*  f1415e0:	3c14800a */ 	lui	$s4,%hi(var800a41b0)
/*  f1415e4:	269441b0 */ 	addiu	$s4,$s4,%lo(var800a41b0)
/*  f1415e8:	26d6f75c */ 	addiu	$s6,$s6,%lo(var8007f75c)
/*  f1415ec:	00009025 */ 	or	$s2,$zero,$zero
/*  f1415f0:	241e0064 */ 	addiu	$s8,$zero,0x64
/*  f1415f4:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f1415f8:	24150003 */ 	addiu	$s5,$zero,0x3
.L0f1415fc:
/*  f1415fc:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f141600:	024e8021 */ 	addu	$s0,$s2,$t6
/*  f141604:	8e02005c */ 	lw	$v0,0x5c($s0)
/*  f141608:	5040002f */ 	beqzl	$v0,.L0f1416c8
/*  f14160c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f141610:	860f0068 */ 	lh	$t7,0x68($s0)
/*  f141614:	59e0002c */ 	blezl	$t7,.L0f1416c8
/*  f141618:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14161c:	5662002a */ 	bnel	$s3,$v0,.L0f1416c8
/*  f141620:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f141624:	9202006a */ 	lbu	$v0,0x6a($s0)
/*  f141628:	00570019 */ 	multu	$v0,$s7
/*  f14162c:	2841000c */ 	slti	$at,$v0,0xc
/*  f141630:	0000c012 */ 	mflo	$t8
/*  f141634:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f141638:	93280008 */ 	lbu	$t0,0x8($t9)
/*  f14163c:	56a80022 */ 	bnel	$s5,$t0,.L0f1416c8
/*  f141640:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f141644:	14200003 */ 	bnez	$at,.L0f141654
/*  f141648:	2841000d */ 	slti	$at,$v0,0xd
/*  f14164c:	5420000d */ 	bnezl	$at,.L0f141684
/*  f141650:	02002025 */ 	or	$a0,$s0,$zero
.L0f141654:
/*  f141654:	0c004b70 */ 	jal	random
/*  f141658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14165c:	005e001b */ 	divu	$zero,$v0,$s8
/*  f141660:	00004810 */ 	mfhi	$t1
/*  f141664:	2d210023 */ 	sltiu	$at,$t1,0x23
/*  f141668:	17c00002 */ 	bnez	$s8,.L0f141674
/*  f14166c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141670:	0007000d */ 	break	0x7
.L0f141674:
/*  f141674:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0xc)
/*  f141678:	10200007 */ 	beqz	$at,.L0f141698
/*  f14167c:	3c03800a */ 	lui	$v1,%hi(var8009cc44)
/*  f141680:	02002025 */ 	or	$a0,$s0,$zero
.L0f141684:
/*  f141684:	0fc4f990 */ 	jal	func0f13e640
/*  f141688:	24050078 */ 	addiu	$a1,$zero,0x78
/*  f14168c:	3c03800a */ 	lui	$v1,%hi(var8009cc44)
/*  f141690:	1000000c */ 	beqz	$zero,.L0f1416c4
/*  f141694:	8c63cc44 */ 	lw	$v1,%lo(var8009cc44)($v1)
.L0f141698:
/*  f141698:	8e020070 */ 	lw	$v0,0x70($s0)
/*  f14169c:	8d4a9fcc */ 	lw	$t2,%lo(g_Vars+0xc)($t2)
/*  f1416a0:	3c010fff */ 	lui	$at,0xfff
/*  f1416a4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1416a8:	00026102 */ 	srl	$t4,$v0,0x4
/*  f1416ac:	01415824 */ 	and	$t3,$t2,$at
/*  f1416b0:	016c6826 */ 	xor	$t5,$t3,$t4
/*  f1416b4:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f1416b8:	01c27826 */ 	xor	$t7,$t6,$v0
/*  f1416bc:	ae0f0070 */ 	sw	$t7,0x70($s0)
/*  f1416c0:	8c63cc44 */ 	lw	$v1,%lo(var8009cc44)($v1)
.L0f1416c4:
/*  f1416c4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f1416c8:
/*  f1416c8:	0223082a */ 	slt	$at,$s1,$v1
/*  f1416cc:	1420ffcb */ 	bnez	$at,.L0f1415fc
/*  f1416d0:	2652007c */ 	addiu	$s2,$s2,0x7c
.L0f1416d4:
/*  f1416d4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1416d8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1416dc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1416e0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1416e4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1416e8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1416ec:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1416f0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1416f4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f1416f8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f1416fc:	03e00008 */ 	jr	$ra
/*  f141700:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f141704
/*  f141704:	3c08800a */ 	lui	$t0,%hi(var8009cc44)
/*  f141708:	8d08cc44 */ 	lw	$t0,%lo(var8009cc44)($t0)
/*  f14170c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f141710:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f141714:	3c070fff */ 	lui	$a3,0xfff
/*  f141718:	00808025 */ 	or	$s0,$a0,$zero
/*  f14171c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f141720:	34e7ffff */ 	ori	$a3,$a3,0xffff
/*  f141724:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f141728:	1900002b */ 	blez	$t0,.L0f1417d8
/*  f14172c:	00002825 */ 	or	$a1,$zero,$zero
/*  f141730:	3c06800a */ 	lui	$a2,%hi(var800a41b0)
/*  f141734:	3c0b8008 */ 	lui	$t3,%hi(var8007f75c)
/*  f141738:	256bf75c */ 	addiu	$t3,$t3,%lo(var8007f75c)
/*  f14173c:	8cc641b0 */ 	lw	$a2,%lo(var800a41b0)($a2)
/*  f141740:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f141744:	240a0003 */ 	addiu	$t2,$zero,0x3
.L0f141748:
/*  f141748:	8cc3005c */ 	lw	$v1,0x5c($a2)
/*  f14174c:	00c01025 */ 	or	$v0,$a2,$zero
/*  f141750:	5060001e */ 	beqzl	$v1,.L0f1417cc
/*  f141754:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f141758:	844e0068 */ 	lh	$t6,0x68($v0)
/*  f14175c:	59c0001b */ 	blezl	$t6,.L0f1417cc
/*  f141760:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f141764:	56030019 */ 	bnel	$s0,$v1,.L0f1417cc
/*  f141768:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14176c:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f141770:	000fce80 */ 	sll	$t9,$t7,0x1a
/*  f141774:	07220015 */ 	bltzl	$t9,.L0f1417cc
/*  f141778:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14177c:	9043006a */ 	lbu	$v1,0x6a($v0)
/*  f141780:	006c0019 */ 	multu	$v1,$t4
/*  f141784:	2861000c */ 	slti	$at,$v1,0xc
/*  f141788:	00006812 */ 	mflo	$t5
/*  f14178c:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f141790:	91cf0008 */ 	lbu	$t7,0x8($t6)
/*  f141794:	554f000d */ 	bnel	$t2,$t7,.L0f1417cc
/*  f141798:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f14179c:	1420000a */ 	bnez	$at,.L0f1417c8
/*  f1417a0:	2861000d */ 	slti	$at,$v1,0xd
/*  f1417a4:	50200009 */ 	beqzl	$at,.L0f1417cc
/*  f1417a8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1417ac:	8c430070 */ 	lw	$v1,0x70($v0)
/*  f1417b0:	0003c102 */ 	srl	$t8,$v1,0x4
/*  f1417b4:	0307082b */ 	sltu	$at,$t8,$a3
/*  f1417b8:	50200004 */ 	beqzl	$at,.L0f1417cc
/*  f1417bc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1417c0:	03003825 */ 	or	$a3,$t8,$zero
/*  f1417c4:	00a04825 */ 	or	$t1,$a1,$zero
.L0f1417c8:
/*  f1417c8:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f1417cc:
/*  f1417cc:	00a8082a */ 	slt	$at,$a1,$t0
/*  f1417d0:	1420ffdd */ 	bnez	$at,.L0f141748
/*  f1417d4:	24c6007c */ 	addiu	$a2,$a2,124
.L0f1417d8:
/*  f1417d8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1417dc:	11210008 */ 	beq	$t1,$at,.L0f141800
/*  f1417e0:	0009c940 */ 	sll	$t9,$t1,0x5
/*  f1417e4:	3c0d800a */ 	lui	$t5,%hi(var800a41b0)
/*  f1417e8:	8dad41b0 */ 	lw	$t5,%lo(var800a41b0)($t5)
/*  f1417ec:	0329c823 */ 	subu	$t9,$t9,$t1
/*  f1417f0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1417f4:	24050078 */ 	addiu	$a1,$zero,0x78
/*  f1417f8:	0fc4f990 */ 	jal	func0f13e640
/*  f1417fc:	032d2021 */ 	addu	$a0,$t9,$t5
.L0f141800:
/*  f141800:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f141804:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f141808:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f14180c:	03e00008 */ 	jr	$ra
/*  f141810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141814:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f141818:	03e00008 */ 	jr	$ra
/*  f14181c:	00801025 */ 	or	$v0,$a0,$zero
);
