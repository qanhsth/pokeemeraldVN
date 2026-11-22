VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Bạn không thể tự gọi mình là\n"
	.string "NHL thực thụ nếu bạn không có\l"
	.string "niềm tin vô POKéMON của mình.\p"
	.string "Chỉ những người tin tưởng vô\n"
	.string "POKéMON của mình mới có thể\l"
	.string "dành chiến thắng cho tới lúc cuối.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "Lý do mà người ta muốn ghé qua\n"
	.string "GIẢN ĐƠN…\p"
	.string "Đó là HỘI THI ĐẤU. Không cần\n"
	.string "phải nói nhiều.\p"
	.string "Hay là có người mà\n"
	.string "bạn muốn tới thăm?$"

