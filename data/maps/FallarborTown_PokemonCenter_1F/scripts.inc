FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Xin chào.\n"
	.string "Bạn là?\p"
	.string "Aa, bạn là {PLAYER}.\n"
	.string "Hình như bạn là NHL thì phải.\p"
	.string "Vậy có nghĩa là bạn đã sử dụng Hệ Thống\n"
	.string "Lưu Trữ POKéMON mà tui đã chế ra.\p"
	.string "Tại sao tui có kết luận đó, thực ra\n"
    .string "là suy luận đơn giản thôi.\p"
    .string "Bạn lại bắt chuyện với tui vì bạn muốn\n"
    .string "coi cái gì đó trong cái máy này.\p"
    .string "À, quên, xin lỗi. Tui là MỸ LAN.\p"
    .string "Thực sự, tui rất vui được gặp bạn,\n"
    .string "đang sử dụng Hệ thống Lưu trữ.\p"
    .string "Nếu được, hãy ghé qua nhà tui.\n"
    .string "Nhà tui nằm trên ĐƯỜNG 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
    .string "Không biết POKÉMON hồi xa xưa\n"
    .string "nhìn ra sao ha?\p"
    .string "Có lẽ người MÊ HOÁ THẠCH ở\n"
    .string "trong góc thị trấn sẽ biết.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
    .string "Trên cánh đồng của NÔNG TRẠI, tụi tui\n"
    .string "trồng nhiều loại cây chắc khoẻ, có thể\l"
    .string "phát triển mạnh kể cả trong tro núi lửa.$"

