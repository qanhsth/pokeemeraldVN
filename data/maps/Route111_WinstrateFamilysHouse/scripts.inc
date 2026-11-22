Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Con là NHL đầu tiên mà chú từng gặp,\n"
    .string "biết sử dụng POKéMON 1 cách điêu luyện.\p"
	.string "Mà, chú phải nói là--con trai chú\n"
    .string "mạnh hơn con nhiều đó.\p"
    .string "Nó còn tham gia LIÊN ĐOÀN POKéMON\n"
    .string "nữa đó, chú chỉ nói vậy thôi.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Nhà cô xài cái NẸP này để\n"
	.string "tăng cường sức mạnh cho POKéMON\l"
	.string "khi huấn luyện.\p"
	.string "Dù gì con cũng đánh bại gia đình\n"
	.string "cô rồi, không biết con có cần không,\l"
	.string "mà thôi cô gởi cho con cái NẸP luôn.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Hễ mà nói về thách đấu POKéMON,\n"
    .string "gia đình cô thường rất là hứng thú.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Má mạnh hơn Ba.\p"
	.string "Tui mạnh hơn Má.\p"
	.string "Và Bà Ngoại mạnh hơn tui luôn!\p"
	.string "Nhưng mà anh hai còn mạnh hơn\n"
	.string "Bà Ngoại nữa.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Không nghi ngờ gì nữa, con rất mạnh.\p"
	.string "Mà nếu con có đấu với thằng cháu ngoại,\n"
	.string "con sẽ thua ấm ức cho mà coi.\p"
	.string "Nó mạnh hơn tất cả NHL\n"
	.string "mà gia đình ngoại từng gặp.\p"
	.string "Chắc thằng cháu ngoại đang thách đấu\n"
    .string "với NHÀ VÔ ĐỊCH LIÊN ĐOÀN POKÉMON rồi.\p"
    .string "Biết tánh cháu, có thể giờ nó đã là\n"
    .string "NHÀ VÔ ĐỊCH rồi!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Chắc thằng cháu ngoại đang thách đấu với\n"
    .string "NHÀ VÔ ĐỊCH LIÊN ĐOÀN POKÉMON rồi.\p"
    .string "Biết tánh cháu, có thể giờ nó đã là\n"
    .string "NHÀ VÔ ĐỊCH rồi!$"

