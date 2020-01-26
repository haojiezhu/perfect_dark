#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_0f09f0.h"
#include "game/game_10ccd0.h"
#include "game/pad.h"
#include "game/game_128f30.h"
#include "game/game_129900.h"
#include "game/game_176d70.h"
#include "library/library_12dc0.h"

GLOBAL_ASM(
glabel padUnpack
/*  f115ab0:	3c0e800a */ 	lui	$t6,0x800a
/*  f115ab4:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f115ab8:	00047840 */ 	sll	$t7,$a0,0x1
/*  f115abc:	3c19800a */ 	lui	$t9,0x800a
/*  f115ac0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f115ac4:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f115ac8:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f115acc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f115ad0:	30e80040 */ 	andi	$t0,$a3,0x40
/*  f115ad4:	03221821 */ 	addu	$v1,$t9,$v0
/*  f115ad8:	11000005 */ 	beqz	$t0,.L0f115af0
/*  f115adc:	00602825 */ 	or	$a1,$v1,$zero
/*  f115ae0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f115ae4:	00095480 */ 	sll	$t2,$t1,0x12
/*  f115ae8:	000a5d83 */ 	sra	$t3,$t2,0x16
/*  f115aec:	accb0048 */ 	sw	$t3,0x48($a2)
.L0f115af0:
/*  f115af0:	30ec0100 */ 	andi	$t4,$a3,0x100
/*  f115af4:	11800004 */ 	beqz	$t4,.L0f115b08
/*  f115af8:	30f90002 */ 	andi	$t9,$a3,0x2
/*  f115afc:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f115b00:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f115b04:	a0ce0050 */ 	sb	$t6,0x50($a2)
.L0f115b08:
/*  f115b08:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115b0c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f115b10:	30ec0002 */ 	andi	$t4,$a3,0x2
/*  f115b14:	00027b82 */ 	srl	$t7,$v0,0xe
/*  f115b18:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f115b1c:	13000017 */ 	beqz	$t8,.L0f115b7c
/*  f115b20:	01e01025 */ 	or	$v0,$t7,$zero
/*  f115b24:	13200013 */ 	beqz	$t9,.L0f115b74
/*  f115b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b2c:	84680000 */ 	lh	$t0,0x0($v1)
/*  f115b30:	44882000 */ 	mtc1	$t0,$f4
/*  f115b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b38:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f115b3c:	e4c60000 */ 	swc1	$f6,0x0($a2)
/*  f115b40:	84690002 */ 	lh	$t1,0x2($v1)
/*  f115b44:	44894000 */ 	mtc1	$t1,$f8
/*  f115b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b4c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f115b50:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f115b54:	846a0004 */ 	lh	$t2,0x4($v1)
/*  f115b58:	448a2000 */ 	mtc1	$t2,$f4
/*  f115b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b60:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f115b64:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f115b68:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115b6c:	00025b82 */ 	srl	$t3,$v0,0xe
/*  f115b70:	01601025 */ 	or	$v0,$t3,$zero
.L0f115b74:
/*  f115b74:	1000000d */ 	beqz	$zero,.L0f115bac
/*  f115b78:	24630008 */ 	addiu	$v1,$v1,0x8
.L0f115b7c:
/*  f115b7c:	5180000b */ 	beqzl	$t4,.L0f115bac
/*  f115b80:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f115b84:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f115b88:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f115b8c:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f115b90:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f115b94:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f115b98:	e4c40008 */ 	swc1	$f4,0x8($a2)
/*  f115b9c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115ba0:	00026b82 */ 	srl	$t5,$v0,0xe
/*  f115ba4:	01a01025 */ 	or	$v0,$t5,$zero
/*  f115ba8:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115bac:
/*  f115bac:	304e000e */ 	andi	$t6,$v0,0xe
/*  f115bb0:	11c00049 */ 	beqz	$t6,.L0f115cd8
/*  f115bb4:	30e90018 */ 	andi	$t1,$a3,0x18
/*  f115bb8:	30ef0018 */ 	andi	$t7,$a3,0x18
/*  f115bbc:	11e00043 */ 	beqz	$t7,.L0f115ccc
/*  f115bc0:	30580002 */ 	andi	$t8,$v0,0x2
/*  f115bc4:	13000013 */ 	beqz	$t8,.L0f115c14
/*  f115bc8:	30490004 */ 	andi	$t1,$v0,0x4
/*  f115bcc:	30590010 */ 	andi	$t9,$v0,0x10
/*  f115bd0:	44800000 */ 	mtc1	$zero,$f0
/*  f115bd4:	13200005 */ 	beqz	$t9,.L0f115bec
/*  f115bd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f115bdc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115be0:	44813000 */ 	mtc1	$at,$f6
/*  f115be4:	10000004 */ 	beqz	$zero,.L0f115bf8
/*  f115be8:	e4c60018 */ 	swc1	$f6,0x18($a2)
.L0f115bec:
/*  f115bec:	44814000 */ 	mtc1	$at,$f8
/*  f115bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115bf4:	e4c80018 */ 	swc1	$f8,0x18($a2)
.L0f115bf8:
/*  f115bf8:	e4c0001c */ 	swc1	$f0,0x1c($a2)
/*  f115bfc:	e4c00020 */ 	swc1	$f0,0x20($a2)
/*  f115c00:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115c04:	44800000 */ 	mtc1	$zero,$f0
/*  f115c08:	00024382 */ 	srl	$t0,$v0,0xe
/*  f115c0c:	1000003f */ 	beqz	$zero,.L0f115d0c
/*  f115c10:	01001025 */ 	or	$v0,$t0,$zero
.L0f115c14:
/*  f115c14:	51200017 */ 	beqzl	$t1,.L0f115c74
/*  f115c18:	44800000 */ 	mtc1	$zero,$f0
/*  f115c1c:	44800000 */ 	mtc1	$zero,$f0
/*  f115c20:	3c013f80 */ 	lui	$at,0x3f80
/*  f115c24:	e4c00018 */ 	swc1	$f0,0x18($a2)
/*  f115c28:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f115c2c:	000a5b82 */ 	srl	$t3,$t2,0xe
/*  f115c30:	316c0010 */ 	andi	$t4,$t3,0x10
/*  f115c34:	51800006 */ 	beqzl	$t4,.L0f115c50
/*  f115c38:	44812000 */ 	mtc1	$at,$f4
/*  f115c3c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115c40:	44815000 */ 	mtc1	$at,$f10
/*  f115c44:	10000004 */ 	beqz	$zero,.L0f115c58
/*  f115c48:	e4ca001c */ 	swc1	$f10,0x1c($a2)
/*  f115c4c:	44812000 */ 	mtc1	$at,$f4
.L0f115c50:
/*  f115c50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115c54:	e4c4001c */ 	swc1	$f4,0x1c($a2)
.L0f115c58:
/*  f115c58:	e4c00020 */ 	swc1	$f0,0x20($a2)
/*  f115c5c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115c60:	44800000 */ 	mtc1	$zero,$f0
/*  f115c64:	00026b82 */ 	srl	$t5,$v0,0xe
/*  f115c68:	10000028 */ 	beqz	$zero,.L0f115d0c
/*  f115c6c:	01a01025 */ 	or	$v0,$t5,$zero
/*  f115c70:	44800000 */ 	mtc1	$zero,$f0
.L0f115c74:
/*  f115c74:	3c013f80 */ 	lui	$at,0x3f80
/*  f115c78:	e4c00018 */ 	swc1	$f0,0x18($a2)
/*  f115c7c:	e4c0001c */ 	swc1	$f0,0x1c($a2)
/*  f115c80:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f115c84:	000e7b82 */ 	srl	$t7,$t6,0xe
/*  f115c88:	31f80010 */ 	andi	$t8,$t7,0x10
/*  f115c8c:	5300000a */ 	beqzl	$t8,.L0f115cb8
/*  f115c90:	44814000 */ 	mtc1	$at,$f8
/*  f115c94:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115c98:	44813000 */ 	mtc1	$at,$f6
/*  f115c9c:	44800000 */ 	mtc1	$zero,$f0
/*  f115ca0:	e4c60020 */ 	swc1	$f6,0x20($a2)
/*  f115ca4:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115ca8:	0002cb82 */ 	srl	$t9,$v0,0xe
/*  f115cac:	10000017 */ 	beqz	$zero,.L0f115d0c
/*  f115cb0:	03201025 */ 	or	$v0,$t9,$zero
/*  f115cb4:	44814000 */ 	mtc1	$at,$f8
.L0f115cb8:
/*  f115cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115cbc:	e4c80020 */ 	swc1	$f8,0x20($a2)
/*  f115cc0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115cc4:	00024382 */ 	srl	$t0,$v0,0xe
/*  f115cc8:	01001025 */ 	or	$v0,$t0,$zero
.L0f115ccc:
/*  f115ccc:	44800000 */ 	mtc1	$zero,$f0
/*  f115cd0:	1000000f */ 	beqz	$zero,.L0f115d10
/*  f115cd4:	304b00e0 */ 	andi	$t3,$v0,0xe0
.L0f115cd8:
/*  f115cd8:	5120000b */ 	beqzl	$t1,.L0f115d08
/*  f115cdc:	44800000 */ 	mtc1	$zero,$f0
/*  f115ce0:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f115ce4:	e4ca0018 */ 	swc1	$f10,0x18($a2)
/*  f115ce8:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f115cec:	e4c4001c */ 	swc1	$f4,0x1c($a2)
/*  f115cf0:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f115cf4:	e4c60020 */ 	swc1	$f6,0x20($a2)
/*  f115cf8:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115cfc:	00025382 */ 	srl	$t2,$v0,0xe
/*  f115d00:	01401025 */ 	or	$v0,$t2,$zero
/*  f115d04:	44800000 */ 	mtc1	$zero,$f0
.L0f115d08:
/*  f115d08:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115d0c:
/*  f115d0c:	304b00e0 */ 	andi	$t3,$v0,0xe0
.L0f115d10:
/*  f115d10:	11600034 */ 	beqz	$t3,.L0f115de4
/*  f115d14:	30ec0014 */ 	andi	$t4,$a3,0x14
/*  f115d18:	30ec0014 */ 	andi	$t4,$a3,0x14
/*  f115d1c:	1180003a */ 	beqz	$t4,.L0f115e08
/*  f115d20:	304d0020 */ 	andi	$t5,$v0,0x20
/*  f115d24:	11a0000e */ 	beqz	$t5,.L0f115d60
/*  f115d28:	304f0040 */ 	andi	$t7,$v0,0x40
/*  f115d2c:	304e0100 */ 	andi	$t6,$v0,0x100
/*  f115d30:	11c00005 */ 	beqz	$t6,.L0f115d48
/*  f115d34:	3c013f80 */ 	lui	$at,0x3f80
/*  f115d38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115d3c:	44814000 */ 	mtc1	$at,$f8
/*  f115d40:	10000004 */ 	beqz	$zero,.L0f115d54
/*  f115d44:	e4c8000c */ 	swc1	$f8,0xc($a2)
.L0f115d48:
/*  f115d48:	44815000 */ 	mtc1	$at,$f10
/*  f115d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115d50:	e4ca000c */ 	swc1	$f10,0xc($a2)
.L0f115d54:
/*  f115d54:	e4c00010 */ 	swc1	$f0,0x10($a2)
/*  f115d58:	1000002b */ 	beqz	$zero,.L0f115e08
/*  f115d5c:	e4c00014 */ 	swc1	$f0,0x14($a2)
.L0f115d60:
/*  f115d60:	51e00012 */ 	beqzl	$t7,.L0f115dac
/*  f115d64:	e4c0000c */ 	swc1	$f0,0xc($a2)
/*  f115d68:	e4c0000c */ 	swc1	$f0,0xc($a2)
/*  f115d6c:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f115d70:	3c013f80 */ 	lui	$at,0x3f80
/*  f115d74:	0018cb82 */ 	srl	$t9,$t8,0xe
/*  f115d78:	33280100 */ 	andi	$t0,$t9,0x100
/*  f115d7c:	51000006 */ 	beqzl	$t0,.L0f115d98
/*  f115d80:	44813000 */ 	mtc1	$at,$f6
/*  f115d84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115d88:	44812000 */ 	mtc1	$at,$f4
/*  f115d8c:	10000004 */ 	beqz	$zero,.L0f115da0
/*  f115d90:	e4c40010 */ 	swc1	$f4,0x10($a2)
/*  f115d94:	44813000 */ 	mtc1	$at,$f6
.L0f115d98:
/*  f115d98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115d9c:	e4c60010 */ 	swc1	$f6,0x10($a2)
.L0f115da0:
/*  f115da0:	10000019 */ 	beqz	$zero,.L0f115e08
/*  f115da4:	e4c00014 */ 	swc1	$f0,0x14($a2)
/*  f115da8:	e4c0000c */ 	swc1	$f0,0xc($a2)
.L0f115dac:
/*  f115dac:	e4c00010 */ 	swc1	$f0,0x10($a2)
/*  f115db0:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f115db4:	3c013f80 */ 	lui	$at,0x3f80
/*  f115db8:	00095382 */ 	srl	$t2,$t1,0xe
/*  f115dbc:	314b0100 */ 	andi	$t3,$t2,0x100
/*  f115dc0:	51600006 */ 	beqzl	$t3,.L0f115ddc
/*  f115dc4:	44815000 */ 	mtc1	$at,$f10
/*  f115dc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115dcc:	44814000 */ 	mtc1	$at,$f8
/*  f115dd0:	1000000d */ 	beqz	$zero,.L0f115e08
/*  f115dd4:	e4c80014 */ 	swc1	$f8,0x14($a2)
/*  f115dd8:	44815000 */ 	mtc1	$at,$f10
.L0f115ddc:
/*  f115ddc:	1000000a */ 	beqz	$zero,.L0f115e08
/*  f115de0:	e4ca0014 */ 	swc1	$f10,0x14($a2)
.L0f115de4:
/*  f115de4:	51800008 */ 	beqzl	$t4,.L0f115e08
/*  f115de8:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f115dec:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f115df0:	e4c4000c */ 	swc1	$f4,0xc($a2)
/*  f115df4:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f115df8:	e4c60010 */ 	swc1	$f6,0x10($a2)
/*  f115dfc:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f115e00:	e4c80014 */ 	swc1	$f8,0x14($a2)
/*  f115e04:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115e08:
/*  f115e08:	30ed0010 */ 	andi	$t5,$a3,0x10
/*  f115e0c:	11a00014 */ 	beqz	$t5,.L0f115e60
/*  f115e10:	30e90080 */ 	andi	$t1,$a3,0x80
/*  f115e14:	c4c0001c */ 	lwc1	$f0,0x1c($a2)
/*  f115e18:	c4c20014 */ 	lwc1	$f2,0x14($a2)
/*  f115e1c:	c4cc0010 */ 	lwc1	$f12,0x10($a2)
/*  f115e20:	c4ce0020 */ 	lwc1	$f14,0x20($a2)
/*  f115e24:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f115e28:	c4d0000c */ 	lwc1	$f16,0xc($a2)
/*  f115e2c:	c4d20018 */ 	lwc1	$f18,0x18($a2)
/*  f115e30:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f115e34:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f115e38:	46107202 */ 	mul.s	$f8,$f14,$f16
/*  f115e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e40:	46121282 */ 	mul.s	$f10,$f2,$f18
/*  f115e44:	e4c60024 */ 	swc1	$f6,0x24($a2)
/*  f115e48:	460c9182 */ 	mul.s	$f6,$f18,$f12
/*  f115e4c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f115e50:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f115e54:	e4c40028 */ 	swc1	$f4,0x28($a2)
/*  f115e58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f115e5c:	e4ca002c */ 	swc1	$f10,0x2c($a2)
.L0f115e60:
/*  f115e60:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f115e64:	30f90020 */ 	andi	$t9,$a3,0x20
/*  f115e68:	30e80020 */ 	andi	$t0,$a3,0x20
/*  f115e6c:	000e7b82 */ 	srl	$t7,$t6,0xe
/*  f115e70:	31f80200 */ 	andi	$t8,$t7,0x200
/*  f115e74:	13000010 */ 	beqz	$t8,.L0f115eb8
/*  f115e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e7c:	13200019 */ 	beqz	$t9,.L0f115ee4
/*  f115e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e84:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f115e88:	e4c40030 */ 	swc1	$f4,0x30($a2)
/*  f115e8c:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f115e90:	e4c60034 */ 	swc1	$f6,0x34($a2)
/*  f115e94:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f115e98:	e4c80038 */ 	swc1	$f8,0x38($a2)
/*  f115e9c:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f115ea0:	e4ca003c */ 	swc1	$f10,0x3c($a2)
/*  f115ea4:	c4640010 */ 	lwc1	$f4,0x10($v1)
/*  f115ea8:	e4c40040 */ 	swc1	$f4,0x40($a2)
/*  f115eac:	c4660014 */ 	lwc1	$f6,0x14($v1)
/*  f115eb0:	1000000c */ 	beqz	$zero,.L0f115ee4
/*  f115eb4:	e4c60044 */ 	swc1	$f6,0x44($a2)
.L0f115eb8:
/*  f115eb8:	1100000a */ 	beqz	$t0,.L0f115ee4
/*  f115ebc:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f115ec0:	44810000 */ 	mtc1	$at,$f0
/*  f115ec4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f115ec8:	44811000 */ 	mtc1	$at,$f2
/*  f115ecc:	e4c00030 */ 	swc1	$f0,0x30($a2)
/*  f115ed0:	e4c00038 */ 	swc1	$f0,0x38($a2)
/*  f115ed4:	e4c00040 */ 	swc1	$f0,0x40($a2)
/*  f115ed8:	e4c20034 */ 	swc1	$f2,0x34($a2)
/*  f115edc:	e4c2003c */ 	swc1	$f2,0x3c($a2)
/*  f115ee0:	e4c20044 */ 	swc1	$f2,0x44($a2)
.L0f115ee4:
/*  f115ee4:	11200004 */ 	beqz	$t1,.L0f115ef8
/*  f115ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115eec:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f115ef0:	000a5b82 */ 	srl	$t3,$t2,0xe
/*  f115ef4:	accb004c */ 	sw	$t3,0x4c($a2)
.L0f115ef8:
/*  f115ef8:	03e00008 */ 	jr	$ra
/*  f115efc:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because the ROM moves `fields` from a1 to a3 then uses a1 for other
// purposes, while the below just keeps a1 where it is.
//void padUnpack(s32 padnum, u32 fields, struct pad *pad)
//{
//	u32 *ibuffer = (u32 *)&g_StageSetup.padfiledata[g_PadOffsets[padnum]];
//	f32 *fbuffer = (f32 *)ibuffer;
//
//	// flags, room and liftnum
//	// ffffffff ffffffff ffrrrrrr rrrrllll
//
//	if (fields & PADFIELD_ROOM) {
//		pad->room = (s32)(*ibuffer << 18) >> 22;
//	}
//
//	if (fields & PADFIELD_LIFT) {
//		pad->liftnum = *ibuffer & 0x0000000f;
//	}
//
//	fbuffer++;
//
//	if ((*ibuffer >> 14) & PADFLAG_INTPOS) {
//		if (fields & PADFIELD_POS) {
//			s16 *sbuffer = (s16 *)fbuffer;
//			pad->pos.x = sbuffer[0];
//			pad->pos.y = sbuffer[1];
//			pad->pos.z = sbuffer[2];
//		}
//		fbuffer += 2;
//	} else {
//		if (fields & PADFIELD_POS) {
//			pad->pos.x = fbuffer[0];
//			pad->pos.y = fbuffer[1];
//			pad->pos.z = fbuffer[2];
//		}
//		fbuffer += 3;
//	}
//
//	if ((*ibuffer >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) {
//		if (fields & (PADFIELD_UP | PADFIELD_NORMAL)) {
//			if ((*ibuffer >> 14) & PADFLAG_UPALIGNTOX) {
//				pad->up.x = ((*ibuffer >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
//				pad->up.y = 0;
//				pad->up.z = 0;
//			} else if ((*ibuffer >> 14) & PADFLAG_UPALIGNTOY) {
//				pad->up.x = 0;
//				pad->up.y = ((*ibuffer >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
//				pad->up.z = 0;
//			} else {
//				pad->up.x = 0;
//				pad->up.y = 0;
//				pad->up.z = ((*ibuffer >> 14) & PADFLAG_UPALIGNINVERT) ? -1 : 1;
//			}
//		}
//	} else {
//		if (fields & (PADFIELD_UP | PADFIELD_NORMAL)) {
//			pad->up.x = fbuffer[0];
//			pad->up.y = fbuffer[1];
//			pad->up.z = fbuffer[2];
//		}
//		fbuffer += 3;
//	}
//
//	if ((*ibuffer >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) {
//		if (fields & (PADFIELD_LOOK | PADFIELD_NORMAL)) {
//			if ((*ibuffer >> 14) & PADFLAG_LOOKALIGNTOX) {
//				pad->look.x = ((*ibuffer >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
//				pad->look.y = 0;
//				pad->look.z = 0;
//			} else if ((*ibuffer >> 14) & PADFLAG_LOOKALIGNTOY) {
//				pad->look.x = 0;
//				pad->look.y = ((*ibuffer >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
//				pad->look.z = 0;
//			} else {
//				pad->look.x = 0;
//				pad->look.y = 0;
//				pad->look.z = ((*ibuffer >> 14) & PADFLAG_LOOKALIGNINVERT) ? -1 : 1;
//			}
//		}
//	} else {
//		if (fields & (PADFIELD_LOOK | PADFIELD_NORMAL)) {
//			pad->look.x = fbuffer[0];
//			pad->look.y = fbuffer[1];
//			pad->look.z = fbuffer[2];
//		}
//		fbuffer = fbuffer + 3;
//	}
//
//	if (fields & PADFIELD_NORMAL) {
//		pad->normal.x = pad->up.y * pad->look.z - pad->look.y * pad->up.z;
//		pad->normal.y = pad->up.z * pad->look.x - pad->look.z * pad->up.x;
//		pad->normal.z = pad->up.x * pad->look.y - pad->look.x * pad->up.y;
//	}
//
//	if ((*ibuffer >> 14) & PADFLAG_HASBBOXDATA) {
//		if (fields & PADFIELD_BBOX) {
//			pad->bbox.xmin = fbuffer[0];
//			pad->bbox.xmax = fbuffer[1];
//			pad->bbox.ymin = fbuffer[2];
//			pad->bbox.ymax = fbuffer[3];
//			pad->bbox.zmin = fbuffer[4];
//			pad->bbox.zmax = fbuffer[5];
//		}
//	} else {
//		if (fields & PADFIELD_BBOX) {
//			pad->bbox.xmin = -100;
//			pad->bbox.ymin = -100;
//			pad->bbox.zmin = -100;
//			pad->bbox.xmax = 100;
//			pad->bbox.ymax = 100;
//			pad->bbox.zmax = 100;
//		}
//	}
//
//	if (fields & PADFIELD_FLAGS) {
//		pad->flags = (*ibuffer >> 14);
//	}
//}

bool padHasBboxData(s32 padnum)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	return ((*header >> 14) & PADFLAG_HASBBOXDATA) != 0;
}

GLOBAL_ASM(
glabel padGetCentre
/*  f115f34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f115f38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f115f3c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f115f40:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f115f44:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f115f48:	0fc456ac */ 	jal	padUnpack
/*  f115f4c:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f115f50:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f115f54:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f115f58:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f115f5c:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f115f60:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f115f64:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f115f68:	3c013f00 */ 	lui	$at,0x3f00
/*  f115f6c:	44810000 */ 	mtc1	$at,$f0
/*  f115f70:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f115f74:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f115f78:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f115f7c:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f115f80:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f115f84:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f115f88:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f115f8c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f115f90:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f115f94:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f115f98:	46088282 */ 	mul.s	$f10,$f16,$f8
/*  f115f9c:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*  f115fa0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fa4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f115fa8:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f115fac:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f115fb0:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*  f115fb4:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f115fb8:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f115fbc:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f115fc0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fc4:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f115fc8:	46062402 */ 	mul.s	$f16,$f4,$f6
/*  f115fcc:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f115fd0:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f115fd4:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f115fd8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f115fdc:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f115fe0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fe4:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f115fe8:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f115fec:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f115ff0:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f115ff4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f115ff8:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f115ffc:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f116000:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f116004:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f116008:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f11600c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f116010:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f116014:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f116018:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f11601c:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f116020:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f116024:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f116028:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f11602c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f116030:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f116034:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f116038:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f11603c:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f116040:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f116044:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f116048:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f11604c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f116050:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f116054:	e4ea0008 */ 	swc1	$f10,0x8($a3)
/*  f116058:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11605c:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f116060:	03e00008 */ 	jr	$ra
/*  f116064:	00000000 */ 	sll	$zero,$zero,0x0
);

