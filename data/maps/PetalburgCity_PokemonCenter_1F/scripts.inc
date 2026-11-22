PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Cái MÁY TÍNH lưu\n"
	.string "trữ POKéMON đó á…\p"
	.string "Cái người làm ra chắc\n"
	.string "chắn là thiên tài rồi!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "POKéMON mà ăn TRÁI LAM,\n"
	.string "nó tự hồi lại MÁU luôn!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Có rất nhiều hệ POKéMON.\p"
	.string "Mỗi hệ có điểm mạnh và\n"
	.string "điểm yếu để khắc chế nhau.\p"
	.string "Tùy theo hệ của POKéMON mà,\n"
	.string "ván đấu có thể thành dễ hay khó.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Thí dụ, con TREECKO của\n"
	.string "bạn là hệ CỎ đi.\p"
	.string "Thì nó sẽ khắc chế\n"
	.string "hệ NƯỚC với hệ ĐẤT.\p"
	.string "Nhưng mà khi gặp POKéMON hệ\n"
	.string "LỬA thì nó bị khắc chế lại.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Thí dụ, con TORCHIC của\n"
	.string "bạn là hệ LỬA đi.\p"
	.string "Thì nó sẽ khắc chế\n"
	.string "hệ CỎ với hệ BỌ.\p"
	.string "Nhưng mà nó sẽ sợ\n"
	.string "POKéMON hệ NƯỚC.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Thí dụ, con MUDKIP của\n"
	.string "bạn là hệ NƯỚC đi.\p"
	.string "Thì nó sẽ khắc chế hệ LỬA.\p"
	.string "Nhưng mà nó sẽ sợ POKéMON\n"
	.string "hệ CỎ với hệ ĐIỆN.$"
