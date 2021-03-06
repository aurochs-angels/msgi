#pragma once

#include "LibGV.hpp"

void DoMapTests();

signed int CC Script_tbl_map_45151D(BYTE* pScript);
void CC Map_FreeHzdItems_44F38D();
void CC Map_ResetMapCountAndKmdsCount_44F3F7();
void CC Map_FreeKmds_44F3B5();

struct map_record;
void CC Map_LitLoad_44F53B(int resourceNameHashed, const map_record* pMapStruct);
int CC Gv_hzm_file_handler_40B734(void*, TFileNameHash);
void CC Map_update_if_changed_44F28B();
map_record* CC Script_tbl_hzd_impl_44F415();
map_record* CC Map_FromId_44F79E(signed int mapChangeFlags);

MGS_VAR_EXTERN(DWORD, map_change_flags_dword_99535C);