//void padGetCentre(s32 padnum, struct coord *coord)
//{
//	struct pad pad;
//
//	padUnpack(padnum, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX, &pad);
//
//	coord->x = pad.pos.x + (
//			(pad.bbox.xmin + pad.bbox.xmax) * pad.normal.x +
//			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.x +
//			pad.look.x * (pad.bbox.zmin + pad.bbox.zmax)) * 0.5f;
//	coord->y = (
//			(pad.bbox.xmax + pad.bbox.xmin) * pad.normal.y +
//			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.y +
//			pad.look.y * (pad.bbox.zmin + pad.bbox.zmax)) * 0.5f + pad.pos.y;
//	coord->z = (
//			(pad.bbox.xmin + pad.bbox.xmax) * pad.normal.z +
//			(pad.bbox.ymin + pad.bbox.ymax) * pad.up.z +
//			pad.look.z * (pad.bbox.zmin + pad.bbox.zmax)) * 0.5f + pad.pos.z;
//}

GLOBAL_ASM(
glabel func0f116068
/*  f116068:	3c0e800a */ 	lui	$t6,0x800a
/*  f11606c:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f116070:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f116074:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116078:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11607c:	3c19800a */ 	lui	$t9,0x800a
/*  f116080:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f116084:	97060000 */ 	lhu	$a2,0x0($t8)
/*  f116088:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f11608c:	03261021 */ 	addu	$v0,$t9,$a2
/*  f116090:	00403825 */ 	or	$a3,$v0,$zero
/*  f116094:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f116098:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f11609c:	00051b82 */ 	srl	$v1,$a1,0xe
/*  f1160a0:	30680001 */ 	andi	$t0,$v1,0x1
/*  f1160a4:	11000003 */ 	beqz	$t0,.L0f1160b4
/*  f1160a8:	3069000e */ 	andi	$t1,$v1,0xe
/*  f1160ac:	10000002 */ 	beqz	$zero,.L0f1160b8
/*  f1160b0:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f1160b4:
/*  f1160b4:	2442000c */ 	addiu	$v0,$v0,0xc
.L0f1160b8:
/*  f1160b8:	5520001d */ 	bnezl	$t1,.L0f116130
/*  f1160bc:	306a00e0 */ 	andi	$t2,$v1,0xe0
/*  f1160c0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f1160c4:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f1160c8:	44802000 */ 	mtc1	$zero,$f4
/*  f1160cc:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f1160d0:	e4440004 */ 	swc1	$f4,0x4($v0)
/*  f1160d4:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f1160d8:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1160dc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1160e0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f1160e4:	0c012974 */ 	jal	sqrtf
/*  f1160e8:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f1160ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f1160f0:	44815000 */ 	mtc1	$at,$f10
/*  f1160f4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f1160f8:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f1160fc:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f116100:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f116104:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f116108:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f11610c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f116110:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f116114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116118:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f11611c:	e4920000 */ 	swc1	$f18,0x0($a0)
/*  f116120:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f116124:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f116128:	00051b82 */ 	srl	$v1,$a1,0xe
/*  f11612c:	306a00e0 */ 	andi	$t2,$v1,0xe0
.L0f116130:
/*  f116130:	1140000d */ 	beqz	$t2,.L0f116168
/*  f116134:	2401fe1f */ 	addiu	$at,$zero,-481
/*  f116138:	00615824 */ 	and	$t3,$v1,$at
/*  f11613c:	01636026 */ 	xor	$t4,$t3,$v1
/*  f116140:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f116144:	01a57026 */ 	xor	$t6,$t5,$a1
/*  f116148:	000e1b82 */ 	srl	$v1,$t6,0xe
/*  f11614c:	346f0040 */ 	ori	$t7,$v1,0x40
/*  f116150:	01e3c026 */ 	xor	$t8,$t7,$v1
/*  f116154:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f116158:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f11615c:	032e4026 */ 	xor	$t0,$t9,$t6
/*  f116160:	10000007 */ 	beqz	$zero,.L0f116180
/*  f116164:	ace80000 */ 	sw	$t0,0x0($a3)
.L0f116168:
/*  f116168:	44800000 */ 	mtc1	$zero,$f0
/*  f11616c:	3c013f80 */ 	lui	$at,0x3f80
/*  f116170:	44814000 */ 	mtc1	$at,$f8
/*  f116174:	e4400000 */ 	swc1	$f0,0x0($v0)
/*  f116178:	e4400008 */ 	swc1	$f0,0x8($v0)
/*  f11617c:	e4480004 */ 	swc1	$f8,0x4($v0)
.L0f116180:
/*  f116180:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116184:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f116188:	03e00008 */ 	jr	$ra
/*  f11618c:	00000000 */ 	sll	$zero,$zero,0x0
);

