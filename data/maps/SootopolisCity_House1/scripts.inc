SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak::
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM:
	.string "Trong suốt 30 năm qua, ta đã ở LƯU\n"
	.string "NIẾT để rèn giũa kỹ năng của mình.\p"
	.string "Ta đã phát triển ra một cái TM cực mạnh.\n"
    .string "Giờ ta sẽ trao tặng nó cho ngươi!$"

SootopolisCity_House1_Text_ExplainBrickBreak:
	.string "TM31 chứa ĐẬP BỂ! Đó là một chiêu\n"
	.string "thức đáng sợ tới mức không tả nỗi.$"

SootopolisCity_House1_Text_Kecleon:
	.string "KECLEON: Pưư pừ ha.$"

