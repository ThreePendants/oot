/*
 * File: z_bg_mizu_movebg.c
 * Overlay: ovl_Bg_Mizu_Movebg
 * Description: Water Temple Background Objects
 */

#include "z_bg_mizu_movebg.h"

#define FLAGS 0x00000010

#define THIS ((BgMizuMovebg*)thisx)

void BgMizuMovebg_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Update(Actor* thisx, GlobalContext* globalCtx);
void BgMizuMovebg_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8089E318(BgMizuMovebg* this, GlobalContext* globalCtx);
void func_8089E650(BgMizuMovebg* this, GlobalContext* globalCtx);
s32 func_8089DC30(GlobalContext* globalCtx);

const ActorInit Bg_Mizu_Movebg_InitVars = {
    ACTOR_BG_MIZU_MOVEBG,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_MIZU_OBJECTS,
    sizeof(BgMizuMovebg),
    (ActorFunc)BgMizuMovebg_Init,
    (ActorFunc)BgMizuMovebg_Destroy,
    (ActorFunc)BgMizuMovebg_Update,
    (ActorFunc)BgMizuMovebg_Draw,
};

// ???
f32 D_8089EB40[] = {
    -115.2f,
    -115.2f,
    -115.2f,
    0.0f,
};

// sDLists
u32 D_8089EB50[] = {
    0x06000190, 0x06000680, 0x06000C20, 0x06002E10, 0x06002E10, 0x06002E10, 0x06002E10, 0x060011F0,
};

// sCollisions
u32 D_8089EB70[] = {
    0x060003F0, 0x06000998, 0x06000ED0, 0x06003590, 0x06003590, 0x06003590, 0x06003590, 0x060015F8,
};

// sInitChain
u32 D_8089EB90[] = {
    0xB0F805DC,
    0xB0FC044C,
    0xB0F403E8,
    0x48500064,
};

// ???
Vec3f D_8089EBA0 = { 0.0f, 80.0f, 23.0f };

// ???
Vec3f D_8089EBAC = { 0.0f, 80.0f, 23.0f };

// ???
u8 D_8089EE40[0x10];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/func_8089DC30.s")

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/BgMizuMovebg_Init.s")
void BgMizuMovebg_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMizuMovebg* this = THIS;
    s32 pad;
    WaterBox* waterBoxes = globalCtx->colCtx.colHeader->waterBoxes;
    s32 type = (this->dyna.actor.params >> 0xC) & 0xF;
    CollisionHeader* colHeader = NULL;
    Vec3f sp48;

    Actor_ProcessInitChain(&this->dyna.actor, D_8089EB90);
    this->unk_168 = this->dyna.actor.posRot.pos.y;

    this->unk_180 = D_8089EB50[type];
    DynaPolyActor_Init(&this->dyna.actor, 1);
    CollisionHeader_GetVirtual(D_8089EB70[type], &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, colHeader);

    switch (type) {
        case 0:
            if ((waterBoxes[2].ySurface + 15.0f) < (this->unk_168 - 700.0f)) {
                this->dyna.actor.posRot.pos.y = this->unk_168 - 700.0f;
            } else {
                this->dyna.actor.posRot.pos.y = waterBoxes[2].ySurface + 15.0f;
            }

            this->actionFunc = func_8089E318;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
        case 1:
            if ((waterBoxes[2].ySurface + 15.0f) < (this->unk_168 - 710.0f)) {
                this->dyna.actor.posRot.pos.y = this->unk_168 - 710.0f;
            } else {
                this->dyna.actor.posRot.pos.y = waterBoxes[2].ySurface + 15.0f;
            }

            this->actionFunc = func_8089E318;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
        case 2:
            if ((waterBoxes[2].ySurface + 15.0f) < (this->unk_168 - 700.0f)) {
                this->dyna.actor.posRot.pos.y = waterBoxes[2].ySurface + 15.0f;
            } else {
                this->dyna.actor.posRot.pos.y = this->unk_168 - 700.0f;
            }

            this->actionFunc = func_8089E318;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
        case 3:
            this->dyna.actor.posRot.pos.y = D_8089EB40[func_8089DC30(globalCtx)] + this->unk_168;
            this->actionFunc = func_8089E318;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
        default:
            if (Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F)) {
                this->dyna.actor.posRot.pos.y = this->unk_168 + 115.19999999999999;
            } else {
                this->dyna.actor.posRot.pos.y = this->unk_168;
            }

            this->actionFunc = func_8089E318;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
        case 7:
            this->unk_16C = 160;
            this->unk_170 = 160;
            this->unk_174 = 160;
            this->unk_178 = 160;
            this->unk_184 = this->dyna.actor.params & 0xF;
            func_8089E108(globalCtx->setupPathList, &this->dyna.actor.posRot, (this->dyna.actor.params >> 8) & 0xF, this->dyna.actor.params & 0xF);
            this->actionFunc = &func_8089E650;
            type = (this->dyna.actor.params >> 0xC) & 0xF;
            break;
    }

    if (((type) == 3) || ((type) == 4) ||
        ((type) == 5) || ((type) == 6)) {
        Matrix_RotateY(this->dyna.actor.posRot.rot.y * (M_PI / 32768.0f), MTXMODE_NEW);
        Matrix_MultVec3f(&D_8089EBA0, &sp48);

        if (Actor_SpawnAsChild(&globalCtx->actorCtx, &this->dyna.actor, globalCtx, ACTOR_OBJ_HSBLOCK, this->dyna.actor.posRot.pos.x + sp48.x,
                               this->dyna.actor.posRot.pos.y + sp48.y, this->dyna.actor.posRot.pos.z + sp48.z, this->dyna.actor.posRot.rot.x,
                               this->dyna.actor.posRot.rot.y, this->dyna.actor.posRot.rot.z, 2) == NULL) {
            Actor_Kill(&this->dyna.actor);
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/BgMizuMovebg_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/func_8089E108.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/func_8089E198.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/func_8089E318.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/func_8089E650.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/BgMizuMovebg_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Mizu_Movebg/BgMizuMovebg_Draw.s")
