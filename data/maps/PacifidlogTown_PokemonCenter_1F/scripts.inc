PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "THẺ HUẨN LUYỆN của bạn có màu gì?\n"
	.string "Của tui là màu dây đồng!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "LÀNG NỔI nổi ở trên đầu\n"
	.string "của sinh vật CORSOLA.\p"
	.string "Nếu mà tui nói vậy, bạn có\n"
	.string "tin không?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Tổ tiên của mấy người ở LÀNG NỔI\n"
	.string "hình như là được sanh ra ở trên\l"
	.string "chiếc thuyền rồi sống chết\l"
	.string "ở trên đó luôn.\p"
	.string "Tui cũng hiểu là họ sống như vậy\n"
	.string "là bởi vì họ đang tìm kiếm cái\l"
	.string "gì đó.$"

