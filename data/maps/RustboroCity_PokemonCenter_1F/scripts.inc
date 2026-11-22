RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "POKéMON của tui có tính cách NGÂY THƠ,\n"
	.string "còn của bạn tui thì là VUI VẺ.\p"
	.string "POKéMON mà cũng có tính\n"
	.string "cách, kỳ lạ ha!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Giống như con người, có POKéMON\n"
	.string "đực, có POKéMON cái.\p"
	.string "Nhưng mà hình như không có ai\n"
	.string "biết tụi nó khác nhau chỗ nào hết.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Cái ông nhà kế bên cho tui HM nè!\p"
	.string "Tui sẽ xài để dạy cho POKéMON\n"
	.string "cách CẮT cây non xuống.$"

