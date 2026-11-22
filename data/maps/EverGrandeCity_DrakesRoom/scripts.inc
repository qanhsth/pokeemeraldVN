EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Ta là người ĐẠI TỨ cuối cùng trong\n"
	.string "LIÊN ĐOÀN, LOAN THỤ, bậc thầy hệ RỒNG!\p"
	.string "Trong trạng thái tự nhiên, POKéMON là\n"
    .string "những sinh vật hoang dã. Tự do.\p"
    .string "Đôi khi, cản trở chúng ta.\n"
    .string "Đôi khi, giúp đỡ lại chúng ta.\p"
	.string "Để chiến đấu cùng POKéMON với tư cách là\n"
    .string "đồng đội, con có biết phải làm gì không?\p"
    .string "Con có biết cần phải có gì không?\p"
    .string "Nếu không, thì con sẽ không bao giờ\n"
    .string "chiến thắng được ta đâu!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Phải nói là, tuyệt trần.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Con xứng đáng nhận được mọi lời khen vì\n"
    .string "tới được đây với tư cách là NHL POKéMON.\p"
    .string "Có vẻ như con thực sự hiểu mình cần gì.\p"
    .string "Đúng vậy, điều mà một NHL cần chính là\n"
    .string "một trái tim cao thượng.\p"
	.string "POKéMON cảm nhận được lòng nhân ái của\n"
    .string "các NHL và phân biệt được đúng sai.\p"
    .string "Tụi nó cảm nhận được lòng nhân ái của\n"
    .string "các NHL và trở nên mạnh mẽ.\p"
    .string "Tiến lên! Tiến lên đi!\n"
    .string "CHỨC VÔ ĐỊCH đang chờ con đó!$"

