FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Nói nghe nè, nhóc đang thu thập\n"
	.string "thông tin POKéMON phải không?\p"
	.string "Hừmm… Tới KHU SĂN BẮT đi.\n"
	.string "Ta gợi ý vậy thôi.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Bạn có lại chỗ\n"
	.string "KHU GHI HÌNH chưa?\p"
	.string "Khá là hay ho đó. Kết hợp và sắp xếp\n"
    .string "kỷ lục của NHL.\p"
    .string "Tui cũng không rành, nhưng mà\n"
    .string "nó rất hay. Thú vị nữa!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Ủa, trời ơi, bạn có BẢN ĐỒ kìa!\n"
	.string "Giống y chang tui luôn!\p"
	.string "Bạn có biết hệ thống GỌI ĐIỆN\n"
	.string "trong BẢN ĐỒ không?\p"
	.string "Vô đó, bạn sẽ có thể tám với người\n"
	.string "mà mình đã lưu số, bất kỳ lúc nào.\p"
	.string "Nó cũng sẽ hiện lên, NHL muốn\n"
	.string "tái đấu với bạn.\p"
	.string "Hay á chớ bộ! Mấy ông DEVON này\n"
	.string "công nhận tài thiệt!$"