void padCopyBboxFromPad(s32 padnum, struct pad *src)
{
	u32 offset = g_PadOffsets[padnum];
	f32 *fbuffer = (f32 *)&g_StageSetup.padfiledata[offset];
	u32 *header = (u32 *)fbuffer;

	if ((*header >> 14) & PADFLAG_HASBBOXDATA) {
		fbuffer++;

		if ((*header >> 14) & PADFLAG_INTPOS) {
			fbuffer += 2;
		} else {
			fbuffer += 3;
		}

		if (((*header >> 14) & (PADFLAG_UPALIGNTOX | PADFLAG_UPALIGNTOY | PADFLAG_UPALIGNTOZ)) == 0) {
			fbuffer += 3;
		}

		if (((*header >> 14) & (PADFLAG_LOOKALIGNTOX | PADFLAG_LOOKALIGNTOY | PADFLAG_LOOKALIGNTOZ)) == 0) {
			fbuffer += 3;
		}

		fbuffer[0] = src->bbox.xmin;
		fbuffer[1] = src->bbox.xmax;
		fbuffer[2] = src->bbox.ymin;
		fbuffer[3] = src->bbox.ymax;
		fbuffer[4] = src->bbox.zmin;
		fbuffer[5] = src->bbox.zmax;
	}
}

