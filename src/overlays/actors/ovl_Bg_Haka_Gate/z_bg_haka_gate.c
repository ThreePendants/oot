/*
 * File: z_bg_haka_gate.c
 * Overlay: ovl_Bg_Haka_Gate
 * Description: Truth Spinner Puzzle (Shadow Temple)
 */

#include "z_bg_haka_gate.h"
#include "objects/gameplay_keep/gameplay_keep.h"

#define FLAGS 0x00000000

#define THIS ((BgHakaGate*)thisx)

// general purpose timer
#define vTimer actionVar1

// variables for turning the statue. Deg10 rotations are in tenths of a degree
#define vTurnDirection actionVar1
#define vTurnRateDeg10 actionVar2
#define vTurnAngleDeg10 actionVar3
#define vRotYDeg10 actionVar4
#define vInitTurnAngle actionVar5

// opening angle for floor
#define vOpenAngle actionVar2

// variables for the skull flames
#define vFlameScale actionVar3
#define vIsSkullOfTruth actionVar4
#define vScrollTimer actionVar5

#define SKULL_OF_TRUTH_FOUND 100

void BgHakaGate_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaGate_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaGate_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaGate_Draw(Actor* this, GlobalContext* globalCtx);

void BgHakaGate_DoNothing(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_StatueInactive(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_StatueIdle(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_StatueTurn(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_FloorClosed(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_FloorOpen(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_GateWait(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_GateOpen(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_SkullOfTruth(BgHakaGate* this, GlobalContext* globalCtx);
void BgHakaGate_FalseSkull(BgHakaGate* this, GlobalContext* globalCtx);

extern ColHeader D_0600A938;
extern Gfx D_0600F1B0[];
extern Gfx D_06010A10[];
extern Gfx D_06010C10[];
extern ColHeader D_06010E10;
extern ColHeader D_060131C4;

static s16 sSkullOfTruthRotY = 0x100;
static u8 sPuzzleState = 1;
static f32 sStatueDistFromLink = 0;

static s16 sStatueRotY;

const ActorInit Bg_Haka_Gate_InitVars = {
    ACTOR_BG_HAKA_GATE,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaGate),
    (ActorFunc)BgHakaGate_Init,
    (ActorFunc)BgHakaGate_Destroy,
    (ActorFunc)BgHakaGate_Update,
    (ActorFunc)BgHakaGate_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaGate_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHakaGate* this = THIS;
    ColHeader* colHeader = NULL;

    Actor_ProcessInitChain(thisx, sInitChain);
    this->switchFlag = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;
    DynaPolyInfo_SetActorMove(&this->dyna, 0);
    if (thisx->params == BGHAKAGATE_SKULL) {
        if (sSkullOfTruthRotY != 0x100) {
            this->actionFunc = BgHakaGate_FalseSkull;
        } else if (ABS(thisx->shape.rot.y) < 0x4000) {
            if ((Rand_ZeroOne() * 3.0f) < sPuzzleState) {
                this->vIsSkullOfTruth = true;
                sSkullOfTruthRotY = thisx->shape.rot.y + 0x8000;
                if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
                    this->actionFunc = BgHakaGate_DoNothing;
                } else {
                    this->actionFunc = BgHakaGate_SkullOfTruth;
                }
            } else {
                sPuzzleState++;
                this->actionFunc = BgHakaGate_FalseSkull;
            }
        } else {
            this->actionFunc = BgHakaGate_FalseSkull;
        }
        this->vScrollTimer = Rand_ZeroOne() * 20.0f;
        thisx->flags |= 0x10;
        if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
            this->vFlameScale = 350;
        }
    } else {
        if (thisx->params == BGHAKAGATE_STATUE) {
            DynaPolyInfo_Alloc(&D_060131C4, &colHeader);
            this->vTimer = 0;
            sStatueDistFromLink = 0.0f;
            if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
                this->actionFunc = BgHakaGate_StatueInactive;
            } else {
                this->actionFunc = BgHakaGate_StatueIdle;
            }
        } else if (thisx->params == BGHAKAGATE_FLOOR) {
            DynaPolyInfo_Alloc(&D_06010E10, &colHeader);
            if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
                this->actionFunc = BgHakaGate_DoNothing;
            } else {
                this->actionFunc = BgHakaGate_FloorClosed;
            }
        } else { // BGHAKAGATE_GATE
            DynaPolyInfo_Alloc(&D_0600A938, &colHeader);
            if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
                this->actionFunc = BgHakaGate_DoNothing;
                thisx->posRot.pos.y += 80.0f;
            } else {
                thisx->flags |= 0x10;
                Actor_SetHeight(thisx, 30.0f);
                this->actionFunc = BgHakaGate_GateWait;
            }
        }
        this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, thisx, colHeader);
    }
}

void BgHakaGate_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHakaGate* this = THIS;

    DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
    if (this->dyna.actor.params == BGHAKAGATE_STATUE) {
        sSkullOfTruthRotY = 0x100;
        sPuzzleState = 1;
    }
}

