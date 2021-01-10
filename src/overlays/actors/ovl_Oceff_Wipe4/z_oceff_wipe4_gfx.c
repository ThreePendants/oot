#include "z_oceff_wipe4.h"
#include "objects/gameplay_keep/gameplay_keep.h"

static u32 tex0[] = {
    0x00061507, 0x00000000, 0x295a2b08, 0x10030f03, 0x0d070006, 0x00031625, 0x3f230012, 0x79590000, 0x00102c2a,
    0x254a1b0e, 0xaff66600, 0x00467e29, 0x08020000, 0x03383e0b, 0x0501000a, 0x31211c05, 0x00031c27, 0x4ca92f13,
    0xb2ef5500, 0x057ebf37, 0x00000000, 0x0e493f13, 0x00000002, 0x335c3e03, 0x00000e07, 0x3c761200, 0x447e2200,
    0x00426710, 0x00000000, 0x071c2208, 0x00000168, 0xe18f0f00, 0x00060e00, 0x0a100000, 0x0514022d, 0x1b020400,
    0x00000000, 0x093a3f0a, 0x050010ae, 0xda360000, 0x00070500, 0x00000000, 0x00001461, 0x3e050024, 0x24000000,
    0x184e3755, 0x9132043c, 0x2f000000, 0x12020a54, 0x3c000200, 0x00000f3e, 0x2b041159, 0x2c000000, 0x030b22ce,
    0xf9420000, 0x00000301, 0x371160ef, 0xac6d2b00, 0x00000008, 0x05000d27, 0x06000000, 0x00001a91, 0x760b0000,
    0x000b030a, 0x747db0bd, 0xbda31d00, 0x00000000, 0x00000000, 0x00000511, 0x01000209, 0x03020015, 0x583a0010,
    0xc1e0892d, 0x532d0000, 0x03160600, 0x00050001, 0x15142e4e, 0x07000500, 0x100d004c, 0xb65c001b, 0xb2df9417,
    0x00000020, 0x57420400, 0x45882f00, 0x18093b3e, 0x01182f0d, 0x1405003f, 0xb75b001e, 0x5dc2e14f, 0x00000161,
    0xbc4a005a, 0xecf84a00, 0x0011330f, 0x0044591c, 0x01001c7c, 0xb122001f, 0x5de4ff71, 0x00000177, 0xba3218d9,
    0xffc41700, 0x1e7b5a1c, 0x2b769635, 0x0044d5fa, 0x9e000530, 0xc7ffce35, 0x00000035, 0x663441cf, 0xc9380000,
    0x3d733c28, 0x3e709726, 0x0086faf1, 0x9b170d4c, 0xc9812700, 0x000e1a02, 0x4c642544, 0x2b000000, 0x0d0e0508,
    0x0a252f03, 0x00335297, 0xc75b014e, 0x77470600, 0x00160f00, 0x3a350016, 0x29070000, 0x0c3a3911, 0x00000003,
    0x0100004b, 0x8f4b051c, 0x7f6c1c00, 0x00000000, 0x00000437, 0x2e030001, 0x2a6e6b2c, 0x0604000e, 0x0b000004,
    0x19350814, 0x3e63813d, 0x13000000, 0x00000117, 0x06000000, 0x14362911, 0x312e021f, 0x13000000, 0x010c000c,
    0x10b9ef72, 0x2d010000, 0x040c0c10, 0x02000000, 0x33410306, 0x3b30071d, 0x07000000, 0x00000000, 0x1bc2a129,
    0x0d000000, 0x050e1112, 0x0100002e, 0xd2c22e00, 0x21593403, 0x00000000, 0x01010000, 0x0e451b00, 0x00000000,
    0x0000060d, 0x00000061, 0xffea2e00, 0x3da04200, 0x00000000, 0x06140b00, 0x00040200, 0x00000000, 0x00061b0c,
    0x00000037, 0x8d620500, 0x2a8f5801, 0x00000000, 0x082e3404, 0x00000000, 0x00000003, 0x0a201b02, 0x00000000,
    0x06000000, 0x11826503, 0x00060400, 0x07303402, 0x07010007, 0x2f1e0b0a, 0x09080000, 0x03000000, 0x00000000,
    0x07452500, 0x0e361100, 0x000b0a00, 0x06000018, 0x3e170600, 0x00060f0d, 0x3e190000, 0x00000000, 0x00000000,
    0x21360700, 0x00000000, 0x00000007, 0x09000000, 0x0a857124, 0x703c0000, 0x01000000, 0x00000000, 0x08050000,
    0x00000000, 0x00000000, 0x00000000, 0x32d97112, 0x4a1b0001, 0x02050000, 0x00000000, 0x021a0a00, 0x00000613,
    0x07000000, 0x00000000, 0x1e5d1700, 0x04000000, 0x37550400, 0x00000000, 0x14300600, 0x00003e5b, 0x08000000,
    0x00000000, 0x2f2f0000, 0x00000007, 0x90840300, 0x0f070000, 0x06070000, 0x00055a62, 0x00000000, 0x00000020,
    0xa77b0700, 0x0106000f, 0x612d0006, 0x1b030000, 0x00000001, 0x0000211a, 0x00000000, 0x0000002e, 0x944a0103,
    0x3b390200, 0x04000011, 0x14000005, 0x302f0d10, 0x01000000, 0x00000000, 0x00000009, 0x10000015, 0x5d290000,
    0x00000015, 0x09000027, 0x73510f09, 0x37410700, 0x00061408, 0x00000000, 0x25582d09, 0x12020e03, 0x0c070007,
    0x00031627, 0x41240011, 0x795b0000, 0x00102d29, 0x244b1c0d, 0xb0f76600, 0x00467c28, 0x08020000, 0x02383e0b,
    0x0401000a, 0x32231c04, 0x00031b28, 0x4ca83112, 0xb2ef5500, 0x057ebe38, 0x00000000, 0x0d493d13, 0x00000002,
    0x325c3f03, 0x00000e08, 0x3d761200, 0x457f2200, 0x0043660f, 0x00000000, 0x071d2208, 0x00000168, 0xe1901000,
    0x00070e00, 0x09110000, 0x0515022d, 0x1b020400, 0x00000000, 0x093b3e09, 0x050011ae, 0xd9370000, 0x00070500,
    0x00000000, 0x00001462, 0x3e050024, 0x25000000, 0x184e3554, 0x9431043c, 0x2e000000, 0x12010955, 0x3c000300,
    0x0000103e, 0x2b04115a, 0x2d000000, 0x030b22ce, 0xf9420000, 0x00000301, 0x361161ef, 0xac6b2b00, 0x00000008,
    0x05000d27, 0x07000000, 0x00001a8f, 0x760b0000, 0x000b030a, 0x727db1bd, 0xbca21c00, 0x00000000, 0x00000000,
    0x00000610, 0x00000208, 0x03030016, 0x57390010, 0xc1e1892e, 0x522c0000, 0x03160600, 0x00060001, 0x14142f4e,
    0x07000500, 0x100e004b, 0xb55c001b, 0xb0dd9416, 0x0000001f, 0x57430500, 0x468a3000, 0x16093b3e, 0x01192f0d,
    0x1405003e, 0xb65b001d, 0x5cc1e04e, 0x0000005e, 0xbc4b0058, 0xebfa4b00, 0x0011340e, 0x0045591c, 0x02001c7c,
    0xb223001e, 0x5ce5ff71, 0x00000176, 0xb93216d8, 0xffc21700, 0x1d7b5b1c, 0x2b759636, 0x0041d4fc, 0x9d000530,
    0xc7ffce36, 0x00000036, 0x663540ce, 0xc6360000, 0x3c743e29, 0x3e719827, 0x0085faf0, 0x9b160d4e, 0xc9812600,
    0x000f1a03, 0x4b642646, 0x2b000000, 0x0d0e0608, 0x0a253002, 0x00345299, 0xc85b014e, 0x75470600, 0x00160f00,
    0x39350015, 0x29070000, 0x0c3a3911, 0x00000003, 0x0100004b, 0x914b051e, 0x7d6c1c01, 0x00000000, 0x00000437,
    0x2e030001, 0x2a6f6a2a, 0x0604000e, 0x0b000003, 0x1a350814, 0x3e63813e, 0x13000000, 0x00000118, 0x07000000,
    0x13382911, 0x302e0320, 0x14000000, 0x010d000c, 0x0fb9ee73, 0x2f000000, 0x040b0c11, 0x02000000, 0x36440307,
    0x3b30071d, 0x07000000, 0x00000000, 0x1abf9f29, 0x0e000000, 0x050f1112, 0x0100002d, 0xd3c42b00, 0x22593404,
    0x00000000, 0x01010000, 0x0e451b00, 0x00000000, 0x0000070c, 0x00000061, 0xffed2f00, 0x3ea04300, 0x00000000,
    0x05140b00, 0x00030200, 0x00000000, 0x00061c0b, 0x00000037, 0x8f640500, 0x2a8f5901, 0x00000000, 0x082d3504,
    0x00000000, 0x00010003, 0x0a201b02, 0x00000000, 0x07000000, 0x11826503, 0x00050400, 0x072f3503, 0x07010007,
    0x2f1e0c0b, 0x09080000, 0x03000000, 0x00000000, 0x07462500, 0x0e361100, 0x000b0900, 0x04000018, 0x3e160600,
    0x00060f0b, 0x3d190000, 0x00000000, 0x00000000, 0x21370600, 0x00000000, 0x00000007, 0x09000000, 0x0b866f22,
    0x713c0000, 0x02000000, 0x00000000, 0x08060000, 0x00000000, 0x00000000, 0x00000000, 0x30d76f12, 0x4b1a0001,
    0x02050000, 0x00000000, 0x021a0a00, 0x00000714, 0x08000000, 0x00000000, 0x1e5c1700, 0x03000000, 0x36560400,
    0x00000000, 0x15300600, 0x00003f5d, 0x07000000, 0x00000000, 0x2e2f0000, 0x00000008, 0x8f840300, 0x0f060000,
    0x06070000, 0x00065b61, 0x00000000, 0x00000020, 0xa67c0700, 0x0006000e, 0x612d0006, 0x1b030000, 0x00000001,
    0x0001211b, 0x00000000, 0x0000002f, 0x93490103, 0x3b390200, 0x04000011, 0x13000005, 0x2f2e0c11, 0x02000000,
    0x00000000, 0x00000008, 0x14030015, 0x5d2c0000, 0x00000115, 0x08000027, 0x724f0f0a, 0x353d0600,
};

