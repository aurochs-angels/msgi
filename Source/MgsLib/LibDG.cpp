#include "stdafx.h"
#include "LibDG.hpp"
#include "Script.hpp"
#include "LibGV.hpp"
#include "Actor_GameD.hpp"
#include <assert.h>
#include "Renderer.hpp"
#include "Fs.hpp"
#include "pcx.hpp"
#include "WinMain.hpp"
#include "Actor_Debug.hpp"
#include "Actor_Movie.hpp"
#include "Menu.hpp"

#define LIBDG_IMPL true

void LibDGCpp_ForceLink() { }

#define REDIRECT_LIBDG_DATA 1

MGS_FUNC_NOT_IMPL(0x62130E, Actor* CC(DWORD scriptData, int scriptBinds, BYTE* pScript), Res_env_test_create_62130E);

// "Metal gear solid" animated - for demo end or disk swap screen
MGS_FUNC_NOT_IMPL(0x4B54AB, Actor* CC(DWORD scriptData, int scriptBinds, BYTE* pScript), Res_met_logo_create_4B54AB);

MGS_FUNC_NOT_IMPL(0x455BB8, Actor* CC(DWORD scriptData, int scriptBinds, BYTE* pScript), Res_sndtst_create_455BB8);

struct Actor_Open
{
    Actor mBase;
};


Actor* CC Res_open_create_486BD4(DWORD scriptData, int scriptBinds, BYTE* pScript)
{
    std::ignore = scriptData;
    std::ignore = scriptBinds;
    std::ignore = pScript;

    return &AddDebugActor()->mBase;
//    return Res_sndtst_create_455BB8(scriptData, scriptBinds, pScript);
//    return Res_env_test_create_62130E(scriptData, scriptBinds, pScript);
//    return Res_met_logo_create_4B54AB(scriptData, scriptBinds, pScript);
}
MGS_FUNC_IMPLEX(0x486BD4, Res_open_create_486BD4, false); // TODO


MGS_ARY(REDIRECT_LIBDG_DATA, 0x669AE0, Res_Init_Record, 512, gKnownResInitFuncs_669AE0,
{
    { 0x002A, 0, (ResInitFn)0x00519A61 }, /* Res_anime_pre_create_519A61 */              { 0x002F, 0, (ResInitFn)0x00519A9D }, /* Res_anime_pre_create_519A9D */
    { 0x0030, 0, (ResInitFn)0x00600135 }, /* Res_blst_ln_600135 */                       { 0x0009, 0, (ResInitFn)0x005FFC1C }, /* Res_blood_5FFC1C */
    { 0x000D, 0, (ResInitFn)0x005FF35B }, /* Res_d_bloods_5FF35B */                      { 0x0048, 0, (ResInitFn)0x005C5666 }, /* Res_blooddrp_create_5C5666 */
    { 0x0047, 0, (ResInitFn)0x005C5111 }, /* Res_bloodhzd_create_5C5111 */               { 0x000A, 0, (ResInitFn)0x005FEFB9 }, /* Res_splash_create_5FEFB9 */
    { 0x0025, 0, (ResInitFn)0x005F7EE2 }, /* Ret0_5F7EE2 */                              { 0x004A, 0, (ResInitFn)0x005683EF }, /* Res_liquid_bombled_create_5683EF */
    { 0x000E, 0, (ResInitFn)0x0051B59B }, /* Res_anime_create_breath */                  { 0x0012, 0, (ResInitFn)0x005FECC3 }, /* Res_bubble_t_create_5FECC3 */
    { 0x0013, 0, (ResInitFn)0x005FE85B }, /* Res_bubble_p_create_5FE85B */               { 0x000B, 0, (ResInitFn)0x005FE69B }, /* Res_bullet_create_5FE69B */
    { 0x0033, 0, (ResInitFn)0x0051B1CF }, /* Res_anime_pre_create_51B1CF */              { 0x003A, 0, (ResInitFn)0x005C4C4E }, /* Res_celofan2_create_5C4C4E */
    { 0x0040, 0, (ResInitFn)0x005C445E }, /* Res_celofan2_create_5C445E */               { 0x0039, 0, (ResInitFn)0x005FD769 }, /* Res_crsh_smk_create_5FD769 */
    { 0x0034, 0, (ResInitFn)0x0051B051 }, /* Res_anime_pre_create_51B051 */              { 0x0015, 0, (ResInitFn)0x00628ECC }, /* Res_goggle_create_628ECC */
    { 0x0016, 0, (ResInitFn)0x005BB2D5 }, /* Res_Equip_gglsight_create_5BB2D5 */         { 0x0037, 0, (ResInitFn)0x005DF33A }, /* Res_red_alr_create_5DF33A */
    { 0x0038, 0, (ResInitFn)0x005DF50D },                                                { 0x001C, 0, (ResInitFn)0x00628A91 }, /* Res_envmap3_create_628A91 */
    { 0x0001, 0, (ResInitFn)0x0043EC38 }, /* Res_blast_create_43EC38 */                  { 0x0003, 0, (ResInitFn)0x00441CF2 }, /* Res_fadeio_create_441CF2 */
    { 0x0004, 0, (ResInitFn)0x00441CF2 }, /* Res_fadeio_create_441CF2 */                 { 0x0045, 0, (ResInitFn)0x005C41C3 }, /* Res_famaslit_create_5C41C3 */
    { 0x0010, 0, (ResInitFn)0x005ABCB7 }, /* Res_demoasi_create_5ABCB7 */                { 0x0044, 0, (ResInitFn)0x005E7FC9 },
    { 0x0019, 0, (ResInitFn)0x0051AED6 }, /* Res_anime_pre_create_51AED6 */              { 0x0042, 0, (ResInitFn)0x0061FFFF }, /* Res_gas_efct_create_61FFFF */
    { 0x0022, 0, (ResInitFn)0x005BB23E }, /* Res_Equip_gmsight_create_5BB23E */          { 0x0046, 0, (ResInitFn)0x006288F0 }, /* Res_realshdw_create_6288F0 */
    { 0x003B, 0, (ResInitFn)0x005C3D78 }, /* Res_inverlt_create_5C3D78 */                { 0x003F, 0, (ResInitFn)0x005C3580 }, /* Res_inverlt2_create_5C3580 */
    { 0x0017, 0, (ResInitFn)0x0062862E }, /* Res_Takabe_goggleir_create_62862E */        { 0x0018, 0, (ResInitFn)0x005BB2D5 }, /* Res_Equip_gglsight_create_5BB2D5 */
    { 0x0020, 0, (ResInitFn)0x005C31B7 }, /* Res_Kojo_mgrexlzr_create_5C31B7 */          { 0x004B, 0, (ResInitFn)0x005FD23A }, /* Res_mg_room_create_5FD23A */
    { 0x000C, 0, (ResInitFn)0x0051A97A }, /* Res_anime_pre_create_51A97A */              { 0x0028, 0, (ResInitFn)0x0062852B }, /* Res_sepia_create_62852B */
    { 0x0011, 0, (ResInitFn)0x0051AD2A }, /* Res_anime_pre_create_51AD2A */              { 0x0049, 0, (ResInitFn)0x00627B86 }, /* Res_windcrcl_create_627B86 */
    { 0x0041, 0, (ResInitFn)0x005C2454 }, /* Res_ninjalzr_create_5C2454 */               { 0x002D, 0, (ResInitFn)0x005ABC28 }, /* Res_katana_create_5ABC28 */
    { 0x0035, 0, (ResInitFn)0x0051AB83 }, /* Res_anime_pre_create_51AB83 */              { 0x0036, 0, (ResInitFn)0x0051AC56 }, /* Res_anime_pre_create_51AC56 */
    { 0x001A, 0, (ResInitFn)0x005BAC0B }, /* Res_Equip_kogaku2_create_5BAC0B */          { 0x001B, 0, (ResInitFn)0x005BB0B2 }, /* Res_kogaku2_create_5BB0B2 */
    { 0x001D, 0, (ResInitFn)0x005E1D68 }, /* Res_plasma_create_5E1D68 */                 { 0x0024, 0, (ResInitFn)0x005E1E8B }, /* Res_plasma_create_5E1E8B */
    { 0x0007, 0, (ResInitFn)0x00519E54 }, /* Res_anime_pre_create_519E54 */              { 0x0029, 0, (ResInitFn)0x0063F7DF }, /* Res_rfsight_create_63F7DF */
    { 0x0014, 0, (ResInitFn)0x005B9F52 }, /* Res_Equip_scope_create_5B9F52 */            { 0x001F, 0, (ResInitFn)0x006282D3 }, /* Res_sepia_6282D3 */
    { 0x000F, 0, (ResInitFn)0x005AB3EA }, /* Res_Enemy_demokage_create_5AB3EA */         { 0x0032, 0, (ResInitFn)0x005C22AC }, /* Res_Kojo_m1e1smke_create_5C22AC */
    { 0x002C, 0, (ResInitFn)0x004438CF }, /* Res_sight_create_4438CF */                  { 0x0008, 0, (ResInitFn)0x00519DEC }, /* Res_anime_pre_create_519DEC */
    { 0x0002, 0, (ResInitFn)0x00519A25 }, /* Res_anime_pre_create_519A25 */              { 0x0031, 0, (ResInitFn)0x005FD006 }, /* Res_smke_ln_create_5FD006 */
    { 0x003C, 0, (ResInitFn)0x00627ECA }, /* Res_spark2_create_627ECA */                 { 0x003D, 0, (ResInitFn)0x005FCA8F }, /* Res_spark_create_5FCA8F */
    { 0x003E, 0, (ResInitFn)0x00519504 }, /* Res_anime_pre_create_519504 */              { 0x0026, 0, (ResInitFn)0x005197BC }, /* Res_anime_pre_create_5197BC */
    { 0x0027, 0, (ResInitFn)0x00519838 }, /* Res_anime_pre_create_519838 */              { 0x002E, 0, (ResInitFn)0x005FBEE0 }, /* Res_sub_room_create_5FBEE0 */
    { 0x0043, 0, (ResInitFn)0x00627C02 }, /* Res_sub_efct_create_627C02 */               { 0x0006, 0, (ResInitFn)0x00519E54 }, /* Res_anime_pre_create_519E54 */
    { 0x0005, 0, (ResInitFn)0x006154A7 }, /* Res_telop_create_6154A7 */                  { 0x004C, 0, (ResInitFn)0x006153CF }, /* Res_telop_create_6153CF */
    { 0x0021, 0, (ResInitFn)0x00627BFF }, /* Ret0_627BFF */                              { 0x0023, 0, (ResInitFn)0x005FF35B }, /* Res_d_bloods_create_5FF35B */
    { 0x002B, 0, (ResInitFn)0x005FF35B }, /* Res_d_bloods_create_5FF35B */               { 0x001E, 0, (ResInitFn)0x00627715 }, /* Res_windcrcl_create_627715 */
    { 0x40E9, 0, (ResInitFn)0x005FBB0A }, /* Res_10a_demo_create_5FBB0A */               { 0xE068, 0, (ResInitFn)0x005FAF3E }, /* Res_s11_objs_create_5FAF3E */
    { 0xD53C, 0, (ResInitFn)0x005FA06A }, /* Res_11b_demo_create_5FA06A */               { 0x153E, 0, (ResInitFn)0x005F9170 }, /* Res_11g_demo_create_5F9170 */
    { 0x9FFD, 0, (ResInitFn)0x00457B50 },                                                { 0x2D0A, 0, (ResInitFn)0x00457AC1 }, /* Res_second_457AC1 */
    { 0x566F, 0, (ResInitFn)0x004B3B01 }, /* Res_abst_create_4B3B01 */                   { 0x4974, 0, (ResInitFn)0x004B0578 }, /* Res_ab_demo1_create_4B0578 */
    { 0x4975, 0, (ResInitFn)0x004AC173 }, /* Res_ab_demo2_create_4AC173 */               { 0x05EF, 0, (ResInitFn)0x005F8FFA }, /* Res_a_shower_create_5F8FFA */
    { 0x2A90, 0, (ResInitFn)0x00627435 }, /* Res_gclarray_create_627435 */               { 0x02C4, 0, (ResInitFn)0x005AB396 }, /* Res_asiato_create_5AB396 */
    { 0x92BC, 0, (ResInitFn)0x005AA507 }, /* Res_asioto_create_5AA507 */                 { 0x9988, 0, (ResInitFn)0x004ABBC9 }, /* Res_at_create_4ABBC9 */
    { 0xF59E, 0, (ResInitFn)0x00514A19 }, /* Res_belong_create_514A19 */                 { 0x6B6C, 0, (ResInitFn)0x005682F7 }, /* Res_b_smoke_create_5682F7 */
    { 0x8185, 0, (ResInitFn)0x005F8E18 }, /* Res_blink_tx_create_5F8E18 */               { 0x1158, 0, (ResInitFn)0x005F8573 }, /* Res_mel10_create_5F8573 */
    { 0x4E95, 0, (ResInitFn)0x005F820B }, /* Res_blood_cl_create_5F820B */               { 0x6A4C, 0, (ResInitFn)0x005F7EE8 }, /* Res_blood_bl_create_5F7EE8 */
    { 0x9093, 0, (ResInitFn)0x005F7EE5 }, /* Ret0_5F7EE5 */                              { 0xF74B, 0, (ResInitFn)0x005142ED }, /* Res_boxall_5142ED */
    { 0x32FC, 0, (ResInitFn)0x006270F3 }, /* Res_breakobj_create_6270F3 */               { 0x6471, 0, (ResInitFn)0x00626FE4 }, /* Res_btn_chk_create_626FE4 */
    { 0x1A02, 0, (ResInitFn)0x005F781C }, /* Res_bubble_s_create_5F781C */               { 0x93B6, 0, (ResInitFn)0x004A2B6B }, /* Res_b_select_create_4A2B6B */
    { 0x7ECA, 0, (ResInitFn)0x0049FC71 }, /* Res_wire_create_49FC71 */                   { 0x6E90, 0, (ResInitFn)0x005A9076 }, /* Res_camera_5A9076 */
    { 0x56CC, 0, (ResInitFn)0x005A816F }, /* Res_camera2_create_5A816F */                { 0xA9C5, 0, (ResInitFn)0x005F5F72 }, /* Res_guncame_create_5F5F72 */
    { 0x7BC2, 0, (ResInitFn)0x00626EA8 }, /* Res_camshake_create_626EA8 */               { 0xB99F, 0, (ResInitFn)0x0049EA8B }, /* Res_cape_create_49EA8B */
    { 0x51C6, 0, (ResInitFn)0x00626C7D }, /* Res_cat_in_create_626C7D */                 { 0xF722, 0, (ResInitFn)0x0046BC36 }, /* Res_change_46BC36 */
    { 0x43A0, 0, (ResInitFn)0x006262A0 }, /* Res_ir_cens_create_6262A0 */                { 0x788D, 0, (ResInitFn)0x00625DC1 }, /* Res_chair_create_625DC1 */
    { 0x7A05, 0, (ResInitFn)0x00625D63 }, /* Res_cinema_create_625D63 */                 { 0x3C0C, 0, (ResInitFn)0x005A04D6 }, /* Res_jirai_5A04D6 */
    { 0xC6D7, 0, (ResInitFn)0x005A7099 }, /* Res_command_create_5A7099 */                { 0xCC45, 0, (ResInitFn)0x005F2E0F }, /* Res_dyncon_create_5F2E0F */
    { 0x22C6, 0, (ResInitFn)0x005A6143 }, /* Res_timer_create_5A6143 */                  { 0xECED, 0, (ResInitFn)0x004629FE },
    { 0xA3FB, 0, (ResInitFn)0x005F1A1D }, /* Res_crane_create_5F1A1D */                  { 0x8E60, 0, (ResInitFn)0x005F0B54 }, /* Res_crow_create_5F0B54 */
    { 0xBE79, 0, (ResInitFn)0x005F07A4 }, /* Res_death_sp_create_5F07A4 */               { 0x6A98, 0, (ResInitFn)0x00513F69 }, /* Res_dsmoke_513F69 */
    { 0x76BC, 0, (ResInitFn)0x0051368C }, /* Res_dsmoke2_51368C */                       { 0xB4E6, 0, (ResInitFn)0x00457974 }, /* Res_cancel_457974 */
    { 0xE97E, 0, (ResInitFn)0x0056781A }, /* Res_doll_create_56781A */                   { 0x3686, 0, (ResInitFn)0x0049B6AD }, /* Res_demosel_create_49B6AD */
    { 0x9F7D, 0, (ResInitFn)0x00511789 }, /* Res_display_create_511789 */                { 0x9D00, 0, (ResInitFn)0x00624FDF }, /* Res_dummy_fl_create_624FDF */
    { 0x58F0, 0, (ResInitFn)0x00624A97 }, /* Res_dummy_wl_624A97 */                      { 0x6C0E, 0, (ResInitFn)0x005EA179 }, /* Res_dog_create_5EA179 */
    { 0xB997, 0, (ResInitFn)0x0040BB8B }, /* Res_door_create_40BB8B */                   { 0x73F8, 0, (ResInitFn)0x00624208 }, /* Res_door2_create_624208 */
    { 0xB58D, 0, (ResInitFn)0x00623B32 }, /* Res_drum_create_623B32 */                   { 0x4BE8, 0, (ResInitFn)0x00623714 }, /* Res_drum2_create_623714 */
    { 0x3303, 0, (ResInitFn)0x005E9A03 }, /* Res_ductmous_create_5E9A03 */               { 0xAF6C, 0, (ResInitFn)0x0062345B }, /* Res_dymc_flr_create_62345B */
    { 0xB103, 0, (ResInitFn)0x0062330F }, /* Res_dymc_seg_create_62330F */               { 0xE75A, 0, (ResInitFn)0x0062305A }, /* Res_ed_telop_create_62305A */
    { 0x107C, 0, (ResInitFn)0x00622EEF }, /* Res_elc_damg_create_622EEF */               { 0xAEF2, 0, (ResInitFn)0x00622D21 }, /* Res_elc_flr_create_622D21 */
    { 0x2ABC, 0, (ResInitFn)0x00621BDD }, /* Res_elevator_create_621BDD */               { 0x9AB9, 0, (ResInitFn)0x005E80FE }, /* Res_valcan_ele_crow_create_5E80FE */
    { 0xE253, 0, (ResInitFn)0x00456960 }, /* Res_evpanel_create_456960 */                { 0x32E5, 0, (ResInitFn)0x0063F60E }, /* Res_emitter_create_63F60E */
    { 0xA9DD, 0, (ResInitFn)0x0063F43D }, /* Res_emitter2_create_63F43D */               { 0xB789, 0, (ResInitFn)0x0062190F }, /* Res_ending2_create_62190F */
    { 0x3F9A, 0, (ResInitFn)0x00621797 }, /* Res_env_snd_create_621797 */                { 0x76FE, 0, (ResInitFn)0x0062130E }, /* Res_env_test_create_62130E */
    { 0xA12E, 0, (ResInitFn)0x0044200E }, /* Res_fadeio_create_44200E */                 { 0xC73E, 0, (ResInitFn)0x005E7FCF }, /* Res_fall_spl_create_5E7FCF */
    { 0x5D64, 0, (ResInitFn)0x00620DA7 }, /* Res_o2_damge_create_620DA7 */               { 0x118C, 0, (ResInitFn)0x00620978 }, /* Res_findtrap_create_620978 */
    { 0xD6FB, 0, (ResInitFn)0x00620833 }, /* Res_fog_create_620833 */                    { 0x84E1, 0, (ResInitFn)0x005115AE }, /* Res_fonttext_5115AE */
    { 0x0FAD, 0, (ResInitFn)0x00511497 }, /* Res_motse_511497 */                         { 0xADD8, 0, (ResInitFn)0x0062052F }, /* Res_furnace_create_62052F */
    { 0x8D5A, 0, (ResInitFn)0x006203E0 }, /* Res_gasdamge_create_6203E0 */               { 0x5A50, 0, (ResInitFn)0x0061FE1B }, /* Res_gas_efct_create_61FE1B */
    { 0x2477, 0, (ResInitFn)0x0061F9A8 }, /* Res_jeep_emy_create_61F9A8 */               { 0xCCD3, 0, (ResInitFn)0x005E7FCC },
    { 0x8E70, 0, (ResInitFn)0x0061F2D5 }, /* Res_glass_create_61F2D5 */                  { 0xDB1F, 0, (ResInitFn)0x004DAA01 }, /* Res_goal_create_4DAA01 */
    { 0x9EB7, 0, (ResInitFn)0x00567203 }, /* Res_godzcom_create_567203 */                { 0xCB1F, 0, (ResInitFn)0x0056653D }, /* Res_godzila_56653D */
    { 0x5F5A, 0, (ResInitFn)0x0063F0EF }, /* Res_grdcam_63F0EF */                        { 0xCBEB, 0, (ResInitFn)0x005E76AA }, /* Res_bg_hex_create_5E76AA */
    { 0x0D9B, 0, (ResInitFn)0x005E6DD7 }, /* Res_bg_hex_s_loader_5E6DD7 */               { 0x42E4, 0, (ResInitFn)0x005E6A41 }, /* Res_hiyoko_create_5E6A41 */
    { 0xDD8B, 0, (ResInitFn)0x00511349 }, /* Res_intr_cam_511349 */                      { 0x8767, 0, (ResInitFn)0x0044D086 }, /* Res_item_44D086 */
    { 0x6A48, 0, (ResInitFn)0x0061E1DD }, /* Res_jeep_srl_create_61E1DD */               { 0xA27E, 0, (ResInitFn)0x0061DDFA }, /* Res_jdrum_create_61DDFA */
    { 0xB757, 0, (ResInitFn)0x00462532 },                                                { 0x1EF9, 0, (ResInitFn)0x0050C653 }, /* Res_johnny_create_50C653 */
    { 0x81C7, 0, (ResInitFn)0x0049B678 }, /* Res_TitleStageLoadRelated_49B678 */         { 0x4F02, 0, (ResInitFn)0x005B9F42 },
    { 0xC6AC, 0, (ResInitFn)0x005E66A1 }, /* Res_key_item_create_5E66A1 */               { 0x52BF, 0, (ResInitFn)0x005A60A2 }, /* Res_kiken_5A60A2 */
    { 0xA6F6, 0, (ResInitFn)0x004421C2 }, /* Res_Cache_Kmd_4421C2 */                     { 0x8B1A, 0, (ResInitFn)0x0050BF9B }, /* Res_landing_create_50BF9B */
    { 0x711F, 0, (ResInitFn)0x0061DC48 }, /* Res_life_up_61DC48 */                       { 0x425F, 0, (ResInitFn)0x0061D52C }, /* Res_lift_create_61D52C */
    { 0x921B, 0, (ResInitFn)0x0061CCCC }, /* Res_lift2_create_61CCCC */                  { 0x7BF2, 0, (ResInitFn)0x005652F4 }, /* Res_liquid_create_5652F4 */
    { 0xCF72, 0, (ResInitFn)0x0049AD6B }, /* Res_CdSwap_create_49AD6B */                 { 0x53C7, 0, (ResInitFn)0x004606E2 },
    { 0x9D71, 0, (ResInitFn)0x005C0C8B }, /* Res_m1e1_create_5C0C8B */                   { 0xD5EC, 0, (ResInitFn)0x005BFEA1 }, /* Res_m1e1came_create_5BFEA1 */
    { 0xE448, 0, (ResInitFn)0x0061B8B9 }, /* Res_doll2_61B8B9 */                         { 0x450F, 0, (ResInitFn)0x0050A2E4 }, /* Res_hair_m_create_50A2E4 */
    { 0xAF72, 0, (ResInitFn)0x00509679 }, /* Res_mempsy_create_509679 */                 { 0xC755, 0, (ResInitFn)0x00565013 }, /* Res_meryl3_565013 */
    { 0x5078, 0, (ResInitFn)0x005A53CA }, /* Res_meryl7_create_5A53CA */                 { 0xE271, 0, (ResInitFn)0x005644F4 }, /* Res_meryl72_create_5644F4 */
    { 0x4754, 0, (ResInitFn)0x005BE3F8 }, /* Res_mgrex_create_5BE3F8 */                  { 0x954B, 0, (ResInitFn)0x0061B32D }, /* Res_mg_demo1_create_61B32D */
    { 0x1787, 0, (ResInitFn)0x005BD2D4 }, /* Res_hind_create_5BD2D4 */                   { 0xC218, 0, (ResInitFn)0x0061AB21 }, /* Res_mirror_create_61AB21 */
    { 0xA2B5, 0, (ResInitFn)0x0045692F },                                                { 0x7ACF, 0, (ResInitFn)0x005E61CC }, /* Res_model_dt_create_5E61CC */
    { 0x6D78, 0, (ResInitFn)0x0061A71C }, /* Res_monitor1_create_61A71C */               { 0x0065, 0, (ResInitFn)0x0061A683 }, /* Res_mosaic_create_61A683 */
    { 0xD4A5, 0, (ResInitFn)0x005E52D5 }, /* Res_mouse_create_5E52D5 */                  { 0x3453, 0, (ResInitFn)0x00456860 }, /* Res_movie_456860 */
    { 0x5345, 0, Res_movie_create_4561C6 },                                              { 0xB98C, 0, (ResInitFn)0x005A4F47 }, /* Res_m_door_5A4F47 */
    { 0xD3C0, 0, (ResInitFn)0x0050964C },                                                { 0xF002, 0, (ResInitFn)0x00508856 }, /* Res_hair_n_create_508856 */
    { 0x30BA, 0, (ResInitFn)0x00563A09 }, /* Res_ninja_create_563A0 */                   { 0x4811, 0, (ResInitFn)0x005A473D }, /* Res_object_5A473D */
    { 0xCF79, 0, Res_open_create_486BD4 },                                               { 0x3AC3, 0, (ResInitFn)0x00482D1F }, /* Res_opena_create_482D1F */
    { 0xCFEF, 0, (ResInitFn)0x0047EE6E }, /* Res_openp_47EE6E */                         { 0x976C, 0, (ResInitFn)0x0047A5E5 }, /* Res_opt_create_47A5E5 */
    { 0x8D31, 0, (ResInitFn)0x004792A6 }, /* Res_opta_create_4792A6 */                   { 0xB916, 0, (ResInitFn)0x00477F58 }, /* Res_optp_create_477F58 */
    { 0xCBF8, 0, (ResInitFn)0x00456093 }, /* Res_pad_create_456093 */                    { 0x3ED7, 0, (ResInitFn)0x0061A311 }, /* Res_pad_demo_create_61A311 */
    { 0x720D, 0, (ResInitFn)0x00539051 }, /* Res_paddemo2_539051 */                      { 0xFED1, 0, (ResInitFn)0x00455F32 }, /* Res_vibrate_create_455F32 */
    { 0x20F2, 0, (ResInitFn)0x00619C50 }, /* Res_panel_create_619C50 */                  { 0xDD95, 0, (ResInitFn)0x006198AB }, /* Res_panel2_create_6198AB */
    { 0x5F02, 0, (ResInitFn)0x006196C0 }, /* Res_paper_create_6196C0 */                  { 0x30CE, 0, (ResInitFn)0x005E40BB }, /* Res_pato_lmp_5E40BB */
    { 0xFDB6, 0, (ResInitFn)0x004612E8 }, /* Res_pocket_create_4612E8 */                 { 0x8FDC, 0, (ResInitFn)0x00462529 }, /* Res_pocket_create_1_462529 */
    { 0x6414, 0, (ResInitFn)0x00462395 }, /* Res_pocket_create_0_462395 */               { 0xAA13, 0, (ResInitFn)0x00460D44 },
    { 0xCF00, 0, (ResInitFn)0x00460D1C },                                                { 0x10FF, 0, (ResInitFn)0x00508209 }, /* Res_perapict_create_508209 */
    { 0xEDEB, 0, (ResInitFn)0x00505D37 }, /* Res_photosel_505D37 */                      { 0x8427, 0, (ResInitFn)0x005E3D51 }, /* Res_scn_anim_create_5E3D51 */
    { 0x17F5, 0, (ResInitFn)0x005E372A }, /* Res_bg_sp_create_5E372A */                  { 0x1FA5, 0, (ResInitFn)0x0043EEFB }, /* Res_bg_stage_43EEFB */
    { 0xB032, 0, (ResInitFn)0x005E316B }, /* Res_bg_st1_create_5E316B */                 { 0xB033, 0, (ResInitFn)0x005E2B67 }, /* Res_bg_st2_create_5E2B67 */
    { 0xB7AE, 0, (ResInitFn)0x005E262D }, /* Res_bg_sp_cm_create_5E262D */               { 0xBC76, 0, (ResInitFn)0x005E2053 }, /* Res_bg_sp_st_create_5E2053 */
    { 0x9C6C, 0, (ResInitFn)0x0061947E }, /* Res_pk_gate_create_61947E */                { 0xB47A, 0, (ResInitFn)0x0061870B }, /* Res_pjeep_create_61870B */
    { 0x9BC2, 0, (ResInitFn)0x005E1032 }, /* Res_plasma_create_5E1032 */                 { 0xFC0B, 0, (ResInitFn)0x005E0C21 }, /* Res_flr_spa_create_5E0C21 */
    { 0x3AD2, 0, (ResInitFn)0x00505B87 }, /* Res_Ret0_505B87 */                          { 0xCC89, 0, (ResInitFn)0x005E01D2 }, /* Res_bg_hex_p_5E01D2 */
    { 0x6D1B, 0, (ResInitFn)0x00476B30 }, /* Res_preope_create_476B30 */                 { 0xD8DD, 0, (ResInitFn)0x005054F4 }, /* Res_ninja_5054F4 */
    { 0xBF66, 0, (ResInitFn)0x00504B42 }, /* Res_otacom_504B42 */                        { 0xA404, 0, (ResInitFn)0x005045B7 }, /* Res_sne_03c_5045B7 */
    { 0x27A2, 0, (ResInitFn)0x0050492D }, /* Res_sne_03c_50492D */                       { 0xA76F, 0, (ResInitFn)0x004E8181 }, /* Res_psyco_4E8181 */
    { 0xF4B0, 0, (ResInitFn)0x004FFA7A }, /* Res_meryl07b_create_4FFA7A */               { 0x710D, 0, (ResInitFn)0x004FEEC7 }, /* Res_psyobj_create_4FEEC7 */
    { 0x91AA, 0, (ResInitFn)0x006183F2 }, /* Res_puthzd_create_6183F2 */                 { 0x169C, 0, (ResInitFn)0x005DF74E }, /* Res_p_lamp_create_5DF74E */
    { 0x5147, 0, (ResInitFn)0x00455E18 }, /* Res_point_455E18 */                         { 0x917B, 0, (ResInitFn)0x005DF51B }  /* Res_item_dot_create_5DF51B */
});

