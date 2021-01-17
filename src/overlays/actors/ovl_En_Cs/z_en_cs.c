#include "z_en_cs.h"

#define FLAGS 0x00000009

#define THIS ((EnCs*)thisx)

void EnCs_Init(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Update(Actor* thisx, GlobalContext* globalCtx);
void EnCs_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809E2134(EnCs* this, GlobalContext* globalCtx);
void func_809E2360(EnCs* this, GlobalContext* globalCtx);
void func_809E22D4(EnCs* this, GlobalContext* globalCtx);
void func_809E2134(EnCs* this, GlobalContext* globalCtx);
s32 EnCs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* pos, Vec3s* rot, void* thisx);
void EnCs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx);

extern UNK_TYPE D_06008540;
extern Gfx D_0602AF70[];

const ActorInit En_Cs_InitVars = {
    ACTOR_EN_CS,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_CS,
    sizeof(EnCs),
    (ActorFunc)EnCs_Init,
    (ActorFunc)EnCs_Destroy,
    (ActorFunc)EnCs_Update,
    (ActorFunc)EnCs_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    { COLTYPE_UNK10, 0x00, 0x00, 0x39, 0x20, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 18, 63, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit2 = { 0, 0, 0, 0, 0xFF };

static DamageTable sDamageTable = { 0 };

static struct_D_80AA1678 sAnimations[] = {
    { 0x06000700, 1.0f, 2, -10.0f },
    { 0x06000E10, 1.0f, 2, -10.0f },
    { 0x06001588, 1.0f, 2, -10.0f },
    { 0x0600195C, 1.0f, 2, -10.0f },
};

void func_809E18B0(EnCs* this, s32 animIndex, s32* currentAnimIndex) {
    f32 transitionRate;

    if ((*currentAnimIndex < 0) || (animIndex == *currentAnimIndex)) {
        transitionRate = 0.0f;
    } else {
        transitionRate = sAnimations[animIndex].transitionRate;
    }

    if (sAnimations[animIndex].frameCount >= 0.0f) {
        Animation_Change(&this->skelAnime, sAnimations[animIndex].animation, sAnimations[animIndex].frameCount, 0.0f,
                         Animation_GetLastFrame(sAnimations[animIndex].animation), sAnimations[animIndex].unk_08,
                         transitionRate);
    } else {
        Animation_Change(&this->skelAnime, sAnimations[animIndex].animation, sAnimations[animIndex].frameCount,
                         Animation_GetLastFrame(sAnimations[animIndex].animation), 0.0f, sAnimations[animIndex].unk_08,
                         transitionRate);
    }

    *currentAnimIndex = animIndex;
}

void EnCs_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnCs* this = THIS;
    s32 pad;

    if (gSaveContext.nightFlag != 0) {
        Actor_Kill(&this->actor);
        return;
    }

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 19.0f);

    SkelAnime_InitFlex(globalCtx, &this->skelAnime, &D_06008540, NULL, this->jointTable, this->morphTable, 16);

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &sCylinderInit);

    func_80061EFC(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit2);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);

    Animation_Change(&this->skelAnime, sAnimations[0].animation, 1.0f, 0.0f,
                     Animation_GetLastFrame(sAnimations[0].animation), sAnimations[0].unk_08,
                     sAnimations[0].transitionRate);

    this->actor.unk_1F = 6;
    this->path = this->actor.params & 0xFF;
    this->unk_1EC = 0;
    this->talkState = 0;
    this->currentAnimIndex = -1;
    this->actor.gravity = -1.0f;

    func_809E18B0(this, 0, &this->currentAnimIndex);

    this->actionFunc = func_809E2134;
    this->runSpeed = 1.0f;
}

void EnCs_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnCs* this = THIS;

    Collider_DestroyCylinder(globalCtx, &this->collider);
}

