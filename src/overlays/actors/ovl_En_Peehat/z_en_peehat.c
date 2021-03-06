#include "z_en_peehat.h"

#define FLAGS 0x01000015

#define THIS ((EnPeehat*)thisx)

void EnPeehat_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPeehat_Draw(Actor* thisx, GlobalContext* globalCtx);

extern UNK_TYPE D_06000350;
extern UNK_TYPE D_060005C4;
extern UNK_TYPE D_06000844;
extern UNK_TYPE D_060009C4;
extern UNK_TYPE D_06001C80;

/*
const ActorInit En_Peehat_InitVars = {
    ACTOR_EN_PEEHAT,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_PEEHAT,
    sizeof(EnPeehat),
    (ActorFunc)EnPeehat_Init,
    (ActorFunc)EnPeehat_Destroy,
    (ActorFunc)EnPeehat_Update,
    (ActorFunc)EnPeehat_Draw,
};

static ColliderCylinderInit D_80AD2740 = {
    {
        COLTYPE_WOOD,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    },
    { 50, 160, -70, { 0, 0, 0 } },
};

static ColliderQuadInit D_80AD27A0 = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x10 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static ColliderJntSphElementInit D_80AD276C[1] = {
    {
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0xFFCFFFFF, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 20 }, 100 },
    },
};

static ColliderJntSphInit D_80AD2790 = {
    {
        COLTYPE_HIT6,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    1,
    D_80AD276C,
};
*/
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACF4A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/EnPeehat_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/EnPeehat_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACF788.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACF920.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFB34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFBCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFD20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFDAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFEB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80ACFEF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0070.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0118.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD02E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD038C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0558.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD05A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0720.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD076C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0B3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0B84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0D3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0D84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0F38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD0FC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1220.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1258.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1440.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD14A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD167C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1700.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD177C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD17E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1AA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1B00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD1BD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/EnPeehat_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD2224.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/func_80AD2438.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Peehat/EnPeehat_Draw.s")