// An zeroed array initially as the name suggests it is dynamically populated at run time.
MGS_ARY(REDIRECT_LIBDG_DATA, 0x994320, Res_Init_Record, 512, gDynamicResFuncs_word_994320, {} );

MGS_ARY(REDIRECT_LIBDG_DATA, 0x650040, Res_Init_Record, 3, gStaticResInitFuncs_stru_650040,
{
    { 0x21CA, 0, (ResInitFn)0x004E1701 }, // Res_sna_init_create_4E1701
    { 0x8767, 0, (ResInitFn)0x0044D086 }, // Res_item_44D086
    { 0xB997, 0, (ResInitFn)0x0040BB8B }  // Res_door_create_40BB8B
});

MGS_PTR(REDIRECT_LIBDG_DATA, 0x993F44, Res_Init_Record*, gpToDynamicResInitFuncs_dword_993F44, nullptr);

MGS_VAR(REDIRECT_LIBDG_DATA, 0x994304, DWORD, gSleep5000_after_res_funcs_1_dword_994304, 0);
MGS_VAR(REDIRECT_LIBDG_DATA, 0x99430C, DWORD, gSleep5000_after_res_funcs_2_dword_99430C, 0);

MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BB910, Actor, gLibDGD_1_stru_6BB910, {});
MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BB930, LibDG_Struct, gLibDG_2_stru_6BB930, {});

MGS_VAR(REDIRECT_LIBDG_DATA, 0x722A40, DWORD, gBinds_dword_722A40, 0);
MGS_ARY(1, 0x6BED18, DWORD, 2, dword_6BED18, {});

MGS_VAR(1, 0x6BC180, struct_gv, gLibGvStruct0_6BC180, {}); // TODO: Probably an array of 3?
MGS_VAR(1, 0x6BC36C, struct_gv, gLibGVStruct1_6BC36C, {});
MGS_VAR(1, 0x6BC558, struct_gv, gLibGvStruct2_6BC558, {});

MGS_VAR(1, 0x78D32C, DWORD, dword_78D32C, 0);

ResInitFn CC Script_tbl_get_res_init_fn_457B9A(BYTE *pScript)
{
    const WORD hashedName = static_cast<WORD>(Script_Unknown8_409924(pScript));
    LOG_INFO("Looking for " << hashedName << " chara function");
    return LibDG_GetResourceInitFuncPtr_457BAC(hashedName);
}
MGS_FUNC_IMPLEX(0x00457B9A, Script_tbl_get_res_init_fn_457B9A, LIBDG_IMPL);

signed int CC Script_tbl_chara_451AC3(BYTE* pScript)
{
    BYTE* scriptRet = Script_GetReturnAddress();
    ResInitFn pResFn = Script_tbl_get_res_init_fn_457B9A(scriptRet);
    if (pResFn)
    {
        BYTE* scriptRet2 = Script_GetReturnAddress();
        DWORD scriptUnknown = Script_Unknown8_409924(scriptRet2);
        LOG_INFO("Exec chara fn: " << pResFn);
        pResFn(scriptUnknown, gBinds_dword_722A40, pScript);
        return 0;
    }
    return -1;
}
MGS_FUNC_IMPLEX(0x00451AC3, Script_tbl_chara_451AC3, LIBDG_IMPL);

signed int CC GV_bin_file_handler_44E9D2(void* pData, TFileNameHash /*fileNameHash*/)
{
    Res_Init_Record* pStartingRecord = reinterpret_cast<Res_Init_Record*>(pData);
    int dst_idx = 0;
    for (;;)
    {
        if (!pStartingRecord->mInitFunctionPointer)
        {
            break;
        }

        int src_idx = 0;
        while (gKnownResInitFuncs_669AE0[src_idx].mHashedName)
        {
            if (gKnownResInitFuncs_669AE0[src_idx].mHashedName == pStartingRecord->mHashedName)
            {
                gDynamicResFuncs_word_994320[dst_idx].mHashedName = pStartingRecord->mHashedName;
                gDynamicResFuncs_word_994320[dst_idx].mInitFunctionPointer = gKnownResInitFuncs_669AE0[src_idx].mInitFunctionPointer;
                break;
            }
            src_idx++;
        }
        printf("CHARA %d, %p\n", gDynamicResFuncs_word_994320[dst_idx].mHashedName, gDynamicResFuncs_word_994320[dst_idx].mInitFunctionPointer);

        ++dst_idx;
        ++pStartingRecord;
    }

    // Set last entry to 0 to terminate
    gDynamicResFuncs_word_994320[dst_idx].mHashedName = 0;
    gDynamicResFuncs_word_994320[dst_idx].mInitFunctionPointer = nullptr;

    if (gSleep5000_after_res_funcs_1_dword_994304 || gSleep5000_after_res_funcs_2_dword_99430C)
    {
        ::Sleep(5000);
    }

    gSleep5000_after_res_funcs_1_dword_994304 = 0;
    gSleep5000_after_res_funcs_2_dword_99430C = 0;

    return 1;
}
MGS_FUNC_IMPLEX(0x0044E9D2, GV_bin_file_handler_44E9D2, LIBDG_IMPL);

void CC LibDG_SetActiveResourceInitFuncPtrs_457B5B()
{
    memcpy(gDynamicResFuncs_word_994320, gKnownResInitFuncs_669AE0, 4096u); // 4096u = sizeof(gResInitFuncs_669AE0)
    gpToDynamicResInitFuncs_dword_993F44 = gDynamicResFuncs_word_994320;
}
MGS_FUNC_IMPLEX(0x457B5B, LibDG_SetActiveResourceInitFuncPtrs_457B5B, LIBDG_IMPL);

void CC LibDG_ClearActiveResourceFunctionPointerList_457B7C()
{
    memset(gDynamicResFuncs_word_994320, 0, 4096u); // 4096u = sizeof(gResInitFuncs_669AE0)
    gpToDynamicResInitFuncs_dword_993F44 = gDynamicResFuncs_word_994320;
}
MGS_FUNC_IMPLEX(0x457B7C, LibDG_ClearActiveResourceFunctionPointerList_457B7C, LIBDG_IMPL);

static ResInitFn FindFnPtrByHash(Res_Init_Record* arrayToSearch, WORD hashName)
{
    Res_Init_Record* pRecord = arrayToSearch;
    while (pRecord->mInitFunctionPointer)
    {
        if (pRecord->mHashedName == hashName)
        {
            return pRecord->mInitFunctionPointer;
        }
        ++pRecord;
    }
    return nullptr;
}

ResInitFn CC LibDG_GetResourceInitFuncPtr_457BAC(WORD hashedName)
{
    // Search in the 3 "static" records
    ResInitFn result = FindFnPtrByHash(gStaticResInitFuncs_stru_650040, hashedName);
    if (result)
    {
        return result;
    }

    // Search in the 512 "dynamic" records
    result = FindFnPtrByHash(gpToDynamicResInitFuncs_dword_993F44, hashedName);
    return result;
}
MGS_FUNC_IMPLEX(0x457BAC, LibDG_GetResourceInitFuncPtr_457BAC, LIBDG_IMPL);

MGS_ARY(1, 0x6BCB44, DWORD, 33, ot_gv0_0_6BCB44, {});
MGS_ARY(1, 0x6BCBC8, DWORD, 289, ot_gv0_1_6BCBC8, {});
MGS_ARY(1, 0x6BD04C, DWORD, 257, ot_gv1_0_6BD04C, {});
MGS_ARY(1, 0x6BD450, DWORD, 513, ot_gv1_1_6BD450, {});
MGS_ARY(1, 0x6BDC54, DWORD, 2, ot_gv2_0_6BDC54, {});
MGS_ARY(1, 0x6BDC5C, DWORD, 259, ot_gv2_1_6BDC5C, {});

MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BE068, DR_ENV, stru_6BE068, {});
MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BE0A8, DR_ENV, pPacked_6BE0A8, {});

MGS_ARY(1, 0x6BBD60, Prim_Union*, 256, dg_dword_6BBD60_prim_ptrs, {});
MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BBD5C, DWORD, dg_dword_6BBD5C_k320, 0);
MGS_ARY(1, 0x6BB95C, Prim_Union*, 256, dg_dword_6BB95C_prim_ptrs, {});

void CC sub_401570(struct_gv* gv, DRAWENV* pDrawEnv, int bNotBg)
{
    DRAWENV drawEnv = {};

    memcpy(&drawEnv, pDrawEnv, sizeof(drawEnv));
    const int xoff = gv->word_6BC378_1 != 0 ? dg_dword_6BBD5C_k320 : 0;
    gv->dword_6BC3D0_rect.x1 = drawEnv.clip.x1 - drawEnv.offx;
    gv->dword_6BC3D0_rect.y1 = drawEnv.clip.y1 - drawEnv.offy;
    gv->dword_6BC3D0_rect.x2 = drawEnv.clip.x2;
    gv->dword_6BC3D0_rect.y2 = drawEnv.clip.y2;
    SetDrawEnv_40DDE0(&gv->dword_6BC4D8_src_dr_env1, &drawEnv);
    drawEnv.clip.x1 += static_cast<s16>(xoff);
    drawEnv.offx += static_cast<s16>(xoff);
    SetDrawEnv_40DDE0(&gv->dword_6BC518_src_offsetted_dr_evn, &drawEnv);
    if (bNotBg)
    {
        drawEnv.isbg = 0;
        SetDrawEnv_40DDE0(&pPacked_6BE0A8, &drawEnv);
        drawEnv.clip.x1 -= static_cast<s16>(xoff);
        drawEnv.offx -= static_cast<s16>(xoff);
        SetDrawEnv_40DDE0(&stru_6BE068, &drawEnv);
    }
}
MGS_FUNC_IMPLEX(0x401570, sub_401570, LIBDG_IMPL);

void CC Gv3StructsInit_4012F2(int k320)
{
    DRAWENV drawEnv = {};
    //DrawSynCallback(NullDrawSyncCallBack);

    gLibGvStruct0_6BC180.word_6BC376_16 = -1;
    dg_dword_6BBD5C_k320 = k320;
    gLibGvStruct0_6BC180.mOrderingTables[0] = ot_gv0_0_6BCB44;// ot start?
    gLibGvStruct0_6BC180.mOrderingTables[1] = ot_gv0_1_6BCBC8;// also part of ot?
    gLibGvStruct0_6BC180.mFreePrimCount = 8;
    gLibGvStruct0_6BC180.mTotalQueueSize = 8;
    gLibGvStruct0_6BC180.mTotalObjectCount = 0;
    gLibGvStruct0_6BC180.mQueue = dg_dword_6BBD60_prim_ptrs;// Might be 8 instead of 256?
    gLibGvStruct0_6BC180.word_6BC374_8 = 5;
    gLibGvStruct0_6BC180.word_6BC378_1 = 1;
    gLibGvStruct0_6BC180.word_6BC37A_0_1EC_size = 0;// used in other func

    Renderer_DRAWENV_Init_401888(&drawEnv, 0, 0, 320, 224);
    drawEnv.isbg = 1;

    sub_401570(&gLibGvStruct0_6BC180, &drawEnv, 1);

    memcpy(
        gLibGvStruct0_6BC180.dword_6BC3D8_dst,
        &gLibGvStruct0_6BC180.dword_6BC4D8_src_dr_env1,
        sizeof(gLibGvStruct0_6BC180.dword_6BC3D8_dst));

    gLibGvStruct0_6BC180.dword_6BC3C8_pStructure_rect = gLibGvStruct0_6BC180.dword_6BC3D0_rect;

    memcpy(
        gLibGvStruct0_6BC180.dword_6BC418_dst,
        &gLibGvStruct0_6BC180.dword_6BC518_src_offsetted_dr_evn,
        sizeof(gLibGvStruct0_6BC180.dword_6BC418_dst));

    gLibGVStruct1_6BC36C.mOrderingTables[0] = &ot_gv1_0_6BD04C[0];
    gLibGVStruct1_6BC36C.mOrderingTables[1] = &ot_gv1_1_6BD450[0];
    gLibGVStruct1_6BC36C.mFreePrimCount = 256;
    gLibGVStruct1_6BC36C.mTotalQueueSize = 256;
    gLibGVStruct1_6BC36C.mTotalObjectCount = 0;
    gLibGVStruct1_6BC36C.mQueue = dg_dword_6BB95C_prim_ptrs;
    gLibGVStruct1_6BC36C.word_6BC374_8 = 8;
    gLibGVStruct1_6BC36C.word_6BC376_16 = 16;
    gLibGVStruct1_6BC36C.word_6BC378_1 = 1;
    gLibGVStruct1_6BC36C.word_6BC37A_0_1EC_size = 0;

    Renderer_DRAWENV_Init_401888(&drawEnv, 0, 0, 320, 224);
    drawEnv.offx = 160;
    drawEnv.offy = 112;
    sub_401570(&gLibGVStruct1_6BC36C, &drawEnv, 0);

    memcpy(
        gLibGVStruct1_6BC36C.dword_6BC3D8_dst,
        &gLibGVStruct1_6BC36C.dword_6BC4D8_src_dr_env1,
        sizeof(gLibGVStruct1_6BC36C.dword_6BC3D8_dst));

    gLibGVStruct1_6BC36C.dword_6BC3C8_pStructure_rect = gLibGVStruct1_6BC36C.dword_6BC3D0_rect;

    memcpy(
        gLibGVStruct1_6BC36C.dword_6BC418_dst,
        &gLibGVStruct1_6BC36C.dword_6BC518_src_offsetted_dr_evn,
        sizeof(gLibGVStruct1_6BC36C.dword_6BC418_dst));

    memcpy(gLibGVStruct1_6BC36C.dword_6BC458, &stru_6BE068, sizeof(gLibGVStruct1_6BC36C.dword_6BC458));
    memcpy(gLibGVStruct1_6BC36C.dword_6BC498, &pPacked_6BE0A8, sizeof(gLibGVStruct1_6BC36C.dword_6BC498));

    gLibGvStruct2_6BC558.mOrderingTables[0] = &ot_gv2_0_6BDC54[0];
    gLibGvStruct2_6BC558.mOrderingTables[1] = &ot_gv2_1_6BDC5C[0];
    gLibGvStruct2_6BC558.mFreePrimCount = 0;
    gLibGvStruct2_6BC558.mTotalQueueSize = 0;
    gLibGvStruct2_6BC558.mTotalObjectCount = 0;
    gLibGvStruct2_6BC558.mQueue = 0;
    gLibGvStruct2_6BC558.word_6BC374_8 = 0;
    gLibGvStruct2_6BC558.word_6BC376_16 = 8;
    gLibGvStruct2_6BC558.word_6BC378_1 = 1;
    gLibGvStruct2_6BC558.word_6BC37A_0_1EC_size = 0;

    Renderer_DRAWENV_Init_401888(&drawEnv, 0, 0, 320, 224);
    sub_401570(&gLibGvStruct2_6BC558, &drawEnv, 0);

    memcpy(
        gLibGvStruct2_6BC558.dword_6BC3D8_dst,
        &gLibGvStruct2_6BC558.dword_6BC4D8_src_dr_env1,
        sizeof(gLibGvStruct2_6BC558.dword_6BC3D8_dst));

    gLibGvStruct2_6BC558.dword_6BC3C8_pStructure_rect = gLibGvStruct2_6BC558.dword_6BC3D0_rect;

    memcpy(
        gLibGvStruct2_6BC558.dword_6BC418_dst,
        &gLibGvStruct2_6BC558.dword_6BC518_src_offsetted_dr_evn,
        sizeof(gLibGvStruct2_6BC558.dword_6BC418_dst));

    memcpy(gLibGvStruct2_6BC558.dword_6BC458, &stru_6BE068, sizeof(gLibGvStruct2_6BC558.dword_6BC458));
    memcpy(gLibGvStruct2_6BC558.dword_6BC498, &pPacked_6BE0A8, sizeof(gLibGvStruct2_6BC558.dword_6BC498));
}
MGS_FUNC_IMPLEX(0x4012F2, Gv3StructsInit_4012F2, LIBDG_IMPL);

MGS_VAR(LIBDG_IMPL, 0x78D320, DWORD, gNumTexturesCopiedToResidentMemory_78D320, 0);
MGS_VAR(LIBDG_IMPL, 0x78BB08, Texture_Record*, gResidentTextureCacheCopy_78BB08, nullptr);
MGS_ARY(LIBDG_IMPL, 0x78BB20, Texture_Record, 512, g512Textures_unk_78BB20, {});