s32 func_809E1B8C(EnCs* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 pad2;
    s32 talkState = 1;

    switch (func_8010BDBC(&globalCtx->msgCtx)) {
        case 4:
            if (func_80106BC8(globalCtx) != 0) {
                if (globalCtx->msgCtx.choiceIndex == 0) {
                    this->actor.textId = 0x2026;
                    func_809E18B0(this, 3, &this->currentAnimIndex);
                    talkState = 2;
                } else {
                    this->actor.textId = 0x2024;
                    func_809E18B0(this, 1, &this->currentAnimIndex);
                    talkState = 2;
                }
            }
            break;
        case 6:
            if (func_80106BC8(globalCtx)) {
                if (this->actor.textId == 0x2026) {
                    Player_UnsetMask(globalCtx);
                    Item_Give(globalCtx, ITEM_SOLD_OUT);
                    gSaveContext.itemGetInf[3] |= 0x400;
                    Rupees_ChangeBy(30);
                    this->actor.textId = 0x2027;
                    talkState = 2;
                } else {
                    talkState = 0;
                }
            }
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
            break;
    }

    return talkState;
}

s32 func_809E1CB8(EnCs* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;
    s32 textId = Text_GetFaceReaction(globalCtx, 15);

    if (gSaveContext.itemGetInf[3] & 0x400) {
        if (textId == 0) {
            textId = 0x2028;
        }
    } else if (player->currentMask == PLAYER_MASK_SPOOKY) {
        textId = 0x2023;
    } else {
        if (textId == 0) {
            textId = 0x2022;
        }
    }

    return textId;
}

void func_809E1D38(EnCs* this, GlobalContext* globalCtx) {
    s32 pad;
    s16 sp2A;
    s16 sp28;

    if (this->talkState == 2) {
        func_8010B720(globalCtx, this->actor.textId);
        this->talkState = 1;
    } else if (this->talkState == 1) {
        this->talkState = func_809E1B8C(this, globalCtx);
    } else if (func_8002F194(&this->actor, globalCtx)) {
        if ((this->actor.textId == 0x2022) || ((this->actor.textId != 0x2022) && (this->actor.textId != 0x2028))) {
            func_809E18B0(this, 3, &this->currentAnimIndex);
        }

        if ((this->actor.textId == 0x2023) || (this->actor.textId == 0x2028)) {
            func_809E18B0(this, 1, &this->currentAnimIndex);
        }

        if (this->actor.textId == 0x2023) {
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        }

        this->talkState = 1;
    } else {
        func_8002F374(globalCtx, &this->actor, &sp2A, &sp28);

        if ((sp2A >= 0) && (sp2A <= 320) && (sp28 >= 0) && (sp28 <= 240) && (func_8002F2CC(this, globalCtx, 100.0f))) {
            this->actor.textId = func_809E1CB8(this, globalCtx);
        }
    }
}

s32 EnCs_GetPathPointCount(Path* pathList, s32 pathIndex) {
    Path* path = &pathList[pathIndex];

    return path->count;
}

s32 EnCs_GetPathPoint(Path* pathList, Vec3f* dest, s32 pathIndex, s32 waypoint) {
    Path* path = pathList;
    Vec3s* pathPos;

    path += pathIndex;
    pathPos = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[waypoint];

    dest->x = pathPos->x;
    dest->y = pathPos->y;
    dest->z = pathPos->z;

    return 0;
}

