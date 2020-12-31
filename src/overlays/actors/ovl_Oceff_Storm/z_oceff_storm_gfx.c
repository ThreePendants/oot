#include "z_oceff_storm.h"
#include "objects/gameplay_keep/gameplay_keep.h"

static u32 tex0[] = {
    0x2F6E6F59, 0x6197B3CC, 0xC8AD8E6C, 0x5333170A, 0x17366173, 0x86ABC7C6, 0xA9928C7E, 0x55496341, 0x40705B59,
    0x79A5DAE8, 0xC9A5927F, 0x6F50270D, 0x17304F6C, 0x8BAAC3B9, 0x9189A0A5, 0x854A2F1F, 0x33808E74, 0x709BB7CC,
    0xC6B18E69, 0x4627100D, 0x21406880, 0x9BC2DAC1, 0x92808378, 0x514B7350, 0x386E6768, 0x80AAE1E4, 0xC6A0866D,
    0x644B2513, 0x2541617F, 0xA2BBD7C6, 0x9C97B8B9, 0x86322A2C, 0x3381A28F, 0x82A0BECA, 0xCBBF956B, 0x40210A15,
    0x2F4D718F, 0xB1D7E8BA, 0x856B706D, 0x49447654, 0x366C6C71, 0x87ADDFD8, 0xB8967B68, 0x543A1B15, 0x32537094,
    0xB5D1E5CF, 0xAEA9C9CD, 0x9F3C3235, 0x3883AEA8, 0x98A4C1C5, 0xC9CCA576, 0x45210D1D, 0x3C5D7E9F, 0xC3E7EFAF,
    0x785B5C5B, 0x3935684F, 0x36646A79, 0x8FADD5C9, 0xA6877561, 0x40271721, 0x406180A5, 0xC7E2EED5, 0xC1BDCACD,
    0xAD46333D, 0x3A82B5BB, 0xADADC5BD, 0xC4D5B282, 0x532C152A, 0x4B6D8FB0, 0xD5F4F4AD, 0x73534F4D, 0x2D28584D,
    0x3C5E6981, 0x9AB0CCBB, 0x987B775E, 0x2D151B2F, 0x507192B8, 0xDAF0F2D6, 0xD0CAC1C0, 0xB5573241, 0x4180B2C3,
    0xBFB9C8B3, 0xB9CCB085, 0x5E392138, 0x5B7DA1C3, 0xE5FBF8BC, 0x805B534F, 0x383C605E, 0x5363738F, 0xA9B7CAB1,
    0x8E79805E, 0x1F10233F, 0x6081A4CA, 0xEAFAF1CF, 0xD4CBB0B2, 0xC06E3246, 0x4D7BA9C3, 0xC8C4CAAB, 0xA5AF9777,
    0x62463249, 0x6B90B4D4, 0xF2FEFBD3, 0xA47B6B69, 0x686B7D7E, 0x777D869D, 0xB4C3C6A8, 0x8E888E5F, 0x1B173050,
    0x7292B8DC, 0xF6FFE7C0, 0xC2B99CAC, 0xC682334E, 0x57779EBB, 0xCBCFD0A4, 0x8D856E58, 0x5B514459, 0x7BA1C6E5,
    0xFAFFFEE9, 0xC9A48D8F, 0x8C868E92, 0x8C999DA8, 0xBCCABE9F, 0x99A4A065, 0x23254060, 0x83A4CBEB, 0xFCFFDDAC,
    0xA69D8CAF, 0xC8993A56, 0x617998B5, 0xCBD7D29F, 0x765B4138, 0x505D596E, 0x8CB2D6F1, 0xFEFFFEF8, 0xE7C5B0AD,
    0xA295979B, 0x99AFB3B2, 0xC3CAB197, 0xA9C1B36F, 0x32354F72, 0x94B5DCF6, 0xFFFFD99F, 0x8E898BB8, 0xC3A84A5D,
    0x6E819AB5, 0xCEDECF98, 0x65402323, 0x4B6B7283, 0x9EC1E4FA, 0xFFFFFCF7, 0xF6DAC7C2, 0xAC96929D, 0xA2BFC5BD,
    0xC9C6A192, 0xB6D7C682, 0x49466281, 0xA4C4ECFD, 0xFFFFDFAD, 0x95919DBE, 0xB8B26768, 0x8190A4BC, 0xD5DFC38C,
    0x61402328, 0x547D8C99, 0xADCFEBFA, 0xFEFFFAF1, 0xF3DCD0C8, 0x9C808AA2, 0xA9C9D4CA, 0xD0C09D94, 0xB9DCD7A2,
    0x685D7290, 0xB2CFF4FF, 0xFFFFEBC6, 0xADA2AABE, 0xB1B98781, 0x99A2B1C6, 0xDEDBAD7E, 0x6957393A, 0x6995A8AF,
    0xBED7E7EF, 0xF7FEFAED, 0xE8D1CEC1, 0x907595AA, 0xB3CEDFD7, 0xD5B69F99, 0xADCEE4C4, 0x8B7482A0, 0xBFCFF2FC,
    0xFEFFF7DD, 0xC7B5B2B5, 0xB0B69390, 0xADB8C0D4, 0xE9D69970, 0x74745656, 0x82AEC0C0, 0xC9D9DBDC, 0xEAF8FAEB,
    0xDEC9C4B8, 0x8F71A5B5, 0xC1D6E7E4, 0xD7AFA39D, 0x9CBAECE1, 0xAD8A93AF, 0xC5C6E1F1, 0xFAFEFCED, 0xDAC6B0A6,
    0xACAD9094, 0xB5CDD2E3, 0xF3D38D69, 0x808A6D70, 0xA0C7CECB, 0xD1D8CCC6, 0xD4EFF9E9, 0xD5C3BCAD, 0x937AB7BE,
    0xCBDFEFEE, 0xD3A5A097, 0x88A4EDF6, 0xC39CA2BF, 0xC4B5C9DE, 0xEEF7F9ED, 0xDAC4A092, 0xA0967C8B, 0xB1DFE4EE,
    0xF9DA926C, 0x83927C84, 0xBCD7D5D5, 0xD8D5C0B2, 0xB9DDF4E1, 0xCFBCB4A4, 0xA190C5C3, 0xCFE3F4F6, 0xCD9B9388,
    0x7899E8F9, 0xCCA8B3CD, 0xBDA0ACC3, 0xDBEDF4E4, 0xD7C09481, 0x8B7C5B71, 0xABEDEDF0, 0xFCE6A97A, 0x818B8198,
    0xD1DDD5DC, 0xDDD2B9A4, 0x9FCCECD5, 0xCCBAAF9F, 0xACAACAC9, 0xDAEBF8FA, 0xC68F7E72, 0x6F98E2F1, 0xCBB1C2D8,
    0xB49191A8, 0xC6E4EAD7, 0xCCBB8B75, 0x7867495E, 0xADF6EFE5, 0xF7F1C692, 0x817F84A9, 0xDEDBD2E3, 0xDECCB299,
    0x8ABBE1C7, 0xCAB6A7A4, 0xB5C1C6C4, 0xE1F4FCFC, 0xC3876A5E, 0x6C98DAE8, 0xC4B8CFDA, 0xA9858399, 0xBBDEDCC9,
    0xC2B2846D, 0x6D5D4357, 0xBCFBEAD2, 0xE7F7E1AF, 0x85798DB9, 0xDFD2D1E5, 0xD6BCA48C, 0x81B1DABF, 0xCBB399A9,
    0xBFC9B1B1, 0xE1FAFEFE, 0xC8895F55, 0x6D9DD8DF, 0xC1C2D3D0, 0x9E80829D, 0xBFDACDB7, 0xB8B0846E, 0x6E5E4061,
    0xD3FEE5BC, 0xCFECF1CF, 0x9882A0CA, 0xDAC7CEDD, 0xC19F8B7D, 0x82B5D7C0, 0xCBB288A1, 0xB4B98E8F, 0xD9FEFFFE,
    0xD697695C, 0x729FDADB, 0xC5C8C9BC, 0x928392B5, 0xCCD3BFA8, 0xB3B49178, 0x77603C76, 0xE6FFE6AB, 0xB1D4EDE6,
    0xB094B9D3, 0xD1C0C6CB, 0xA37E6F6E, 0x92C0D5C3, 0xCAAC758F, 0x9F996568, 0xC8FEFFFF, 0xE6B28271, 0x7BA5DFD9,
    0xC8C7B9A0, 0x878CAECF, 0xD2CBB69D, 0xB2B9A485, 0x7D5C368E, 0xF2FFE89F, 0x95B8DAF3, 0xC9A9CCD5, 0xC7BCBDB3,
    0x84615364, 0xA6C7D3C9, 0xC3A06472, 0x8372444B, 0xB1FAFFFF, 0xF4D1A890, 0x8BB1E1D6, 0xC9C09F87, 0x7A95C9DF,
    0xD2BDAF93, 0xB3C0B290, 0x7C5138A6, 0xFAFFE38F, 0x88A4BFF2, 0xDDBAD7D0, 0xC0BCB09A, 0x70534569, 0xB9C6CAC6,
    0xB18D5B51, 0x5F50363F, 0x92F0FFFF, 0xFDE9CDB5, 0xA8C1DECE, 0xC4B18B74, 0x6B98DBE4, 0xC9B0A48A, 0xA9BAB494,
    0x784541BD, 0xFCFAC978, 0x8DA8A6E6, 0xE9C6DAC5, 0xBDBFA385, 0x6E61537A, 0xC3BAB7B3, 0x97765141, 0x50433D4A,
    0x70D8FFFF, 0xFCF3E6D6, 0xC6D0D7C4, 0xBCA17E69, 0x5B90E1DF, 0xC3AD9C80, 0x93A3A38D, 0x723C4ECA, 0xF3EBA45D,
    0x99BC98D7, 0xF0CDD2BA, 0xB9BD9475, 0x7A7D6C91, 0xC2A6A29C, 0x7C634A3A, 0x50414A64, 0x55B9FDFF, 0xF7E6F1ED,
    0xE0DACEBA, 0xB394725F, 0x4A7AD6D8, 0xC1AF9C7C, 0x7D888680, 0x6E3557CA, 0xDECF7743, 0xA2CD99CF, 0xEFCFC7AF,
    0xB1B38063, 0x809482A2, 0xBC978E82, 0x6A5E4339, 0x4D3F5077, 0x4B90FBFF, 0xF1CEE6F1, 0xF0DFC3B0, 0xA8896454,
    0x3A60C2D1, 0xB9A99F85, 0x64656776, 0x743854BA, 0xBBAA4E2D, 0x9CCFA4D6, 0xEDCCBDA5, 0xA19F6D54, 0x7B998AA4,
    0xB79A8B71, 0x615E4145, 0x49384B79, 0x4F67F7FF, 0xEDB7CCDF, 0xEBDCB9A5, 0x9A7C5846, 0x2F43A4C3, 0xADA0A097,
    0x624B5576, 0x85504A95, 0x8C853A1F, 0x80BCBBDF, 0xE6CAB9A3, 0x92885E46, 0x65827B95, 0xA59B9778, 0x5C57546E,
    0x5B333D67, 0x574DF0FF, 0xEFACAFBD, 0xD2DAAD98, 0x896E4D39, 0x282882AD, 0x9D9298A0, 0x7E5F6188, 0xA27A516C,
    0x5F6A3817, 0x5C99CEE7, 0xDFCBBDA8, 0x8E7D5E48, 0x4D5E6079, 0x8D929B8C, 0x584E75A1, 0x86412C4B, 0x583AE8FF,
    0xF5B99292, 0xB3D3A48A, 0x775E412C, 0x21196191, 0x8F8187A4, 0x9A857D9F, 0xBFA9724E, 0x3C5F3A15, 0x3871DAE8,
    0xDAD1C6B3, 0x9B887055, 0x4139405D, 0x73859FA4, 0x584E9ECC, 0xB7632338, 0x513ADAFF, 0xFBCA7E6A, 0x90CDA17F,
    0x6B533821, 0x1B10457A, 0x8C807A9F, 0xB7AB96AD, 0xCECC9C4A, 0x2C624013, 0x2151E1DE, 0xD7D2CEBC, 0xAEA28A68,
    0x411F324E, 0x536F9FB9, 0x6C6FC7ED, 0xE1872736, 0x4D3FC6FE, 0xFEDA724A, 0x72C2A57F, 0x6E59361D, 0x1710356D,
    0x918A7D9B, 0xCFC09FA7, 0xC7D2B854, 0x326E4113, 0x2540DCD5, 0xD5CCD0BB, 0xBEB9A378, 0x481D4055, 0x4D63A2C1,
    0x939FE2FC, 0xFAA42F3F, 0x4B45AAFB, 0xFFE46838, 0x63B5B091, 0x87744F2A, 0x1B15356D, 0x97998EA9, 0xCBB58F8A,
    0xA4B9B553, 0x417D3F17, 0x2D39D8CF, 0xD1BECBB3, 0xC6C6B583, 0x4527606D, 0x576DAFBF, 0xB8C5F3FD, 0xFFB93541,
    0x494D86F2, 0xFEE25932, 0x5DB0BAA4, 0x9F967343, 0x21193C72, 0x9FA9A4BD, 0xB8926C62, 0x748A9549, 0x51873D19,
    0x3238D4CE, 0xC8ADC2A6, 0xC4C9C089, 0x3F2D7F8A, 0x6A7DBCB8, 0xD6E4FAFE, 0xFFC7333D, 0x454A63DB, 0xF8D34D36,
    0x61ADC0B2, 0xB1B3955E, 0x2C214477, 0xA4B7BACC, 0x9E614438, 0x43516436, 0x5F83391B, 0x3338CCCF, 0xBEA0BC9D,
    0xC2C4C990, 0x403A99A8, 0x8090C5B1, 0xE9F1FCFF, 0xFDD63238, 0x394445BB, 0xDCB14540, 0x73B5C3BC, 0xBFC6AC72,
    0x3C304D7B, 0xA5BCC9DA, 0x7E362117, 0x1D27352F, 0x5F723821, 0x3238C2D2, 0xB59DB99F, 0xC1C0D09B, 0x4E46A9BC,
    0x9DA9CAB5, 0xEDF5FEF9, 0xF6E43236, 0x2D353592, 0xB08D544D, 0x88B9C3BF, 0xC0C4A97A, 0x50455579, 0xA2BCCDDF,
    0x74271319, 0x32251738, 0x53553928, 0x3238B5D2, 0xB19DBCAB, 0xC0BFD8A9, 0x624EADC9, 0xB7C3D2C3, 0xEFFAFEEF,
    0xEDF03536, 0x23233569, 0x7F797259, 0x99B5C3C3, 0xBBB2977C, 0x6C65637B, 0x9FB9CEE3, 0x862F1932, 0x60401040,
    0x40393632, 0x383FA7D2, 0xB5A3BFB9, 0xC0C3E1B8, 0x7759A7CF, 0xCCD9DFDA, 0xF2FEFDE6, 0xE8F23539, 0x1F19324A,
    0x50759267, 0xA5ADC5CA, 0xB59C827D, 0x8A867680, 0x9EB8CCE8, 0xA03D2F57, 0x9664153D, 0x2D283538, 0x414A98CF,
    0xBAADBEC0, 0xC3CFE7C3, 0x8A639FCC, 0xD8E6E8EB, 0xF6FFFDE5, 0xEBEA3238, 0x1D173035, 0x3D7DA973, 0xA9A4C5CE,
    0xAB82778A, 0xA9A5888A, 0xA4BCC6E6, 0xBA4F548A, 0xC6881F33, 0x302D3239, 0x535C8AC9, 0xBAB6BAC1, 0xCBD6E6CB,
    0x967195C3, 0xD7E6EEF8, 0xFAFFFDEB, 0xF1D42A35, 0x1F25322F, 0x417DAF7D, 0xA6ACC0CE, 0xA27583A9, 0xC9BF9898,
    0xB0BEBEE1, 0xCC6585BB, 0xE7A53832, 0x4E402F38, 0x697084C4, 0xB3BEB4BD, 0xD5D7E1CC, 0x9F7E92BC, 0xD2E4EFFB,
    0xFEFFFEF6, 0xF4B5212C, 0x273C3A30, 0x4A70AC89, 0xA3B7BCCD, 0x9F7499C8, 0xE1CFA3A4, 0xBCBDB0D7, 0xD87DB5DF,
    0xF9BC604B, 0x7454323D, 0x7C7D7FBF, 0xAAC1B1BE, 0xDFD8D9CB, 0xA48994B5, 0xCEE1E6F1, 0xFEFFFFFE, 0xF59F2D30,
    0x3D574D36, 0x5462A394, 0xA2C2B9CF, 0xA277AFE1, 0xF3DAABAF, 0xC4B69FCF, 0xE29FDBF6, 0xFECF947D, 0x9C65414D,
    0x898282BB, 0xA3C3B4C6, 0xE6DCD7C7, 0xA2919CB6, 0xCFE1DBE2, 0xFDFFFFFF, 0xF4A56358, 0x64725C3D, 0x5F5F9FA0,
    0xA1C9B9D4, 0xA47BB8ED, 0xFADFB5B9, 0xC8AE99CF, 0xECC3F3FE, 0xFEE1C3B2, 0xBB765B69, 0x8D7D90BA, 0xA9C6BCD5,
    0xEFE6DFC5, 0x9F97A8C0, 0xD9E7CDCC, 0xF9FFFFFF, 0xF6C09D90, 0x91866343, 0x6564A7AB, 0xA2CCC1DC, 0xA379B3E6,
    0xF6E1BEC4, 0xCBB2AADA, 0xF6E0FDFF, 0xFFF1E4D7, 0xCD877D8B, 0x8E7596BD, 0xB6C8C7E5, 0xF6F3E8C3, 0x9D9FB2CC,
    0xE5ECB9B3, 0xF4FFFFFE, 0xF9DDC6B9, 0xB78F6549, 0x646EB0B4, 0xA9D0CCE5, 0xA378A6D5, 0xEBE1C6CC, 0xCCBFC6E8,
    0xFBF5FEFF, 0xFFFBF4E9, 0xD99FA2A9, 0x947399BD, 0xC1CCD2F1, 0xFBFCF2C3, 0x9FA7BED5, 0xE9E4A299, 0xEBFEFFFD,
    0xFAEFE3D5, 0xCE8C6150, 0x657EB9BA, 0xAFD4D7EF, 0xA97D9AC3, 0xDFDCCCCF, 0xCACAE0F6, 0xFCF7F7FE, 0xFFFEF3EA,
    0xDAB5B9BA, 0xA2819EBB, 0xC8D0DEFA, 0xFFFFF6C6, 0xA7B3C5D1, 0xDECF887E, 0xD6F9FFFD, 0xF9EFE4D8, 0xD5846160,
    0x7396B9BD, 0xB9D7E3F7, 0xB48899B9, 0xD2D7D2CD, 0xC0CAF1FD, 0xF1E4E6F9, 0xFFFDEBE0, 0xD6BEBEBB, 0xA890A3BC,
    0xC9D7EAFE, 0xFFFFF6C9, 0xB4BDC2C0, 0xC2AC6963, 0xB6EBFEFD, 0xF8E6D7C9, 0xCC78687A, 0x8DA3ADBB, 0xC6DEEDFB,
    0xC79FAABB, 0xCAD3D8C9, 0xACB5E8F8, 0xDEC9CDEB, 0xFDFAE7DA, 0xCEB9B1AA, 0xA18F99B9, 0xCCE2F4FF, 0xFFFFF5CE,
    0xC0C0B7A6, 0x997E4948, 0x91D7FDFE, 0xF8E0CCC0, 0xBC6B7192, 0x9FA39CB5, 0xD1E7F6FE, 0xDDBCC5C6, 0xC9D5E3C4,
    0x8F92D1E8, 0xC6A9B0DB, 0xF7F6E7D6, 0xBCA3958D, 0x8A818AB1, 0xD3EDFBFF, 0xFFFFF2D2, 0xC5BCA489, 0x6F542F32,
    0x6BBEFBFF, 0xFADCC2B8, 0xAE657AA9, 0xA9988AB1, 0xDDF1FCFF, 0xEDD7DDD0, 0xCBDCEFBF, 0x716AB1D2, 0xAC9199CA,
    0xEEEDE6D0, 0xA884786E, 0x656373A1, 0xD6F4FFFE, 0xFFFFEFD3, 0xC3B0906F, 0x4E331B23, 0x4FA5F7FF, 0xF8D7B8B1,
    0xA56780B5, 0xAC8785B3, 0xE9FBFFFF, 0xFAEDEDD4, 0xCBE4F8BC, 0x57458FB9, 0x9B878FBC, 0xE1DFDFC4, 0x916D5F50,
    0x46455189, 0xCCF6FFFE, 0xFFFFE8CF, 0xBA9F8260, 0x3A1F101F, 0x4692F4FE, 0xF4D1B0AC, 0xA97382B3, 0xAB878CC2,
    0xF2FEFFFF, 0xFEFAF1CF, 0xC4E8FCB4, 0x453278A5, 0x968A92BB, 0xD6CED1B1, 0x7C604E3A, 0x323C4B74, 0xB9F1FFFE,
    0xFFFCE0C7, 0xAE927956, 0x30151027, 0x4888EDFA, 0xEFCBA9A6, 0xB28384AD, 0xB4969ED6, 0xFAFFFFFF, 0xFFFAE8C3,
    0xB6DDF4A9, 0x3925659A, 0x99959EBE, 0xCDBCBB9A, 0x6C5B452C, 0x25435772, 0xA8EBFFFE, 0xFFF6D2BB, 0xA2897250,
    0x2C131730, 0x5186E4F1, 0xE5C3A5A3, 0xBA9689A6, 0xC3ACB5EA, 0xFEFEFFFF, 0xFFF4D9B3, 0xA2C5DC95, 0x301F5B96,
    0xA4A5ACC3, 0xC3ABA183, 0x60574121, 0x1F4D6A82, 0xA6EAFFFF, 0xFDECC4AC, 0x96826D4E, 0x2F1B213F, 0x608BDBE2,
    0xD5BAA3A2, 0xBCA991A6, 0xD0C1CCF7, 0xFEFCFFFF, 0xFCE7C9A2, 0x8AA0B87A, 0x271F5998, 0xB5B7B9C8, 0xB99D8A70,
    0x59503A19, 0x1F577F9E, 0xBFEFFFFF, 0xF7DEB59B, 0x8A7D654D, 0x3D2F324E, 0x6F98D1CF, 0xC3AFA2A4, 0xBAB79DAE,
    0xD9D2E1FE, 0xFEFCFFFE, 0xF6D7B691, 0x7576895C, 0x1D21599F, 0xCAC8C3C9, 0xAC907964, 0x51453013, 0x215E92BD,
    0xDAF6FFFC, 0xEDCEA58A, 0x7D7A604E, 0x5549415E, 0x82A4CCBD, 0xADA09EA4, 0xB5C1ADBB, 0xE1DFEFFF, 0xFEFCFFFB,
    0xE9C5A581, 0x61505B3F, 0x192A60A8, 0xDAD1C9C6, 0x9E836D5D, 0x4936230D, 0x2361A5D9, 0xF1FDFEF7, 0xDDBC9476,
    0x6E745C53, 0x6B5F5371, 0x92B2C9AF, 0x9A8E919F, 0xB1C8BEC9, 0xE4E7F9FF, 0xFEFDFEF3, 0xDAB29471, 0x4F35352D,
    0x1D3869B3, 0xE1D2C9C0, 0x91776859, 0x3F251710, 0x2767B9EE, 0xFEFFFCEC, 0xCAA88364, 0x5E6C5859, 0x7D706282,
    0xA3C0C6A6, 0x8B7B7C8C, 0xACC9C6CB, 0xDEEBFEFF, 0xFFFFFAE6, 0xC7A08563, 0x3F231F27, 0x2A4874BB, 0xDFCBC3B7,
    0x8A736C5B, 0x3219131F, 0x2A69C6FA, 0xFFFFF6DC, 0xB8957253, 0x4E5F5963, 0x84797394, 0xB5C9C09F, 0x826F6570,
    0xA5C6BFBC, 0xCFECFFFF, 0xFFFDEFD5, 0xB48F7454, 0x3017172D, 0x3C5D82BD, 0xD5C0B9B0, 0x8C7D7A5B, 0x271B132F,
    0x306CD2FE, 0xFFFEEBCC, 0xA5856143, 0x3C505B6D, 0x837B82A5, 0xC3CFB897, 0x7E695751, 0x9CC0A9A0, 0xB8E6FFFF,
    0xFFF6E2C8, 0xA47D6346, 0x23101939, 0x4F7091C3, 0xCAB3ABA9, 0x99928955, 0x1F23173A, 0x3975D9FE, 0xFFF8DCBA,
    0x94765333, 0x2C415D73, 0x7D7D92B6, 0xD2D0AE92, 0x7A675136, 0x8EB38979, 0x9EDDFEFF, 0xFDECD4C1, 0x9B6F5039,
    0x190D2345, 0x6181A0C4, 0xC0A89FA6, 0xABA98F48, 0x1B271940, 0x437CCFF4, 0xF3E4C3A1, 0x82674023, 0x1F365E71,
    0x757F9DC1, 0xD8C4A18A, 0x705D4F25, 0x7C9F6756, 0x85C9EDF7, 0xEDD5C3B9, 0x8F5F3D2C, 0x1310274A, 0x688DA4BC,
    0xAD998FA0, 0xB2AD8236, 0x23463343, 0x4B85C4E6, 0xE2CDAE8D, 0x72563215, 0x15305F6F, 0x718AA9C6, 0xCEB99C84,
    0x64534E25, 0x658A5146, 0x78B3E1F2, 0xE2C1B4A9, 0x8759351F, 0x0D173350, 0x7292ACBA, 0x9E8F8792, 0xA0956725,
    0x2A5C534B, 0x5691BCD9, 0xD5BB9E7D, 0x6245250D, 0x13305F6F, 0x7999B8CA, 0xC0A89782, 0x5C4B5732, 0x517A504B,
    0x74AADCEF, 0xD7B4A497, 0x7E562D15, 0x1023405E, 0x7E9FB7B9, 0x95898F97, 0x90734619,
};

