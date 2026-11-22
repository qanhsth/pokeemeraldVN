SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Muốn nghe mẹo thách đấu không?\p"
	.string "Theo tui nghĩ, đó là nên nuôi\n"
    .string "POKéMON có nhiều hệ khác nhau.\p"
    .string "Chỉ tập trung luyện cấp cho một\n"
    .string "POKéMON thôi là không tốt.\p"
    .string "Nếu gặp bất lợi về hệ,\n"
	.string "nó sẽ không có cơ hội thắng đâu.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
    .string "Tui trao đổi POKéMON với bạn.\p"
    .string "Nếu POKéMON được trao đổi có cầm một\n"
    .string "vật phẩm, thì tui sẽ rất vui!$"