signed int CC LibDG_SearchForTextureRecord_4024D2(signed int hashCode, Texture_Record** ppFreeItem)
{
    const int kStartEndIdx = hashCode % 512;
    int idx = kStartEndIdx;
    do
    {
        // Not found case
        if (!g512Textures_unk_78BB20[idx].mHashedName)
        {
            *ppFreeItem = &g512Textures_unk_78BB20[idx];
            return 0;
        }

        // Found case
        if (g512Textures_unk_78BB20[idx].mHashedName == hashCode)
        {
            *ppFreeItem = &g512Textures_unk_78BB20[idx];
            return 1;
        }

        // Loop back around to the starting item
        if (++idx == 512)
        {
            idx = 0;
        }

    } while (idx != kStartEndIdx);

    *ppFreeItem = nullptr;

    return 0;
}
MGS_FUNC_IMPLEX(0x4024D2, LibDG_SearchForTextureRecord_4024D2, LIBDG_IMPL);

Texture_Record* CC LibDG_FindTexture_4024A0(WORD hashCode)
{
    Texture_Record* pFound = nullptr;
    if (!LibDG_SearchForTextureRecord_4024D2(hashCode, &pFound))
    {
        // Not found case
        static Texture_Record sLastFoundTexture_6BEE78 = {};
        LOG_ERROR("Texture " << hashCode << " was not found");
        return &sLastFoundTexture_6BEE78;
    }
    return pFound;
}
MGS_FUNC_IMPLEX(0x4024A0, LibDG_FindTexture_4024A0, LIBDG_IMPL);

void CC LibDG_ClearTexturesCache_402487()
{
    for (int i = 0; i<512; i++)
    {
        g512Textures_unk_78BB20[i].mHashedName = 0;
        g512Textures_unk_78BB20[i].mUsed = FALSE;
    }
}
MGS_FUNC_IMPLEX(0x402487, LibDG_ClearTexturesCache_402487, LIBDG_IMPL);

void CC LibDG_Restore_Textures_From_Resident_Memory_40274C()
{
    if (gResidentTextureCacheCopy_78BB08 && gNumTexturesCopiedToResidentMemory_78D320 > 0)
    {
        for (DWORD i = 0; i < gNumTexturesCopiedToResidentMemory_78D320; i++)
        {
            // Record will not exist therefore pFree will be set to a pointer to the next free entry
            Texture_Record* pFree = nullptr;
            LibDG_SearchForTextureRecord_4024D2(gResidentTextureCacheCopy_78BB08[i].mHashedName, &pFree);

            // Which we then populate
            *pFree = gResidentTextureCacheCopy_78BB08[i];
        }
    }
}
MGS_FUNC_IMPLEX(0x40274C, LibDG_Restore_Textures_From_Resident_Memory_40274C, LIBDG_IMPL);

void CC LibDG_Save_Texture_Hashes_To_Resident_Memory_4026F5()
{
    int usedCount = 0;
    for (int i = 0; i < 512; i++)
    {
        if (g512Textures_unk_78BB20[i].mHashedName)
        {
            usedCount++;
        }
    }

    if (usedCount > 0)
    {
        gNumTexturesCopiedToResidentMemory_78D320 = usedCount;
        Texture_Record* pResidentAllocated = (Texture_Record *)ResidentTopAllocate_40B379(sizeof(Texture_Record) * usedCount);
        gResidentTextureCacheCopy_78BB08 = pResidentAllocated;

        for (int i = 0; i < 512; i++)
        {
            if (g512Textures_unk_78BB20[i].mHashedName)
            {
                *pResidentAllocated = g512Textures_unk_78BB20[i];
                ++pResidentAllocated;
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x4026F5, LibDG_Save_Texture_Hashes_To_Resident_Memory_4026F5, LIBDG_IMPL);

void CC LibDG_Clear_Resident_Texture_Cache_Copy_4026E6()
{
    gNumTexturesCopiedToResidentMemory_78D320 = 0;
    gResidentTextureCacheCopy_78BB08 = nullptr;
}
MGS_FUNC_IMPLEX(0x4026E6, LibDG_Clear_Resident_Texture_Cache_Copy_4026E6, LIBDG_IMPL);


MGS_FUNC_NOT_IMPL(0x4020D8, void CC(), LibDG_Init_helper_4020D8);
MGS_FUNC_NOT_IMPL(0x40B9FF, void CC(), LibDG_40B9FF);

void CC SetRGB_40195A(char r, char g, char b)
{
    DRAWENV drawEnv = {};
    Renderer_DRAWENV_Init_401888(&drawEnv, 0, 0, 320, 224);
    drawEnv.r0 = r;
    drawEnv.g0 = g;
    drawEnv.b0 = b;
    drawEnv.isbg = 1;
    sub_401570(&gLibGvStruct0_6BC180, &drawEnv, 1);
    gLibGvStruct0_6BC180.word_6BC37A_0_1EC_size = 2;
}
MGS_FUNC_IMPLEX(0x40195A, SetRGB_40195A, LIBDG_IMPL);

void SetRGB000_4019AB()
{
    SetRGB_40195A(0, 0, 0);
}
MGS_FUNC_IMPLEX(0x4019AB, SetRGB000_4019AB, LIBDG_IMPL);

void CC LibDG_Set_RGB_FromDG_Actor_4019B9()
{
    SetRGB_40195A(gLibDG_2_stru_6BB930.gR_byte_6BB95A, gLibDG_2_stru_6BB930.gB_byte_6BB959, gLibDG_2_stru_6BB930.gG_byte_6BB958);
}
MGS_FUNC_IMPLEX(0x4019B9, LibDG_Set_RGB_FromDG_Actor_4019B9, LIBDG_IMPL);

void CC LibDG_SetRGB_401931(BYTE r, BYTE b, BYTE g)
{
    gLibDG_2_stru_6BB930.gR_byte_6BB95A = r;
    gLibDG_2_stru_6BB930.gG_byte_6BB958 = g;
    gLibDG_2_stru_6BB930.gB_byte_6BB959 = b;
    SetRGB_40195A(r, b, g);
}
MGS_FUNC_IMPLEX(0x401931, LibDG_SetRGB_401931, LIBDG_IMPL);

void CC OT_Related_40162D(int activeBuffer); // WinMain.cpp

void CC LibDG_Init_OTs_ExecFnPtrs_401ABE()
{
    OT_Related_40162D(0);
    OT_Related_40162D(1);
    LibDG_ExecFnPtrs_40171C(0);
    LibDG_ExecFnPtrs_40171C(1);
}
MGS_FUNC_IMPLEX(0x401ABE, LibDG_Init_OTs_ExecFnPtrs_401ABE, LIBDG_IMPL);

void CC LibDG_4010A6()
{
    LibDG_Init_helper_4020D8();
    LibDG_Init_OTs_ExecFnPtrs_401ABE();
    dword_78D32C = 0;
    jImageMove_401A31();
    LibDG_40B9FF(); // Just sets var 6C0644 = 0
    LibDG_SetRGB_401931(0, 0, 0);
    printf("Object Queue %d\n", gLibGVStruct1_6BC36C.mTotalObjectCount);
    printf("Primitive Queue %d\n", gLibGVStruct1_6BC36C.mTotalQueueSize - gLibGVStruct1_6BC36C.mFreePrimCount);
    gLibGVStruct1_6BC36C.mTotalObjectCount = 0;
    gLibGVStruct1_6BC36C.mFreePrimCount = gLibGVStruct1_6BC36C.mTotalQueueSize;
}
MGS_FUNC_IMPLEX(0x4010A6, LibDG_4010A6, LIBDG_IMPL);

void CC LibGvInitDispEnv_401A4F(int ClipX1, __int16 clipY1, __int16 clipX2, __int16 clipY2, int a320)
{
    gDispEnv_6BECF0.disp.y1 = clipY1;
    gDispEnv_6BECF0.disp.x2 = clipX2;
    gDispEnv_6BECF0.disp.y2 = clipY2;
    gDispEnv_6BECF0.screen.x1 = 0;
    gDispEnv_6BECF0.isinter = 0;
    gDispEnv_6BECF0.isrgb24 = 0;
    gDispEnv_6BECF0.disp.x1 = static_cast<s16>(ClipX1);
    dword_6BED18[0] = ClipX1;
    gDispEnv_6BECF0.screen.x2 = 256;
    gDispEnv_6BECF0.screen.y1 = 8;
    gDispEnv_6BECF0.screen.y2 = 224;
    dword_6BED18[1] = a320 + ClipX1;
}
MGS_FUNC_IMPLEX(0x401A4F, LibGvInitDispEnv_401A4F, LIBDG_IMPL);

// kVertexIndexingOrder_650174 provides the indexing order for referencing the transformed vertex sections
const char kVertexIndexingOrder_650174[4] = { 0, 1, 3, 2 };
// kVertexIndexingOffsets provides the offsets to the transformed vertex sections based on the indexing order
const char kVertexIndexingOffsets[4] = { offsetof(POLY_GT4, x0), offsetof(POLY_GT4, x1), offsetof(POLY_GT4, x3), offsetof(POLY_GT4, x2) };

void CC GV_kmd_link_vertices_to_parent_4028C1(kmdObject* pKmdObj, kmdObject* pParentObj)
{
    unsigned int indexFlags = 0;
    for (DWORD i = 0; i < pKmdObj->field_4_numFaces * 4; ++i)
    {
        const SVECTOR& vertexData = pKmdObj->vertOfs_38[pKmdObj->indexOfs_3C[i]];
        const unsigned short linkedVertexIndex = vertexData.field_6_padding;

        if (linkedVertexIndex == 0xFFFF)
        {
            continue;
        }

        indexFlags |= pKmdObj->indexOfs_3C[i];
        pKmdObj->indexOfs_3C[i] |= 0x80;
    }

    // determine whether vertex index data has already been processed
    const bool processed = (0x80 & indexFlags) != 0;

    if (processed)
    {
        return;
    }

    for (DWORD i = 0; i < pKmdObj->numVerts_34; ++i)
    {
        const unsigned short linkedVertexIndex = pKmdObj->vertOfs_38[i].field_6_padding;

        if (linkedVertexIndex == 0xFFFF)
        {
            continue;
        }

        // find first usage of linked vertex index in parent
        DWORD j = 0;
        for (; j < pParentObj->field_4_numFaces * 4; ++j)
        {
            if ((pParentObj->indexOfs_3C[j] & 0x7F) == linkedVertexIndex)
            {
                break;
            }
        }

        const int faceIndex = j / 4;
        const int faceVertexIndex = j % 4;

        // compute offset of linked poly data
        pKmdObj->vertOfs_38[i].field_6_padding = static_cast<short int>((sizeof(POLY_GT4) * faceIndex) + kVertexIndexingOffsets[faceVertexIndex]);
    }
}
MGS_FUNC_IMPLEX(0x4028C1, GV_kmd_link_vertices_to_parent_4028C1, LIBDG_IMPL);

int CC GV_kmd_file_handler_402796(void* fileData, TFileNameHash /*fileNameHash*/)
{
    KmdHeader* pFileBuffer = reinterpret_cast<KmdHeader*>(fileData);
    int numMeshes = pFileBuffer->mNumberOfObjects;
    for (kmdObject* pKmdObj = DataAfterStructure<kmdObject*>(pFileBuffer); --numMeshes >= 0; ++pKmdObj)
    {
        if (pKmdObj->vertOfs_38)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->vertOfs_38);
        }

        if (pKmdObj->indexOfs_3C)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->indexOfs_3C);
        }

        if (pKmdObj->normOfs_44)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->normOfs_44);
        }

        if (pKmdObj->normIndex_48)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->normIndex_48);
        }

        if (pKmdObj->ofsUV_4C)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->ofsUV_4C);
        }

        if (pKmdObj->ofsTextureNameHashes_50)
        {
            OffsetToPointer(pFileBuffer, &pKmdObj->ofsTextureNameHashes_50);
        }

        if (pKmdObj->mRef_2C_parentObjIndex >= 0)
        {
            GV_kmd_link_vertices_to_parent_4028C1(pKmdObj, &DataAfterStructure<kmdObject*>(pFileBuffer)[pKmdObj->mRef_2C_parentObjIndex]);
        }
    }
    return 1;
}
MGS_FUNC_IMPLEX(0x402796, GV_kmd_file_handler_402796, LIBDG_IMPL);

// TODO: These are not implemented - just here to return 1 for running standalone
signed int CC GV_lit_file_handler_402B1D(void*, TFileNameHash)
{
    return 1;
}
MGS_FUNC_IMPLEX(0x402B1D, GV_lit_file_handler_402B1D, LIBDG_IMPL);

int CC GV_n_file_handler_402A03(void* /*fileData*/, TFileNameHash /*fileNameHash*/)
{
    LOG_WARNING("N loader not impl");
    return 1;
}
MGS_FUNC_IMPLEX(0x402A03, GV_n_file_handler_402A03, false); // TODO

int CC GV_oar_file_handler_402A29(void* /*fileData*/, TFileNameHash /*fileNameHash*/)
{
    LOG_WARNING("OAR loader not impl");
    return 1;
}
MGS_FUNC_IMPLEX(0x402A29, GV_oar_file_handler_402A29, false); // TODO

int CC GV_zmd_file_handler_403290(void* /*fileData*/, TFileNameHash /*fileNameHash*/)
{
    LOG_WARNING("ZMD loader not impl");
    return 1;
}
MGS_FUNC_IMPLEX(0x403290, GV_zmd_file_handler_403290, false); // TODO

int CC GV_img_file_handler_402A5F(void* /*fileData*/, TFileNameHash /*fileNameHash*/)
{
    LOG_WARNING("IMG loader not impl");
    return 1;
}
MGS_FUNC_IMPLEX(0x402A5F, GV_img_file_handler_402A5F, false); // TODO

int CC GV_sgt_file_handler_402AA9(void* /*fileData*/, TFileNameHash /*fileNameHash*/)
{
    LOG_WARNING("SGT loader not impl");
    return 1;
}
MGS_FUNC_IMPLEX(0x402AA9, GV_sgt_file_handler_402AA9, false); // TODO

MGS_VAR(REDIRECT_LIBDG_DATA, 0x6BB908, DWORD, dword_6BB908, 0);

MGS_VAR(REDIRECT_LIBDG_DATA, 0x650090, DWORD, dword_650090, 0);


MGS_VAR(REDIRECT_LIBDG_DATA, 0x9942AB, BYTE, byte_9942AB, 0);

MGS_VAR(1, 0x7919B0, DWORD, dword_7919B0, 0);

int __cdecl sub_40AB96(int input, int mask1, int mask2)
{
    int result;
    int mask2RemainderBits;
    int mask1RemainderBits;
    signed int k2Counter;

    result = input;
    mask2RemainderBits = mask2;
    mask1RemainderBits = mask1;
    k2Counter = 2;
    do
    {
        result &= ~(mask2RemainderBits | mask1RemainderBits);
        if (mask1RemainderBits & input)
        {
            result |= mask2RemainderBits;
        }
        if (mask2RemainderBits & input)
        {
            result |= mask1RemainderBits;
        }
        mask1RemainderBits <<= 16;
        mask2RemainderBits <<= 16;
        --k2Counter;
    } while (k2Counter);
    return result;
}
MGS_FUNC_IMPLEX(0x40AB96, sub_40AB96, LIBDG_IMPL);

int __cdecl sub_40AB6B(int input)
{
    if ((gGameStates_78E7E0.gFlags_dword_78E7E4 & 7) == 1) // pad number ?
    {
        return sub_40AB96(input, 0x20, 0x40);
    }
    if ((gGameStates_78E7E0.gFlags_dword_78E7E4 & 7) == 2)
    {
        return sub_40AB96(input, 0x20, 0x80);
    }
    return input;
}
MGS_FUNC_IMPLEX(0x40AB6B, sub_40AB6B, LIBDG_IMPL);

unsigned int *__cdecl sub_40ABCA(unsigned int *a1, PadAnalogDeltas * a2)
{
    unsigned int *result;
    unsigned __int8 v3;
    unsigned __int8 v4;
    signed int v5;

    result = a1;
    *(BYTE *)(result + 1) &= 0xFu;
    v3 = a2[1].field_2_left_dx;
    v4 = a2[1].field_3_left_dy;
    v5 = 0;
    if (v3 >= 0x40u)
    {
        if (v3 > 0xC0u)
        {
            v5 = 0x2000;
        }
    }
    else
    {
        v5 = 0x8000;
    }
    if (v4 >= 0x40u)
    {
        if (v4 > 0xC0u)
        {
            //PsxButtonBits::eDPadDown
            v5 |= 0x4000u;
        }
    }
    else
    {
        v5 |= 0x1000u;
    }
    *a1 |= v5;
    return result;
}
MGS_FUNC_IMPLEX(0x40ABCA, sub_40ABCA, LIBDG_IMPL);

int CC Res_base_unknown_44CCD0(signed int a1, signed int a2)
{
    if (a1 || a2)
    {
        // TODO: Figure out what the constant value relates to
        return static_cast<int>((atan2(static_cast<double>(a1), static_cast<double>(a2)) * 651.8986476493061));
    }
    return 0;
}
MGS_FUNC_IMPLEX(0x44CCD0, Res_base_unknown_44CCD0, LIBDG_IMPL);

int CC Res_base_unknown_40B612(const SVECTOR* pVec)
{
    return Res_base_unknown_44CCD0(pVec->field_0_x, pVec->field_4_z) & 4095;
}
MGS_FUNC_IMPLEX(0x40B612, Res_base_unknown_40B612, LIBDG_IMPL);

__int16 word_65089C[] = { 0, 2048, 1024, 1536, 0, 0, 512, 0, 3072, 2560, 0, 0, 3584, 0, 0, 0 };

// Reverse memcpy ??
void __cdecl System_Q_sub_40B1B6(void* pStart, void* pEnd, int sizeOrCount)
{
    // when the "right" way around the colours of the start screen change..
    // I believe this is some sort of optimized memcpy like the optimized memset
    memcpy(pEnd , pStart, sizeOrCount);
}
MGS_FUNC_IMPLEX(0x40B1B6, System_Q_sub_40B1B6, true);

// TODO: This needs refactoring and more understanding
void CC LibDG_Update2_helper_40A857()
{
    PadAnalogDeltas padDeltas[2] = {};

    unsigned int releasedBits = 0;
    unsigned int gamedInput_status = GameD_Input_Wrapper_4455F0();
    unsigned int gamedInputCopy_status = gamedInput_status;
    unsigned int gamedInputMapped_released = sub_40AB6B(gamedInput_status); // Get bits for current pad?

    if (counter_dword_6BED20 > 0)
    {
        goto clear_input_and_input_mapped;
    }

    if ((game_state_dword_72279C.flags & 0x80000000) == 0)
    {
        if (game_state_dword_72279C.flags & 0x40000000)
        {
            // Mask out (~PsxButtonBits::ePADi | PsxButtonBits::ePADj) for pad0 and 1
            gamedInput_status = dword_7919B0 & 0xF9FFF9FF;
            gamedInputCopy_status = dword_7919B0 & 0xF9FFF9FF;
            gamedInputMapped_released = dword_7919B0 & 0xF9FFF9FF;
            goto LABEL_10;
        }
        if (!(game_state_dword_72279C.flags & 0x10000000))
        {
            if (!(game_state_dword_72279C.flags & 0x8000000))
            {
                goto LABEL_10;
            }
            gamedInputMapped_released &= g_lib_gv_stru_6BFEE0.gGv_dword_6C03A0_buttons_released;
            gamedInput_status &= g_lib_gv_stru_6BFEE0.gGv_dword_6C03A0_buttons_released;
            gamedInputCopy_status = gamedInput_status;
            goto LABEL_10;
        }
    clear_input_and_input_mapped:
        gamedInputMapped_released = 0;
        gamedInput_status = 0;
        gamedInputCopy_status = gamedInput_status;
        goto LABEL_10;
    }

LABEL_10:
    DWORD counter = 2;
    DWORD k32Counter = 32;
    ButtonStates* pBackingArray_0xA = &gButtonsArray4_7919C0[0];

    // Never been able to test any of the code paths below as they don't hold
    // true with a 360 controller.
    do // TODO: Can probably just be a for loop
    {
        if (game_state_dword_72279C.flags & 0x40000000 && k32Counter == 32)
        {
            const DWORD maskedState = game_state_dword_72279C.flags & 0x40000000;
            if (game_state_dword_72279C.flags & 0x40000000)
            {
                padDeltas[0].field_0_right_dx = 1;
            }
            const __int16 v6 = padDeltas[0].field_1_right_dy - 1;
            pBackingArray_0xA->field_A_analog = v6;
            if (v6 <= 0 || game_state_dword_72279C.flags & 0x90000000 && !maskedState)
            {
                pBackingArray_0xA->field_A_analog = 0;
                const DWORD v10 = gamedInputMapped_released & 0xF000;
                if (v10)
                {
                    pBackingArray_0xA->field_8_dir = (LOWORD(g_lib_gv_stru_6BFEE0.gGv_dword_6C03A4_left_stick)
                                                           + word_65089C[v10 >> 12]) & 4095;
                }
                else
                {
                    pBackingArray_0xA->field_8_dir = -1;
                }
            }
            else
            {
                if (gamedInputMapped_released & 0xF000)
                {
                    if (gamedInputMapped_released & 0xF000)
                    {
                        pBackingArray_0xA->field_8_dir =
                           (LOWORD(g_lib_gv_stru_6BFEE0.gGv_dword_6C03A4_left_stick)
                                 + word_65089C[(gamedInputMapped_released & 0xF000) >> 12]) & 4095;
                    }
                    else
                    {
                        pBackingArray_0xA->field_8_dir = -1;
                    }
                    pBackingArray_0xA->field_A_analog= 0;
                }
                else
                {
                    SVECTOR vec = {};
                    vec.field_0_x = (unsigned __int16)(((unsigned __int8)padDeltas[1].field_2_left_dx - 128) / 8) << 8;
                    vec.field_4_z = (unsigned __int16)(((unsigned __int8)padDeltas[1].field_3_left_dy - 128) / 8) << 8;
                    if (vec.field_0_x <= -2048
                        || (signed __int16)((unsigned __int16)(((unsigned __int8)padDeltas[1].field_2_left_dx - 128) / 8) << 8) >= 2048
                        || (signed __int16)((unsigned __int16)(((unsigned __int8)padDeltas[1].field_3_left_dy - 128) / 8) << 8) <= -2048
                        || (signed __int16)((unsigned __int16)(((unsigned __int8)padDeltas[1].field_3_left_dy - 128) / 8) << 8) >= 2048)
                    {
                        pBackingArray_0xA->field_8_dir = static_cast<WORD>(LOWORD(g_lib_gv_stru_6BFEE0.gGv_dword_6C03A4_left_stick) + Res_base_unknown_40B612(&vec));
                    }
                    else
                    {
                        pBackingArray_0xA->field_8_dir = -1;
                    }
                    sub_40ABCA(&gamedInputMapped_released, padDeltas);
                    gamedInput_status = gamedInputCopy_status;

                }

                pBackingArray_0xA->field_C_deltas = padDeltas[1];

                if (game_state_dword_72279C.flags & 0x8000000)
                {
                    if (!(g_lib_gv_stru_6BFEE0.gGv_dword_6C03A0_buttons_released & 0xF000))
                    {
                        pBackingArray_0xA->field_A_analog = 0;
                        pBackingArray_0xA->field_8_dir = -1;
                    }
                }
            }
            g_lib_gv_stru_6BFEE0.gGv_dword_6C03A8 |= 1 << counter;
        }
        else
        {
            pBackingArray_0xA->field_A_analog = 0;
            pBackingArray_0xA->field_8_dir = -1;
        }

        pBackingArray_0xA->field_A_analog = 0;
        const DWORD v13 = gamedInputMapped_released & 0xF000;
        if (v13)
        {
            pBackingArray_0xA->field_8_dir = (LOWORD(g_lib_gv_stru_6BFEE0.gGv_dword_6C03A4_left_stick) + word_65089C[v13 >> 12]) & 4095;
        }
        else
        {
            pBackingArray_0xA->field_8_dir = -1;
        }

        const DWORD v15 = gamedInputMapped_released;
        pBackingArray_0xA++;
        gamedInputMapped_released >>= 16;
        releasedBits |= v15 << (32 - k32Counter);
        --counter;
        k32Counter -= 16;
    } while (k32Counter);

    gamedInputMapped_released = releasedBits;
    const DWORD v16 = releasedBits & 0xF000F000 | gamedInput_status;
    gamedInputCopy_status = v16;
    System_Q_sub_40B1B6(&gButtonsArray4_7919C0[0], &gButtonsArray4_7919C0[2], sizeof(ButtonStates)*2);

    unsigned int f_1_button_status = gamedInputMapped_released;
    const DWORD v18 = g_lib_gv_stru_6BFEE0.gGv_dword_6C0380_released;
    unsigned int f_3_button_released = g_lib_gv_stru_6BFEE0.gGv_dword_6C0380_released & ~gamedInputMapped_released;
    g_lib_gv_stru_6BFEE0.gGv_dword_6C0380_released = gamedInputMapped_released;
    unsigned int f_2_other_pressed = v16 & ~g_lib_gv_stru_6BFEE0.gGv_dword_6C0384;
    unsigned int f_2_button_pressed = gamedInputMapped_released & ~v18;
    gamedInputMapped_released = g_lib_gv_stru_6BFEE0.gGv_dword_6C0384 & ~v16;
    g_lib_gv_stru_6BFEE0.gGv_dword_6C0384 = v16;

    // Collect buttons pressed in the last 6 frames
    unsigned int f_4_button_quick = 0;
    if (f_2_button_pressed)
    {
        DWORD pressedButtonsAccumulator = 0;
        for (int i = 0; i < 6; i++)
        {
            pressedButtonsAccumulator |= g_lib_gv_stru_6BFEE0.gGv_dword_6C0388_history[i];
        }
        // Ones that match this frames buttons are the "quick" presses
        f_4_button_quick = f_2_button_pressed & pressedButtonsAccumulator;
    }

    g_lib_gv_stru_6BFEE0.gGv_dword_6C0388_history[g_lib_gv_stru_6BFEE0.gRenderedFramesCount_dword_6BFF00 % 6] = f_2_button_pressed;

    for (int i=0; i<4; i++)
    {
        if (i == 2)
        {
            f_1_button_status = gamedInputCopy_status;
            f_2_button_pressed = f_2_other_pressed;
            f_3_button_released = gamedInputMapped_released;
        }
        gButtonsArray4_7919C0[i].field_0_button_status = static_cast<WORD>(f_1_button_status);
        gButtonsArray4_7919C0[i].field_2_button_pressed = static_cast<WORD>(f_2_button_pressed);
        gButtonsArray4_7919C0[i].field_4_button_release = static_cast<WORD>(f_3_button_released);
        gButtonsArray4_7919C0[i].field_6_button_quick = static_cast<WORD>(f_4_button_quick);

        // 16 bits for buttons 0,1, then gets reset after setting 2 items of the 
        // array for 16bits for button 2,3
        f_1_button_status >>= 16;
        f_2_button_pressed >>= 16;
        f_3_button_released >>= 16;
        f_4_button_quick >>= 16;
    }
}
MGS_FUNC_IMPLEX(0x40A857, LibDG_Update2_helper_40A857, LIBDG_IMPL);