s32 EnCs_HandleRunning(EnCs* this, GlobalContext* globalCtx) {
    f32 xDiff;
    f32 zDiff;
    Vec3f pathPos;
    s32 pathPointCount;
    s16 angle1;
    s16 angle2;

    EnCs_GetPathPoint(globalCtx->setupPathList, &pathPos, this->path, this->waypoint);
    xDiff = pathPos.x - this->actor.posRot.pos.x;
    zDiff = pathPos.z - this->actor.posRot.pos.z;
    angle1 = Math_FAtan2F(xDiff, zDiff) * 10430.378f;
    this->unk_204 = angle1;
    this->runDist = sqrtf((xDiff * xDiff) + (zDiff * zDiff));

    while (this->runDist <= 10.44f) {
        this->waypoint++;
        pathPointCount = EnCs_GetPathPointCount(globalCtx->setupPathList, this->path);

        if ((this->waypoint < 0) || (!(this->waypoint < pathPointCount))) {
            this->waypoint = 0;
        }

        EnCs_GetPathPoint(globalCtx->setupPathList, &pathPos, this->path, this->waypoint);
        xDiff = pathPos.x - this->actor.posRot.pos.x;
        zDiff = pathPos.z - this->actor.posRot.pos.z;
        angle2 = Math_FAtan2F(xDiff, zDiff) * 10430.378f;
        this->unk_204 = angle2;
        this->runDist = sqrtf((xDiff * xDiff) + (zDiff * zDiff));
    }

    Math_SmoothStepToS(&this->actor.shape.rot.y, this->unk_204, 1, 2500, 0);
    this->actor.posRot.rot.y = this->actor.shape.rot.y;
    this->actor.speedXZ = this->runSpeed;
    Actor_MoveForward(&this->actor);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);

    return 0;
}

// void func_809E2134(EnCs* this, GlobalContext* globalCtx);
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Cs/func_809E2134.s")
void func_809E2134(EnCs* this, GlobalContext* globalCtx) {
    s32 phi_v0;
    s32 phi_a1;

    if (this->talkState != 0) {
        this->actionFunc = func_809E2360;
        return;
    }

    if (SkelAnime_Update(&this->skelAnime)) {
        phi_a1 = this->currentAnimIndex;

        if (this->talkState == 0) {
            if (gSaveContext.itemGetInf[3] & 0x400) {
                phi_v0 = Rand_ZeroOne() * 10.0f;
            } else {
                phi_v0 = Rand_ZeroOne() * 5.0f;
            }

            phi_a1 = 0;

            if (phi_v0 == 0) {
                phi_a1 = 2;

                if (gSaveContext.itemGetInf[3] & 0x400) {
                    phi_a1 = 2.0f * Rand_ZeroOne();
                    phi_a1 = (phi_a1 == 0) ? 2 : 1;
                }

                this->actionFunc = func_809E22D4;
            }
        }

        func_809E18B0(this, phi_a1, &this->currentAnimIndex);
    }

    if (this->talkState == 0) {
        if (((s32)this->skelAnime.curFrame < 8) || ((s32)this->skelAnime.curFrame >= 16)) {
            if (((s32)this->skelAnime.curFrame < 23) || ((s32)this->skelAnime.curFrame >= 30)) {
                if ((s32)this->skelAnime.curFrame != 0) {
                    this->runSpeed = 1.0f;
                }
            } else {
                this->runSpeed = 0.0f;
            }
        }

        EnCs_HandleRunning(this, globalCtx);
    }
}

void func_809E22D4(EnCs* this, GlobalContext* globalCtx) {
    s32 animIndex;

    if (this->talkState != 0) {
        this->actionFunc = func_809E2360;
        return;
    }

    if (SkelAnime_Update(&this->skelAnime)) {
        animIndex = this->currentAnimIndex;

        if (this->talkState == 0) {
            if (this->unk_200 > 0) {
                this->unk_200--;
                animIndex = this->currentAnimIndex;
            } else {
                animIndex = 0;
                this->actionFunc = func_809E2134;
            }
        }

        func_809E18B0(this, animIndex, &this->currentAnimIndex);
    }
}

