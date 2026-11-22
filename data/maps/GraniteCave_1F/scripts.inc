GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Ê, lại đây biểu!\n"
	.string "Càng vô sâu càng tối đó.\l"
	.string "Đi vô thám hiểm rất là khó.\p"
	.string "Cái người mới đi qua…\n"
	.string "hình như là ĐẠI.\p"
	.string "Hình như ổng biết xài CHÓI, nên\n"
	.string "chắc là không sao, nhưng mà…\p"
	.string "Đối với người LEO NÚI như tụi tui,\n"
	.string "luôn luôn giúp người mà mình gặp.\p"
	.string "Xoè tay ra, tui đưa cho cái này nè.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Dạy cho POKéMON biết\n"
	.string "xài chiêu CHÓI đi.\p"
	.string "Để khi mà vô hang tối\n"
	.string "thì còn thấy đường mà đi.\p"
	.string "Mà nếu muốn sử dụng thì phải có\n"
	.string "HUY HIỆU THÔN ĐẢO mới được.$"