void padSetFlag(s32 padnum, u32 flag)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	*header = *header ^ ((*header >> 14) ^ ((*header >> 14) | flag)) << 14;
}

void padUnsetFlag(s32 padnum, u32 flag)
{
	u32 offset = g_PadOffsets[padnum];
	u32 *header = (u32 *)&g_StageSetup.padfiledata[offset];

	*header = *header ^ ((*header >> 14) ^ ((*header >> 14) & ~flag)) << 14;
}

bool func0f1162c4(s32 padnum, s32 arg1)
{
	return padnum;
}

GLOBAL_ASM(
glabel func0f1162d0
/*  f1162d0:	3c0e800a */ 	lui	$t6,0x800a
/*  f1162d4:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1162d8:	03e00008 */ 	jr	$ra
/*  f1162dc:	8dc20004 */ 	lw	$v0,0x4($t6)
);

GLOBAL_ASM(
glabel func0f1162e0
/*  f1162e0:	3c0e800a */ 	lui	$t6,0x800a
/*  f1162e4:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1162e8:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1162ec:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f1162f0:	008f082a */ 	slt	$at,$a0,$t7
/*  f1162f4:	10200008 */ 	beqz	$at,.L0f116318
/*  f1162f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1162fc:	04800006 */ 	bltz	$a0,.L0f116318
/*  f116300:	3c03800a */ 	lui	$v1,0x800a
/*  f116304:	8c63d038 */ 	lw	$v1,-0x2fc8($v1)
/*  f116308:	3c09800a */ 	lui	$t1,%hi(var800a2360)
/*  f11630c:	25292360 */ 	addiu	$t1,$t1,%lo(var800a2360)
/*  f116310:	14600003 */ 	bnez	$v1,.L0f116320
/*  f116314:	309800ff */ 	andi	$t8,$a0,0xff
.L0f116318:
/*  f116318:	03e00008 */ 	jr	$ra
/*  f11631c:	00001025 */ 	or	$v0,$zero,$zero
.L0f116320:
/*  f116320:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f116324:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f116328:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11632c:	00792821 */ 	addu	$a1,$v1,$t9
/*  f116330:	24aa000c */ 	addiu	$t2,$a1,0xc
/*  f116334:	acc50000 */ 	sw	$a1,0x0($a2)
/*  f116338:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f11633c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f116340:	00043840 */ 	sll	$a3,$a0,0x1
/*  f116344:	94ad0018 */ 	lhu	$t5,0x18($a1)
/*  f116348:	01674021 */ 	addu	$t0,$t3,$a3
/*  f11634c:	950c0000 */ 	lhu	$t4,0x0($t0)
/*  f116350:	3c0a800a */ 	lui	$t2,0x800a
/*  f116354:	00045880 */ 	sll	$t3,$a0,0x2
/*  f116358:	018d7025 */ 	or	$t6,$t4,$t5
/*  f11635c:	a50e0000 */ 	sh	$t6,0x0($t0)
/*  f116360:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f116364:	240effff */ 	addiu	$t6,$zero,-1
/*  f116368:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11636c:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f116370:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f116374:	a4d9000c */ 	sh	$t9,0xc($a2)
/*  f116378:	8d4a2364 */ 	lw	$t2,0x2364($t2)
/*  f11637c:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f116380:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f116384:	a4ce000a */ 	sh	$t6,0xa($a2)
/*  f116388:	a4cd0008 */ 	sh	$t5,0x8($a2)
/*  f11638c:	03e00008 */ 	jr	$ra
/*  f116390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116394:	3c02800a */ 	lui	$v0,0x800a
/*  f116398:	03e00008 */ 	jr	$ra
/*  f11639c:	9442236c */ 	lhu	$v0,0x236c($v0)
/*  f1163a0:	3c02800a */ 	lui	$v0,0x800a
/*  f1163a4:	8c422370 */ 	lw	$v0,0x2370($v0)
/*  f1163a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1163ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1163b0:	10400009 */ 	beqz	$v0,.L0f1163d8
/*  f1163b4:	00803025 */ 	or	$a2,$a0,$zero
/*  f1163b8:	04800007 */ 	bltz	$a0,.L0f1163d8
/*  f1163bc:	3c0e800a */ 	lui	$t6,0x800a
/*  f1163c0:	95ce236c */ 	lhu	$t6,0x236c($t6)
/*  f1163c4:	00067840 */ 	sll	$t7,$a2,0x1
/*  f1163c8:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1163cc:	01c4082a */ 	slt	$at,$t6,$a0
/*  f1163d0:	10200003 */ 	beqz	$at,.L0f1163e0
/*  f1163d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1163d8:
/*  f1163d8:	10000008 */ 	beqz	$zero,.L0f1163fc
/*  f1163dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1163e0:
/*  f1163e0:	0fc458b8 */ 	jal	func0f1162e0
/*  f1163e4:	97040000 */ 	lhu	$a0,0x0($t8)
/*  f1163e8:	50400004 */ 	beqzl	$v0,.L0f1163fc
/*  f1163ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f1163f0:	10000002 */ 	beqz	$zero,.L0f1163fc
/*  f1163f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1163f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1163fc:
/*  f1163fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116400:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116404:	03e00008 */ 	jr	$ra
/*  f116408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11640c:	3c03800a */ 	lui	$v1,0x800a
/*  f116410:	8c632370 */ 	lw	$v1,0x2370($v1)
/*  f116414:	10600009 */ 	beqz	$v1,.L0f11643c
/*  f116418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11641c:	04800007 */ 	bltz	$a0,.L0f11643c
/*  f116420:	3c0e800a */ 	lui	$t6,0x800a
/*  f116424:	95ce236c */ 	lhu	$t6,0x236c($t6)
/*  f116428:	00047840 */ 	sll	$t7,$a0,0x1
/*  f11642c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f116430:	01c4082a */ 	slt	$at,$t6,$a0
/*  f116434:	50200004 */ 	beqzl	$at,.L0f116448
/*  f116438:	97020000 */ 	lhu	$v0,0x0($t8)
.L0f11643c:
/*  f11643c:	03e00008 */ 	jr	$ra
/*  f116440:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f116444:	97020000 */ 	lhu	$v0,0x0($t8)
.L0f116448:
/*  f116448:	03e00008 */ 	jr	$ra
/*  f11644c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116450:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f116454:	03e00008 */ 	jr	$ra
/*  f116458:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f11645c
/*  f11645c:	04800007 */ 	bltz	$a0,.L0f11647c
/*  f116460:	3c0e800a */ 	lui	$t6,0x800a
/*  f116464:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f116468:	3c18800a */ 	lui	$t8,0x800a
/*  f11646c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f116470:	01e4082a */ 	slt	$at,$t7,$a0
/*  f116474:	10200003 */ 	beqz	$at,.L0f116484
/*  f116478:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11647c:
/*  f11647c:	03e00008 */ 	jr	$ra
/*  f116480:	00001025 */ 	or	$v0,$zero,$zero
.L0f116484:
/*  f116484:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f116488:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f11648c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f116490:	95020000 */ 	lhu	$v0,0x0($t0)
/*  f116494:	30490002 */ 	andi	$t1,$v0,0x2
/*  f116498:	01201025 */ 	or	$v0,$t1,$zero
/*  f11649c:	03e00008 */ 	jr	$ra
/*  f1164a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1164a4
/*  f1164a4:	04800016 */ 	bltz	$a0,.L0f116500
/*  f1164a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f1164ac:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1164b0:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f1164b4:	008f082a */ 	slt	$at,$a0,$t7
/*  f1164b8:	10200011 */ 	beqz	$at,.L0f116500
/*  f1164bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1164c0:	10a00009 */ 	beqz	$a1,.L0f1164e8
/*  f1164c4:	3c0a800a */ 	lui	$t2,0x800a
/*  f1164c8:	3c18800a */ 	lui	$t8,0x800a
/*  f1164cc:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f1164d0:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f1164d4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1164d8:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f1164dc:	35090002 */ 	ori	$t1,$t0,0x2
/*  f1164e0:	03e00008 */ 	jr	$ra
/*  f1164e4:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f1164e8:
/*  f1164e8:	8d4a2360 */ 	lw	$t2,0x2360($t2)
/*  f1164ec:	00045840 */ 	sll	$t3,$a0,0x1
/*  f1164f0:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f1164f4:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f1164f8:	318dfffd */ 	andi	$t5,$t4,0xfffd
/*  f1164fc:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f116500:
/*  f116500:	03e00008 */ 	jr	$ra
/*  f116504:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116508
/*  f116508:	3c0e800a */ 	lui	$t6,0x800a
/*  f11650c:	8dce2360 */ 	lw	$t6,0x2360($t6)
/*  f116510:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116514:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f116518:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f11651c:	0305c825 */ 	or	$t9,$t8,$a1
/*  f116520:	03e00008 */ 	jr	$ra
/*  f116524:	a4590000 */ 	sh	$t9,0x0($v0)
);