void func_809E2360(EnCs* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    if (SkelAnime_Update(&this->skelAnime) != 0) {
        func_809E18B0(this, this->currentAnimIndex, &this->currentAnimIndex);
    }

    this->flag |= 1;
    this->npcInfo.unk_18.x = player->actor.posRot2.pos.x;
    this->npcInfo.unk_18.y = player->actor.posRot2.pos.y;
    this->npcInfo.unk_18.z = player->actor.posRot2.pos.z;
    func_80034A14(&this->actor, &this->npcInfo, 0, 4);

    if (this->talkState == 0) {
        func_809E18B0(this, 0, &this->currentAnimIndex);
        this->actionFunc = func_809E2134;
        this->flag &= ~1;
    }
}

void EnCs_Update(Actor* thisx, GlobalContext* globalCtx) {
    static s32 eyeBlinkFrames[] = { 70, 1, 1 };
    EnCs* this = THIS;
    s32 pad;

    if (this->currentAnimIndex == 0) {
        if (((s32)this->skelAnime.curFrame == 9) || ((s32)this->skelAnime.curFrame == 23)) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_CHIBI_WALK);
        }
    } else if (this->currentAnimIndex == 1) {
        if (((s32)this->skelAnime.curFrame == 10) || ((s32)this->skelAnime.curFrame == 25)) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_CHIBI_WALK);
        }
    } else if ((this->currentAnimIndex == 2) && ((s32)this->skelAnime.curFrame == 20)) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EV_CHIBI_WALK);
    }

    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    this->actionFunc(this, globalCtx);

    func_809E1D38(this, globalCtx);

    this->eyeBlinkTimer--;

    if (this->eyeBlinkTimer < 0) {
        this->eyeIndex++;

        if (this->eyeIndex >= 3) {
            this->eyeIndex = 0;
        }

        this->eyeBlinkTimer = eyeBlinkFrames[this->eyeIndex];
    }
}

void EnCs_Draw(Actor* thisx, GlobalContext* globalCtx) {
    static u32* eyeTextures[] = { 0x06002130, 0x06002930, 0x06003130 };
    EnCs* this = THIS;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_cs.c", 968);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTextures[this->eyeIndex]));

    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          EnCs_OverrideLimbDraw, EnCs_PostLimbDraw, &this->actor);

    if (gSaveContext.itemGetInf[3] & 0x400) {
        s32 childLinkObjectIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_LINK_CHILD);

        if (childLinkObjectIndex >= 0) {
            Mtx* mtx;

            Matrix_Put(&this->spookyMaskMtx);
            mtx = Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_cs.c", 1000);
            gSPSegment(POLY_OPA_DISP++, 0x06, globalCtx->objectCtx.status[childLinkObjectIndex].segment);
            gSPSegment(POLY_OPA_DISP++, 0x0D, mtx - 7);
            gSPDisplayList(POLY_OPA_DISP++, D_0602AF70);
            gSPSegment(POLY_OPA_DISP++, 0x06, globalCtx->objectCtx.status[this->actor.objBankIndex].segment);
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_cs.c", 1015);
}

s32 EnCs_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* pos, Vec3s* rot, void* thisx) {
    EnCs* this = THIS;

    if (this->flag & 1) {
        switch (limbIndex) {
            case 8:
                rot->x += this->npcInfo.unk_0E.y;
                rot->y -= this->npcInfo.unk_0E.x;
                break;
            case 15:
                rot->x += this->npcInfo.unk_08.y;
                rot->z += this->npcInfo.unk_08.x;
                break;
        }
    }

    return 0;
}

void EnCs_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    static Vec3f D_809E2970 = { 500.0f, 800.0f, 0.0f };
    EnCs* this = THIS;

    if (limbIndex == 15) {
        Matrix_MultVec3f(&D_809E2970, &this->actor.posRot2.pos);
        Matrix_Translate(0.0f, -200.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateY(0.0f, MTXMODE_APPLY);
        Matrix_RotateX(0.0f, MTXMODE_APPLY);
        Matrix_RotateZ(1.7453293f, MTXMODE_APPLY);
        Matrix_Get(&this->spookyMaskMtx);
    }
}