static Vtx vertices[] = {
    VTX(88, 121, 0, 819, 1024, 0xFF, 0xFF, 0xFF, 0x00),    VTX(243, 176, 1000, 717, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(143, 46, 0, 614, 1024, 0xFF, 0xFF, 0xFF, 0x00),    VTX(300, 0, 1000, 512, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 150, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0x00),    VTX(93, 285, 1000, 922, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-88, 121, 0, 1229, 1024, 0xFF, 0xFF, 0xFF, 0x00),  VTX(-93, 285, 1000, 1126, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-143, 46, 0, 1434, 1024, 0xFF, 0xFF, 0xFF, 0x00),  VTX(-243, 176, 1000, 1331, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-143, -46, 0, 1638, 1024, 0xFF, 0xFF, 0xFF, 0x00), VTX(-300, 0, 1000, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-88, -121, 0, 1843, 1024, 0xFF, 0xFF, 0xFF, 0x00), VTX(-243, -176, 1000, 1741, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -150, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0x00),   VTX(-93, -285, 1000, 1946, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(88, -121, 0, 205, 1024, 0xFF, 0xFF, 0xFF, 0x00),   VTX(93, -285, 1000, 102, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -150, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0x00),      VTX(93, -285, 1000, 2150, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(143, -46, 0, 410, 1024, 0xFF, 0xFF, 0xFF, 0x00),   VTX(243, -176, 1000, 307, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx sTextureDL0[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadMultiBlock(gEffectUnknown12Tex, 0x100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                       G_TX_NOMIRROR | G_TX_NOMIRROR, 5, 5, 1, 15),
    gsDPSetPrimColor(0x00, 0x00, 170, 255, 255, 255),
    gsDPSetEnvColor(0, 150, 0, 128),
    gsSPEndDisplayList(),
};

static Gfx sTexture1DL[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadMultiBlock(gEffectUnknown12Tex, 0x100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                       G_TX_NOMIRROR | G_TX_NOMIRROR, 5, 5, 1, 0),
    gsDPSetPrimColor(0x00, 0x00, 255, 170, 255, 255),
    gsDPSetEnvColor(120, 0, 100, 128),
    gsSPEndDisplayList(),
};

static Gfx sTexture2DL[] = {
    gsDPPipeSync(),
    gsDPLoadTextureBlock(tex0, G_IM_FMT_I, G_IM_SIZ_8b, 32, 64, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                         G_TX_NOMIRROR | G_TX_NOMIRROR, 5, 6, 14, 1),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, ENV_ALPHA, TEXEL1, TEXEL0, 0, ENVIRONMENT, TEXEL1, PRIMITIVE, ENVIRONMENT,
                       COMBINED, ENVIRONMENT, COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(AA_EN | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | FORCE_BL |
                          GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1),
                      G_RM_AA_XLU_SURF2),
    gsSPClearGeometryMode(G_TEXTURE_ENABLE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    //! @bug : gsSPEndDisplayList() is missing so the next dlist will execute as well
};

static Gfx sFrustrumDl[] = {
    gsSPVertex(vertices, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 5, 0, 0, 5, 1, 0, 0),
    gsSP2Triangles(6, 7, 4, 0, 7, 5, 4, 0),
    gsSP2Triangles(8, 9, 6, 0, 9, 7, 6, 0),
    gsSP2Triangles(10, 11, 8, 0, 11, 9, 8, 0),
    gsSP2Triangles(12, 13, 10, 0, 13, 11, 10, 0),
    gsSP2Triangles(14, 15, 12, 0, 15, 13, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 15, 14, 0),
    gsSP2Triangles(20, 21, 16, 0, 21, 17, 16, 0),
    gsSP2Triangles(2, 3, 20, 0, 3, 21, 20, 0),
    gsSPEndDisplayList(),
};