void BgHakaGate_DoNothing(BgHakaGate* this, GlobalContext* globalCtx) {
}

void BgHakaGate_StatueInactive(BgHakaGate* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (this->dyna.unk_150 != 0.0f) {
        player->stateFlags2 &= ~0x10;
        this->dyna.unk_150 = 0.0f;
    }
}

void BgHakaGate_StatueIdle(BgHakaGate* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    s32 linkDirection;
    f32 forceDirection;

    if (this->dyna.unk_150 != 0.0f) {
        if (this->vTimer == 0) {
            this->vInitTurnAngle = this->dyna.actor.shape.rot.y - this->dyna.actor.yawTowardsLink;
            sStatueDistFromLink = this->dyna.actor.xzDistFromLink;
            forceDirection = (this->dyna.unk_150 >= 0.0f) ? 1.0f : -1.0f;
            linkDirection = ((s16)(this->dyna.actor.yawTowardsLink - player->actor.shape.rot.y) > 0) ? -1 : 1;
            this->vTurnDirection = linkDirection * forceDirection;
            this->actionFunc = BgHakaGate_StatueTurn;
        } else {
            player->stateFlags2 &= ~0x10;
            this->dyna.unk_150 = 0.0f;
            if (this->vTimer != 0) {
                this->vTimer--;
            }
        }
    } else {
        if (sPuzzleState == SKULL_OF_TRUTH_FOUND) {
            this->actionFunc = BgHakaGate_StatueInactive;
        } else {
            this->vTimer = 0;
        }
    }
}

void BgHakaGate_StatueTurn(BgHakaGate* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    s32 turnFinished;
    s16 turnAngle;

    this->vTurnRateDeg10++;
    this->vTurnRateDeg10 = CLAMP_MAX(this->vTurnRateDeg10, 5);
    turnFinished = Math_StepToS(&this->vTurnAngleDeg10, 600, this->vTurnRateDeg10);
    turnAngle = this->vTurnAngleDeg10 * this->vTurnDirection;
    this->dyna.actor.shape.rot.y = (this->vRotYDeg10 + turnAngle) * 0.1f * (0x10000 / 360.0f);
    if ((player->stateFlags2 & 0x10) && (sStatueDistFromLink > 0.0f)) {
        player->actor.posRot.pos.x =
            this->dyna.actor.initPosRot.pos.x +
            (Math_SinS(this->dyna.actor.shape.rot.y - this->vInitTurnAngle) * sStatueDistFromLink);
        player->actor.posRot.pos.z =
            this->dyna.actor.initPosRot.pos.z +
            (Math_CosS(this->dyna.actor.shape.rot.y - this->vInitTurnAngle) * sStatueDistFromLink);
    } else {
        sStatueDistFromLink = 0.0f;
    }
    sStatueRotY = this->dyna.actor.shape.rot.y;
    if (turnFinished) {
        player->stateFlags2 &= ~0x10;
        this->vRotYDeg10 = (this->vRotYDeg10 + turnAngle) % 3600;
        this->vTurnRateDeg10 = 0;
        this->vTurnAngleDeg10 = 0;
        this->vTimer = 5;
        this->actionFunc = BgHakaGate_StatueIdle;
        this->dyna.unk_150 = 0.0f;
    }
    func_8002F974(&this->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}

void BgHakaGate_FloorClosed(BgHakaGate* this, GlobalContext* globalCtx) {
    if ((sStatueDistFromLink > 1.0f) && (sStatueRotY != 0)) {
        Player* player = PLAYER;
        f32 radialDist;
        f32 angDist;
        f32 cos = Math_CosS(sStatueRotY);
        f32 sin = Math_SinS(sStatueRotY);
        f32 dx = player->actor.posRot.pos.x - this->dyna.actor.posRot.pos.x;
        f32 dz = player->actor.posRot.pos.z - this->dyna.actor.posRot.pos.z;

        radialDist = dx * cos - dz * sin;
        angDist = dx * sin + dz * cos;

        if ((radialDist > 110.0f) || (fabsf(angDist) > 40.0f)) {
            s16 yawDiff = sSkullOfTruthRotY - sStatueRotY;

            sStatueDistFromLink = 0.0f;
            if (ABS(yawDiff) < 0x80) {
                Flags_SetSwitch(globalCtx, this->switchFlag);
                sPuzzleState = SKULL_OF_TRUTH_FOUND;
                this->actionFunc = BgHakaGate_DoNothing;
            } else {
                func_80078884(NA_SE_SY_ERROR);
                Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_GROUND_GATE_OPEN);
                func_8003EBF8(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
                this->vTimer = 60;
                this->actionFunc = BgHakaGate_FloorOpen;
            }
        }
    }
}

void BgHakaGate_FloorOpen(BgHakaGate* this, GlobalContext* globalCtx) {
    if (this->vTimer != 0) {
        this->vTimer--;
    }
    if (this->vTimer == 0) {
        if (Math_ScaledStepToS(&this->vOpenAngle, 0, 0x800)) {
            func_8003EC50(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
            this->actionFunc = BgHakaGate_FloorClosed;
        }
    } else {
        Math_ScaledStepToS(&this->vOpenAngle, 0x3000, 0x800);
    }
}

void BgHakaGate_GateWait(BgHakaGate* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
        func_80080480(globalCtx, &this->dyna.actor);
        this->actionFunc = BgHakaGate_GateOpen;
    }
}

void BgHakaGate_GateOpen(BgHakaGate* this, GlobalContext* globalCtx) {
    if (Math_StepToF(&this->dyna.actor.posRot.pos.y, this->dyna.actor.initPosRot.pos.y + 80.0f, 1.0f)) {
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_METALDOOR_STOP);
        this->dyna.actor.flags &= ~0x10;
        this->actionFunc = BgHakaGate_DoNothing;
    } else {
        func_8002F974(&this->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
    }
}

void BgHakaGate_SkullOfTruth(BgHakaGate* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, this->switchFlag) && Math_StepToS(&this->vFlameScale, 350, 20)) {
        this->actionFunc = BgHakaGate_DoNothing;
    }
}