MGS_FUNC_NOT_IMPL(0x5200D2, signed __int64 CC(), sub_5200D2);

signed __int64 CC WaitFor_445580(int totalCount)
{
    __int64 result = 0;
    for (int i = 0; i < totalCount; i++)
    {
        result = sub_5200D2();
    }
    return result;
}
MGS_FUNC_IMPLEX(0x445580, WaitFor_445580, LIBDG_IMPL);


void CC LibDG_Update2_401234(Actor* /*pLibDg*/)
{
    static int sTimeStamp_dword_650094 = 0;

    dword_6BB908 = 0;

    gLibDG_2_stru_6BB930.dword_6BB954 = gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers;

    if (BYTE3(game_state_dword_72279C) & 0x20)
    {
        int bDontFlipBuffers = gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers;

        if (sTimeStamp_dword_650094 == -1)
        {
            sTimeStamp_dword_650094 = static_cast<int>(TimeGetElapsed_4455A0()); // TODO: Check truncation is correct here
            bDontFlipBuffers = 0;
            gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers = 0;
        }

        if (!bDontFlipBuffers)
        {
            WaitFor_445580(dword_650090);
        }

        // TODO: This is not 100% correct - but I don't think 
        // dword_6BB950_do_not_flip_buffers can ever be set to 1?
        //MGS_WARN_ONCE("Possibly wrong behavior here"); // TODO: Impl MGS_WARN_ONCE

        __int64 elapsed = TimeGetElapsed_4455A0();
        if (elapsed - (sTimeStamp_dword_650094 + 2) < 0)
        {
            sTimeStamp_dword_650094 += 2;
        }
        gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers = 0;
    }
    else
    {
        WaitFor_445580(dword_650090);
        sTimeStamp_dword_650094 = -1;
        gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers = 0;
    }

    Main_sub_401C02();

    /*
    g_lib_gv_stru_6BFEE0.gGv_dword_6C0380 = 0; // Released bits
    g_lib_gv_stru_6BFEE0.gGv_dword_6C0384 = PsxButtonBits::eCircle;
    for (int i = 0; i < 6; i++)
    {
        g_lib_gv_stru_6BFEE0.gGv_dword_6C0388[i] = 2;
    }
    g_lib_gv_stru_6BFEE0.gGv_dword_6C03A0 = PsxButtonBits::eCircle; // Script val from pad table?
    g_lib_gv_stru_6BFEE0.gGv_dword_6C03A4 = PsxButtonBits::eCircle; // left analog stick?
    g_lib_gv_stru_6BFEE0.gGv_dword_6C03A8 = PsxButtonBits::eCircle;
    */


    LibDG_Update2_helper_40A857(); // Probably input related as input no longer works if not called?

    gpActiveButtons_995324 = gButtonsArray4_7919C0;
    if (byte_9942AB & 0x10)
    {
        if (gButtonsArray4_7919C0[1].field_0_button_status | gButtonsArray4_7919C0[1].field_4_button_release)
        {
            gpActiveButtons_995324 = &gButtonsArray4_7919C0[1];
        }
    }

 
}
MGS_FUNC_IMPLEX(0x401234, LibDG_Update2_401234, LIBDG_IMPL);


MGS_VAR(1, 0x6BECE8, DWORD, gLibDG_ExecPtrs_6BECE8, 0);

void CC sub_40191F()
{
    gLibDG_ExecPtrs_6BECE8 = 0;
    counter_dword_6BED20 = 1;
}
MGS_FUNC_IMPLEX(0x40191F, sub_40191F, LIBDG_IMPL);


MGS_ARY(1, 0x6BE4E8, DWORD*, 512, gUnkSize_1024_6BE4E8, {}); // TODO: Might just be 256?


void* CC MemClearUnknown_40B231(void* pMem, int size)
{
    return memset(pMem, 0, size);
}
MGS_FUNC_IMPLEX(0x40B231, MemClearUnknown_40B231, LIBDG_IMPL);

using TDG_FnPtr = void(CC*)(struct_gv* pGv, int activeBuffer);

MGS_FUNC_NOT_IMPL(0x4062CB, void __cdecl (VECTOR* pBoundingBox), LibGV_Helper_4062CB);
MGS_FUNC_NOT_IMPL(0x40640F, signed int (), LibGV_Helper_40640F);

