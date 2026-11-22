MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "Cái cha nội ở đằng kia, nói\n"
	.string "tầm bậy không à!\p"
	.string "Ổng cũng vui mà tầm bậy quá.\n"
	.string "Chắc tui sẽ khó quên được ổng!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "Khi mà tui vô PHÒNG CHUYỂN ĐỔI,\n"
	.string "dữ liệu về cái đang hot ở\l"
	.string "THÔN ĐẢO đã được cập nhật.\p"
	.string "Giờ thì tui đã có dữ liệu\n"
	.string "giống của bạn tui rồi!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "PHÒNG CHUYỂN ĐỔI ở trên lầu\n"
	.string "trong TRUNG TÂM POKéMON.\p"
	.string "Tui không biết đó là gì nữa, mà\n"
	.string "nghe cũng vui. Tui sẽ đi coi thử!$"