void BgHakaGate_FalseSkull(BgHakaGate* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
        Math_StepToS(&this->vFlameScale, 350, 20);
    }
    if (globalCtx->actorCtx.unk_03) {
        this->dyna.actor.flags |= 0x80;
    } else {
        this->dyna.actor.flags &= ~0x80;
    }
}

void BgHakaGate_Update(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    BgHakaGate* this = THIS;

    this->actionFunc(this, globalCtx);
    if (this->dyna.actor.params == BGHAKAGATE_SKULL) {
        this->vScrollTimer++;
    }
}

void BgHakaGate_DrawFlame(BgHakaGate* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->dyna.actor;
    f32 scale;

    if (this->vFlameScale > 0) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 716);

        if (1) {}

        func_80093D84(globalCtx->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                    (this->vScrollTimer * -20) & 0x1FF, 0x20, 0x80));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);

        Matrix_Translate(thisx->posRot.pos.x, thisx->posRot.pos.y + 15.0f, thisx->posRot.pos.z, MTXMODE_NEW);
        Matrix_RotateY(Camera_GetCamDirYaw(ACTIVE_CAM) * (M_PI / 0x8000), MTXMODE_APPLY);
        scale = this->vFlameScale * 0.00001f;
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 744),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gEffectFireDL1);
        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 749);
    }
}

void BgHakaGate_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static Gfx* displayLists[] = { 0x06012270, 0x06010A10, 0x0600A860, 0x0600F1B0 };
    BgHakaGate* this = THIS;
    MtxF currentMtxF;

    if ((thisx->flags & 0x80) == 0x80) {
        Gfx_DrawDListXlu(globalCtx, D_0600F1B0);
    } else {
        func_80093D18(globalCtx->state.gfxCtx);
        if (thisx->params == BGHAKAGATE_FLOOR) {
            OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 781);
            Matrix_Get(&currentMtxF);
            Matrix_Translate(0.0f, 0.0f, -2000.0f, MTXMODE_APPLY);
            Matrix_RotateX(this->vOpenAngle * (M_PI / 0x8000), MTXMODE_APPLY);
            Matrix_Translate(0.0f, 0.0f, 2000.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 788),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, D_06010A10);
            Matrix_Put(&currentMtxF);
            Matrix_Translate(0.0f, 0.0f, 2000.0f, MTXMODE_APPLY);
            Matrix_RotateX(-this->vOpenAngle * (M_PI / 0x8000), MTXMODE_APPLY);
            Matrix_Translate(0.0f, 0.0f, -2000.0f, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 796),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, D_06010C10);
            CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_gate.c", 800);
        } else {
            Gfx_DrawDListOpa(globalCtx, displayLists[thisx->params]);
        }
    }
    if (thisx->params == BGHAKAGATE_SKULL) {
        BgHakaGate_DrawFlame(this, globalCtx);
    }
}
