/*
 * File: z_eff_ss_g_fire.c
 * Overlay: ovl_Effect_Ss_G_Fire
 * Description: Flame Footprints
 */

#include "z_eff_ss_g_fire.h"
#include "objects/gameplay_keep/gameplay_keep.h"

u32 EffectSsGFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx);
void EffectSsGFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this);
void EffectSsGFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_G_Fire_InitVars = {
    EFFECT_SS_G_FIRE,
    EffectSsGFire_Init,
};

u32 EffectSsGFire_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsGFireInitParams* initParams = (EffectSsGFireInitParams*)initParamsx;
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };

    this->velocity = this->accel = zeroVec;
    this->pos = initParams->pos;
    this->draw = EffectSsGFire_Draw;
    this->update = EffectSsGFire_Update;
    this->gfx = SEGMENTED_TO_VIRTUAL(gEffectFireFootprintDL);
    this->life = 8;
    this->flags = 0;
    this->rgScale = 200;
    this->rgTexIdx = 0;
    this->rgTexIdxStep = 50;
    this->rgPrimColorR = 255;
    this->rgPrimColorG = 220;
    this->rgPrimColorB = 80;
    this->rgPrimColorA = 255;
    this->rgEnvColorR = 130;
    this->rgEnvColorG = 30;
    this->rgEnvColorB = 0;
    this->rgEnvColorA = 0;

    return 1;
}

void EffectSsGFire_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    UNK_PTR textures[] = {
        gEffectFireFootprintTex1, gEffectFireFootprintTex2, gEffectFireFootprintTex3, gEffectFireFootprintTex4,
        gEffectFireFootprintTex5, gEffectFireFootprintTex6, gEffectFireFootprintTex7, gEffectFireFootprintTex8,
    };
    s16 texIdx = (this->rgTexIdx / 100) % 7;

    EffectSs_DrawGEffect(globalCtx, this, textures[texIdx]);
}

void EffectSsGFire_Update(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    this->rgTexIdx += this->rgTexIdxStep;
}