GLOBAL_ASM(
glabel func0f116528
/*  f116528:	3c0e800a */ 	lui	$t6,0x800a
/*  f11652c:	8dce2360 */ 	lw	$t6,0x2360($t6)
/*  f116530:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116534:	00a0c827 */ 	nor	$t9,$a1,$zero
/*  f116538:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f11653c:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f116540:	03194024 */ 	and	$t0,$t8,$t9
/*  f116544:	03e00008 */ 	jr	$ra
/*  f116548:	a4480000 */ 	sh	$t0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f11654c
/*  f11654c:	04800016 */ 	bltz	$a0,.L0f1165a8
/*  f116550:	3c0e800a */ 	lui	$t6,0x800a
/*  f116554:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f116558:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f11655c:	008f082a */ 	slt	$at,$a0,$t7
/*  f116560:	10200011 */ 	beqz	$at,.L0f1165a8
/*  f116564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116568:	10a00009 */ 	beqz	$a1,.L0f116590
/*  f11656c:	3c0a800a */ 	lui	$t2,0x800a
/*  f116570:	3c18800a */ 	lui	$t8,0x800a
/*  f116574:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f116578:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f11657c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116580:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f116584:	35090001 */ 	ori	$t1,$t0,0x1
/*  f116588:	03e00008 */ 	jr	$ra
/*  f11658c:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f116590:
/*  f116590:	8d4a2360 */ 	lw	$t2,0x2360($t2)
/*  f116594:	00045840 */ 	sll	$t3,$a0,0x1
/*  f116598:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f11659c:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f1165a0:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*  f1165a4:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f1165a8:
/*  f1165a8:	03e00008 */ 	jr	$ra
/*  f1165ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1165b0
/*  f1165b0:	9482000c */ 	lhu	$v0,0xc($a0)
/*  f1165b4:	304e00e0 */ 	andi	$t6,$v0,0xe0
/*  f1165b8:	03e00008 */ 	jr	$ra
/*  f1165bc:	000e102b */ 	sltu	$v0,$zero,$t6
/*  f1165c0:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f1165c4:	03e00008 */ 	jr	$ra
/*  f1165c8:	00801025 */ 	or	$v0,$a0,$zero
);