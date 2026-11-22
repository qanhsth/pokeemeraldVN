OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Cái MÁY TÍNH ở trong góc đó\n"
	.string "là NHL POKéMON mới xài được.\p"
	.string "Tức là, bạn cũng được phép\n"
	.string "xài nó luôn.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "TRUNG TÂM POKéMON rất tuyệt vời!\p"
	.string "Bạn có thể sử dụng dịch vụ của họ\n"
	.string "thoải mái, mà không tốn đồng nào.\l"
	.string "Không cần phải lo gì đâu!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "CLB POKéMON không dây ở trên\n"
	.string "tầng 2 mới được xây lại thì phải.\p"
	.string "Mà nghe người ta vẫn còn đang\n"
	.string "sửa chữa thêm hay sao đó.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "CLB POKéMON không dây ở trên\n"
	.string "tầng 2 mới được xây lại thì phải.\p"
	.string "Chắc tui phải đi trao đổi POKéMON thôi.$"

