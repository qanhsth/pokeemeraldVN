GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Tui tên là ĐẠI.\p"
	.string "Tui thích đá quý,\n"
	.string "và đi đây đó.\p"
	.string "Ủa?\n"
	.string "LÁ THƠ cho tui hả?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "ĐẠI: Rồi, cảm ơn nha.\p"
	.string "Bạn đã mắc công đem tới đây cho tui,\n"
	.string "phải có gì đó để cảm ơn bạn mới được.\p"
	.string "Để coi…\n"
	.string "Tui sẽ cho bạn cái TM này.\p"
	.string "Trong đây có chiêu mà tui thích,\n"
	.string "CÁNH THÉP.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "ĐẠI: POKéMON nhìn cũng\n"
	.string "ok đó.\p"
	.string "Nếu chăm chỉ rèn luyện, bạn thậm chí\n"
	.string "sẽ trở thành NHÀ VÔ ĐỊCH LIÊN ĐOÀN\l"
	.string "POKéMON 1 ngày nào đó. Tui nghĩ vậy.\p"
	.string "Mà tụi mình cũng biết nhau rồi,\n"
	.string "thôi thì lưu số nhau vô\l"
	.string "BẢN ĐỒ nha.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Lưu số ĐẠI\n"
	.string "vô BẢN ĐỒ.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Thôi tui phải đi rồi.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Ủa, TÚI đầy rồi…\n"
	.string "Vậy sao tui cho bạn được.$"