static Gfx sTextureDL[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetRenderMode(IM_RD | CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1),
                      G_RM_CLD_SURF2),
    gsDPSetEnvColor(50, 50, 0, 0),
    gsSPClearGeometryMode(G_TEXTURE_ENABLE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                       ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0),
    gsDPLoadTextureBlock(tex0, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                         G_TX_NOMIRROR | G_TX_NOMIRROR, 6, 6, 3, 1),
    gsDPLoadMultiBlock(tex0, 0x0, 1, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                       G_TX_NOMIRROR | G_TX_NOMIRROR, 6, 6, 2, 0),
    gsSPEndDisplayList(),
};

static Vtx vertices[] = {
    VTX(-35, 150, -35, 1792, 512, 0xFF, 0xFF, 0xFF, 0x7E), VTX(-35, 500, -35, 1792, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 500, -50, 1536, 0, 0xFF, 0xFF, 0xFF, 0x00),     VTX(35, 0, -35, 1280, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(50, 150, 0, 1024, 512, 0xFF, 0xFF, 0xFF, 0x00),    VTX(50, 0, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(35, 150, -35, 1280, 512, 0xFF, 0xFF, 0xFF, 0x7E),  VTX(35, 500, -35, 1280, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(50, 500, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0x00),      VTX(0, 0, -50, 1536, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 150, -50, 1536, 512, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-35, 0, -35, 1792, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-50, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0x00),    VTX(-50, 150, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-50, 500, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0x00),     VTX(-35, 0, 35, 256, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-35, 150, 35, 256, 512, 0xFF, 0xFF, 0xFF, 0x7E),   VTX(-50, 150, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-50, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0x00),       VTX(-35, 500, 35, 256, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-50, 500, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0x00),        VTX(0, 0, 50, 512, 1024, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 150, 50, 512, 512, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, 500, 50, 512, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(35, 0, 35, 768, 1024, 0xFF, 0xFF, 0xFF, 0x00),     VTX(35, 150, 35, 768, 512, 0xFF, 0xFF, 0xFF, 0x7E),
    VTX(35, 500, 35, 768, 0, 0xFF, 0xFF, 0xFF, 0x00),
};

static Gfx sCylinderTexDl[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(gEffectUnknownTex10, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                         G_TX_NOMIRROR | G_TX_NOMIRROR, 5, 5, 2, 13),
    gsDPLoadMultiBlock(gEffectUnknownTex11, 0x100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_NOMIRROR,
                       G_TX_NOMIRROR | G_TX_NOMIRROR, 5, 5, 1, 12),
    gsDPSetCombineLERP(TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, PRIMITIVE, ENVIRONMENT,
                       COMBINED, ENVIRONMENT, COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(AA_EN | Z_CMP | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_XLU | FORCE_BL |
                          GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1),
                      G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_TEXTURE_ENABLE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPEndDisplayList(),
};

static Gfx sCylinderDl[] = {
    gsSPVertex(vertices, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 4, 0),
    gsSP2Triangles(9, 10, 6, 0, 9, 6, 3, 0),
    gsSP2Triangles(10, 2, 7, 0, 10, 7, 6, 0),
    gsSP2Triangles(11, 0, 10, 0, 11, 10, 9, 0),
    gsSP2Triangles(3, 6, 4, 0, 0, 2, 10, 0),
    gsSP2Triangles(12, 13, 0, 0, 12, 0, 11, 0),
    gsSP2Triangles(13, 14, 1, 0, 13, 1, 0, 0),
    gsSP2Triangles(15, 16, 17, 0, 15, 17, 18, 0),
    gsSP2Triangles(16, 19, 20, 0, 16, 20, 17, 0),
    gsSP2Triangles(21, 22, 16, 0, 21, 16, 15, 0),
    gsSP2Triangles(22, 23, 19, 0, 22, 19, 16, 0),
    gsSP2Triangles(24, 25, 22, 0, 24, 22, 21, 0),
    gsSP2Triangles(25, 26, 23, 0, 25, 23, 22, 0),
    gsSP2Triangles(5, 4, 25, 0, 5, 25, 24, 0),
    gsSP2Triangles(4, 8, 26, 0, 4, 26, 25, 0),
    gsSPEndDisplayList(),
};
