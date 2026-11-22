FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "TS.TINH: Ủa…\n"
	.string "Lẽ ra tui không nên để mình bị gạt\l"
    .string "rồi tiết lộ cho ĐỘI MAGMA nơi\l"
    .string "có thể tìm thấy ĐÁ TRỜI…\p"
    .string "Cái ĐÁ TRỜI từ THÁC SAO BĂNG đó…\n"
    .string "Sẽ không bao giờ thuộc về tui nữa…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Ủa!\n"
	.string "Hả?\p"
	.string "Cái đó…\p"
	.string "Phải chăng là?\p"
	.string "Có phải là ĐÁ TRỜI mà ĐỘI MAGMA\n"
	.string "đã lấy từ THÁC SAO BĂNG không?\p"
	.string "Tui có thể xin lại được không?\p"
	.string "Tất nhiên là tui có món để đổi lại rồi.\n"
	.string "Đổi lấy cái TM này nha?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "TS.TINH: Cái TM này,\n"
	.string "là tấm lòng biết ơn của tui.\l"
	.string "Xin hãy sử dụng nó!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "TS.TINH: Trời, không thể tin được.\n"
	.string "Tốt quá, tốt quá rồi!\p"
	.string "Được nghiên cứu cái này, mãn nguyện rồi!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "TS.TINH: Ụa, mà…\n"
	.string "Tui lỡ làm bể rồi…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "TS.TINH: Làm ơn cho tui\n"
	.string "xin ĐÁ TRỜI đi?\p"
	.string "Tất nhiên là tui có món để đổi lại rồi.\n"
	.string "Đổi lấy cái TM này nha?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "TS.TINH qua THÁC SAO BĂNG\n"
	.string "ở ĐƯỜNG 114 với mấy người\l"
	.string "của ĐỘI MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Tội TS.TINH quá…\n"
	.string "Ổng xuống sắc quá trời… tội nghiệp ổng.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Nhìn TS.TINH kìa…\n"
	.string "Ổng vui quá! Thấy cưng ghê.$"