void CC LibGV_prim_buffer_set_all_cluts_to_3FFF_406649(Prim_Mesh_0x5C* pMeshObj, int activeBuffer)
{
    Prim_Mesh_0x5C* pMeshObjIter = pMeshObj;
    POLY_GT4* pPrimBufferIter = pMeshObj->field_54_prim_buffers[activeBuffer];
    if (pPrimBufferIter)
    {
        if (pPrimBufferIter->clut != 0x3FFF)
        {
            while (pMeshObjIter)
            {
                for (int i = 0; i < pMeshObjIter->field_52_num_faces; i++)
                {
                    pPrimBufferIter->clut = 0x3FFF;
                    ++pPrimBufferIter;
                }
                pMeshObjIter = pMeshObjIter->field_48_pLinked;
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x406649, LibGV_prim_buffer_set_all_cluts_to_3FFF_406649, LIBDG_IMPL);

MGS_VAR(1, 0x6BEF08, Texture_Record, stru_6BEF08, {});

void CC LibGV_prim_buffer_set_cluts_40667F(Prim_Mesh_0x5C* pMeshObj, int activeBuffer)
{
    Prim_Mesh_0x5C* pMeshObjIter = pMeshObj;
    POLY_GT4* pPrimBufferIter = pMeshObj->field_54_prim_buffers[activeBuffer];
    if (pPrimBufferIter)
    {
        if (pPrimBufferIter->clut == 0x3FFF)
        {
            WORD previousTextureHash = 0;
            while (pMeshObjIter)
            {
                Texture_Record* pTextureRec = &stru_6BEF08;
                WORD* textureInfo = pMeshObjIter->field_40_pKmdObj->ofsTextureNameHashes_50;
                for (int i = 0; i < pMeshObjIter->field_52_num_faces; i++)
                {
                    WORD textureHashName = textureInfo[i];
                    if (textureHashName != previousTextureHash)
                    {
                        previousTextureHash = textureHashName;
                        pTextureRec = LibDG_FindTexture_4024A0(textureHashName);
                    }
                    pPrimBufferIter[i].clut = pTextureRec->mClut;
                }
                pMeshObjIter = pMeshObjIter->field_48_pLinked;
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x40667F, LibGV_prim_buffer_set_cluts_40667F, LIBDG_IMPL);


void CC LibGV_Helper_4065AA(struct_gv* pGv, int activeBuffer)
{
    if (game_state_dword_72279C.mParts.flags0 & 8)
    {
        for (int i = 0; i < pGv->mTotalObjectCount; i++)
        {
            Prim_unknown_0x48* pObj = &pGv->mQueue[i]->prim_48;
            if (pObj->field_28_flags_or_type & 0x200)
            {
                if (pObj->field_32)
                {
                    Prim_Mesh_0x5C* pMeshIter = reinterpret_cast<Prim_Mesh_0x5C*>(&pObj[1]);
                    for (int j = 0; j < pObj->field_2E_UnknownOrNumFaces; j++)
                    {
                        if (pMeshIter->field_4C_bounding_ret)
                        {
                            LibGV_prim_buffer_set_all_cluts_to_3FFF_406649(&pMeshIter[j], activeBuffer);
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < pGv->mTotalObjectCount; i++)
        {
            Prim_unknown_0x48* pObj = &pGv->mQueue[i]->prim_48;
            if (pObj->field_28_flags_or_type & 0x200)
            {
                if (pObj->field_32)
                {
                    Prim_Mesh_0x5C* pMeshIter = (Prim_Mesh_0x5C *)&pObj[1];
                    for (int j = 0; j < pObj->field_2E_UnknownOrNumFaces; j++)
                    {
                        LibGV_prim_buffer_set_cluts_40667F(&pMeshIter[j], activeBuffer);
                    }
                }
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x4065AA, LibGV_Helper_4065AA, LIBDG_IMPL);

void CC LibGV_void_active_prim_buffer_4073E8(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    if (pMesh->field_54_prim_buffers[activeBuffer])
    {
        System_VoidAllocation_40B187(activeBuffer, (void **)&pMesh->field_54_prim_buffers[activeBuffer]);
        pMesh->field_54_prim_buffers[activeBuffer] = nullptr;
    }
}
MGS_FUNC_IMPLEX(0x4073E8, LibGV_void_active_prim_buffer_4073E8, LIBDG_IMPL);

void CC LibGV_allocate_in_bounds_and_void_out_of_bounds_4064B1(Prim_unknown_0x48* pObject, int activeBuffer, BYTE flags, int previousBoundingRet)
{
    Prim_Mesh_0x5C* pMeshObj = reinterpret_cast<Prim_Mesh_0x5C*>(&pObject[1]);
    for (int i = 0; i < pObject->field_2E_UnknownOrNumFaces; i++)
    {
        int boundingRet = 0;
        if (previousBoundingRet)
        {
            boundingRet = 2;
            if (flags & 0x10)
            {
                gte_rotation_matrix_993E40 = pMeshObj->field_20_mtx.m;
                gGte_translation_vector_993E54 = pMeshObj->field_20_mtx.t;
                LibGV_Helper_4062CB(pMeshObj->field_40_pKmdObj->boundingBox);
                boundingRet = LibGV_Helper_40640F();
            }
        }

        pMeshObj->field_4C_bounding_ret = static_cast<WORD>(boundingRet);

        if (boundingRet)
        {
            pMeshObj->field_4E_counter = 8;
            if (pMeshObj->field_52_num_faces > 0 && !pMeshObj->field_54_prim_buffers[activeBuffer])
            {
                if (LibGV_prim_buffer_allocate_texture_and_shade_40730A(pMeshObj, activeBuffer, flags) < 0)
                {
                    pMeshObj->field_4C_bounding_ret = 0;
                    if (flags & 0x20)
                    {
                        pObject->field_32 = 0;
                        return;
                    }
                }
            }
        }
        else if (pMeshObj->field_54_prim_buffers[activeBuffer])
        {
            if (--pMeshObj->field_4E_counter <= 0)
            {
                LibGV_void_active_prim_buffer_4073E8(pMeshObj, activeBuffer);
            }
        }
        ++pMeshObj;
    }
}
MGS_FUNC_IMPLEX(0x4064B1, LibGV_allocate_in_bounds_and_void_out_of_bounds_4064B1, LIBDG_IMPL);

void CC LibGV_4061E7(struct_gv* pGv, int activeBuffer)
{
    const unsigned __int16 dword_78D32C_copy = static_cast<unsigned __int16>(dword_78D32C);

    Gte_project_distance_rect_401DA8(&pGv->dword_6BC3C8_pStructure_rect, pGv->word_6BC3BC);

    for (int i = 0; i < pGv->mTotalObjectCount; i++)
    {
        Prim_Union* pObject = pGv->mQueue[i];
        Prim_unknown_0x48* pObj48 = &pObject->prim_48;

        signed int unknownArg3 = 0;
        const int flags = pObj48->field_28_flags_or_type;
        if ((flags & 0x80u) == 0 && (!pObj48->field_2C_index || pObj48->field_2C_index & dword_78D32C_copy))
        {
            if (flags & 0x20)
            {
                Prim_Mesh_0x5C* pMesh = (Prim_Mesh_0x5C*)&pObj48[1];
                gte_rotation_matrix_993E40 = pMesh->field_20_mtx.m;
                gGte_translation_vector_993E54 = pMesh->field_20_mtx.t;

                LibGV_Helper_4062CB(pObj48->field_24_pKmdFileData->mBoundingBox);
                unknownArg3 = LibGV_Helper_40640F();
            }
            else
            {
                unknownArg3 = 2;
            }
        }
        pObj48->field_32 = static_cast<WORD>(unknownArg3);
        LibGV_allocate_in_bounds_and_void_out_of_bounds_4064B1(&pObject->prim_48, activeBuffer, static_cast<BYTE>(flags), unknownArg3);
    }
    LibGV_Helper_4065AA(pGv, activeBuffer);
}
MGS_FUNC_IMPLEX(0x4061E7, LibGV_4061E7, LIBDG_IMPL);

MGS_VAR(1, 0x991E40, Psx_ScratchPad, gScratchPadMemory_991E40, {});

void CC LibGV_40674E(Prim_unknown_0x48* pPrim, int faceCount)
{
    Psx_ScratchPad_Matrix* pScratch = &gScratchPadMemory_991E40.field_2_Matrix;

    gte_rotation_matrix_993E40 = pScratch->mtx[0].m;
    
    gGte_IR1_993EE4.IR_32 = pScratch->mtx[1].m.m[0][0];
    gGte_IR2_993EE8.IR_32 = pScratch->mtx[1].m.m[1][0];
    gGte_IR3_993EEC.IR_32 = pScratch->mtx[1].m.m[2][0];
    Psx_gte_RT1_rtir_447480();

    pScratch->mtx[2].m.m[0][0] = gGte_IR1_993EE4.IR_16;
    pScratch->mtx[2].m.m[1][0] = gGte_IR2_993EE8.IR_16;
    pScratch->mtx[2].m.m[2][0] = gGte_IR3_993EEC.IR_16;

    gGte_IR1_993EE4.IR_32 = pScratch->mtx[1].m.m[0][1];
    gGte_IR2_993EE8.IR_32 = pScratch->mtx[1].m.m[1][1];
    gGte_IR3_993EEC.IR_32 = pScratch->mtx[1].m.m[2][1];
    Psx_gte_RT1_rtir_447480();

    pScratch->mtx[2].m.m[0][1] = gGte_IR1_993EE4.IR_16;
    pScratch->mtx[2].m.m[1][1] = gGte_IR2_993EE8.IR_16;
    pScratch->mtx[2].m.m[2][1] = gGte_IR3_993EEC.IR_16;

    gGte_IR1_993EE4.IR_32 = pScratch->mtx[1].m.m[0][2];
    gGte_IR2_993EE8.IR_32 = pScratch->mtx[1].m.m[1][2];
    gGte_IR3_993EEC.IR_32 = pScratch->mtx[1].m.m[2][2];
    Psx_gte_RT1_rtir_447480();

    pScratch->mtx[2].m.m[0][2] = gGte_IR1_993EE4.IR_16;
    pScratch->mtx[2].m.m[1][2] = gGte_IR2_993EE8.IR_16;
    pScratch->mtx[2].m.m[2][2] = gGte_IR3_993EEC.IR_16;

    gGte_translation_vector_993E54.field_0_x = pScratch->mtx[0].t.field_0_x;
    gGte_translation_vector_993E54.field_4_y = pScratch->mtx[0].t.field_4_y;
    gGte_translation_vector_993E54.field_8_z = pScratch->mtx[0].t.field_8_z;

    gGte_VXY0_993EC0.regs.VX = static_cast<short>(pScratch->mtx[1].t.field_0_x);
    gGte_VXY0_993EC0.regs.VY = static_cast<short>(pScratch->mtx[1].t.field_4_y);
    gGte_VXY0_993EC0.regs.VZ = static_cast<short>(pScratch->mtx[1].t.field_8_z);

    Psx_gte_RT1TR_rt_4477A0();

    pScratch->mtx[2].t.field_0_x = gGte_MAC1_993F24.MAC_32;
    pScratch->mtx[2].t.field_4_y = gGte_MAC2_993F28.MAC_32;
    pScratch->mtx[2].t.field_8_z = gGte_MAC3_993F2C.MAC_32;

    // Pointer to data after the main structure
    Prim_Mesh_0x5C* pData = reinterpret_cast<Prim_Mesh_0x5C*>(&pPrim[1]);
    for (int i = 0; i < faceCount; i++)
    {
        pData[i].field_0_mtx = pScratch->mtx[1];
        pData[i].field_20_mtx = pScratch->mtx[2];
    }
}
MGS_FUNC_IMPLEX(0x40674E, LibGV_40674E, LIBDG_IMPL);

void CC LibGV_406A78(Prim_unknown_0x48* pObj, int innerCount)
{
    Psx_ScratchPad_Matrix* pScratch = &gScratchPadMemory_991E40.field_2_Matrix;

    gte_rotation_matrix_993E40 = pScratch->mtx[1].m;

    SVECTOR* field_44_iter = pObj->field_44;
    Prim_Mesh_0x5C* pMeshObj = (Prim_Mesh_0x5C *)&pObj[1];
    PSX_MATRIX* pScratch3 = &pScratch->mtx[2];

    for (int i = 0; i < innerCount; i++)
    {
        PSX_MATRIX* pScratchMatrix = &pScratch->mtx[pMeshObj->field_40_pKmdObj->mRef_2C_parentObjIndex + 2]; // + 2 because matrix 0 and 1 are in use

        gGte_translation_vector_993E54 = pScratchMatrix->t;

        gGte_VXY0_993EC0.regs.VX = field_44_iter->field_0_x;
        gGte_VXY0_993EC0.regs.VY = field_44_iter->field_2_y;
        gGte_VXY0_993EC0.regs.VZ = field_44_iter->field_4_z;
        gGte_VXY0_993EC0.regs.Zero = field_44_iter->field_6_padding;

        Psx_gte_RT1TR_rt_4477A0();
    
        pScratch3->m = gte_rotation_matrix_993E40;
        pScratch3->t = gGte_translation_vector_993E54;

        // This makes the above stores pointless..
        pScratch3->t.field_0_x = gGte_MAC1_993F24.MAC_32;
        pScratch3->t.field_4_y = gGte_MAC2_993F28.MAC_32;
        pScratch3->t.field_8_z = gGte_MAC3_993F2C.MAC_32;

        pMeshObj->field_0_mtx = *pScratch3;
        pMeshObj++;
        pScratch3++;
        field_44_iter++;
    }

}
MGS_FUNC_IMPLEX(0x406A78, LibGV_406A78, LIBDG_IMPL);

void CC LibGV_406906(Prim_unknown_0x48* pObj, int innerCount)
{
    Psx_ScratchPad_Matrix* pScratch = &gScratchPadMemory_991E40.field_2_Matrix;

    gte_rotation_matrix_993E40 = pScratch->mtx[0].m;

    gGte_translation_vector_993E54.field_0_x = pScratch->mtx[0].t.field_0_x;
    gGte_translation_vector_993E54.field_4_y = pScratch->mtx[0].t.field_4_y;
    gGte_translation_vector_993E54.field_8_z = pScratch->mtx[0].t.field_8_z;

    for (int i = 0; i < innerCount; i++)
    {
        PSX_MATRIX* pMtx = (&gScratchPadMemory_991E40.field_2_Matrix.mtx[2]) + i;
        Prim_Mesh_0x5C* pMesh = ((Prim_Mesh_0x5C*)&pObj[1]) + i;

        gGte_VXY0_993EC0.regs.VX = static_cast<short>(pMtx->t.field_0_x);
        gGte_VXY0_993EC0.regs.VY = static_cast<short>(pMtx->t.field_4_y);
        gGte_VXY0_993EC0.regs.VZ = static_cast<short>(pMtx->t.field_8_z);
        Psx_gte_RT1TR_rt_4477A0();
        pMesh->field_20_mtx.t.field_0_x = gGte_MAC1_993F24.MAC_32;
        pMesh->field_20_mtx.t.field_4_y = gGte_MAC2_993F28.MAC_32;
        pMesh->field_20_mtx.t.field_8_z = gGte_MAC3_993F2C.MAC_32;

        gGte_IR1_993EE4.IR_32 = pMtx->m.m[0][0];
        gGte_IR2_993EE8.IR_32 = pMtx->m.m[1][0];
        gGte_IR3_993EEC.IR_32 = pMtx->m.m[2][0];
        Psx_gte_RT1_rtir_447480();
        pMesh->field_20_mtx.m.m[0][0] = gGte_IR1_993EE4.IR_16;
        pMesh->field_20_mtx.m.m[1][0] = gGte_IR2_993EE8.IR_16;
        pMesh->field_20_mtx.m.m[2][0] = gGte_IR3_993EEC.IR_16;

        gGte_IR1_993EE4.IR_32 = pMtx->m.m[0][1];
        gGte_IR2_993EE8.IR_32 = pMtx->m.m[1][1];
        gGte_IR3_993EEC.IR_32 = pMtx->m.m[2][1];
        Psx_gte_RT1_rtir_447480();
        pMesh->field_20_mtx.m.m[0][1] = gGte_IR1_993EE4.IR_16;
        pMesh->field_20_mtx.m.m[1][1] = gGte_IR2_993EE8.IR_16;
        pMesh->field_20_mtx.m.m[2][1] = gGte_IR3_993EEC.IR_16;

        gGte_IR1_993EE4.IR_32 = pMtx->m.m[0][2];
        gGte_IR2_993EE8.IR_32 = pMtx->m.m[1][2];
        gGte_IR3_993EEC.IR_32 = pMtx->m.m[2][2];
        Psx_gte_RT1_rtir_447480();
        pMesh->field_20_mtx.m.m[0][2] = gGte_IR1_993EE4.IR_16;
        pMesh->field_20_mtx.m.m[1][2] = gGte_IR2_993EE8.IR_16;
        pMesh->field_20_mtx.m.m[2][2] = gGte_IR3_993EEC.IR_16;
    }
}
MGS_FUNC_IMPLEX(0x406906, LibGV_406906, LIBDG_IMPL);

void CC LibGV_406B97(Prim_unknown_0x48* pObj, int faceCount)
{
    Prim_Mesh_0x5C* pMesh = (Prim_Mesh_0x5C*)&pObj[1];
    kmdObject* pKmd = pMesh->field_40_pKmdObj;
    Psx_ScratchPad_Matrix* pScratch = &gScratchPadMemory_991E40.field_2_Matrix;

    if (pObj->field_40)
    {
        RotMatrixZYX_gte_44C880(pObj->field_40, (MATRIX3x3 *)&pScratch->mtx[26]);
    }
    else
    {
        RotMatrixZYX_gte_44C880(pObj->field_38_size24b->field_0, (MATRIX3x3 *)&pScratch->mtx[26]);
    }

    pScratch->mtx[26].t = pKmd->translation;

    if (pObj->field_3C)
    {
        pScratch->mtx[27] = pScratch->mtx[1];
        pScratch->mtx[1] = gIdentity_matrix_6501F8;
    }
    else
    {
        gte_rotation_matrix_993E40 = pScratch->mtx[1].m;
        gGte_translation_vector_993E54 = pScratch->mtx[1].t;

        for (int i = 0; i < 3; i++)
        {
            gGte_IR1_993EE4.IR_32 = pScratch->mtx[26].m.m[0][i];
            gGte_IR2_993EE8.IR_32 = pScratch->mtx[26].m.m[1][i];
            gGte_IR3_993EEC.IR_32 = pScratch->mtx[26].m.m[2][i];
            Psx_gte_RT1_rtir_447480();
            pScratch->mtx[26].m.m[0][i] = static_cast<short>(gGte_IR1_993EE4.IR_32);
            pScratch->mtx[26].m.m[1][i] = static_cast<short>(gGte_IR2_993EE8.IR_32);
            pScratch->mtx[26].m.m[2][i] = static_cast<short>(gGte_IR3_993EEC.IR_32);
        }

        gGte_translation_vector_993E54.field_0_x = pScratch->mtx[1].t.field_0_x;
        gGte_translation_vector_993E54.field_4_y = pScratch->mtx[1].t.field_4_y;
        gGte_translation_vector_993E54.field_8_z = pScratch->mtx[1].t.field_8_z;

        gGte_VXY0_993EC0.regs.VX = static_cast<short>(pScratch->mtx[26].t.field_0_x);
        gGte_VXY0_993EC0.regs.VY = static_cast<short>(pScratch->mtx[26].t.field_4_y);
        gGte_VXY0_993EC0.regs.VZ = static_cast<short>(pScratch->mtx[26].t.field_8_z);

        Psx_gte_RT1TR_rt_4477A0();

        pScratch->mtx[26].t.field_0_x = gGte_MAC1_993F24.MAC_32;
        pScratch->mtx[26].t.field_4_y = gGte_MAC2_993F28.MAC_32;
        pScratch->mtx[26].t.field_8_z = gGte_MAC3_993F2C.MAC_32;
    }


    SVECTOR* field_3C_ptr = pObj->field_3C;
    int faceCount2 = faceCount;
    if (faceCount > 0) // TODO: Refactor to a for loop
    {
        Prim_Mesh_0x5C *pMeshIter = pMesh;
        SVECTOR* pLightsIter = pObj->field_38_size24b->field_0;
        PSX_MATRIX* pScratchMtx = &pScratch->mtx[2];
        do
        {
            PSX_MATRIX* pMtx = &pScratch->mtx[pMeshIter->field_40_pKmdObj->mRef_2C_parentObjIndex + 2];
            RotMatrixZYX_gte_44C880(pLightsIter, &pScratchMtx->m);
            pScratchMtx->t = pMeshIter->field_40_pKmdObj->translation;
            PSX_MATRIX* v10 = &pScratch->mtx[26];

            if (faceCount2 != faceCount - 1)
            {
                v10 = pMtx;
            }

            gte_rotation_matrix_993E40 = v10->m;
            gGte_translation_vector_993E54 = v10->t;

            for (int i = 0; i < 3; i++)
            {
                gGte_IR1_993EE4.IR_32 = pScratchMtx->m.m[0][i];
                gGte_IR2_993EE8.IR_32 = pScratchMtx->m.m[1][i];
                gGte_IR3_993EEC.IR_32 = pScratchMtx->m.m[2][i];
                Psx_gte_RT1_rtir_447480();
                pScratchMtx->m.m[0][i] = static_cast<short>(gGte_IR1_993EE4.IR_32);
                pScratchMtx->m.m[1][i] = static_cast<short>(gGte_IR2_993EE8.IR_32);
                pScratchMtx->m.m[2][i] = static_cast<short>(gGte_IR3_993EEC.IR_32);
            }

            gGte_translation_vector_993E54 = v10->t;

            gGte_VXY0_993EC0.regs.VX = static_cast<short>(pScratchMtx->t.field_0_x);
            gGte_VXY0_993EC0.regs.VY = static_cast<short>(pScratchMtx->t.field_4_y);
            gGte_VXY0_993EC0.regs.VZ = static_cast<short>(pScratchMtx->t.field_8_z);

            Psx_gte_RT1TR_rt_4477A0();
            pScratchMtx->t.field_0_x = gGte_MAC1_993F24.MAC_32;
            pScratchMtx->t.field_4_y = gGte_MAC2_993F28.MAC_32;
            pScratchMtx->t.field_8_z = gGte_MAC3_993F2C.MAC_32;

            if (field_3C_ptr)
            {
                if (field_3C_ptr->field_4_z)
                {
                    RotMatrixZ_44C320(field_3C_ptr->field_4_z, pScratchMtx);
                }
                if (field_3C_ptr->field_0_x)
                {
                    RotMatrixX_44C1C0(field_3C_ptr->field_0_x, pScratchMtx);
                }
                if (field_3C_ptr->field_2_y)
                {
                    RotMatrixY_44C270(field_3C_ptr->field_2_y, pScratchMtx);
                }

                ++field_3C_ptr;
            }
            else
            {
                pMeshIter->field_0_mtx = *pScratchMtx;
            }

            pMeshIter++;
            pLightsIter++;
            faceCount2--;
            pScratchMtx++;

        } while (faceCount2 > 0);
    }

    if (pObj->field_3C)
    {
        gte_rotation_matrix_993E40 = pScratch->mtx[27].m;
        gGte_translation_vector_993E54 = pScratch->mtx[27].t;

        PSX_MATRIX* pMtxAry = &pScratch->mtx[2];
        Prim_Mesh_0x5C* pMeshIter = pMesh;

        for (int i = 0; i < faceCount; i++)
        {
            gGte_VXY0_993EC0.regs.VX = static_cast<short>(pMtxAry[i].t.field_0_x);
            gGte_VXY0_993EC0.regs.VY = static_cast<short>(pMtxAry[i].t.field_4_y);
            gGte_VXY0_993EC0.regs.VZ = static_cast<short>(pMtxAry[i].t.field_8_z);
            Psx_gte_RT1TR_rt_4477A0();
            pMtxAry[i].t.field_0_x = gGte_MAC1_993F24.MAC_32;
            pMtxAry[i].t.field_4_y = gGte_MAC2_993F28.MAC_32;
            pMtxAry[i].t.field_8_z = gGte_MAC3_993F2C.MAC_32;

            for (int k = 0; k < 3; k++)
            {
                gGte_IR1_993EE4.IR_32 = pMtxAry[i].m.m[0][k];
                gGte_IR2_993EE8.IR_32 = pMtxAry[i].m.m[1][k];
                gGte_IR3_993EEC.IR_32 = pMtxAry[i].m.m[2][k];
                Psx_gte_RT1_rtir_447480();
                pMtxAry[i].m.m[0][k] = gGte_IR1_993EE4.IR_16;
                pMtxAry[i].m.m[1][k] = gGte_IR2_993EE8.IR_16;
                pMtxAry[i].m.m[2][k] = gGte_IR3_993EEC.IR_16;
            }
            pMeshIter[i].field_0_mtx = pMtxAry[i];
        }
    }
}
MGS_FUNC_IMPLEX(0x406B97, LibGV_406B97, LIBDG_IMPL);

void CC LibGV_4066ED(Prim_Union* pObj)
{
    const int count = pObj->prim_48.field_2E_UnknownOrNumFaces;
    if (pObj->prim_48.field_20_pMesh)
    {
        pObj->prim_48.field_0_matrix = pObj->prim_48.field_20_pMesh->field_0_mtx;
    }

    gScratchPadMemory_991E40.field_2_Matrix.mtx[1] = pObj->prim_48.field_0_matrix;

    if (pObj->prim_48.field_28_flags_or_type & 0x40)
    {
        LibGV_40674E(&pObj->prim_48, count);
    }
    else
    {
        if (pObj->prim_48.field_38_size24b)
        {
            LibGV_406B97(&pObj->prim_48, count);
        }
        else if (pObj->prim_48.field_44)
        {
            LibGV_406A78(&pObj->prim_48, count);
        }
        LibGV_406906(&pObj->prim_48, count);
    }
}
MGS_FUNC_IMPLEX(0x4066ED, LibGV_4066ED, LIBDG_IMPL);

MGS_FUNC_NOT_IMPL(0x404A0F, BYTE *__cdecl (Prim_unknown_0x54 *pPrim, BYTE *primBuffer, int count), LibGV_404A0F);

MGS_FUNC_NOT_IMPL(0x404B36, BYTE *__cdecl (Prim_unknown_0x54 *pObj, BYTE *pPrimBuffer, int count), LibGV_404B36);


MGS_FUNC_NOT_IMPL(0x40556A, POLY_GT4 *__cdecl (unsigned int *pNorms, POLY_GT4 *pPoly, int faceCount, unsigned int *pIndices), LibGV_indexed_normals_40556A);

struct Scratch_405428
{
    PSX_MATRIX field_0;
    CVECTOR field_20[82*3]; // Max of 992 bytes
};

POLY_GT4* CC LibGV_normals_4054F2(const unsigned int* pNormIdx, POLY_GT4* pPoly, int faceCount)
{
    if (faceCount - 1 < 0)
    {
        return pPoly;
    }

    const unsigned int* pNormIdxIter = pNormIdx;
    POLY_GT4* pPolyIter = pPoly;
    Scratch_405428* pScratch = (Scratch_405428*)&gScratchPadMemory_991E40; // TODO: Add to union
    for (int i=0; i<faceCount; i++)
    {
        if (LOWORD(pPolyIter[i].tag))
        {
            const DWORD idx = pNormIdxIter[i];
            // TODO: Do not cast, copy each rgb field by itself
            *(DWORD *)&pPolyIter[i].r0 = *(DWORD *)&pScratch->field_20[idx & 255]; // Max 246 idx
            *(DWORD *)&pPolyIter[i].r1 = *(DWORD *)&pScratch->field_20[((idx >> 6) & 1020) / sizeof(CVECTOR)];
            *(DWORD *)&pPolyIter[i].r2 = *(DWORD *)&pScratch->field_20[((idx >> 22) & 1020) / sizeof(CVECTOR)];
            *(DWORD *)&pPolyIter[i].r3 = *(DWORD *)&pScratch->field_20[((idx >> 14) & 1020) / sizeof(CVECTOR)];
        }
    }
    return pPolyIter;
}
MGS_FUNC_IMPLEX(0x4054F2, LibGV_normals_4054F2, LIBDG_IMPL);

static void Test_LibGV_normals_4054F2()
{
    Scratch_405428* pScratcPad = (Scratch_405428*)&gScratchPadMemory_991E40; // TODO: Add to union
    BYTE c = 0;
    for (int i = 0; i < 4 * 2; i++)
    {
        pScratcPad->field_20[i].r = c++;
        pScratcPad->field_20[i].g = c++;
        pScratcPad->field_20[i].b = c++;
        pScratcPad->field_20[i].cd = c++;
    }

    BYTE normals[4*2] = 
    {
        2 | 0x80,
        1 | 0x80,
        0 | 0x80,
        3 | 0x80,
        4,
        5,
        6,
        7,
    };

    POLY_GT4 polys[2] = {};
    for (int i = 0; i < 2; i++)
    {
        polys[i].tag = 0xFFFF;
    }

    LibGV_normals_4054F2((unsigned int*)normals, polys, 2);

    ASSERT_EQ(polys[0].r0, pScratcPad->field_20[normals[0]].r);
    ASSERT_EQ(polys[0].g0, pScratcPad->field_20[normals[0]].g);
    ASSERT_EQ(polys[0].b0, pScratcPad->field_20[normals[0]].b);

    ASSERT_EQ(polys[0].r1, pScratcPad->field_20[normals[1]].r);
    ASSERT_EQ(polys[0].g1, pScratcPad->field_20[normals[1]].g);
    ASSERT_EQ(polys[0].b1, pScratcPad->field_20[normals[1]].b);

    ASSERT_EQ(polys[0].r2, pScratcPad->field_20[normals[3]].r);
    ASSERT_EQ(polys[0].g2, pScratcPad->field_20[normals[3]].g);
    ASSERT_EQ(polys[0].b2, pScratcPad->field_20[normals[3]].b);

    ASSERT_EQ(polys[0].r3, pScratcPad->field_20[normals[2]].r);
    ASSERT_EQ(polys[0].g3, pScratcPad->field_20[normals[2]].g);
    ASSERT_EQ(polys[0].b3, pScratcPad->field_20[normals[2]].b);

    ASSERT_EQ(polys[1].r0, pScratcPad->field_20[normals[4]].r);
    ASSERT_EQ(polys[1].g0, pScratcPad->field_20[normals[4]].g);
    ASSERT_EQ(polys[1].b0, pScratcPad->field_20[normals[4]].b);

    ASSERT_EQ(polys[1].r1, pScratcPad->field_20[normals[5]].r);
    ASSERT_EQ(polys[1].g1, pScratcPad->field_20[normals[5]].g);
    ASSERT_EQ(polys[1].b1, pScratcPad->field_20[normals[5]].b);

    ASSERT_EQ(polys[1].r2, pScratcPad->field_20[normals[7]].r);
    ASSERT_EQ(polys[1].g2, pScratcPad->field_20[normals[7]].g);
    ASSERT_EQ(polys[1].b2, pScratcPad->field_20[normals[7]].b);

    ASSERT_EQ(polys[1].r3, pScratcPad->field_20[normals[6]].r);
    ASSERT_EQ(polys[1].g3, pScratcPad->field_20[normals[6]].g);
    ASSERT_EQ(polys[1].b3, pScratcPad->field_20[normals[6]].b);
}


void CC Psx_gte_nct_449B30();

void CC LibGV_405428(kmdObject* pKmd)
{
    if (pKmd->field_0_flags & 2)
    {
        gGte_light_colour_993ED8 = light_transparent_colour_65016C;
    }
    else
    {
        gGte_light_colour_993ED8 = light_opaque_colour_650168;
    }

    Scratch_405428* pScratcPad = (Scratch_405428*)&gScratchPadMemory_991E40; // TODO: Add to union

    SVECTOR* pNormIter = pKmd->normOfs_44;
    CVECTOR* pScratch = &pScratcPad->field_20[0];
    const int normCount = (pKmd->numNorms_40 + 2) / 3u; // TODO: Add clarity to this calculation (rounding to multiple of 3??)
    assert(normCount < 82);

    for (int i = 0; i < normCount; i++)
    {
        // NOTE: The real function will put the normals into the scratch pad first, this is tricky because
        // it means writing 3 normals and then overwriting with 3 RGB values. And then advancing by the size
        // of 3 RGB values and writing 3 more normals. Because using the scratch pad is irrelevant on PC 
        // I just copy from normal directly to GTE registers, it's much more simple to understand this way.
        gGte_VXY0_993EC0.regs.VX = pNormIter[0].field_0_x;
        gGte_VXY0_993EC0.regs.VY = pNormIter[0].field_2_y;
        gGte_VXY0_993EC0.regs.VZ = pNormIter[0].field_4_z;

        gGte_VXY1_993EC8.regs.VX = pNormIter[1].field_0_x;
        gGte_VXY1_993EC8.regs.VY = pNormIter[1].field_2_y;
        gGte_VXY1_993EC8.regs.VZ = pNormIter[1].field_4_z;

        gGte_VXY2_993ED0.regs.VX = pNormIter[2].field_0_x;
        gGte_VXY2_993ED0.regs.VY = pNormIter[2].field_2_y;
        gGte_VXY2_993ED0.regs.VZ = pNormIter[2].field_4_z;
        
        pNormIter += 3;

        Psx_gte_nct_449B30();

        pScratch[0] = gGte_RGB0_993F10;
        pScratch[1] = gGte_RGB1_993F14;
        pScratch[2] = gGte_RGB2_993F18;

        pScratch += 3;
    }
}
MGS_FUNC_IMPLEX(0x405428, LibGV_405428, LIBDG_IMPL);

static void Stub_Psx_gte_nct_449B30()
{
    gGte_RGB0_993F10 = { 10,11,12,13 };
    gGte_RGB1_993F14 = { 14,15,16,17 };
    gGte_RGB2_993F18 = { 18,19,110,111 };
}

inline bool operator == (const CVECTOR& lhs, const CVECTOR& rhs)
{
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.cd == rhs.cd);
}

static void Test_LibGV_405428()
{
    SCOPED_REDIRECT(Psx_gte_nct_449B30, Stub_Psx_gte_nct_449B30);

    memset(&gScratchPadMemory_991E40, 0, 1024);

    SVECTOR normals[9] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {40,50,60,70},

        { 21,22,23,24 },
        { 25,26,27,28 },
        { 29,210,211,212 },

        { 1,2,3,4 },
        { 5,6,7,8 },
        { 33,44,55,66 },

    };
    kmdObject kmdObj = {};
    kmdObj.numNorms_40 = 6;
    kmdObj.normOfs_44 = normals;

    LibGV_405428(&kmdObj);

    const Scratch_405428* pScratcPad = (Scratch_405428*)&gScratchPadMemory_991E40;
    const CVECTOR* ptr = &pScratcPad->field_20[0];
 
    ASSERT_EQ(gGte_RGB0_993F10, ptr[0]);
    ASSERT_EQ(gGte_RGB1_993F14, ptr[1]);
    ASSERT_EQ(gGte_RGB2_993F18, ptr[2]);
}


void CC LibGV_4053D1(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    POLY_GT4* pPrimBufferIter = pMesh->field_54_prim_buffers[activeBuffer];
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    do
    {
        LibGV_405428(pMeshIter->field_40_pKmdObj);  // populate scratch 
        if (pMeshIter->field_40_pKmdObj->field_0_flags & 0x10000)
        {
            pPrimBufferIter = LibGV_indexed_normals_40556A(
                (unsigned int*)pMeshIter->field_40_pKmdObj->normIndex_48, // TODO: Check types
                pPrimBufferIter,
                pMeshIter->field_52_num_faces,
                (unsigned int*)pMeshIter->field_40_pKmdObj->indexOfs_3C); // TODO: Check types
        }
        else
        {
            pPrimBufferIter = LibGV_normals_4054F2(
                (unsigned int*)pMeshIter->field_40_pKmdObj->normIndex_48,// TODO: Check types
                pPrimBufferIter, 
                pMeshIter->field_52_num_faces); 
        }
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);
}
MGS_FUNC_IMPLEX(0x4053D1, LibGV_4053D1, LIBDG_IMPL);

void CC LibGV_lights_405180(struct_gv* pGv, int activeBuffer)
{
    Prim_Union** pObjects = pGv->mQueue;
    if (pGv->mTotalObjectCount > 0)
    {
        int numObjects = pGv->mTotalObjectCount;
        do
        {
            Prim_Union* pObject = *pObjects;
            ++pObjects;
            if (pObject)
            {
                PSX_MATRIX* pLightMtxAry = pObject->prim_48.field_34_light_mtx_array;
                if (pLightMtxAry)
                {
                    if (pObject->prim_48.field_32)
                    {
                        if (pObject->prim_48.field_28_flags_or_type & 8)
                        {
                            gte_rotation_matrix_993E40 = pLightMtxAry[0].m;
                            gGte_light_colour_matrix_source_993E80 = pLightMtxAry[1].m;

                            if (pObject->prim_48.field_28_flags_or_type & 0x100)
                            {
                                gGte_background_colour_993E74.field_0_x = 16 * pObject->prim_48.field_34_light_mtx_array->t.field_0_x;
                                gGte_background_colour_993E74.field_4_y = 16 * pObject->prim_48.field_34_light_mtx_array->t.field_4_y;
                                gGte_background_colour_993E74.field_8_z = 16 * pObject->prim_48.field_34_light_mtx_array->t.field_8_z;
                            }

                            Prim_Mesh_0x5C* pMeshIter = (Prim_Mesh_0x5C *)(&pObject->prim_48 + 1);

                            if (pObject->prim_48.field_2E_UnknownOrNumFaces > 0)
                            {
                                int count = pObject->prim_48.field_2E_UnknownOrNumFaces;
                                do
                                {
                                    if (pMeshIter->field_4C_bounding_ret)
                                    {
                                        gGte_IR1_993EE4.IR_32 = pMeshIter->field_0_mtx.m.m[0][0];
                                        gGte_IR2_993EE8.IR_32 = pMeshIter->field_0_mtx.m.m[1][0];
                                        gGte_IR3_993EEC.IR_32 = pMeshIter->field_0_mtx.m.m[2][0];
                                        Psx_gte_RT1_rtir_447480();
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[0][0] = gGte_IR1_993EE4.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[1][0] = gGte_IR2_993EE8.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[2][0] = gGte_IR3_993EEC.IR_16;

                                        gGte_IR1_993EE4.IR_32 = pMeshIter->field_0_mtx.m.m[0][1];
                                        gGte_IR2_993EE8.IR_32 = pMeshIter->field_0_mtx.m.m[1][1];
                                        gGte_IR3_993EEC.IR_32 = pMeshIter->field_0_mtx.m.m[2][1];
                                        Psx_gte_RT1_rtir_447480();
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[0][1] = gGte_IR1_993EE4.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[1][1] = gGte_IR2_993EE8.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[2][1] = gGte_IR3_993EEC.IR_16;

                                        gGte_IR1_993EE4.IR_32 = pMeshIter->field_0_mtx.m.m[0][2];
                                        gGte_IR2_993EE8.IR_32 = pMeshIter->field_0_mtx.m.m[1][2];
                                        gGte_IR3_993EEC.IR_32 = pMeshIter->field_0_mtx.m.m[2][2];
                                        Psx_gte_RT1_rtir_447480();
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[0][2] = gGte_IR1_993EE4.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[1][2] = gGte_IR2_993EE8.IR_16;
                                        gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m.m[2][2] = gGte_IR3_993EEC.IR_16;

                                        gGte_light_source_matrix_993E60 = gScratchPadMemory_991E40.field_2_Matrix.mtx[0].m;
                                        LibGV_4053D1(pMeshIter, activeBuffer);
                                    }
                                    ++pMeshIter;
                                    --count;
                                } while (count);
                            }


                            if (pObject->prim_48.field_28_flags_or_type & 0x100)
                            {
                                gGte_background_colour_993E74.field_0_x = 16 * light_r_word_6BEE70;
                                gGte_background_colour_993E74.field_4_y = 16 * light_g_word_6BEE72;
                                gGte_background_colour_993E74.field_8_z = 16 * light_b_word_6BEE74;
                            }
                        }
                    }
                }
            }
            --numObjects;
        } while (numObjects);
    }
}
MGS_FUNC_IMPLEX(0x405180, LibGV_lights_405180, LIBDG_IMPL);


MGS_VAR(1, 0x6BEF18, Texture_Record, stru_6BEF18, {});

void CC LibGV_apply_texture_to_quads_4071E1(Texture_Record* pTexture, BYTE* pUvs, POLY_GT4* pPolyGT4)
{
    DWORD u0 = pTexture->u0;
    DWORD v0 = pTexture->v0;
    DWORD u11 = pTexture->u1 + 1;
    DWORD v11 = pTexture->v1 + 1;

    pPolyGT4->u0 = static_cast<BYTE>(u0 + u11 * pUvs[0] / 256);
    pPolyGT4->v0 = static_cast<BYTE>(v0 + v11 * pUvs[1] / 256);

    pPolyGT4->u1 = static_cast<BYTE>(u0 + u11 * pUvs[2] / 256);
    pPolyGT4->v1 = static_cast<BYTE>(v0 + v11 * pUvs[3] / 256);
   
    pPolyGT4->u2 = static_cast<BYTE>(u0 + u11 * pUvs[6] / 256);
    pPolyGT4->v2 = static_cast<BYTE>(v0 + v11 * pUvs[7] / 256);
    
    pPolyGT4->u3 = static_cast<BYTE>(u0 + u11 * pUvs[4] / 256);
    pPolyGT4->v3 = static_cast<BYTE>(v0 + v11 * pUvs[5] / 256);

    pPolyGT4->tpage = pTexture->mTPage;
    pPolyGT4->clut = pTexture->mClut;
}
MGS_FUNC_IMPLEX(0x4071E1, LibGV_apply_texture_to_quads_4071E1, LIBDG_IMPL);

static void Test_LibGV_apply_texture_to_quads_4071E1()
{
    Texture_Record tr = {};
    tr.u0 = 5;
    tr.v0 = 10;
    tr.u1 = 15;
    tr.v1 = 20;

    BYTE uvs[8] = {1,2,3,4,5,6,7,8};
    POLY_GT4 poly = {};
    LibGV_apply_texture_to_quads_4071E1(&tr, uvs, &poly);

    ASSERT_EQ(poly.u0, 5);
    ASSERT_EQ(poly.v0, 10);

    ASSERT_EQ(poly.u1, 5);
    ASSERT_EQ(poly.v1, 10);

    ASSERT_EQ(poly.u2, 5);
    ASSERT_EQ(poly.v2, 10);

    ASSERT_EQ(poly.u3, 5);
    ASSERT_EQ(poly.v3, 10);
}

int CC LibGV_prim_buffer_allocate_407354(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    // Get number of polys
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    int totalCount = 0;
    do
    {
        totalCount += pMeshIter->field_52_num_faces;
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);

    // Allocate
    void* alloc = System_mem_zerod_alloc_40AFA4(activeBuffer, totalCount * sizeof(POLY_GT4), (void**)&pMesh->field_54_prim_buffers[activeBuffer]);
    if (alloc)
    {
        return 1;
    }
    return -1;
}
MGS_FUNC_IMPLEX(0x407354, LibGV_prim_buffer_allocate_407354, LIBDG_IMPL);

void CC LibGV_prim_buffer_init_polyGT4s_40738D(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    POLY_GT4* pPrimBufferIter = pMesh->field_54_prim_buffers[activeBuffer];
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    do
    {
        for (int i = 0; i < pMeshIter->field_52_num_faces; i++)
        {
            setPolyGT4(pPrimBufferIter);
            pPrimBufferIter->code |= pMesh->field_40_pKmdObj->field_0_flags & 2;
            setRGB0(pPrimBufferIter, 128, 128, 128);
            setRGB1(pPrimBufferIter, 128, 128, 128);
            setRGB2(pPrimBufferIter, 128, 128, 128);
            setRGB3(pPrimBufferIter, 128, 128, 128);
            pPrimBufferIter++;
        }
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);
}
MGS_FUNC_IMPLEX(0x40738D, LibGV_prim_buffer_init_polyGT4s_40738D, LIBDG_IMPL);

void CC LibGV_prim_buffer_set_shade_colour_4072B7(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    POLY_GT4* pPrimBufferIter = pMesh->field_54_prim_buffers[activeBuffer];
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    do
    {
        CVECTOR* pVec = pMeshIter->field_44_light_colour_buffer;
        for (int i = 0; i < pMeshIter->field_52_num_faces; i++)
        {
            setRGB0(pPrimBufferIter, pVec[0].r, pVec[0].g, pVec[0].b);
            setRGB1(pPrimBufferIter, pVec[1].r, pVec[1].g, pVec[1].b);
            setRGB2(pPrimBufferIter, pVec[3].r, pVec[3].g, pVec[3].b);
            setRGB3(pPrimBufferIter, pVec[2].r, pVec[2].g, pVec[2].b);
            pPrimBufferIter++;
            pVec += 4;
        }
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);
}
MGS_FUNC_IMPLEX(0x4072B7, LibGV_prim_buffer_set_shade_colour_4072B7, LIBDG_IMPL);

static void Test_LibGV_prim_buffer_init_polyGT4s_40738D()
{
    POLY_GT4 prim = {};
    Prim_Mesh_0x5C mesh = {};
    kmdObject kmdObj = {};
    mesh.field_40_pKmdObj = &kmdObj;
    mesh.field_40_pKmdObj->field_0_flags = 2;
    mesh.field_52_num_faces = 1;
    mesh.field_54_prim_buffers[0] = &prim;

    LibGV_prim_buffer_init_polyGT4s_40738D(&mesh, 0);
    ASSERT_EQ(prim.code, 0x3E);

    mesh.field_40_pKmdObj->field_0_flags = 0;
    LibGV_prim_buffer_init_polyGT4s_40738D(&mesh, 0);
    ASSERT_EQ(prim.code, 0x3C);
}

void CC LibGV_406168(struct_gv* pGv, int activeBuffer)
{
    Prim_Union** ppObjects = pGv->mQueue;
    for (int i = 0; i < pGv->mTotalObjectCount; i++)
    {
        Prim_unknown_0x48* pObject = &ppObjects[i]->prim_48;
        if (pObject->field_32)
        {
            Prim_Mesh_0x5C* pMeshIter = DataAfterStructure<Prim_Mesh_0x5C*>(pObject);
            for (int j = 0; j < pObject->field_2E_UnknownOrNumFaces; j++)
            {
                if (pMeshIter[j].field_4C_bounding_ret)
                {
                    int totalFaceCount = 0;
                    Prim_Mesh_0x5C* pLinked = pMeshIter;
                    do
                    {
                        totalFaceCount += pLinked->field_52_num_faces;
                        pLinked = pLinked->field_48_pLinked;
                    } while (pLinked);

                    if (pMeshIter->field_54_prim_buffers[activeBuffer])
                    {
                        for (int k = 0; k < totalFaceCount; k++)
                        {
                            POLY_GT4* pPoly = pMeshIter->field_54_prim_buffers[activeBuffer];
                            pPoly[k].pad2 = 0;
                        }
                    }
                }
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x406168, LibGV_406168, LIBDG_IMPL);

static void Test_LibGV_406168()
{
    struct_gv gv = {};
    gv.mTotalObjectCount = 1;
 
    struct TestPrim
    {
        Prim_unknown_0x48 mPrim;
        Prim_Mesh_0x5C mMesh[2];
    };

    TestPrim prim = {};
    POLY_GT4 faces[2] = {};
    prim.mPrim.field_32 = 1;
    prim.mPrim.field_2E_UnknownOrNumFaces = 1;
    prim.mMesh[0].field_4C_bounding_ret = 1;
    prim.mMesh[0].field_52_num_faces = 1;
    prim.mMesh[0].field_54_prim_buffers[0] = faces;
    memset(&faces[0], 1, sizeof(POLY_GT4));

    Prim_Union* prims[] = { reinterpret_cast<Prim_Union*>(&prim) };
    gv.mQueue = prims;

    ASSERT_EQ(faces[0].pad2, 0x0101);
    LibGV_406168(&gv, 0);
    ASSERT_EQ(faces[0].pad2, 0);
}

struct ScratchPad_405668 // TODO: Add to union and figure out other pad fields
{
    WORD pad1[254];
    WORD field_1FC_flags2;
    WORD flags;
    WORD pad2[252];
    POLY_GT4* pPolys;
    SVECTOR* pVerts;
};
MGS_ASSERT_SIZEOF(ScratchPad_405668, 0x400);

MGS_FUNC_NOT_IMPL(0x4057FF, void __cdecl (SVECTOR *vertPtr, int vertCount), LibGV_4057FF);
MGS_FUNC_NOT_IMPL(0x405DAF, POLY_GT4 *__cdecl (unsigned int* pVertIdxes, POLY_GT4 *pPoly, int faceCount), LibGV_helper_405DAF);

template<class T>
static void Vec2Reg(T& reg, const SVECTOR& v)
{
    reg.regs.VX = v.field_0_x;
    reg.regs.VY = v.field_2_y;
    reg.regs.VZ = v.field_4_z;
    reg.regs.Zero = v.field_6_padding;
}

struct FVECTOR
{
    float field_0_x, field_4_y, field_8_z;
};
MGS_ASSERT_SIZEOF(FVECTOR, 0xC);

struct UnknownData
{
    FVECTOR mArray[42];
    DWORD pad[2];
};
MGS_ARY(1, 0x992240, UnknownData, 3, stru_992240, {});

struct ScratchPad_ProjectedVerts // TODO: Add to union
{
    struct XYRet
    {
        short x;
        short y;
    };

    struct XYVec
    {
        XYRet mXY[3];
    };

    struct OTZAry
    {
        int mZ[3];
    };

    XYVec xys[42];
    DWORD pad[2];
    OTZAry zs[42];
};

void CC LibGV_helper_405B8A(SVECTOR* vertPtr, int vertCount)
{
    assert(vertCount <= 42*3);

    ScratchPad_ProjectedVerts* pScratch = (ScratchPad_ProjectedVerts*)&gScratchPadMemory_991E40; // TODO: Add to union

    // TODO: Move duplication to a helper
    Vec2Reg(gGte_VXY0_993EC0, *vertPtr);
    vertPtr++;

    Vec2Reg(gGte_VXY1_993EC8, *vertPtr);
    vertPtr++;

    Vec2Reg(gGte_VXY2_993ED0, *vertPtr);
    vertPtr++;

    Psx_gte_rtpt_445990();

    pScratch->xys[0].mXY[0].x = gGte_SXY0_993EF0.regs.SX;
    pScratch->xys[0].mXY[0].y = gGte_SXY0_993EF0.regs.SY;

    pScratch->xys[0].mXY[1].x = gGte_SXY1_993EF4.regs.SX;
    pScratch->xys[0].mXY[1].y = gGte_SXY1_993EF4.regs.SY;

    pScratch->xys[0].mXY[2].x = gGte_SXY2_993EF8.regs.SX;
    pScratch->xys[0].mXY[2].y = gGte_SXY2_993EF8.regs.SY;
    
    pScratch->zs[0].mZ[0] = gGte_SZ1_993F04.Z_32;
    pScratch->zs[0].mZ[1] = gGte_SZ2_993F08.Z_32;
    pScratch->zs[0].mZ[2] = gGte_SZ3_993F0C.Z_32;

    for (int j = 0; j < 3; j++)
    {
        stru_992240[j].mArray[0].field_0_x = gGte_unknown_72270C.d[j].field_4_prev_8[0];
        stru_992240[j].mArray[0].field_4_y = gGte_unknown_72270C.d[j].field_4_prev_8[1];
        stru_992240[j].mArray[0].field_8_z = gGte_unknown_72270C.d[j].field_4_prev_8[2];
    }

    if (vertCount - 3 > 0)
    {
        const int count = (vertCount - 3 + 2) / 3u;
        for (int i = 1; i < count + 1; i++)
        {
            Vec2Reg(gGte_VXY0_993EC0, *vertPtr);
            vertPtr++;

            Vec2Reg(gGte_VXY1_993EC8, *vertPtr);
            vertPtr++;

            Vec2Reg(gGte_VXY2_993ED0, *vertPtr);
            vertPtr++;

            Psx_gte_rtpt_445990();

            // Store projected 3D -> 2D coordinates
            pScratch->xys[i].mXY[0].x = gGte_SXY0_993EF0.regs.SX;
            pScratch->xys[i].mXY[0].y = gGte_SXY0_993EF0.regs.SY;

            pScratch->xys[i].mXY[1].x = gGte_SXY1_993EF4.regs.SX;
            pScratch->xys[i].mXY[1].y = gGte_SXY1_993EF4.regs.SY;

            pScratch->xys[i].mXY[2].x = gGte_SXY2_993EF8.regs.SX;
            pScratch->xys[i].mXY[2].y = gGte_SXY2_993EF8.regs.SY;

            // Store OTZ's
            pScratch->zs[i].mZ[0] = gGte_SZ1_993F04.Z_32;
            pScratch->zs[i].mZ[1] = gGte_SZ2_993F08.Z_32;
            pScratch->zs[i].mZ[2] = gGte_SZ3_993F0C.Z_32;

            // Extra higher precision float copies of the projected values to fix the polygon "wobble"
            for (int j = 0; j < 3; j++)
            {
                stru_992240[j].mArray[i].field_0_x = gGte_unknown_72270C.d[j].field_4_prev_8[0];
                stru_992240[j].mArray[i].field_4_y = gGte_unknown_72270C.d[j].field_4_prev_8[1];
                stru_992240[j].mArray[i].field_8_z = gGte_unknown_72270C.d[j].field_4_prev_8[2];
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x405B8A, LibGV_helper_405B8A, LIBDG_IMPL);

static void CC Stub_Psx_gte_rtpt_445990()
{
    static int c = 0;

    gGte_SXY0_993EF0.regs.SX = static_cast<short>(10 + c);
    gGte_SXY0_993EF0.regs.SY = static_cast<short>(20 + c);

    gGte_SXY1_993EF4.regs.SX = static_cast<short>(30 + c);
    gGte_SXY1_993EF4.regs.SY = static_cast<short>(40 + c);

    gGte_SXY2_993EF8.regs.SX = static_cast<short>(50 + c);
    gGte_SXY2_993EF8.regs.SY = static_cast<short>(60 + c);

    gGte_SZ1_993F04.Z_32 = 70 + c;
    gGte_SZ2_993F08.Z_32 = 80 + c;
    gGte_SZ3_993F0C.Z_32 = 90 + c;
    c++;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gGte_unknown_72270C.d[i].field_4_prev_8[j] = 1.0f * (i + 1) * (j + 1) + c;
        }
    }
}

static void Test_LibGV_helper_405B8A()
{
    SCOPED_REDIRECT(Psx_gte_rtpt_445990, Stub_Psx_gte_rtpt_445990);

    SVECTOR verts[126] = {};
    for (int i = 0; i < _countof(verts); i++)
    {
        verts[i].field_0_x = static_cast<short>(10 + i);
        verts[i].field_2_y = static_cast<short>(20 + i);
        verts[i].field_4_z = static_cast<short>(30 + i);
        verts[i].field_6_padding = static_cast<short>(40 + i);
    }

    memset(&gScratchPadMemory_991E40, 0, 1024);

    LibGV_helper_405B8A(verts, _countof(verts));


    ScratchPad_ProjectedVerts* pScratch = (ScratchPad_ProjectedVerts*)&gScratchPadMemory_991E40; // TODO: Add to union

    ASSERT_EQ(pScratch->xys[0].mXY[0].x, 10);
    ASSERT_EQ(pScratch->xys[0].mXY[0].y, 20);

    ASSERT_EQ(pScratch->xys[0].mXY[1].x, 30);
    ASSERT_EQ(pScratch->xys[0].mXY[1].y, 40);

    ASSERT_EQ(pScratch->xys[0].mXY[2].x, 50);
    ASSERT_EQ(pScratch->xys[0].mXY[2].y, 60);

    ASSERT_EQ(pScratch->xys[41].mXY[0].x, 51);
    ASSERT_EQ(pScratch->xys[41].mXY[0].y, 61);

    ASSERT_EQ(pScratch->xys[41].mXY[1].x, 71);
    ASSERT_EQ(pScratch->xys[41].mXY[1].y, 81);

    ASSERT_EQ(pScratch->xys[41].mXY[2].x, 91);
    ASSERT_EQ(pScratch->xys[41].mXY[2].y, 101);
    
    ASSERT_EQ(pScratch->zs[0].mZ[0], 70);
    ASSERT_EQ(pScratch->zs[0].mZ[1], 80);
    ASSERT_EQ(pScratch->zs[0].mZ[2], 90);

    ASSERT_EQ(pScratch->zs[41].mZ[0], 111);
    ASSERT_EQ(pScratch->zs[41].mZ[1], 121);
    ASSERT_EQ(pScratch->zs[41].mZ[2], 131);
    
    ASSERT_EQ(stru_992240[0].mArray[0].field_0_x, 2.0f);
    ASSERT_EQ(stru_992240[0].mArray[0].field_4_y, 3.0f);
    ASSERT_EQ(stru_992240[0].mArray[0].field_8_z, 4.0f);

    ASSERT_EQ(stru_992240[0].mArray[41].field_0_x, 43.0f);
    ASSERT_EQ(stru_992240[0].mArray[41].field_4_y, 44.0f);
    ASSERT_EQ(stru_992240[0].mArray[41].field_8_z, 45.0f);

    UnknownData* pStru1= &stru_992240[1];
    ASSERT_EQ(pStru1->mArray[0].field_0_x, 3.0f);
    ASSERT_EQ(pStru1->mArray[0].field_4_y, 5.0f);
    ASSERT_EQ(pStru1->mArray[0].field_8_z, 7.0f);

    UnknownData* pStru2 = &stru_992240[2];
    ASSERT_EQ(pStru2->mArray[0].field_0_x, 4.0f);
    ASSERT_EQ(pStru2->mArray[0].field_4_y, 7.0f);
    ASSERT_EQ(pStru2->mArray[0].field_8_z, 10.0f); 
}

void CC LibGV_4057A0(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    ScratchPad_405668* pScratch = (ScratchPad_405668*)&gScratchPadMemory_991E40; // TODO: Add to union
    POLY_GT4* pPolyIter = pMesh->field_54_prim_buffers[activeBuffer];
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    do
    {
        kmdObject* pKmd = pMeshIter->field_40_pKmdObj;
        if (pScratch->flags & 1)
        {
            LibGV_4057FF(pKmd->vertOfs_38, pKmd->numVerts_34);
        }
        else
        {
            LibGV_helper_405B8A(pKmd->vertOfs_38, pKmd->numVerts_34);
        }
        pScratch->field_1FC_flags2 = pKmd->field_0_flags & 0x400;
        // TODO: Check type of indexOfs_3C
        pPolyIter = LibGV_helper_405DAF((unsigned int*)pKmd->indexOfs_3C, pPolyIter, pMeshIter->field_52_num_faces);
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);
}
MGS_FUNC_IMPLEX(0x4057A0, LibGV_4057A0, LIBDG_IMPL);

void CC LibGV_405668(struct_gv* pGv, int activeBuffer)
{
    LibGV_406168(pGv, activeBuffer);
    Gte_project_distance_rect_401DA8(&pGv->dword_6BC3C8_pStructure_rect, pGv->word_6BC3BC);

    ScratchPad_405668* pScratch = (ScratchPad_405668*)&gScratchPadMemory_991E40; // TODO: Add to union

    for (int i = 0; i < pGv->mTotalObjectCount; i++)
    {
        Prim_unknown_0x48* pObject = &pGv->mQueue[i]->prim_48;
        if (pObject->field_32)
        {
            const unsigned int bFlag5 = (~pObject->field_28_flags_or_type >> 5) & 1;
            Prim_Mesh_0x5C* pMesh = DataAfterStructure<Prim_Mesh_0x5C*>(pObject);
            for (int j = 0; j < pObject->field_2E_UnknownOrNumFaces; j++)
            {
                if (pMesh[j].field_4C_bounding_ret)
                {
                    kmdObject* pObjKmd = pMesh[j].field_40_pKmdObj;

                    pScratch->pPolys = pMesh[pObjKmd->mRef_2C_parentObjIndex].field_54_prim_buffers[gActiveBuffer_dword_791A08];
                    pScratch->pVerts = pObjKmd->vertOfs_38;

                    gte_rotation_matrix_993E40 = pMesh[j].field_20_mtx.m;
                    gGte_translation_vector_993E54 = pMesh[j].field_20_mtx.t;

                    pScratch->flags = bFlag5 && pMesh[j].field_4C_bounding_ret == 1;

                    if (pObject->field_28_flags_or_type & 8)
                    {
                        pScratch->flags |= 4u;
                    }
                    LibGV_4057A0(&pMesh[j], activeBuffer);
                }
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x405668, LibGV_405668, LIBDG_IMPL);

void CC LibGV_prim_buffer_apply_textures_407163(Prim_Mesh_0x5C* pMeshObj, int activeBuffer)
{
    Prim_Mesh_0x5C* pLinked = pMeshObj;
    POLY_GT4* pPolys = pMeshObj->field_54_prim_buffers[activeBuffer];
    if (pPolys)
    {
        WORD lastTextureHash = 0;
        for (Texture_Record* pRec = &stru_6BEF18; pLinked; pLinked = pLinked->field_48_pLinked)
        {
            kmdObject* pKmd = pLinked->field_40_pKmdObj;
            WORD* pUnk = pKmd->ofsTextureNameHashes_50;
            BYTE* pUvs = pKmd->ofsUV_4C;
            if (pLinked->field_52_num_faces > 0)
            {
                int count = pLinked->field_52_num_faces;
                do
                {
                    WORD textureHash = *pUnk;
                    ++pUnk;
                    if (textureHash != lastTextureHash)
                    {
                        lastTextureHash = textureHash;
                        pRec = LibDG_FindTexture_4024A0(textureHash);
                    }
                    LibGV_apply_texture_to_quads_4071E1(pRec, pUvs, pPolys);
                    ++pPolys;
                    pUvs += 8;
                    --count;
                } while (count);
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x407163, LibGV_prim_buffer_apply_textures_407163, LIBDG_IMPL);

int CC LibGV_prim_buffer_allocate_texture_and_shade_40730A(Prim_Mesh_0x5C* pMeshObj, int activeBuffer, BYTE flags)
{
    if (LibGV_prim_buffer_allocate_407354(pMeshObj, activeBuffer) < 0)
    {
        return -1;
    }

    LibGV_prim_buffer_init_polyGT4s_40738D(pMeshObj, activeBuffer);
    if (flags & 1)
    {
        LibGV_prim_buffer_apply_textures_407163(pMeshObj, activeBuffer);
    }

    if (flags & 2)
    {
        LibGV_prim_buffer_set_shade_colour_4072B7(pMeshObj, activeBuffer);
    }
    return 0;
}
MGS_FUNC_IMPLEX(0x40730A, LibGV_prim_buffer_allocate_texture_and_shade_40730A, LIBDG_IMPL);

BYTE* CC LibGV_40466A(Prim_unknown_0x54* pObj, BYTE* pPolys, int polyCount)
{
    struct XY
    {
        short x, y;
    };

    SVECTOR* pScratch = (SVECTOR *)&gScratchPadMemory_991E40; // TODO: Add to union
    for (int i=0; i<polyCount; i++)
    {
        BYTE* pCurrentPolyXY = &pPolys[pObj->field_34_primF3];

        // Set OTZ
        *reinterpret_cast<WORD*>(pPolys) = pScratch->field_4_z;

        for (int j=0; j<(pObj->field_32_primF2_vert_count & 4); j++)
        {
            // Set X,Y
            XY* pXy = reinterpret_cast<XY*>(pCurrentPolyXY);
            pXy->x = pScratch->field_0_x;
            pXy->y = pScratch->field_2_y;

            // To next X,Y
            pCurrentPolyXY += pObj->field_36_primF4;

            // To next source X,Y
            pScratch++;
        }
        pPolys += pObj->field_30_prim_size;
    }
    return pPolys;
}
MGS_FUNC_IMPLEX(0x40466A, LibGV_40466A, LIBDG_IMPL);

struct Test_Prim_unknown_0x54
{
    Prim_unknown_0x54 mPrim;
    POLY_FT4 mPolys[5];
};

static void Test_LibGV_40466A()
{
    Test_Prim_unknown_0x54 test = {};
    test.mPrim.field_30_prim_size = 40;
    test.mPrim.field_32_primF2_vert_count = 4;
    test.mPrim.field_34_primF3 = 8;
    test.mPrim.field_36_primF4 = 8;
    test.mPrim.field_40_pDataStart[0] = reinterpret_cast<BYTE*>(&test.mPolys[0]);

    memset(gScratchPadMemory_991E40.field_0_raw.field_0, 0, 1024);
    SVECTOR* pScratch = (SVECTOR *)&gScratchPadMemory_991E40;
    short v = 0;
    short z = 1234;
    for (int i = 0; i < 5 * 4; i++)
    {
        pScratch[i].field_0_x = v++;
        pScratch[i].field_2_y = v++;
        pScratch[i].field_4_z = z++;
        pScratch[i].field_6_padding = 0; // Padding is never used by the func
 
    }

    LibGV_40466A(&test.mPrim, test.mPrim.field_40_pDataStart[0], 5);

    ASSERT_EQ(1234, test.mPolys[0].tag);
    ASSERT_EQ(0, test.mPolys[0].x0);
    ASSERT_EQ(1, test.mPolys[0].y0);
    ASSERT_EQ(2, test.mPolys[0].x1);
    ASSERT_EQ(3, test.mPolys[0].y1);
    ASSERT_EQ(4, test.mPolys[0].x2);
    ASSERT_EQ(5, test.mPolys[0].y2);
    ASSERT_EQ(6, test.mPolys[0].x3);
    ASSERT_EQ(7, test.mPolys[0].y3);

    ASSERT_EQ(1238, test.mPolys[1].tag);
    ASSERT_EQ(8, test.mPolys[1].x0);
    ASSERT_EQ(9, test.mPolys[1].y0);
    ASSERT_EQ(10, test.mPolys[1].x1);
    ASSERT_EQ(11, test.mPolys[1].y1);
    ASSERT_EQ(12, test.mPolys[1].x2);
    ASSERT_EQ(13, test.mPolys[1].y2);
    ASSERT_EQ(14, test.mPolys[1].x3);
    ASSERT_EQ(15, test.mPolys[1].y3);
}

void CC LibGV_4044E8(Prim_unknown_0x54* pPrim)
{
    const int vertCount = pPrim->field_32_primF2_vert_count;
    int count = 0;
    int numItems = 0;
    if (vertCount == 4)
    {
        count = 40;
        numItems = 30;
    }
    else
    {
        count = 42;
        numItems = 126 / vertCount;
    }
    Prim_24b* p24Struct = pPrim->field_38_size24b;
    BYTE* pPrimBuffer = pPrim->field_40_pDataStart[gActiveBuffer_dword_791A08];
    int i = 0;
    for (i = pPrim->field_2A_num_prims; i > numItems; i -= numItems)
    {
        p24Struct = LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, count);
        pPrimBuffer = LibGV_40466A(pPrim, pPrimBuffer, numItems);
    }
    LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, (vertCount * i + 2) / 3);
    LibGV_40466A(pPrim, pPrimBuffer, i);
}
MGS_FUNC_IMPLEX(0x4044E8, LibGV_4044E8, LIBDG_IMPL);

MGS_FUNC_NOT_IMPL(0x404823, BYTE *__cdecl (Prim_unknown_0x54 *pObj, BYTE *pPrimBuffer, int count), LibGV_404823);

void CC LibGV_404766(Prim_unknown_0x54* pPrim)
{
    const int vertCount = pPrim->field_32_primF2_vert_count;
    int count = 0;
    int numItems = 0;
    if (vertCount == 4)
    {
        count = 40;
        numItems = 30;
    }
    else
    {
        count = 42;
        numItems = 126 / vertCount;
    }
    Prim_24b* p24Struct = pPrim->field_38_size24b;
    BYTE* pPrimBuffer = pPrim->field_40_pDataStart[gActiveBuffer_dword_791A08];
    int i = 0;
    for (i = pPrim->field_2A_num_prims; i > numItems; i -= numItems)
    {
        p24Struct = LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, count);
        pPrimBuffer = LibGV_404823(pPrim, pPrimBuffer, numItems);
    }
    LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, (vertCount * i + 2) / 3);
    LibGV_404823(pPrim, pPrimBuffer, i);
}
MGS_FUNC_IMPLEX(0x404766, LibGV_404766, LIBDG_IMPL);

void CC LibGV_SingleVert_40498B(Prim_unknown_0x54* pPrim)
{
    Prim_24b* p24Struct = pPrim->field_38_size24b;
    BYTE* pPrimBuffer = pPrim->field_40_pDataStart[gActiveBuffer_dword_791A08];
    int count = 0;
    for (count = pPrim->field_2A_num_prims; count > 126; count -= 126)
    {
        p24Struct = LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, 42);
        pPrimBuffer = LibGV_404A0F(pPrim, pPrimBuffer, 126);
    }
    LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, (count + 2) / 3);
    LibGV_404A0F(pPrim, pPrimBuffer, count);
}
MGS_FUNC_IMPLEX(0x40498B, LibGV_SingleVert_40498B, LIBDG_IMPL);

void CC LibGV_MultiVert_404AB2(Prim_unknown_0x54* pPrim)
{
    Prim_24b* p24Struct = pPrim->field_38_size24b;
    BYTE* pPrimBuffer = pPrim->field_40_pDataStart[gActiveBuffer_dword_791A08];
    int count = 0;
    for (count = pPrim->field_2A_num_prims; count > 123; count -= 123)
    {
        p24Struct = LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, 41);
        pPrimBuffer = LibGV_404B36(pPrim, pPrimBuffer, 123);
    }
    LibGV_ProcessAndStoreInScratch_4045A5(p24Struct, (count + 2) / 3);
    LibGV_404B36(pPrim, pPrimBuffer, count);
}
MGS_FUNC_IMPLEX(0x404AB2, LibGV_MultiVert_404AB2, LIBDG_IMPL);

void CC LibGV_40442C(__int16* pXY0, __int16* pXY1, __int16* pXY2, __int16* pXY3)
{
    const short int pX0 = pXY0[0];
    const short int pX1 = pXY1[0];
    const short int pY0 = pXY0[1];
    const short int pY1 = pXY1[1];

    int xDiff = pX1 - pX0;
    if (pX1 - pX0 < 0)
    {
        xDiff = pX0 - pX1;
    }

    int yDiff = pY1 - pY0;
    if (yDiff < 0)
    {
        yDiff = pY0 - pY1;
    }

    if (xDiff > yDiff)
    {
        pXY2[0] = pX0;      // X2
        pXY2[1] = pY0 + 1;  // Y2
        pXY3[0] = pX1;      // X3
        pXY3[1] = pY1 + 1;  // Y3
    }
    else
    {
        pXY2[0] = pX0 + 2;  // X2
        pXY2[1] = pY0;      // Y2
        pXY3[0] = pX1 + 2;  // X3
        pXY3[1] = pY1;      // Y3
    }
}
MGS_FUNC_IMPLEX(0x40442C, LibGV_40442C, LIBDG_IMPL);

void CC LibGV_Transform_XYs_40436E(Prim_unknown_0x54* pPrims, int type)
{
    if (type == 21)
    {
        POLY_FT4* pIter = reinterpret_cast<POLY_FT4*>(pPrims->field_40_pDataStart[gActiveBuffer_dword_791A08]);
        for (int i = 0; i <  pPrims->field_2A_num_prims; i++)
        {
            LibGV_40442C(&pIter[i].x0, &pIter[i].x1, &pIter[i].x2, &pIter[i].x3);
        }
    }
    else // type == 22s
    {
        POLY_GT4* pIter = reinterpret_cast<POLY_GT4*>(pPrims->field_40_pDataStart[gActiveBuffer_dword_791A08]);
        for (int i = 0; i < pPrims->field_2A_num_prims; i++)
        {
            LibGV_40442C(&pIter[i].x0, &pIter[i].x1, &pIter[i].x2, &pIter[i].x3);
        }
    }
}
MGS_FUNC_IMPLEX(0x40436E, LibGV_Transform_XYs_40436E, LIBDG_IMPL);

void CC LibGV_404E08(const PSX_MATRIX* pMtx, const Prim_unknown_0x54* pObj)
{
    PSX_MATRIX mtx = {};

    gte_rotation_matrix_993E40 = pMtx->m;

    gGte_IR1_993EE4.IR_32 = pObj->field_0_matrix.m.m[0][0];
    gGte_IR2_993EE8.IR_32 = pObj->field_0_matrix.m.m[1][0];
    gGte_IR3_993EEC.IR_32 = pObj->field_0_matrix.m.m[2][0];
    Psx_gte_RT1_rtir_447480();
    mtx.m.m[0][0] = gGte_IR1_993EE4.IR_16;
    mtx.m.m[1][0] = gGte_IR2_993EE8.IR_16;
    mtx.m.m[2][0] = gGte_IR3_993EEC.IR_16;

    gGte_IR1_993EE4.IR_32 = pObj->field_0_matrix.m.m[0][1];
    gGte_IR2_993EE8.IR_32 = pObj->field_0_matrix.m.m[1][1];
    gGte_IR3_993EEC.IR_32 = pObj->field_0_matrix.m.m[2][1];
    Psx_gte_RT1_rtir_447480();
    mtx.m.m[0][1] = gGte_IR1_993EE4.IR_16;
    mtx.m.m[1][1] = gGte_IR2_993EE8.IR_16;
    mtx.m.m[2][1] = gGte_IR3_993EEC.IR_16;

    gGte_IR1_993EE4.IR_32 = pObj->field_0_matrix.m.m[0][2];
    gGte_IR2_993EE8.IR_32 = pObj->field_0_matrix.m.m[1][2];
    gGte_IR3_993EEC.IR_32 = pObj->field_0_matrix.m.m[2][2];
    Psx_gte_RT1_rtir_447480();
    mtx.m.m[0][2] = gGte_IR1_993EE4.IR_16;
    mtx.m.m[1][2] = gGte_IR2_993EE8.IR_16;
    mtx.m.m[2][2] = gGte_IR3_993EEC.IR_16;

    gGte_translation_vector_993E54.field_0_x = pMtx->t.field_0_x;
    gGte_translation_vector_993E54.field_4_y = pMtx->t.field_4_y;
    gGte_translation_vector_993E54.field_8_z = pMtx->t.field_8_z;

    gGte_VXY0_993EC0.regs.VX = static_cast<short int>(pObj->field_0_matrix.t.field_0_x);
    gGte_VXY0_993EC0.regs.VY = static_cast<short int>(pObj->field_0_matrix.t.field_4_y);
    gGte_VXY0_993EC0.regs.VZ = static_cast<short int>(pObj->field_0_matrix.t.field_8_z);
    Psx_gte_RT1TR_rt_4477A0();
    mtx.m.m[1][0] = 58 * mtx.m.m[1][0] / 64;
    mtx.m.m[1][1] = 58 * mtx.m.m[1][1] / 64;
    mtx.m.m[1][2] = 58 * mtx.m.m[1][2] / 64;

    gte_rotation_matrix_993E40 = mtx.m;

    gGte_translation_vector_993E54.field_0_x = gGte_MAC1_993F24.MAC_32;
    gGte_translation_vector_993E54.field_4_y = 58 * gGte_MAC2_993F28.MAC_32 / 64;
    gGte_translation_vector_993E54.field_8_z = gGte_MAC3_993F2C.MAC_32;

}
MGS_FUNC_IMPLEX(0x404E08, LibGV_404E08, LIBDG_IMPL);

static void Test_LibGV_404E08()
{
    Prim_unknown_0x54 obj = {};
    obj.field_0_matrix.t.field_0_x = 50;
    obj.field_0_matrix.t.field_4_y = 100;
    obj.field_0_matrix.t.field_8_z = 150;

    obj.field_0_matrix.m.m[0][0] = 4096 * 2;
    obj.field_0_matrix.m.m[0][1] = 0;
  
    obj.field_0_matrix.m.m[1][0] = 0;
    obj.field_0_matrix.m.m[1][1] = 4096 * 2;

    obj.field_0_matrix.m.m[2][0] = 0;
    obj.field_0_matrix.m.m[2][1] = 4096 * 2;

    LibGV_404E08(&obj.field_0_matrix, &obj);

    ASSERT_EQ(gte_rotation_matrix_993E40.m[0][0], 16384);
    ASSERT_EQ(gte_rotation_matrix_993E40.m[0][1], 0);

    ASSERT_EQ(gte_rotation_matrix_993E40.m[1][0], 0);
    ASSERT_EQ(gte_rotation_matrix_993E40.m[1][1], 14848);

    ASSERT_EQ(gte_rotation_matrix_993E40.m[2][0], 0);
    ASSERT_EQ(gte_rotation_matrix_993E40.m[2][1], 16384);

    ASSERT_EQ(gGte_translation_vector_993E54.field_0_x, 150);
    ASSERT_EQ(gGte_translation_vector_993E54.field_4_y, 271);
    ASSERT_EQ(gGte_translation_vector_993E54.field_8_z, 350);
}

Prim_24b* CC LibGV_ProcessAndStoreInScratch_4045A5(Prim_24b* pIn, int count)
{
    SVECTOR* pOut = (SVECTOR *)&gScratchPadMemory_991E40.field_0_raw.field_0[0]; // TODO: Add to union
    for (int i=0; i<count; i++)
    {
        // Copy inputs
        gGte_VXY0_993EC0.regs.VX = pIn->field_0_v1.field_0_x;
        gGte_VXY0_993EC0.regs.VY = pIn->field_0_v1.field_2_y;
        gGte_VXY0_993EC0.regs.VZ = pIn->field_0_v1.field_4_z;
        gGte_VXY0_993EC0.regs.Zero = pIn->field_0_v1.field_6_padding;

        gGte_VXY1_993EC8.regs.VX = pIn->field_8_v2.field_0_x;
        gGte_VXY1_993EC8.regs.VY = pIn->field_8_v2.field_2_y;
        gGte_VXY1_993EC8.regs.VZ = pIn->field_8_v2.field_4_z;
        gGte_VXY1_993EC8.regs.Zero = pIn->field_8_v2.field_6_padding;

        gGte_VXY2_993ED0.regs.VX = pIn->field_10_v3.field_0_x;
        gGte_VXY2_993ED0.regs.VY = pIn->field_10_v3.field_2_y;
        gGte_VXY2_993ED0.regs.VZ = pIn->field_10_v3.field_4_z;
        gGte_VXY2_993ED0.regs.Zero = pIn->field_10_v3.field_6_padding;

        Psx_gte_rtpt_445990();

        // Copy output X/Y's and Z's
        pOut->field_0_x = gGte_SXY0_993EF0.regs.SX;
        pOut->field_2_y = gGte_SXY0_993EF0.regs.SY;
        pOut->field_4_z = gGte_SZ1_993F04.regs.hi;
        pOut->field_6_padding = 0;
        pOut++;

        pOut->field_0_x = gGte_SXY1_993EF4.regs.SX;
        pOut->field_2_y = gGte_SXY1_993EF4.regs.SY;
        pOut->field_4_z = gGte_SZ2_993F08.regs.hi;
        pOut->field_6_padding = 0;
        pOut++;

        pOut->field_0_x = gGte_SXY2_993EF8.regs.SX;
        pOut->field_2_y = gGte_SXY2_993EF8.regs.SY;
        pOut->field_4_z = gGte_SZ3_993F0C.regs.hi;
        pOut->field_6_padding = 0;
        pOut++;

        pIn++;
    }
    return pIn;
}
MGS_FUNC_IMPLEX(0x4045A5, LibGV_ProcessAndStoreInScratch_4045A5, LIBDG_IMPL);

static void Test_LibGV_4045A5()
{
    gGte_translation_vector_993E54.field_0_x = 50;
    gGte_translation_vector_993E54.field_4_y = 100;
    gGte_translation_vector_993E54.field_8_z = 150;

    Prim_24b test[2] = {};
    test[0].field_0_v1.field_0_x = 1345;
    test[0].field_0_v1.field_2_y = 50;
    test[0].field_0_v1.field_4_z = 70;
    test[0].field_0_v1.field_6_padding = 9999;
    
    test[0].field_8_v2.field_0_x = 6000;
    test[0].field_8_v2.field_2_y = 2;
    test[0].field_8_v2.field_4_z = 9999;

    test[0].field_10_v3.field_0_x = 500;
    test[0].field_10_v3.field_2_y = 1000;
    test[0].field_10_v3.field_4_z = 2000;

    LibGV_ProcessAndStoreInScratch_4045A5(test, 1);
    Prim_24b *pIter = (Prim_24b *)&gScratchPadMemory_991E40.field_0_raw.field_0[0];

    ASSERT_EQ(pIter->field_0_v1.field_4_z, 220);
    ASSERT_EQ(pIter->field_0_v1.field_6_padding, 0);

    ASSERT_EQ(pIter->field_8_v2.field_4_z, 10149);
    ASSERT_EQ(pIter->field_10_v3.field_4_z, 2150);
}

void CC LibGV_404DBA(Prim_unknown_0x54* pObj)
{
    LibGV_ProcessAndStoreInScratch_4045A5(pObj->field_38_size24b, pObj->field_48_count);
    pObj->field_50_pFn(pObj, pObj->field_40_pDataStart[gActiveBuffer_dword_791A08], pObj->field_2A_num_prims);
}
MGS_FUNC_IMPLEX(0x404DBA, LibGV_404DBA, LIBDG_IMPL);

void CC LibGV_4041A5(struct_gv* pGv, int /*activeBuffer*/)
{
    if (pGv->mTotalQueueSize != pGv->mFreePrimCount)
    {
        Gte_project_distance_rect_401DA8(&pGv->dword_6BC3C8_pStructure_rect, pGv->word_6BC3BC);
        Prim_Union** ppObjs = &pGv->mQueue[pGv->mFreePrimCount];
        const unsigned __int16 primTypeMask = static_cast<__int16>(dword_78D32C);
        const int counter = pGv->mTotalQueueSize - pGv->mFreePrimCount;
        for (int i = 0; i < counter; i++)
        {
            Prim_unknown_0x54* pObj = &ppObjs[i]->prim_54;
            const int flags = pObj->field_24_flags2;
            if (!(flags & 0x900) && (!pObj->field_28_flags_or_type || primTypeMask & pObj->field_28_flags_or_type))
            {
                if (flags & 0x200)
                {
                    gte_rotation_matrix_993E40 = gIdentity_matrix_6501F8.m;
                    gGte_translation_vector_993E54 = gIdentity_matrix_6501F8.t;
                }
                else
                {
                    if (pObj->field_20)
                    {
                        pObj->field_0_matrix = *pObj->field_20;
                    }
                    LibGV_404E08(&pGv->field_10_matrix, pObj);
                }
                if (flags & 0x2000)
                {
                    LibGV_404DBA(pObj);
                }
                else if (flags & 0x400)
                {
                    if (pObj->field_32_primF2_vert_count == 1)
                    {
                        // Chaff squares
                        LibGV_SingleVert_40498B(pObj);
                    }
                    else
                    {
                        LibGV_MultiVert_404AB2(pObj);
                    }
                }
                else if (flags & 0x1000)
                {
                    LibGV_404766(pObj);
                }
                else
                {
                    LibGV_4044E8(pObj);
                }
                const int flagsMasked = flags & 0x1F;
                if (flagsMasked == 0x15 || flagsMasked == 0x16)
                {
                    // Square socom laser target and source
                    LibGV_Transform_XYs_40436E(pObj, flagsMasked);
                }
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x4041A5, LibGV_4041A5, LIBDG_IMPL);

struct ScratchPad_Allocs
{
    DWORD** field_0_1024_unk_ptr;
    __int16 field_4;
    __int16 field_6_numObjTranslated;
    int field_8;
    int field_C;
    float field_10_float;
    int field_14_unknown;
    int field_18_2048;
    int field_1C_project_distance;
    POLY_GT4* field_20_pPolyBufferIter;
    system_struct* field_24_sys_ptr;
    LibGV_MemoryAllocation* field_28_gv_alloc;
    DWORD field_2C_max_possible_elements;
    BYTE* field_30_alloc_ptr;
    int field_34_allocated_size;
    PSX_MATRIX* field_38_pMatrix;
    PSX_MATRIX field_3C_matrix;
};
MGS_ASSERT_SIZEOF(ScratchPad_Allocs, 0x5C);

BYTE* CC LibGV_prims_scratch_alloc_403672(int system_index)
{
    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40; // TODO: Add to union

    system_struct* pSystem = System_Get_Max_Allocatable_Element_Count_4036A7(system_index, &pScratch->field_2C_max_possible_elements, sizeof(POLY_GT4));

    pScratch->field_28_gv_alloc = nullptr;
    pScratch->field_24_sys_ptr = pSystem;
    pScratch->field_30_alloc_ptr = System_allocate_with_hint_4036ED(pSystem, &pScratch->field_28_gv_alloc, &pScratch->field_34_allocated_size);

    return pScratch->field_30_alloc_ptr;
}
MGS_FUNC_IMPLEX(0x403672, LibGV_prims_scratch_alloc_403672, LIBDG_IMPL);

BYTE* CC LibGV_Scratch_alloc_POLY_GT4_403ED1()
{
    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40; // TODO: Add to union
    BYTE* pPoly = nullptr;
    while (1)
    {
        pScratch->field_34_allocated_size -= sizeof(POLY_GT4);
        if (pScratch->field_34_allocated_size >= 0)
        {
            break;
        }

        pPoly = System_allocate_with_hint_4036ED(
            pScratch->field_24_sys_ptr,
            &pScratch->field_28_gv_alloc,
            &pScratch->field_34_allocated_size);
        pScratch->field_30_alloc_ptr = pPoly;

        if (pPoly == nullptr)
        {
            pScratch->field_2C_max_possible_elements = 0;
            return nullptr;
        }
    }
    pPoly = pScratch->field_30_alloc_ptr;
    pScratch->field_2C_max_possible_elements--;
    pScratch->field_30_alloc_ptr += sizeof(POLY_GT4);
    return pPoly;
}
MGS_FUNC_IMPLEX(0x403ED1, LibGV_Scratch_alloc_POLY_GT4_403ED1, LIBDG_IMPL);


// TODO: Impl
void CC Psx_gte_403F3C(SVECTOR *, unsigned int *, POLY_GT4 *);
MGS_FUNC_IMPLEX(0x403F3C, Psx_gte_403F3C, true);

void CC Psx_gte_403F3C(SVECTOR * a, unsigned int *b, POLY_GT4 *c)
{
    Psx_gte_403F3C_.Ptr()(a,b,c);
}

// TODO: Impl
void CC LibGV_403845();
MGS_FUNC_IMPLEX(0x403845, LibGV_403845, true);

void CC LibGV_403845()
{
    LibGV_403845_.Ptr()();
}

// TODO: Refactor
POLY_GT4* CC LibGV_Helper_403778(POLY_GT4* pPolyBuffer, int numFaces, SVECTOR* pVerts, unsigned int* pIndcies)
{
    if (numFaces - 1 < 0)
    {
        return pPolyBuffer;
    }

    ScratchPad_Allocs* pAllocs = (ScratchPad_Allocs*)gScratchPadMemory_991E40.field_0_raw.field_0;
    for (int i=0; i<numFaces; i++)
    {
        struct PolyTag2
        {
            WORD field_0_distance;
            BYTE field_2;
            BYTE field_3;
        };

        PolyTag2* polTag = (PolyTag2*)&pPolyBuffer[i].tag;
        int tagByte = pPolyBuffer[i].tag >> 8;
        if (tagByte <= pAllocs->field_18_2048
            || polTag->field_0_distance >= pAllocs->field_1C_project_distance
            || pAllocs->field_2C_max_possible_elements < 4)
        {
            if (polTag->field_0_distance)
            {
                const WORD depth = (polTag->field_0_distance - pAllocs->field_6_numObjTranslated) & 0xFFFF;
                const DWORD otPos = LOBYTE(depth);
                const DWORD size = HIBYTE(depth);
                const DWORD ptrWithSize = (DWORD)(pAllocs->field_0_1024_unk_ptr[otPos]) | (size << 24);
                pPolyBuffer[i].tag = ptrWithSize;
                addPrim(&pAllocs->field_0_1024_unk_ptr[otPos], &pPolyBuffer[i]);
            }
        }
        else
        {
            polTag->field_0_distance = 0;
            int field_c = pAllocs->field_14_unknown;
            pAllocs->field_20_pPolyBufferIter = &pPolyBuffer[i];
            if (tagByte & 256)
            {
                field_c = -pAllocs->field_14_unknown;
            }
            pAllocs->field_C = field_c;
            pAllocs->field_38_pMatrix = &pAllocs->field_3C_matrix;
            pAllocs->field_10_float = static_cast<float>(field_c * 0.5);
         
            Psx_gte_403F3C(pVerts, &pIndcies[i], &pPolyBuffer[i]);
            LibGV_403845();
        }
    }
    return &pPolyBuffer[numFaces];
}
MGS_FUNC_IMPLEX(0x403778, LibGV_Helper_403778, LIBDG_IMPL);

static void CC Stub_Psx_gte_403F3C(SVECTOR *, unsigned int *, POLY_GT4 *)
{
    LOG_INFO("Stub_Psx_gte_403F3C");
}

static void CC Stub_LibGV_403845()
{
    LOG_INFO("Stub_LibGV_403845");
}

static void Test_LibGV_Helper_403778()
{
    ScratchPad_Allocs* pAllocs = (ScratchPad_Allocs*)gScratchPadMemory_991E40.field_0_raw.field_0;
    pAllocs->field_6_numObjTranslated = 0;
    pAllocs->field_18_2048 = 5;
    pAllocs->field_1C_project_distance = 20;
    pAllocs->field_2C_max_possible_elements = 3;
    DWORD* buffer[1024] = {};
    pAllocs->field_0_1024_unk_ptr = buffer;

    // Check 0'ed tag does nothing
    {
        POLY_GT4 polys[2] = {};
        LibGV_Helper_403778(polys, 2, nullptr, nullptr);
        ASSERT_EQ(buffer[0], nullptr);
    }

    // Check the 4th tag byte becomes OTZ and the 3rd is inserted
    // into the start of the OT pointer.
    // First 2 bytes are checked against the projection distance.
    {
        POLY_GT4 polys[2] = {};
        polys[0].tag |= 0xCCDD2130;
        buffer[0x30] = (DWORD*)0x00febaee;

        LibGV_Helper_403778(polys, 2, nullptr, nullptr);
        ASSERT_EQ(buffer[0x30], (DWORD*)&polys[0]);
        ASSERT_EQ(polys[0].tag, (DWORD)(0x21febaee));
    }

    {
        SCOPED_REDIRECT(Psx_gte_403F3C, Stub_Psx_gte_403F3C);
        SCOPED_REDIRECT(LibGV_403845, Stub_LibGV_403845);

        pAllocs->field_14_unknown = 3;
        pAllocs->field_18_2048 = 1;
        pAllocs->field_1C_project_distance = 999999;
        pAllocs->field_2C_max_possible_elements = 4;

        POLY_GT4 polys[2] = {};
        polys[0].tag |= 0x11ffbaee;
        buffer[0x30] = 0;

        LibGV_Helper_403778(polys, 2, nullptr, nullptr);

        ASSERT_EQ(pAllocs->field_10_float, -1.5f);
        ASSERT_EQ(pAllocs->field_C, -3);


        ASSERT_EQ(buffer[0x30], nullptr);
        ASSERT_EQ(polys[0].tag, (DWORD)(0x11ff0000));
    }

    {
        SCOPED_REDIRECT(Psx_gte_403F3C, Stub_Psx_gte_403F3C);
        SCOPED_REDIRECT(LibGV_403845, Stub_LibGV_403845);

        pAllocs->field_14_unknown = 3;
        pAllocs->field_18_2048 = 1;
        pAllocs->field_1C_project_distance = 999999;
        pAllocs->field_2C_max_possible_elements = 4;

        POLY_GT4 polys[2] = {};
        polys[0].tag |= 0x11febaee;
        buffer[0x30] = 0;

        LibGV_Helper_403778(polys, 2, nullptr, nullptr);

        ASSERT_EQ(pAllocs->field_10_float, 1.5f);
        ASSERT_EQ(pAllocs->field_C, 3);

        ASSERT_EQ(buffer[0x30], nullptr);
        ASSERT_EQ(polys[0].tag, (DWORD)(0x11fe0000));
    }
}

void CC LibGV_Helper_40373E(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40; // TODO: Add to union
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    POLY_GT4* pPolyBuffer = pMesh->field_54_prim_buffers[activeBuffer];
    pScratch->field_6_numObjTranslated = pMesh->field_50_numObjTranslated;
    while (pMeshIter)
    {
        pPolyBuffer = LibGV_Helper_403778(
            pPolyBuffer,
            pMeshIter->field_52_num_faces,
            pMeshIter->field_40_pKmdObj->vertOfs_38,
            (unsigned int *)pMeshIter->field_40_pKmdObj->indexOfs_3C); // TODO: Check types - is actually used as BYTE* else where?
        pMeshIter = pMeshIter->field_48_pLinked;
    }
}
MGS_FUNC_IMPLEX(0x40373E, LibGV_Helper_40373E, LIBDG_IMPL);

struct PolyTag
{
    BYTE field_0_OTZ;
    BYTE field_1_unknown;
    BYTE field_2_not_used;
    BYTE field_3_prim_length_words;
};
MGS_ASSERT_SIZEOF(PolyTag, 0x4);

void CC LibGV_404139(Prim_Mesh_0x5C* pMesh, int activeBuffer)
{
    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40; // TODO: Add to union
    POLY_GT4* pPolyIter = pMesh->field_54_prim_buffers[activeBuffer];
    Prim_Mesh_0x5C* pMeshIter = pMesh;
    const __int16 field_50_numObjTranslated = pMesh->field_50_numObjTranslated;
    do
    {
        DWORD** pScratchOt = pScratch->field_0_1024_unk_ptr;
        //pPolyIter = (POLY_GT4 *)((unsigned int)pPolyIter & 0xFFFFFF);

        //assert(pMeshIter->field_52_num_faces < 256);
        for (int i = 0; i < pMeshIter->field_52_num_faces; i++)
        {
            PolyTag* pTag = (PolyTag*)&pPolyIter[i].tag;
            if (pTag->field_0_OTZ || pTag->field_1_unknown)
            {
                pTag->field_3_prim_length_words = 0;
                const int otPos = pTag->field_0_OTZ - pMesh->field_50_numObjTranslated;
                const BYTE newLen = pTag->field_1_unknown;

               
                addPrim(&pScratchOt[otPos], &pPolyIter[i]);
                setlen(&pPolyIter[i].tag, newLen);
            }
        }
        pMeshIter = pMeshIter->field_48_pLinked;
    } while (pMeshIter);
}
MGS_FUNC_IMPLEX(0x404139, LibGV_404139, false); // TODO: Implement me - snakes shadow is broken so impl is still wrong somehow


static void Test_LibGV_404139()
{
    DWORD* ot[256] = {};

    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40;
    pScratch->field_0_1024_unk_ptr = ot;

    Prim_Mesh_0x5C mesh = {};
    POLY_GT4 polys[4] = {};
    for (int i = 0; i < 4; i++)
    {
        setPolyGT4(&polys[i]);

        PolyTag* pTag = (PolyTag*)&polys[i].tag;
        pTag->field_0_OTZ = 10;
        pTag->field_1_unknown = 6;
        pTag->field_2_not_used = 7;
    }

    mesh.field_54_prim_buffers[0] = polys;
    mesh.field_52_num_faces = 2;
    mesh.field_50_numObjTranslated = 5;

    DWORD test[20] = {};
    DWORD* pTest = &test[0];
   // DWORD* pTest2 = &test[3];
    ot[10 - 5] = pTest;

    LibGV_404139(&mesh, 0);

    DWORD newTag1 = 0x06000000 | ((DWORD)pTest);
    ASSERT_EQ(polys[0].tag, newTag1);

    DWORD newTag2 = 0x06000000 | ((DWORD)&polys[0].tag);
    ASSERT_EQ(polys[1].tag, newTag2);
    //ASSERT_EQ(polys[2].tag, 0);

    ASSERT_EQ(ot[10-5], (DWORD*)&polys[1].tag);

}

void CC LibGV_prims_403528(struct_gv* pGv, int activeBuffer)
{
    ScratchPad_Allocs* pScratch = (ScratchPad_Allocs*)&gScratchPadMemory_991E40; // TODO: Add to union

    if (LibGV_prims_scratch_alloc_403672(activeBuffer))
    {
        Gte_project_distance_rect_401DA8(&pGv->dword_6BC3C8_pStructure_rect, pGv->word_6BC3BC);
        pScratch->field_0_1024_unk_ptr = gUnkSize_1024_6BE4E8; // TODO: !?
        pScratch->field_18_2048 = 2048;
        pScratch->field_1C_project_distance = (unsigned __int16)(pGv->word_6BC3BC <= 1000 ? 0 : 0xCA60) + 0x2000;

        if (!dword_688CD8)
        {
            pScratch->field_1C_project_distance = 0;
        }

        for (int i = 0; i < pGv->mTotalObjectCount; i++)
        {
            Prim_unknown_0x48* pPrim = &pGv->mQueue[i]->prim_48;
            if (pPrim->field_32)
            {
                Prim_Mesh_0x5C* pMesh = DataAfterStructure<Prim_Mesh_0x5C*>(pPrim);
                for (int j = 0; j < pPrim->field_2E_UnknownOrNumFaces; j++)
                {
                    if (pMesh[j].field_4C_bounding_ret)
                    {
                        if ((pPrim->field_28_flags_or_type & 0x20) == 0)
                        {
                            gte_rotation_matrix_993E40 = pMesh[j].field_20_mtx.m;
                            gGte_translation_vector_993E54 = pMesh[j].field_20_mtx.t;
                            pScratch->field_14_unknown = ~(pMesh[j].field_40_pKmdObj->field_0_flags >> 1) & 1;
                            LibGV_Helper_40373E(&pMesh[j], activeBuffer);
                        }
                        else
                        {
                            LibGV_404139(&pMesh[j], activeBuffer);
                        }
                    }
                }
            }
        }
    }
}
MGS_FUNC_IMPLEX(0x403528, LibGV_prims_403528, LIBDG_IMPL);

void CC MarkObjectVoided_40744A(Prim_unknown_0x48* pObj, int bufferIndex)
{
    for (int i = 0; i < pObj->field_2E_UnknownOrNumFaces; i++)
    {
        Prim_Mesh_0x5C* pMeshIter = (Prim_Mesh_0x5C *)&pObj[1];
        if (pMeshIter[i].field_54_prim_buffers[bufferIndex])
        {
            System_VoidAllocation_40B187(bufferIndex, (void **)&pMeshIter[i].field_54_prim_buffers[bufferIndex]);
            pMeshIter[i].field_54_prim_buffers[bufferIndex] = nullptr;
        }
    }
}
MGS_FUNC_IMPLEX(0x40744A, MarkObjectVoided_40744A, LIBDG_IMPL);

void CC MarkObjectQueueVoid_4018E0()
{
    gLibDG_ExecPtrs_6BECE8 = 1;
    Prim_Union** pObj = gLibGVStruct1_6BC36C.mQueue;
    for (int i = 0; i < gLibGVStruct1_6BC36C.mTotalObjectCount; i++)
    {
        MarkObjectVoided_40744A(&pObj[i]->prim_48, 0);
        MarkObjectVoided_40744A(&pObj[i]->prim_48, 1);
    }
}
MGS_FUNC_IMPLEX(0x4018E0, MarkObjectQueueVoid_4018E0, LIBDG_IMPL);

const PSX_MATRIX gIdentity_matrix =
{ 
    {{
        { 4096, 0, 0 },
        { 0, 4096, 0 },
        { 0, 0, 4096 }
    }},
    { 0 },
    { 0, 0, 0 }
};

MGS_VAR(1, 0x6501F8, PSX_MATRIX, gIdentity_matrix_6501F8, { gIdentity_matrix });


void CC sub_401D64(PSX_MATRIX* pMatrix)
{
    pMatrix->m.m[1][0] = 58 * pMatrix->m.m[1][0] / 64;
    pMatrix->m.m[1][1] = 58 * pMatrix->m.m[1][1] / 64;
    pMatrix->m.m[1][2] = 58 * pMatrix->m.m[1][2] / 64;
    pMatrix->t.field_4_y = 58 * pMatrix->t.field_4_y / 64;
}
MGS_FUNC_IMPLEX(0x401D64, sub_401D64, LIBDG_IMPL);

void CC LibGV_407122(struct_gv* pGv, int /*activeBuffer*/)
{
    gScratchPadMemory_991E40.field_2_Matrix.mtx[0] = pGv->field_10_matrix;
    sub_401D64(&gScratchPadMemory_991E40.field_2_Matrix.mtx[0]);

    for (int i = 0; i < pGv->mTotalObjectCount; i++)
    {
        Prim_Union* pObj = pGv->mQueue[i];
        LibGV_4066ED(pObj);
    }
}
MGS_FUNC_IMPLEX(0x407122, LibGV_407122, LIBDG_IMPL);

struct ScratchPad_40340A
{
    DWORD** field_0_1024_unk_ptr;
    DWORD* field_4_ordering_table;
    DWORD field_8_face_count;
};

void CC OrderingTableAdd_4034C6(BYTE* pPrimDataStart, int count, int size)
{
    ScratchPad_40340A* pScratch = (ScratchPad_40340A*)&gScratchPadMemory_991E40; // TODO: Add to union

    DWORD* pOrderingTable = pScratch->field_4_ordering_table;
    const DWORD faceCount = pScratch->field_8_face_count;
    for (int i = 0; i < count; ++i, pPrimDataStart += size)
    {
        const DWORD polyTagLowPart = *(WORD*)pPrimDataStart;

        if (polyTagLowPart <= 0) // TODO: Can't ever be true unless its == 0
        {
            continue;
        }

        long offset = (polyTagLowPart - faceCount);
        if (offset < 0)
        {
            offset = 0;
        }

        addPrim(&pOrderingTable[offset / 256], pPrimDataStart);
    }
}
MGS_FUNC_IMPLEX(0x4034C6, OrderingTableAdd_4034C6, LIBDG_IMPL);

void CC LibGV_40340A(struct_gv* pGv, int activeBuffer)
{
    ScratchPad_40340A* pScratch = (ScratchPad_40340A*)&gScratchPadMemory_991E40; // TODO: Add to union
    pScratch->field_0_1024_unk_ptr = gUnkSize_1024_6BE4E8;// 256 DWORD's.. or 512?
    pScratch->field_4_ordering_table = pGv->mOrderingTables[activeBuffer] + 1;

    DWORD** unk1024 = pScratch->field_0_1024_unk_ptr;
    DWORD* otrPtrNext = pScratch->field_4_ordering_table;
    for (int i=0; i<256; i++)
    {
        DWORD* unkItem = unk1024[i];
        if (unkItem)
        {
            DWORD unkPtr = 0;
            do
            {
                DWORD* otPosPtr = &otrPtrNext[*unkItem >> 24];
                unkPtr = *unkItem & 0xFFFFFF;
                *unkItem = *otPosPtr | 0x0C000000; // 0x0c000000 POLY_GT4 tag/size?
                *otPosPtr = (DWORD)unkItem;
                unkItem = (DWORD *)unkPtr;
            } while (unkPtr);
        }
    }

    const DWORD mask = dword_78D32C;
    Prim_Union** ppPrims = &pGv->mQueue[pGv->mFreePrimCount];
    const int primCount = pGv->mTotalQueueSize - pGv->mFreePrimCount;
    for (int i = 0; i < primCount; i++)
    {
        Prim_unknown_0x54* pPrim = &ppPrims[i]->prim_54;
        if (!(pPrim->field_24_flags2 & 256)  // maybe count?
        && (pPrim->field_28_flags_or_type == 0 || pPrim->field_28_flags_or_type & mask))
        {
            pScratch->field_8_face_count = pPrim->field_2E_UnknownOrNumFaces;
            OrderingTableAdd_4034C6(
                pPrim->field_40_pDataStart[activeBuffer],
                pPrim->field_2A_num_prims,
                pPrim->field_30_prim_size);
        }
    }
}
MGS_FUNC_IMPLEX(0x40340A, LibGV_40340A, false); // TODO: Implement me


MGS_ARY(1, 0x6500E0, TDG_FnPtr, 8, gLibDg_FuncPtrs_off_6500E0,
{
    LibGV_407122,
    LibGV_4061E7,
    LibGV_405668,
    LibGV_lights_405180,
    LibGV_4041A5,
    LibGV_prims_403528,
    LibGV_40340A,
    nullptr
});

// Returns the old pointer because the calling code will use it to restore it later
TDG_FnPtr CC LibDG_SetFnPtr_4019FA(int idx, TDG_FnPtr fnPtr)
{
    if (idx == 7)
    {
        MGS_FATAL("LibDG_SetFnPtr_4019FA - should never be reached");
    }
    TDG_FnPtr old = gLibDg_FuncPtrs_off_6500E0[idx];
    gLibDg_FuncPtrs_off_6500E0[idx] = fnPtr;
    return old;
}
MGS_FUNC_IMPLEX(0x4019FA, LibDG_SetFnPtr_4019FA, LIBDG_IMPL);

void CC LibDG_Update1_4012ED(Actor* /*pActor*/)
{
    // This function is a jmp to a stub that does this
    LibDG_ExecFnPtrs_40171C(gActiveBuffer_dword_791A08);
}
MGS_FUNC_IMPLEX(0x4012ED, LibDG_Update1_4012ED, LIBDG_IMPL);

void CC DG_Init_40111A()
{
    //GetNewVblControlTable_8();
    //SetVblankControlFunc_7(PrimitiveQueueEmpty_4011F8);
    LibGvInitDispEnv_401A4F(0, 0, 320, 240, 320);
    Gv3StructsInit_4012F2(320);
    LibDG_Clear_Resident_Texture_Cache_Copy_4026E6();
    LibDG_4010A6();
    LibGV_Set_FileExtHandler_40A68D('p', GV_pcx_file_handler_402B25); // .pcc/.pcx
    LibGV_Set_FileExtHandler_40A68D('k', GV_kmd_file_handler_402796);
    LibGV_Set_FileExtHandler_40A68D('l', GV_lit_file_handler_402B1D);
    LibGV_Set_FileExtHandler_40A68D('n', GV_n_file_handler_402A03);
    LibGV_Set_FileExtHandler_40A68D('o', GV_oar_file_handler_402A29);
    LibGV_Set_FileExtHandler_40A68D('z', GV_zmd_file_handler_403290);
    LibGV_Set_FileExtHandler_40A68D('i', GV_img_file_handler_402A5F);
    LibGV_Set_FileExtHandler_40A68D('s', GV_sgt_file_handler_402AA9);
    Actor_PushBack_40A2AF(0, &gLibDG_2_stru_6BB930.mBase, 0);// Handles 2D rendering?
    Actor_Init_40A347(&gLibDG_2_stru_6BB930.mBase, LibDG_Update2_401234, nullptr, "C:\\mgs\\source\\LibDG\\dgd.c");
    Actor_PushBack_40A2AF(8, &gLibDGD_1_stru_6BB910, 0); // Handles 3D rendering?
    Actor_Init_40A347(&gLibDGD_1_stru_6BB910, LibDG_Update1_4012ED, nullptr, "C:\\mgs\\source\\LibDG\\dgd.c");
}
MGS_FUNC_IMPLEX(0x40111A, DG_Init_40111A, LIBDG_IMPL);

void CC LibDG_ExecFnPtrs_40171C(int activeBuffer)
{
    if (!gLibDG_ExecPtrs_6BECE8)
    {
        MemClearUnknown_40B231(gUnkSize_1024_6BE4E8, 1024);

        int count = 7;
        // Check if extra function pointer slot is in use?
        // TODO: Seems like this is dead code as the condition can never be true?
        if (gLibDG_2_stru_6BB930.dword_6BB950_do_not_flip_buffers != 0)
        {
            count++;
            MGS_FATAL("LibDG_ExecFnPtrs_40171C - should never be reached");
        }

        for (int i = 0; i < count; i++)
        {
            gLibDg_FuncPtrs_off_6500E0[i](&gLibGVStruct1_6BC36C, activeBuffer);
        }
    }
}
MGS_FUNC_IMPLEX(0x40171C, LibDG_ExecFnPtrs_40171C, LIBDG_IMPL);

struct DG_Light
{
    DWORD field_0_lightCount;
    Light* field_4_pLights;
};
MGS_ASSERT_SIZEOF(DG_Light, 0x8);

MGS_ARY(1, 0x6BEE30, DG_Light, 8, gLights_6BEE30, {});

void CC LibDG_Init_Lights_4021B3()
{
    for (int i = 0; i < 8; i++)
    {
        gLights_6BEE30[i].field_0_lightCount = 0;
        gLights_6BEE30[i].field_4_pLights = nullptr;
    }
}
MGS_FUNC_IMPLEX(0x4021B3, LibDG_Init_Lights_4021B3, LIBDG_IMPL);

void CC Light_add_4021C9(Light* pLights, int lightCount)
{
    for (int i = 0; i < 8; i++)
    {
        if (gLights_6BEE30[i].field_4_pLights != pLights && gLights_6BEE30[i].field_0_lightCount == 0)
        {
            gLights_6BEE30[i].field_0_lightCount = lightCount;
            gLights_6BEE30[i].field_4_pLights = pLights;
            return;
        }
    }
}
MGS_FUNC_IMPLEX(0x4021C9, Light_add_4021C9, LIBDG_IMPL);

void DoDGTests()
{
    Test_LibGV_4045A5();
    Test_LibGV_404E08();
    Test_LibGV_apply_texture_to_quads_4071E1();
    Test_LibGV_prim_buffer_init_polyGT4s_40738D();
    Test_LibGV_404139();
    Test_LibGV_405428();
    Test_LibGV_normals_4054F2();
    Test_LibGV_406168();
    Test_LibGV_40466A();
    Test_LibGV_Helper_403778();
    Test_LibGV_helper_405B8A();
}
